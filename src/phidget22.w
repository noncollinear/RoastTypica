@** Phidget22 library.

\noindent Around the same time as the \pn{} 1.8.0 release, Phidgets released a
new hardware communications library with no regard for compatibility with
existing software and poor communication around that fact. They did, however,
provide hardware specimen for testing that requires the new library.

API differences are significant enough that it makes more sense to write new
code for interacting with phidget22 than attempting to retrofit existing
phidget21 code. By leaving both in, there is no configuration disruption for
people already using hardware previously supported and it is possible to use
both libraries simultaneously to communicate with different hardware.

The option to configure devices with this library should only be shown if the
library is installed. The library name is different on a Mac.

@<Register top level device configuration nodes@>=
#if __APPLE__
QLibrary phidget22check("Phidget22.framework/Phidget22");
#else
QLibrary phidget22check("phidget22");
#endif
if(phidget22check.load())
{
	inserter = new NodeInserter(tr("Phidget22"), tr("Phidget22"), "phidget22",
                                NULL);
	topLevelNodeInserters.append(inserter);
	phidget22check.unload();
}

@ A top level configuration is used to group channels using this library while
child nodes provide channel configuration. The configuration widgets need to be
registered so they can be instantiated as appropriate.

@<Register device configuration widgets@>=
app.registerDeviceConfigurationWidget("phidget22",
	PhidgetConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("phidgetchannel",
	PhidgetChannelConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("phidgetcurrentchannel",
	PhidgetCurrentChannelConfWidget::staticMetaObject);

@ The first configuration widget just serves as a parent to all channels using
this library. There does not seem to be a need for the configuration to mirror
how the hardware is connected, so this serves as a parent node for any number
of devices connected either directly or through a hub.

@<Class declarations@>=
class PhidgetConfWidget : public BasicDeviceConfigurationWidget
{
	Q_OBJECT
	public:
		Q_INVOKABLE PhidgetConfWidget(DeviceTreeModel *model,
		                              const QModelIndex &index);
};

@ The only thing this configuration widget provides is a way to create child
nodes.

Originally, this only supported channels that use the TemperatureInput API.
With the addition of support for other input types, the decision was made to
give each channel type its own node type and configuration widget rather than
attempt to cram every configuration option for all supported types into the
same configuration control.

@<Phidget implementation@>=
PhidgetConfWidget::PhidgetConfWidget(DeviceTreeModel *model,
                                     const QModelIndex &index)
	: BasicDeviceConfigurationWidget(model, index)
{
	QHBoxLayout *layout = new QHBoxLayout;
	QPushButton *addChannelButton = new QPushButton(tr("Add Channel"));
	QMenu *channelTypeMenu = new QMenu;
	NodeInserter *temperatureChannel =
		new NodeInserter(tr("Temperature Channel"),
		tr("Temperature Channel"), "phidgetchannel");
	connect(temperatureChannel, SIGNAL(triggered(QString, QString)),
	        this, SLOT(insertChildNode(QString, QString)));
	channelTypeMenu->addAction(temperatureChannel);
	NodeInserter *currentChannel =
		new NodeInserter(tr("Current Channel"),
		tr("Current Channel"), "phidgetcurrentchannel");
	connect(currentChannel, SIGNAL(triggered(QString, QString)),
	        this, SLOT(insertChildNode(QString, QString)));
	channelTypeMenu->addAction(currentChannel);
	addChannelButton->setMenu(channelTypeMenu);	
	layout->addWidget(addChannelButton);
	setLayout(layout);
}

@ For this library, \pn{} supports a broader range of hardware. This requires
slightly more involved hardware configuration to ensure that a given channel
configuration consistently refers to the same sensor.

Channels will be initialized with a device serial number, a channel number, and
other channel specific configuration options as applicable. These other
configuration options depend on the sensor type associated with the channel. A
thermocouple requires different configuration options than an RTD while the
built in ambient temperature sensors on some devices do not require additional
configuration.

To simplify configuration, a combo box is provided which displays all of the
currently connected channels that \pn{} supports and allows a configuration
widget to obtain relevant channel information when the desired channel is
selected.

By passing an optional channel type into the constructor, this will only
display channels matching the specified type. Some potentially interesting
channel types incude:

\medskip

\settabs 4 \columns

\+&2&Current Input\cr
\+&5&Digital Input\cr
\+&6&Digital Output\cr
\+&28&Temperature Input\cr
\+&29&Voltage Input\cr
\+&30&Voltage Output\cr
\+&38&Current Output\cr
\smallskip

\centerline{Table \secno: A Selection of Phidget Channel Types}

\medskip

@<Class declarations@>=
class PhidgetChannelSelector : public QComboBox
{
	Q_OBJECT
	public:@/
		PhidgetChannelSelector(int channeltype = 0);
		~PhidgetChannelSelector();
		void addChannel(void *device);
		void removeChannel(void *device);
	private:@/
		int typefilter;
		QLibrary driver;
		void *manager;
		@<Phidget22 function pointers@>@;
};

@ At this point, it becomes necessary to call functions in the library. To avoid
a dependency on phidget22.h some function pointer types are created.

@<Additional type definitions@>=
#if defined(__stdcall)
 #define CCONV __stdcall
#else
 #if defined(_MSC_VER)
  #define CCONV __stdcall
 #else
  #define CCONV
 #endif
#endif

typedef int (CCONV *PhidgetPointer)(void *);
typedef int (CCONV *PhidgetPointerStringOut)(void *, char **);
typedef int (CCONV *PhidgetPointerIntOut)(void *, int *);
typedef void (CCONV *PhidgetManagerCallback)(void *, void *, void *);
typedef void (CCONV *PhidgetValueCallback)(void *, void *, double);
typedef void (CCONV *PhidgetErrorCallback)(void *, void *, int, const char *);
typedef int (CCONV *PhidgetPointerCallbackPointer)(void *,
                                                   PhidgetManagerCallback,
                                                   void *);
typedef int (CCONV *PhidgetPointerVCPointer)(void *,
                                             PhidgetValueCallback,
                                             void *);
typedef int (CCONV *PhidgetPointerIntIn)(void *, int);
typedef int (CCONV *PhidgetPointerECPointer)(void *, PhidgetErrorCallback,
                                              void *);

@ These are used to define function pointers that will be used to
communicate with the library.

@<Phidget22 function pointers@>=
PhidgetPointer createManager;
PhidgetPointerCallbackPointer setOnAttachManager;
PhidgetPointerCallbackPointer setOnDetachManager;
PhidgetPointer openManager;
PhidgetPointerStringOut getDeviceName;
PhidgetPointerIntOut getDeviceSerialNumber;
PhidgetPointerIntOut getChannel;
PhidgetPointerIntOut getChannelClass;
PhidgetPointerIntOut getChannelSubclass;
PhidgetPointerIntOut getHubPort;
PhidgetPointer closeManager;
PhidgetPointer deleteManager;

@ These pointers must be initialized before they can be used.

@<Initialize phidget22 function pointers@>=
if((createManager = (PhidgetPointer) driver.resolve("PhidgetManager_create")) == 0 ||
   (setOnAttachManager = (PhidgetPointerCallbackPointer) driver.resolve("PhidgetManager_setOnAttachHandler")) == 0 ||
   (setOnDetachManager = (PhidgetPointerCallbackPointer) driver.resolve("PhidgetManager_setOnDetachHandler")) == 0 ||
   (openManager = (PhidgetPointer) driver.resolve("PhidgetManager_open")) == 0 ||
   (getDeviceName = (PhidgetPointerStringOut) driver.resolve("Phidget_getDeviceName")) == 0 ||
   (getDeviceSerialNumber = (PhidgetPointerIntOut) driver.resolve("Phidget_getDeviceSerialNumber")) == 0 ||
   (getChannel = (PhidgetPointerIntOut) driver.resolve("Phidget_getChannel")) == 0 ||
   (getChannelClass = (PhidgetPointerIntOut) driver.resolve("Phidget_getChannelClass")) == 0 ||
   (getChannelSubclass = (PhidgetPointerIntOut) driver.resolve("Phidget_getChannelSubclass")) == 0 ||
   (getHubPort = (PhidgetPointerIntOut) driver.resolve("Phidget_getHubPort")) == 0 ||
   (closeManager = (PhidgetPointer) driver.resolve("PhidgetManager_close")) == 0 ||
   (deleteManager = (PhidgetPointer) driver.resolve("PhidgetManager_delete")) == 0)
{
	QMessageBox::critical(NULL, tr("Typica: Link error"),
	                      tr("Failed to link a required symbol in phidget22."));
	return;
}

@ The constuctor sets up a manager so that appropriate channels can be added to
the combo box.

@<Phidget implementation@>=
PhidgetChannelSelector::PhidgetChannelSelector(int channeltype) :
	QComboBox(), typefilter(channeltype), manager(NULL)
{
#if __APPLE__
	driver.setFileName("Phidget22.framework/Phidget22");
#else
	driver.setFileName("phidget22");
#endif
	if(!driver.load())
	{
		QMessageBox::critical(NULL, tr("Typica: Driver not found"),
		                      tr("Failed to find phidget22. Please install it."));
		return;
	}
	@<Initialize phidget22 function pointers@>@;
	createManager(&manager);
	setOnAttachManager(manager, ChannelListAddChannel, this);
	setOnDetachManager(manager, ChannelListRemoveChannel, this);
	openManager(manager);
}

@ The callbacks registered in the constructor pass a pointer to the combo box
so that contents can be updated from the relevant global functions.

@<Additional functions@>=
void CCONV ChannelListAddChannel(void *, void *context, void *device)
{
	PhidgetChannelSelector *list =
		qobject_cast<PhidgetChannelSelector*>((QObject*)context);
	list->addChannel(device);
}

void CCONV ChannelListRemoveChannel(void *, void *context, void *device)
{
	PhidgetChannelSelector *list =
		qobject_cast<PhidgetChannelSelector*>((QObject*)context);
	list->removeChannel(device);
}

@ These require function prototypes.

@<Additional function prototypes@>=
void CCONV ChannelListAddChannel(void *manager, void *context, void *device);
void CCONV ChannelListRemoveChannel(void *manager, void *context,
                                    void *device);

@ Adding and removing channels from the list happens in class where pointers
to the required library functions are known.

@<Phidget implementation@>=
void PhidgetChannelSelector::addChannel(void *device)
{
	char *deviceName;
	int deviceSerialNumber;
	int channel;
	int channelClass;
	int channelSubclass;
	int hubPort;
	
	getDeviceName(device, &deviceName);
	getDeviceSerialNumber(device, &deviceSerialNumber);
	getChannel(device, &channel);
	getChannelClass(device, &channelClass);
	getChannelSubclass(device, &channelSubclass);
	getHubPort(device, &hubPort);
	
	QMap<QString,QVariant> itemData;
	
	if(typefilter != 0 && channelClass == typefilter)
	{
		itemData.insert("serialNumber", QString("%1").arg(deviceSerialNumber));
		itemData.insert("channel", QString("%1").arg(channel));
		itemData.insert("class", QString("%1").arg(channelClass));
		itemData.insert("subclass", 
		                QString("%1").arg(channelSubclass));
		itemData.insert("hubport", QString("%1").arg(hubPort));
		addItem(QString("%1: %2").arg(deviceName).arg(channel),
		        QVariant(itemData));
	}
}

@ On removal, no attempt is made to match each call to the exact channel
referenced. Rather, the assumption is that all channels on a device with a
matching serial number should be removed at once and in the case of a
multi-channel device getting removed, subsequent calls will just fail to match
anything. The most common expected scenario is that only one device will be
connected or not connected, so removing this results in an empty list for
channels that were removed early.

@<Phidget implementation@>=
void PhidgetChannelSelector::removeChannel(void *device)
{
	int deviceSerialNumber;
	
	getDeviceSerialNumber(device, &deviceSerialNumber);
	
	for(int i = count() - 1; i >= 0; i--)
	{
		QMap<QString,QVariant> data = itemData(i).toMap();
		if(data.value("serialNumber").toInt() == deviceSerialNumber)
		{
			removeItem(i);
		}
	}
}

@ A destructor closes and deletes the manager.

@<Phidget implementation@>=
PhidgetChannelSelector::~PhidgetChannelSelector()
{
	if(manager != NULL)
	{
		closeManager(manager);
		deleteManager(&manager);
	}
}
                                                   
@ Channel configuration provides a |PhidgetChannelSelector| for choosing
among connected devices but also displays the relevant configuration data.

This class only deals with temperature channels as that was the only channel
type originally supported. Other configuration classes should be used for
other channel types to allow type specific configuration options to be
presented sensibly.
                                                   
@<Class declarations@>=
class PhidgetChannelConfWidget : public BasicDeviceConfigurationWidget
{
	Q_OBJECT
	public:
		Q_INVOKABLE PhidgetChannelConfWidget(DeviceTreeModel *model,
		                                     const QModelIndex &index);
	public slots:
		void changeSelectedChannel(int index);
		void updateSerialNumber(const QString &value);
		void updateChannel(const QString &value);
		void updateHubPort(const QString &value);
		void updateColumnName(const QString &value);
		void updateChannelType(int value);
		void updateTCType(int value);
		void updateRTDType(int value);
		void updateRTDWiring(int value);
		void updateHidden(int value);
	private:
		PhidgetChannelSelector *channelSelector;
		QLineEdit *serialNumber;
		QLineEdit *channel;
		QLineEdit *hubPort;
		QComboBox *subtype;
		QStackedLayout *subtypeLayout;
		QComboBox *tctype;
		QComboBox *rtdtype;
		QComboBox *rtdwiring;
};

@ The constructor is responsible for setting up the interface.

@<Phidget implementation@>=
PhidgetChannelConfWidget::PhidgetChannelConfWidget(DeviceTreeModel *model,
                                                   const QModelIndex &index)
	: BasicDeviceConfigurationWidget(model, index),
	channelSelector(new PhidgetChannelSelector(28)),
	serialNumber(new QLineEdit),
	channel(new QLineEdit),
	hubPort(new QLineEdit),
	subtype(new QComboBox),
	subtypeLayout(new QStackedLayout),
	tctype(new QComboBox),
	rtdtype(new QComboBox),
	rtdwiring(new QComboBox)
{
	QVBoxLayout *outerLayout = new QVBoxLayout;
	QFormLayout *layout = new QFormLayout;
	QLineEdit *columnName = new QLineEdit;
	subtype->addItem(tr("IC"), QVariant(1));
	subtype->addItem(tr("RTD"), QVariant(32));
	subtype->addItem(tr("Thermocouple"), QVariant(33));
	layout->addRow(tr("Channels:"), channelSelector);
	layout->addRow(tr("Column Name:"), columnName);
	QCheckBox *hidden = new QCheckBox(tr("Hide channel"));
	layout->addRow(hidden);
	layout->addRow(tr("Serial Number:"), serialNumber);
	layout->addRow(tr("Hub Port:"), hubPort);
	layout->addRow(tr("Channel Number:"), channel);
	layout->addRow(tr("Channel Type:"), subtype);
	serialNumber->setEnabled(false);
	channel->setEnabled(false);
	subtype->setEnabled(false);
    outerLayout->addLayout(layout);
    QWidget *icconfiguration = new QWidget;
    QWidget *rtdconfiguration = new QWidget;
    QFormLayout *rtdconfigurationLayout = new QFormLayout;
    rtdtype->addItem(tr("PT100 with .00385 curve"), QVariant(1));
    rtdtype->addItem(tr("PT1000 with .00385 curve"), QVariant(2));
    rtdtype->addItem(tr("PT100 with .00392 curve"), QVariant(3));
    rtdtype->addItem(tr("PT1000 with .00392 curve"), QVariant(4));
    rtdconfigurationLayout->addRow(tr("RTD type:"), rtdtype);
    rtdwiring->addItem(tr("2 wire"), QVariant(1));
    rtdwiring->addItem(tr("3 wire"), QVariant(2));
    rtdwiring->addItem(tr("4 wire"), QVariant(3));
    rtdconfigurationLayout->addRow(tr("RTD wiring:"), rtdwiring);
    rtdconfiguration->setLayout(rtdconfigurationLayout);
    QWidget *tcconfiguration = new QWidget;
    QFormLayout *tcconfigurationLayout = new QFormLayout;
    tctype->addItem(tr("Type J"), QVariant(1));
    tctype->addItem(tr("Type K"), QVariant(2));
    tctype->addItem(tr("Type E"), QVariant(3));
    tctype->addItem(tr("Type T"), QVariant(4));
    tcconfigurationLayout->addRow(tr("Thermocouple type:"), tctype);
    tcconfiguration->setLayout(tcconfigurationLayout);
    subtypeLayout->addWidget(icconfiguration);
    subtypeLayout->addWidget(rtdconfiguration);
    subtypeLayout->addWidget(tcconfiguration);
    
    @<Get device configuration data for current node@>@;
    for(int i = 0; i < configData.size(); i++)
    {
	    node = configData.at(i).toElement();
	    if(node.attribute("name") == "serialnumber")
	    {
		    serialNumber->setText(node.attribute("value"));
	    }
	    else if(node.attribute("name") == "channel")
	    {
		    channel->setText(node.attribute("value"));
	    }
	    else if(node.attribute("name") == "columnname")
	    {
		    columnName->setText(node.attribute("value"));
	    }
	    else if(node.attribute("name") == "channeltype")
	    {
		    subtype->setCurrentIndex(subtype->
			    findData(QVariant(node.attribute("value").toInt())));
		    subtypeLayout->setCurrentIndex(subtype->currentIndex());
	    }
	    else if(node.attribute("name") == "tctype")
	    {
		    tctype->setCurrentIndex(tctype->
			    findData(QVariant(node.attribute("value").toInt())));
	    }
	    else if(node.attribute("name") == "rtdtype")
	    {
		    rtdtype->setCurrentIndex(rtdtype->
			    findData(QVariant(node.attribute("value").toInt())));
	    }
	    else if(node.attribute("name") == "rtdwiring")
	    {
		    rtdwiring->setCurrentIndex(rtdwiring->
			    findData(QVariant(node.attribute("value").toInt())));
	    }
	    else if(node.attribute("name") == "hubport")
	    {
		    hubPort->setText(node.attribute("value"));
	    }
	    else if(node.attribute("name") == "hidden")
	    {
		    hidden->setCheckState(node.attribute("value") == "true" ? Qt::Checked : Qt::Unchecked);
	    }
    }
    outerLayout->addLayout(subtypeLayout);
	setLayout(outerLayout);
	updateSerialNumber(serialNumber->text());
	updateChannel(channel->text());
	updateColumnName(columnName->text());
	updateChannelType(subtype->currentIndex());
	updateTCType(tctype->currentIndex());
	updateRTDType(rtdtype->currentIndex());
	updateRTDWiring(rtdwiring->currentIndex());
	updateHubPort(hubPort->text());
	updateHidden(hidden->checkState());
	connect(channelSelector, SIGNAL(currentIndexChanged(int)),
	        this, SLOT(changeSelectedChannel(int)));
    connect(subtype, SIGNAL(currentIndexChanged(int)),
            subtypeLayout, SLOT(setCurrentIndex(int)));
    connect(serialNumber, SIGNAL(textChanged(QString)),
            this, SLOT(updateSerialNumber(QString)));
    connect(channel, SIGNAL(textChanged(QString)),
            this, SLOT(updateChannel(QString)));
    connect(columnName, SIGNAL(textEdited(QString)),
	        this, SLOT(updateColumnName(QString)));
    connect(subtype, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateChannelType(int)));
    connect(tctype, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateTCType(int)));
    connect(rtdtype, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateRTDType(int)));
    connect(rtdwiring, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateRTDWiring(int)));
    connect(hubPort, SIGNAL(textChanged(QString)),
            this, SLOT(updateHubPort(QString)));
    connect(hidden, SIGNAL(stateChanged(int)),
            this, SLOT(updateHidden(int)));
}

@ The combo box provides a convenient way to populate required configuration
fields with values that are not immediately obvious.

@<Phidget implementation@>=
void PhidgetChannelConfWidget::changeSelectedChannel(int index)
{
	QMap<QString,QVariant> data = channelSelector->itemData(index).toMap();
	serialNumber->setText(data.value("serialNumber").toString());
	channel->setText(data.value("channel").toString());
	subtype->setCurrentIndex(subtype->
		findData(QVariant(data.value("subclass").toString().toInt())));
	hubPort->setText(data.value("hubport").toString());
}

@ Channel configuration settings are persisted as they are updated.

@<Phidget implementation@>=
void PhidgetChannelConfWidget::updateSerialNumber(const QString &value)
{
	updateAttribute("serialnumber", value);
}

void PhidgetChannelConfWidget::updateChannel(const QString &value)
{
	updateAttribute("channel", value);
}

void PhidgetChannelConfWidget::updateColumnName(const QString &value)
{
	updateAttribute("columnname", value);
}

void PhidgetChannelConfWidget::updateChannelType(int value)
{
	updateAttribute("channeltype", subtype->itemData(value).toString());
}

void PhidgetChannelConfWidget::updateTCType(int value)
{
	updateAttribute("tctype", tctype->itemData(value).toString());
}

void PhidgetChannelConfWidget::updateRTDType(int value)
{
	updateAttribute("rtdtype", rtdtype->itemData(value).toString());
}

void PhidgetChannelConfWidget::updateRTDWiring(int value)
{
	updateAttribute("rtdwiring", rtdwiring->itemData(value).toString());
}

void PhidgetChannelConfWidget::updateHubPort(const QString &value)
{
	updateAttribute("hubport", value);
}

void PhidgetChannelConfWidget::updateHidden(int value)
{
	updateAttribute("hidden", value == 0 ? "false" : "true");
}

@ The current input channel is intended for devices that can measure 4-20mA
current signals. The output from such a channel is likely to be hidden and
redirected to something that bring those measurements into whatever scale the
signal represents. For example, the motivating hardware for this feature was a
device that used 4-20mA to represent an approximation of the Agtron Gourmet
Scale in the range of 25-95. Another potential use is measuring gas pressure,
in which case it would be desirable to present this in terms of an appropriate
pressure unit. Longer term it would be nice to add support for custom units and
allow different graphing configurations for different units.

@<Class declarations@>=
class PhidgetCurrentChannelConfWidget : BasicDeviceConfigurationWidget
{
	Q_OBJECT@;
	public:@/
		Q_INVOKABLE PhidgetCurrentChannelConfWidget(DeviceTreeModel *model,
		                                            const QModelIndex &index);
	public slots:@/
		void changeSelectedChannel(int index);
		void updateSerialNumber(const QString &value);
		void updateChannel(const QString &value);
		void updateHubPort(const QString &value);
		void updateColumnName(const QString &value);
		void updatePowerSupply(int value);
		void updateDataInterval(int value);
		void updateHidden(int value);
	private:@/
		PhidgetChannelSelector *channelSelector;
		QLineEdit *serialNumber;
		QLineEdit *channel;
		QLineEdit *hubPort;
		QComboBox *powerSupply;
};

@ The constructor is responsible for setting up the interface. This is
slightly simpler than the configuration for temperature inputs as instead of
requiring information about RTD types and wiring or thermocouple types, a
current input only requires selecting the power supply and data interval.

It might be a good idea to go back to the temperature channels and allow the
data interval to be set there as well instead of relying on the default
sample rate.

@<Phidget implementation@>=
PhidgetCurrentChannelConfWidget::PhidgetCurrentChannelConfWidget(
	DeviceTreeModel *model, const QModelIndex &index
) :
	BasicDeviceConfigurationWidget(model, index),
	channelSelector(new PhidgetChannelSelector(2)),
	serialNumber(new QLineEdit),
	channel(new QLineEdit),
	hubPort(new QLineEdit),
	powerSupply(new QComboBox)
{
	QFormLayout *layout = new QFormLayout;
	layout->addRow(tr("Channel:"), channelSelector);
	QLineEdit *columnName = new QLineEdit;
	layout->addRow(tr("Column Name:"), columnName);
	powerSupply->addItem(tr("12V"), QVariant(2));
	powerSupply->addItem(tr("24V"), QVariant(3));
	layout->addRow(tr("Power Supply:"), powerSupply);
	QSpinBox *dataInterval = new QSpinBox;
	dataInterval->setMinimum(20);
	dataInterval->setMaximum(1000);
	dataInterval->setValue(250);
	layout->addRow(tr("Data Interval:"), dataInterval);
	QCheckBox *hidden = new QCheckBox(tr("Hide channel"));
	layout->addRow(hidden);
	serialNumber->setEnabled(false);
	channel->setEnabled(false);
	hubPort->setEnabled(false);
	layout->addRow(tr("Serial Number:"), serialNumber);
	layout->addRow(tr("Channel Number:"), channel);
	layout->addRow(tr("Hub Port:"), hubPort);
	@<Get device configuration data for current node@>@;
	for(int i = 0; i < configData.size(); i++)
	{
		node = configData.at(i).toElement();
		if(node.attribute("name") == "serialnumber")
		{
			serialNumber->setText(node.attribute("value"));
		}
		else if(node.attribute("name") == "channel")
		{
			channel->setText(node.attribute("value"));
		}
		else if(node.attribute("name") == "columnname")
		{
			columnName->setText(node.attribute("value"));
		}
		else if(node.attribute("name") == "hidden")
		{
			hidden->setCheckState(node.attribute("value") == "true" ?
				Qt::Checked : Qt::Unchecked);
		}
		else if(node.attribute("name") == "powersupply")
		{
			powerSupply->setCurrentIndex(
				powerSupply->findData(
					QVariant(node.attribute("value").toInt())));
		}
		else if(node.attribute("name") == "datainterval")
		{
			dataInterval->setValue(node.attribute("value").toInt());
		}
	}
	setLayout(layout);
	updateSerialNumber(serialNumber->text());
	updateChannel(channel->text());
	updateColumnName(columnName->text());
	updateHubPort(hubPort->text());
	updateHidden(hidden->checkState());
	updatePowerSupply(powerSupply->currentIndex());
	updateDataInterval(dataInterval->value());
	connect(channelSelector, SIGNAL(currentIndexChanged(int)),
	        this, SLOT(changeSelectedChannel(int)));
	connect(serialNumber, SIGNAL(textChanged(QString)),
	        this, SLOT(updateSerialNumber(QString)));
	connect(channel, SIGNAL(textChanged(QString)),
	        this, SLOT(updateChannel(QString)));
	connect(columnName, SIGNAL(textChanged(QString)),
	        this, SLOT(updateColumnName(QString)));
	connect(hubPort, SIGNAL(textChanged(QString)),
	        this, SLOT(updateHubPort(QString)));
	connect(hidden, SIGNAL(stateChanged(int)),
	        this, SLOT(updateHidden(int)));
	connect(powerSupply, SIGNAL(currentIndexChanged(int)),
	        this, SLOT(updatePowerSupply(int)));
	connect(dataInterval, SIGNAL(valueChanged(int)),
	        this, SLOT(updateDataInterval(int)));
}

@ The combo box is responsible for setting a variety of required configuration
fields with values the user has no reasonable expectation of knowing.

@<Phidget implementation@>=
void PhidgetCurrentChannelConfWidget::changeSelectedChannel(int index)
{
	QMap<QString, QVariant> data = channelSelector->itemData(index).toMap();
	serialNumber->setText(data.value("serialNumber").toString());
	channel->setText(data.value("channel").toString());
	hubPort->setText(data.value("hubport").toString());
}

@ Channel configuration settings are persisted as they are updated as usual.

@<Phidget implementation@>=
void PhidgetCurrentChannelConfWidget::updateSerialNumber(const QString &value)
{
	updateAttribute("serialnumber", value);
}

void PhidgetCurrentChannelConfWidget::updateChannel(const QString &value)
{
	updateAttribute("channel", value);
}

void PhidgetCurrentChannelConfWidget::updateColumnName(const QString &value)
{
	updateAttribute("columnname", value);
}

void PhidgetCurrentChannelConfWidget::updateHubPort(const QString &value)
{
	updateAttribute("hubport", value);
}

void PhidgetCurrentChannelConfWidget::updateHidden(int value)
{
	updateAttribute("hidden", value == 0 ? "false" : "true");
}

void PhidgetCurrentChannelConfWidget::updatePowerSupply(int value)
{
	updateAttribute("powersupply", powerSupply->itemData(value).toString());
}

void PhidgetCurrentChannelConfWidget::updateDataInterval(int value)
{
	updateAttribute("datainterval", QString("%1").arg(value));
}

@ The hardware communnications code provides a single class that reads the
saved configuration data, creates |Channel| objects for the logging view to
connect various things to, and pushes data out on those channels. Internally,
there is more variability in how these channels must be set up, so rather than
just having a bunch of lists for the various properties, not all of which might
be relevant, instead, the channel configuration data will all be kept in a
structure.

@<Class declarations@>=
struct PhidgetChannelData
{
	Channel *channel;
	QString columnName;
	QString indicatorLabel;
	int serialNumber;
	int channelNumber;
	int majorType;
	int channelType;
	int hubPort;
	int dataInterval;
	// Set for temperature channels
	int tcType;
	int rtdType;
	int wiring;
	// Set for current channels
	int powerSupply;
	// Non-specialized
	bool hidden;
	void *device;
};

@ The host environment requires a class that handles communication with the
hardware. The public interface has been kept the same as the phidget21 code to
minimize changes required in the configuration files.

@<Class declarations@>=
class Phidget22 : public QObject
{
	Q_OBJECT
	public:
		Q_INVOKABLE Phidget22(const QModelIndex &deviceIndex);
		Q_INVOKABLE int channelCount();
		Channel* getChannel(int channel);
		Q_INVOKABLE bool isChannelHidden(int channel);
		Q_INVOKABLE QString channelColumnName(int channel);
		Q_INVOKABLE QString channelIndicatorText(int channel);
		Q_INVOKABLE QString channelType(int channel);
	public slots:
		void start();
		void stop();
	private:
		QList<PhidgetChannelData *> channelConfiguration;
		QLibrary driver;
		PhidgetPointer p_createTemperatureSensor;
		PhidgetPointer p_createCurrentSensor;
		PhidgetPointerIntIn p_setSerialNumber;
		PhidgetPointerIntIn p_setChannelNumber;
		PhidgetPointerIntIn p_setHubPort;
		PhidgetPointerIntIn p_setTCType;
		PhidgetPointerIntIn p_setRTDType;
		PhidgetPointerIntIn p_setRTDWiring;
		PhidgetPointerIntIn p_setCurrentPowerSupply;
		PhidgetPointerIntIn p_setCurrentDataInterval;
		PhidgetPointerVCPointer p_setNewDataCallback;
		PhidgetPointerVCPointer p_setCurrentNewDataCallback;
		PhidgetPointerIntIn p_open;
		PhidgetPointer p_close;
		PhidgetPointer p_delete;
		PhidgetPointerECPointer p_setOnErrorCallback;
};

@ The constructor reads the previously saved hardware configuration data and
uses that to create the relevant channels. The channels are not initialized
until the device is started.

@<Phidget implementation@>=
Phidget22::Phidget22(const QModelIndex &index) : QObject(NULL)
{
	DeviceTreeModel *model = (DeviceTreeModel *)(index.model());
	if(model->hasChildren(index))
	{
		for(int i = 0; i < model->rowCount(index); i++)
		{
			QModelIndex channelIndex = model->index(i, 0, index);
			QDomElement channelReference = model->
				referenceElement(model->data(channelIndex, 32).toString());
			QDomElement channelReferenceElement = model->
				referenceElement(model->
					data(channelIndex, Qt::UserRole).toString());
			QDomNodeList channelConfigData =
				channelReferenceElement.elementsByTagName("attribute");
			PhidgetChannelData *c = new PhidgetChannelData;
			c->channel = new Channel;
			c->indicatorLabel =
				model->data(channelIndex, Qt::DisplayRole).toString();
			c->device = NULL;
			c->hubPort = -1;
			c->dataInterval = -1;
			c->powerSupply = -1;
			if(channelReferenceElement.attribute("driver") == "phidgetchannel")
			{
				c->majorType = 28; // Temperature Input
			}
			else if(channelReferenceElement.attribute("driver") ==
			        "phidgetcurrentchannel")
			{
				c->majorType = 2; // Current Input
			}
			for(int j = 0; j < channelConfigData.size(); j++)
			{
				QDomElement node = channelConfigData.at(j).toElement();
				if(node.attribute("name") == "serialnumber")
				{
					c->serialNumber = node.attribute("value").toInt();
				}
				else if(node.attribute("name") == "channel")
				{
					c->channelNumber = node.attribute("value").toInt();
				}
				else if(node.attribute("name") == "channeltype")
				{
					c->channelType = node.attribute("value").toInt();
				}
				else if(node.attribute("name") == "tctype")
				{
					c->tcType = node.attribute("value").toInt();
				}
				else if(node.attribute("name") == "rtdtype")
				{
					c->rtdType = node.attribute("value").toInt();
				}
				else if(node.attribute("name") == "rtdwiring")
				{
					c->wiring = node.attribute("value").toInt();
				}
				else if(node.attribute("name") == "powersupply")
				{
					c->powerSupply = node.attribute("value").toInt();
				}
				else if(node.attribute("name") == "datainterval")
				{
					c->dataInterval = node.attribute("value").toInt();
				}
				else if(node.attribute("name") == "hidden")
				{
					c->hidden = (node.attribute("value") == "true");
				}
				else if(node.attribute("name") == "columnname")
				{
					c->columnName = node.attribute("value");
				}
				else if(node.attribute("name") == "hubport")
				{
					c->hubPort = node.attribute("value").toInt();
				}
			}
			channelConfiguration.append(c);
		}
	}
}

@ A bit of glue is needed to get the |Channel| objects out to the host
environment.

@<Phidget implementation@>=
int Phidget22::channelCount()
{
	return channelConfiguration.length();
}

Channel* Phidget22::getChannel(int channel)
{
	return channelConfiguration.at(channel)->channel;
}

@ A little more glue allows the host environment to properly set up UI
elements.

@<Phidget implementation@>=
bool Phidget22::isChannelHidden(int channel)
{
	return channelConfiguration.at(channel)->hidden;
}

QString Phidget22::channelColumnName(int channel)
{
	return channelConfiguration.at(channel)->columnName;
}

QString Phidget22::channelIndicatorText(int channel)
{
	return channelConfiguration.at(channel)->indicatorLabel;
}

QString Phidget22::channelType(int channel)
{
	return (channelConfiguration.at(channel)->majorType == 28 ? "T" : "C");
}

@ Once the hardware configuration has been read and the UI has been set up, we
can start talking to the hardware and start getting measurements.

Now that multiple channel types are supported which each require slightly
different initialization procedures, it would be nice to see if channel
initialization can be reordered to avoid repeatedly checking the channel type
without duplicating code. Alternately, shared features could be separated into
their own chunks.

@<Phidget implementation@>=
void Phidget22::start()
{
	@<Load Phidget22 library@>@;
	@<Resolve Phidget22 function pointers@>@;
	
	for(int i = 0; i < channelConfiguration.length(); i++)
	{
		PhidgetChannelData *c = channelConfiguration.at(i);
		switch(c->majorType)
		{
			case 2:
				p_createCurrentSensor(&(c->device));
				p_setOnErrorCallback(c->device,
				                     Phidget22CurrentErrorCallback,
									 c->channel);
				break;
			case 28:
				p_createTemperatureSensor(&(c->device));
				break;
			default:
				break;
		}
		p_setSerialNumber(c->device, c->serialNumber);
		p_setChannelNumber(c->device, c->channelNumber);
		if(c->majorType == 28) //Set up temperature channel
		{
			switch(c->channelType)
			{
				case 32:
					p_setRTDType(c->device, c->rtdType);
					p_setRTDWiring(c->device, c->wiring);
					break;
				case 33:
					p_setTCType(c->device, c->tcType);
					break;
				default:
					break;
			}
		}
		if(c->hubPort >= 0)
		{
			p_setHubPort(c->device, c->hubPort);
		}
		switch(c->majorType)
		{
			case 2:
				p_setCurrentNewDataCallback(c->device,
				                            Phidget22CurrentValueCallback,
				                            c->channel);
				break;
			case 28:
				p_setNewDataCallback(c->device, Phidget22ValueCallback, c->channel);
				break;
			default:
				break;
		}
		p_open(c->device, 5000);
		/* The data interval must be set after opening the channel, otherwise
		   the change has no effect. */
		if(c->majorType == 2)
		{
			p_setCurrentPowerSupply(c->device, c->powerSupply);
			p_setCurrentDataInterval(c->device, c->dataInterval);
		}
	}
}

@ The library we need is slightly different depending on the current platform.
If the library is not installed, an error is displayed.

@<Load Phidget22 library@>=
#if __APPLE__
	driver.setFileName("Phidget22.framework/Phidget22");
#else
	driver.setFileName("phidget22");
#endif
if(!driver.load())
{
	QMessageBox::critical(NULL, tr("Typica: Driver not found"),
	                      tr("Failed to find phidget22. Please install it."));
	return;
}

@ Several function pointers are required to call into the library. If any of
these fail to resolve, the most likely cause is that an incompatible library
with the same name has been installed.

@<Resolve Phidget22 function pointers@>=
if((p_createTemperatureSensor = (PhidgetPointer)driver.resolve("PhidgetTemperatureSensor_create")) == 0 ||
	(p_createCurrentSensor = (PhidgetPointer)driver.resolve("PhidgetCurrentInput_create")) == 0 ||
	(p_setSerialNumber = (PhidgetPointerIntIn)driver.resolve("Phidget_setDeviceSerialNumber")) == 0 ||
	(p_setChannelNumber = (PhidgetPointerIntIn)driver.resolve("Phidget_setChannel")) == 0 ||
	(p_setTCType = (PhidgetPointerIntIn)driver.resolve("PhidgetTemperatureSensor_setThermocoupleType")) == 0 ||
	(p_setRTDType = (PhidgetPointerIntIn)driver.resolve("PhidgetTemperatureSensor_setRTDType")) == 0 ||
	(p_setRTDWiring = (PhidgetPointerIntIn)driver.resolve("PhidgetTemperatureSensor_setRTDWireSetup")) == 0 ||
	(p_setCurrentPowerSupply = (PhidgetPointerIntIn)driver.resolve("PhidgetCurrentInput_setPowerSupply")) == 0 ||
	(p_setCurrentDataInterval = (PhidgetPointerIntIn)driver.resolve("PhidgetCurrentInput_setDataInterval")) == 0 ||
	(p_setNewDataCallback = (PhidgetPointerVCPointer)driver.resolve("PhidgetTemperatureSensor_setOnTemperatureChangeHandler")) == 0 ||
	(p_setCurrentNewDataCallback = (PhidgetPointerVCPointer)driver.resolve("PhidgetCurrentInput_setOnCurrentChangeHandler")) == 0 ||
	(p_open = (PhidgetPointerIntIn)driver.resolve("Phidget_openWaitForAttachment")) == 0 ||
	(p_close = (PhidgetPointer)driver.resolve("Phidget_close")) == 0 ||
	(p_delete = (PhidgetPointer)driver.resolve("PhidgetTemperatureSensor_delete")) == 0 ||
	(p_setHubPort = (PhidgetPointerIntIn)driver.resolve("Phidget_setHubPort")) == 0 ||
	(p_setOnErrorCallback = (PhidgetPointerECPointer)driver.resolve("Phidget_setOnErrorHandler")) == 0)
{
	QMessageBox::critical(NULL, tr("Typica: Link error"),
	                      tr("Failed to link a required symbol in phidget22."));
	return;
}

@ New values are delivered to a callback function outside of the class, but
with a pointer to the relevant |Channel| object. This means that all the
callback needs to do is perform the unit conversion, assemble the |Measurement|
and send that out.

Unfortunately, there can be no guarantee that new measurements will be
available on all channels simultaneously. Hopefully this will not be too
problematic.

Temperature values and current values are handled separately with the
former requiring a conversion into Fahrenheit and the latter providing a
conversion into mA as the most common use is expected to be reading from
4-20mA sensors. Additional input types might require their own callbacks. For
example, a voltage input callback might not perform any conversion.

For current channels, the initial use case potentially uses the entire 0-20mA
range, which can result in errors being generated instead of measurements. Out
of range and saturation errors should be converted to 0 and 20 respectively.
This may be the wrong call if someone wants to use a larger range current
sensor such as 30A, but until someone provides a concrete use case I'm not
going to worry about that.

@<Additional functions@>=
void CCONV Phidget22ValueCallback(void *, void *context, double value)
{
	Channel *channel = (Channel*)context;
	QTime time = QTime::currentTime();
	Measurement measure(value * 9.0 / 5.0 + 32.0, time);
	channel->input(measure);
}

void CCONV Phidget22CurrentValueCallback(void *, void *context, double value)
{
	Channel *channel = (Channel*)context;
	QTime time = QTime::currentTime();
	Measurement measure(value * 1000.0, time, Units::Unitless);
	channel->input(measure);
}

void CCONV Phidget22CurrentErrorCallback(void *, void *context, int error,
                                         const char *)
{
	Channel *channel = (Channel*)context;
	QTime time = QTime::currentTime();
	switch(error)
	{
		case 4103: // Measurement below valid range
			{
				Measurement measure(0.0, time, Units::Unitless);
				channel->input(measure);
			}
			break;
		case 4105: // Measurement above valid range
			{
				Measurement measure(20.0, time, Units::Unitless);
				channel->input(measure);
			}
			break;
		default:
			break;
	}
}

@ Function prototypes are provided.

@<Additional function prototypes@>=
void CCONV Phidget22ValueCallback(void *device, void *context, double value);
void CCONV Phidget22CurrentValueCallback(void *device, void *context,
                                         double value);
void CCONV Phidget22CurrentErrorCallback(void *device, void *context,
                                         int error, const char *description);

@ When the logging window is closed, it is important to close all open channels
and delete their handles.

@<Phidget implementation@>=
void Phidget22::stop()
{
	for(int i = 0; i < channelConfiguration.length(); i++)
	{
		PhidgetChannelData *c = channelConfiguration.at(i);
		p_close(c->device);
		p_delete(&(c->device));
	}
}

@ Class implementations are currently folded into typica.cpp.

@<Class implementations@>=
@<Phidget implementation@>@;

@ The hardware communications class needs to be available from the host
environment.

@<Set up the scripting engine@>=
constructor = engine->newFunction(constructPhidget22);
value = engine->newQMetaObject(&Phidget22::staticMetaObject, constructor);
engine->globalObject().setProperty("Phidget22", value);

@ Two function prototypes are needed.

@<Function prototypes for scripting@>=
QScriptValue constructPhidget22(QScriptContext *context, QScriptEngine *engine);
QScriptValue Phidget22_getChannel(QScriptContext *context, QScriptEngine *engine);

@ The constructor is trivial.

@<Functions for scripting@>=
QScriptValue constructPhidget22(QScriptContext *context, QScriptEngine *engine)
{
	if(context->argumentCount() != 1)
	{
		context->throwError("Incorrect number of arguments");
	}
	QScriptValue object = engine->newQObject(new Phidget22(argument<QModelIndex>(0, context)), QScriptEngine::ScriptOwnership);
	setQObjectProperties(object, engine);
	object.setProperty("getChannel", engine->newFunction(Phidget22_getChannel));
	return object;
}

@ A wrapper is used for getting channels.

@<Functions for scripting@>=
QScriptValue Phidget22_getChannel(QScriptContext *context, QScriptEngine *engine)
{
	Phidget22 *self = getself<Phidget22 *>(context);
	QScriptValue object;
	if(self)
	{
		object = engine->newQObject(self->getChannel(argument<int>(0, context)));
		setChannelProperties(object, engine);
	}
	return object;
}

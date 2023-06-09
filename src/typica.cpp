/*3:*/
#line 522 "./typica.w"

#define PROGRAM_NAME "Typica"

/*5:*/
#line 622 "./typica.w"

#include <QtCore> 
#include <QtGui> 
#include <QtScript> 
#include <QtScriptTools> 
#include <QtXml> 
#include <QtSql> 
#include <QtDebug> 
#include <QtXmlPatterns> 
#include <QtWebKit> 
#include <QtSvg> 
#include <QtNetwork> 

/*:5*//*6:*/
#line 639 "./typica.w"

#include "helpmenu.h"

/*:6*//*311:*/
#line 6960 "./typica.w"

#include "units.h"

#line 1 "./measurement.w"
/*:311*//*584:*/
#line 217 "./webview.w"

#include "webview.h"

/*:584*//*597:*/
#line 395 "./webview.w"

#include "webelement.h"

#line 13003 "./typica.w"

#line 1 "./printerselector.w"
/*:597*//*599:*/
#line 40 "./printerselector.w"

#include "printerselector.h"

/*:599*//*730:*/
#line 487 "./daterangeselector.w"

#include "daterangeselector.h"
#line 14891 "./typica.w"

/*:730*//*838:*/
#line 17462 "./typica.w"

#include "qextserialport.h"
#include "qextserialenumerator.h"

/*:838*//*1068:*/
#line 124 "./dataqsdk.w"

#ifdef Q_OS_WIN32
#include <windef.h> 
#else
#define PASCAL
#endif

/*:1068*//*1092:*/
#line 862 "./dataqsdk.w"

#include <limits> 

/*:1092*//*1107:*/
#line 62 "./scales.w"

#include "draglabel.h"

/*:1107*//*1122:*/
#line 361 "./scales.w"

#include "scale.h"

/*:1122*/
#line 525 "./typica.w"

/*986:*/
#line 114 "./phidget22.w"

#if defined(__stdcall)
#define CCONV __stdcall
#else
#if defined(_MSC_VER)
#define CCONV __stdcall
#else
#define CCONV
#endif
#endif

typedef int(CCONV*PhidgetPointer)(void*);
typedef int(CCONV*PhidgetPointerStringOut)(void*,char**);
typedef int(CCONV*PhidgetPointerIntOut)(void*,int*);
typedef void(CCONV*PhidgetManagerCallback)(void*,void*,void*);
typedef void(CCONV*PhidgetValueCallback)(void*,void*,double);
typedef int(CCONV*PhidgetPointerCallbackPointer)(void*,
PhidgetManagerCallback,
void*);
typedef int(CCONV*PhidgetPointerVCPointer)(void*,
PhidgetValueCallback,
void*);
typedef int(CCONV*PhidgetPointerIntIn)(void*,int);

/*:986*/
#line 526 "./typica.w"

/*991:*/
#line 220 "./phidget22.w"

void CCONV ChannelListAddChannel(void*manager,void*context,void*device);
void CCONV ChannelListRemoveChannel(void*manager,void*context,
void*device);

/*:991*//*1006:*/
#line 773 "./phidget22.w"

void CCONV Phidget22ValueCallback(void*device,void*context,double value);

/*:1006*/
#line 527 "./typica.w"

/*26:*/
#line 1070 "./typica.w"

class ScriptQMainWindow:public QMainWindow
{
Q_OBJECT
Q_PROPERTY(QString closePrompt READ closePrompt WRITE setClosePrompt)
public:
ScriptQMainWindow();
QString closePrompt();
public slots:
void show();
void saveSizeAndPosition(const QString&key);
void restoreSizeAndPosition(const QString&key);
void displayStatus(const QString&message= QString());
void setClosePrompt(QString prompt);
void setupFinished();
signals:
void aboutToClose(void);
void windowReady(void);
protected:
void closeEvent(QCloseEvent*event);
void showEvent(QShowEvent*event);
private:
QString cprompt;
};

/*:26*//*179:*/
#line 4086 "./typica.w"

class SqlQueryConnection:public QSqlQuery
{
public:
SqlQueryConnection(const QString&query= QString());
~SqlQueryConnection();
QSqlQuery*operator->()const;
private:
QString connection;
QSqlQuery*q;
};

/*:179*//*257:*/
#line 6101 "./typica.w"

class NumericDelegate:public QItemDelegate
{
Q_OBJECT
public:
NumericDelegate(bool positiveOnly= false,QObject*parent= NULL);
QWidget*createEditor(QWidget*parent,
const QStyleOptionViewItem&option,
const QModelIndex&index)const;
void setEditorData(QWidget*editor,const QModelIndex&index)const;
void setModelData(QWidget*editor,QAbstractItemModel*model,
const QModelIndex&index)const;
void updateEditorGeometry(QWidget*editor,
const QStyleOptionViewItem&option,
const QModelIndex&index)const;
private:
bool m_positiveOnly;
};

/*:257*//*263:*/
#line 6210 "./typica.w"

class ScriptValidator:public QValidator
{
Q_OBJECT
public:
ScriptValidator(QValidator*validator,QObject*parent= NULL);
void fixup(QString&input)const;
QValidator::State validate(QString&input,int&pos)const;
private:
QValidator*v;
};

/*:263*//*307:*/
#line 438 "./units.w"

Q_DECLARE_METATYPE(Units::Unit)

/*:307*//*312:*/
#line 19 "./measurement.w"

class Measurement:public QVariantMap
{
public:
Measurement(double temperature= 0,QTime time= QTime(),
Units::Unit sc= Units::Fahrenheit);
Measurement(double temperature);
double temperature()const;
QTime time()const;
void setTemperature(double temperature);
void setTime(QTime time);
void setUnit(Units::Unit scale);
Units::Unit scale()const;
Measurement toFahrenheit();
Measurement toCelsius();
Measurement toKelvin();
Measurement toRankine();
};

/*:312*//*316:*/
#line 128 "./measurement.w"

Q_DECLARE_METATYPE(Measurement)

/*:316*//*323:*/
#line 7024 "./typica.w"

class Channel;
class DAQImplementation;

class DAQ:public QObject
{
Q_OBJECT
Q_ENUMS(ThermocoupleType)
DAQImplementation*imp;
private slots:
void threadFinished();
public:
DAQ(QString device,const QString&driver= QString("nidaqmxbase"));
~DAQ();
Channel*newChannel(int units,int thermocouple);
Q_INVOKABLE void setClockRate(double Hz);
Q_INVOKABLE void start();
Q_INVOKABLE void stop();
enum ThermocoupleType
{
TypeJ= 10072,
TypeK= 10073,
TypeN= 10077,
TypeR= 10082,
TypeS= 10085,
TypeT= 10086,
TypeB= 10047,
TypeE= 10055
};
};

/*:323*//*324:*/
#line 7062 "./typica.w"

class DAQImplementation:public QThread
{
Q_OBJECT
public:
DAQImplementation(const QString&driverinfo);
~DAQImplementation();
void run();
void measure();
/*325:*/
#line 7082 "./typica.w"

typedef int(*daqfp)(...);
daqfp read;
daqfp errorInfo;
daqfp startTask;
daqfp createTask;
daqfp createChannel;
daqfp setClock;
daqfp stopTask;
daqfp clearTask;
daqfp resetDevice;
daqfp waitForMeasurement;

/*:325*/
#line 7071 "./typica.w"

/*326:*/
#line 7098 "./typica.w"

bool useBase;
QString device;
QVector<Channel*> channelMap;
unsigned int handle;
int error;
int channels;
bool ready;
QLibrary driver;
QVector<Units::Unit> unitMap;

/*:326*/
#line 7072 "./typica.w"

};

/*:324*//*342:*/
#line 7603 "./typica.w"

class FakeDAQImplementation:public QThread
{
Q_OBJECT
public:
FakeDAQImplementation();
~FakeDAQImplementation();
void run();
void measure();
QVector<Channel*> channelMap;
int channels;
bool ready;
double clockRate;
};

class FakeDAQ:public QObject
{
Q_OBJECT
FakeDAQImplementation*imp;
public:
FakeDAQ(QString device);
~FakeDAQ();
Channel*newChannel(int units,int thermocouple);
Q_INVOKABLE void setClockRate(double Hz);
Q_INVOKABLE void start();
};

/*:342*//*349:*/
#line 7790 "./typica.w"

class Channel:public QObject
{
Q_OBJECT
public:
Channel();
~Channel();
public slots:
void input(Measurement measurement);
signals:
void newData(Measurement);
};

/*:349*//*353:*/
#line 7857 "./typica.w"

class LinearCalibrator:public QObject
{
Q_OBJECT
Q_PROPERTY(double measuredLower READ measuredLower
WRITE setMeasuredLower)
Q_PROPERTY(double measuredUpper READ measuredUpper
WRITE setMeasuredUpper)
Q_PROPERTY(double mappedLower READ mappedLower WRITE setMappedLower)
Q_PROPERTY(double mappedUpper READ mappedUpper WRITE setMappedUpper)
Q_PROPERTY(bool closedRange READ isClosedRange WRITE setClosedRange)
Q_PROPERTY(double sensitivity READ sensitivity WRITE setSensitivity)
public:
LinearCalibrator(QObject*parent= NULL);
double measuredLower();
double measuredUpper();
double mappedLower();
double mappedUpper();
bool isClosedRange();
double sensitivity();
public slots:
void setMeasuredLower(double lower);
void setMeasuredUpper(double upper);
void setMappedLower(double lower);
void setMappedUpper(double upper);
void setClosedRange(bool closed);
void setSensitivity(double sensitivity);
Measurement newMeasurement(Measurement measure);
signals:
void measurement(Measurement measure);
void newData(Measurement measure);
private:
double Lo1;
double Lo2;
double Up1;
double Up2;
double sensitivitySetting;
bool clamp;
};

/*:353*//*360:*/
#line 8053 "./typica.w"

class LinearSplineInterpolator:public QObject
{
Q_OBJECT
public:
LinearSplineInterpolator(QObject*parent= NULL);
Q_INVOKABLE void add_pair(double source,double destination);
public slots:
Measurement newMeasurement(Measurement measure);
signals:
void newData(Measurement measure);
private:
void make_interpolators();
QMap<double,double> *pairs;
QList<LinearCalibrator*> *interpolators;
};

/*:360*//*365:*/
#line 8189 "./typica.w"

class TemperatureDisplay:public QLCDNumber
{
Q_OBJECT
int unit;
bool r;
public:
TemperatureDisplay(QWidget*parent= NULL);
~TemperatureDisplay();
public slots:
void setValue(Measurement temperature);
void invalidate();
void setDisplayUnits(Units::Unit scale);
void setRelativeMode(bool relative);
};

/*:365*//*376:*/
#line 8408 "./typica.w"

class MeasurementTimeOffset:public QObject
{
Q_OBJECT
QTime epoch;
QTime previous;
bool hasPrevious;
public:
MeasurementTimeOffset(QTime zero);
QTime zeroTime();
public slots:
void newMeasurement(Measurement measure);
void setZeroTime(QTime zero);
signals:
void measurement(Measurement measure);
};

/*:376*//*383:*/
#line 8560 "./typica.w"

class ThresholdDetector:public QObject
{
Q_OBJECT
Q_ENUMS(EdgeDirection)
public:
enum EdgeDirection{
Ascending,Descending
};
ThresholdDetector(double value);
public slots:
void newMeasurement(Measurement measure);
void setThreshold(double value);
void setEdgeDirection(EdgeDirection direction);
signals:
void timeForValue(double);
private:
bool previousValueValid;
double previousValue;
double threshold;
EdgeDirection currentDirection;
};

/*:383*//*388:*/
#line 8676 "./typica.w"

class ZeroEmitter:public QObject
{
Q_OBJECT
Q_PROPERTY(int column READ column WRITE setColumn)
Measurement cache;
int col;
public:
ZeroEmitter(int tempcolumn= 1);
int column();
double lastTemperature();
public slots:
void newMeasurement(Measurement measure);
void setColumn(int column);
void emitZero();
signals:
void measurement(Measurement measure,int tempcolumn);
};

/*:388*//*393:*/
#line 8770 "./typica.w"

class MeasurementAdapter:public QObject
{
Q_OBJECT
int col;
public:
MeasurementAdapter(int tempcolumn);
int column();
public slots:
void newMeasurement(Measurement measure);
void setColumn(int column);
signals:
void measurement(Measurement measure,int tempcolumn);
};

/*:393*//*398:*/
#line 8859 "./typica.w"

class GraphView:public QGraphicsView
{
Q_OBJECT
QGraphicsScene*theScene;
QMap<int,QList<QGraphicsLineItem*> *> *graphLines;
QMap<int,QPointF> *prevPoints;
QMap<int,double> *translations;
QList<QGraphicsItem*> *gridLinesF;
QList<QGraphicsItem*> *gridLinesC;
QList<QGraphicsItem*> *relativeGridLines;
bool relativeEnabled;
bool timeIndicatorEnabled;
QGraphicsLineItem*timeLine;
LinearSplineInterpolator*relativeAdjuster;
public:
GraphView(QWidget*parent= NULL);
void removeSeries(int column);
protected:
void resizeEvent(QResizeEvent*event);
public slots:
void newMeasurement(Measurement measure,int tempcolumn);
void setSeriesTranslation(int column,double offset);
void setTimeIndicatorEnabled(bool enabled);
void clear();
void showF();
void showC();
};

/*:398*//*415:*/
#line 9327 "./typica.w"

class MeasurementModel;
class ZoomLog:public QTableView
{
Q_OBJECT
/*416:*/
#line 9376 "./typica.w"

MeasurementModel*model_ms;
MeasurementModel*model_1s;
MeasurementModel*model_5s;
MeasurementModel*model_10s;
MeasurementModel*model_15s;
MeasurementModel*model_30s;
MeasurementModel*model_1m;
QList<MeasurementModel*> modelSet;
QHash<int,Measurement> lastMeasurement;
MeasurementModel*currentModel;
QList<int> saveTempCols;
QList<int> saveControlCols;
QList<int> saveNoteCols;
QList<int> currentColumnSet;

/*:416*/
#line 9332 "./typica.w"

void switchLOD(MeasurementModel*m);
private slots:
void centerOn(int row);
void persistColumnResize(int column,int oldsize,int newsize);
void restoreColumnWidths();
public:
ZoomLog();
QVariant data(int row,int column)const;
Q_INVOKABLE int rowCount();
bool saveXML(QIODevice*device);
bool saveCSV(QIODevice*device);
QString lastTime(int series);
Q_INVOKABLE Units::Unit displayUnits();
public slots:
void setVisible(bool visibility);
void setHeaderData(int section,QString text);
void LOD_ms();
void LOD_1s();
void LOD_5s();
void LOD_10s();
void LOD_15s();
void LOD_30s();
void LOD_1m();
void newMeasurement(Measurement measure,int tempcolumn);
void newAnnotation(QString annotation,int tempcolumn,
int annotationcolumn);
void clear();
void addOutputTemperatureColumn(int column);
void addOutputControlColumn(int column);
void addOutputAnnotationColumn(int column);
void clearOutputColumns();
void setDisplayUnits(Units::Unit scale);
void addToCurrentColumnSet(int column);
void clearCurrentColumnSet();
protected:
virtual void showEvent(QShowEvent*event);
};

/*:415*//*441:*/
#line 10081 "./typica.w"

class MeasurementList;
class MeasurementModel:public QAbstractItemModel
{
Q_OBJECT
Units::Unit unit;
QList<MeasurementList*> *entries;
QStringList*hData;
int colcount;
QHash<int,int> *lastTemperature;
QList<MeasurementList*> ::iterator lastInsertion;
QHash<int,bool> *controlColumns;
public:
MeasurementModel(QObject*parent= NULL);
~MeasurementModel();
int rowCount(const QModelIndex&parent= QModelIndex())const;
int columnCount(const QModelIndex&parent= QModelIndex())const;
bool setHeaderData(int section,Qt::Orientation orientation,
const QVariant&value,int role= Qt::DisplayRole);
QVariant data(const QModelIndex&index,int role)const;
bool setData(const QModelIndex&index,const QVariant&value,
int role= Qt::EditRole);
Qt::ItemFlags flags(const QModelIndex&index)const;
QVariant headerData(int section,Qt::Orientation orientation,
int role= Qt::DisplayRole)const;
QModelIndex index(int row,int column,
const QModelIndex&parent= QModelIndex())const;
QModelIndex parent(const QModelIndex&index)const;
Units::Unit displayUnits();
public slots:
void newMeasurement(Measurement measure,int tempcolumn);
void newAnnotation(QString annotation,int tempcolumn,
int annotationColumn);
void clear();
void setDisplayUnits(Units::Unit scale);
signals:
void rowChanged(int);
};

/*:441*//*442:*/
#line 10125 "./typica.w"

class MeasurementList:public QVariantList
{
public:
bool operator<(const MeasurementList&other)const;
bool operator==(const MeasurementList&other)const;
};

/*:442*//*468:*/
#line 10783 "./typica.w"

class AnnotationButton:public QPushButton
{
Q_OBJECT
QString noteTemplate;
QString note;
int tc;
int ac;
int count;
QString batch;
public:
AnnotationButton(const QString&text,QWidget*parent= NULL);
public slots:
void setAnnotation(const QString&annotation);
void setTemperatureColumn(int tempcolumn);
void setAnnotationColumn(int annotationcolumn);
void annotate();
void resetCount();
void resetBatch();
void incrementBatch();
signals:
void annotation(QString annotation,int tempcolumn,
int notecolumn);
};

/*:468*//*478:*/
#line 10963 "./typica.w"

class AnnotationSpinBox:public QDoubleSpinBox
{
Q_OBJECT
QString pretext;
QString posttext;
int tc;
int ac;
bool change;
public:
AnnotationSpinBox(const QString&pret,const QString&postt,
QWidget*parent= NULL);
public slots:
void setPretext(const QString&pret);
void setPosttext(const QString&postt);
void setTemperatureColumn(int tempcolumn);
void setAnnotationColumn(int annotationcolumn);
void annotate();
void resetChange();
signals:
void annotation(QString annotation,int tempcolumn,
int notecolumn);
};

/*:478*//*486:*/
#line 11122 "./typica.w"

class TimerDisplay:public QLCDNumber
{
Q_OBJECT
/*487:*/
#line 11172 "./typica.w"

Q_PROPERTY(QTime seconds READ seconds WRITE setTimer)
Q_PROPERTY(TimerMode mode READ mode WRITE setMode)
Q_PROPERTY(bool running READ isRunning)
Q_PROPERTY(QTime resetValue READ resetValue WRITE setResetValue)
Q_PROPERTY(QString displayFormat READ displayFormat WRITE setDisplayFormat)
Q_PROPERTY(bool autoReset READ autoReset WRITE setAutoReset)
Q_PROPERTY(QString value READ value)

/*:487*/
#line 11126 "./typica.w"

private slots:
void updateTime();
void setCountUpMode();
void setCountDownMode();
void setClockMode();
public:
TimerDisplay(QWidget*parent= NULL);
~TimerDisplay();
enum TimerMode
{
CountUp,
CountDown,
Clock
};
QString value();
QTime seconds();
TimerMode mode();
bool isRunning();
QTime resetValue();
QString displayFormat();
bool autoReset();
public slots:
void setTimer(QTime value= QTime(0,0,0));
void setMode(TimerMode mode);
void startTimer();
void stopTimer();
void copyTimer();
void setResetValue(QTime value= QTime(0,0,0));
void reset();
void setDisplayFormat(QString format);
void setAutoReset(bool reset);
void updateDisplay();
signals:
void valueChanged(QTime);
void runStateChanged(bool);
private:
/*488:*/
#line 11183 "./typica.w"

QTime s;
QTime r;
QTimer clock;
TimerDisplay::TimerMode m;
bool running;
bool ar;
QAction*startAction;
QAction*stopAction;
QAction*resetAction;
QString f;
QTime relative;
QTime base;

/*:488*/
#line 11163 "./typica.w"

};

/*:486*//*509:*/
#line 11575 "./typica.w"

class PackLayout:public QLayout
{
int doLayout(const QRect&rect,bool testOnly)const;
QList<QLayoutItem*> itemList;
Qt::Orientations orientation;
public:
PackLayout(QWidget*parent,int margin= 0,int spacing= -1);
PackLayout(int spacing= -1);
~PackLayout();
void addItem(QLayoutItem*item);
Qt::Orientations expandingDirections()const;
bool hasHeightForWidth()const;
int heightForWidth(int width)const;
int count()const;
QLayoutItem*itemAt(int index)const;
QSize minimumSize()const;
void setGeometry(const QRect&rect);
void setOrientation(Qt::Orientations direction);
QSize sizeHint()const;
QLayoutItem*takeAt(int index);
};

/*:509*//*522:*/
#line 11853 "./typica.w"

class SceneButton:public QGraphicsScene
{
Q_OBJECT
public:
SceneButton();
~SceneButton();
protected:
void mousePressEvent(QGraphicsSceneMouseEvent*mouseEvent);
signals:
void clicked(QPoint pos);
};

/*:522*//*524:*/
#line 11895 "./typica.w"

class WidgetDecorator:public QWidget
{
Q_OBJECT
PackLayout*layout;
QGraphicsView*label;
QGraphicsTextItem*text;
SceneButton*scene;
public:
WidgetDecorator(QWidget*widget,const QString&labeltext,
Qt::Orientations orientation= Qt::Horizontal,
QWidget*parent= NULL,Qt::WindowFlags f= 0);
~WidgetDecorator();
void setBackgroundBrush(QBrush background);
void setTextColor(QColor color);
};

/*:524*//*535:*/
#line 12070 "./typica.w"

class LogEditWindow:public QMainWindow
{
Q_OBJECT
QWidget*centralWidget;
PackLayout*mainLayout;
QHBoxLayout*addRowsLayout;
QLabel*startTimeLabel;
QTimeEdit*startTime;
QLabel*endTimeLabel;
QTimeEdit*endTime;
QLabel*intervalLabel;
QSpinBox*interval;
QPushButton*addRows;
QAction*saveXml;
QAction*saveCsv;
QAction*openXml;
MeasurementModel*model;
QTableView*log;
private slots:
void addTheRows();
void saveXML();
void saveCSV();
void openXML();
protected:
void closeEvent(QCloseEvent*event);
public:
LogEditWindow();
};

/*:535*//*549:*/
#line 12378 "./typica.w"

class XMLOutput:public QObject
{
Q_OBJECT
MeasurementModel*data;
QIODevice*out;
int time;
QMap<int,QString> temperatureColumns;
QMap<int,QString> controlColumns;
QMap<int,QString> annotationColumns;
public:
XMLOutput(MeasurementModel*model,QIODevice*device,int timec= 0);
void addTemperatureColumn(const QString&series,int column);
void addControlColumn(const QString&series,int column);
void addAnnotationColumn(const QString&series,int column);
void setModel(MeasurementModel*model);
void setTimeColumn(int column);
void setDevice(QIODevice*device);
bool output();
};

/*:549*//*556:*/
#line 12614 "./typica.w"

class XMLInput:public QObject
{
Q_OBJECT
int firstc;
QIODevice*in;
public:
XMLInput(QIODevice*input,int c);
void setFirstColumn(int column);
void setDevice(QIODevice*device);
bool input();
signals:
void measure(Measurement,int);
void annotation(QString,int,int);
void newTemperatureColumn(int,QString);
void newAnnotationColumn(int,QString);
void lastColumn(int);
};

/*:556*//*567:*/
#line 12868 "./typica.w"

class CSVOutput
{
MeasurementModel*data;
QIODevice*out;
int time;
QMap<int,QString> temperatureColumns;
QMap<int,QString> controlColumns;
QMap<int,QString> annotationColumns;
public:
CSVOutput(MeasurementModel*model,QIODevice*device,int timec= 0);
void addTemperatureColumn(const QString&series,int column);
void addControlColumn(const QString&series,int column);
void addAnnotationColumn(const QString&series,int column);
void setModel(MeasurementModel*model);
void setTimeColumn(int column);
void setDevice(QIODevice*device);
bool output();
};

/*:567*//*607:*/
#line 13013 "./typica.w"

#define AppInstance (qobject_cast<Application *> (qApp))

class NodeInserter;
class DeviceTreeModel;
class DatabaseNotification;
class Application:public QApplication
{
Q_OBJECT
public:
Application(int&argc,char**argv);
QDomDocument*configuration();
/*762:*/
#line 15737 "./typica.w"

QDomDocument deviceConfiguration();

/*:762*//*795:*/
#line 16410 "./typica.w"

void registerDeviceConfigurationWidget(QString driver,QMetaObject widget);
QWidget*deviceConfigurationWidget(DeviceTreeModel*model,
const QModelIndex&index);

/*:795*//*800:*/
#line 16514 "./typica.w"

QList<NodeInserter*> topLevelNodeInserters;

/*:800*/
#line 13025 "./typica.w"

QSqlDatabase database();
Q_INVOKABLE bool databaseConnected();
Q_INVOKABLE QString currentTypicaUser();
Q_INVOKABLE bool login(const QString&user,const QString&password);
Q_INVOKABLE bool autoLogin();
QScriptEngine*engine;
QNetworkAccessManager*network;
DatabaseNotification*subscribe(const QString&notification);
public slots:
void setDatabaseConnected(bool status);
void setCurrentTypicaUser(const QString&user);
void notify(const QString&notification);
/*763:*/
#line 15744 "./typica.w"

void saveDeviceConfiguration();

/*:763*/
#line 13038 "./typica.w"

signals:
void userChanged(const QString&user);
private:
/*761:*/
#line 15728 "./typica.w"

QDomDocument deviceConfigurationDocument;

/*:761*//*794:*/
#line 16404 "./typica.w"

QHash<QString,QMetaObject> deviceConfigurationWidgets;

/*:794*/
#line 13042 "./typica.w"

QDomDocument conf;
bool connectionStatus;
QString currentUser;
QMap<QString,DatabaseNotification*> notifiers;
QSqlDriver*notificationDriver;
};

/*:607*//*619:*/
#line 13214 "./typica.w"

class DatabaseNotification:public QObject
{
Q_OBJECT
public:
DatabaseNotification();
public slots:
void forwardNotification(const QString&notification);
signals:
void notify(const QString&notification);
};

/*:619*//*620:*/
#line 13228 "./typica.w"

DatabaseNotification::DatabaseNotification():QObject(NULL)
{

}

void DatabaseNotification::forwardNotification(const QString&notification)
{
emit notify(notification);
}

/*:620*//*622:*/
#line 13288 "./typica.w"

class SaltModel:public QAbstractItemModel
{
Q_OBJECT
QList<QList<QMap<int,QVariant> > > modelData;
QStringList hData;
int colcount;
public:
SaltModel(int columns);
~SaltModel();
int rowCount(const QModelIndex&parent= QModelIndex())const;
int columnCount(const QModelIndex&parent= QModelIndex())const;
bool setHeaderData(int section,Qt::Orientation orientation,
const QVariant&value,int role= Qt::DisplayRole);
QVariant data(const QModelIndex&index,int role)const;
bool setData(const QModelIndex&index,const QVariant&value,
int role= Qt::EditRole);
Qt::ItemFlags flags(const QModelIndex&index)const;
QVariant headerData(int section,Qt::Orientation orientation,
int role= Qt::DisplayRole)const;
QModelIndex index(int row,int column,
const QModelIndex&parent= QModelIndex())const;
QModelIndex parent(const QModelIndex&index)const;
QString arrayLiteral(int column,int role)const;
QString quotedArrayLiteral(int column,int role)const;
void clear();
bool removeRows(int row,int count,
const QModelIndex&parent= QModelIndex());
int findData(const QVariant&value,int column,int role= Qt::UserRole);
};

/*:622*//*638:*/
#line 13673 "./typica.w"

class SqlComboBox:public QComboBox
{
Q_OBJECT
int dataColumn;
int displayColumn;
bool dataColumnShown;
QString specialNullText;
QVariant specialNullData;
public:
SqlComboBox();
~SqlComboBox();
SqlComboBox*clone(QWidget*parent);
public slots:
void addNullOption();
void addSqlOptions(QString query);
void setDataColumn(int column);
void setDisplayColumn(int column);
void showData(bool show);
void setNullText(QString nullText);
void setNullData(QVariant nullData);
};

/*:638*//*645:*/
#line 13820 "./typica.w"

class SqlComboBoxDelegate:public QItemDelegate
{
Q_OBJECT
SqlComboBox*delegate;
public:
SqlComboBoxDelegate(QObject*parent= NULL);
QWidget*createEditor(QWidget*parent,
const QStyleOptionViewItem&option,
const QModelIndex&index)const;
void setEditorData(QWidget*editor,const QModelIndex&index)const;
void setModelData(QWidget*editor,QAbstractItemModel*model,
const QModelIndex&index)const;
void setWidget(SqlComboBox*widget);
virtual QSize sizeHint()const;
void updateEditorGeometry(QWidget*editor,
const QStyleOptionViewItem&option,
const QModelIndex&index)const;
};

/*:645*//*660:*/
#line 14031 "./typica.w"

class SqlConnectionSetup:public QDialog
{
Q_OBJECT
public:
SqlConnectionSetup();
~SqlConnectionSetup();
public slots:
void testConnection();
private:
QFormLayout*formLayout;
QComboBox*driver;
QLineEdit*hostname;
QLineEdit*portnumber;
QLineEdit*dbname;
QLineEdit*user;
QLineEdit*password;
QVBoxLayout*layout;
QHBoxLayout*buttons;
QPushButton*cancelButton;
QPushButton*connectButton;
};

/*:660*//*665:*/
#line 14179 "./typica.w"

class SqlQueryView:public QTableView
{
Q_OBJECT
public:
SqlQueryView(QWidget*parent= NULL);
void setQuery(const QString&query);
bool setHeaderData(int section,Qt::Orientation orientation,
const QVariant&value,int role);
Q_INVOKABLE QVariant data(int row,int column,
int role= Qt::DisplayRole);
signals:
void openEntry(QString key);
void openEntryRow(int row);
void selectEntry(QString key);
void selectEntryRow(int row);
protected:
virtual void showEvent(QShowEvent*event);
private slots:
void openRow(const QModelIndex&index);
void persistColumnResize(int column,int oldsize,int newsize);
void selectRow(const QModelIndex&index);
};

/*:665*//*680:*/
#line 14454 "./typica.w"

class ReportAction:public QAction
{
Q_OBJECT
public:
ReportAction(const QString&fileName,const QString&reportName,
QObject*parent= NULL);
private slots:
void createReport();
private:
QString reportFile;
};

/*:680*//*692:*/
#line 14665 "./typica.w"

class ReportTable:public QObject
{
Q_OBJECT
QTextFrame*area;
QDomElement configuration;
QMap<QString,QVariant> bindings;
public:
ReportTable(QTextFrame*frame,QDomElement description);
~ReportTable();
Q_INVOKABLE void bind(QString placeholder,QVariant value);
public slots:
void refresh();
};

/*:692*//*705:*/
#line 63 "./plugins.w"

class PluginAction:public QAction
{
Q_OBJECT
Q_PROPERTY(QString preRun READ preRun WRITE setPreRun);
Q_PROPERTY(QString postRun READ postRun WRITE setPostRun);
public:
PluginAction(const QFileInfo&info,QObject*parent);
QString preRun();
QString postRun();
public slots:
void setPreRun(const QString&script);
void setPostRun(const QString&script);
private slots:
void runScript();
private:
QString pluginFile;
QString preRunScript;
QString postRunScript;
};

/*:705*//*708:*/
#line 155 "./plugins.w"

Q_DECLARE_METATYPE(QScriptValue)

/*:708*//*731:*/
#line 14906 "./typica.w"

class FormArray:public QScrollArea
{
Q_OBJECT
QDomElement configuration;
QWidget itemContainer;
QVBoxLayout itemLayout;
int maxwidth;
int maxheight;
public:
FormArray(QDomElement description);
Q_INVOKABLE QWidget*elementAt(int index);
Q_INVOKABLE int elements();
public slots:
void addElements(int copies= 1);
void removeAllElements();
void setMaximumElementWidth(int width);
void setMaximumElementHeight(int height);
};

/*:731*//*741:*/
#line 15122 "./typica.w"

class ScaleControl:public QGraphicsView
{
Q_OBJECT
Q_PROPERTY(double initialValue READ initialValue WRITE setInitialValue)
Q_PROPERTY(double finalValue READ finalValue WRITE setFinalValue)
/*742:*/
#line 15148 "./typica.w"

QGraphicsScene scene;
QGraphicsPolygonItem initialDecrement;
QGraphicsPolygonItem initialIncrement;
QGraphicsPolygonItem finalDecrement;
QGraphicsPolygonItem finalIncrement;
QGraphicsPolygonItem initialIndicator;
QGraphicsPolygonItem finalIndicator;
QGraphicsPathItem scaleLine;
QPolygonF left;
QPolygonF right;
QPolygonF down;
QPolygonF up;
QPainterPath scalePath;
QBrush initialBrush;
QBrush finalBrush;
double nonScoredValue;
double scoredValue;
bool initialSet;
bool finalSet;
bool scaleDown;

/*:742*/
#line 15128 "./typica.w"

public:
ScaleControl();
double initialValue(void);
double finalValue(void);
virtual QSize sizeHint()const;
public slots:
void setInitialValue(double value);
void setFinalValue(double value);
signals:
void initialChanged(double);
void finalChanged(double);
protected:
virtual void mousePressEvent(QMouseEvent*event);
virtual void mouseReleaseEvent(QMouseEvent*event);
};

/*:741*//*753:*/
#line 15445 "./typica.w"

class IntensityControl:public QGraphicsView
{
Q_OBJECT
Q_PROPERTY(double value READ value WRITE setValue)
QGraphicsScene scene;
QGraphicsPolygonItem decrement;
QGraphicsPolygonItem increment;
QGraphicsPolygonItem indicator;
QGraphicsPathItem scaleLine;
QPolygonF left;
QPolygonF up;
QPolygonF down;
QPainterPath scalePath;
QBrush theBrush;
double theValue;
bool valueSet;
bool scaleDown;
public:
IntensityControl();
double value();
virtual QSize sizeHint()const;
public slots:
void setValue(double val);
signals:
void valueChanged(double);
protected:
virtual void mousePressEvent(QMouseEvent*event);
virtual void mouseReleaseEvent(QMouseEvent*event);
};

/*:753*//*769:*/
#line 15833 "./typica.w"

class DeviceTreeModelNode
{
public:
DeviceTreeModelNode(QDomNode&node,int row,
DeviceTreeModelNode*parent= NULL);
~DeviceTreeModelNode();
DeviceTreeModelNode*child(int index);
DeviceTreeModelNode*parent();
QDomNode node()const;
int row();
private:
QDomNode domNode;
QHash<int,DeviceTreeModelNode*> children;
int rowNumber;
DeviceTreeModelNode*parentItem;
};

/*:769*//*771:*/
#line 15908 "./typica.w"

class DeviceTreeModel:public QAbstractItemModel
{
Q_OBJECT
public:
DeviceTreeModel(QObject*parent= NULL);
~DeviceTreeModel();
QVariant data(const QModelIndex&index,int role)const;
Qt::ItemFlags flags(const QModelIndex&index)const;
QVariant headerData(int section,Qt::Orientation orientation,
int role= Qt::DisplayRole)const;
QModelIndex index(int row,int column,
const QModelIndex&parent= QModelIndex())const;
QModelIndex parent(const QModelIndex&child)const;
Q_INVOKABLE int rowCount(const QModelIndex&parent= QModelIndex())const;
int columnCount(const QModelIndex&parent= QModelIndex())const;
bool setData(const QModelIndex&index,const QVariant&value,
int role);
bool removeRows(int row,int count,const QModelIndex&parent);
QDomElement referenceElement(const QString&id);
public slots:
void newNode(const QString&name,const QString&driver,
const QModelIndex&parent);
private:
QDomDocument document;
DeviceTreeModelNode*root;
QDomNode referenceSection;
QDomNode treeRoot;
};

/*:771*//*790:*/
#line 16362 "./typica.w"

Q_DECLARE_METATYPE(QModelIndex)

/*:790*//*798:*/
#line 16469 "./typica.w"

class NodeInserter:public QAction
{
Q_OBJECT
public:
NodeInserter(const QString&title,const QString&name,
const QString&driver,QObject*parent= NULL);
signals:
void triggered(QString name,QString driver);
private slots:
void onTriggered();
private:
QString defaultNodeName;
QString driverString;
};

/*:798*//*801:*/
#line 16524 "./typica.w"

class DeviceConfigurationWindow:public QWidget
{
Q_OBJECT
public:
DeviceConfigurationWindow();
public slots:
void addDevice();
void removeNode();
void newSelection(const QModelIndex&index);
private slots:
void resizeColumn();
private:
QDomDocument document;
DeviceTreeModel*model;
QTreeView*view;
QScrollArea*configArea;
};

/*:801*//*810:*/
#line 16694 "./typica.w"

class BasicDeviceConfigurationWidget:public QWidget
{
Q_OBJECT
public:
BasicDeviceConfigurationWidget(DeviceTreeModel*model,
const QModelIndex&index);
public slots:
void insertChildNode(const QString&name,const QString&driver);
void updateAttribute(const QString&name,const QString&value);
protected:
DeviceTreeModel*deviceModel;
QModelIndex currentNode;
};

/*:810*//*814:*/
#line 16779 "./typica.w"

class RoasterConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE RoasterConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateRoasterId(int id);
void updateCapacityCheck(int value);
void updateCapacity(const QString&value);
void updateCapacityUnit(const QString&value);
};

/*:814*//*819:*/
#line 16984 "./typica.w"

class NiDaqMxBaseDriverConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE NiDaqMxBaseDriverConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
};

/*:819*//*821:*/
#line 17030 "./typica.w"

class NiDaqMxBase9211ConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE NiDaqMxBase9211ConfWidget(DeviceTreeModel*device,
const QModelIndex&index);
private slots:
void addChannel();
void updateDeviceId(const QString&newId);
};

/*:821*//*825:*/
#line 17116 "./typica.w"

class Ni9211TcConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE Ni9211TcConfWidget(DeviceTreeModel*device,
const QModelIndex&index);
private slots:
void updateThermocoupleType(const QString&type);
void updateColumnName(const QString&name);
void updateHidden(bool hidden);
};

/*:825*//*830:*/
#line 17232 "./typica.w"

class NiDaqMxDriverConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE NiDaqMxDriverConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
};

/*:830*//*832:*/
#line 17273 "./typica.w"

class NiDaqMx9211ConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE NiDaqMx9211ConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void addChannel();
void updateDeviceId(const QString&newId);
};

/*:832*//*834:*/
#line 17342 "./typica.w"

class NiDaqMxTc01ConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE NiDaqMxTc01ConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateDeviceId(const QString&newId);
void updateThermocoupleType(const QString&type);
void updateColumnName(const QString&name);
void updateHidden(bool hidden);
};

/*:834*//*839:*/
#line 17473 "./typica.w"

class PortSelector:public QComboBox
{
Q_OBJECT
public:
PortSelector(QWidget*parent= NULL);
private slots:
void addDevice(QextPortInfo port);
private:
QextSerialEnumerator*lister;
};

/*:839*//*841:*/
#line 17521 "./typica.w"

class BaudSelector:public QComboBox
{
Q_OBJECT
Q_ENUMS(BaudRateType)
public:
BaudSelector(QWidget*parent= NULL);
enum BaudRateType
{
#if defined(Q_OS_UNIX) || defined(qdoc)
BAUD50= 50,
BAUD75= 75,
BAUD134= 134,
BAUD150= 150,
BAUD200= 200,
BAUD1800= 1800,
#if defined(B76800) || defined(qdoc)
BAUD76800= 76800,
#endif
#if (defined(B230400) && defined(B4000000)) || defined(qdoc)
BAUD230400= 230400,
BAUD460800= 460800,
BAUD500000= 500000,
BAUD576000= 576000,
BAUD921600= 921600,
BAUD1000000= 1000000,
BAUD1152000= 1152000,
BAUD1500000= 1500000,
BAUD2000000= 2000000,
BAUD2500000= 2500000,
BAUD3000000= 3000000,
BAUD3500000= 3500000,
BAUD4000000= 4000000,
#endif
#endif
#if defined(Q_OS_WIN) || defined(qdoc)
BAUD14400= 14400,
BAUD56000= 56000,
BAUD128000= 128000,
BAUD256000= 256000,
#endif
BAUD110= 110,
BAUD300= 300,
BAUD600= 600,
BAUD1200= 1200,
BAUD2400= 2400,
BAUD4800= 4800,
BAUD9600= 9600,
BAUD19200= 19200,
BAUD38400= 38400,
BAUD57600= 57600,
BAUD115200= 115200
};
};

/*:841*//*843:*/
#line 17592 "./typica.w"

class ParitySelector:public QComboBox
{
Q_OBJECT
Q_ENUMS(ParityType)
public:
ParitySelector(QWidget*parent= NULL);
enum ParityType
{
PAR_NONE,
PAR_ODD,
PAR_EVEN,
#if defined(Q_OS_WIN) || defined(qdoc)
PAR_MARK,
#endif
PAR_SPACE
};
};

/*:843*//*845:*/
#line 17630 "./typica.w"

class FlowSelector:public QComboBox
{
Q_OBJECT
Q_ENUMS(FlowType)
public:
FlowSelector(QWidget*parent= NULL);
enum FlowType
{
FLOW_OFF,
FLOW_HARDWARE,
FLOW_XONXOFF
};
};

/*:845*//*847:*/
#line 17663 "./typica.w"

class StopSelector:public QComboBox
{
Q_OBJECT
Q_ENUMS(StopBitsType)
public:
StopSelector(QWidget*parent= NULL);
enum StopBitsType
{
STOP_1,
#if defined(Q_OS_WIN) || defined(qdoc)
STOP_1_5,
#endif
STOP_2
};
};

/*:847*//*850:*/
#line 17720 "./typica.w"

class ShortHexSpinBox:public QSpinBox
{
Q_OBJECT
public:
ShortHexSpinBox(QWidget*parent= NULL);
virtual QValidator::State validate(QString&input,int&pos)const;
protected:
virtual int valueFromText(const QString&text)const;
virtual QString textFromValue(int value)const;
};

/*:850*//*852:*/
#line 17782 "./typica.w"

class ModbusRtuPortConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ModbusRtuPortConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updatePort(const QString&newPort);
void updateBaudRate(const QString&newRate);
void updateParity(const QString&newParity);
void updateFlowControl(const QString&newFlow);
void updateStopBits(const QString&newStopBits);
};

/*:852*//*854:*/
#line 17933 "./typica.w"

class ModbusRtuDeviceConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ModbusRtuDeviceConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateStationNumber(int newStation);
void updateFixedUnit(bool newFixed);
void updateFixedDecimal(bool newFixed);
void updateUnit(const QString&newUnit);
void updateUnitAddress(int newAddress);
void updateValueF(int newValue);
void updateValueC(int newValue);
void updatePrecisionAddress(int newAddress);
void updatePrecisionValue(int newValue);
private:
QStackedLayout*unitSpecificationLayout;
QStackedLayout*decimalSpecificationLayout;
};

/*:854*//*856:*/
#line 18192 "./typica.w"

class ModbusRtuDeviceTPvConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ModbusRtuDeviceTPvConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateAddress(int newAddress);
};

/*:856*//*858:*/
#line 18238 "./typica.w"

class ModbusRtuDeviceTSvConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ModbusRtuDeviceTSvConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateReadAddress(int newAddress);
void updateWriteAddress(int newAddress);
void updateFixedRange(bool fixed);
void updateLower(const QString&lower);
void updateUpper(const QString&upper);
void updateLowerAddress(int newAddress);
void updateUpperAddress(int newAddress);
private:
QStackedLayout*boundsLayout;
};

/*:858*//*862:*/
#line 18432 "./typica.w"

class AnnotationButtonConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE AnnotationButtonConfWidget(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updateButtonText(const QString&text);
void updateAnnotationText(const QString&text);
};

/*:862*//*866:*/
#line 18500 "./typica.w"

class ReconfigurableAnnotationButtonConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ReconfigurableAnnotationButtonConfWidget(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updateButtonText(const QString&text);
void updateAnnotationText(const QString&text);
};

/*:866*//*869:*/
#line 18575 "./typica.w"

class NoteSpinConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE NoteSpinConfWidget(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updateLabel(const QString&text);
void updateMinimum(const QString&minimum);
void updateMaximum(const QString&maximum);
void updatePrecision(int precision);
void updatePretext(const QString&text);
void updatePosttext(const QString&text);
};

/*:869*//*872:*/
#line 12 "./freeannotation.w"

class FreeAnnotationConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE FreeAnnotationConfWidget(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updateLabel(const QString&text);
};

/*:872*//*876:*/
#line 11 "./settings.w"

class SettingsWindow:public QMainWindow
{
Q_OBJECT
public:
SettingsWindow();
};

/*:876*//*881:*/
#line 8 "./graphsettings.w"

class GraphSettingsWidget:public QWidget
{
Q_OBJECT
public:
GraphSettingsWidget();
};

/*:881*//*883:*/
#line 46 "./graphsettings.w"

class GraphSettingsRelativeTab:public QWidget
{
Q_OBJECT
public:
GraphSettingsRelativeTab();
public slots:
void updateEnableSetting(bool enable);
void updateColorSetting(const QString&color);
void updateAxisSetting(const QString&gridList);
void updateUnit(int unit);
void showColorPicker();
private:
QLineEdit*colorEdit;
};

/*:883*//*887:*/
#line 15 "./colorsettings.w"

class ColorSettingsWidget:public QWidget
{
Q_OBJECT
public:
ColorSettingsWidget();
public slots:
void updateEnable(bool enable);
void updateAddress(const QString&address);
void updateScale(int sccale);
};

/*:887*//*891:*/
#line 7 "./advancedsettings.w"

class AdvancedSettingsWidget:public QWidget
{
Q_OBJECT
public:
AdvancedSettingsWidget();
public slots:
void enableDiagnosticLogging(bool enabled);
};

/*:891*//*895:*/
#line 18700 "./typica.w"

class ModbusRTUDevice:public QObject
{
Q_OBJECT
public:
ModbusRTUDevice(DeviceTreeModel*model,const QModelIndex&index);
~ModbusRTUDevice();
void queueMessage(QByteArray request,QObject*object,const char*callback);
Q_INVOKABLE double SVLower();
Q_INVOKABLE double SVUpper();
Q_INVOKABLE int decimals();
QList<Channel*> channels;
public slots:
void outputSV(double sv);
signals:
void SVLowerChanged(double);
void SVUpperChanged(double);
void SVDecimalChanged(int);
void queueEmpty();
private slots:
void dataAvailable();
void sendNextMessage();
void decimalResponse(QByteArray response);
void unitResponse(QByteArray response);
void svlResponse(QByteArray response);
void svuResponse(QByteArray response);
void requestMeasurement();
void mResponse(QByteArray response);
void ignore(QByteArray response);
void timeout();
private:
QextSerialPort*port;
QByteArray responseBuffer;
QList<QByteArray> messageQueue;
QList<QObject*> retObjQueue;
QList<char*> callbackQueue;
quint16 calculateCRC(QByteArray data);
QTimer*messageDelayTimer;
QTimer*commTimeout;
int delayTime;
char station;
int decimalPosition;
int valueF;
int valueC;
bool unitIsF;
double outputSVLower;
double outputSVUpper;
QByteArray outputSVStub;
QByteArray pvStub;
QByteArray svStub;
QByteArray mStub;
quint16 pvaddress;
quint16 svaddress;
bool svenabled;
bool readingsv;
double savedpv;
bool waiting;
};

/*:895*//*911:*/
#line 19398 "./typica.w"

class ModbusConfigurator:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ModbusConfigurator(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updatePort(const QString&newPort);
void updateBaudRate(const QString&newRate);
void updateParity(const QString&newParity);
void updateFlowControl(const QString&newFlow);
void updateStopBits(const QString&newStopBits);
void updateStation(int station);
void updateFixedDecimal(bool fixed);
void updateDecimalAddress(int address);
void updateDecimalPosition(int position);
void updateFixedUnit(bool fixed);
void updateUnitAddress(int address);
void updateValueForF(int value);
void updateValueForC(int value);
void updateUnit(const QString&newUnit);
void updatePVAddress(int address);
void updateSVEnabled(bool enabled);
void updateSVReadAddress(int address);
void updateDeviceLimit(bool query);
void updateSVLowerAddress(int address);
void updateSVUpperAddress(int address);
void updateSVLower(double value);
void updateSVUpper(double value);
void updateSVWritable(bool canWriteSV);
void updateSVWriteAddress(int address);
void updatePVColumnName(const QString&name);
void updateSVColumnName(const QString&name);
void updatePVHidden(bool hidden);
void updateSVHidden(bool hidden);
private:
PortSelector*port;
BaudSelector*baud;
ParitySelector*parity;
FlowSelector*flow;
StopSelector*stop;
QSpinBox*station;
QCheckBox*decimalQuery;
ShortHexSpinBox*decimalAddress;
QSpinBox*decimalPosition;
QCheckBox*unitQuery;
ShortHexSpinBox*unitAddress;
QSpinBox*valueF;
QSpinBox*valueC;
QComboBox*fixedUnit;
ShortHexSpinBox*pVAddress;
QCheckBox*sVEnabled;
ShortHexSpinBox*sVReadAddress;
QCheckBox*deviceLimit;
ShortHexSpinBox*sVLowerAddr;
ShortHexSpinBox*sVUpperAddr;
QDoubleSpinBox*sVLower;
QDoubleSpinBox*sVUpper;
QCheckBox*sVWritable;
ShortHexSpinBox*sVOutputAddr;
QLineEdit*pVColumnName;
QLineEdit*sVColumnName;
};

/*:911*//*915:*/
#line 22 "./modbus.w"

class ModbusNGConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ModbusNGConfWidget(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updatePort(const QString&value);
void updateBaudRate(const QString&value);
void updateParity(int value);
void updateFlowControl(int value);
void updateStopBits(int value);
void addInput();
private:
ParitySelector*m_parity;
FlowSelector*m_flow;
StopSelector*m_stop;
};

/*:915*//*917:*/
#line 144 "./modbus.w"

class ModbusNGInputConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ModbusNGInputConfWidget(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updateStation(int value);
void updateAddress(int value);
void updateFunction(int value);
void updateFormat(int value);
void updateDecimals(int value);
void updateUnit(int value);
void updateColumnName(const QString&value);
void updateHidden(bool value);
};

/*:917*//*921:*/
#line 342 "./modbus.w"

enum ModbusDataFormat
{
Int16,
FloatHL,
FloatLH
};

struct ModbusScanItem
{
QByteArray request;
ModbusDataFormat format;
int decimalPosition;
Units::Unit unit;
mutable double lastValue;
};

/*:921*//*922:*/
#line 362 "./modbus.w"

class ModbusNG:public QObject
{
Q_OBJECT
public:
ModbusNG(DeviceTreeModel*model,const QModelIndex&index);
~ModbusNG();
Q_INVOKABLE int channelCount();
Channel*getChannel(int);
Q_INVOKABLE QString channelColumnName(int);
Q_INVOKABLE QString channelIndicatorText(int);
Q_INVOKABLE bool isChannelHidden(int);
Q_INVOKABLE QString channelType(int);
private slots:
void sendNextMessage();
void timeout();
void dataAvailable();
void rateLimitTimeout();
private:
quint16 calculateCRC(QByteArray data);
QextSerialPort*port;
int delayTime;
QTimer*messageDelayTimer;
QTimer*commTimeout;
QTimer*rateLimiter;
int scanPosition;
bool waiting;
QByteArray responseBuffer;
QList<Channel*> channels;
QList<ModbusScanItem> scanList;
QList<QString> channelNames;
QList<QString> channelLabels;
QList<bool> hiddenStates;
QList<QString> channelTypeList;
QVector<double> lastMeasurement;
};

/*:922*//*927:*/
#line 36 "./unsupportedserial.w"

class UnsupportedSerialDeviceConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE UnsupportedSerialDeviceConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateConfiguration();
void saveScript();
void addChannel();
private:
SaltModel*deviceSettingsModel;
QTextEdit*scriptEditor;
};

/*:927*//*932:*/
#line 166 "./unsupportedserial.w"

class UnsupportedDeviceChannelConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE UnsupportedDeviceChannelConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateColumnName(const QString&value);
void updateHidden(bool hidden);
void updateConfiguration();
private:
SaltModel*channelSettingsModel;
};

/*:932*//*937:*/
#line 301 "./unsupportedserial.w"

class JavaScriptDevice:public QObject
{
Q_OBJECT
public:
Q_INVOKABLE JavaScriptDevice(const QModelIndex&deviceIndex,
QScriptEngine*engine);
Q_INVOKABLE int channelCount();
Channel*getChannel(int channel);
Q_INVOKABLE bool isChannelHidden(int channel);
Q_INVOKABLE Units::Unit expectedChannelUnit(int channel);
Q_INVOKABLE QString channelColumnName(int channel);
Q_INVOKABLE QString channelIndicatorText(int channel);
public slots:
void setTemperatureColumn(int tcol);
void setAnnotationColumn(int ncol);
void start();
void stop();
signals:
void annotation(QString note,int tcol,int ncol);
void triggerStartBatch();
void triggerStopBatch();
void deviceStopRequested();
private:
QVariantMap deviceSettings;
QString deviceScript;
QList<Channel*> channelList;
QList<bool> hiddenState;
QList<Units::Unit> channelUnits;
QList<QString> columnNames;
QList<QString> indicatorTexts;
QList<QVariantMap> channelSettings;
int annotationTemperatureColumn;
int annotationNoteColumn;
QScriptEngine*scriptengine;
};

/*:937*//*959:*/
#line 11 "./phidgets.w"

class PhidgetsTemperatureSensorConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE PhidgetsTemperatureSensorConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void addChannel();
void updateRate(int ms);
};

/*:959*//*963:*/
#line 82 "./phidgets.w"

class PhidgetTemperatureSensorChannelConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE PhidgetTemperatureSensorChannelConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateColumnName(const QString&value);
void updateHidden(bool hidden);
void updateTC(int index);
void updateChannel(int channel);
private:
QComboBox*tcType;
};

/*:963*//*968:*/
#line 213 "./phidgets.w"

class PhidgetsTemperatureSensor:public QObject
{
Q_OBJECT
public:
Q_INVOKABLE PhidgetsTemperatureSensor(const QModelIndex&deviceIndex);
Q_INVOKABLE int channelCount();
Channel*getChannel(int channel);
Q_INVOKABLE bool isChannelHidden(int channel);
Q_INVOKABLE QString channelColumnName(int channel);
Q_INVOKABLE QString channelIndicatorText(int channel);
public slots:
void start();
void stop();
private slots:
void getMeasurements();
private:
QList<int> channelIndices;
QList<int> tctypes;
QList<Channel*> channelList;
QMap<int,Channel*> channelMap;
QList<bool> hiddenState;
QList<QString> columnNames;
QList<QString> indicatorTexts;
QLibrary driver;
QTimer sampleTimer;
void*device;
/*972:*/
#line 349 "./phidgets.w"

#ifdef _WIN32
typedef int(__stdcall*PhidgetHandleOnly)(void*);
typedef int(__stdcall*PhidgetHandleInt)(void*,int);
typedef int(__stdcall*PhidgetHandleIntInt)(void*,int,int);
typedef int(__stdcall*PhidgetHandleIntDoubleOut)(void*,int,double*);
#else
typedef int(*PhidgetHandleOnly)(void*);
typedef int(*PhidgetHandleInt)(void*,int);
typedef int(*PhidgetHandleIntInt)(void*,int,int);
typedef int(*PhidgetHandleIntDoubleOut)(void*,int,double*);
#endif
PhidgetHandleOnly createDevice;
PhidgetHandleInt openDevice;
PhidgetHandleInt waitForOpen;
PhidgetHandleIntInt setTCType;
PhidgetHandleIntDoubleOut getTemperature;
PhidgetHandleOnly closeDevice;
PhidgetHandleOnly deleteDevice;

/*:972*/
#line 240 "./phidgets.w"

};

/*:968*//*983:*/
#line 46 "./phidget22.w"

class PhidgetConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE PhidgetConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void addChannel();
};

/*:983*//*985:*/
#line 96 "./phidget22.w"

class PhidgetChannelSelector:public QComboBox
{
Q_OBJECT
public:
PhidgetChannelSelector();
~PhidgetChannelSelector();
void addChannel(void*device);
void removeChannel(void*device);
private:
QLibrary driver;
void*manager;
/*987:*/
#line 141 "./phidget22.w"

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

/*:987*/
#line 108 "./phidget22.w"

};

/*:985*//*995:*/
#line 298 "./phidget22.w"

class PhidgetChannelConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE PhidgetChannelConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
public slots:
void changeSelectedChannel(int index);
void updateSerialNumber(const QString&value);
void updateChannel(const QString&value);
void updateHubPort(const QString&value);
void updateColumnName(const QString&value);
void updateChannelType(int value);
void updateTCType(int value);
void updateRTDType(int value);
void updateRTDWiring(int value);
void updateHidden(int value);
private:
PhidgetChannelSelector*channelSelector;
QLineEdit*serialNumber;
QLineEdit*channel;
QLineEdit*hubPort;
QComboBox*subtype;
QStackedLayout*subtypeLayout;
QComboBox*tctype;
QComboBox*rtdtype;
QComboBox*rtdwiring;
};

/*:995*//*999:*/
#line 538 "./phidget22.w"

struct PhidgetChannelData
{
Channel*channel;
QString columnName;
QString indicatorLabel;
int serialNumber;
int channelNumber;
int channelType;
int hubPort;
int tcType;
int rtdType;
int wiring;
bool hidden;
void*device;
};

/*:999*//*1000:*/
#line 559 "./phidget22.w"

class Phidget22:public QObject
{
Q_OBJECT
public:
Q_INVOKABLE Phidget22(const QModelIndex&deviceIndex);
Q_INVOKABLE int channelCount();
Channel*getChannel(int channel);
Q_INVOKABLE bool isChannelHidden(int channel);
Q_INVOKABLE QString channelColumnName(int channel);
Q_INVOKABLE QString channelIndicatorText(int channel);
public slots:
void start();
void stop();
private:
QList<PhidgetChannelData*> channelConfiguration;
QLibrary driver;
PhidgetPointer p_createTemperatureSensor;
PhidgetPointerIntIn p_setSerialNumber;
PhidgetPointerIntIn p_setChannelNumber;
PhidgetPointerIntIn p_setHubPort;
PhidgetPointerIntIn p_setTCType;
PhidgetPointerIntIn p_setRTDType;
PhidgetPointerIntIn p_setRTDWiring;
PhidgetPointerVCPointer p_setNewDataCallback;
PhidgetPointerIntIn p_open;
PhidgetPointer p_close;
PhidgetPointer p_delete;
};

/*:1000*//*1013:*/
#line 19940 "./typica.w"

class LinearSplineInterpolationConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE LinearSplineInterpolationConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateSourceColumn(const QString&source);
void updateDestinationColumn(const QString&dest);
void updateKnots();
private:
SaltModel*tablemodel;
};

/*:1013*//*1019:*/
#line 20070 "./typica.w"

class CoolingTimerConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE CoolingTimerConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateResetTime(QTime time);
};

/*:1019*//*1023:*/
#line 20136 "./typica.w"

class RangeTimerConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE RangeTimerConfWidget(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updateStartButtonText(const QString&text);
void updateStopButtonText(const QString&text);
void updateStartColumnName(const QString&text);
void updateStopColumnName(const QString&text);
void updateStartValue(const QString&text);
void updateStopValue(const QString&text);
void updateStartTrigger(int option);
void updateStopTrigger(int option);
};

/*:1023*//*1028:*/
#line 20388 "./typica.w"

class MultiRangeTimerConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE MultiRangeTimerConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateColumnName(const QString&text);
void updateRangeData();
private:
SaltModel*tablemodel;
};

/*:1028*//*1033:*/
#line 20490 "./typica.w"

class TranslationConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE TranslationConfWidget(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updateMatchingColumn(const QString&column);
void updateTemperature();
void updateDelay();
private:
QDoubleSpinBox*temperatureValue;
QComboBox*unitSelector;
QSpinBox*delaySelector;
};

/*:1033*//*1037:*/
#line 16 "./rate.w"

class RateOfChange:public QObject
{
Q_OBJECT
public:
RateOfChange(int cachetime= 1,int scaletime= 1);
public slots:
void newMeasurement(Measurement measure);
void setCacheTime(int seconds);
void setScaleTime(int seconds);
signals:
void newData(Measurement measure);
private:
int ct;
int st;
QList<Measurement> cache;
};

/*:1037*//*1045:*/
#line 177 "./rate.w"

class RateOfChangeConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE RateOfChangeConfWidget(DeviceTreeModel*model,const QModelIndex&index);
private slots:
void updateColumn(const QString&column);
void updateCacheTime(const QString&seconds);
void updateScaleTime(const QString&seconds);
};

/*:1045*//*1051:*/
#line 15 "./mergeseries.w"

class MergeSeries:public QObject
{
Q_OBJECT
public:
MergeSeries();
public slots:
void in1(Measurement measure);
void in2(Measurement measure);
signals:
void newData(Measurement measure);
protected:
virtual void calculate(Measurement m1,Measurement m2)= 0;
private:
Measurement last1;
Measurement last2;
bool received1;
bool received2;
};

class DifferenceSeries:public MergeSeries
{
Q_OBJECT
public:
DifferenceSeries();
protected:
void calculate(Measurement m1,Measurement m2);
};

class MeanSeries:public MergeSeries
{
Q_OBJECT
public:
MeanSeries();
protected:
void calculate(Measurement m1,Measurement m2);
};

/*:1051*//*1059:*/
#line 167 "./mergeseries.w"

class MergeSeriesConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE MergeSeriesConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateColumn1(const QString&column);
void updateColumn2(const QString&column);
void updateOutput(const QString&column);
void updateType(int type);
};

/*:1059*//*1065:*/
#line 19 "./dataqsdk.w"

class DataqSdkDeviceImplementation;
class DataqSdkDevice:public QObject
{
Q_OBJECT
DataqSdkDeviceImplementation*imp;
private slots:
void threadFinished();
public:
DataqSdkDevice(QString device);
~DataqSdkDevice();
Channel*newChannel(Units::Unit scale);
Q_INVOKABLE void setClockRate(double Hz);
Q_INVOKABLE void start();
static QStringList detectPorts();
static QStringList detectHardware();
};

/*:1065*//*1066:*/
#line 49 "./dataqsdk.w"

class DataqSdkDeviceImplementation:public QThread
{
Q_OBJECT
public:
DataqSdkDeviceImplementation();
~DataqSdkDeviceImplementation();
void run();
/*1067:*/
#line 70 "./dataqsdk.w"

typedef struct di_inlist_struct{
unsigned short chan;
unsigned short diff;
unsigned short gain;
unsigned short unipolar;
unsigned short dig_out_enable;
unsigned short dig_out;
unsigned short ave;
unsigned short counter;
}DI_INLIST_STRUCT;

typedef int(PASCAL*FPDIOPEN)(unsigned);
typedef int(PASCAL*FPDICLOSE)(void);
typedef double(PASCAL*FPDISAMPLERATE)(double,long*,long*);
typedef double(PASCAL*FPDIMAXIMUMRATE)(double);
typedef int(PASCAL*FPDILISTLENGTH)(unsigned,unsigned);
typedef int(PASCAL*FPDIINLIST)(di_inlist_struct*);
typedef int*(PASCAL*FPDIBUFFERALLOC)(unsigned,unsigned);
typedef int(PASCAL*FPDISTARTSCAN)(void);
typedef unsigned(PASCAL*FPDISTATUSREAD)(short*,unsigned);
typedef unsigned(PASCAL*FPDIBUFFERSTATUS)(unsigned);
typedef int(PASCAL*FPDIBURSTRATE)(unsigned);
typedef int(PASCAL*FPDISTOPSCAN)(void);

FPDIOPEN di_open;
FPDICLOSE di_close;
FPDISAMPLERATE di_sample_rate;
FPDIMAXIMUMRATE di_maximum_rate;
FPDILISTLENGTH di_list_length;
FPDIINLIST di_inlist;
FPDIBUFFERALLOC di_buffer_alloc;
FPDISTARTSCAN di_start_scan;
FPDISTATUSREAD di_status_read;
FPDIBUFFERSTATUS di_buffer_status;
FPDIBURSTRATE di_burst_rate;
FPDISTOPSCAN di_stop_scan;

/*:1067*/
#line 57 "./dataqsdk.w"

/*1069:*/
#line 134 "./dataqsdk.w"

bool isOpen;
double sampleRate;
long oversample;
long burstDivisor;
QString device;
unsigned deviceNumber;
QVector<Channel*> channelMap;

int error;
int channels;
bool ready;
QLibrary*driver;
QVector<Units::Unit> unitMap;
int*input_buffer;
QTimer*eventClock;
QMultiMap<int,double> smoother;

/*:1069*/
#line 58 "./dataqsdk.w"

public slots:
void measure();
private:
qint16*buffer;
};

/*:1066*//*1086:*/
#line 663 "./dataqsdk.w"

class DataqSdkDeviceConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE DataqSdkDeviceConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateAutoSelect(bool automatic);
void updateDeviceNumber(int deviceNumber);
void updatePort(QString portId);
void addChannel();
private:
QStackedWidget*deviceIdStack;
};

/*:1086*//*1091:*/
#line 808 "./dataqsdk.w"

class DataqSdkChannelConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE DataqSdkChannelConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateUnits(const QString&unit);
void updateColumnName(const QString&value);
void updateMeasuredLower(const QString&value);
void updateMeasuredUpper(const QString&value);
void updateMappedLower(const QString&value);
void updateMappedUpper(const QString&value);
void updateClosedInterval(bool closed);
void updateSmoothingEnabled(bool enabled);
void updateSensitivity(const QString&value);
void startCalibration();
void stopCalibration();
void resetCalibration();
void updateInput(Measurement measure);
void updateOutput(Measurement measure);
void updateHidden(bool hidden);
private:
QPushButton*startButton;
QPushButton*resetButton;
QPushButton*stopButton;
/*1096:*/
#line 1098 "./dataqsdk.w"

bool autoSelect;
QString deviceID;
unsigned int channelOfInterest;

/*:1096*/
#line 835 "./dataqsdk.w"

DataqSdkDevice*calibrationDevice;
LinearCalibrator*calibrator;
QLineEdit*currentMeasurement;
QLineEdit*minimumMeasurement;
QLineEdit*maximumMeasurement;
QLineEdit*averageMeasurement;
QLineEdit*currentMapped;
QLineEdit*minimumMapped;
QLineEdit*maximumMapped;
QLineEdit*averageMapped;
int rmCount;
int cmCount;
double rmin;
double rmax;
double rmean;
double cmin;
double cmax;
double cmean;
};

/*:1091*//*1118:*/
#line 273 "./scales.w"

Q_DECLARE_METATYPE(BaudRateType)
Q_DECLARE_METATYPE(DataBitsType)
Q_DECLARE_METATYPE(ParityType)
Q_DECLARE_METATYPE(StopBitsType)
Q_DECLARE_METATYPE(FlowType)

/*:1118*//*1125:*/
#line 396 "./scales.w"

class SerialScaleConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE SerialScaleConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updatePort(const QString&newPort);
void updateBaudRate(const QString&rate);
void updateParity(int index);
void updateFlowControl(int index);
void updateStopBits(int index);
void updateWeighCommand(const QString&command);
void updateCommandTerminator(const QString&terminator);
private:
PortSelector*port;
BaudSelector*baud;
ParitySelector*parity;
FlowSelector*flow;
StopSelector*stop;
QLineEdit*weighcommand;
QComboBox*commandterminator;
};

/*:1125*//*1130:*/
#line 14 "./valueannotation.w"

class ValueAnnotationConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ValueAnnotationConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateSourceColumn(const QString&source);
void updateAnnotations();
void updateStart(bool noteOnStart);
private:
SaltModel*tablemodel;
};

/*:1130*//*1138:*/
#line 165 "./valueannotation.w"

class ValueAnnotation:public QObject
{
Q_OBJECT
public:
ValueAnnotation();
Q_INVOKABLE void setAnnotation(double value,const QString&annotation);
public slots:
void newMeasurement(Measurement measure);
void annotate();
void setAnnotationColumn(int column);
void setTemperatureColumn(int column);
void setTolerance(double epsilon);
signals:
void annotation(QString annotation,int tempcolumn,int notecolumn);
private:
int lastIndex;
int annotationColumn;
int measurementColumn;
QList<double> values;
QStringList annotations;
double tolerance;
};

/*:1138*//*1147:*/
#line 14 "./thresholdannotation.w"

class ThresholdAnnotationConfWidget:public BasicDeviceConfigurationWidget
{
Q_OBJECT
public:
Q_INVOKABLE ThresholdAnnotationConfWidget(DeviceTreeModel*model,
const QModelIndex&index);
private slots:
void updateSourceColumn(const QString&source);
void updateThreshold(double value);
void updateDirection(int index);
void updateAnnotation(const QString&note);
};

/*:1147*//*1152:*/
#line 127 "./thresholdannotation.w"

class Annotator:public QObject
{
Q_OBJECT
QString note;
int tc;
int ac;
QTimer t;
public:
Annotator(const QString&text);
public slots:
void setAnnotation(const QString&annotation);
void setTemperatureColumn(int tempcolumn);
void setAnnotationColumn(int annotationcolumn);
void annotate();
private slots:
void catchTimer();
signals:
void annotation(QString annotation,int tempcolumn,int notecolumn);
};

/*:1152*//*1163:*/
#line 78 "./user.w"

class LoginDialog:public QDialog
{
Q_OBJECT
public:
LoginDialog();
public slots:
void attemptLogin();
private:
QLineEdit*user;
QLineEdit*password;
QLabel*warning;
QPushButton*login;
};

/*:1163*//*1169:*/
#line 162 "./user.w"

class UserLabel:public QLabel
{
Q_OBJECT
public:
UserLabel();
public slots:
void updateLabel(const QString&user);
protected:
void mouseReleaseEvent(QMouseEvent*event);
};

/*:1169*//*1173:*/
#line 209 "./user.w"

class NewTypicaUser:public QDialog
{
Q_OBJECT
public:
NewTypicaUser();
public slots:
void createAndReset();
void createAndClose();
void validate();
void cancelValidate();
private:
void createNewUser();
QLineEdit*userField;
QLineEdit*passwordField;
QCheckBox*autoLogin;
QPushButton*saveAndCloseButton;
QPushButton*saveAndNewButton;
QPushButton*cancelButton;
};

/*:1173*//*1180:*/
#line 9 "./roastcoloredit.w"

class RoastColorEdit:public QWidget
{
Q_OBJECT
Q_PROPERTY(QString value READ value WRITE setValue)
public:
RoastColorEdit();
QString value();
public slots:
void setValue(const QString&color);
private slots:
void readColor();
void measureFinished();
void readFinished();
private:
QLineEdit*edit;
QNetworkReply*networkReply;
};

/*:1180*/
#line 528 "./typica.w"

/*990:*/
#line 203 "./phidget22.w"

void CCONV ChannelListAddChannel(void*,void*context,void*device)
{
PhidgetChannelSelector*list= 
qobject_cast<PhidgetChannelSelector*> ((QObject*)context);
list->addChannel(device);
}

void CCONV ChannelListRemoveChannel(void*,void*context,void*device)
{
PhidgetChannelSelector*list= 
qobject_cast<PhidgetChannelSelector*> ((QObject*)context);
list->removeChannel(device);
}

/*:990*//*1005:*/
#line 762 "./phidget22.w"

void CCONV Phidget22ValueCallback(void*,void*context,double value)
{
Channel*channel= (Channel*)context;
QTime time= QTime::currentTime();
Measurement measure(value*9.0/5.0+32.0,time);
channel->input(measure);
}

/*:1005*/
#line 529 "./typica.w"

/*12:*/
#line 820 "./typica.w"

void setQObjectProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QObject_setProperty(QScriptContext*context,QScriptEngine*engine);

/*:12*//*14:*/
#line 845 "./typica.w"

void setQPaintDeviceProperties(QScriptValue value,QScriptEngine*engine);
void setQLayoutItemProperties(QScriptValue value,QScriptEngine*engine);

/*:14*//*19:*/
#line 905 "./typica.w"

void setQWidgetProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructQWidget(QScriptContext*context,QScriptEngine*engine);
QScriptValue QWidget_setLayout(QScriptContext*context,QScriptEngine*engine);
QScriptValue QWidget_activateWindow(QScriptContext*context,
QScriptEngine*engine);

/*:19*//*23:*/
#line 995 "./typica.w"

QScriptValue displayWarning(QScriptContext*context,QScriptEngine*engine);
QScriptValue displayError(QScriptContext*context,QScriptEngine*engine);
QScriptValue displayInfo(QScriptContext*context,QScriptEngine*engine);

/*:23*//*33:*/
#line 1229 "./typica.w"

QScriptValue constructQMainWindow(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QMainWindow_setCentralWidget(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QMainWindow_menuBar(QScriptContext*context,
QScriptEngine*engine);
void setQMainWindowProperties(QScriptValue value,QScriptEngine*engine);

/*:33*//*38:*/
#line 1328 "./typica.w"

void setQMenuBarProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QMenuBar_addMenu(QScriptContext*context,QScriptEngine*engine);

/*:38*//*41:*/
#line 1373 "./typica.w"

void setQMenuProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QMenu_addAction(QScriptContext*context,QScriptEngine*engine);
QScriptValue QMenu_addSeparator(QScriptContext*context,QScriptEngine*engine);

/*:41*//*44:*/
#line 1439 "./typica.w"

void setQFrameProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructQFrame(QScriptContext*context,QScriptEngine*engine);

/*:44*//*47:*/
#line 1472 "./typica.w"

void setQLabelProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructQLabel(QScriptContext*context,QScriptEngine*engine);

/*:47*//*50:*/
#line 1510 "./typica.w"

void setQSvgWidgetProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructQSvgWidget(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QSvgWidget_loadDevice(QScriptContext*context,
QScriptEngine*engine);
void addSvgWidgetToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);

/*:50*//*56:*/
#line 1597 "./typica.w"

void setQLineEditProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructQLineEdit(QScriptContext*context,QScriptEngine*engine);

/*:56*//*60:*/
#line 1636 "./typica.w"

QScriptValue constructQSplitter(QScriptContext*context,QScriptEngine*engine);
QScriptValue QSplitter_addWidget(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QSplitter_saveState(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QSplitter_restoreState(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QSplitter_count(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QSplitter_setCollapsible(QScriptContext*context,
QScriptEngine*engine);
void setQSplitterProperties(QScriptValue value,QScriptEngine*engine);

/*:60*//*67:*/
#line 1797 "./typica.w"

void setQLayoutProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QLayout_addWidget(QScriptContext*context,QScriptEngine*engine);

/*:67*//*69:*/
#line 1852 "./typica.w"

QScriptValue constructQBoxLayout(QScriptContext*context,
QScriptEngine*engine);
void setQBoxLayoutProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QBoxLayout_addLayout(QScriptContext*context,QScriptEngine*engine);
QScriptValue QBoxLayout_addWidget(QScriptContext*context,QScriptEngine*engine);

/*:69*//*73:*/
#line 1965 "./typica.w"

QScriptValue constructQAction(QScriptContext*context,QScriptEngine*engine);
QScriptValue QAction_setShortcut(QScriptContext*context,
QScriptEngine*engine);
void setQActionProperties(QScriptValue value,QScriptEngine*engine);

/*:73*//*76:*/
#line 2021 "./typica.w"

QScriptValue QFileDialog_getOpenFileName(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QFileDialog_getSaveFileName(QScriptContext*context,
QScriptEngine*engine);
void setQFileDialogProperties(QScriptValue value,QScriptEngine*engine);
void setQDialogProperties(QScriptValue value,QScriptEngine*engine);

/*:76*//*81:*/
#line 2132 "./typica.w"

QScriptValue constructQFile(QScriptContext*context,QScriptEngine*engine);
void setQFileProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QFile_remove(QScriptContext*context,QScriptEngine*engine);
void setQIODeviceProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QIODevice_open(QScriptContext*context,QScriptEngine*engine);
QScriptValue QIODevice_close(QScriptContext*context,QScriptEngine*engine);
QScriptValue QIODevice_readToString(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QIODevice_putChar(QScriptContext*context,QScriptEngine*engine);
QScriptValue QIODevice_writeString(QScriptContext*context,QScriptEngine*engine);
QScriptValue QIODevice_writeBytes(QScriptContext*context,QScriptEngine*engine);
QScriptValue QIODevice_readBytes(QScriptContext*context,QScriptEngine*engine);
QScriptValue QIODevice_peek(QScriptContext*context,QScriptEngine*engine);
QScriptValue QIODevice_read(QScriptContext*context,QScriptEngine*engine);

/*:81*//*92:*/
#line 2358 "./typica.w"

QScriptValue constructQProcess(QScriptContext*context,QScriptEngine*engine);
void setQProcessProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QProcess_execute(QScriptContext*context,QScriptEngine*engine);
QScriptValue QProcess_startDetached(QScriptContext*context,QScriptEngine*engine);
QScriptValue QProcess_setWorkingDirectory(QScriptContext*context,QScriptEngine*engine);
QScriptValue QProcess_start(QScriptContext*context,QScriptEngine*engine);

/*:92*//*100:*/
#line 2476 "./typica.w"

QScriptValue QByteArray_toScriptValue(QScriptEngine*engine,const QByteArray&bytes);
void QByteArray_fromScriptValue(const QScriptValue&value,QByteArray&bytes);
QScriptValue constructQByteArray(QScriptContext*context,QScriptEngine*engine);
void setQByteArrayProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QByteArray_fromHex(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_getAt(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_setAt(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_appendBytes(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_appendString(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_size(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_left(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_right(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_mid(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_chop(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_remove(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_toInt8(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_toInt16(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_toInt32(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_toFloat(QScriptContext*context,QScriptEngine*engine);
QScriptValue QByteArray_toDouble(QScriptContext*context,QScriptEngine*engine);

/*:100*//*113:*/
#line 2750 "./typica.w"

QScriptValue bytesFromInt8(QScriptContext*context,QScriptEngine*engine);
QScriptValue bytesFromInt16(QScriptContext*context,QScriptEngine*engine);
QScriptValue bytesFromInt32(QScriptContext*context,QScriptEngine*engine);
QScriptValue bytesFromFloat(QScriptContext*context,QScriptEngine*engine);
QScriptValue bytesFromDouble(QScriptContext*context,QScriptEngine*engine);

/*:113*//*116:*/
#line 2855 "./typica.w"

QScriptValue constructQBuffer(QScriptContext*context,QScriptEngine*engine);
void setQBufferProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QBuffer_setData(QScriptContext*context,QScriptEngine*engine);
QScriptValue QBuffer_data(QScriptContext*context,QScriptEngine*engine);

/*:116*//*119:*/
#line 2908 "./typica.w"

QScriptValue constructXQuery(QScriptContext*context,QScriptEngine*engine);
QScriptValue XQuery_bind(QScriptContext*context,QScriptEngine*engine);
QScriptValue XQuery_exec(QScriptContext*context,QScriptEngine*engine);
QScriptValue XQuery_setQuery(QScriptContext*context,QScriptEngine*engine);
QScriptValue XQuery_invalidate(QScriptContext*context,QScriptEngine*engine);
void setXQueryProperties(QScriptValue value,QScriptEngine*engine);

/*:119*//*125:*/
#line 2990 "./typica.w"

QScriptValue constructXmlWriter(QScriptContext*context,QScriptEngine*engine);
QScriptValue XmlWriter_setDevice(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeAttribute(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeCDATA(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeCharacters(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeDTD(QScriptContext*context,QScriptEngine*engine);
QScriptValue XmlWriter_writeEmptyElement(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeEndDocument(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeEndElement(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeEntityReference(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeProcessingInstruction(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeStartDocument(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeStartElement(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlWriter_writeTextElement(QScriptContext*context,
QScriptEngine*engine);
void setXmlWriterProperties(QScriptValue value,QScriptEngine*engine);

/*:125*//*134:*/
#line 3208 "./typica.w"

QScriptValue constructXmlReader(QScriptContext*context,QScriptEngine*engine);
QScriptValue XmlReader_atEnd(QScriptContext*context,QScriptEngine*engine);
QScriptValue XmlReader_attribute(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlReader_hasAttribute(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlReader_isDTD(QScriptContext*context,QScriptEngine*engine);
QScriptValue XmlReader_isStartElement(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlReader_name(QScriptContext*context,QScriptEngine*engine);
QScriptValue XmlReader_readElementText(QScriptContext*context,
QScriptEngine*engine);
QScriptValue XmlReader_readNext(QScriptContext*context,QScriptEngine*engine);
QScriptValue XmlReader_text(QScriptContext*context,QScriptEngine*engine);
void setXmlReaderProperties(QScriptValue value,QScriptEngine*engine);

/*:134*//*141:*/
#line 3343 "./typica.w"

QScriptValue QSettings_value(QScriptContext*context,QScriptEngine*engine);
QScriptValue QSettings_setValue(QScriptContext*context,QScriptEngine*engine);
void setQSettingsProperties(QScriptValue value,QScriptEngine*engine);

/*:141*//*145:*/
#line 3425 "./typica.w"

QScriptValue constructQLCDNumber(QScriptContext*context,
QScriptEngine*engine);
void setQLCDNumberProperties(QScriptValue value,QScriptEngine*engine);

/*:145*//*148:*/
#line 3463 "./typica.w"

QScriptValue constructQTime(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_addMSecs(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_addSecs(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_elapsed(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_hour(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_isNull(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_isValid(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_minute(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_msec(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_msecsTo(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_restart(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_second(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_secsTo(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_setHMS(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_start(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_toString(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_currentTime(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_fromString(QScriptContext*context,QScriptEngine*engine);
QScriptValue QTime_valueOf(QScriptContext*context,QScriptEngine*engine);
void setQTimeProperties(QScriptValue value,QScriptEngine*engine);

/*:148*//*164:*/
#line 3940 "./typica.w"

QScriptValue constructQColor(QScriptContext*context,QScriptEngine*engine);

/*:164*//*167:*/
#line 3964 "./typica.w"

QScriptValue constructQBrush(QScriptContext*context,QScriptEngine*engine);

/*:167*//*170:*/
#line 3989 "./typica.w"

void setQAbstractScrollAreaProperties(QScriptValue value,
QScriptEngine*engine);

/*:170*//*172:*/
#line 4004 "./typica.w"

void setQAbstractItemViewProperties(QScriptValue value,QScriptEngine*engine);

/*:172*//*174:*/
#line 4017 "./typica.w"

void setQGraphicsViewProperties(QScriptValue value,QScriptEngine*engine);
void setQTableViewProperties(QScriptValue value,QScriptEngine*engine);

/*:174*//*176:*/
#line 4041 "./typica.w"

void setQAbstractButtonProperties(QScriptValue value,QScriptEngine*engine);
void setQPushButtonProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructQPushButton(QScriptContext*context,
QScriptEngine*engine);

/*:176*//*183:*/
#line 4140 "./typica.w"

void setQSqlQueryProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructQSqlQuery(QScriptContext*context,QScriptEngine*engine);
QScriptValue QSqlQuery_bind(QScriptContext*context,QScriptEngine*engine);
QScriptValue QSqlQuery_bindDeviceData(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QSqlQuery_bindFileData(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QSqlQuery_exec(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QSqlQuery_executedQuery(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QSqlQuery_invalidate(QScriptContext*context,QScriptEngine*engine);
QScriptValue QSqlQuery_next(QScriptContext*context,QScriptEngine*engine);
QScriptValue QSqlQuery_prepare(QScriptContext*context,QScriptEngine*engine);
QScriptValue QSqlQuery_value(QScriptContext*context,QScriptEngine*engine);

/*:183*//*190:*/
#line 4311 "./typica.w"

QScriptValue baseName(QScriptContext*context,QScriptEngine*engine);
QScriptValue dir(QScriptContext*context,QScriptEngine*engine);
QScriptValue sqlToArray(QScriptContext*context,QScriptEngine*engine);
QScriptValue setFont(QScriptContext*context,QScriptEngine*engine);
QScriptValue annotationFromRecord(QScriptContext*context,
QScriptEngine*engine);
QScriptValue setTabOrder(QScriptContext*context,QScriptEngine*engine);
QScriptValue saveFileFromDatabase(QScriptContext*context,QScriptEngine*engine);
QScriptValue scriptTr(QScriptContext*context,QScriptEngine*engine);

/*:190*//*203:*/
#line 4658 "./typica.w"

QScriptValue createWindow(QScriptContext*context,QScriptEngine*engine);
QScriptValue createReport(QScriptContext*context,QScriptEngine*engine);
void addLayoutToWidget(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addLayoutToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addSplitterToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addSplitterToSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void populateGridLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void populateBoxLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void populateSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void populateWidget(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void populateStackedLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addTemperatureDisplayToSplitter(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addTemperatureDisplayToLayout(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addTimerDisplayToSplitter(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addTimerDisplayToLayout(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addDecorationToSplitter(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addDecorationToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addWidgetToSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addButtonToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addZoomLogToSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addGraphToSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addSqlDropToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addSaltToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addLineToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addTextToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addSqlQueryViewToLayout(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addCalendarToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addSpinBoxToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addTimeEditToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);

/*:203*//*232:*/
#line 5139 "./typica.w"

QScriptValue constructQTabBar(QScriptContext*context,QScriptEngine*engine);
void setQTabBarProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QTabBar_addTab(QScriptContext*context,QScriptEngine*engine);

/*:232*//*274:*/
#line 6467 "./typica.w"

void setQDateEditProperties(QScriptValue value,QScriptEngine*engine);
void setQDateTimeEditProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QDateTimeEdit_setDate(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QDateTimeEdit_day(QScriptContext*context,QScriptEngine*engine);
QScriptValue QDateTimeEdit_month(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QDateTimeEdit_year(QScriptContext*context,QScriptEngine*engine);
QScriptValue QDateTimeEdit_setToCurrentTime(QScriptContext*context,QScriptEngine*engine);

/*:274*//*277:*/
#line 6512 "./typica.w"

void setQTimeEditProperties(QScriptValue value,QScriptEngine*engine);

/*:277*//*278:*/
#line 6520 "./typica.w"

QScriptValue findChildObject(QScriptContext*context,QScriptEngine*engine);

/*:278*//*282:*/
#line 6667 "./typica.w"

void setSaltTableProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue SaltTable_bindableColumnArray(QScriptContext*context,
QScriptEngine*engine);
QScriptValue SaltTable_bindableQuotedColumnArray(QScriptContext*context,
QScriptEngine*engine);
QScriptValue SaltTable_columnSum(QScriptContext*context,
QScriptEngine*engine);
QScriptValue SaltTable_columnArray(QScriptContext*context,
QScriptEngine*engine);
QScriptValue SaltTable_data(QScriptContext*context,QScriptEngine*engine);
QScriptValue SaltTable_model(QScriptContext*context,QScriptEngine*engine);
QScriptValue SaltTable_quotedColumnArray(QScriptContext*context,
QScriptEngine*engine);
QScriptValue SaltTable_setData(QScriptContext*context,QScriptEngine*engine);
QScriptValue SaltTable_clear(QScriptContext*context,QScriptEngine*engine);
QScriptValue SaltTable_removeRow(QScriptContext*context,QScriptEngine*engine);
QScriptValue SaltTable_findData(QScriptContext*context,QScriptEngine*engine);

/*:282*//*292:*/
#line 6883 "./typica.w"

void setSqlComboBoxProperties(QScriptValue value,QScriptEngine*engine);
void setQComboBoxProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QComboBox_currentData(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QComboBox_addItem(QScriptContext*context,QScriptEngine*engine);
QScriptValue QComboBox_setModel(QScriptContext*context,QScriptEngine*engine);
QScriptValue QComboBox_findText(QScriptContext*context,QScriptEngine*engine);
QScriptValue QComboBox_findData(QScriptContext*context,QScriptEngine*engine);

/*:292*//*304:*/
#line 379 "./units.w"

QScriptValue Units_convertTemperature(QScriptContext*context,QScriptEngine*engine);
QScriptValue Units_convertRelativeTemperature(QScriptContext*context,
QScriptEngine*engine);
QScriptValue Units_isTemperatureUnit(QScriptContext*context,QScriptEngine*engine);
QScriptValue Units_convertWeight(QScriptContext*context,QScriptEngine*engine);
QScriptValue Units_isWeightUnit(QScriptContext*context,QScriptEngine*engine);

/*:304*//*308:*/
#line 443 "./units.w"

QScriptValue Unit_toScriptValue(QScriptEngine*engine,const Units::Unit&value);
void Unit_fromScriptValue(const QScriptValue&sv,Units::Unit&value);

/*:308*//*317:*/
#line 133 "./measurement.w"

QScriptValue constructMeasurement(QScriptContext*context,QScriptEngine*engine);
void setMeasurementProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue Measurement_toScriptValue(QScriptEngine*engine,const Measurement&measurement);
void Measurement_fromScriptValue(const QScriptValue&value,Measurement&measurement);

/*:317*//*337:*/
#line 7518 "./typica.w"

QScriptValue constructDAQ(QScriptContext*context,QScriptEngine*engine);
QScriptValue DAQ_newChannel(QScriptContext*context,QScriptEngine*engine);
void setDAQProperties(QScriptValue value,QScriptEngine*engine);

/*:337*//*346:*/
#line 7723 "./typica.w"

QScriptValue constructFakeDAQ(QScriptContext*context,QScriptEngine*engine);
QScriptValue FakeDAQ_newChannel(QScriptContext*context,QScriptEngine*engine);
void setFakeDAQProperties(QScriptValue value,QScriptEngine*engine);

/*:346*//*351:*/
#line 7824 "./typica.w"

void setChannelProperties(QScriptValue value,QScriptEngine*engine);

/*:351*//*357:*/
#line 8006 "./typica.w"

QScriptValue constructLinearCalibrator(QScriptContext*context,
QScriptEngine*engine);
void setLinearCalibratorProperties(QScriptValue value,QScriptEngine*engine);

/*:357*//*362:*/
#line 8146 "./typica.w"

QScriptValue constructLinearSplineInterpolator(QScriptContext*context,QScriptEngine*engine);
void setLinearSplineInterpolatorProperties(QScriptValue value,QScriptEngine*engine);

/*:362*//*372:*/
#line 8351 "./typica.w"

QScriptValue constructTemperatureDisplay(QScriptContext*context,
QScriptEngine*engine);
void setTemperatureDisplayProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue TemperatureDisplay_setDisplayUnits(QScriptContext*context,
QScriptEngine*engine);

/*:372*//*380:*/
#line 8510 "./typica.w"

QScriptValue constructMeasurementTimeOffset(QScriptContext*context,
QScriptEngine*engine);
void setMeasurementTimeOffsetProperties(QScriptValue value,
QScriptEngine*engine);

/*:380*//*385:*/
#line 8633 "./typica.w"

QScriptValue constructThresholdDetector(QScriptContext*context,QScriptEngine*engine);
void setThresholdDetectorProperties(QScriptValue value,QScriptEngine*engine);

/*:385*//*390:*/
#line 8731 "./typica.w"

QScriptValue constructZeroEmitter(QScriptContext*context,
QScriptEngine*engine);
void setZeroEmitterProperties(QScriptValue value,QScriptEngine*engine);

/*:390*//*395:*/
#line 8810 "./typica.w"

QScriptValue constructMeasurementAdapter(QScriptContext*context,
QScriptEngine*engine);
void setMeasurementAdapterProperties(QScriptValue value,QScriptEngine*engine);

/*:395*//*412:*/
#line 9274 "./typica.w"

void setGraphViewProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructGraphView(QScriptContext*context,QScriptEngine*engine);

/*:412*//*435:*/
#line 9913 "./typica.w"

void setZoomLogProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructZoomLog(QScriptContext*context,QScriptEngine*engine);
QScriptValue ZoomLog_saveXML(QScriptContext*context,QScriptEngine*engine);
QScriptValue ZoomLog_saveCSV(QScriptContext*context,QScriptEngine*engine);
QScriptValue ZoomLog_saveState(QScriptContext*context,QScriptEngine*engine);
QScriptValue ZoomLog_restoreState(QScriptContext*context,
QScriptEngine*engine);
QScriptValue ZoomLog_lastTime(QScriptContext*context,QScriptEngine*engine);
QScriptValue ZoomLog_saveTemporary(QScriptContext*context,
QScriptEngine*engnie);
QScriptValue ZoomLog_setDisplayUnits(QScriptContext*context,
QScriptEngine*engine);

/*:435*//*475:*/
#line 10925 "./typica.w"

QScriptValue constructAnnotationButton(QScriptContext*context,
QScriptEngine*engine);
void setAnnotationButtonProperties(QScriptValue value,QScriptEngine*engine);

/*:475*//*483:*/
#line 11065 "./typica.w"

QScriptValue constructAnnotationSpinBox(QScriptContext*context,
QScriptEngine*engine);
void setAnnotationSpinBoxProperties(QScriptValue value,QScriptEngine*engine);
void setQDoubleSpinBoxProperties(QScriptValue value,QScriptEngine*engine);
void setQAbstractSpinBoxProperties(QScriptValue value,QScriptEngine*engine);

/*:483*//*504:*/
#line 11491 "./typica.w"

QScriptValue constructTimerDisplay(QScriptContext*context,
QScriptEngine*engine);
void setTimerDisplayProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue TimerDisplay_setTimerMode(QScriptContext*context,QScriptEngine*engine);

/*:504*//*532:*/
#line 12016 "./typica.w"

void setWidgetDecoratorProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructWidgetDecorator(QScriptContext*context,
QScriptEngine*engine);

/*:532*//*545:*/
#line 12299 "./typica.w"

QScriptValue constructLogEditWindow(QScriptContext*context,
QScriptEngine*engine);

/*:545*//*564:*/
#line 12826 "./typica.w"

QScriptValue constructXMLInput(QScriptContext*context,QScriptEngine*engine);
QScriptValue XMLInput_input(QScriptContext*context,QScriptEngine*engine);

/*:564*//*583:*/
#line 209 "./webview.w"

QScriptValue constructWebView(QScriptContext*context,QScriptEngine*engine);
void setQWebViewProperties(QScriptValue value,QScriptEngine*engine);
void addWebViewToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);

/*:583*//*586:*/
#line 239 "./webview.w"

QScriptValue QWebElement_toScriptValue(QScriptEngine*engine,const QWebElement&element);
void QWebElement_fromScriptValue(const QScriptValue&value,QWebElement&element);

/*:586*//*590:*/
#line 297 "./webview.w"

QScriptValue constructWebElement(QScriptContext*context,
QScriptEngine*engine);

/*:590*//*602:*/
#line 67 "./printerselector.w"

QScriptValue constructPrinterSelector(QScriptContext*context,
QScriptEngine*engine);
void addPrinterSelectorToLayout(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);

/*:602*//*617:*/
#line 13197 "./typica.w"

QScriptValue Application_subscribe(QScriptContext*context,
QScriptEngine*engine);

/*:617*//*675:*/
#line 14324 "./typica.w"

void setSqlQueryViewProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue constructSqlQueryView(QScriptContext*context,
QScriptEngine*engine);
QScriptValue SqlQueryView_setQuery(QScriptContext*context,
QScriptEngine*engine);
QScriptValue SqlQueryView_setHeaderData(QScriptContext*context,
QScriptEngine*engine);
QScriptValue SqlQueryView_rows(QScriptContext*context,
QScriptEngine*engine);

/*:675*//*685:*/
#line 14572 "./typica.w"

void addReportToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);

/*:685*//*701:*/
#line 14857 "./typica.w"

void setQTextEditProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue QTextEdit_print(QScriptContext*context,QScriptEngine*engine);

/*:701*//*729:*/
#line 480 "./daterangeselector.w"

void addDateRangeToLayout(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);

/*:729*//*738:*/
#line 15056 "./typica.w"

void addFormArrayToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);

/*:738*//*759:*/
#line 15640 "./typica.w"

void addScaleControlToLayout(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);
void addIntensityControlToLayout(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack);

/*:759*//*785:*/
#line 16226 "./typica.w"

QScriptValue constructDeviceTreeModel(QScriptContext*context,
QScriptEngine*engine);
void setDeviceTreeModelProperties(QScriptValue value,QScriptEngine*engine);
void setQAbstractItemModelProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue DeviceTreeModel_referenceElement(QScriptContext*context,
QScriptEngine*engine);
QScriptValue QAbstractItemModel_data(QScriptContext*context,QScriptEngine*engine);
QScriptValue QAbstractItemModel_index(QScriptContext*context,QScriptEngine*engine);
QScriptValue QAbstractItemModel_rowCount(QScriptContext*context,QScriptEngine*engine);
QScriptValue QAbstractItemModel_hasChildren(QScriptContext*context,QScriptEngine*engine);

/*:785*//*791:*/
#line 16368 "./typica.w"

QScriptValue QModelIndex_toScriptValue(QScriptEngine*engine,const QModelIndex&index);
void QModelIndex_fromScriptValue(const QScriptValue&value,QModelIndex&index);

/*:791*//*807:*/
#line 16666 "./typica.w"

QScriptValue constructDeviceConfigurationWindow(QScriptContext*context,
QScriptEngine*engine);

/*:807*//*878:*/
#line 44 "./settings.w"

QScriptValue constructSettingsWindow(QScriptContext*context,QScriptEngine*engine);

/*:878*//*906:*/
#line 19305 "./typica.w"

QScriptValue constructModbusRTUDevice(QScriptContext*context,QScriptEngine*engine);
QScriptValue ModbusRTUDevice_pVChannel(QScriptContext*context,QScriptEngine*engine);
QScriptValue ModbusRTUDevice_sVChannel(QScriptContext*context,QScriptEngine*engine);
void setModbusRTUDeviceProperties(QScriptValue value,QScriptEngine*engine);

/*:906*//*924:*/
#line 698 "./modbus.w"

QScriptValue constructModbusNG(QScriptContext*context,QScriptEngine*engine);
void setModbusNGProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue ModbusNG_getChannel(QScriptContext*context,QScriptEngine*engine);

/*:924*//*938:*/
#line 348 "./unsupportedserial.w"

QScriptValue createDevice(QScriptContext*context,QScriptEngine*engine);

/*:938*//*944:*/
#line 428 "./unsupportedserial.w"

QScriptValue JavaScriptDevice_getChannel(QScriptContext*context,QScriptEngine*engine);

/*:944*//*950:*/
#line 620 "./unsupportedserial.w"

QScriptValue getMeasurementTimestamp(QScriptContext*context,QScriptEngine*engine);

/*:950*//*954:*/
#line 654 "./unsupportedserial.w"

QScriptValue constructSerialPort(QScriptContext*context,QScriptEngine*engine);
void setSerialPortProperties(QScriptValue value,QScriptEngine*engine);
QScriptValue SerialPort_flush(QScriptContext*context,QScriptEngine*engine);

/*:954*//*978:*/
#line 457 "./phidgets.w"

QScriptValue constructPhidgetsTemperatureSensor(QScriptContext*context,QScriptEngine*engine);
QScriptValue Phidgets_getChannel(QScriptContext*context,QScriptEngine*engine);

/*:978*//*1010:*/
#line 805 "./phidget22.w"

QScriptValue constructPhidget22(QScriptContext*context,QScriptEngine*engine);
QScriptValue Phidget22_getChannel(QScriptContext*context,QScriptEngine*engine);

/*:1010*//*1042:*/
#line 138 "./rate.w"

QScriptValue constructRateOfChange(QScriptContext*context,QScriptEngine*engine);
void setRateOfChangeProperties(QScriptValue value,QScriptEngine*engine);

/*:1042*//*1056:*/
#line 129 "./mergeseries.w"

QScriptValue constructDifferenceSeries(QScriptContext*context,
QScriptEngine*engine);
QScriptValue constructMeanSeries(QScriptContext*context,
QScriptEngine*engine);

/*:1056*//*1081:*/
#line 597 "./dataqsdk.w"

QScriptValue constructDataqSdkDevice(QScriptContext*context,QScriptEngine*engine);
QScriptValue DataqSdkDevice_newChannel(QScriptContext*context,QScriptEngine*engine);
void setDataqSdkDeviceProperties(QScriptValue value,QScriptEngine*engine);

/*:1081*//*1108:*/
#line 67 "./scales.w"

QScriptValue constructDragLabel(QScriptContext*context,QScriptEngine*engine);
void setDragLabelProperties(QScriptValue value,QScriptEngine*engine);

/*:1108*//*1116:*/
#line 259 "./scales.w"

QScriptValue constructSerialScale(QScriptContext*context,QScriptEngine*engine);
void setSerialScaleProperties(QScriptValue value,QScriptEngine*engine);

/*:1116*//*1119:*/
#line 284 "./scales.w"

QScriptValue BaudRateType_toScriptValue(QScriptEngine*engine,const BaudRateType&value);
void BaudRateType_fromScriptValue(const QScriptValue&sv,BaudRateType&value);
QScriptValue DataBitsType_toScriptValue(QScriptEngine*engine,const DataBitsType&value);
void DataBitsType_fromScriptValue(const QScriptValue&sv,DataBitsType&value);
QScriptValue ParityType_toScriptValue(QScriptEngine*engine,const ParityType&value);
void ParityType_fromScriptValue(const QScriptValue&sv,ParityType&value);
QScriptValue StopBitsType_toScriptValue(QScriptEngine*engine,const StopBitsType&value);
void StopBitsType_fromScriptValue(const QScriptValue&sv,StopBitsType&value);
QScriptValue FlowType_toScriptValue(QScriptEngine*engine,const FlowType&value);
void FlowType_fromScriptValue(const QScriptValue&sv,FlowType&value);

/*:1119*//*1144:*/
#line 265 "./valueannotation.w"

QScriptValue constructValueAnnotation(QScriptContext*context,QScriptEngine*engine);
void setValueAnnotationProperties(QScriptValue value,QScriptEngine*engine);

/*:1144*//*1155:*/
#line 194 "./thresholdannotation.w"

QScriptValue constructAnnotator(QScriptContext*context,
QScriptEngine*engine);
void setAnnotatorProperties(QScriptValue value,QScriptEngine*engine);

/*:1155*//*1168:*/
#line 151 "./user.w"

QScriptValue constructLoginDialog(QScriptContext*context,QScriptEngine*engine);

/*:1168*//*1178:*/
#line 339 "./user.w"

QScriptValue constructNewTypicaUser(QScriptContext*context,QScriptEngine*engine);

/*:1178*/
#line 530 "./typica.w"

/*655:*/
#line 13957 "./typica.w"

void messageFileOutput(QtMsgType type,const char*msg);

/*:655*/
#line 531 "./typica.w"

/*4:*/
#line 540 "./typica.w"

/*799:*/
#line 16489 "./typica.w"

NodeInserter::NodeInserter(const QString&title,const QString&name,
const QString&driver,QObject*parent):
QAction(title,parent),defaultNodeName(name),driverString(driver)
{
connect(this,SIGNAL(triggered()),this,SLOT(onTriggered()));
}

void NodeInserter::onTriggered()
{
emit triggered(defaultNodeName,driverString);
}

/*:799*/
#line 541 "./typica.w"

/*313:*/
#line 40 "./measurement.w"

Measurement::Measurement(double temperature,QTime time,Units::Unit sc)
{
insert("measurement",temperature);
insert("time",time);
insert("unit",sc);
}

Measurement::Measurement(double temperature)
{
insert("measurement",temperature);
insert("time",QTime::currentTime());
insert("unit",Units::Fahrenheit);
}

void Measurement::setTemperature(double temperature)
{
insert("measurement",temperature);
}

void Measurement::setTime(QTime time)
{
insert("time",time);
}

void Measurement::setUnit(Units::Unit scale)
{
insert("unit",scale);
}

double Measurement::temperature()const
{
return value("measurement").toDouble();
}

QTime Measurement::time()const
{
return value("time").toTime();
}

Units::Unit Measurement::scale()const
{
return(Units::Unit)(value("unit").toInt());
}

/*:313*//*314:*/
#line 88 "./measurement.w"

Measurement Measurement::toFahrenheit()
{
return Measurement(Units::convertTemperature(this->temperature(),
this->scale(),Units::Fahrenheit),
this->time(),Units::Fahrenheit);
}

Measurement Measurement::toCelsius()
{
return Measurement(Units::convertTemperature(this->temperature(),
this->scale(),Units::Celsius),
this->time(),Units::Celsius);
}

Measurement Measurement::toKelvin()
{
return Measurement(Units::convertTemperature(this->temperature(),
this->scale(),Units::Kelvin),
this->time(),Units::Kelvin);
}

Measurement Measurement::toRankine()
{
return Measurement(Units::convertTemperature(this->temperature(),
this->scale(),Units::Rankine),
this->time(),Units::Rankine);
}

/*:314*/
#line 542 "./typica.w"

/*327:*/
#line 7123 "./typica.w"

void DAQImplementation::measure()
{
int samplesRead= 0;
double buffer[channels];
error= read((unsigned int)(handle),(signed long)(1),(double)(10.0),
(unsigned long)(0),buffer,(unsigned long)(channels),
&samplesRead,(signed long)(0));
if(error)
{
ready= false;
}
else
{
if(samplesRead)
{
QTime time= QTime::currentTime();
for(int i= 0;i<samplesRead;i++)
{
for(int j= 0;j<channels;j++)
{
double measuredValue= buffer[j+(i*channels)];
Measurement measure(measuredValue,time,
unitMap[j]);
channelMap[j]->input(measure);
}
}
}
}
}

/*:327*//*328:*/
#line 7166 "./typica.w"

void DAQImplementation::run()
{
setPriority(QThread::TimeCriticalPriority);
while(ready)
{
measure();
}
}

/*:328*//*329:*/
#line 7182 "./typica.w"

void DAQ::threadFinished()
{
if(imp->error)
{
/*330:*/
#line 7233 "./typica.w"

imp->ready= false;
QMessageBox warning;
warning.setStandardButtons(QMessageBox::Cancel);
warning.setIcon(QMessageBox::Warning);
warning.setText(QString(tr("Error: %1")).arg(imp->error));
unsigned long bytes= imp->errorInfo(NULL,0);
char string[bytes];
imp->errorInfo(string,bytes);
warning.setInformativeText(QString(string));
warning.setWindowTitle(QString(PROGRAM_NAME));
warning.exec();

/*:330*/
#line 7187 "./typica.w"

}
}

/*:329*//*331:*/
#line 7258 "./typica.w"

void DAQ::start()
{
if(imp->ready)
{
imp->error= imp->startTask(imp->handle);
if(imp->error)
{
/*330:*/
#line 7233 "./typica.w"

imp->ready= false;
QMessageBox warning;
warning.setStandardButtons(QMessageBox::Cancel);
warning.setIcon(QMessageBox::Warning);
warning.setText(QString(tr("Error: %1")).arg(imp->error));
unsigned long bytes= imp->errorInfo(NULL,0);
char string[bytes];
imp->errorInfo(string,bytes);
warning.setInformativeText(QString(string));
warning.setWindowTitle(QString(PROGRAM_NAME));
warning.exec();

/*:330*/
#line 7266 "./typica.w"

}
else
{
connect(imp,SIGNAL(finished()),this,SLOT(threadFinished()));
imp->start();
}
}
}

void DAQ::stop()
{
if(imp->useBase)
{
imp->ready= false;
imp->wait(ULONG_MAX);
imp->stopTask(imp->handle);
}
else
{
imp->ready= false;
imp->error= imp->stopTask(imp->handle);
if(imp->error)
{
/*330:*/
#line 7233 "./typica.w"

imp->ready= false;
QMessageBox warning;
warning.setStandardButtons(QMessageBox::Cancel);
warning.setIcon(QMessageBox::Warning);
warning.setText(QString(tr("Error: %1")).arg(imp->error));
unsigned long bytes= imp->errorInfo(NULL,0);
char string[bytes];
imp->errorInfo(string,bytes);
warning.setInformativeText(QString(string));
warning.setWindowTitle(QString(PROGRAM_NAME));
warning.exec();

/*:330*/
#line 7290 "./typica.w"

}
imp->error= imp->clearTask(imp->handle);
if(imp->error)
{
/*330:*/
#line 7233 "./typica.w"

imp->ready= false;
QMessageBox warning;
warning.setStandardButtons(QMessageBox::Cancel);
warning.setIcon(QMessageBox::Warning);
warning.setText(QString(tr("Error: %1")).arg(imp->error));
unsigned long bytes= imp->errorInfo(NULL,0);
char string[bytes];
imp->errorInfo(string,bytes);
warning.setInformativeText(QString(string));
warning.setWindowTitle(QString(PROGRAM_NAME));
warning.exec();

/*:330*/
#line 7295 "./typica.w"

}
}
}

/*:331*//*332:*/
#line 7305 "./typica.w"

DAQ::DAQ(QString device,const QString&driver):imp(new DAQImplementation(driver))
{
imp->device= device;
imp->error= imp->createTask(device.toAscii().data(),&(imp->handle));
if(imp->error)
{
/*330:*/
#line 7233 "./typica.w"

imp->ready= false;
QMessageBox warning;
warning.setStandardButtons(QMessageBox::Cancel);
warning.setIcon(QMessageBox::Warning);
warning.setText(QString(tr("Error: %1")).arg(imp->error));
unsigned long bytes= imp->errorInfo(NULL,0);
char string[bytes];
imp->errorInfo(string,bytes);
warning.setInformativeText(QString(string));
warning.setWindowTitle(QString(PROGRAM_NAME));
warning.exec();

/*:330*/
#line 7312 "./typica.w"

}
else
{
imp->ready= true;
}
}

/*:332*//*333:*/
#line 7326 "./typica.w"

Channel*DAQ::newChannel(int units,int thermocouple)
{
Channel*retval= new Channel();
imp->channelMap[imp->channels]= retval;
imp->unitMap[imp->channels]= (Units::Unit)units;
imp->channels++;
if(imp->ready)
{
if(imp->useBase)
{
imp->error= imp->createChannel(imp->handle,
QString("%1/ai%2").arg(imp->device).
arg(imp->channels-1).
toAscii().data(),
"",(double)(-1.0),(double)(100.0),
(signed long)(units),
(signed long)(thermocouple),
(signed long)(10200),(double)(0),
"");
}
else
{
imp->error= imp->createChannel(imp->handle,
QString("%1/ai%2").arg(imp->device).
arg(imp->channels-1).
toAscii().data(),
"",(double)(50.0),(double)(500.0),
(signed long)(units),
(signed long)(thermocouple),
(signed long)(10200),(double)(0),
"");
}
if(imp->error)
{
/*330:*/
#line 7233 "./typica.w"

imp->ready= false;
QMessageBox warning;
warning.setStandardButtons(QMessageBox::Cancel);
warning.setIcon(QMessageBox::Warning);
warning.setText(QString(tr("Error: %1")).arg(imp->error));
unsigned long bytes= imp->errorInfo(NULL,0);
char string[bytes];
imp->errorInfo(string,bytes);
warning.setInformativeText(QString(string));
warning.setWindowTitle(QString(PROGRAM_NAME));
warning.exec();

/*:330*/
#line 7361 "./typica.w"

}
}
return retval;
}

/*:333*//*334:*/
#line 7375 "./typica.w"

void DAQ::setClockRate(double Hz)
{
if(imp->ready)
{
imp->error= imp->setClock(imp->handle,"OnboardClock",Hz,
(signed long)(10280),(signed long)(10123),
(unsigned long long)(1));
if(imp->error)
{
/*330:*/
#line 7233 "./typica.w"

imp->ready= false;
QMessageBox warning;
warning.setStandardButtons(QMessageBox::Cancel);
warning.setIcon(QMessageBox::Warning);
warning.setText(QString(tr("Error: %1")).arg(imp->error));
unsigned long bytes= imp->errorInfo(NULL,0);
char string[bytes];
imp->errorInfo(string,bytes);
warning.setInformativeText(QString(string));
warning.setWindowTitle(QString(PROGRAM_NAME));
warning.exec();

/*:330*/
#line 7385 "./typica.w"

}
}
}

/*:334*//*335:*/
#line 7395 "./typica.w"

DAQ::~DAQ()
{
if(imp->useBase)
{
imp->resetDevice(imp->device.toAscii().data());
imp->clearTask(imp->handle);
}
else
{
if(imp->ready)
{
imp->ready= false;
imp->wait(ULONG_MAX);
imp->stopTask(imp->handle);
imp->resetDevice(imp->device.toAscii().data());
imp->clearTask(imp->handle);
}
}
delete imp;
}

/*:335*//*336:*/
#line 7426 "./typica.w"

DAQImplementation::DAQImplementation(const QString&driverinfo)
:QThread(NULL),channelMap(4),handle(0),error(0),channels(0),ready(false),
unitMap(4)
{
if(driverinfo=="nidaqmxbase")
{
useBase= true;
}
else
{
useBase= false;
}
if(useBase)
{
driver.setFileName("nidaqmxbase.framework/nidaqmxbase");
if(!driver.load())
{
driver.setFileName("nidaqmxbase");
if(!driver.load())
{
QMessageBox::critical(NULL,tr("Typica: Driver not found"),
tr("Failed to find nidaqmxbase. Please install it."));
QApplication::quit();
}
}
}
else
{
driver.setFileName("nicaiu");
if(!driver.load())
{
QMessageBox::critical(NULL,tr("Typica: Driver not found"),
tr("Failed to find nidaqmx. Please install it."));
QApplication::quit();
}
}
if(useBase)
{
if((createTask= (daqfp)driver.resolve("DAQmxBaseCreateTask"))==0||
(startTask= (daqfp)driver.resolve("DAQmxBaseStartTask"))==0||
(stopTask= (daqfp)driver.resolve("DAQmxBaseStopTask"))==0||
(clearTask= (daqfp)driver.resolve("DAQmxBaseClearTask"))==0||
(createChannel= (daqfp)driver.resolve("DAQmxBaseCreateAIThrmcplChan"))
==0||
(setClock= (daqfp)driver.resolve("DAQmxBaseCfgSampClkTiming"))==
0||
(read= (daqfp)driver.resolve("DAQmxBaseReadAnalogF64"))==0||
(errorInfo= (daqfp)driver.resolve("DAQmxBaseGetExtendedErrorInfo"))==
0||
(resetDevice= (daqfp)driver.resolve("DAQmxBaseResetDevice"))==0)
{
waitForMeasurement= NULL;
QMessageBox::critical(NULL,tr("Typica: Link error"),
tr("Failed to link a required symbol in NI-DAQmxBase."));
QApplication::quit();
}
}
else
{
if((createTask= (daqfp)driver.resolve("DAQmxCreateTask"))==0||
(startTask= (daqfp)driver.resolve("DAQmxStartTask"))==0||
(stopTask= (daqfp)driver.resolve("DAQmxStopTask"))==0||
(clearTask= (daqfp)driver.resolve("DAQmxClearTask"))==0||
(createChannel= (daqfp)driver.resolve("DAQmxCreateAIThrmcplChan"))
==0||
(setClock= (daqfp)driver.resolve("DAQmxCfgSampClkTiming"))==0||
(read= (daqfp)driver.resolve("DAQmxReadAnalogF64"))==0||
(errorInfo= (daqfp)driver.resolve("DAQmxGetExtendedErrorInfo"))==
0||
(resetDevice= (daqfp)driver.resolve("DAQmxResetDevice"))==0||
(waitForMeasurement= (daqfp)driver.resolve("DAQmxWaitUntilTaskDone"))==0)
{
QMessageBox::critical(NULL,tr("Typica: Link error"),
tr("Failed to link a required symbol in NI-DAQmx."));
QApplication::quit();
}
}
}

DAQImplementation::~DAQImplementation()
{
driver.unload();
}

/*:336*/
#line 543 "./typica.w"

/*1070:*/
#line 197 "./dataqsdk.w"

void DataqSdkDeviceImplementation::measure()
{
unsigned count= channels*40;
di_status_read(buffer,count);
QTime time= QTime::currentTime();
for(unsigned int i= 0;i<count;i++)
{
buffer[i]= buffer[i]&0xFFFC;
}
QList<int> countList;
for(unsigned int i= 0;i<(unsigned)channels;i++)
{
QList<double> channelBuffer;
for(unsigned int j= 0;j<40;j++)
{
channelBuffer<<((double)buffer[i+(channels*j)]*10.0)/32768.0;
if(i==0)
{
countList<<buffer[i+(channels*j)];
}
}
double value= 0.0;
for(unsigned int j= 0;j<40;j++)
{
value+= channelBuffer[j];
}
value/= 40.0;
if(i==0)
{
QList<double> smoothingList;
smoothingList<<value;
QList<int> smoothingKeys= smoother.uniqueKeys();
for(int j= 0;j<smoothingKeys.size();j++)
{
if(countList.contains(smoothingKeys[j]))
{
QList<double> keyValues= smoother.values(smoothingKeys[j]);
for(int k= 0;k<keyValues.size();k++)
{
smoothingList<<keyValues[k];
}
}
else
{
smoother.remove(smoothingKeys[j]);
}
}
qSort(countList);
int lastCount= 0;
for(int j= 0;j<countList.size();j++)
{
if(j==0||countList[j]!=lastCount)
{
smoother.insert(countList[j],value);
lastCount= countList[j];
}
}
value= 0.0;
for(int j= 0;j<smoothingList.size();j++)
{
value+= smoothingList[j];
}
value/= smoothingList.size();
}
Measurement measure(value,time,unitMap[i]);
channelMap[i]->input(measure);
}
}

/*:1070*//*1071:*/
#line 290 "./dataqsdk.w"

void DataqSdkDeviceImplementation::run()
{
if(!ready)
{
error= 9;
return;
}
driver= new QLibrary(device);
if(!driver->load())
{
error= 1;
qDebug()<<"Failed to load driver: "<<device;
return;
}
di_open= (FPDIOPEN)driver->resolve("di_open");
di_close= (FPDICLOSE)driver->resolve("di_close");
di_sample_rate= (FPDISAMPLERATE)driver->resolve("di_sample_rate");
di_maximum_rate= (FPDIMAXIMUMRATE)driver->resolve("di_maximum_rate");
di_list_length= (FPDILISTLENGTH)driver->resolve("di_list_length");
di_inlist= (FPDIINLIST)driver->resolve("di_inlist");
di_buffer_alloc= (FPDIBUFFERALLOC)driver->resolve("di_buffer_alloc");
di_start_scan= (FPDISTARTSCAN)driver->resolve("di_start_scan");
di_status_read= (FPDISTATUSREAD)driver->resolve("di_status_read");
di_buffer_status= (FPDIBUFFERSTATUS)driver->resolve("di_buffer_status");
di_burst_rate= (FPDIBURSTRATE)driver->resolve("di_burst_rate");
di_stop_scan= (FPDISTOPSCAN)driver->resolve("di_stop_scan");
if((!di_open)||(!di_close)||(!di_sample_rate)||(!di_maximum_rate)||
(!di_list_length)||(!di_inlist)||(!di_buffer_alloc)||
(!di_start_scan)||(!di_status_read)||(!di_buffer_status)||
(!di_burst_rate)||(!di_stop_scan))
{
error= 2;
return;
}
error= di_open(deviceNumber);
if(error)
{
di_close();
error= di_open(deviceNumber);
if(error)
{
error= 3;
di_close();
return;
}
}
isOpen= true;
di_maximum_rate(240.0);
sampleRate= di_sample_rate(sampleRate*channels*40,&oversample,
&burstDivisor);
buffer= new qint16[(int)sampleRate];
di_inlist_struct inlist[16]= {{0,0,0,0,0,0,0,0}};
for(unsigned short i= 0;i<channels;i++)
{
inlist[i].chan= i;
inlist[i].gain= 0;
inlist[i].ave= 1;
inlist[i].counter= (oversample-1);
}
error= di_list_length(channels,0);
if(error)
{
error= 4;
return;
}
error= di_inlist(inlist);
if(error)
{
error= 5;
return;
}
input_buffer= di_buffer_alloc(0,4096);
if(input_buffer==NULL)
{
error= 6;
return;
}
error= di_start_scan();
if(error)
{
error= 7;
return;
}
while(ready)
{
measure();
}
}

/*:1071*//*1072:*/
#line 386 "./dataqsdk.w"

void DataqSdkDevice::threadFinished()
{
if(imp->error)
{
/*1073:*/
#line 400 "./dataqsdk.w"

imp->ready= false;
QMessageBox warning;
warning.setStandardButtons(QMessageBox::Cancel);
warning.setIcon(QMessageBox::Warning);
warning.setText(QString(tr("Error: %1")).arg(imp->error));
warning.setInformativeText(tr("An error occurred"));
warning.setWindowTitle(QString(PROGRAM_NAME));
warning.exec();

/*:1073*/
#line 391 "./dataqsdk.w"

}
}

/*:1072*//*1074:*/
#line 417 "./dataqsdk.w"

void DataqSdkDevice::start()
{
connect(imp,SIGNAL(finished()),this,SLOT(threadFinished()));
imp->start();
}

/*:1074*//*1075:*/
#line 428 "./dataqsdk.w"

QStringList DataqSdkDevice::detectHardware()
{
QSettings deviceLookup("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\services\\usbser\\Enum",
QSettings::NativeFormat);
QStringList keys= deviceLookup.childKeys();
QStringList devices;
for(int i= 0;i<keys.size();i++)
{
QString value= deviceLookup.value(keys.at(i)).toString();
if(value.startsWith("USB\\VID_0683&PID_1450\\"))
{
devices.append(value.split("\\").at(2));
}
}
QStringList portList;
foreach(QString device,devices)
{
QString deviceKey= QString("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Enum\\USB\\VID_0683&PID_1450\\%1").arg(device);
QSettings deviceEntry(deviceKey,QSettings::NativeFormat);
portList.append(deviceEntry.value("FriendlyName").toString());
}
return portList;
}

QStringList DataqSdkDevice::detectPorts()
{
QStringList friendlyNames= detectHardware();
QStringList portList;
foreach(QString name,friendlyNames)
{
name.remove(0,name.indexOf("COM"));
name.chop(1);
portList.append(name);
}
return portList;
}

/*:1075*//*1076:*/
#line 473 "./dataqsdk.w"

DataqSdkDevice::DataqSdkDevice(QString device):imp(new DataqSdkDeviceImplementation)
{
bool usesAuto= false;
int autoIndex= device.toInt(&usesAuto);
QString finalizedPort;
if(usesAuto)
{
QStringList portList= detectPorts();
if(autoIndex> 0&&autoIndex<=portList.size())
{
finalizedPort= portList.at(autoIndex-1);
}
else
{
imp->error= 8;
qDebug()<<"Failed to detect port.";
}
}
else
{
finalizedPort= device;
}
int rstart= finalizedPort.indexOf("COM");
finalizedPort.remove(0,rstart+3);
bool chopFinished= false;
int finalizedPortNumber= 0;
while(finalizedPort.size()> 0&&!chopFinished)
{
finalizedPortNumber= finalizedPort.toInt(&chopFinished);
if(!chopFinished)
{
finalizedPort.chop(1);
}
}
if(finalizedPortNumber<10)
{
imp->device= QString("DI10%1NT.DLL").arg(finalizedPort);
}
else
{
imp->device= QString("DI1%1NT.DLL").arg(finalizedPort);
}
imp->deviceNumber= 0x12C02D00;
imp->deviceNumber+= finalizedPortNumber;
imp->ready= true;
}

/*:1076*//*1077:*/
#line 523 "./dataqsdk.w"

Channel*DataqSdkDevice::newChannel(Units::Unit scale)
{
Channel*retval= NULL;
if(imp->ready)
{
retval= new Channel();
imp->channelMap[imp->channels]= retval;
imp->unitMap[imp->channels]= scale;
imp->channels++;
}
return retval;
}

/*:1077*//*1078:*/
#line 547 "./dataqsdk.w"

void DataqSdkDevice::setClockRate(double Hz)
{
imp->sampleRate= Hz;
}

/*:1078*//*1079:*/
#line 557 "./dataqsdk.w"

DataqSdkDevice::~DataqSdkDevice()
{
if(imp->ready)
{
imp->ready= false;
}
imp->wait(ULONG_MAX);
delete imp;
}

/*:1079*//*1080:*/
#line 575 "./dataqsdk.w"

DataqSdkDeviceImplementation::DataqSdkDeviceImplementation():QThread(NULL),
channelMap(4),error(0),channels(0),ready(false),unitMap(4)
{

}

DataqSdkDeviceImplementation::~DataqSdkDeviceImplementation()
{
if(isOpen)
{
di_stop_scan();
di_close();
}
if(driver->isLoaded())
{
driver->unload();
}
}

/*:1080*/
#line 544 "./typica.w"

/*343:*/
#line 7635 "./typica.w"

void FakeDAQImplementation::measure()
{
msleep((int)(1000/clockRate));
QTime time= QTime::currentTime();
for(int i= 0;i<channels;i++)
{
Measurement measure(qrand()%500,time);
channelMap[i]->input(measure);
}
}

/*:343*//*344:*/
#line 7649 "./typica.w"

void FakeDAQImplementation::run()
{
setPriority(QThread::TimeCriticalPriority);
while(ready)
{
measure();
}
}

FakeDAQImplementation::FakeDAQImplementation():QThread(NULL),channelMap(4),
channels(0),ready(false),clockRate(1)
{

}

FakeDAQImplementation::~FakeDAQImplementation()
{

}

/*:344*//*345:*/
#line 7674 "./typica.w"

void FakeDAQ::start()
{
if(imp->ready)
{
imp->start();
}
}

FakeDAQ::FakeDAQ(QString):imp(new FakeDAQImplementation())
{
imp->ready= true;
}

Channel*FakeDAQ::newChannel(int,int)
{
Channel*retval;
if(imp->ready)
{
retval= new Channel();
imp->channelMap[imp->channels]= retval;
imp->channels++;
}
else
{
return NULL;
}
return retval;
}

void FakeDAQ::setClockRate(double Hz)
{
if(imp->ready)
{
imp->clockRate= Hz;
}
}

FakeDAQ::~FakeDAQ()
{
imp->ready= false;
imp->wait(ULONG_MAX);
delete imp;
}

/*:345*/
#line 545 "./typica.w"

/*350:*/
#line 7805 "./typica.w"

Channel::Channel():QObject(NULL)
{

}

Channel::~Channel()
{

}

void Channel::input(Measurement measurement)
{
emit newData(measurement);
}

/*:350*/
#line 546 "./typica.w"

/*366:*/
#line 8210 "./typica.w"

void TemperatureDisplay::setRelativeMode(bool relative)
{
r= relative;
}

/*:366*//*367:*/
#line 8227 "./typica.w"

void TemperatureDisplay::setValue(Measurement temperature)
{
QString number;
switch(unit)
{
case Units::Fahrenheit:
display(QString("%1'F").
arg(number.setNum(temperature.toFahrenheit().temperature(),'f',
2)));
break;
case Units::Celsius:
if(!r){
display(QString("%1'C").
arg(number.setNum(temperature.toCelsius().temperature(),'f',
2)));
}else{
number.setNum(temperature.temperature()*(5.0/9.0),'f',2);
display(QString("%1'C").arg(number));
}
break;
case Units::Kelvin:
if(!r){
display(QString("%1").
arg(number.setNum(temperature.toKelvin().temperature(),'f',
2)));
}else{
number.setNum(temperature.temperature()*(5.0/9.0),'f',2);
display(QString("%1").arg(number));
}
break;
case Units::Rankine:
display(QString("%1'r").
arg(number.setNum(temperature.toRankine().temperature(),'f',
2)));
break;
case Units::Unitless:
display(QString("%1").arg(number.setNum(temperature.temperature(),'f',0)));
break;
default:
switch(temperature.scale())
{
case Units::Fahrenheit:
display(QString("%1'F").
arg(number.setNum(temperature.temperature(),'f',2)));
break;
case Units::Celsius:
display(QString("%1'C").
arg(number.setNum(temperature.temperature(),'f',2)));
break;
case Units::Kelvin:
display(QString("%1").
arg(number.setNum(temperature.temperature(),'f',2)));
break;
case Units::Rankine:
display(QString("%1'r").
arg(number.setNum(temperature.temperature(),'f',2)));
break;
case Units::Unitless:
display(QString("%1").arg(number.setNum(temperature.temperature(),'f',0)));
break;
default:
qDebug()<<"Warning: Attempting to convert a non-temperature unit to a temperature unit";
break;
}
break;
}
}

/*:367*//*368:*/
#line 8306 "./typica.w"

TemperatureDisplay::TemperatureDisplay(QWidget*parent):
QLCDNumber(8,parent),unit(Units::Fahrenheit),r(false)
{
setSegmentStyle(Filled);
display("---.--'F");
}

/*:368*//*369:*/
#line 8322 "./typica.w"

void TemperatureDisplay::invalidate()
{
display("---.--'F");
}

/*:369*//*370:*/
#line 8334 "./typica.w"

void TemperatureDisplay::setDisplayUnits(Units::Unit scale)
{
unit= scale;
}

/*:370*//*371:*/
#line 8342 "./typica.w"

TemperatureDisplay::~TemperatureDisplay()
{

}

/*:371*/
#line 547 "./typica.w"

/*377:*/
#line 8442 "./typica.w"

void MeasurementTimeOffset::newMeasurement(Measurement measure)
{
if(measure.time()<epoch)
{
if(hasPrevious)
{
QTime jitBase(epoch.hour()-1,epoch.minute(),epoch.second(),
epoch.msec());
QTime jitComp(epoch.hour(),measure.time().minute(),
measure.time().second(),measure.time().msec());
int relTime= jitBase.msecsTo(jitComp);
/*378:*/
#line 8476 "./typica.w"

QTime newTime(0,0,0,0);
newTime= newTime.addMSecs(relTime);
if(newTime.hour()> 0)
{
newTime.setHMS(0,newTime.minute(),newTime.second(),newTime.msec());
}
Measurement rel= measure;
rel.setTime(newTime);
emit measurement(rel);

/*:378*/
#line 8454 "./typica.w"

}
else
{
Measurement rel= measure;
rel.setTime(QTime(0,0,0,0));
emit measurement(rel);
}
}
else
{
int relTime= epoch.msecsTo(measure.time());
/*378:*/
#line 8476 "./typica.w"

QTime newTime(0,0,0,0);
newTime= newTime.addMSecs(relTime);
if(newTime.hour()> 0)
{
newTime.setHMS(0,newTime.minute(),newTime.second(),newTime.msec());
}
Measurement rel= measure;
rel.setTime(newTime);
emit measurement(rel);

/*:378*/
#line 8466 "./typica.w"

}
hasPrevious= true;
previous= measure.time();
}

/*:377*//*379:*/
#line 8489 "./typica.w"

MeasurementTimeOffset::MeasurementTimeOffset(QTime zero):epoch(zero),
previous(0,0,0,0),hasPrevious(false)
{

}

QTime MeasurementTimeOffset::zeroTime()
{
return epoch;
}

void MeasurementTimeOffset::setZeroTime(QTime zero)
{
epoch= zero;
hasPrevious= false;
}

/*:379*/
#line 548 "./typica.w"

/*389:*/
#line 8697 "./typica.w"

ZeroEmitter::ZeroEmitter(int tempcolumn):QObject(NULL),col(tempcolumn)
{

}

int ZeroEmitter::column()
{
return col;
}

double ZeroEmitter::lastTemperature()
{
return cache.temperature();
}

void ZeroEmitter::newMeasurement(Measurement measure)
{
cache= measure;
}

void ZeroEmitter::setColumn(int column)
{
col= column;
}

void ZeroEmitter::emitZero()
{
cache.setTime(QTime(0,0,0,0));
emit measurement(cache,col);
}

/*:389*/
#line 549 "./typica.w"

/*394:*/
#line 8787 "./typica.w"

MeasurementAdapter::MeasurementAdapter(int tempcolumn):col(tempcolumn)
{

}

int MeasurementAdapter::column()
{
return col;
}

void MeasurementAdapter::newMeasurement(Measurement measure)
{
emit measurement(measure,col);
}

void MeasurementAdapter::setColumn(int column)
{
col= column;
}

/*:394*/
#line 550 "./typica.w"

/*399:*/
#line 8909 "./typica.w"

GraphView::GraphView(QWidget*parent):QGraphicsView(parent),
theScene(new QGraphicsScene),
graphLines(new QMap<int,QList<QGraphicsLineItem*> *> ),
prevPoints(new QMap<int,QPointF> ),
translations(new QMap<int,double> ),
gridLinesF(new QList<QGraphicsItem*> ),
gridLinesC(new QList<QGraphicsItem*> ),
relativeGridLines(new QList<QGraphicsItem*> ),
relativeEnabled(false),
timeIndicatorEnabled(false),
timeLine(new QGraphicsLineItem),
relativeAdjuster(new LinearSplineInterpolator)
{
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setScene(theScene);
setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
QPen timePen;
timePen.setColor(QColor(160,160,164,127));
timeLine->setPen(timePen);
timeLine->setLine(0,0,0,-500);
timeLine->hide();
theScene->addItem(timeLine);
/*400:*/
#line 8949 "./typica.w"

QGraphicsLineItem*tempaxis= new QGraphicsLineItem;
tempaxis->setLine(-10,-500,-10,0);
theScene->addItem(tempaxis);
QGraphicsLineItem*gridLine;
QGraphicsTextItem*label;
for(int y= -100;y> -600;y-= 100)
{
gridLine= new QGraphicsLineItem;
gridLine->setLine(0,y,1200,y);
theScene->addItem(gridLine);
label= new QGraphicsTextItem;
label->setHtml(QString("%1&deg;F").arg(-y));
label->setPos(-55,y-(label->boundingRect().height()/2));
theScene->addItem(label);
gridLinesF->append(gridLine);
gridLinesF->append(label);
}
for(int degC= 50;degC<=250;degC+= 50)
{
gridLine= new QGraphicsLineItem;
int y= -(degC*(9.0/5.0)+32);
gridLine->setLine(0,y,1200,y);
gridLine->hide();
theScene->addItem(gridLine);
gridLinesC->append(gridLine);
label= new QGraphicsTextItem;
label->setHtml(QString("%1&deg;C").arg(degC));
label->setPos(-55,y-(label->boundingRect().height()/2));
label->hide();
theScene->addItem(label);
gridLinesC->append(label);
}

/*:400*/
#line 8933 "./typica.w"
;
/*401:*/
#line 8990 "./typica.w"

QSettings settings;
if(settings.contains("settings/graph/relative/enable"))
{
if(settings.value("settings/graph/relative/enable").toBool())
{
relativeEnabled= true;
QColor relativeColor= QColor(settings.value("settings/graph/relative/color").toString());
QString unit= QString(settings.value("settings/graph/relative/unit").toInt()==0?"F":"C");
QMap<double,QString> relativeAxisPairs;
QStringList relativeAxisLabels= settings.value("settings/graph/relative/grid").toString().split(QRegExp("[\\s,]+"),QString::SkipEmptyParts);
foreach(QString item,relativeAxisLabels)
{
relativeAxisPairs.insert(item.toDouble(),item);
}
if(relativeAxisPairs.size()> 1)
{
double skip= 500.0/(relativeAxisPairs.size()-1);
double y= 0;
foreach(double key,relativeAxisPairs.keys())
{
gridLine= new QGraphicsLineItem;
gridLine->setLine(0,y,1205,y);
gridLine->setPen(QPen(relativeColor));
theScene->addItem(gridLine);
relativeGridLines->append(gridLine);
label= new QGraphicsTextItem;
label->setHtml(QString("%1&deg;%2").arg(relativeAxisPairs.value(key)).arg(unit));
label->setPos(1210,y-(label->boundingRect().height()/2));
theScene->addItem(label);
relativeGridLines->append(label);
if(unit=="F")
{
relativeAdjuster->add_pair(key,-y);
}
else
{
relativeAdjuster->add_pair(key*(9.0/5.0),-y);
}
y-= skip;
}
}
}
}

/*:401*/
#line 8934 "./typica.w"

/*403:*/
#line 9067 "./typica.w"

QGraphicsLineItem*timeaxis= new QGraphicsLineItem;
timeaxis->setLine(0,10,1200,10);
theScene->addItem(timeaxis);
for(int x= 0;x<1201;x+= 120)
{
QGraphicsLineItem*tick= new QGraphicsLineItem;
tick->setLine(x,0,x,20);
theScene->addItem(tick);
QGraphicsTextItem*label= new QGraphicsTextItem;
label->setPlainText(QString("%1").arg(x/60));
label->setPos(x-(label->boundingRect().width()/2),20);
theScene->addItem(label);
}

/*:403*/
#line 8935 "./typica.w"
;
fitInView(theScene->sceneRect().adjusted(-50,-50,50,50));
}

/*:399*//*402:*/
#line 9037 "./typica.w"

void GraphView::showF()
{
for(int i= 0;i<gridLinesF->size();i++)
{
gridLinesF->at(i)->show();
}
for(int i= 0;i<gridLinesC->size();i++)
{
gridLinesC->at(i)->hide();
}
}

void GraphView::showC()
{
for(int i= 0;i<gridLinesF->size();i++)
{
gridLinesF->at(i)->hide();
}
for(int i= 0;i<gridLinesC->size();i++)
{
gridLinesC->at(i)->show();
}
}

/*:402*//*404:*/
#line 9086 "./typica.w"

void GraphView::resizeEvent(QResizeEvent*)
{
fitInView(theScene->sceneRect().adjusted(-50,-50,50,50));
}

/*:404*//*405:*/
#line 9100 "./typica.w"

#define FULLTIMETOINT(t) (t.msec() + (t.second() * 1000) +  (t.minute() * 60 * 1000))

void GraphView::newMeasurement(Measurement measure,int tempcolumn)
{
double offset= 0;
if(measure.contains("relative"))
{
if(measure.value("relative").toBool())
{
if(relativeEnabled)
{
measure.setTemperature(relativeAdjuster->newMeasurement(measure).temperature());
}
else
{
return;
}
}
}
if(translations->contains(tempcolumn))
{
offset= translations->value(tempcolumn);
}
if(prevPoints->contains(tempcolumn))
{
/*407:*/
#line 9177 "./typica.w"

QGraphicsLineItem*segment= new QGraphicsLineItem;
QPointF nextPoint(FULLTIMETOINT(measure.time())/1000,measure.temperature());
segment->setLine(prevPoints->value(tempcolumn).x()+offset,
-(prevPoints->value(tempcolumn).y()),
nextPoint.x()+offset,-(nextPoint.y()));
static QColor p[12]= {Qt::yellow,Qt::blue,Qt::cyan,Qt::red,Qt::magenta,
Qt::green,Qt::darkGreen,Qt::darkMagenta,
Qt::darkRed,Qt::darkCyan,Qt::darkBlue,
Qt::darkYellow};
segment->setPen(p[tempcolumn%12]);
theScene->addItem(segment);
prevPoints->insert(tempcolumn,nextPoint);
if(timeIndicatorEnabled)
{
timeLine->setLine(nextPoint.x()+offset,0,nextPoint.x()+offset,-500);
}

/*:407*/
#line 9126 "./typica.w"

if(graphLines->contains(tempcolumn))
{

graphLines->value(tempcolumn)->append(segment);
}
else
{

QList<QGraphicsLineItem*> *newLine= 
new QList<QGraphicsLineItem*> ;
newLine->append(segment);
graphLines->insert(tempcolumn,newLine);
}
}
else
{
/*406:*/
#line 9162 "./typica.w"

int x= FULLTIMETOINT(measure.time())/1000;
prevPoints->insert(tempcolumn,QPointF(x,measure.temperature()));
if(timeIndicatorEnabled)
{
timeLine->setLine(x,0,x,-500);
}

/*:406*/
#line 9143 "./typica.w"

}
}

/*:405*//*408:*/
#line 9198 "./typica.w"

void GraphView::clear()
{
int i;
foreach(i,prevPoints->keys())
{
removeSeries(i);
}
translations->clear();
}

/*:408*//*409:*/
#line 9212 "./typica.w"

void GraphView::removeSeries(int column)
{
if(graphLines->contains(column))
{
QList<QGraphicsLineItem*> *series= graphLines->value(column);
QGraphicsLineItem*segment;
foreach(segment,*series)
{
theScene->removeItem(segment);
}
qDeleteAll(*series);
}
graphLines->remove(column);
prevPoints->remove(column);
}

/*:409*//*410:*/
#line 9231 "./typica.w"

void GraphView::setSeriesTranslation(int column,double offset)
{
if(graphLines->contains(column))
{
QList<QGraphicsLineItem*> *series= graphLines->value(column);
QGraphicsLineItem*segment;
foreach(segment,*series)
{
segment->setPos(segment->pos().x()+offset,segment->pos().y());
}
}
if(translations->contains(column))
{
translations->insert(column,offset+translations->value(column));
}
else
{
translations->insert(column,offset);
}
}

/*:410*//*411:*/
#line 9258 "./typica.w"

void GraphView::setTimeIndicatorEnabled(bool enabled)
{
timeIndicatorEnabled= enabled;
if(enabled)
{
timeLine->show();
}
else
{
timeLine->hide();
}
}

/*:411*/
#line 551 "./typica.w"

/*417:*/
#line 9405 "./typica.w"

void ZoomLog::newMeasurement(Measurement measure,int tempcolumn)
{
if(measure.time()!=QTime(0,0,0,0))
{
/*419:*/
#line 9479 "./typica.w"

if(lastMeasurement.contains(tempcolumn))
{
if(lastMeasurement[tempcolumn].time()<measure.time())
{
QList<QTime> timelist;
QList<double> templist;
QTime z= QTime(0,0,0,0);
double ptime= (double)(z.secsTo(lastMeasurement[tempcolumn].time()));
double ptemp= lastMeasurement[tempcolumn].temperature();
double ctime= (double)(z.secsTo(measure.time()));
double ctemp= measure.temperature();
for(QTime i= lastMeasurement.value(tempcolumn).time().addSecs(1);i<measure.time();i= i.addSecs(1))
{
timelist.append(i);
double v= ((ptemp*(ctime-z.secsTo(i)))+(ctemp*(z.secsTo(i)-ptime)))/(ctime-ptime);
templist.append(v);
}
for(int i= 0;i<timelist.size();i++)
{
Measurement synthesized= measure;
synthesized.setTime(timelist[i]);
synthesized.setTemperature(templist[i]);
newMeasurement(synthesized,tempcolumn);
}
}
}

/*:419*/
#line 9410 "./typica.w"

}
model_ms->newMeasurement(measure,tempcolumn);
if(lastMeasurement.contains(tempcolumn))
{
if(measure.time().second()!=
lastMeasurement.value(tempcolumn).time().second())
{
Measurement adjusted= measure;
QTime adjtime(0,measure.time().minute(),measure.time().second(),0);
adjusted.setTime(adjtime);
model_1s->newMeasurement(adjusted,tempcolumn);
if(adjusted.time().second()%5==0)
{
model_5s->newMeasurement(adjusted,tempcolumn);
if(adjusted.time().second()%10==0)
{
model_10s->newMeasurement(adjusted,tempcolumn);
}
if(adjusted.time().second()%15==0)
{
model_15s->newMeasurement(adjusted,tempcolumn);
if(adjusted.time().second()%30==0)
{
model_30s->newMeasurement(adjusted,tempcolumn);
if(adjusted.time().second()==0)
{
model_1m->newMeasurement(adjusted,tempcolumn);
}
}
}
}
}
/*421:*/
#line 9532 "./typica.w"

if(currentColumnSet.contains(tempcolumn))
{
int replicationcolumn;
foreach(replicationcolumn,currentColumnSet)
{
if(replicationcolumn!=tempcolumn)
{
if(lastMeasurement.contains(replicationcolumn))
{
if(measure.time()> lastMeasurement.value(replicationcolumn).time())
{
Measurement synthetic= lastMeasurement.value(replicationcolumn);
synthetic.setTime(measure.time());
model_ms->newMeasurement(synthetic,replicationcolumn);
if(synthetic.time().second()!=lastMeasurement.value(replicationcolumn).time().second())
{
Measurement adjusted= synthetic;
adjusted.setTime(QTime(0,synthetic.time().minute(),synthetic.time().second(),0));
model_1s->newMeasurement(adjusted,replicationcolumn);
if(adjusted.time().second()%5==0)
{
model_5s->newMeasurement(adjusted,replicationcolumn);
if(adjusted.time().second()%10==0)
{
model_10s->newMeasurement(adjusted,replicationcolumn);
}
if(adjusted.time().second()%15==0)
{
model_15s->newMeasurement(adjusted,replicationcolumn);
if(adjusted.time().second()%30==0)
{
model_30s->newMeasurement(adjusted,replicationcolumn);
if(adjusted.time().second()==0)
{
model_1m->newMeasurement(adjusted,replicationcolumn);
}
}
}
}
}
lastMeasurement[replicationcolumn]= synthetic;
}
}
}
}
}

/*:421*/
#line 9443 "./typica.w"

}
else
{
/*418:*/
#line 9455 "./typica.w"

MeasurementModel*m;
foreach(m,modelSet)
{
m->newMeasurement(measure,tempcolumn);
}

/*:418*/
#line 9447 "./typica.w"

}
lastMeasurement.insert(tempcolumn,measure);
}

/*:417*//*420:*/
#line 9518 "./typica.w"

void ZoomLog::addToCurrentColumnSet(int column)
{
currentColumnSet.append(column);
}

void ZoomLog::clearCurrentColumnSet()
{
currentColumnSet.clear();
}

/*:420*//*422:*/
#line 9602 "./typica.w"

void ZoomLog::newAnnotation(QString annotation,int tempcolumn,
int annotationcolumn)
{
model_ms->newAnnotation(annotation,tempcolumn,annotationcolumn);
MeasurementModel*m;
if(lastMeasurement.contains(tempcolumn))
{
foreach(m,modelSet)
{
m->newMeasurement(lastMeasurement.value(tempcolumn),tempcolumn);
}
}
foreach(m,modelSet)
{
m->newAnnotation(annotation,tempcolumn,annotationcolumn);
}
}

/*:422*//*423:*/
#line 9626 "./typica.w"

void ZoomLog::centerOn(int row)
{
scrollTo(currentModel->index(row,0),QAbstractItemView::PositionAtCenter);
}

/*:423*//*424:*/
#line 9636 "./typica.w"

void ZoomLog::clear()
{
MeasurementModel*m;
foreach(m,modelSet)
{
m->clear();
}
lastMeasurement.clear();
saveTempCols.clear();
saveControlCols.clear();
saveNoteCols.clear();
}

/*:424*//*425:*/
#line 9654 "./typica.w"

QVariant ZoomLog::data(int row,int column)const
{
return model_ms->data(model_ms->index(row,column,QModelIndex()),
Qt::DisplayRole);
}

int ZoomLog::rowCount()
{
return model_ms->rowCount();
}

/*:425*//*426:*/
#line 9677 "./typica.w"

bool ZoomLog::saveXML(QIODevice*device)
{
Units::Unit prevUnits= model_ms->displayUnits();
if(prevUnits!=Units::Fahrenheit)
{
model_ms->setDisplayUnits(Units::Fahrenheit);
}
XMLOutput writer(model_ms,device,0);
int c;
foreach(c,saveTempCols)
{
writer.addTemperatureColumn(model_ms->headerData(c,Qt::Horizontal).
toString(),c);
}
foreach(c,saveControlCols)
{
writer.addControlColumn(model_ms->headerData(c,Qt::Horizontal).
toString(),c);
}
foreach(c,saveNoteCols)
{
writer.addAnnotationColumn(model_ms->headerData(c,Qt::Horizontal).
toString(),c);
}
bool retval= writer.output();
if(prevUnits!=Units::Fahrenheit)
{
model_ms->setDisplayUnits(prevUnits);
}
return retval;
}

/*:426*//*427:*/
#line 9713 "./typica.w"

bool ZoomLog::saveCSV(QIODevice*device)
{
CSVOutput writer(currentModel,device,0);
int c;
foreach(c,saveTempCols)
{
writer.addTemperatureColumn(model_ms->headerData(c,Qt::Horizontal).
toString(),c);
}
foreach(c,saveControlCols)
{
writer.addControlColumn(model_ms->headerData(c,Qt::Horizontal).
toString(),c);
}
foreach(c,saveNoteCols)
{
writer.addAnnotationColumn(model_ms->headerData(c,Qt::Horizontal).
toString(),c);
}
return writer.output();
}

/*:427*//*428:*/
#line 9742 "./typica.w"

void ZoomLog::switchLOD(MeasurementModel*m)
{
disconnect(currentModel,SIGNAL(rowChanged(int)),this,0);
setModel(m);
currentModel= m;
connect(currentModel,SIGNAL(rowChanged(int)),this,SLOT(centerOn(int)));
}

void ZoomLog::LOD_ms()
{
switchLOD(model_ms);
}

void ZoomLog::LOD_1s()
{
switchLOD(model_1s);
}

void ZoomLog::LOD_5s()
{
switchLOD(model_5s);
}

void ZoomLog::LOD_10s()
{
switchLOD(model_10s);
}

void ZoomLog::LOD_15s()
{
switchLOD(model_15s);
}

void ZoomLog::LOD_30s()
{
switchLOD(model_30s);
}

void ZoomLog::LOD_1m()
{
switchLOD(model_1m);
}

/*:428*//*429:*/
#line 9790 "./typica.w"

void ZoomLog::setDisplayUnits(Units::Unit scale)
{
model_ms->setDisplayUnits(scale);
model_1s->setDisplayUnits(scale);
model_5s->setDisplayUnits(scale);
model_10s->setDisplayUnits(scale);
model_15s->setDisplayUnits(scale);
model_30s->setDisplayUnits(scale);
model_1m->setDisplayUnits(scale);
}

Units::Unit ZoomLog::displayUnits()
{
return model_ms->displayUnits();
}

/*:429*//*430:*/
#line 9810 "./typica.w"

QString ZoomLog::lastTime(int series)
{
Measurement measure= lastMeasurement.value(series);
QTime time= measure.time();
return time.toString("h:mm:ss.zzz");
}

/*:430*//*431:*/
#line 9820 "./typica.w"

ZoomLog::ZoomLog():QTableView(NULL),model_ms(new MeasurementModel(this)),
model_1s(new MeasurementModel(this)),model_5s(new MeasurementModel(this)),
model_10s(new MeasurementModel(this)),model_15s(new MeasurementModel(this)),
model_30s(new MeasurementModel(this)),model_1m(new MeasurementModel(this))
{
setEditTriggers(QAbstractItemView::NoEditTriggers);
setSelectionMode(QAbstractItemView::NoSelection);
modelSet<<model_ms<<model_1s<<model_5s<<model_10s<<model_15s<<
model_30s<<model_1m;
currentModel= model_30s;
setModel(currentModel);
connect(currentModel,SIGNAL(rowChanged(int)),this,SLOT(centerOn(int)));
connect(horizontalHeader(),SIGNAL(sectionResized(int,int,int)),
this,SLOT(persistColumnResize(int,int,int)));
connect(horizontalHeader(),SIGNAL(sectionCountChanged(int,int)),
this,SLOT(restoreColumnWidths()));
}

/*:431*//*432:*/
#line 9843 "./typica.w"

void ZoomLog::setHeaderData(int section,QString text)
{
MeasurementModel*m;
foreach(m,modelSet)
{
m->setHeaderData(section,Qt::Horizontal,QVariant(text));
}
}

/*:432*//*433:*/
#line 9861 "./typica.w"

void ZoomLog::addOutputTemperatureColumn(int column)
{
saveTempCols.append(column);
}

void ZoomLog::addOutputControlColumn(int column)
{
saveControlCols.append(column);
}

void ZoomLog::addOutputAnnotationColumn(int column)
{
saveNoteCols.append(column);
}

void ZoomLog::clearOutputColumns()
{
saveTempCols.clear();
saveControlCols.clear();
saveNoteCols.clear();
}

/*:433*//*434:*/
#line 9887 "./typica.w"

void ZoomLog::persistColumnResize(int column,int,int newsize)
{
/*668:*/
#line 14233 "./typica.w"

QSettings settings;
/*669:*/
#line 14246 "./typica.w"

QWidget*topLevelWidget= this;
while(topLevelWidget->parentWidget())
{
topLevelWidget= topLevelWidget->parentWidget();
}

/*:669*/
#line 14235 "./typica.w"

settings.setValue(QString("columnWidths/%1/%2/%3").
arg(topLevelWidget->objectName()).
arg(objectName()).arg(column),
QVariant(newsize));

/*:668*/
#line 9890 "./typica.w"

}

void ZoomLog::restoreColumnWidths()
{
/*671:*/
#line 14266 "./typica.w"

QSettings settings;
/*669:*/
#line 14246 "./typica.w"

QWidget*topLevelWidget= this;
while(topLevelWidget->parentWidget())
{
topLevelWidget= topLevelWidget->parentWidget();
}

/*:669*/
#line 14268 "./typica.w"

QString baseKey= 
QString("columnWidths/%1/%2").arg(topLevelWidget->objectName()).
arg(objectName());
for(int i= 0;i<model()->columnCount();i++)
{
QString key= QString("%1/%2").arg(baseKey).arg(i);
if(settings.contains(key))
{
setColumnWidth(i,settings.value(key).toInt());
}
}

/*:671*/
#line 9895 "./typica.w"

}

void ZoomLog::setVisible(bool visibility)
{
QTableView::setVisible(visibility);
}

void ZoomLog::showEvent(QShowEvent*)
{
/*671:*/
#line 14266 "./typica.w"

QSettings settings;
/*669:*/
#line 14246 "./typica.w"

QWidget*topLevelWidget= this;
while(topLevelWidget->parentWidget())
{
topLevelWidget= topLevelWidget->parentWidget();
}

/*:669*/
#line 14268 "./typica.w"

QString baseKey= 
QString("columnWidths/%1/%2").arg(topLevelWidget->objectName()).
arg(objectName());
for(int i= 0;i<model()->columnCount();i++)
{
QString key= QString("%1/%2").arg(baseKey).arg(i);
if(settings.contains(key))
{
setColumnWidth(i,settings.value(key).toInt());
}
}

/*:671*/
#line 9905 "./typica.w"

}

/*:434*/
#line 552 "./typica.w"

/*443:*/
#line 10138 "./typica.w"

bool MeasurementList::operator<(const MeasurementList&other)const
{
return this->first().toTime()<other.first().toTime();
}

bool MeasurementList::operator==(const MeasurementList&other)const
{
return this->first().toTime()==other.first().toTime();
}

/*:443*//*444:*/
#line 10154 "./typica.w"

QModelIndex MeasurementModel::parent(const QModelIndex&)const
{
return QModelIndex();
}

/*:444*//*445:*/
#line 10164 "./typica.w"

void MeasurementModel::newMeasurement(Measurement measure,int tempcolumn)
{
if(measure.scale()==Units::Unitless)
{
controlColumns->insert(tempcolumn,true);
}
else
{
controlColumns->insert(tempcolumn,false);
}
MeasurementList*temp;
temp= new MeasurementList;
temp->append(QVariant(measure.time()));
/*446:*/
#line 10223 "./typica.w"

/*447:*/
#line 10268 "./typica.w"

QList<MeasurementList*> ::iterator i= lastInsertion;
bool quickscan= false;
if(entries->size()> 5)
{
if(**i<*temp)
{
i+= 1;
for(int j= 10;j> 0;j--)
{
if(i!=entries->end())
{
if(**i<*temp)
{
i+= 1;
}
else
{
quickscan= true;
break;
}
}
else
{
quickscan= true;
break;
}
}
}
else
{
if(**i==*temp)
{
quickscan= true;
}
}
}

/*:447*/
#line 10224 "./typica.w"

if(quickscan==false)
{
i= entries->begin();
QList<MeasurementList*> ::iterator u= entries->end();
QList<MeasurementList*> ::iterator midpoint;
int n= u-i;
int rA;
while(n> 0)
{
rA= n>>1;
midpoint= i+rA;
if(**midpoint<*temp)
{
i= midpoint+1;
n-= rA+1;
}
else
{
n= rA;
}
}
}

/*:446*/
#line 10178 "./typica.w"

MeasurementList*newEntry;
int insertion;
if(i!=entries->end())
{
insertion= entries->indexOf(*i);
if((*i)->first().toTime()==measure.time())
{
/*448:*/
#line 10310 "./typica.w"

if((*i)->size()<tempcolumn+1)
{
for(int j= (*i)->size()-1;j<tempcolumn+1;j++)
{
(*i)->append(QVariant());
}
}
(*i)->replace(tempcolumn,measure);
lastInsertion= i;
emit dataChanged(createIndex(insertion,tempcolumn),
createIndex(insertion,tempcolumn));
lastTemperature->insert(tempcolumn,insertion);

/*:448*/
#line 10186 "./typica.w"

}
else
{
/*449:*/
#line 10328 "./typica.w"

beginInsertRows(QModelIndex(),insertion,insertion);
newEntry= new MeasurementList;
newEntry->append(QVariant(measure.time()));
for(int j= 0;j<tempcolumn+1;j++)
{
newEntry->append(QVariant());
}
newEntry->replace(tempcolumn,measure);
lastInsertion= entries->insert(i,newEntry);
endInsertRows();
lastTemperature->insert(tempcolumn,insertion);

/*:449*/
#line 10190 "./typica.w"

}
}
else
{
/*450:*/
#line 10346 "./typica.w"

insertion= entries->size();
/*449:*/
#line 10328 "./typica.w"

beginInsertRows(QModelIndex(),insertion,insertion);
newEntry= new MeasurementList;
newEntry->append(QVariant(measure.time()));
for(int j= 0;j<tempcolumn+1;j++)
{
newEntry->append(QVariant());
}
newEntry->replace(tempcolumn,measure);
lastInsertion= entries->insert(i,newEntry);
endInsertRows();
lastTemperature->insert(tempcolumn,insertion);

/*:449*/
#line 10348 "./typica.w"


/*:450*/
#line 10195 "./typica.w"

}
if(tempcolumn>=colcount)
{
colcount= tempcolumn+1;
}
emit rowChanged(insertion);
delete temp;
}

/*:445*//*451:*/
#line 10358 "./typica.w"

void MeasurementModel::newAnnotation(QString annotation,int tempcolumn,
int annotationColumn)
{
int r;
if(lastTemperature->contains(tempcolumn))
{
r= lastTemperature->value(tempcolumn);
}
else
{
r= 0;
}
if(r==0&&entries->size()==0)
{
/*452:*/
#line 10396 "./typica.w"

beginInsertRows(QModelIndex(),0,0);
MeasurementList*newEntry= new MeasurementList;
newEntry->append(QVariant(QTime(0,0,0,0)));
entries->append(newEntry);
endInsertRows();

/*:452*/
#line 10373 "./typica.w"

}
MeasurementList*row= entries->at(r);
if(row->size()<=annotationColumn)
{
for(int i= row->size()-1;i<annotationColumn+1;i++)
{
row->append(QVariant());
}
}
row->replace(annotationColumn,annotation);
emit dataChanged(createIndex(r,annotationColumn),
createIndex(r,annotationColumn));
emit rowChanged(r);
if(annotationColumn> colcount-1)
{
colcount= annotationColumn+1;
}
}

/*:451*//*453:*/
#line 10407 "./typica.w"

void MeasurementModel::clear()
{
beginRemoveRows(QModelIndex(),0,entries->size());
while(entries->size()!=0)
{
MeasurementList*row= entries->takeFirst();
delete row;
}
endRemoveRows();
colcount= hData->size();
lastTemperature->clear();
reset();
}

/*:453*//*454:*/
#line 10440 "./typica.w"

bool MeasurementModel::setData(const QModelIndex&index,
const QVariant&value,int role)
{
if(role!=Qt::EditRole&&role!=Qt::DisplayRole)
{
return false;
}
/*455:*/
#line 10472 "./typica.w"

bool valid= false;
if(index.isValid())
{
if(index.row()<entries->size())
{
if(index.column()<colcount)
{
valid= true;
}
}
}

/*:455*/
#line 10448 "./typica.w"

if(!valid)
{
return false;
}
MeasurementList*row= entries->at(index.row());
if(index.column()>=row->size())
{
/*456:*/
#line 10489 "./typica.w"

for(int i= row->size()-1;i<index.column();i++)
{
row->append(QVariant());
}

/*:456*/
#line 10456 "./typica.w"

}
if(index.column()==0)
{
/*457:*/
#line 10504 "./typica.w"

QTime time;
if(!(time= QTime::fromString(value.toString(),"m:s.z")).isValid())
{
if(!(time= QTime::fromString(value.toString(),"m:s")).isValid())
{
return false;
}
}
row= entries->takeAt(index.row());
row->replace(index.column(),QVariant(time));
MeasurementList*temp= row;
/*446:*/
#line 10223 "./typica.w"

/*447:*/
#line 10268 "./typica.w"

QList<MeasurementList*> ::iterator i= lastInsertion;
bool quickscan= false;
if(entries->size()> 5)
{
if(**i<*temp)
{
i+= 1;
for(int j= 10;j> 0;j--)
{
if(i!=entries->end())
{
if(**i<*temp)
{
i+= 1;
}
else
{
quickscan= true;
break;
}
}
else
{
quickscan= true;
break;
}
}
}
else
{
if(**i==*temp)
{
quickscan= true;
}
}
}

/*:447*/
#line 10224 "./typica.w"

if(quickscan==false)
{
i= entries->begin();
QList<MeasurementList*> ::iterator u= entries->end();
QList<MeasurementList*> ::iterator midpoint;
int n= u-i;
int rA;
while(n> 0)
{
rA= n>>1;
midpoint= i+rA;
if(**midpoint<*temp)
{
i= midpoint+1;
n-= rA+1;
}
else
{
n= rA;
}
}
}

/*:446*/
#line 10516 "./typica.w"

entries->insert(i,row);
int newRow= entries->indexOf(*i);
if(newRow<index.row())
{
emit dataChanged(createIndex(newRow,index.column()),index);
}
else
{
emit dataChanged(index,createIndex(newRow,index.column()));
}

/*:457*/
#line 10460 "./typica.w"

}
else
{
/*458:*/
#line 10530 "./typica.w"

row->replace(index.column(),value);
emit dataChanged(index,index);

/*:458*/
#line 10464 "./typica.w"

}
return true;
}

/*:454*//*459:*/
#line 10538 "./typica.w"

MeasurementModel::MeasurementModel(QObject*parent):QAbstractItemModel(parent),
unit(Units::Fahrenheit),hData(new QStringList),
lastTemperature(new QHash<int,int> ),
controlColumns(new QHash<int,bool> )
{
colcount= 1;
entries= new QList<MeasurementList*> ;
lastInsertion= entries->begin();
hData->append(tr("Time"));
}

/*:459*//*460:*/
#line 10552 "./typica.w"

MeasurementModel::~MeasurementModel()
{
clear();
delete entries;
delete hData;
}

/*:460*//*461:*/
#line 10564 "./typica.w"

int MeasurementModel::rowCount(const QModelIndex&parent)const
{
if(parent==QModelIndex())
{
return entries->size();
}
return 0;
}

int MeasurementModel::columnCount(const QModelIndex&parent)const
{
if(parent==QModelIndex())
{
return colcount;
}
return 0;
}

/*:461*//*462:*/
#line 10591 "./typica.w"

bool MeasurementModel::setHeaderData(int section,Qt::Orientation orientation,
const QVariant&value,int)
{
if(orientation==Qt::Horizontal)
{
if(hData->size()<section+1)
{
for(int i= hData->size();i<section+1;i++)
{
if(colcount<i)
{
beginInsertColumns(QModelIndex(),i,i);
}
hData->append(QString());
if(colcount<i)
{
endInsertColumns();
}
}
}
hData->replace(section,value.toString());
emit headerDataChanged(orientation,section,section);
if(colcount<section+1)
{
colcount= section+1;
}
return true;
}
return false;
}

/*:462*//*463:*/
#line 10631 "./typica.w"

void MeasurementModel::setDisplayUnits(Units::Unit scale)
{
beginResetModel();
unit= scale;
endResetModel();
}

Units::Unit MeasurementModel::displayUnits()
{
return unit;
}

/*:463*//*464:*/
#line 10657 "./typica.w"

QVariant MeasurementModel::data(const QModelIndex&index,int role)const
{
/*455:*/
#line 10472 "./typica.w"

bool valid= false;
if(index.isValid())
{
if(index.row()<entries->size())
{
if(index.column()<colcount)
{
valid= true;
}
}
}

/*:455*/
#line 10660 "./typica.w"

if(!valid)
{
return QVariant();
}
MeasurementList*row= entries->at(index.row());
if(role==Qt::UserRole)
{
return QVariant(row->at(index.column()));
}
if(role==Qt::DisplayRole||role==Qt::EditRole)
{
if(index.column()> row->size())
{
return QVariant();
}
else
{
if(index.column()==0)
{
return QVariant(row->at(0).toTime().toString("mm:ss.zzz"));
}
else if(lastTemperature->contains(index.column()))
{
QVariantMap v= row->at(index.column()).toMap();
if(!v.contains("measurement"))
{
return QVariant();
}
if((Units::Unit)(v.value("unit").toInt())==Units::Unitless)
{
return v.value("measurement");
}
else
{
if(v.contains("relative"))
{
if(v.value("relative").toBool())
{
return QVariant(QString("%1").arg(Units::convertRelativeTemperature(v.value("measurement").
toDouble(),(Units::Unit)(v.value("unit").toInt()),unit)));
}
}
return QVariant(QString("%1").
arg(Units::convertTemperature(v.value("measurement").toDouble(),
(Units::Unit)(v.value("unit").toInt()),unit)));
}
}
return QVariant(row->at(index.column()).toString());
}
}
return QVariant();
}

/*:464*//*465:*/
#line 10716 "./typica.w"

QVariant MeasurementModel::headerData(int section,Qt::Orientation orientation,
int role)const
{
if(orientation==Qt::Horizontal)
{
if(role==Qt::DisplayRole)
{
if(section<hData->size())
{
return QVariant(hData->at(section));
}
}
}
return QVariant();
}

/*:465*//*466:*/
#line 10743 "./typica.w"

Qt::ItemFlags MeasurementModel::flags(const QModelIndex&index)const
{
/*455:*/
#line 10472 "./typica.w"

bool valid= false;
if(index.isValid())
{
if(index.row()<entries->size())
{
if(index.column()<colcount)
{
valid= true;
}
}
}

/*:455*/
#line 10746 "./typica.w"

if(valid)
{
return Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsEditable;
}
return 0;
}

/*:466*//*467:*/
#line 10758 "./typica.w"

QModelIndex MeasurementModel::index(int row,int column,
const QModelIndex&parent)const
{
if(parent==QModelIndex())
{
if(row<entries->size()&&entries->isEmpty()==false)
{
if(column<entries->at(row)->size())
{
return createIndex(row,column);
}
}
}
return QModelIndex();
}

/*:467*/
#line 553 "./typica.w"

/*469:*/
#line 10813 "./typica.w"

AnnotationButton::AnnotationButton(const QString&text,QWidget*parent):
QPushButton(text,parent),noteTemplate(""),note(""),tc(0),ac(0),
count(0),batch("A")
{
connect(this,SIGNAL(clicked()),this,SLOT(annotate()));
}

/*:469*//*470:*/
#line 10829 "./typica.w"

void AnnotationButton::annotate()
{
if(note.contains("%1"))
{
count++;
emit annotation(note.arg(count),tc,ac);
}
else
{
emit annotation(note,tc,ac);
}
}

/*:470*//*471:*/
#line 10847 "./typica.w"

void AnnotationButton::setTemperatureColumn(int tempcolumn)
{
tc= tempcolumn;
}

void AnnotationButton::setAnnotationColumn(int annotationcolumn)
{
ac= annotationcolumn;
}

void AnnotationButton::setAnnotation(const QString&annotation)
{
noteTemplate= annotation;
/*472:*/
#line 10867 "./typica.w"

int batchReplace= noteTemplate.indexOf("%A");
if(batchReplace>=0)
{
QString temp= noteTemplate;
note= temp.replace(batchReplace,2,batch);
}
else
{
note= noteTemplate;
}

/*:472*/
#line 10861 "./typica.w"

}

/*:471*//*473:*/
#line 10882 "./typica.w"

void AnnotationButton::resetCount()
{
count= 0;
}

void AnnotationButton::resetBatch()
{
batch= "A";
/*472:*/
#line 10867 "./typica.w"

int batchReplace= noteTemplate.indexOf("%A");
if(batchReplace>=0)
{
QString temp= noteTemplate;
note= temp.replace(batchReplace,2,batch);
}
else
{
note= noteTemplate;
}

/*:472*/
#line 10891 "./typica.w"

}

/*:473*//*474:*/
#line 10897 "./typica.w"

void AnnotationButton::incrementBatch()
{
int position= batch.size()-1;
increment:
if(batch[position]!='Z')
{
batch[position]= batch[position].unicode()+1;
}
else
{
batch[position]= 'A';
if(position> 0)
{
position--;
goto increment;
}
else
{
batch.append("A");
}
}
/*472:*/
#line 10867 "./typica.w"

int batchReplace= noteTemplate.indexOf("%A");
if(batchReplace>=0)
{
QString temp= noteTemplate;
note= temp.replace(batchReplace,2,batch);
}
else
{
note= noteTemplate;
}

/*:472*/
#line 10919 "./typica.w"

}

/*:474*/
#line 554 "./typica.w"

/*479:*/
#line 10999 "./typica.w"

AnnotationSpinBox::AnnotationSpinBox(const QString&pret,
const QString&postt,
QWidget*parent)
:QDoubleSpinBox(parent),pretext(pret),posttext(postt)
{
resetChange();
connect(this,SIGNAL(editingFinished()),this,SLOT(annotate()));
connect(this,SIGNAL(valueChanged(double)),this,SLOT(resetChange()));
}

/*:479*//*480:*/
#line 11016 "./typica.w"

void AnnotationSpinBox::resetChange()
{
change= true;
}

/*:480*//*481:*/
#line 11027 "./typica.w"

void AnnotationSpinBox::annotate()
{
if(change)
{
change= false;
emit annotation(QString("%1%2%3").arg(pretext).
arg(value()).arg(posttext),tc,ac);
}
}

/*:481*//*482:*/
#line 11040 "./typica.w"

void AnnotationSpinBox::setTemperatureColumn(int tempcolumn)
{
tc= tempcolumn;
}

void AnnotationSpinBox::setAnnotationColumn(int annotationcolumn)
{
ac= annotationcolumn;
}

void AnnotationSpinBox::setPretext(const QString&pret)
{
pretext= pret;
}

void AnnotationSpinBox::setPosttext(const QString&postt)
{
posttext= postt;
}

/*:482*/
#line 555 "./typica.w"

/*489:*/
#line 11209 "./typica.w"

TimerDisplay::TimerDisplay(QWidget*parent):QLCDNumber(8,parent),
s(QTime(0,0,0)),r(QTime(0,0,0)),clock(NULL),m(TimerDisplay::CountUp),
running(false),ar(false),startAction(new QAction(tr("Start"),NULL)),
stopAction(new QAction(tr("Stop"),NULL)),
resetAction(new QAction(tr("Reset"),NULL)),f(QString("hh:mm:ss")),
relative(QTime::currentTime()),base(QTime(0,0,0))
{
connect(startAction,SIGNAL(triggered(bool)),this,SLOT(startTimer()));
connect(stopAction,SIGNAL(triggered(bool)),this,SLOT(stopTimer()));
connect(resetAction,SIGNAL(triggered(bool)),this,SLOT(reset()));
clock.setInterval(500);
clock.setSingleShot(false);
connect(&clock,SIGNAL(timeout()),this,SLOT(updateTime()));
setSegmentStyle(Filled);
updateDisplay();
}

/*:489*//*490:*/
#line 11230 "./typica.w"

void TimerDisplay::updateTime()
{
QTime time;
int cseconds= 0;
int oseconds= 0;
int r= 0;
QTime nt= QTime(0,0,0);
int n= 0;
int bseconds= 0;
switch(m)
{
case TimerDisplay::CountUp:
/*491:*/
#line 11262 "./typica.w"

/*492:*/
#line 11275 "./typica.w"

#define TIMETOINT(t) ((t.hour() * 60 * 60) + (t.minute() * 60) + (t.second()))

time= QTime::currentTime();
cseconds= TIMETOINT(time);
oseconds= TIMETOINT(relative);
r= cseconds-oseconds;

/*:492*/
#line 11263 "./typica.w"

nt= nt.addSecs(r);
if(nt!=s)
{
s= nt;
emit valueChanged(s);
}

/*:491*/
#line 11243 "./typica.w"
;
break;
case TimerDisplay::CountDown:
/*493:*/
#line 11287 "./typica.w"

if(s> QTime(0,0,0))
{
/*492:*/
#line 11275 "./typica.w"

#define TIMETOINT(t) ((t.hour() * 60 * 60) + (t.minute() * 60) + (t.second()))

time= QTime::currentTime();
cseconds= TIMETOINT(time);
oseconds= TIMETOINT(relative);
r= cseconds-oseconds;

/*:492*/
#line 11290 "./typica.w"

bseconds= TIMETOINT(base);
n= bseconds-r;
nt= nt.addSecs(n);
if(nt!=s)
{
s= nt;
emit valueChanged(s);
}
}else{
stopTimer();
}

/*:493*/
#line 11246 "./typica.w"
;
break;
case TimerDisplay::Clock:
/*494:*/
#line 11306 "./typica.w"

time= QTime::currentTime();
if(time!=s)
{
s= time;
emit valueChanged(s);
}

/*:494*/
#line 11249 "./typica.w"
;
break;
default:
Q_ASSERT_X(false,"updateTime","invalid timer mode");
break;
}
updateDisplay();
}

/*:490*//*495:*/
#line 11318 "./typica.w"

#define TIMESUBTRACT(t1, t2) (t1.addSecs(-(TIMETOINT(t2))).addSecs(-t2.msec()))

void TimerDisplay::startTimer()
{
if(!running)
{
relative= QTime::currentTime();
if(ar)
{
reset();
}
else
{
relative= TIMESUBTRACT(relative,s);
}
if(m==Clock)
{
updateTime();
}
base= s;
clock.start();
running= true;
emit runStateChanged(true);
}
}

/*:495*//*496:*/
#line 11348 "./typica.w"

void TimerDisplay::stopTimer()
{
if(running)
{
clock.stop();
running= false;
emit runStateChanged(false);
}
}

/*:496*//*497:*/
#line 11361 "./typica.w"

TimerDisplay::~TimerDisplay()
{
clock.stop();
}

/*:497*//*498:*/
#line 11370 "./typica.w"

void TimerDisplay::setCountUpMode()
{
m= TimerDisplay::CountUp;
}

void TimerDisplay::setCountDownMode()
{
m= TimerDisplay::CountDown;
}

void TimerDisplay::setClockMode()
{
m= TimerDisplay::Clock;
}

/*:498*//*499:*/
#line 11388 "./typica.w"

QString TimerDisplay::value()
{
return s.toString(f);
}

QTime TimerDisplay::seconds()
{
return s;
}

TimerDisplay::TimerMode TimerDisplay::mode()
{
return m;
}

bool TimerDisplay::isRunning()
{
return running;
}

QTime TimerDisplay::resetValue()
{
return r;
}

QString TimerDisplay::displayFormat()
{
return f;
}

bool TimerDisplay::autoReset()
{
return ar;
}

/*:499*//*500:*/
#line 11426 "./typica.w"

void TimerDisplay::setTimer(QTime value)
{
if(value.isValid())
{
s= value;
updateDisplay();
emit valueChanged(value);
}
}

void TimerDisplay::setMode(TimerDisplay::TimerMode mode)
{
m= mode;
}

void TimerDisplay::setResetValue(QTime value)
{
r= value;
}

void TimerDisplay::setDisplayFormat(QString format)
{
f= format;
setNumDigits(format.length());
}

void TimerDisplay::setAutoReset(bool reset)
{
ar= reset;
}

/*:500*//*501:*/
#line 11461 "./typica.w"

void TimerDisplay::copyTimer()
{
QApplication::clipboard()->setText(value());
}

/*:501*//*502:*/
#line 11470 "./typica.w"

void TimerDisplay::reset()
{
if(!running)
{
s= r;
updateDisplay();
}
}

/*:502*//*503:*/
#line 11483 "./typica.w"

void TimerDisplay::updateDisplay()
{
display(value());
}

/*:503*/
#line 556 "./typica.w"

/*510:*/
#line 11608 "./typica.w"

int PackLayout::doLayout(const QRect&rect,bool testOnly)const
{
int x= rect.x();
int y= rect.y();
QLayoutItem*item;
if(orientation==Qt::Horizontal)
{
/*511:*/
#line 11632 "./typica.w"

foreach(item,itemList)
{
int nextX= x+item->sizeHint().width()+spacing();
int right= x+item->sizeHint().width();
if(item==itemList.last())
{
right= rect.right();
}
int bottom= rect.bottom();
if(!testOnly)
{
item->setGeometry(QRect(QPoint(x,y),QPoint(right,bottom)));
}
x= nextX;
}

/*:511*/
#line 11616 "./typica.w"

}
else
{
/*512:*/
#line 11651 "./typica.w"

foreach(item,itemList)
{
int nextY= y+item->sizeHint().height()+spacing();
int bottom= y+item->sizeHint().height();
if(item==itemList.last())
{
bottom= rect.bottom();
}
int right= rect.right();
if(!testOnly)
{
item->setGeometry(QRect(QPoint(x,y),QPoint(right,bottom)));
}
y= nextY;
}

/*:512*/
#line 11620 "./typica.w"

}
return y;
}

/*:510*//*513:*/
#line 11675 "./typica.w"

QSize PackLayout::minimumSize()const
{
QSize size;
QLayoutItem*item;
foreach(item,itemList)
{
if(orientation==Qt::Horizontal)
{
size+= QSize(item->minimumSize().width(),0);
if(size.height()<item->minimumSize().height())
{
size.setHeight(item->minimumSize().height());
}
}
else
{
size+= QSize(0,item->minimumSize().height());
if(size.width()<item->minimumSize().width())
{
size.setWidth(item->minimumSize().width());
}
}
}
size+= QSize(2*margin(),2*margin());
return size;
}

/*:513*//*514:*/
#line 11707 "./typica.w"

PackLayout::PackLayout(QWidget*parent,int margin,int spacing):
QLayout(parent)
{
setMargin(margin);
setSpacing(spacing);
setOrientation(Qt::Horizontal);
}

PackLayout::PackLayout(int spacing)
{
setSpacing(spacing);
setOrientation(Qt::Horizontal);
}

/*:514*//*515:*/
#line 11725 "./typica.w"

PackLayout::~PackLayout()
{
QLayoutItem*item;
while((item= takeAt(0)))
{
delete item;
}
}

/*:515*//*516:*/
#line 11739 "./typica.w"

QLayoutItem*PackLayout::takeAt(int index)
{
if(index>=0&&index<itemList.size())
{
return itemList.takeAt(index);
}
else
{
return NULL;
}
}

/*:516*//*517:*/
#line 11755 "./typica.w"

QLayoutItem*PackLayout::itemAt(int index)const
{
if(index>=0&&index<itemList.size())
{
return itemList.at(index);
}
else
{
return NULL;
}
}

/*:517*//*518:*/
#line 11778 "./typica.w"

void PackLayout::addItem(QLayoutItem*item)
{
itemList.append(item);
}

/*:518*//*519:*/
#line 11786 "./typica.w"

int PackLayout::count()const
{
return itemList.size();
}

/*:519*//*520:*/
#line 11798 "./typica.w"

Qt::Orientations PackLayout::expandingDirections()const
{
return Qt::Vertical|Qt::Horizontal;
}

bool PackLayout::hasHeightForWidth()const
{
return false;
}

int PackLayout::heightForWidth(int width)const
{
return doLayout(QRect(0,0,width,0),true);
}

void PackLayout::setGeometry(const QRect&rect)
{
QLayout::setGeometry(rect);
doLayout(rect,false);
}

QSize PackLayout::sizeHint()const
{
return minimumSize();
}

/*:520*//*521:*/
#line 11829 "./typica.w"

void PackLayout::setOrientation(Qt::Orientations direction)
{
orientation= direction;
doLayout(geometry(),false);
}

/*:521*/
#line 557 "./typica.w"

/*523:*/
#line 11868 "./typica.w"

SceneButton::SceneButton():QGraphicsScene()
{

}

SceneButton::~SceneButton()
{

}

void SceneButton::mousePressEvent(QGraphicsSceneMouseEvent*mouseEvent)
{
emit clicked(mouseEvent->buttonDownScreenPos(mouseEvent->button()));
}

/*:523*/
#line 558 "./typica.w"

/*525:*/
#line 11914 "./typica.w"

WidgetDecorator::WidgetDecorator(QWidget*widget,const QString&labeltext,
Qt::Orientations orientation,
QWidget*parent,Qt::WindowFlags f):
QWidget(parent,f),label(new QGraphicsView()),
scene(new SceneButton())
{
layout= new PackLayout(this);
layout->setOrientation(orientation);
/*526:*/
#line 11934 "./typica.w"

label->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
label->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
label->setFrameShape(QFrame::NoFrame);
label->setInteractive(true);

/*:526*/
#line 11923 "./typica.w"

/*527:*/
#line 11945 "./typica.w"

scene->setBackgroundBrush(Qt::cyan);
text= scene->addText(labeltext);
if(orientation==Qt::Horizontal)
{
text->rotate(270.0);
}
label->setScene(scene);

/*:527*/
#line 11924 "./typica.w"

/*528:*/
#line 11963 "./typica.w"

if(orientation==Qt::Horizontal)
{
label->setMaximumWidth((int)(text->boundingRect().height()+1));
}
else
{
label->setMaximumHeight((int)(text->boundingRect().height()+1));
}
label->centerOn(text);

/*:528*/
#line 11925 "./typica.w"

/*529:*/
#line 11978 "./typica.w"

layout->addWidget(label);
layout->addWidget(widget);
if(orientation==Qt::Horizontal)
{
setMinimumSize(widget->sizeHint().width()+label->sizeHint().width(),
widget->sizeHint().height());
}
else
{
setMinimumSize(widget->sizeHint().width(),
widget->sizeHint().height()+label->sizeHint().height());
}

/*:529*/
#line 11926 "./typica.w"

}

/*:525*//*530:*/
#line 11995 "./typica.w"

void WidgetDecorator::setBackgroundBrush(QBrush background)
{
scene->setBackgroundBrush(background);
}

void WidgetDecorator::setTextColor(QColor color)
{
text->setDefaultTextColor(color);
}

/*:530*//*531:*/
#line 12008 "./typica.w"

WidgetDecorator::~WidgetDecorator()
{

}

/*:531*/
#line 559 "./typica.w"

/*536:*/
#line 12107 "./typica.w"

void LogEditWindow::addTheRows()
{
QTime s= startTime->time();
while(s<endTime->time())
{
model->newMeasurement(Measurement(0,s),1);
s= s.addSecs(interval->value());
}
model->newMeasurement(Measurement(0,endTime->time()),1);
}

/*:536*//*537:*/
#line 12121 "./typica.w"

LogEditWindow::LogEditWindow():QMainWindow(NULL),
centralWidget(new QWidget(NULL)),mainLayout(new PackLayout(0)),
addRowsLayout(new QHBoxLayout(NULL)),
startTimeLabel(new QLabel("Start Time")),
startTime(new QTimeEdit(QTime(0,0,0,0))),
endTimeLabel(new QLabel("End Time")),
endTime(new QTimeEdit(QTime(0,20,0,0))),
intervalLabel(new QLabel("Interval (seconds)")),
interval(new QSpinBox()),
addRows(new QPushButton("Add Rows")),
saveXml(new QAction(tr("Save Profile As..."),NULL)),
saveCsv(new QAction(tr("Export CSV"),NULL)),
openXml(new QAction(tr("Load Target Profile..."),NULL)),
model(new MeasurementModel()),
log(new QTableView())
{
/*538:*/
#line 12158 "./typica.w"

QSettings settings;
resize(settings.value("logSize",QSize(620,400)).toSize());
move(settings.value("logPos",QPoint(200,60)).toPoint());

/*:538*/
#line 12138 "./typica.w"

/*539:*/
#line 12171 "./typica.w"

mainLayout->setOrientation(Qt::Vertical);
addRowsLayout->addSpacing(10);
addRowsLayout->addWidget(startTimeLabel);
addRowsLayout->addWidget(startTime);
addRowsLayout->addSpacing(10);
startTime->setDisplayFormat("mm:ss");
addRowsLayout->addWidget(endTimeLabel);
addRowsLayout->addWidget(endTime);
addRowsLayout->addSpacing(10);
endTime->setDisplayFormat("mm:ss");
addRowsLayout->addWidget(intervalLabel);
addRowsLayout->addWidget(interval);
addRowsLayout->addSpacing(10);
interval->setRange(0,60);
interval->setValue(30);
addRowsLayout->addWidget(addRows);
addRowsLayout->addSpacing(10);
connect(addRows,SIGNAL(clicked()),this,SLOT(addTheRows()));

/*:539*/
#line 12139 "./typica.w"

/*540:*/
#line 12194 "./typica.w"

model->setHeaderData(0,Qt::Horizontal,"Time");
model->setHeaderData(1,Qt::Horizontal,"Temperature");
model->setHeaderData(2,Qt::Horizontal,"Annotation");
model->clear();

/*:540*/
#line 12140 "./typica.w"

/*541:*/
#line 12203 "./typica.w"

log->setModel(model);
log->setColumnWidth(0,100);
log->setColumnWidth(1,100);
log->setColumnWidth(2,100);

/*:541*/
#line 12141 "./typica.w"

mainLayout->addItem(addRowsLayout);
mainLayout->addWidget(log);
centralWidget->setLayout(mainLayout);
setCentralWidget(centralWidget);
QMenu*fileMenu= menuBar()->addMenu(tr("&File"));
fileMenu->addAction(openXml);
connect(openXml,SIGNAL(triggered()),this,SLOT(openXML()));
fileMenu->addAction(saveXml);
connect(saveXml,SIGNAL(triggered()),this,SLOT(saveXML()));
fileMenu->addAction(saveCsv);
connect(saveCsv,SIGNAL(triggered()),this,SLOT(saveCSV()));
}

/*:537*//*542:*/
#line 12214 "./typica.w"

void LogEditWindow::saveXML()
{
QSettings settings;
QString lastDir= settings.value("lastDirectory").toString();
QString filename= QFileDialog::getSaveFileName(this,tr("Save Log As..."),
lastDir,"",0);
QFile file(filename);
XMLOutput writer(model,&file,0);
writer.addTemperatureColumn("Temperature",1);
writer.addAnnotationColumn("Annotation",2);
if(writer.output())
{
QFileInfo info(filename);
QDir directory= info.dir();
lastDir= directory.path();
settings.setValue("lastDirectory",lastDir);
}
}

void LogEditWindow::saveCSV()
{
QSettings settings;
QString lastDir= settings.value("lastDirectory").toString();
QString filename= QFileDialog::getSaveFileName(this,tr("Export As..."),
lastDir,"",0);
QFile file(filename);
CSVOutput writer(model,&file,0);
writer.addTemperatureColumn("Temperature",1);
writer.addAnnotationColumn("Annotation",2);
if(writer.output())
{
QFileInfo info(filename);
QDir directory= info.dir();
lastDir= directory.path();
settings.setValue("lastDirectory",lastDir);
}
}

/*:542*//*543:*/
#line 12257 "./typica.w"

void LogEditWindow::openXML()
{
QSettings settings;
QString lastDir= settings.value("lastDirectory").toString();
QString filename= QFileDialog::getOpenFileName(this,tr("Open XML Log..."),
lastDir,"",0);
if(filename.isNull())
{
return;
}
QFile file(filename);
XMLInput reader(&file,1);
connect(&reader,SIGNAL(measure(Measurement,int)),
model,SLOT(newMeasurement(Measurement,int)));
connect(&reader,SIGNAL(annotation(QString,int,int)),
model,SLOT(newAnnotation(QString,int,int)));
if(reader.input())
{
QFileInfo info(filename);
setWindowTitle(QString(tr("%1 - %2")).
arg(QCoreApplication::applicationName()).arg(info.baseName()));
QDir directory= info.dir();
lastDir= directory.path();
settings.setValue("lastDirectory",lastDir);
}
}

/*:543*//*544:*/
#line 12288 "./typica.w"

void LogEditWindow::closeEvent(QCloseEvent*event)
{
QSettings settings;
settings.setValue("logSize",size());
settings.setValue("logPos",pos());
event->accept();
}

/*:544*/
#line 560 "./typica.w"

/*550:*/
#line 12403 "./typica.w"

bool XMLOutput::output()
{
if(!out->open(QIODevice::WriteOnly|QIODevice::Text))
{
return false;
}
QXmlStreamWriter xmlout(out);
xmlout.writeStartDocument("1.0");
xmlout.writeDTD("<!DOCTYPE roastlog3.0>");
xmlout.writeStartElement("roastlog");
/*551:*/
#line 12436 "./typica.w"

foreach(int c,temperatureColumns.keys())
{
xmlout.writeStartElement("tempseries");
xmlout.writeAttribute("name",temperatureColumns.value(c));
xmlout.writeEndElement();
}
foreach(int c,controlColumns.keys())
{
xmlout.writeStartElement("controlseries");
xmlout.writeAttribute("name",controlColumns.value(c));
xmlout.writeEndElement();
}
foreach(int c,annotationColumns.keys())
{
xmlout.writeStartElement("noteseries");
xmlout.writeAttribute("name",annotationColumns.value(c));
xmlout.writeEndElement();
}

/*:551*/
#line 12414 "./typica.w"

xmlout.writeStartElement("roast");
bool oresult;
for(int i= 0;i<data->rowCount();i++)
{
/*552:*/
#line 12461 "./typica.w"

oresult= false;
foreach(int c,temperatureColumns.keys())
{
if(data->data(data->index(i,c),Qt::DisplayRole).isValid()&&
!(data->data(data->index(i,c),Qt::DisplayRole).toString().isEmpty()))
{
oresult= true;
break;
}
}
foreach(int c,controlColumns.keys())
{
if(data->data(data->index(i,c),Qt::DisplayRole).isValid()&&
!(data->data(data->index(i,c),Qt::DisplayRole).toString().isEmpty()))
{
oresult= true;
break;
}
}
if(oresult==false)
{
foreach(int c,annotationColumns.keys())
{
if(data->data(data->index(i,c),Qt::DisplayRole).isValid()&&
!(data->data(data->index(i,c),Qt::DisplayRole).toString().
isEmpty()))
{
oresult= true;
break;
}
}
}

/*:552*/
#line 12419 "./typica.w"

if(oresult)
{
/*553:*/
#line 12500 "./typica.w"

xmlout.writeStartElement("tuple");
xmlout.writeTextElement("time",data->data(data->index(i,time),
Qt::DisplayRole).toString());
foreach(int c,temperatureColumns.keys())
{
if(data->data(data->index(i,c),Qt::DisplayRole).isValid()&&
!(data->data(data->index(i,c),Qt::DisplayRole).toString().isEmpty()))
{
xmlout.writeStartElement("temperature");
xmlout.writeAttribute("series",temperatureColumns.value(c));
if(data->data(data->index(i,c),Qt::UserRole).toMap().contains("relative"))
{
if(data->data(data->index(i,c),Qt::UserRole).toMap().value("relative").toBool())
{
xmlout.writeAttribute("relative","true");
}
}
xmlout.writeCharacters(data->data(data->index(i,c),Qt::DisplayRole).
toString());
xmlout.writeEndElement();
}
}
foreach(int c,controlColumns.keys())
{
if(data->data(data->index(i,c),Qt::DisplayRole).isValid()&&
!(data->data(data->index(i,c),Qt::DisplayRole).toString().isEmpty()))
{
xmlout.writeStartElement("control");
xmlout.writeAttribute("series",controlColumns.value(c));
xmlout.writeCharacters(data->data(data->index(i,c),Qt::DisplayRole).toString());
xmlout.writeEndElement();
}
}
foreach(int c,annotationColumns.keys())
{
if(data->data(data->index(i,c),Qt::DisplayRole).isValid()&&
!(data->data(data->index(i,c),Qt::DisplayRole).toString().isEmpty()))
{
xmlout.writeStartElement("annotation");
xmlout.writeAttribute("series",annotationColumns.value(c));
xmlout.writeCharacters(data->data(data->index(i,c),Qt::DisplayRole).
toString());
xmlout.writeEndElement();
}
}
xmlout.writeEndElement();

/*:553*/
#line 12422 "./typica.w"

}
}
xmlout.writeEndElement();
xmlout.writeEndElement();
xmlout.writeEndDocument();
out->close();
return true;
}

/*:550*//*554:*/
#line 12550 "./typica.w"

XMLOutput::XMLOutput(MeasurementModel*model,QIODevice*device,int timec)
:QObject(NULL),data(model),out(device),time(timec)
{

}

void XMLOutput::setModel(MeasurementModel*model)
{
data= model;
}

void XMLOutput::setTimeColumn(int column)
{
time= column;
}

void XMLOutput::setDevice(QIODevice*device)
{
out= device;
}

/*:554*//*555:*/
#line 12579 "./typica.w"

void XMLOutput::addTemperatureColumn(const QString&series,int column)
{
temperatureColumns.insert(column,series);
}

void XMLOutput::addControlColumn(const QString&series,int column)
{
controlColumns.insert(column,series);
}

void XMLOutput::addAnnotationColumn(const QString&series,int column)
{
annotationColumns.insert(column,series);
}

/*:555*/
#line 561 "./typica.w"

/*557:*/
#line 12636 "./typica.w"

bool XMLInput::input()
{
if(!in->open(QIODevice::ReadOnly|QIODevice::Text))
{
return false;
}
QXmlStreamReader xmlin(in);
QMap<QString,int> temperatureColumns;
QMap<QString,int> annotationColumns;
int nextColumn= firstc;
/*558:*/
#line 12667 "./typica.w"

while(!xmlin.isDTD())
{
xmlin.readNext();
}
if(xmlin.isDTD())
{
if(xmlin.text()=="<!DOCTYPE roastlog>")
{
/*559:*/
#line 12689 "./typica.w"

emit newTemperatureColumn(firstc,"Bean");
emit newAnnotationColumn(firstc+1,"Note");
emit lastColumn(firstc+1);

/*:559*/
#line 12676 "./typica.w"

}
else
{
xmlin.readNext();
/*560:*/
#line 12698 "./typica.w"

while(xmlin.name()!="roast")
{
if(xmlin.isStartElement())
{
if((xmlin.name()=="tempseries")||(xmlin.name()=="controlseries"))
{
temperatureColumns.insert(xmlin.attributes().value("name").
toString(),
nextColumn);
emit newTemperatureColumn(nextColumn,
xmlin.attributes().value("name").
toString());
nextColumn++;
}
else if(xmlin.name()=="noteseries")
{
annotationColumns.insert(xmlin.attributes().value("name").
toString(),nextColumn);
emit newAnnotationColumn(nextColumn,
xmlin.attributes().value("name").
toString());
nextColumn++;
}
}
xmlin.readNext();
}
emit lastColumn(nextColumn-1);

/*:560*/
#line 12681 "./typica.w"

}
}

/*:558*/
#line 12647 "./typica.w"

QTime timeval= QTime();
double tempval= 0;
QString noteval= QString();
int column;
int counter= 0;
while(!xmlin.atEnd())
{
/*561:*/
#line 12739 "./typica.w"

xmlin.readNext();
if(xmlin.isStartElement())
{
/*562:*/
#line 12765 "./typica.w"

if(xmlin.name()=="time")
{
timeval= QTime::fromString(xmlin.readElementText(),"mm:ss.zzz");
}
else if(xmlin.name()=="temperature")
{
column= xmlin.attributes().hasAttribute("series")?
temperatureColumns.value(xmlin.attributes().value("series").toString()):firstc;
bool relative= (xmlin.attributes().value("relative")=="true");
tempval= xmlin.readElementText().toDouble();
Measurement measurement(tempval,timeval);
if(relative)
{
measurement.insert("relative",true);
}
emit measure(measurement,column);
}
else if(xmlin.name()=="control")
{
column= xmlin.attributes().value("series").toString().isEmpty()?
firstc:temperatureColumns.value(xmlin.attributes().
value("series").toString());
tempval= xmlin.readElementText().toDouble();
Measurement measurement(tempval,timeval,Units::Unitless);
emit measure(measurement,column);
}
else if(xmlin.name()=="annotation")
{
column= xmlin.attributes().value("series").toString().isEmpty()?
firstc+1:annotationColumns.value(xmlin.attributes().
value("series").toString());
noteval= xmlin.readElementText();
if(!noteval.isEmpty())
{
emit annotation(noteval,firstc,column);
}
}

/*:562*/
#line 12743 "./typica.w"

}
counter++;
if(counter%100==0)
{
QCoreApplication::processEvents();
}

/*:561*/
#line 12655 "./typica.w"

}
return true;
}

/*:557*//*563:*/
#line 12806 "./typica.w"

XMLInput::XMLInput(QIODevice*input,int c):
firstc(c),in(input)
{

}

void XMLInput::setFirstColumn(int column)
{
firstc= column;
}

void XMLInput::setDevice(QIODevice*device)
{
in= device;
}

/*:563*/
#line 562 "./typica.w"

/*568:*/
#line 12897 "./typica.w"

bool CSVOutput::output()
{
if(!out->open(QIODevice::WriteOnly|QIODevice::Text))
{
return false;
}
QTextStream output(out);
/*569:*/
#line 12921 "./typica.w"

output<<"Time";
foreach(int c,temperatureColumns.keys())
{
output<<','<<temperatureColumns.value(c);
}
foreach(int c,controlColumns.keys())
{
output<<','<<controlColumns.value(c);
}
foreach(int c,annotationColumns.keys())
{
output<<','<<annotationColumns.value(c);
}
output<<'\n';

/*:569*/
#line 12905 "./typica.w"

bool oresult;
for(int i= 0;i<data->rowCount();i++)
{
/*552:*/
#line 12461 "./typica.w"

oresult= false;
foreach(int c,temperatureColumns.keys())
{
if(data->data(data->index(i,c),Qt::DisplayRole).isValid()&&
!(data->data(data->index(i,c),Qt::DisplayRole).toString().isEmpty()))
{
oresult= true;
break;
}
}
foreach(int c,controlColumns.keys())
{
if(data->data(data->index(i,c),Qt::DisplayRole).isValid()&&
!(data->data(data->index(i,c),Qt::DisplayRole).toString().isEmpty()))
{
oresult= true;
break;
}
}
if(oresult==false)
{
foreach(int c,annotationColumns.keys())
{
if(data->data(data->index(i,c),Qt::DisplayRole).isValid()&&
!(data->data(data->index(i,c),Qt::DisplayRole).toString().
isEmpty()))
{
oresult= true;
break;
}
}
}

/*:552*/
#line 12909 "./typica.w"

if(oresult)
{
/*570:*/
#line 12946 "./typica.w"

output<<data->data(data->index(i,time),Qt::DisplayRole).toString();
foreach(int c,temperatureColumns.keys())
{
output<<','<<data->data(data->index(i,c),Qt::DisplayRole).toString();
}
foreach(int c,controlColumns.keys())
{
output<<','<<data->data(data->index(i,c),Qt::DisplayRole).toString();
}
foreach(int c,annotationColumns.keys())
{
output<<','<<data->data(data->index(i,c),Qt::DisplayRole).toString();
}
output<<'\n';

/*:570*/
#line 12912 "./typica.w"

}
}
out->close();
return true;
}

/*:568*//*571:*/
#line 12965 "./typica.w"

CSVOutput::CSVOutput(MeasurementModel*model,QIODevice*device,int timec):
data(model),out(device),time(timec)
{

}

void CSVOutput::setModel(MeasurementModel*model)
{
data= model;
}

void CSVOutput::setTimeColumn(int column)
{
time= column;
}

void CSVOutput::addTemperatureColumn(const QString&series,int column)
{
temperatureColumns.insert(column,series);
}

void CSVOutput::addControlColumn(const QString&series,int column)
{
controlColumns.insert(column,series);
}

void CSVOutput::addAnnotationColumn(const QString&series,int column)
{
annotationColumns.insert(column,series);
}

void CSVOutput::setDevice(QIODevice*device)
{
out= device;
}

#line 1 "./webview.w"
/*:571*/
#line 563 "./typica.w"

/*623:*/
#line 13361 "./typica.w"

QString SaltModel::arrayLiteral(int column,int role)const
{
QString literal= "'{";
for(int i= 0;i<rowCount();i++)
{
QString datum= data(index(i,column),role).toString();
if(!datum.isEmpty())
{
literal.append(datum);
literal.append(", ");
}
}
if(literal.size()> 2)
{
literal.chop(2);
}
literal.append("}'");
return literal;
}

QString SaltModel::quotedArrayLiteral(int column,int role)const
{
QString literal= "'{";
for(int i= 0;i<rowCount();i++)
{
QString datum= data(index(i,column),role).toString();
if(!datum.isEmpty())
{
literal.append("\"");
literal.append(datum);
literal.append("\", ");
}
}
if(literal.size()> 2)
{
literal.chop(2);
}
literal.append("}'");
return literal;
}

/*:623*//*624:*/
#line 13405 "./typica.w"

QModelIndex SaltModel::parent(const QModelIndex&)const
{
return QModelIndex();
}

/*:624*//*625:*/
#line 13424 "./typica.w"

bool SaltModel::setData(const QModelIndex&index,const QVariant&value,
int role)
{
/*626:*/
#line 13455 "./typica.w"

bool valid= false;
if(index.isValid())
{
if(index.row()<modelData.size())
{
if(index.column()<colcount)
{
valid= true;
}
}
}

/*:626*/
#line 13428 "./typica.w"

if(!valid)
{
return false;
}
if(index.row()==modelData.size()-1)
{
beginInsertRows(QModelIndex(),modelData.size(),modelData.size());
/*627:*/
#line 13471 "./typica.w"

QList<QMap<int,QVariant> > newRow;
QMap<int,QVariant> defaults;
for(int i= 0;i<colcount;i++)
{
newRow.append(defaults);
}
modelData.append(newRow);

/*:627*/
#line 13436 "./typica.w"

endInsertRows();
}
QList<QMap<int,QVariant> > row= modelData.at(index.row());
QMap<int,QVariant> cell= row.at(index.column());
cell.insert(role,value);
if(role==Qt::EditRole)
{
cell.insert(Qt::DisplayRole,value);
}
row.replace(index.column(),cell);
modelData.replace(index.row(),row);
emit dataChanged(index,index);
return true;
}

/*:625*//*628:*/
#line 13482 "./typica.w"

SaltModel::SaltModel(int columns):QAbstractItemModel(),colcount(columns)
{
for(int i= 0;i<columns;i++)
{
hData<<"";
}
/*627:*/
#line 13471 "./typica.w"

QList<QMap<int,QVariant> > newRow;
QMap<int,QVariant> defaults;
for(int i= 0;i<colcount;i++)
{
newRow.append(defaults);
}
modelData.append(newRow);

/*:627*/
#line 13489 "./typica.w"

}

/*:628*//*629:*/
#line 13494 "./typica.w"

SaltModel::~SaltModel()
{

}

/*:629*//*630:*/
#line 13504 "./typica.w"

int SaltModel::rowCount(const QModelIndex&parent)const
{
return(parent==QModelIndex()?modelData.size():0);
}

int SaltModel::columnCount(const QModelIndex&parent)const
{
return(parent==QModelIndex()?colcount:0);
}

/*:630*//*631:*/
#line 13517 "./typica.w"

bool SaltModel::setHeaderData(int section,Qt::Orientation orientation,
const QVariant&value,int)
{
if(orientation==Qt::Horizontal&&section<colcount)
{
hData.replace(section,value.toString());
emit headerDataChanged(orientation,section,section);
return true;
}
return false;
}

/*:631*//*632:*/
#line 13532 "./typica.w"

QVariant SaltModel::data(const QModelIndex&index,int role)const
{
/*626:*/
#line 13455 "./typica.w"

bool valid= false;
if(index.isValid())
{
if(index.row()<modelData.size())
{
if(index.column()<colcount)
{
valid= true;
}
}
}

/*:626*/
#line 13535 "./typica.w"

if(!valid)
{
return QVariant();
}
QList<QMap<int,QVariant> > row= modelData.at(index.row());
QMap<int,QVariant> cell= row.at(index.column());
return cell.value(role,QVariant());
}

QVariant SaltModel::headerData(int section,Qt::Orientation orientation,
int role)const
{
if(orientation==Qt::Horizontal&&role==Qt::DisplayRole&&
section<colcount)
{
return QVariant(hData.at(section));
}
return QVariant();
}

/*:632*//*633:*/
#line 13559 "./typica.w"

Qt::ItemFlags SaltModel::flags(const QModelIndex&index)const
{
/*626:*/
#line 13455 "./typica.w"

bool valid= false;
if(index.isValid())
{
if(index.row()<modelData.size())
{
if(index.column()<colcount)
{
valid= true;
}
}
}

/*:626*/
#line 13562 "./typica.w"

if(valid)
{
return Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsDropEnabled;
}
return 0;
}

/*:633*//*634:*/
#line 13573 "./typica.w"

QModelIndex SaltModel::index(int row,int column,
const QModelIndex&parent)const
{
if(parent==QModelIndex())
{
if(row<modelData.size()&&column<colcount)
{
return createIndex(row,column);
}
}
return QModelIndex();
}

/*:634*//*635:*/
#line 13591 "./typica.w"

void SaltModel::clear()
{
beginResetModel();
modelData.clear();
/*627:*/
#line 13471 "./typica.w"

QList<QMap<int,QVariant> > newRow;
QMap<int,QVariant> defaults;
for(int i= 0;i<colcount;i++)
{
newRow.append(defaults);
}
modelData.append(newRow);

/*:627*/
#line 13596 "./typica.w"

endResetModel();
}

/*:635*//*636:*/
#line 13605 "./typica.w"

bool SaltModel::removeRows(int row,int count,
const QModelIndex&parent)
{
if(parent==QModelIndex())
{
if(row>=0&&count> 0&&(row+count-1)<modelData.size())
{
beginRemoveRows(parent,row,row+count-1);
for(int i= 0;i<count;i++)
{
modelData.removeAt(row);
}
endRemoveRows();
if(modelData.size()==0)
{
beginInsertRows(parent,0,0);
/*627:*/
#line 13471 "./typica.w"

QList<QMap<int,QVariant> > newRow;
QMap<int,QVariant> defaults;
for(int i= 0;i<colcount;i++)
{
newRow.append(defaults);
}
modelData.append(newRow);

/*:627*/
#line 13622 "./typica.w"

endInsertRows();
}
return true;
}
}
return false;
}

/*:636*//*637:*/
#line 13636 "./typica.w"

int SaltModel::findData(const QVariant&value,int column,int role)
{
for(int i= 0;i<modelData.size();i++)
{
if(modelData.at(i).size()> column)
{
if(modelData.at(i).at(column).contains(role))
{
if(modelData.at(i).at(column).value(role)==value)
{
return i;
}
}
}
}
return-1;
}

/*:637*/
#line 564 "./typica.w"

/*639:*/
#line 13700 "./typica.w"

SqlComboBox*SqlComboBox::clone(QWidget*parent)
{
SqlComboBox*widget= new SqlComboBox();
widget->setParent(parent);
for(int i= 0;i<count();i++)
{
widget->addItem(itemText(i),itemData(i));
}
return widget;
}

/*:639*//*640:*/
#line 13717 "./typica.w"

void SqlComboBox::showData(bool show)
{
dataColumnShown= show;
}

/*:640*//*641:*/
#line 13731 "./typica.w"

void SqlComboBox::addNullOption()
{
addItem(specialNullText,specialNullData);
}

void SqlComboBox::setNullText(QString nullText)
{
specialNullText= nullText;
}

void SqlComboBox::setNullData(QVariant nullData)
{
specialNullData= nullData;
}

/*:641*//*642:*/
#line 13754 "./typica.w"

void SqlComboBox::setDataColumn(int column)
{
dataColumn= column;
}

void SqlComboBox::setDisplayColumn(int column)
{
displayColumn= column;
}

/*:642*//*643:*/
#line 13768 "./typica.w"

void SqlComboBox::addSqlOptions(QString query)
{
SqlQueryConnection h;
QSqlQuery*dbquery= h.operator->();
if(!dbquery->exec(query))
{
QSqlError error= dbquery->lastError();
qDebug()<<error.databaseText();
qDebug()<<error.driverText();
qDebug()<<error.text();
qDebug()<<dbquery->lastQuery();

}
while(dbquery->next())
{
QString displayValue(dbquery->value(displayColumn).toString());
QString dataValue(dbquery->value(dataColumn).toString());
if(dataColumnShown)
{
displayValue.append(QString(" (%1)").arg(dataValue));
}
addItem(displayValue,dataValue);
}
}

/*:643*//*644:*/
#line 13804 "./typica.w"

SqlComboBox::SqlComboBox():
dataColumn(0),displayColumn(0),dataColumnShown(false),
specialNullText(tr("Unknown")),specialNullData(QVariant::String)
{
view()->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
}

SqlComboBox::~SqlComboBox()
{

}

/*:644*/
#line 565 "./typica.w"

/*646:*/
#line 13843 "./typica.w"

void SqlComboBoxDelegate::setWidget(SqlComboBox*widget)
{
delegate= widget;
}

/*:646*//*647:*/
#line 13852 "./typica.w"

QWidget*SqlComboBoxDelegate::createEditor(QWidget*parent,
const QStyleOptionViewItem&,
const QModelIndex&)const
{
return delegate->clone(parent);
}

/*:647*//*648:*/
#line 13863 "./typica.w"

void SqlComboBoxDelegate::setEditorData(QWidget*editor,
const QModelIndex&index)const
{
SqlComboBox*self= qobject_cast<SqlComboBox*> (editor);
self->setCurrentIndex(self->findData(
index.model()->data(index,
Qt::UserRole).toString()));
}

/*:648*//*649:*/
#line 13876 "./typica.w"

void SqlComboBoxDelegate::setModelData(QWidget*editor,
QAbstractItemModel*model,
const QModelIndex&index)const
{
SqlComboBox*self= qobject_cast<SqlComboBox*> (editor);
model->setData(index,self->itemData(self->currentIndex(),Qt::UserRole),
Qt::UserRole);
model->setData(index,self->currentText(),Qt::DisplayRole);
}

/*:649*//*650:*/
#line 13889 "./typica.w"

void SqlComboBoxDelegate::updateEditorGeometry(QWidget*editor,
const QStyleOptionViewItem&option,
const QModelIndex&)const
{
editor->setGeometry(option.rect);
}

/*:650*//*651:*/
#line 13900 "./typica.w"

QSize SqlComboBoxDelegate::sizeHint()const
{
return delegate->sizeHint();
}

/*:651*//*652:*/
#line 13908 "./typica.w"

SqlComboBoxDelegate::SqlComboBoxDelegate(QObject*parent)
:QItemDelegate(parent)
{

}

/*:652*/
#line 566 "./typica.w"

/*608:*/
#line 13053 "./typica.w"

Application::Application(int&argc,char**argv):QApplication(argc,argv),
connectionStatus(false),currentUser(QString())
{
network= new QNetworkAccessManager(this);
/*609:*/
#line 13070 "./typica.w"

setOrganizationName("Wilson's Coffee & Tea");
setOrganizationDomain("wilsonscoffee.com");
setApplicationName(PROGRAM_NAME);

/*:609*/
#line 13058 "./typica.w"

/*610:*/
#line 13079 "./typica.w"

QTranslator*base= new QTranslator;
if(base->load(QString("qt_%1").arg(QLocale::system().name()),QString("%1/Translations").arg(QCoreApplication::applicationDirPath())))
{
installTranslator(base);
}
QTranslator*app= new QTranslator;
if(app->load(QString("%1_%2").arg("Typica").arg(QLocale::system().name()),QString("%1/Translations").arg(QCoreApplication::applicationDirPath())))
{
installTranslator(app);
}

/*:610*/
#line 13059 "./typica.w"

/*315:*/
#line 123 "./measurement.w"

qRegisterMetaType<Measurement> ("Measurement");

/*:315*/
#line 13060 "./typica.w"

/*829:*/
#line 17216 "./typica.w"

NodeInserter*inserter= new NodeInserter(tr("NI DAQmx Base Device"),
tr("NI DAQmx Base"),
"nidaqmxbase",NULL);
topLevelNodeInserters.append(inserter);

/*:829*//*837:*/
#line 17447 "./typica.w"

#ifdef Q_OS_WIN32
inserter= new NodeInserter(tr("NI DAQmx Device"),tr("NI DAQmx"),"nidaqmx",NULL);
topLevelNodeInserters.append(inserter);
#endif

/*:837*//*861:*/
#line 18414 "./typica.w"

#if 0
inserter= new NodeInserter(tr("Modbus RTU Port"),tr("Modbus RTU Port"),"modbusrtuport",NULL);
topLevelNodeInserters.append(inserter);
#endif

/*:861*//*914:*/
#line 19923 "./typica.w"

inserter= new NodeInserter(tr("Modbus RTU Device"),tr("Modbus RTU Device"),"modbusrtu",NULL);
topLevelNodeInserters.append(inserter);

#line 1 "./modbus.w"
/*:914*//*920:*/
#line 328 "./modbus.w"

inserter= new NodeInserter(tr("ModbusNG Port"),tr("Modbus RTU Port"),"modbusngport",NULL);
topLevelNodeInserters.append(inserter);

/*:920*//*936:*/
#line 275 "./unsupportedserial.w"

inserter= new NodeInserter(tr("Other Device"),tr("Other Device"),
"unsupporteddevice",NULL);
topLevelNodeInserters.append(inserter);

/*:936*//*967:*/
#line 190 "./phidgets.w"

QLibrary phidgetsCheck("phidget21");
if(phidgetsCheck.load())
{
inserter= new NodeInserter(tr("Phidgets 1048"),tr("Phidgets 1048"),
"phidgets1048",NULL);
topLevelNodeInserters.append(inserter);
phidgetsCheck.unload();
}
else
{
phidgetsCheck.setFileName("Phidget21.framework/Phidget21");
if(phidgetsCheck.load())
{
inserter= new NodeInserter(tr("Phidgets 1048"),tr("Phidgets 1048"),
"phidgets1048",NULL);
topLevelNodeInserters.append(inserter);
phidgetsCheck.unload();
}
}

/*:967*//*981:*/
#line 17 "./phidget22.w"

#if __APPLE__
QLibrary phidget22check("Phidget22.framework/Phidget22");
#else
QLibrary phidget22check("phidget22");
#endif
if(phidget22check.load())
{
inserter= new NodeInserter(tr("Phidget22"),tr("Phidget22"),"phidget22",
NULL);
topLevelNodeInserters.append(inserter);
phidget22check.unload();
}

/*:981*//*1104:*/
#line 1241 "./dataqsdk.w"

#ifdef Q_OS_WIN32
inserter= new NodeInserter(tr("DATAQ SDK Device"),tr("DATAQ Device"),
"dataqsdk",NULL);
topLevelNodeInserters.append(inserter);
#endif

#line 20594 "./typica.w"

#line 1 "./scales.w"
/*:1104*//*1129:*/
#line 557 "./scales.w"

inserter= new NodeInserter(tr("Serial Scale"),tr("Scale"),"scale",NULL);
topLevelNodeInserters.append(inserter);

#line 20596 "./typica.w"

#line 1 "./valueannotation.w"
/*:1129*/
#line 13061 "./typica.w"

}

/*:608*//*612:*/
#line 13102 "./typica.w"

QDomDocument*Application::configuration()
{
return&conf;
}

/*:612*//*613:*/
#line 13111 "./typica.w"

QSqlDatabase Application::database()
{
QString connectionName;
QSqlDatabase connection= 
QSqlDatabase::database(QLatin1String(QSqlDatabase::defaultConnection),false);
do
{
connectionName= QUuid::createUuid().toString();
}while(QSqlDatabase::connectionNames().contains(connectionName));
return QSqlDatabase::cloneDatabase(connection,QString(connectionName));
}

/*:613*//*614:*/
#line 13127 "./typica.w"

void Application::setDatabaseConnected(bool status)
{
connectionStatus= status;
}

bool Application::databaseConnected()
{
return connectionStatus;
}

/*:614*//*615:*/
#line 13150 "./typica.w"

DatabaseNotification*Application::subscribe(const QString&notification)
{
DatabaseNotification*retval;
if(notifiers.contains(notification))
{
retval= notifiers.value(notification);
}
else
{
if(notifiers.size()==0)
{
notificationDriver= QSqlDatabase::database().driver();
connect(notificationDriver,SIGNAL(notification(QString)),this,SLOT(notify(QString)));
}
retval= new DatabaseNotification;
connect(this,SIGNAL(aboutToQuit()),retval,SLOT(deleteLater()));
if(notifiers.size()!=
notificationDriver->subscribedToNotifications().size())
{
for(int i= 0;i<notifiers.size();i++)
{
notificationDriver->subscribeToNotification(notifiers.keys().at(i));
}
}
notifiers.insert(notification,retval);
notificationDriver->subscribeToNotification(notification);
}
return retval;
}

/*:615*//*616:*/
#line 13186 "./typica.w"

void Application::notify(const QString&notification)
{
if(notifiers.contains(notification))
{
DatabaseNotification*notifier= notifiers.value(notification);
notifier->forwardNotification(notification);
}
}

/*:616*//*764:*/
#line 15749 "./typica.w"

void Application::saveDeviceConfiguration()
{
QSettings settings;
settings.setValue("DeviceConfiguration",
QVariant(deviceConfigurationDocument.toByteArray()));
}

/*:764*//*765:*/
#line 15761 "./typica.w"

QDomDocument Application::deviceConfiguration()
{
if(deviceConfigurationDocument.isNull())
{
/*766:*/
#line 15775 "./typica.w"

QSettings settings;
QByteArray document= settings.value("DeviceConfiguration").toByteArray();
QString etext;
int eline;
int ecol;
if(document.length()==0)
{
qDebug()<<"Loaded settings length is 0. Creating new configuration.";
/*767:*/
#line 15799 "./typica.w"

QFile emptyDocument(":/resources/xml/EmptyDeviceConfiguration.xml");
emptyDocument.open(QIODevice::ReadOnly);
if(!deviceConfigurationDocument.setContent(&emptyDocument,false,
&etext,&eline,&ecol))
{
/*768:*/
#line 15816 "./typica.w"

qDebug()<<QString(tr("An error occurred loading device configuration."));
qDebug()<<QString(tr("Line %1, Column %2")).arg(eline).arg(ecol);
qDebug()<<etext;

/*:768*/
#line 15805 "./typica.w"

}
else
{
saveDeviceConfiguration();
}

/*:767*/
#line 15784 "./typica.w"

}
else
{
if(!deviceConfigurationDocument.setContent(document,false,
&etext,&eline,&ecol))
{
/*768:*/
#line 15816 "./typica.w"

qDebug()<<QString(tr("An error occurred loading device configuration."));
qDebug()<<QString(tr("Line %1, Column %2")).arg(eline).arg(ecol);
qDebug()<<etext;

/*:768*/
#line 15791 "./typica.w"

/*767:*/
#line 15799 "./typica.w"

QFile emptyDocument(":/resources/xml/EmptyDeviceConfiguration.xml");
emptyDocument.open(QIODevice::ReadOnly);
if(!deviceConfigurationDocument.setContent(&emptyDocument,false,
&etext,&eline,&ecol))
{
/*768:*/
#line 15816 "./typica.w"

qDebug()<<QString(tr("An error occurred loading device configuration."));
qDebug()<<QString(tr("Line %1, Column %2")).arg(eline).arg(ecol);
qDebug()<<etext;

/*:768*/
#line 15805 "./typica.w"

}
else
{
saveDeviceConfiguration();
}

/*:767*/
#line 15792 "./typica.w"

}
}

/*:766*/
#line 15766 "./typica.w"

}
return deviceConfigurationDocument;
}

/*:765*//*796:*/
#line 16417 "./typica.w"

void Application::registerDeviceConfigurationWidget(QString driver,
QMetaObject widget)
{
deviceConfigurationWidgets.insert(driver,widget);
}

/*:796*//*797:*/
#line 16433 "./typica.w"

QWidget*Application::deviceConfigurationWidget(DeviceTreeModel*model,
const QModelIndex&index)
{
QVariant nodeReference= index.data(Qt::UserRole);
QDomElement referenceElement= model->referenceElement(
model->data(index,Qt::UserRole).toString());
QMetaObject metaObject= 
deviceConfigurationWidgets.value(referenceElement.attribute("driver"),
QWidget::staticMetaObject);
QWidget*editor;
if(metaObject.className()==QWidget::staticMetaObject.className())
{
editor= NULL;
}
else
{
editor= qobject_cast<QWidget*> (
metaObject.newInstance(Q_ARG(DeviceTreeModel*,model),
Q_ARG(QModelIndex,index)));
}
return editor;
}

/*:797*//*1159:*/
#line 16 "./user.w"

QString Application::currentTypicaUser()
{
return currentUser;
}

/*:1159*//*1160:*/
#line 26 "./user.w"

void Application::setCurrentTypicaUser(const QString&user)
{
currentUser= user;
emit userChanged(currentUser);
}

/*:1160*//*1161:*/
#line 37 "./user.w"

bool Application::login(const QString&user,const QString&password)
{
SqlQueryConnection h;
QSqlQuery*dbquery= h.operator->();
dbquery->prepare("SELECT 1 FROM typica_users WHERE name = :name AND password = :password AND active = TRUE");
dbquery->bindValue(":name",user);
dbquery->bindValue(":password",password);
dbquery->exec();
if(dbquery->next())
{
currentUser= user;
emit userChanged(currentUser);
return true;
}
return false;
}

/*:1161*//*1162:*/
#line 58 "./user.w"

bool Application::autoLogin()
{
SqlQueryConnection h;
QSqlQuery*dbquery= h.operator->();
dbquery->exec("SELECT name FROM typica_users WHERE auto_login = TRUE");
if(dbquery->next())
{
currentUser= dbquery->value(0).toString();
emit userChanged(currentUser);
return true;
}
return false;
}

/*:1162*/
#line 567 "./typica.w"

/*661:*/
#line 14056 "./typica.w"

SqlConnectionSetup::SqlConnectionSetup():
formLayout(new QFormLayout),driver(new QComboBox),hostname(new QLineEdit),
portnumber(new QLineEdit),
dbname(new QLineEdit),user(new QLineEdit),password(new QLineEdit),
layout(new QVBoxLayout),buttons(new QHBoxLayout),
cancelButton(new QPushButton(tr("Cancel"))),
connectButton(new QPushButton(tr("Connect")))
{
QSettings settings;
driver->addItem("PostgreSQL","QPSQL");
formLayout->addRow(tr("Database driver:"),driver);
formLayout->addRow(tr("Host name:"),hostname);
hostname->setText(settings.value("database/hostname").toString());
formLayout->addRow(tr("Port number:"),portnumber);
portnumber->setText(settings.value("database/portnumber","5432").toString());
formLayout->addRow(tr("Database name:"),dbname);
dbname->setText(settings.value("database/dbname").toString());
formLayout->addRow(tr("User name:"),user);
user->setText(settings.value("database/user").toString());
password->setEchoMode(QLineEdit::Password);
formLayout->addRow(tr("Password:"),password);
password->setText(settings.value("database/password").toString());
layout->addLayout(formLayout);
buttons->addStretch(1);
buttons->addWidget(cancelButton);
connect(cancelButton,SIGNAL(clicked(bool)),this,SLOT(reject()));
buttons->addWidget(connectButton);
layout->addLayout(buttons);
connect(connectButton,SIGNAL(clicked(bool)),this,SLOT(testConnection()));
connectButton->setDefault(true);
setLayout(layout);
setModal(true);
}

SqlConnectionSetup::~SqlConnectionSetup()
{

}

/*:661*//*662:*/
#line 14099 "./typica.w"

void SqlConnectionSetup::testConnection()
{
QSqlDatabase database= 
QSqlDatabase::addDatabase(driver->itemData(driver->currentIndex()).
toString());
database.setConnectOptions("application_name=Typica");
database.setHostName(hostname->text());
database.setPort(portnumber->text().toInt());
database.setDatabaseName(dbname->text());
database.setUserName(user->text());
database.setPassword(password->text());
if(database.open())
{
QSettings settings;
settings.setValue("database/exists","true");
settings.setValue("database/driver",
driver->itemData(driver->currentIndex()).toString());
settings.setValue("database/hostname",hostname->text());
settings.setValue("database/portnumber",portnumber->text());
settings.setValue("database/dbname",dbname->text());
settings.setValue("database/user",user->text());
settings.setValue("database/password",password->text());
AppInstance->setDatabaseConnected(true);
accept();
}
else
{
QMessageBox::information(this,tr("Database connection failed"),
tr("Failed to connect to database."));
}
}

/*:662*/
#line 568 "./typica.w"

/*666:*/
#line 14207 "./typica.w"

SqlQueryView::SqlQueryView(QWidget*parent):QTableView(parent)
{
setModel(new QSqlQueryModel);
connect(this,SIGNAL(doubleClicked(QModelIndex)),
this,SLOT(openRow(QModelIndex)));
connect(horizontalHeader(),SIGNAL(sectionResized(int,int,int)),
this,SLOT(persistColumnResize(int,int,int)));
connect(this,SIGNAL(activated(QModelIndex)),
this,SLOT(selectRow(QModelIndex)));
}

/*:666*//*667:*/
#line 14224 "./typica.w"

void SqlQueryView::persistColumnResize(int column,int,int newsize)
{
/*668:*/
#line 14233 "./typica.w"

QSettings settings;
/*669:*/
#line 14246 "./typica.w"

QWidget*topLevelWidget= this;
while(topLevelWidget->parentWidget())
{
topLevelWidget= topLevelWidget->parentWidget();
}

/*:669*/
#line 14235 "./typica.w"

settings.setValue(QString("columnWidths/%1/%2/%3").
arg(topLevelWidget->objectName()).
arg(objectName()).arg(column),
QVariant(newsize));

/*:668*/
#line 14227 "./typica.w"

}

/*:667*//*670:*/
#line 14256 "./typica.w"

void SqlQueryView::showEvent(QShowEvent*event)
{
/*671:*/
#line 14266 "./typica.w"

QSettings settings;
/*669:*/
#line 14246 "./typica.w"

QWidget*topLevelWidget= this;
while(topLevelWidget->parentWidget())
{
topLevelWidget= topLevelWidget->parentWidget();
}

/*:669*/
#line 14268 "./typica.w"

QString baseKey= 
QString("columnWidths/%1/%2").arg(topLevelWidget->objectName()).
arg(objectName());
for(int i= 0;i<model()->columnCount();i++)
{
QString key= QString("%1/%2").arg(baseKey).arg(i);
if(settings.contains(key))
{
setColumnWidth(i,settings.value(key).toInt());
}
}

/*:671*/
#line 14259 "./typica.w"

event->accept();
}

/*:670*//*672:*/
#line 14283 "./typica.w"

void SqlQueryView::openRow(const QModelIndex&index)
{
emit openEntry(((QSqlQueryModel*)model())->record(index.row()).value(0).toString());
emit openEntryRow(index.row());
}

void SqlQueryView::selectRow(const QModelIndex&index)
{
emit selectEntry(((QSqlQueryModel*)model())->record(index.row()).value(0).toString());
emit selectEntryRow(index.row());
}

/*:672*//*673:*/
#line 14298 "./typica.w"

void SqlQueryView::setQuery(const QString&query)
{
QSqlDatabase database= AppInstance->database();
database.open();
QSqlQuery q(query,database);
((QSqlQueryModel*)model())->setQuery(q);
database.close();
}

bool SqlQueryView::setHeaderData(int section,Qt::Orientation orientation,
const QVariant&value,int role)
{
return model()->setHeaderData(section,orientation,value,role);
}

/*:673*//*674:*/
#line 14316 "./typica.w"

QVariant SqlQueryView::data(int row,int column,int role)
{
return model()->data(model()->index(row,column),role);
}

/*:674*/
#line 569 "./typica.w"

/*180:*/
#line 4104 "./typica.w"

SqlQueryConnection::SqlQueryConnection(const QString&query)
{
QSqlDatabase database= AppInstance->database();
database.open();
q= new QSqlQuery(query,database);
connection= database.connectionName();
}

/*:180*//*181:*/
#line 4117 "./typica.w"

SqlQueryConnection::~SqlQueryConnection()
{
delete q;
{
QSqlDatabase database= QSqlDatabase::database(connection);
database.close();
}
QSqlDatabase::removeDatabase(connection);
}

/*:181*//*182:*/
#line 4131 "./typica.w"

QSqlQuery*SqlQueryConnection::operator->()const
{
return q;
}

/*:182*/
#line 570 "./typica.w"

/*693:*/
#line 14684 "./typica.w"

ReportTable::ReportTable(QTextFrame*frame,QDomElement description):
area(frame),configuration(description)
{
refresh();
}

ReportTable::~ReportTable()
{

}

/*:693*//*694:*/
#line 14700 "./typica.w"

void ReportTable::bind(QString placeholder,QVariant value)
{
bindings.insert(placeholder,value);
}

/*:694*//*695:*/
#line 14710 "./typica.w"

void ReportTable::refresh()
{
/*696:*/
#line 14731 "./typica.w"

QTextCursor cursor= area->firstCursorPosition();
while(cursor<area->lastCursorPosition())
{
cursor.movePosition(QTextCursor::Right,QTextCursor::KeepAnchor);
}
cursor.removeSelectedText();

/*:696*/
#line 14713 "./typica.w"

int rows= 1;
int columns= 1;
int currentRow= 0;
QTextTable*table= cursor.insertTable(rows,columns);
/*697:*/
#line 14744 "./typica.w"

QTextTableFormat format= table->format();
format.setBorderStyle(QTextFrameFormat::BorderStyle_None);
if(configuration.hasAttribute("align"))
{
if(configuration.attribute("align")=="center")
{
format.setAlignment(Qt::AlignHCenter);
}
}
table->setFormat(format);

/*:697*/
#line 14718 "./typica.w"

/*698:*/
#line 14758 "./typica.w"

QDomNodeList children= configuration.childNodes();
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
if(currentElement.tagName()=="query")
{
/*699:*/
#line 14785 "./typica.w"

SqlQueryConnection h;
QSqlQuery*query= h.operator->();
query->prepare(currentElement.text());
foreach(QString key,bindings.uniqueKeys())
{
if(currentElement.text().contains(key))
{
query->bindValue(key,bindings.value(key));
}
}
query->exec();
if(!query->next())
{
continue;
}
if(query->record().count()> columns)
{
table->appendColumns(query->record().count()-columns);
}
do
{
table->appendRows(1);
rows++;
currentRow++;
for(int j= 0;j<query->record().count();j++)
{
QTextTableCell cell= table->cellAt(currentRow,j);
cursor= cell.firstCursorPosition();
cursor.insertText(query->value(j).toString());
}
}while(query->next());

/*:699*/
#line 14770 "./typica.w"

}
else if(currentElement.tagName()=="row")
{
/*700:*/
#line 14825 "./typica.w"

table->appendRows(1);
currentRow++;
rows++;
QDomNodeList rowChildren= currentElement.childNodes();
int currentColumn= 0;
for(int j= 0;j<rowChildren.count();j++)
{
QDomNode node;
QDomElement nodeElement;
node= rowChildren.at(j);
if(node.isElement())
{
nodeElement= node.toElement();
if(nodeElement.tagName()=="cell")
{
if(currentColumn==columns)
{
table->appendColumns(1);
columns++;
}
QTextTableCell cell= table->cellAt(currentRow,currentColumn);
cursor= cell.firstCursorPosition();
cursor.insertText(nodeElement.text());
currentColumn++;
}
}
}

/*:700*/
#line 14774 "./typica.w"

}
}
}

/*:698*/
#line 14719 "./typica.w"

if(rows> 1)
{
table->removeRows(0,1);
}
}

/*:695*/
#line 571 "./typica.w"

/*732:*/
#line 14931 "./typica.w"

FormArray::FormArray(QDomElement description):configuration(description),
maxwidth(-1),maxheight(-1)
{
setWidget(&itemContainer);
itemContainer.setLayout(&itemLayout);
}

/*:732*//*733:*/
#line 14948 "./typica.w"

void FormArray::addElements(int copies)
{
QStack<QWidget*> *widgetStack= new QStack<QWidget*> ;
QStack<QLayout*> *layoutStack= new QStack<QLayout*> ;
QWidget*widget;
for(int i= 0;i<copies;i++)
{
widget= new QWidget;
if(maxwidth> -1)
{
widget->setMaximumWidth(maxwidth);
}
if(maxheight> -1)
{
widget->setMaximumHeight(maxheight);
}
if(configuration.hasChildNodes())
{
widgetStack->push(widget);
populateWidget(configuration,widgetStack,layoutStack);
widgetStack->pop();
widget->setMinimumHeight(widget->sizeHint().height());
itemLayout.addWidget(widget);
if(widget->sizeHint().height()> maxheight&&maxheight> -1)
{
itemContainer.setMinimumHeight(maxheight*elements()+50);
}
else
{
itemContainer.setMinimumHeight(itemContainer.sizeHint().height()
+widget->sizeHint().height());
}
if(maxwidth> -1)
{
itemContainer.setMinimumWidth(maxwidth+50);
}
else
{
itemContainer.setMinimumWidth(widget->sizeHint().width()+50);
}
}
}
}

/*:733*//*734:*/
#line 14998 "./typica.w"

QWidget*FormArray::elementAt(int index)
{
if(index<itemLayout.count())
{
QLayoutItem*item= itemLayout.itemAt(index);
return item->widget();
}
else
{
return NULL;
}
}

/*:734*//*735:*/
#line 15015 "./typica.w"

void FormArray::removeAllElements()
{
while(itemLayout.count()> 0)
{
QLayoutItem*item;
item= itemLayout.itemAt(0);
item->widget()->hide();
itemLayout.removeWidget(item->widget());
}
itemContainer.setMinimumHeight(0);
}

/*:735*//*736:*/
#line 15031 "./typica.w"

int FormArray::elements()
{
return itemLayout.count();
}

/*:736*//*737:*/
#line 15042 "./typica.w"

void FormArray::setMaximumElementWidth(int width)
{
maxwidth= width;
}

void FormArray::setMaximumElementHeight(int height)
{
maxheight= height;
}

/*:737*/
#line 572 "./typica.w"

/*743:*/
#line 15173 "./typica.w"

ScaleControl::ScaleControl():QGraphicsView(NULL,NULL),nonScoredValue(-1),
scoredValue(-1),initialSet(false),finalSet(false),scaleDown(false)
{
left<<QPointF(0,5)<<QPointF(10,0)<<QPointF(10,10)<<
QPointF(0,5);
right<<QPointF(10,5)<<QPointF(0,0)<<QPointF(0,10)<<
QPointF(10,5);
down<<QPointF(0,0)<<QPointF(-5,-10)<<QPointF(5,-10)<<
QPointF(0,0);
up<<QPointF(0,0)<<QPointF(-5,10)<<QPointF(4,10)<<QPointF(0,0);
initialBrush.setColor(QColor(170,170,255));
initialBrush.setStyle(Qt::SolidPattern);
finalBrush.setColor(Qt::blue);
finalBrush.setStyle(Qt::SolidPattern);
initialDecrement.setPolygon(left);
initialDecrement.setBrush(initialBrush);
initialDecrement.setPos(0,0);
scene.addItem(&initialDecrement);
initialIncrement.setPolygon(right);
initialIncrement.setBrush(initialBrush);
initialIncrement.setPos(122,0);
scene.addItem(&initialIncrement);
finalDecrement.setPolygon(left);
finalDecrement.setBrush(finalBrush);
finalDecrement.setPos(0,12);
scene.addItem(&finalDecrement);
finalIncrement.setPolygon(right);
finalIncrement.setBrush(finalBrush);
finalIncrement.setPos(122,12);
scene.addItem(&finalIncrement);
scalePath.moveTo(0,10);
scalePath.lineTo(100,10);
scalePath.moveTo(0,0);
scalePath.lineTo(0,20);
scalePath.moveTo(10,5);
scalePath.lineTo(10,15);
scalePath.moveTo(20,5);
scalePath.lineTo(20,15);
scalePath.moveTo(30,5);
scalePath.lineTo(30,15);
scalePath.moveTo(40,5);
scalePath.lineTo(40,15);
scalePath.moveTo(50,0);
scalePath.lineTo(50,20);
scalePath.moveTo(60,5);
scalePath.lineTo(60,15);
scalePath.moveTo(70,5);
scalePath.lineTo(70,15);
scalePath.moveTo(80,5);
scalePath.lineTo(80,15);
scalePath.moveTo(90,5);
scalePath.lineTo(90,15);
scalePath.moveTo(100,0);
scalePath.lineTo(100,20);
scaleLine.setPath(scalePath);
scaleLine.setPos(16,1);
scene.addItem(&scaleLine);
setScene(&scene);
initialIndicator.setPolygon(down);
initialIndicator.setBrush(initialBrush);
finalIndicator.setPolygon(up);
finalIndicator.setBrush(finalBrush);
setMinimumSize(sizeHint());
setMaximumSize(sizeHint());
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setMinimumSize(sizeHint());
}

/*:743*//*744:*/
#line 15246 "./typica.w"

QSize ScaleControl::sizeHint()const
{
return QSize(140,30);
}

/*:744*//*745:*/
#line 15255 "./typica.w"

void ScaleControl::setInitialValue(double value)
{
if(value>=0&&value<=10)
{
nonScoredValue= value;
if(!initialSet)
{
scene.addItem(&initialIndicator);
}
initialSet= true;
initialIndicator.setPos(value*10+16,10);
emit initialChanged(value);
if(!finalSet)
{
setFinalValue(value);
}
}
}

void ScaleControl::setFinalValue(double value)
{
if(value>=0&&value<=10)
{
scoredValue= value;
if(!finalSet)
{
scene.addItem(&finalIndicator);
}
finalSet= true;
finalIndicator.setPos(value*10+16,11);
emit finalChanged(value);
}
}

/*:745*//*746:*/
#line 15292 "./typica.w"

double ScaleControl::initialValue(void)
{
return nonScoredValue;
}

double ScaleControl::finalValue(void)
{
return scoredValue;
}

/*:746*//*747:*/
#line 15313 "./typica.w"

void ScaleControl::mousePressEvent(QMouseEvent*event)
{
/*748:*/
#line 15325 "./typica.w"

if(event->button()!=Qt::LeftButton)
{
event->ignore();
return;
}

/*:748*/
#line 15316 "./typica.w"

scaleDown= true;
event->accept();
}

/*:747*//*749:*/
#line 15336 "./typica.w"

void ScaleControl::mouseReleaseEvent(QMouseEvent*event)
{
/*748:*/
#line 15325 "./typica.w"

if(event->button()!=Qt::LeftButton)
{
event->ignore();
return;
}

/*:748*/
#line 15339 "./typica.w"

if(!scaleDown)
{
event->ignore();
return;
}
scaleDown= false;
QPointF sceneCoordinate= mapToScene(event->x(),event->y());
/*750:*/
#line 15361 "./typica.w"

if(sceneCoordinate.x()>=0&&sceneCoordinate.x()<=10)
{
if(sceneCoordinate.y()>=0&&sceneCoordinate.y()<=10)
{
if(initialSet)
{
setInitialValue(nonScoredValue-0.05);
}
event->accept();
return;
}
else if(sceneCoordinate.y()>=12&&sceneCoordinate.y()<=22)
{
if(finalSet)
{
setFinalValue(scoredValue-0.05);
event->accept();
return;
}
}
}

/*:750*/
#line 15347 "./typica.w"

/*751:*/
#line 15387 "./typica.w"

else if(sceneCoordinate.x()>=122&&sceneCoordinate.x()<=132)
{
if(sceneCoordinate.y()>=0&&sceneCoordinate.y()<=10)
{
if(initialSet)
{
setInitialValue(nonScoredValue+0.05);
event->accept();
return;
}
}
else if(sceneCoordinate.y()>=12&&sceneCoordinate.y()<=22)
{
if(finalSet)
{
setFinalValue(scoredValue+0.05);
event->accept();
return;
}
}
}

/*:751*/
#line 15348 "./typica.w"

/*752:*/
#line 15413 "./typica.w"

double relativeX= sceneCoordinate.x()-16;
if(initialSet)
{
if(relativeX>=0&&relativeX<=100)
{
setFinalValue(relativeX/10.0);
event->accept();
return;
}
}
else
{
if(relativeX>=0&&relativeX<=100)
{
setInitialValue(relativeX/10.0);
event->accept();
return;
}
}

/*:752*/
#line 15349 "./typica.w"

event->ignore();
return;
}

/*:749*/
#line 573 "./typica.w"

/*754:*/
#line 15479 "./typica.w"

IntensityControl::IntensityControl():QGraphicsView(NULL,NULL),theValue(-1),
valueSet(false),scaleDown(false)
{
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
left<<QPointF(0,0)<<QPointF(10,-5)<<QPointF(10,5)<<QPointF(0,0);
down<<QPointF(0,0)<<QPointF(10,0)<<QPointF(5,10)<<QPointF(0,0);
up<<QPointF(0,10)<<QPointF(10,10)<<QPointF(5,0)<<QPointF(0,10);
theBrush.setColor(Qt::blue);
theBrush.setStyle(Qt::SolidPattern);
increment.setPolygon(up);
increment.setBrush(theBrush);
increment.setPos(0,0);
scene.addItem(&increment);
decrement.setPolygon(down);
decrement.setBrush(theBrush);
decrement.setPos(0,122);
scene.addItem(&decrement);
scalePath.moveTo(5,0);
scalePath.lineTo(5,100);
scalePath.moveTo(0,0);
scalePath.lineTo(10,0);
scalePath.moveTo(0,10);
scalePath.lineTo(10,10);
scalePath.moveTo(0,20);
scalePath.lineTo(10,20);
scalePath.moveTo(0,30);
scalePath.lineTo(10,30);
scalePath.moveTo(0,40);
scalePath.lineTo(10,40);
scalePath.moveTo(0,50);
scalePath.lineTo(10,50);
scalePath.moveTo(0,60);
scalePath.lineTo(10,60);
scalePath.moveTo(0,70);
scalePath.lineTo(10,70);
scalePath.moveTo(0,80);
scalePath.lineTo(10,80);
scalePath.moveTo(0,90);
scalePath.lineTo(10,90);
scalePath.moveTo(0,100);
scalePath.lineTo(10,100);
scaleLine.setPath(scalePath);
scaleLine.setPos(0,16);
scene.addItem(&scaleLine);
setScene(&scene);
indicator.setPolygon(left);
indicator.setBrush(theBrush);
setMinimumSize(sizeHint());
setMaximumSize(sizeHint());
}

/*:754*//*755:*/
#line 15534 "./typica.w"

QSize IntensityControl::sizeHint()const
{
return QSize(25,160);
}

/*:755*//*756:*/
#line 15549 "./typica.w"

void IntensityControl::setValue(double val)
{
if(val>=0&&val<=10)
{
theValue= val;
if(!valueSet)
{
scene.addItem(&indicator);
}
valueSet= true;
indicator.setPos(6,(100-(val*10))+16);
emit(valueChanged(val));
}
else if(val<1)
{
setValue(0);
}
else
{
setValue(10);
}
}

double IntensityControl::value()
{
return theValue;
}

/*:756*//*757:*/
#line 15581 "./typica.w"

void IntensityControl::mousePressEvent(QMouseEvent*event)
{
/*748:*/
#line 15325 "./typica.w"

if(event->button()!=Qt::LeftButton)
{
event->ignore();
return;
}

/*:748*/
#line 15584 "./typica.w"

scaleDown= true;
event->accept();
}

/*:757*//*758:*/
#line 15595 "./typica.w"

void IntensityControl::mouseReleaseEvent(QMouseEvent*event)
{
/*748:*/
#line 15325 "./typica.w"

if(event->button()!=Qt::LeftButton)
{
event->ignore();
return;
}

/*:748*/
#line 15598 "./typica.w"

if(!scaleDown)
{
event->ignore();
return;
}
scaleDown= false;
QPointF sceneCoordinate= mapToScene(event->x(),event->y());
if(sceneCoordinate.x()>=0&&sceneCoordinate.x()<=16)
{
if(sceneCoordinate.y()>=0&&sceneCoordinate.y()<=10)
{
if(valueSet)
{
setValue(theValue+0.05);
}
event->accept();
return;
}
else if(sceneCoordinate.y()>=122&&sceneCoordinate.y()<=132)
{
if(valueSet)
{
setValue(theValue-0.05);
}
event->accept();
return;
}
else if(sceneCoordinate.y()>=16&&sceneCoordinate.y()<=116)
{
setValue(10-((sceneCoordinate.y()-16)/10.0));
event->accept();
return;
}
}
}

/*:758*/
#line 574 "./typica.w"

/*384:*/
#line 8593 "./typica.w"

void ThresholdDetector::newMeasurement(Measurement measure)
{
if((currentDirection==Ascending&&previousValue<threshold&&
previousValueValid)||(currentDirection==Descending&&
previousValue> threshold&&previousValueValid))
{
if((currentDirection==Ascending&&measure.temperature()>=threshold)||
(currentDirection==Descending&&measure.temperature()<=threshold))
{
double offset= measure.time().hour()*60*60;
offset+= measure.time().minute()*60;
offset+= measure.time().second();
offset+= measure.time().msec()/1000;
emit timeForValue(offset);
}
}
previousValue= measure.temperature();
previousValueValid= true;
}

ThresholdDetector::ThresholdDetector(double value):QObject(NULL),
previousValueValid(false),
previousValue(-1),threshold(value),currentDirection(Ascending)
{

}

void ThresholdDetector::setThreshold(double value)
{
threshold= value;
}

void ThresholdDetector::setEdgeDirection(EdgeDirection direction)
{
currentDirection= direction;
}

/*:384*/
#line 575 "./typica.w"

/*840:*/
#line 17487 "./typica.w"

PortSelector::PortSelector(QWidget*parent):QComboBox(parent),
lister(new QextSerialEnumerator)
{
QList<QextPortInfo> ports= QextSerialEnumerator::getPorts();
QextPortInfo port;
foreach(port,ports)
{
#ifdef Q_OS_WIN32
addItem(port.portName);
#else
addItem(port.physName);
#endif
}
lister->setUpNotifications();
connect(lister,SIGNAL(deviceDiscovered(QextPortInfo)),
this,SLOT(addDevice(QextPortInfo)));
setEditable(true);
}

void PortSelector::addDevice(QextPortInfo port)
{
addItem(port.portName);
}

/*:840*/
#line 576 "./typica.w"

/*842:*/
#line 17579 "./typica.w"

BaudSelector::BaudSelector(QWidget*parent):QComboBox(parent)
{
QMetaObject meta= BaudSelector::staticMetaObject;
QMetaEnum type= meta.enumerator(meta.indexOfEnumerator("BaudRateType"));
for(int i= 0;i<type.keyCount();i++)
{
addItem(QString("%1").arg(type.value(i)));
}
}

/*:842*/
#line 577 "./typica.w"

/*844:*/
#line 17617 "./typica.w"

ParitySelector::ParitySelector(QWidget*parent):QComboBox(parent)
{
QMetaObject meta= ParitySelector::staticMetaObject;
QMetaEnum type= meta.enumerator(meta.indexOfEnumerator("ParityType"));
for(int i= 0;i<type.keyCount();i++)
{
addItem(QString(type.key(i)),QVariant(type.value(i)));
}
}

/*:844*/
#line 578 "./typica.w"

/*846:*/
#line 17647 "./typica.w"

FlowSelector::FlowSelector(QWidget*parent):QComboBox(parent)
{
QMetaObject meta= FlowSelector::staticMetaObject;
QMetaEnum type= meta.enumerator(meta.indexOfEnumerator("FlowType"));
for(int i= 0;i<type.keyCount();i++)
{
addItem(QString(type.key(i)),QVariant(type.value(i)));
}
}

/*:846*/
#line 579 "./typica.w"

/*848:*/
#line 17682 "./typica.w"

StopSelector::StopSelector(QWidget*parent):QComboBox(parent)
{
QMetaObject meta= StopSelector::staticMetaObject;
QMetaEnum type= meta.enumerator(meta.indexOfEnumerator("StopBitsType"));
for(int i= 0;i<type.keyCount();i++)
{
addItem(QString(type.key(i)),QVariant(type.value(i)));
}
}

/*:848*/
#line 580 "./typica.w"

/*912:*/
#line 19464 "./typica.w"

ModbusConfigurator::ModbusConfigurator(DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
port(new PortSelector),baud(new BaudSelector),parity(new ParitySelector),
flow(new FlowSelector),stop(new StopSelector),station(new QSpinBox),
decimalQuery(new QCheckBox(tr("Enable"))),
decimalAddress(new ShortHexSpinBox),decimalPosition(new QSpinBox),
unitQuery(new QCheckBox(tr("Enable"))),
unitAddress(new ShortHexSpinBox),valueF(new QSpinBox),
valueC(new QSpinBox),fixedUnit(new QComboBox),
pVAddress(new ShortHexSpinBox),
sVEnabled(new QCheckBox(tr("Enable"))),
sVReadAddress(new ShortHexSpinBox),
deviceLimit(new QCheckBox(tr("Enable"))),
sVLowerAddr(new ShortHexSpinBox),sVUpperAddr(new ShortHexSpinBox),
sVLower(new QDoubleSpinBox),sVUpper(new QDoubleSpinBox),
sVWritable(new QCheckBox(tr("Enable"))),
sVOutputAddr(new ShortHexSpinBox),
pVColumnName(new QLineEdit),sVColumnName(new QLineEdit)
{
QHBoxLayout*layout= new QHBoxLayout;
QWidget*form= new QWidget;
QHBoxLayout*masterLayout= new QHBoxLayout;
QVBoxLayout*portAndDeviceLayout= new QVBoxLayout;
QVBoxLayout*seriesLayout= new QVBoxLayout;
QFormLayout*serialSection= new QFormLayout;
serialSection->addRow(QString(tr("Port:")),port);
serialSection->addRow(QString(tr("Baud rate:")),baud);
serialSection->addRow(QString(tr("Parity:")),parity);
serialSection->addRow(QString(tr("Flow control:")),flow);
serialSection->addRow(QString(tr("Stop bits:")),stop);
QGroupBox*serialSectionBox= new QGroupBox(tr("Serial Port Configuration"));
serialSectionBox->setLayout(serialSection);
portAndDeviceLayout->addWidget(serialSectionBox);
QFormLayout*deviceSection= new QFormLayout;
station->setMinimum(1);
station->setMaximum(255);
decimalPosition->setMinimum(0);
decimalPosition->setMaximum(9);
valueF->setMinimum(0);
valueF->setMaximum(0xFFFF);
valueC->setMinimum(0);
valueC->setMaximum(0xFFFF);
fixedUnit->addItem(tr("Fahrenheit"),QVariant(QString("F")));
fixedUnit->addItem(tr("Celsius"),QVariant(QString("C")));
deviceSection->addRow(tr("Station:"),station);
deviceSection->addRow(tr("Decimal position from device:"),decimalQuery);
deviceSection->addRow(tr("Decimal position relative address:"),decimalAddress);
deviceSection->addRow(tr("Fixed decimal position:"),decimalPosition);
deviceSection->addRow(tr("Measurement unit from device:"),unitQuery);
deviceSection->addRow(tr("Current unit relative address:"),unitAddress);
deviceSection->addRow(tr("Value for Fahrenheit:"),valueF);
deviceSection->addRow(tr("Value for Celsius:"),valueC);
deviceSection->addRow(tr("Fixed unit:"),fixedUnit);
QGroupBox*deviceSectionBox= new QGroupBox(tr("Device Configuration"));
deviceSectionBox->setLayout(deviceSection);
portAndDeviceLayout->addWidget(deviceSectionBox);
QFormLayout*pVSection= new QFormLayout;
pVSection->addRow(tr("Value relative address:"),pVAddress);
pVSection->addRow(tr("PV column name:"),pVColumnName);
QCheckBox*pVHideBox= new QCheckBox(tr("Hide this channel"));
pVSection->addRow(pVHideBox);
QGroupBox*processValueBox= new QGroupBox(tr("Process Value"));
processValueBox->setLayout(pVSection);
seriesLayout->addWidget(processValueBox);
QFormLayout*sVSection= new QFormLayout;
sVLower->setDecimals(1);
sVLower->setMinimum(0.0);
sVLower->setMaximum(999.9);
sVUpper->setDecimals(1);
sVUpper->setMinimum(0.0);
sVUpper->setMaximum(999.9);
sVSection->addRow(tr("Set value:"),sVEnabled);
sVSection->addRow(tr("Read relative address:"),sVReadAddress);
sVSection->addRow(tr("SV column name:"),sVColumnName);
sVSection->addRow(tr("Limits from device:"),deviceLimit);
sVSection->addRow(tr("Lower limit relative address:"),sVLowerAddr);
sVSection->addRow(tr("Upper limit relative address:"),sVUpperAddr);
sVSection->addRow(tr("Lower limit:"),sVLower);
sVSection->addRow(tr("Upper limit:"),sVUpper);
sVSection->addRow(tr("Output set value:"),sVWritable);
sVSection->addRow(tr("Output relative address:"),sVOutputAddr);
QCheckBox*sVHideBox= new QCheckBox(tr("Hide this channel"));
sVSection->addRow(sVHideBox);
QGroupBox*setValueBox= new QGroupBox(tr("Set Value"));
setValueBox->setLayout(sVSection);
seriesLayout->addWidget(setValueBox);
masterLayout->addLayout(portAndDeviceLayout);
masterLayout->addLayout(seriesLayout);
form->setLayout(masterLayout);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 19554 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="port")
{
QString portname= node.attribute("value");
int idx= port->findText(portname);
if(idx>=0)
{
port->setCurrentIndex(idx);
}
else
{
port->addItem(portname);
}
}
else if(node.attribute("name")=="baud")
{
baud->setCurrentIndex(baud->findText(node.attribute("value")));
}
else if(node.attribute("name")=="parity")
{
parity->setCurrentIndex(parity->findData(node.attribute("value")));
}
else if(node.attribute("name")=="flow")
{
flow->setCurrentIndex(flow->findData(node.attribute("value")));
}
else if(node.attribute("name")=="stop")
{
stop->setCurrentIndex(stop->findData(node.attribute("value")));
}
else if(node.attribute("name")=="station")
{
station->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="decimalQuery")
{
if(node.attribute("value")=="true")
{
decimalQuery->setChecked(true);
}
else
{
decimalQuery->setChecked(false);
}
}
else if(node.attribute("name")=="decimalAddress")
{
decimalAddress->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="decimalPosition")
{
decimalPosition->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="unitQuery")
{
if(node.attribute("value")=="true")
{
unitQuery->setChecked(true);
}
else
{
unitQuery->setChecked(false);
}
}
else if(node.attribute("name")=="unitAddress")
{
unitAddress->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="valueF")
{
valueF->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="valueC")
{
valueC->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="fixedUnit")
{
fixedUnit->setCurrentIndex(fixedUnit->findText(node.attribute("value")));
}
else if(node.attribute("name")=="pVAddress")
{
pVAddress->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="sVEnabled")
{
if(node.attribute("value")=="true")
{
sVEnabled->setChecked(true);
}
else
{
sVEnabled->setChecked(false);
}
}
else if(node.attribute("name")=="sVReadAddress")
{
sVReadAddress->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="deviceLimit")
{
if(node.attribute("value")=="true")
{
deviceLimit->setChecked(true);
}
else
{
deviceLimit->setChecked(false);
}
}
else if(node.attribute("name")=="sVLowerAddr")
{
sVLowerAddr->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="sVUpperAddr")
{
sVUpperAddr->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="sVLower")
{
sVLower->setValue(node.attribute("value").toDouble());
}
else if(node.attribute("name")=="sVUpper")
{
sVUpper->setValue(node.attribute("value").toDouble());
}
else if(node.attribute("name")=="sVWritable")
{
if(node.attribute("value")=="true")
{
sVWritable->setChecked(true);
}
else
{
sVWritable->setChecked(false);
}
}
else if(node.attribute("name")=="sVOutputAddr")
{
sVOutputAddr->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="pvcolname")
{
pVColumnName->setText(node.attribute("value"));
}
else if(node.attribute("name")=="svcolname")
{
sVColumnName->setText(node.attribute("value"));
}
else if(node.attribute("name")=="pvhidden")
{
pVHideBox->setChecked(node.attribute("value")=="true");
}
else if(node.attribute("name")=="svhidden")
{
sVHideBox->setChecked(node.attribute("value")=="true");
}
}
updatePort(port->currentText());
updateBaudRate(baud->currentText());
updateParity(parity->itemData(parity->currentIndex()).toString());
updateFlowControl(flow->itemData(flow->currentIndex()).toString());
updateStopBits(stop->itemData(stop->currentIndex()).toString());
updateStation(station->value());
updateFixedDecimal(decimalQuery->isChecked());
updateDecimalAddress(decimalAddress->value());
updateDecimalPosition(decimalPosition->value());
updateFixedUnit(unitQuery->isChecked());
updateUnitAddress(unitAddress->value());
updateValueForF(valueF->value());
updateValueForC(valueC->value());
updateUnit(fixedUnit->currentText());
updatePVAddress(pVAddress->value());
updateSVEnabled(sVEnabled->isChecked());
updateSVReadAddress(sVReadAddress->value());
updateDeviceLimit(deviceLimit->isChecked());
updateSVLowerAddress(sVLowerAddr->value());
updateSVUpperAddress(sVUpperAddr->value());
updateSVLower(sVLower->value());
updateSVUpper(sVUpper->value());
updateSVWritable(sVWritable->isChecked());
updateSVWriteAddress(sVOutputAddr->value());
updatePVColumnName(pVColumnName->text());
updateSVColumnName(sVColumnName->text());
updatePVHidden(pVHideBox->isChecked());
updateSVHidden(sVHideBox->isChecked());
connect(port,SIGNAL(currentIndexChanged(QString)),this,SLOT(updatePort(QString)));
connect(port,SIGNAL(editTextChanged(QString)),this,SLOT(updatePort(QString)));
connect(baud,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateBaudRate(QString)));
connect(parity,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateParity(QString)));
connect(flow,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateFlowControl(QString)));
connect(stop,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateStopBits(QString)));
connect(station,SIGNAL(valueChanged(int)),this,SLOT(updateStation(int)));
connect(decimalQuery,SIGNAL(toggled(bool)),this,SLOT(updateFixedDecimal(bool)));
connect(decimalAddress,SIGNAL(valueChanged(int)),this,SLOT(updateDecimalAddress(int)));
connect(decimalPosition,SIGNAL(valueChanged(int)),this,SLOT(updateDecimalPosition(int)));
connect(unitQuery,SIGNAL(toggled(bool)),this,SLOT(updateFixedUnit(bool)));
connect(unitAddress,SIGNAL(valueChanged(int)),this,SLOT(updateUnitAddress(int)));
connect(valueF,SIGNAL(valueChanged(int)),this,SLOT(updateValueForF(int)));
connect(valueC,SIGNAL(valueChanged(int)),this,SLOT(updateValueForC(int)));
connect(fixedUnit,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateUnit(QString)));
connect(pVAddress,SIGNAL(valueChanged(int)),this,SLOT(updatePVAddress(int)));
connect(sVEnabled,SIGNAL(toggled(bool)),this,SLOT(updateSVEnabled(bool)));
connect(sVReadAddress,SIGNAL(valueChanged(int)),this,SLOT(updateSVReadAddress(int)));
connect(deviceLimit,SIGNAL(toggled(bool)),this,SLOT(updateDeviceLimit(bool)));
connect(sVLowerAddr,SIGNAL(valueChanged(int)),this,SLOT(updateSVLowerAddress(int)));
connect(sVUpperAddr,SIGNAL(valueChanged(int)),this,SLOT(updateSVUpperAddress(int)));
connect(sVLower,SIGNAL(valueChanged(double)),this,SLOT(updateSVLower(double)));
connect(sVUpper,SIGNAL(valueChanged(double)),this,SLOT(updateSVUpper(double)));
connect(sVWritable,SIGNAL(toggled(bool)),this,SLOT(updateSVWritable(bool)));
connect(sVOutputAddr,SIGNAL(valueChanged(int)),this,SLOT(updateSVWriteAddress(int)));
connect(pVColumnName,SIGNAL(textEdited(QString)),this,SLOT(updatePVColumnName(QString)));
connect(sVColumnName,SIGNAL(textEdited(QString)),this,SLOT(updateSVColumnName(QString)));
connect(pVHideBox,SIGNAL(toggled(bool)),this,SLOT(updatePVHidden(bool)));
connect(sVHideBox,SIGNAL(toggled(bool)),this,SLOT(updateSVHidden(bool)));
layout->addWidget(form);
setLayout(layout);
}

void ModbusConfigurator::updatePort(const QString&newPort)
{
updateAttribute("port",newPort);
}

void ModbusConfigurator::updateBaudRate(const QString&newRate)
{
updateAttribute("baud",newRate);
}

void ModbusConfigurator::updateParity(const QString&)
{
updateAttribute("parity",parity->itemData(parity->currentIndex()).toString());
}

void ModbusConfigurator::updateFlowControl(const QString&)
{
updateAttribute("flow",flow->itemData(flow->currentIndex()).toString());
}

void ModbusConfigurator::updateStopBits(const QString&)
{
updateAttribute("stop",stop->itemData(stop->currentIndex()).toString());
}

void ModbusConfigurator::updateStation(int station)
{
updateAttribute("station",QString("%1").arg(station));
}

void ModbusConfigurator::updateFixedDecimal(bool fixed)
{
updateAttribute("decimalQuery",fixed?"true":"false");
}

void ModbusConfigurator::updateDecimalAddress(int address)
{
updateAttribute("decimalAddress",QString("%1").arg(address));
}

void ModbusConfigurator::updateDecimalPosition(int position)
{
updateAttribute("decimalPosition",QString("%1").arg(position));
}

void ModbusConfigurator::updateFixedUnit(bool fixed)
{
updateAttribute("unitQuery",fixed?"true":"false");
}

void ModbusConfigurator::updateUnitAddress(int address)
{
updateAttribute("unitAddress",QString("%1").arg(address));
}

void ModbusConfigurator::updateValueForF(int value)
{
updateAttribute("valueF",QString("%1").arg(value));
}

void ModbusConfigurator::updateValueForC(int value)
{
updateAttribute("valueC",QString("%1").arg(value));
}

void ModbusConfigurator::updateUnit(const QString&newUnit)
{
updateAttribute("fixedUnit",newUnit);
}

void ModbusConfigurator::updatePVAddress(int address)
{
updateAttribute("pVAddress",QString("%1").arg(address));
}

void ModbusConfigurator::updateSVEnabled(bool enabled)
{
updateAttribute("sVEnabled",enabled?"true":"false");
}

void ModbusConfigurator::updateSVReadAddress(int address)
{
updateAttribute("sVReadAddress",QString("%1").arg(address));
}

void ModbusConfigurator::updateDeviceLimit(bool query)
{
updateAttribute("deviceLimit",query?"true":"false");
}

void ModbusConfigurator::updateSVLowerAddress(int address)
{
updateAttribute("sVLowerAddr",QString("%1").arg(address));
}

void ModbusConfigurator::updateSVUpperAddress(int address)
{
updateAttribute("sVUpperAddr",QString("%1").arg(address));
}

void ModbusConfigurator::updateSVLower(double value)
{
updateAttribute("sVLower",QString("%1").arg(value));
}

void ModbusConfigurator::updateSVUpper(double value)
{
updateAttribute("sVUpper",QString("%1").arg(value));
}

void ModbusConfigurator::updateSVWritable(bool canWriteSV)
{
updateAttribute("sVWritable",canWriteSV?"true":"false");
}

void ModbusConfigurator::updateSVWriteAddress(int address)
{
updateAttribute("sVOutputAddr",QString("%1").arg(address));
}

void ModbusConfigurator::updatePVColumnName(const QString&name)
{
updateAttribute("pvcolname",name);
}

void ModbusConfigurator::updateSVColumnName(const QString&name)
{
updateAttribute("svcolname",name);
}

void ModbusConfigurator::updatePVHidden(bool hidden)
{
updateAttribute("pvhidden",hidden?"true":"false");
}

void ModbusConfigurator::updateSVHidden(bool hidden)
{
updateAttribute("svhidden",hidden?"true":"false");
}

/*:912*/
#line 581 "./typica.w"

/*851:*/
#line 17735 "./typica.w"

ShortHexSpinBox::ShortHexSpinBox(QWidget*parent):QSpinBox(parent)
{
setMinimum(0);
setMaximum(0xFFFF);
setPrefix("0x");
setMinimumWidth(65);
}

QValidator::State ShortHexSpinBox::validate(QString&input,int&)const
{
if(input.size()==2)
{
return QValidator::Intermediate;
}
bool okay;
input.toInt(&okay,16);
if(okay)
{
return QValidator::Acceptable;
}
return QValidator::Invalid;
}

int ShortHexSpinBox::valueFromText(const QString&text)const
{
return text.toInt(NULL,16);
}

QString ShortHexSpinBox::textFromValue(int value)const
{
QString retval;
retval.setNum(value,16);
while(retval.size()<4)
{
retval.prepend("0");
}
return retval.toUpper();
}

/*:851*/
#line 582 "./typica.w"

/*896:*/
#line 18768 "./typica.w"

ModbusRTUDevice::ModbusRTUDevice(DeviceTreeModel*model,const QModelIndex&index)
:QObject(NULL),messageDelayTimer(new QTimer),commTimeout(new QTimer),unitIsF(true),readingsv(false),
waiting(false)
{
QDomElement portReferenceElement= model->referenceElement(model->data(index,
Qt::UserRole).toString());
QDomNodeList portConfigData= portReferenceElement.elementsByTagName("attribute");
QDomElement node;
QVariantMap attributes;
for(int i= 0;i<portConfigData.size();i++)
{
node= portConfigData.at(i).toElement();
attributes.insert(node.attribute("name"),node.attribute("value"));
}
port= new QextSerialPort(attributes.value("port").toString(),
QextSerialPort::EventDriven);
int baudRate= attributes.value("baud").toInt();
port->setBaudRate((BaudRateType)baudRate);
double temp= ((double)(1)/(double)(baudRate))*48;
delayTime= (int)(temp*3000);
messageDelayTimer->setSingleShot(true);
commTimeout->setSingleShot(true);
connect(messageDelayTimer,SIGNAL(timeout()),this,SLOT(sendNextMessage()));
connect(commTimeout,SIGNAL(timeout()),this,SLOT(timeout()));
port->setDataBits(DATA_8);
port->setParity((ParityType)attributes.value("parity").toInt());
port->setStopBits((StopBitsType)attributes.value("stop").toInt());
port->setFlowControl((FlowType)attributes.value("flow").toInt());
connect(port,SIGNAL(readyRead()),this,SLOT(dataAvailable()));
port->open(QIODevice::ReadWrite);
station= (char)attributes.value("station").toInt();
if(attributes.value("decimalQuery")=="true")
{
decimalPosition= 0;
QByteArray message;
message.append(station);
message.append((char)0x03);
quint16 address= (quint16)attributes.value("decimalAddress").toInt();
char*addressBytes= (char*)&address;
message.append(addressBytes[1]);
message.append(addressBytes[0]);
message.append((char)0x00);
message.append((char)0x01);
queueMessage(message,this,"decimalResponse(QByteArray)");
}
else
{
decimalPosition= attributes.value("decimalPosition").toInt();
}
valueF= attributes.value("valueF").toInt();
valueC= attributes.value("valueC").toInt();
if(attributes.value("unitQuery")=="true")
{
QByteArray message;
message.append(station);
message.append((char)0x03);
quint16 address= (quint16)attributes.value("unitAddress").toInt();
char*addressBytes= (char*)&address;
message.append(addressBytes[1]);
message.append(addressBytes[0]);
message.append((char)0x00);
message.append((char)0x01);
queueMessage(message,this,"unitResponse(QByteArray)");
}
else
{
if(attributes.value("fixedUnit")=="Celsius")
{
unitIsF= false;
}
}
if(attributes.value("sVWritable")=="true")
{
if(attributes.value("deviceLimit")=="true")
{
QByteArray lmessage;
lmessage.append(station);
lmessage.append((char)0x03);
quint16 laddress= (quint16)attributes.value("sVLowerAddr").toInt();
char*addressBytes= (char*)&laddress;
lmessage.append(addressBytes[1]);
lmessage.append(addressBytes[0]);
lmessage.append((char)0x00);
lmessage.append((char)0x01);
queueMessage(lmessage,this,"svlResponse(QByteArray)");
QByteArray umessage;
umessage.append(station);
umessage.append((char)0x03);
quint16 uaddress= (quint16)attributes.value("sVUpperAddr").toInt();
addressBytes= (char*)&uaddress;
umessage.append(addressBytes[1]);
umessage.append(addressBytes[0]);
umessage.append((char)0x00);
umessage.append((char)0x01);
queueMessage(umessage,this,"svuResponse(QByteArray)");
}
else
{
outputSVLower= attributes.value("sVLower").toDouble();
outputSVUpper= attributes.value("sVUpper").toDouble();
}
outputSVStub.append(station);
outputSVStub.append((char)0x06);
quint16 address= (quint16)attributes.value("sVOutputAddr").toInt();
char*addressBytes= (char*)&address;
outputSVStub.append(addressBytes[1]);
outputSVStub.append(addressBytes[0]);
}
Channel*pv= new Channel;
channels.append(pv);
pvStub.append(station);
pvStub.append((char)0x04);
pvaddress= (quint16)attributes.value("pVAddress").toInt();
char*pvac= (char*)&pvaddress;
pvStub.append(pvac[1]);
pvStub.append(pvac[0]);
pvStub.append((char)0x00);
pvStub.append((char)0x01);
svenabled= attributes.value("sVEnabled").toBool();
if(svenabled)
{
Channel*sv= new Channel;
channels.append(sv);
svStub.append(station);
svStub.append((char)0x04);
svaddress= (quint16)attributes.value("sVReadAddress").toInt();
char*svac= (char*)&svaddress;
svStub.append(svac[1]);
svStub.append(svac[0]);
svStub.append((char)0x00);
svStub.append((char)0x01);
if(svaddress-pvaddress==1)
{
mStub.append(station);
mStub.append((char)0x04);
mStub.append(pvac[1]);
mStub.append(pvac[0]);
mStub.append((char)0x00);
mStub.append((char)0x02);
}
}
connect(this,SIGNAL(queueEmpty()),this,SLOT(requestMeasurement()));
requestMeasurement();
}

double ModbusRTUDevice::SVLower()
{
return outputSVLower;
}

double ModbusRTUDevice::SVUpper()
{
return outputSVUpper;
}

int ModbusRTUDevice::decimals()
{
return decimalPosition;
}

void ModbusRTUDevice::decimalResponse(QByteArray response)
{
quint16 temp;
char*tchar= (char*)&temp;
tchar[1]= response.at(3);
tchar[0]= response.at(4);
decimalPosition= temp;
emit SVDecimalChanged(decimalPosition);
}

void ModbusRTUDevice::unitResponse(QByteArray response)
{
quint16 temp;
char*tchar= (char*)&temp;
tchar[1]= response.at(3);
tchar[0]= response.at(4);
int value= temp;
if(value==valueF)
{
unitIsF= true;
}
else
{
unitIsF= false;
}
}

void ModbusRTUDevice::svlResponse(QByteArray response)
{
quint16 temp;
char*tchar= (char*)&temp;
tchar[1]= response.at(3);
tchar[0]= response.at(4);
outputSVLower= (double)temp;
for(int i= 0;i<decimalPosition;i++)
{
outputSVLower/= 10;
}
emit SVLowerChanged(outputSVLower);
}

void ModbusRTUDevice::svuResponse(QByteArray response)
{
quint16 temp;
char*tchar= (char*)&temp;
tchar[1]= response.at(3);
tchar[0]= response.at(4);
outputSVUpper= (double)temp;
for(int i= 0;i<decimalPosition;i++)
{
outputSVUpper/= 10;
}
emit SVUpperChanged(outputSVUpper);
}

void ModbusRTUDevice::requestMeasurement()
{
if(mStub.length()> 0)
{
queueMessage(mStub,this,"mResponse(QByteArray)");
}
else
{
queueMessage(pvStub,this,"mResponse(QByteArray)");
if(svenabled)
{
queueMessage(svStub,this,"mResponse(QByteArray)");
}
}
}

void ModbusRTUDevice::mResponse(QByteArray response)
{
QTime time= QTime::currentTime();
if(response.at(2)==0x04)
{
/*897:*/
#line 19018 "./typica.w"

quint16 pv;
quint16 sv;
char*pvBytes= (char*)&pv;
char*svBytes= (char*)&sv;
pvBytes[1]= response.at(3);
pvBytes[0]= response.at(4);
svBytes[1]= response.at(5);
svBytes[0]= response.at(6);
double pvOut= (double)pv;
double svOut= (double)sv;
for(int i= 0;i<decimalPosition;i++)
{
pvOut/= 10;
svOut/= 10;
}
if(!unitIsF)
{
pvOut= pvOut*9/5+32;
svOut= svOut*9/5+32;
}
Measurement pvm(pvOut,time,Units::Fahrenheit);
Measurement svm(svOut,time,Units::Fahrenheit);
channels.at(0)->input(pvm);
channels.at(1)->input(svm);

/*:897*/
#line 19005 "./typica.w"

}
else
{
/*898:*/
#line 19048 "./typica.w"

quint16 value;
char*valueBytes= (char*)&value;
valueBytes[1]= response.at(3);
valueBytes[0]= response.at(4);
double valueOut= (double)value;
for(int i= 0;i<decimalPosition;i++)
{
valueOut/= 10;
}
if(!unitIsF)
{
valueOut= valueOut*9/5+32;
}
if(!svenabled)
{
Measurement vm(valueOut,time,Units::Fahrenheit);
channels.at(0)->input(vm);
}
else
{
if(readingsv)
{
Measurement pvm(savedpv,time,Units::Fahrenheit);
Measurement svm(valueOut,time,Units::Fahrenheit);
channels.at(0)->input(pvm);
channels.at(1)->input(svm);
readingsv= false;
}
else
{
savedpv= valueOut;
readingsv= true;
}
}

/*:898*/
#line 19009 "./typica.w"

}
}

/*:896*//*899:*/
#line 19086 "./typica.w"

ModbusRTUDevice::~ModbusRTUDevice()
{
commTimeout->stop();
messageDelayTimer->stop();
port->close();
}

/*:899*//*900:*/
#line 19113 "./typica.w"

void ModbusRTUDevice::dataAvailable()
{
if(messageDelayTimer->isActive())
{
messageDelayTimer->stop();
}
responseBuffer.append(port->readAll());
/*901:*/
#line 19159 "./typica.w"

if(responseBuffer.size()<5)
{
return;
}
switch(responseBuffer.at(1))
{
case 0x01:
case 0x02:
if(responseBuffer.size()<6)
{
return;
}
responseBuffer= responseBuffer.left(6);
break;
case 0x03:
case 0x04:
if(responseBuffer.size()<5+responseBuffer.at(2))
{
return;
}
responseBuffer= responseBuffer.left(5+responseBuffer.at(2));
break;
case 0x05:
case 0x06:
case 0x10:
if(responseBuffer.size()<8)
{
return;
}
responseBuffer= responseBuffer.left(8);
break;
}

/*:901*/
#line 19121 "./typica.w"

commTimeout->stop();
if(calculateCRC(responseBuffer)==0)
{
QObject*object= retObjQueue.at(0);
char*method= callbackQueue.at(0);
QMetaMethod metamethod= object->metaObject()->
method(object->metaObject()->
indexOfMethod(QMetaObject::normalizedSignature(method)));
metamethod.invoke(object,Qt::QueuedConnection,
Q_ARG(QByteArray,responseBuffer));
messageQueue.removeAt(0);
retObjQueue.removeAt(0);
callbackQueue.removeAt(0);
}
else
{
qDebug()<<"CRC failed";
}
messageDelayTimer->start(delayTime);
waiting= false;
responseBuffer.clear();
}

/*:900*//*902:*/
#line 19201 "./typica.w"

quint16 ModbusRTUDevice::calculateCRC(QByteArray data)
{
quint16 retval= 0xFFFF;
int i= 0;
while(i<data.size())
{
retval^= 0x00FF&(quint16)data.at(i);
for(int j= 0;j<8;j++)
{
if(retval&1)
{
retval= (retval>>1)^0xA001;
}
else
{
retval>>= 1;
}
}
i++;
}
return retval;
}

/*:902*//*903:*/
#line 19232 "./typica.w"

void ModbusRTUDevice::queueMessage(QByteArray request,QObject*object,
const char*callback)
{
messageQueue.append(request);
retObjQueue.append(object);
callbackQueue.append(const_cast<char*> (callback));
if(messageQueue.size()==1&&!(messageDelayTimer->isActive()))
{
sendNextMessage();
}
}

void ModbusRTUDevice::sendNextMessage()
{
if(messageQueue.size()> 0&&!waiting)
{
QByteArray message= messageQueue.at(0);
quint16 crc= calculateCRC(message);
char*check= (char*)&crc;
message.append(check[0]);
message.append(check[1]);
port->write(message);
commTimeout->start(2000);
messageDelayTimer->start(delayTime);
waiting= true;
}
else
{
emit queueEmpty();
}
}

void ModbusRTUDevice::outputSV(double value)
{
for(int i= 0;i<decimalPosition;i++)
{
value*= 10;
}
quint16 outval= (quint16)value;
QByteArray message(outputSVStub);
char*valBytes= (char*)&outval;
message.append(valBytes[1]);
message.append(valBytes[0]);
queueMessage(message,this,"ignore(QByteArray)");
}

/*:903*//*904:*/
#line 19281 "./typica.w"

void ModbusRTUDevice::ignore(QByteArray)
{
return;
}

/*:904*//*905:*/
#line 19294 "./typica.w"

void ModbusRTUDevice::timeout()
{
qDebug()<<"Communications timeout.";
responseBuffer.clear();
waiting= false;
messageDelayTimer->start();
}

/*:905*/
#line 583 "./typica.w"

/*770:*/
#line 15853 "./typica.w"

DeviceTreeModelNode::DeviceTreeModelNode(QDomNode&node,int row,
DeviceTreeModelNode*parent)
:domNode(node),rowNumber(row),parentItem(parent)
{

}

DeviceTreeModelNode::~DeviceTreeModelNode()
{
QHash<int,DeviceTreeModelNode*> ::iterator i;
for(i= children.begin();i!=children.end();i++)
{
delete i.value();
}
}

DeviceTreeModelNode*DeviceTreeModelNode::parent()
{
return parentItem;
}

int DeviceTreeModelNode::row()
{
return rowNumber;
}

QDomNode DeviceTreeModelNode::node()const
{
return domNode;
}

DeviceTreeModelNode*DeviceTreeModelNode::child(int index)
{
if(children.contains(index))
{
return children[index];
}
if(index>=0&&index<domNode.childNodes().count())
{
QDomNode childNode= domNode.childNodes().item(index);
DeviceTreeModelNode*childItem= new DeviceTreeModelNode(childNode,
index,this);
children[index]= childItem;
return childItem;
}
return NULL;
}

/*:770*/
#line 584 "./typica.w"

/*772:*/
#line 15942 "./typica.w"

DeviceTreeModel::DeviceTreeModel(QObject*parent)
:QAbstractItemModel(parent)
{
document= AppInstance->deviceConfiguration();
QDomNodeList elements= document.elementsByTagName("devices");
if(elements.size()!=1)
{
qDebug()<<"Unexpected result when loading device map.";
}
treeRoot= elements.at(0);
root= new DeviceTreeModelNode(treeRoot,0);
elements= document.elementsByTagName("references");
if(elements.size()!=1)
{
qDebug()<<"No references section. Creating.";
referenceSection= document.createElement("references");
document.appendChild(referenceSection);
}
else
{
referenceSection= elements.at(0);
}
connect(this,SIGNAL(dataChanged(QModelIndex,QModelIndex)),
AppInstance,SLOT(saveDeviceConfiguration()));
connect(this,SIGNAL(modelReset()),
AppInstance,SLOT(saveDeviceConfiguration()));
connect(this,SIGNAL(rowsInserted(QModelIndex,int,int)),
AppInstance,SLOT(saveDeviceConfiguration()));
}

/*:772*//*773:*/
#line 15977 "./typica.w"

int DeviceTreeModel::columnCount(const QModelIndex&)const
{
return 1;
}

int DeviceTreeModel::rowCount(const QModelIndex&parent)const
{
if(parent.column()> 0)
{
return 0;
}
/*774:*/
#line 15996 "./typica.w"

DeviceTreeModelNode*parentItem;
if(!parent.isValid())
{
parentItem= root;
}
else
{
parentItem= static_cast<DeviceTreeModelNode*> (parent.internalPointer());
}

/*:774*/
#line 15989 "./typica.w"

return parentItem->node().childNodes().count();
}

/*:773*//*775:*/
#line 16010 "./typica.w"

QModelIndex DeviceTreeModel::index(int row,int column,
const QModelIndex&parent)const
{
if(!hasIndex(row,column,parent))
{
return QModelIndex();
}
/*774:*/
#line 15996 "./typica.w"

DeviceTreeModelNode*parentItem;
if(!parent.isValid())
{
parentItem= root;
}
else
{
parentItem= static_cast<DeviceTreeModelNode*> (parent.internalPointer());
}

/*:774*/
#line 16018 "./typica.w"

DeviceTreeModelNode*childItem= parentItem->child(row);
if(childItem)
{
return createIndex(row,column,childItem);
}
return QModelIndex();
}

/*:775*//*776:*/
#line 16029 "./typica.w"

QModelIndex DeviceTreeModel::parent(const QModelIndex&child)const
{
if(!child.isValid())
{
return QModelIndex();
}
DeviceTreeModelNode*childItem= 
static_cast<DeviceTreeModelNode*> (child.internalPointer());
DeviceTreeModelNode*parentItem= childItem->parent();
if(!parentItem||parentItem==root)
{
return QModelIndex();
}
return createIndex(parentItem->row(),0,parentItem);
}

/*:776*//*777:*/
#line 16048 "./typica.w"

Qt::ItemFlags DeviceTreeModel::flags(const QModelIndex&index)const
{
if(!index.isValid())
{
return 0;
}
return Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsEditable;
}

/*:777*//*778:*/
#line 16063 "./typica.w"

QVariant DeviceTreeModel::data(const QModelIndex&index,int role)const
{
if(!index.isValid())
{
return QVariant();
}
if(role!=Qt::DisplayRole&&role!=Qt::UserRole&&role!=Qt::EditRole)
{
return QVariant();
}
DeviceTreeModelNode*item= 
static_cast<DeviceTreeModelNode*> (index.internalPointer());
QDomNode node= item->node();
QDomElement element= node.toElement();
switch(role)
{
case Qt::DisplayRole:
case Qt::EditRole:
return QVariant(element.attribute("name"));
case Qt::UserRole:
return QVariant(element.attribute("reference"));
default:
return QVariant();
}
return QVariant();
}

/*:778*//*779:*/
#line 16095 "./typica.w"

bool DeviceTreeModel::setData(const QModelIndex&index,
const QVariant&value,int)
{
if(!index.isValid())
{
return false;
}
DeviceTreeModelNode*item= 
static_cast<DeviceTreeModelNode*> (index.internalPointer());
QDomNode node= item->node();
QDomElement element= node.toElement();
element.setAttribute("name",value.toString());
emit dataChanged(index,index);
return true;
}

/*:779*//*780:*/
#line 16118 "./typica.w"

void DeviceTreeModel::newNode(const QString&name,const QString&driver,
const QModelIndex&parent)
{
QString referenceID= QUuid::createUuid().toString();
/*774:*/
#line 15996 "./typica.w"

DeviceTreeModelNode*parentItem;
if(!parent.isValid())
{
parentItem= root;
}
else
{
parentItem= static_cast<DeviceTreeModelNode*> (parent.internalPointer());
}

/*:774*/
#line 16123 "./typica.w"

QDomNode parentNode= parentItem->node();
int newRowNumber= rowCount(parent);
beginInsertRows(parent,newRowNumber,newRowNumber);
QDomElement deviceElement= document.createElement("node");
deviceElement.setAttribute("name",name);
deviceElement.setAttribute("reference",referenceID);
parentNode.appendChild(deviceElement);
QDomElement referenceElement= document.createElement("reference");
referenceElement.setAttribute("id",referenceID);
referenceElement.setAttribute("driver",driver);
referenceSection.appendChild(referenceElement);
endInsertRows();
}

/*:780*//*781:*/
#line 16141 "./typica.w"

bool DeviceTreeModel::removeRows(int row,int count,const QModelIndex&parent)
{
/*774:*/
#line 15996 "./typica.w"

DeviceTreeModelNode*parentItem;
if(!parent.isValid())
{
parentItem= root;
}
else
{
parentItem= static_cast<DeviceTreeModelNode*> (parent.internalPointer());
}

/*:774*/
#line 16144 "./typica.w"

QDomNode parentNode= parentItem->node();
QDomNodeList childNodes= parentNode.childNodes();
if(childNodes.size()<row+count)
{
return false;
}
beginRemoveRows(parent,row,row+count-1);
QList<QDomElement> removalList;
for(int i= row;i<row+count;i++)
{
removalList.append(childNodes.at(i).toElement());
}
QDomElement element;
QDomElement reference;
for(int i= 0;i<count;i++)
{
element= removalList.at(i);
if(element.hasAttribute("reference"))
{
reference= referenceElement(element.attribute("reference"));
if(!reference.isNull())
{
referenceSection.removeChild(reference);
}
}
parentNode.removeChild(element);
}
endRemoveRows();
beginResetModel();
delete root;
root= new DeviceTreeModelNode(treeRoot,0);
endResetModel();
return true;
}

/*:781*//*782:*/
#line 16183 "./typica.w"

QDomElement DeviceTreeModel::referenceElement(const QString&id)
{
QDomNodeList childNodes= referenceSection.childNodes();
QDomElement element;
for(int i= 0;i<childNodes.size();i++)
{
element= childNodes.at(i).toElement();
if(element.hasAttribute("id"))
{
if(element.attribute("id")==id)
{
return element;
}
}
}
return QDomElement();
}

/*:782*//*783:*/
#line 16204 "./typica.w"

QVariant DeviceTreeModel::headerData(int,Qt::Orientation,int)const
{
return QVariant();
}

/*:783*//*784:*/
#line 16213 "./typica.w"

DeviceTreeModel::~DeviceTreeModel()
{
delete root;
}

/*:784*/
#line 585 "./typica.w"

/*811:*/
#line 16713 "./typica.w"

BasicDeviceConfigurationWidget::BasicDeviceConfigurationWidget(
DeviceTreeModel*model,const QModelIndex&index)
:QWidget(NULL),deviceModel(model),currentNode(index)
{

}

/*:811*//*812:*/
#line 16725 "./typica.w"

void BasicDeviceConfigurationWidget::updateAttribute(const QString&name,
const QString&value)
{
QDomElement referenceElement= deviceModel->referenceElement(
deviceModel->data(currentNode,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;
bool found= false;
for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")==name)
{
node.setAttribute("value",value);
found= true;
break;
}
}
if(!found)
{
node= AppInstance->deviceConfiguration().createElement("attribute");
node.setAttribute("name",name);
node.setAttribute("value",value);
referenceElement.appendChild(node);
}
AppInstance->saveDeviceConfiguration();
}

/*:812*//*813:*/
#line 16759 "./typica.w"

void BasicDeviceConfigurationWidget::insertChildNode(const QString&name,
const QString&driver)
{
deviceModel->newNode(name,driver,currentNode);
}

/*:813*/
#line 586 "./typica.w"

/*802:*/
#line 16557 "./typica.w"

DeviceConfigurationWindow::DeviceConfigurationWindow():QWidget(NULL),
view(new QTreeView),configArea(new QScrollArea)
{
QSplitter*splitter= new QSplitter;
QWidget*leftWidget= new QWidget;
leftWidget->setMinimumWidth(200);
QVBoxLayout*left= new QVBoxLayout;
view->setAnimated(true);
view->setSelectionMode(QAbstractItemView::SingleSelection);
document= AppInstance->deviceConfiguration();
model= new DeviceTreeModel;
view->setModel(model);
view->setTextElideMode(Qt::ElideNone);
view->expandAll();
view->resizeColumnToContents(0);
connect(model,SIGNAL(modelReset()),view,SLOT(expandAll()));
QHBoxLayout*treeButtons= new QHBoxLayout;
QToolButton*addDeviceButton= new QToolButton;
addDeviceButton->setIcon(QIcon::fromTheme("list-add"));
addDeviceButton->setToolTip(tr("New Roaster"));
connect(addDeviceButton,SIGNAL(clicked()),
this,SLOT(addDevice()));
QToolButton*removeNodeButton= new QToolButton;
removeNodeButton->setIcon(QIcon::fromTheme("list-remove"));
removeNodeButton->setToolTip(tr("Delete Selection"));
connect(removeNodeButton,SIGNAL(clicked()),this,SLOT(removeNode()));
treeButtons->addWidget(addDeviceButton);
treeButtons->addWidget(removeNodeButton);
left->addWidget(view);
left->addLayout(treeButtons);
leftWidget->setLayout(left);
splitter->addWidget(leftWidget);
configArea->setMinimumWidth(580);
configArea->setMinimumHeight(460);
configArea->setWidgetResizable(true);
splitter->addWidget(configArea);
QVBoxLayout*centralLayout= new QVBoxLayout;
centralLayout->addWidget(splitter);
setLayout(centralLayout);
connect(view,SIGNAL(activated(QModelIndex)),
this,SLOT(newSelection(QModelIndex)));
connect(view,SIGNAL(clicked(QModelIndex)),
this,SLOT(newSelection(QModelIndex)));
connect(model,SIGNAL(rowsInserted(QModelIndex,int,int)),
view,SLOT(expand(QModelIndex)));
connect(model,SIGNAL(rowsInserted(QModelIndex,int,int)),
this,SLOT(resizeColumn()));
connect(model,SIGNAL(rowsRemoved(QModelIndex,int,int)),
this,SLOT(resizeColumn()));
}

/*:802*//*803:*/
#line 16612 "./typica.w"

void DeviceConfigurationWindow::addDevice()
{
model->newNode(tr("New Roaster"),"roaster",QModelIndex());
}

/*:803*//*804:*/
#line 16620 "./typica.w"

void DeviceConfigurationWindow::removeNode()
{
QModelIndex index= view->currentIndex();
if(index.isValid())
{
int row= index.row();
QModelIndex parent= index.parent();
model->removeRow(row,parent);
}
}

/*:804*//*805:*/
#line 16636 "./typica.w"

void DeviceConfigurationWindow::newSelection(const QModelIndex&index)
{
QWidget*editor= AppInstance->deviceConfigurationWidget(model,index);
if(editor)
{
configArea->setWidget(editor);
editor->show();
}
}

/*:805*//*806:*/
#line 16653 "./typica.w"

void DeviceConfigurationWindow::resizeColumn()
{
view->resizeColumnToContents(0);
}

/*:806*/
#line 587 "./typica.w"

/*826:*/
#line 17134 "./typica.w"

Ni9211TcConfWidget::Ni9211TcConfWidget(DeviceTreeModel*model,
const QModelIndex&index):
BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QLineEdit*columnName= new QLineEdit;
layout->addRow(tr("Column Name:"),columnName);
QComboBox*typeSelector= new QComboBox;
typeSelector->addItem("J");
typeSelector->addItem("K");
typeSelector->addItem("T");
typeSelector->addItem("B");
typeSelector->addItem("E");
typeSelector->addItem("N");
typeSelector->addItem("R");
typeSelector->addItem("S");
layout->addRow(tr("Thermocouple Type:"),typeSelector);
QCheckBox*hideSeries= new QCheckBox("Hide this channel");
layout->addRow(hideSeries);
setLayout(layout);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 17155 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="type")
{
typeSelector->setCurrentIndex(
typeSelector->findText(node.attribute("value")));
}
else if(node.attribute("name")=="columnname")
{
columnName->setText(node.attribute("value"));
}
else if(node.attribute("name")=="hidden")
{
hideSeries->setChecked(node.attribute("value")=="true");
}
}
updateThermocoupleType(typeSelector->currentText());
updateColumnName(columnName->text());
updateHidden(hideSeries->isChecked());
connect(typeSelector,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updateThermocoupleType(QString)));
connect(columnName,SIGNAL(textEdited(QString)),this,SLOT(updateColumnName(QString)));
connect(hideSeries,SIGNAL(toggled(bool)),this,SLOT(updateHidden(bool)));
}

/*:826*//*827:*/
#line 17185 "./typica.w"

void Ni9211TcConfWidget::updateThermocoupleType(const QString&type)
{
updateAttribute("type",type);
}

void Ni9211TcConfWidget::updateColumnName(const QString&name)
{
updateAttribute("columnname",name);
}

void Ni9211TcConfWidget::updateHidden(bool hidden)
{
updateAttribute("hidden",hidden?"true":"false");
}

/*:827*/
#line 588 "./typica.w"

/*822:*/
#line 17048 "./typica.w"

NiDaqMxBase9211ConfWidget::NiDaqMxBase9211ConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QVBoxLayout*layout= new QVBoxLayout;
QHBoxLayout*deviceIdLayout= new QHBoxLayout;
QLabel*label= new QLabel(tr("Device ID:"));
QLineEdit*deviceId= new QLineEdit;
deviceIdLayout->addWidget(label);
deviceIdLayout->addWidget(deviceId);
QPushButton*addChannelButton= new QPushButton(tr("Add Channel"));
layout->addLayout(deviceIdLayout);
layout->addWidget(addChannelButton);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 17062 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="deviceID")
{
deviceId->setText(node.attribute("value","Dev1"));
break;
}
}
updateDeviceId(deviceId->text());
connect(addChannelButton,SIGNAL(clicked()),
this,SLOT(addChannel()));
connect(deviceId,SIGNAL(textEdited(QString)),
this,SLOT(updateDeviceId(QString)));
setLayout(layout);
}

/*:822*//*823:*/
#line 17084 "./typica.w"

void NiDaqMxBase9211ConfWidget::updateDeviceId(const QString&newId)
{
updateAttribute("deviceID",newId);
}

/*:823*//*824:*/
#line 17092 "./typica.w"

void NiDaqMxBase9211ConfWidget::addChannel()
{
insertChildNode(tr("Thermocouple channel"),"ni9211seriestc");
}

/*:824*/
#line 589 "./typica.w"

/*820:*/
#line 16999 "./typica.w"

NiDaqMxBaseDriverConfWidget::NiDaqMxBaseDriverConfWidget(
DeviceTreeModel*model,const QModelIndex&index):
BasicDeviceConfigurationWidget(model,index)
{
QHBoxLayout*layout= new QHBoxLayout;
QToolButton*addDeviceButton= new QToolButton;
addDeviceButton->setText(tr("Add Device"));
NodeInserter*add9211= new NodeInserter("NI USB 9211","NI USB 9211",
"nidaqmxbase9211series");
NodeInserter*add9211a= new NodeInserter("NI USB 9211A","NI USB 9211A",
"nidaqmxbase9211series");
connect(add9211,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
connect(add9211a,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
QMenu*deviceMenu= new QMenu;
deviceMenu->addAction(add9211);
deviceMenu->addAction(add9211a);
addDeviceButton->setMenu(deviceMenu);
addDeviceButton->setPopupMode(QToolButton::InstantPopup);
layout->addWidget(addDeviceButton);
setLayout(layout);
}

/*:820*/
#line 590 "./typica.w"

/*681:*/
#line 14471 "./typica.w"

ReportAction::ReportAction(const QString&fileName,const QString&reportName,
QObject*parent):
QAction(reportName,parent),reportFile(fileName)
{
connect(this,SIGNAL(triggered()),this,SLOT(createReport()));
}

/*:681*//*682:*/
#line 14487 "./typica.w"

void ReportAction::createReport()
{
QFile file(reportFile);
QDomDocument document;
if(file.open(QIODevice::ReadOnly))
{
document.setContent(&file,true);
QDomElement element= document.documentElement();
QScriptEngine*engine= AppInstance->engine;
QScriptContext*context= engine->pushContext();
QScriptValue object;
QString targetID= reportFile;
/*208:*/
#line 4814 "./typica.w"

ScriptQMainWindow*window= new ScriptQMainWindow;
window->setObjectName(targetID);
object= engine->newQObject(window);
setQMainWindowProperties(object,engine);
QWidget*central= new(QWidget);
central->setParent(window);
central->setObjectName("centralWidget");
window->setCentralWidget(central);
if(element.hasChildNodes())
{
/*209:*/
#line 4850 "./typica.w"

QStack<QWidget*> widgetStack;
QStack<QLayout*> layoutStack;
QString windowScript;
widgetStack.push(central);
QDomNodeList windowChildren= element.childNodes();
int i= 0;
while(i<windowChildren.count())
{
QDomNode current;
QDomElement element;
current= windowChildren.at(i);
if(current.isElement())
{
element= current.toElement();
if(element.tagName()=="program")
{
windowScript.append(element.text());
}
else if(element.tagName()=="layout")
{
element.setAttribute("trcontext","configuration");
addLayoutToWidget(element,&widgetStack,&layoutStack);
}
else if(element.tagName()=="menu")
{
/*210:*/
#line 4898 "./typica.w"

QMenuBar*bar= window->menuBar();
bar->setParent(window);
bar->setObjectName("menuBar");
if(element.hasAttribute("name"))
{
QMenu*menu= bar->addMenu(QCoreApplication::translate("configuration",
element.attribute("name").toUtf8().data()));
menu->setParent(bar);
if(element.hasAttribute("type"))
{
if(element.attribute("type")=="reports")
{
if(element.hasAttribute("src"))
{
/*679:*/
#line 14431 "./typica.w"

QSettings settings;
QString reportDirectory= QString("%1/%2").arg(settings.value("config").
toString()).
arg(element.attribute("src"));
QDir::addSearchPath("reports",reportDirectory);
QDir directory(reportDirectory);
directory.setFilter(QDir::Files);
directory.setSorting(QDir::Name);
QStringList nameFilter;
nameFilter<<"*.xml";
directory.setNameFilters(nameFilter);
QFileInfoList reportFiles= directory.entryInfoList();
for(int i= 0;i<reportFiles.size();i++)
{
QFileInfo reportFile= reportFiles.at(i);
/*683:*/
#line 14511 "./typica.w"

QString path= reportFile.absoluteFilePath();
QFile file(path);
if(file.open(QIODevice::ReadOnly))
{
QDomDocument document;
document.setContent(&file,true);
QDomElement root= document.documentElement();
QString translationContext= root.attribute("id");
QDomNode titleNode= root.elementsByTagName("reporttitle").at(0);
if(!titleNode.isNull())
{
QDomElement titleElement= titleNode.toElement();
QString title= QCoreApplication::translate("configuration",
titleElement.text().toUtf8().data());
if(!title.isEmpty())
{
QStringList hierarchy= title.split(":->");
QMenu*insertionPoint= menu;
/*684:*/
#line 14540 "./typica.w"

for(int j= 0;j<hierarchy.size()-1;j++)
{
QObjectList menuList= insertionPoint->children();
bool menuFound= false;
for(int k= 0;k<menuList.size();k++)
{
QMenu*currentItem= qobject_cast<QMenu*> (menuList.at(k));
if(currentItem)
{
if(currentItem->title()==hierarchy.at(j))
{
menuFound= true;
insertionPoint= currentItem;
break;
}
}
}
if(!menuFound)
{
insertionPoint= insertionPoint->addMenu(hierarchy.at(j));
}
}

/*:684*/
#line 14530 "./typica.w"

ReportAction*action= new ReportAction(path,hierarchy.last());
insertionPoint->addAction(action);
}
}
}

/*:683*/
#line 14447 "./typica.w"

}

/*:679*/
#line 4913 "./typica.w"

}
}
}
if(element.hasChildNodes())
{
/*211:*/
#line 4926 "./typica.w"

QDomNodeList menuItems= element.childNodes();
int j= 0;
while(j<menuItems.count())
{
QDomNode item= menuItems.at(j);
if(item.isElement())
{
QDomElement itemElement= item.toElement();
if(itemElement.tagName()=="item")
{
QAction*itemAction= new QAction(QCoreApplication::translate("configuration",
itemElement.text().toUtf8().data()),menu);
if(itemElement.hasAttribute("id"))
{
itemAction->setObjectName(itemElement.attribute("id"));
}
if(itemElement.hasAttribute("shortcut"))
{
itemAction->setShortcut(itemElement.attribute("shortcut"));
}
menu->addAction(itemAction);
}
else if(itemElement.tagName()=="separator")
{
menu->addSeparator();
}
else if(itemElement.tagName()=="plugins")
{
/*704:*/
#line 21 "./plugins.w"

QMenu*pluginMenu= new QMenu(menu);
if(itemElement.hasAttribute("id"))
{
pluginMenu->setObjectName(itemElement.attribute("id"));
}
if(itemElement.hasAttribute("title"))
{
pluginMenu->setTitle(itemElement.attribute("title"));
}
if(itemElement.hasAttribute("src"))
{
QSettings settings;
QString pluginDirectory= QString("%1/%2").
arg(settings.value("config").toString()).
arg(itemElement.attribute("src"));
QDir directory(pluginDirectory);
directory.setFilter(QDir::Files);
directory.setSorting(QDir::Name);
QStringList nameFilter;
nameFilter<<"*.js";
directory.setNameFilters(nameFilter);
QFileInfoList pluginFiles= directory.entryInfoList();
for(int k= 0;k<pluginFiles.size();k++)
{
PluginAction*pa= new PluginAction(pluginFiles.at(k),pluginMenu);
if(itemElement.hasAttribute("preRun"))
{
pa->setPreRun(itemElement.attribute("preRun"));
}
if(itemElement.hasAttribute("postRun"))
{
pa->setPostRun(itemElement.attribute("postRun"));
}
pluginMenu->addAction(pa);
}
}
menu->addMenu(pluginMenu);

/*:704*/
#line 4955 "./typica.w"

}
}
j++;
}

#line 1 "./helpmenu.w"
/*:211*/
#line 4919 "./typica.w"

}
}

/*:210*/
#line 4876 "./typica.w"

}
}
i++;
}
QScriptValue oldThis= context->thisObject();
context->setThisObject(object);
QScriptValue result= engine->evaluate(windowScript);
/*202:*/
#line 4629 "./typica.w"

if(engine->hasUncaughtException())
{
int line= engine->uncaughtExceptionLineNumber();
qDebug()<<"Uncaught excpetion at line "<<line<<" : "<<
result.toString();
QString trace;
foreach(trace,engine->uncaughtExceptionBacktrace())
{
qDebug()<<trace;
}
}

/*:202*/
#line 4884 "./typica.w"

context->setThisObject(oldThis);

/*:209*/
#line 4825 "./typica.w"

}
/*212:*/
#line 9 "./helpmenu.w"

HelpMenu*helpMenu= new HelpMenu();
window->menuBar()->addMenu(helpMenu);

/*:212*/
#line 4827 "./typica.w"

window->show();
window->setupFinished();

/*:208*/
#line 14500 "./typica.w"

file.close();
engine->popContext();
}
}

/*:682*/
#line 591 "./typica.w"

/*258:*/
#line 6122 "./typica.w"

NumericDelegate::NumericDelegate(bool positiveOnly,QObject*parent):
QItemDelegate(parent),m_positiveOnly(positiveOnly)
{

}

/*:258*//*259:*/
#line 6134 "./typica.w"

void NumericDelegate::setEditorData(QWidget*editor,
const QModelIndex&index)const
{
QString value= index.model()->data(index,Qt::EditRole).toString();
QLineEdit*line= static_cast<QLineEdit*> (editor);
line->setText(value);
}

/*:259*//*260:*/
#line 6149 "./typica.w"

void NumericDelegate::setModelData(QWidget*editor,QAbstractItemModel*model,
const QModelIndex&index)const
{
QLineEdit*line= static_cast<QLineEdit*> (editor);
model->setData(index,line->text(),Qt::EditRole);
QScriptEngine*engine= AppInstance->engine;
engine->pushContext();
QString script= QString("Number(%1)").arg(line->text());
QScriptValue result= engine->evaluate(line->text());
if(result.isNumber())
{
if(m_positiveOnly)
{
if(result.toNumber()<0)
{
model->setData(index,QVariant(),Qt::DisplayRole);
}
else
{
model->setData(index,result.toVariant(),Qt::DisplayRole);
}
}
else
{
model->setData(index,result.toVariant(),Qt::DisplayRole);
}
}
else
{
model->setData(index,QVariant(),Qt::DisplayRole);
}
engine->popContext();
}

/*:260*//*261:*/
#line 6186 "./typica.w"

QWidget*NumericDelegate::createEditor(QWidget*parent,
const QStyleOptionViewItem&,
const QModelIndex&)const
{
return(new QLineEdit(parent));
}

/*:261*//*262:*/
#line 6197 "./typica.w"

void NumericDelegate::updateEditorGeometry(QWidget*editor,
const QStyleOptionViewItem&option,
const QModelIndex&)const
{
editor->setGeometry(option.rect);
}

/*:262*/
#line 592 "./typica.w"

/*831:*/
#line 17244 "./typica.w"

NiDaqMxDriverConfWidget::NiDaqMxDriverConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QHBoxLayout*layout= new QHBoxLayout;
QToolButton*addDeviceButton= new QToolButton;
addDeviceButton->setText(tr("Add Device"));
NodeInserter*add9211a= new NodeInserter("NI USB 9211A","NI USB 9211A",
"nidaqmx9211series");
NodeInserter*addtc01= new NodeInserter("NI USB TC01","NI USB TC01",
"nidaqmxtc01");
connect(add9211a,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
connect(addtc01,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
QMenu*deviceMenu= new QMenu;
deviceMenu->addAction(add9211a);
deviceMenu->addAction(addtc01);
addDeviceButton->setMenu(deviceMenu);
addDeviceButton->setPopupMode(QToolButton::InstantPopup);
layout->addWidget(addDeviceButton);
setLayout(layout);
}

/*:831*/
#line 593 "./typica.w"

/*833:*/
#line 17293 "./typica.w"

NiDaqMx9211ConfWidget::NiDaqMx9211ConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QVBoxLayout*layout= new QVBoxLayout;
QHBoxLayout*deviceIdLayout= new QHBoxLayout;
QLabel*label= new QLabel(tr("Device ID:"));
QLineEdit*deviceId= new QLineEdit;
deviceIdLayout->addWidget(label);
deviceIdLayout->addWidget(deviceId);
QPushButton*addChannelButton= new QPushButton(tr("Add Channel"));
layout->addLayout(deviceIdLayout);
layout->addWidget(addChannelButton);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 17307 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="deviceID")
{
deviceId->setText(node.attribute("value","Dev1"));
break;
}
}
updateDeviceId(deviceId->text());
connect(addChannelButton,SIGNAL(clicked()),this,SLOT(addChannel()));
connect(deviceId,SIGNAL(textEdited(QString)),
this,SLOT(updateDeviceId(QString)));
setLayout(layout);
}

void NiDaqMx9211ConfWidget::updateDeviceId(const QString&newId)
{
updateAttribute("deviceID",newId);
}

void NiDaqMx9211ConfWidget::addChannel()
{
insertChildNode(tr("Thermocouple channel"),"ni9211seriestc");
}

/*:833*/
#line 594 "./typica.w"

/*835:*/
#line 17358 "./typica.w"

NiDaqMxTc01ConfWidget::NiDaqMxTc01ConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QLineEdit*deviceId= new QLineEdit;
layout->addRow(tr("Device ID:"),deviceId);
QLineEdit*columnName= new QLineEdit;
layout->addRow(tr("Column Name:"),columnName);
QComboBox*typeSelector= new QComboBox;
typeSelector->addItem("J");
typeSelector->addItem("K");
typeSelector->addItem("T");
typeSelector->addItem("B");
typeSelector->addItem("E");
typeSelector->addItem("N");
typeSelector->addItem("R");
typeSelector->addItem("S");
layout->addRow(tr("Thermocouple Type:"),typeSelector);
QCheckBox*hideSeries= new QCheckBox(tr("Hide this channel"));
layout->addRow(hideSeries);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 17380 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="deviceID")
{
deviceId->setText(node.attribute("value"));
}
else if(node.attribute("name")=="type")
{
typeSelector->setCurrentIndex(typeSelector->findText(node.attribute("value")));
}
else if(node.attribute("name")=="columnname")
{
columnName->setText(node.attribute("value"));
}
else if(node.attribute("name")=="hidden")
{
hideSeries->setChecked(node.attribute("value")=="true");
}
}
updateDeviceId(deviceId->text());
updateThermocoupleType(typeSelector->currentText());
updateColumnName(columnName->text());
updateHidden(hideSeries->isChecked());
connect(deviceId,SIGNAL(textEdited(QString)),this,SLOT(updateDeviceId(QString)));
connect(typeSelector,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateThermocoupleType(QString)));
connect(columnName,SIGNAL(textEdited(QString)),this,SLOT(updateColumnName(QString)));
setLayout(layout);
connect(hideSeries,SIGNAL(toggled(bool)),this,SLOT(updateHidden(bool)));
}

void NiDaqMxTc01ConfWidget::updateDeviceId(const QString&newId)
{
updateAttribute("deviceID",newId);
}

void NiDaqMxTc01ConfWidget::updateThermocoupleType(const QString&type)
{
updateAttribute("type",type);
}

void NiDaqMxTc01ConfWidget::updateColumnName(const QString&name)
{
updateAttribute("columnname",name);
}

void NiDaqMxTc01ConfWidget::updateHidden(bool hidden)
{
updateAttribute("hidden",hidden?"true":"false");
}

/*:835*/
#line 595 "./typica.w"

/*853:*/
#line 17800 "./typica.w"

ModbusRtuPortConfWidget::ModbusRtuPortConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QToolButton*addDeviceButton= new QToolButton;
addDeviceButton->setText(tr("Add Device"));
NodeInserter*addModbusRtuDevice= new NodeInserter("Modbus RTU Device",
"Modbus RTU Device",
"modbusrtudevice");
connect(addModbusRtuDevice,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
QMenu*deviceMenu= new QMenu;
deviceMenu->addAction(addModbusRtuDevice);
addDeviceButton->setMenu(deviceMenu);
addDeviceButton->setPopupMode(QToolButton::InstantPopup);
layout->addRow(QString(),addDeviceButton);
PortSelector*port= new PortSelector;
layout->addRow(tr("Port:"),port);
connect(port,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updatePort(QString)));
connect(port,SIGNAL(editTextChanged(QString)),
this,SLOT(updatePort(QString)));
BaudSelector*rate= new BaudSelector;
layout->addRow(tr("Baud:"),rate);
connect(rate,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updateBaudRate(QString)));
ParitySelector*parity= new ParitySelector;
layout->addRow(tr("Parity:"),parity);
connect(parity,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updateParity(QString)));
FlowSelector*flow= new FlowSelector;
layout->addRow(tr("Flow Control:"),flow);
connect(flow,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updateFlowControl(QString)));
StopSelector*stop= new StopSelector;
layout->addRow(tr("Stop Bits:"),stop);
connect(stop,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updateStopBits(QString)));
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 17840 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="port")
{
int j= port->findText(node.attribute("value"));
if(j>=0)
{
port->setCurrentIndex(j);
}
else
{
port->insertItem(0,node.attribute("value"));
port->setCurrentIndex(0);
}
}
else if(node.attribute("name")=="baudrate")
{
rate->setCurrentIndex(rate->findText(node.attribute("value")));
}
else if(node.attribute("name")=="parity")
{
parity->setCurrentIndex(parity->findText(node.attribute("value")));
}
else if(node.attribute("name")=="flowcontrol")
{
flow->setCurrentIndex(flow->findText(node.attribute("value")));
}
else if(node.attribute("name")=="stopbits")
{
stop->setCurrentIndex(stop->findText(node.attribute("value")));
}
}
updatePort(port->currentText());
updateBaudRate(rate->currentText());
updateParity(parity->currentText());
updateFlowControl(flow->currentText());
updateStopBits(stop->currentText());
setLayout(layout);
}

void ModbusRtuPortConfWidget::updatePort(const QString&newPort)
{
updateAttribute("port",newPort);
}

void ModbusRtuPortConfWidget::updateBaudRate(const QString&newRate)
{
updateAttribute("baudrate",newRate);
}

void ModbusRtuPortConfWidget::updateParity(const QString&newParity)
{
updateAttribute("parity",newParity);
}

void ModbusRtuPortConfWidget::updateFlowControl(const QString&newFlow)
{
updateAttribute("flowcontrol",newFlow);
}

void ModbusRtuPortConfWidget::updateStopBits(const QString&newStopBits)
{
updateAttribute("stopbits",newStopBits);
}

/*:853*/
#line 596 "./typica.w"

/*855:*/
#line 17963 "./typica.w"

ModbusRtuDeviceConfWidget::ModbusRtuDeviceConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
unitSpecificationLayout(new QStackedLayout),
decimalSpecificationLayout(new QStackedLayout)
{
QVBoxLayout*layout= new QVBoxLayout;
QToolButton*addChannelButton= new QToolButton;
addChannelButton->setText(tr("Add Channel"));
NodeInserter*addTemperaturePV= new NodeInserter("Temperature Process Value",
"Temperature Process Value",
"modbustemperaturepv");
NodeInserter*addTemperatureSV= new NodeInserter("Temperature Set Value",
"Temperature Set Value",
"modbustemperaturesv");
connect(addTemperaturePV,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
connect(addTemperatureSV,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
QMenu*channelMenu= new QMenu;
channelMenu->addAction(addTemperaturePV);
channelMenu->addAction(addTemperatureSV);
addChannelButton->setMenu(channelMenu);
addChannelButton->setPopupMode(QToolButton::InstantPopup);
layout->addWidget(addChannelButton);
QHBoxLayout*stationLayout= new QHBoxLayout;
QLabel*stationLabel= new QLabel(tr("Station:"));
QSpinBox*stationNumber= new QSpinBox;
stationNumber->setMinimum(0);
stationNumber->setMaximum(255);
stationLayout->addWidget(stationLabel);
stationLayout->addWidget(stationNumber);
layout->addLayout(stationLayout);
QCheckBox*fixedUnit= new QCheckBox(tr("Fixed Temperature Unit"));
layout->addWidget(fixedUnit);
QWidget*fixedUnitPlaceholder= new QWidget(this);
QHBoxLayout*fixedUnitLayout= new QHBoxLayout;
QLabel*fixedUnitLabel= new QLabel(tr("Temperature Unit:"));
QComboBox*fixedUnitSelector= new QComboBox;
fixedUnitSelector->addItem("Fahrenheit");
fixedUnitSelector->addItem("Celsius");
fixedUnitLayout->addWidget(fixedUnitLabel);
fixedUnitLayout->addWidget(fixedUnitSelector);
fixedUnitPlaceholder->setLayout(fixedUnitLayout);
unitSpecificationLayout->addWidget(fixedUnitPlaceholder);
QWidget*queriedUnitPlaceholder= new QWidget(this);
QFormLayout*queriedUnitLayout= new QFormLayout;
ShortHexSpinBox*unitAddress= new ShortHexSpinBox;
queriedUnitLayout->addRow(tr("Function 0x03 Unit Address:"),unitAddress);
QSpinBox*valueF= new QSpinBox;
valueF->setMinimum(0);
valueF->setMaximum(65535);
queriedUnitLayout->addRow(tr("Value for Fahrenheit"),valueF);
QSpinBox*valueC= new QSpinBox;
valueC->setMinimum(0);
valueC->setMaximum(65535);
queriedUnitLayout->addRow(tr("Value for Celsius"),valueC);
queriedUnitPlaceholder->setLayout(queriedUnitLayout);
unitSpecificationLayout->addWidget(queriedUnitPlaceholder);
layout->addLayout(unitSpecificationLayout);
QCheckBox*fixedPrecision= new QCheckBox(tr("Fixed Precision"));
layout->addWidget(fixedPrecision);
QWidget*fixedPrecisionPlaceholder= new QWidget(this);
QFormLayout*fixedPrecisionLayout= new QFormLayout;
QSpinBox*fixedPrecisionValue= new QSpinBox;
fixedPrecisionValue->setMinimum(0);
fixedPrecisionValue->setMaximum(9);
fixedPrecisionLayout->addRow("Places after the decimal point:",
fixedPrecisionValue);
fixedPrecisionPlaceholder->setLayout(fixedPrecisionLayout);
decimalSpecificationLayout->addWidget(fixedPrecisionPlaceholder);
QWidget*queriedPrecisionPlaceholder= new QWidget(this);
QFormLayout*queriedPrecisionLayout= new QFormLayout;
ShortHexSpinBox*precisionAddress= new ShortHexSpinBox;
queriedPrecisionLayout->addRow("Function 0x03 Decimal Position Address:",
precisionAddress);
queriedPrecisionPlaceholder->setLayout(queriedPrecisionLayout);
decimalSpecificationLayout->addWidget(queriedPrecisionPlaceholder);
layout->addLayout(decimalSpecificationLayout);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 18043 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="station")
{
stationNumber->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="fixedunit")
{
if(node.attribute("value")=="true")
{
fixedUnit->setCheckState(Qt::Checked);
}
else if(node.attribute("value")=="false")
{
fixedUnit->setCheckState(Qt::Unchecked);
}
}
else if(node.attribute("name")=="fixedprecision")
{
fixedPrecisionValue->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="unit")
{
fixedUnitSelector->setCurrentIndex(fixedUnitSelector->findText(node.attribute("value")));
}
else if(node.attribute("name")=="unitaddress")
{
unitAddress->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="fvalue")
{
valueF->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="cvalue")
{
valueC->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="precisionaddress")
{
precisionAddress->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="precision")
{
fixedPrecisionValue->setValue(node.attribute("value").toInt());
}
}
updateStationNumber(stationNumber->value());
updateFixedUnit(fixedUnit->isChecked());
updateFixedDecimal(fixedPrecision->isChecked());
updateUnit(fixedUnitSelector->currentText());
updateUnitAddress(unitAddress->value());
updateValueF(valueF->value());
updateValueC(valueC->value());
updatePrecisionAddress(precisionAddress->value());
updatePrecisionValue(fixedPrecisionValue->value());
connect(stationNumber,SIGNAL(valueChanged(int)),
this,SLOT(updateStationNumber(int)));
connect(fixedUnitSelector,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updateUnit(QString)));
connect(unitAddress,SIGNAL(valueChanged(int)),
this,SLOT(updateUnitAddress(int)));
connect(valueF,SIGNAL(valueChanged(int)),
this,SLOT(updateValueF(int)));
connect(valueC,SIGNAL(valueChanged(int)),
this,SLOT(updateValueC(int)));
connect(fixedUnit,SIGNAL(toggled(bool)),
this,SLOT(updateFixedUnit(bool)));
connect(fixedPrecision,SIGNAL(toggled(bool)),
this,SLOT(updateFixedDecimal(bool)));
connect(fixedPrecisionValue,SIGNAL(valueChanged(int)),
this,SLOT(updatePrecisionValue(int)));
connect(precisionAddress,SIGNAL(valueChanged(int)),
this,SLOT(updatePrecisionAddress(int)));
setLayout(layout);
}

void ModbusRtuDeviceConfWidget::updateStationNumber(int newStation)
{
updateAttribute("station",QString("%1").arg(newStation));
}

void ModbusRtuDeviceConfWidget::updateFixedUnit(bool newFixed)
{
if(newFixed)
{
unitSpecificationLayout->setCurrentIndex(0);
updateAttribute("fixedunit","true");
}
else
{
unitSpecificationLayout->setCurrentIndex(1);
updateAttribute("fixedunit","false");
}
}

void ModbusRtuDeviceConfWidget::updateFixedDecimal(bool newFixed)
{
if(newFixed)
{
decimalSpecificationLayout->setCurrentIndex(0);
updateAttribute("fixedprecision","true");
}
else
{
decimalSpecificationLayout->setCurrentIndex(1);
updateAttribute("fixedprecision","false");
}
}

void ModbusRtuDeviceConfWidget::updateUnit(const QString&newUnit)
{
updateAttribute("unit",newUnit);
}

void ModbusRtuDeviceConfWidget::updateUnitAddress(int newAddress)
{
updateAttribute("unitaddress",QString("%1").arg(newAddress));
}

void ModbusRtuDeviceConfWidget::updateValueF(int newValue)
{
updateAttribute("fvalue",QString("%1").arg(newValue));
}

void ModbusRtuDeviceConfWidget::updateValueC(int newValue)
{
updateAttribute("cvalue",QString("%1").arg(newValue));
}

void ModbusRtuDeviceConfWidget::updatePrecisionAddress(int newAddress)
{
updateAttribute("precisionaddress",QString("%1").arg(newAddress));
}

void ModbusRtuDeviceConfWidget::updatePrecisionValue(int newValue)
{
updateAttribute("precision",QString("%1").arg(newValue));
}

/*:855*/
#line 597 "./typica.w"

/*857:*/
#line 18206 "./typica.w"

ModbusRtuDeviceTPvConfWidget::ModbusRtuDeviceTPvConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
ShortHexSpinBox*address= new ShortHexSpinBox;
layout->addRow(tr("Function 0x04 Process Value Address"),address);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 18214 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="address")
{
address->setValue(node.attribute("value").toInt());
break;
}
}
updateAddress(address->value());
connect(address,SIGNAL(valueChanged(int)),this,SLOT(updateAddress(int)));
setLayout(layout);
}

void ModbusRtuDeviceTPvConfWidget::updateAddress(int newAddress)
{
updateAttribute("address",QString("%1").arg(newAddress));
}

/*:857*/
#line 598 "./typica.w"

/*859:*/
#line 18262 "./typica.w"

ModbusRtuDeviceTSvConfWidget::ModbusRtuDeviceTSvConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),boundsLayout(new QStackedLayout)
{
QVBoxLayout*layout= new QVBoxLayout;
QFormLayout*addressLayout= new QFormLayout;
ShortHexSpinBox*readAddress= new ShortHexSpinBox;
ShortHexSpinBox*writeAddress= new ShortHexSpinBox;
addressLayout->addRow(tr("Function 0x04 Read Set Value Address:"),readAddress);
addressLayout->addRow(tr("Function 0x06 Write Set Value Address:"),writeAddress);
layout->addLayout(addressLayout);
QCheckBox*fixedRange= new QCheckBox(tr("Fixed Set Value Range"));
layout->addWidget(fixedRange);
QWidget*queriedRangePlaceholder= new QWidget(this);
QFormLayout*queriedRangeLayout= new QFormLayout;
ShortHexSpinBox*lowerAddress= new ShortHexSpinBox;
ShortHexSpinBox*upperAddress= new ShortHexSpinBox;
queriedRangeLayout->addRow(tr("Function 0x03 Minimum Set Value Address"),
lowerAddress);
queriedRangeLayout->addRow(tr("Function 0x03 Maximum Set Value Address"),
upperAddress);
queriedRangePlaceholder->setLayout(queriedRangeLayout);
boundsLayout->addWidget(queriedRangePlaceholder);
QWidget*fixedRangePlaceholder= new QWidget(this);
QFormLayout*fixedRangeLayout= new QFormLayout;
QLineEdit*fixedLower= new QLineEdit;
QLineEdit*fixedUpper= new QLineEdit;
fixedRangeLayout->addRow(tr("Minimum Set Value:"),fixedLower);
fixedRangeLayout->addRow(tr("Maximum Set Value:"),fixedUpper);
fixedRangePlaceholder->setLayout(fixedRangeLayout);
boundsLayout->addWidget(fixedRangePlaceholder);
layout->addLayout(boundsLayout);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 18295 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="readaddress")
{
readAddress->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="writeaddress")
{
writeAddress->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="fixedrange")
{
if(node.attribute("value")=="true")
{
fixedRange->setCheckState(Qt::Checked);
}
else if(node.attribute("value")=="false")
{
fixedRange->setCheckState(Qt::Unchecked);
}
}
else if(node.attribute("name")=="fixedlower")
{
fixedLower->setText(node.attribute("value"));
}
else if(node.attribute("name")=="fixedupper")
{
fixedUpper->setText(node.attribute("value"));
}
else if(node.attribute("name")=="loweraddress")
{
lowerAddress->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="upperaddress")
{
upperAddress->setValue(node.attribute("value").toInt());
}
}
updateReadAddress(readAddress->value());
updateWriteAddress(writeAddress->value());
updateFixedRange(fixedRange->isChecked());
updateLower(fixedLower->text());
updateUpper(fixedUpper->text());
updateLowerAddress(lowerAddress->value());
updateUpperAddress(upperAddress->value());
connect(readAddress,SIGNAL(valueChanged(int)),
this,SLOT(updateReadAddress(int)));
connect(writeAddress,SIGNAL(valueChanged(int)),
this,SLOT(updateWriteAddress(int)));
connect(fixedRange,SIGNAL(toggled(bool)),this,SLOT(updateFixedRange(bool)));
connect(fixedLower,SIGNAL(textChanged(QString)),
this,SLOT(updateLower(QString)));
connect(fixedUpper,SIGNAL(textChanged(QString)),
this,SLOT(updateUpper(QString)));
connect(lowerAddress,SIGNAL(valueChanged(int)),
this,SLOT(updateLowerAddress(int)));
connect(upperAddress,SIGNAL(valueChanged(int)),
this,SLOT(updateUpperAddress(int)));
setLayout(layout);
}

void ModbusRtuDeviceTSvConfWidget::updateReadAddress(int newAddress)
{
updateAttribute("readaddress",QString("%1").arg(newAddress));
}

void ModbusRtuDeviceTSvConfWidget::updateWriteAddress(int newAddress)
{
updateAttribute("writeaddress",QString("%1").arg(newAddress));
}

void ModbusRtuDeviceTSvConfWidget::updateFixedRange(bool fixed)
{
if(fixed)
{
updateAttribute("fixedrange","true");
boundsLayout->setCurrentIndex(1);
}
else
{
updateAttribute("fixedrange","false");
boundsLayout->setCurrentIndex(0);
}
}

void ModbusRtuDeviceTSvConfWidget::updateLower(const QString&lower)
{
updateAttribute("fixedlower",lower);
}

void ModbusRtuDeviceTSvConfWidget::updateUpper(const QString&upper)
{
updateAttribute("fixedupper",upper);
}

void ModbusRtuDeviceTSvConfWidget::updateLowerAddress(int newAddress)
{
updateAttribute("loweraddress",QString("%1").arg(newAddress));
}

void ModbusRtuDeviceTSvConfWidget::updateUpperAddress(int newAddress)
{
updateAttribute("upperaddress",QString("%1").arg(newAddress));
}

/*:859*/
#line 599 "./typica.w"

/*815:*/
#line 16798 "./typica.w"

RoasterConfWidget::RoasterConfWidget(DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QVBoxLayout*layout= new QVBoxLayout;
QPushButton*addDeviceButton= new QPushButton(tr("Add Device"));
QMenu*deviceMenu= new QMenu;
NodeInserter*insertAction;
foreach(insertAction,AppInstance->topLevelNodeInserters)
{
connect(insertAction,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
deviceMenu->addAction(insertAction);
}
addDeviceButton->setMenu(deviceMenu);
layout->addWidget(addDeviceButton);
QPushButton*addAnnotationControlButton= new QPushButton(tr("Add Annotation Control"));
QMenu*annotationMenu= new QMenu;
NodeInserter*basicButtonInserter= new NodeInserter(tr("Annotation Button"),tr("Annotation Button"),"annotationbutton");
NodeInserter*countingButtonInserter= new NodeInserter(tr("Counting Button"),tr("Counting Button"),"reconfigurablebutton");
NodeInserter*spinBoxInserter= new NodeInserter(tr("Numeric Entry"),tr("Numeric Entry"),"annotationspinbox");
NodeInserter*freeAnnotationInserter= new NodeInserter(tr("Free Text"),
tr("Free Text"),
"freeannotation");
annotationMenu->addAction(basicButtonInserter);
annotationMenu->addAction(countingButtonInserter);
annotationMenu->addAction(spinBoxInserter);
annotationMenu->addAction(freeAnnotationInserter);
connect(basicButtonInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
connect(countingButtonInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
connect(spinBoxInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
connect(freeAnnotationInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
/*1137:*/
#line 144 "./valueannotation.w"

NodeInserter*valueAnnotationInserter= new NodeInserter(tr("Value Annotation"),
tr("Value Annotation"),
"valueannotation");
annotationMenu->addAction(valueAnnotationInserter);
connect(valueAnnotationInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));

/*:1137*//*1151:*/
#line 115 "./thresholdannotation.w"

NodeInserter*thresholdAnnotationInserter= new NodeInserter(tr("Threshold Annotation"),
tr("Threshold Annotation"),
"thresholdannotation");
annotationMenu->addAction(thresholdAnnotationInserter);
connect(thresholdAnnotationInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));

/*:1151*/
#line 16834 "./typica.w"

addAnnotationControlButton->setMenu(annotationMenu);
layout->addWidget(addAnnotationControlButton);

QPushButton*timersButton= new QPushButton(tr("Extra Timers"));
QMenu*timersMenu= new QMenu;
NodeInserter*coolingTimerInserter= new NodeInserter(tr("Cooling Timer"),tr("Cooling Timer"),"coolingtimer");
NodeInserter*rangeTimerInserter= new NodeInserter(tr("Range Timer"),tr("Range Timer"),"rangetimer");
NodeInserter*multirangeTimerInserter= new NodeInserter(tr("Multi-Range Timer"),tr("Multi-Range Timer"),"multirangetimer");
timersMenu->addAction(coolingTimerInserter);
timersMenu->addAction(rangeTimerInserter);
timersMenu->addAction(multirangeTimerInserter);
connect(coolingTimerInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
connect(rangeTimerInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
connect(multirangeTimerInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
timersButton->setMenu(timersMenu);
layout->addWidget(timersButton);

QPushButton*advancedButton= new QPushButton(tr("Advanced Features"));
QMenu*advancedMenu= new QMenu;
NodeInserter*linearsplineinserter= new NodeInserter(tr("Linear Spline Interpolated Series"),tr("Linear Spline Interpolated Series"),"linearspline");
advancedMenu->addAction(linearsplineinserter);
NodeInserter*translationinserter= new NodeInserter(tr("Profile Translation"),tr("Profile Translation"),"translation");
advancedMenu->addAction(translationinserter);
connect(linearsplineinserter,SIGNAL(triggered(QString,QString)),this,SLOT(insertChildNode(QString,QString)));
connect(translationinserter,SIGNAL(triggered(QString,QString)),this,SLOT(insertChildNode(QString,QString)));
/*1049:*/
#line 258 "./rate.w"

NodeInserter*rateOfChangeInserter= new NodeInserter(tr("Rate of Change"),tr("Rate of Change"),"rate");
connect(rateOfChangeInserter,SIGNAL(triggered(QString,QString)),this,SLOT(insertChildNode(QString,QString)));
advancedMenu->addAction(rateOfChangeInserter);

/*:1049*//*1063:*/
#line 272 "./mergeseries.w"

NodeInserter*mergeSeriesInserter= new NodeInserter(tr("Merge Series"),
tr("Merge"),
"mergeseries");
connect(mergeSeriesInserter,SIGNAL(triggered(QString,QString)),
this,SLOT(insertChildNode(QString,QString)));
advancedMenu->addAction(mergeSeriesInserter);

/*:1063*/
#line 16863 "./typica.w"

advancedButton->setMenu(advancedMenu);
layout->addWidget(advancedButton);

QHBoxLayout*idLayout= new QHBoxLayout;
QLabel*idLabel= new QLabel(tr("Machine ID for database:"));
idLayout->addWidget(idLabel);
QSpinBox*id= new QSpinBox;
idLayout->addWidget(id);
idLayout->addStretch();
layout->addLayout(idLayout);
QHBoxLayout*capacityLayout= new QHBoxLayout;
QCheckBox*capacityCheckEnabled= new QCheckBox(tr("Maximum batch size:"));
QDoubleSpinBox*capacity= new QDoubleSpinBox;
capacity->setMinimum(0.0);
capacity->setDecimals(3);
capacity->setMaximum(999999.999);
QComboBox*capacityUnit= new QComboBox;
capacityUnit->addItem("g");
capacityUnit->addItem("Kg");
capacityUnit->addItem("oz");
capacityUnit->addItem("Lb");
capacityUnit->setCurrentIndex(3);
capacityLayout->addWidget(capacityCheckEnabled);
capacityLayout->addWidget(capacity);
capacityLayout->addWidget(capacityUnit);
capacityLayout->addStretch();
layout->addLayout(capacityLayout);
layout->addStretch();
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 16892 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="databaseid")
{
id->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="checkcapacity")
{
capacityCheckEnabled->setChecked(node.attribute("value")=="true");
}
else if(node.attribute("name")=="capacity")
{
capacity->setValue(node.attribute("value").toDouble());
}
else if(node.attribute("name")=="capacityunit")
{
capacityUnit->setCurrentIndex(capacityUnit->findText(node.attribute("value")));
}
}
updateRoasterId(id->value());
connect(id,SIGNAL(valueChanged(int)),this,SLOT(updateRoasterId(int)));
connect(capacityCheckEnabled,SIGNAL(stateChanged(int)),this,SLOT(updateCapacityCheck(int)));
connect(capacity,SIGNAL(valueChanged(QString)),this,SLOT(updateCapacity(QString)));
connect(capacityUnit,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateCapacityUnit(QString)));
setLayout(layout);
}

/*:815*//*817:*/
#line 16938 "./typica.w"

void RoasterConfWidget::updateRoasterId(int id)
{
updateAttribute("databaseid",QString("%1").arg(id));
}

void RoasterConfWidget::updateCapacityCheck(int value)
{
updateAttribute("checkcapacity",value==Qt::Checked?"true":"false");
}

void RoasterConfWidget::updateCapacity(const QString&value)
{
updateAttribute("capacity",value);
}

void RoasterConfWidget::updateCapacityUnit(const QString&value)
{
updateAttribute("capacityunit",value);
}

/*:817*/
#line 600 "./typica.w"

/*863:*/
#line 18445 "./typica.w"

AnnotationButtonConfWidget::AnnotationButtonConfWidget(DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QLineEdit*buttonTextEdit= new QLineEdit;
QLineEdit*annotationTextEdit= new QLineEdit;
layout->addRow(tr("Button Text:"),buttonTextEdit);
layout->addRow(tr("Annotation Text:"),annotationTextEdit);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 18454 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="buttontext")
{
buttonTextEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="annotationtext")
{
annotationTextEdit->setText(node.attribute("value"));
}
}
updateButtonText(buttonTextEdit->text());
updateAnnotationText(annotationTextEdit->text());
connect(buttonTextEdit,SIGNAL(textEdited(QString)),this,SLOT(updateButtonText(QString)));
connect(annotationTextEdit,SIGNAL(textEdited(QString)),this,SLOT(updateAnnotationText(QString)));
setLayout(layout);
}

/*:863*//*864:*/
#line 18476 "./typica.w"

void AnnotationButtonConfWidget::updateButtonText(const QString&text)
{
updateAttribute("buttontext",text);
}

void AnnotationButtonConfWidget::updateAnnotationText(const QString&text)
{
updateAttribute("annotationtext",text);
}

/*:864*//*867:*/
#line 18514 "./typica.w"

ReconfigurableAnnotationButtonConfWidget::ReconfigurableAnnotationButtonConfWidget(DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QLineEdit*buttonTextEdit= new QLineEdit;
QLineEdit*annotationTextEdit= new QLineEdit;
annotationTextEdit->setText("%A-%1");
layout->addRow(tr("Button Text:"),buttonTextEdit);
layout->addRow(tr("Annotation Text:"),annotationTextEdit);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 18524 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="buttontext")
{
buttonTextEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="annotationtext")
{
annotationTextEdit->setText(node.attribute("value"));
}
}
updateButtonText(buttonTextEdit->text());
updateAnnotationText(annotationTextEdit->text());
connect(buttonTextEdit,SIGNAL(textEdited(QString)),this,SLOT(updateButtonText(QString)));
connect(annotationTextEdit,SIGNAL(textEdited(QString)),this,SLOT(updateAnnotationText(QString)));
QTextEdit*documentation= new QTextEdit;
documentation->setHtml(tr("If the <b>Annotation Text</b> contains <tt>%1</tt>, this will be replaced in the annotation with a number that increments each time the button is pressed."));
documentation->setReadOnly(true);
layout->addRow("",documentation);
setLayout(layout);
}

void ReconfigurableAnnotationButtonConfWidget::updateButtonText(const QString&text)
{
updateAttribute("buttontext",text);
}

void ReconfigurableAnnotationButtonConfWidget::updateAnnotationText(const QString&text)
{
updateAttribute("annotationtext",text);
}

/*:867*/
#line 601 "./typica.w"

/*870:*/
#line 18592 "./typica.w"

NoteSpinConfWidget::NoteSpinConfWidget(DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QLineEdit*labelEdit= new QLineEdit;
layout->addRow(tr("Control Label: "),labelEdit);
QLineEdit*minimumEdit= new QLineEdit;
layout->addRow(tr("Minimum Value: "),minimumEdit);
QLineEdit*maximumEdit= new QLineEdit;
layout->addRow(tr("Maximum Value: "),maximumEdit);
QSpinBox*precisionEdit= new QSpinBox;
precisionEdit->setMinimum(0);
precisionEdit->setMaximum(9);
layout->addRow(tr("Precision"),precisionEdit);
QLineEdit*pretext= new QLineEdit;
layout->addRow(tr("Prefix text"),pretext);
QLineEdit*posttext= new QLineEdit;
layout->addRow(tr("Suffix text"),posttext);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 18611 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="label")
{
labelEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="minimum")
{
minimumEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="maximum")
{
maximumEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="precision")
{
precisionEdit->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="pretext")
{
pretext->setText(node.attribute("value"));
}
else if(node.attribute("name")=="posttext")
{
posttext->setText(node.attribute("value"));
}
}
updateLabel(labelEdit->text());
updateMinimum(minimumEdit->text());
updateMaximum(maximumEdit->text());
updatePrecision(precisionEdit->value());
updatePretext(pretext->text());
updatePosttext(posttext->text());
connect(labelEdit,SIGNAL(textEdited(QString)),this,SLOT(updateLabel(QString)));
connect(minimumEdit,SIGNAL(textEdited(QString)),this,SLOT(updateMinimum(QString)));
connect(maximumEdit,SIGNAL(textEdited(QString)),this,SLOT(updateMaximum(QString)));
connect(precisionEdit,SIGNAL(valueChanged(int)),this,SLOT(updatePrecision(int)));
connect(pretext,SIGNAL(textEdited(QString)),this,SLOT(updatePretext(QString)));
connect(posttext,SIGNAL(textEdited(QString)),this,SLOT(updatePosttext(QString)));
setLayout(layout);
}

void NoteSpinConfWidget::updateLabel(const QString&text)
{
updateAttribute("label",text);
}

void NoteSpinConfWidget::updateMinimum(const QString&minimum)
{
updateAttribute("minimum",minimum);
}

void NoteSpinConfWidget::updateMaximum(const QString&maximum)
{
updateAttribute("maximum",maximum);
}

void NoteSpinConfWidget::updatePrecision(int precision)
{
updateAttribute("precision",QString("%1").arg(precision));
}

void NoteSpinConfWidget::updatePretext(const QString&text)
{
updateAttribute("pretext",text);
}

void NoteSpinConfWidget::updatePosttext(const QString&text)
{
updateAttribute("posttext",text);
}

/*:870*/
#line 602 "./typica.w"

/*354:*/
#line 7901 "./typica.w"

LinearCalibrator::LinearCalibrator(QObject*parent):
QObject(parent),Lo1(0),Lo2(0),Up1(1),Up2(1),sensitivitySetting(0.0),clamp(false)
{
connect(this,SIGNAL(measurement(Measurement)),this,SIGNAL(newData(Measurement)));
}

/*:354*//*355:*/
#line 7915 "./typica.w"

Measurement LinearCalibrator::newMeasurement(Measurement measure)
{
double outval= Lo1+(measure.temperature()-Lo2)*(Up1-Lo1)/(Up2-Lo2);
if(clamp)
{
if(outval<Lo1)
{
outval= Lo1;
}
else if(outval> Up1)
{
outval= Up1;
}
}
if(sensitivitySetting>=0.05)
{
int temp= qRound(outval/sensitivitySetting);
outval= temp*sensitivitySetting;
}
Measurement adjusted(outval,measure.time(),measure.scale());
emit measurement(adjusted);
return adjusted;
}

/*:355*//*356:*/
#line 7942 "./typica.w"

double LinearCalibrator::measuredLower()
{
return Lo2;
}

double LinearCalibrator::measuredUpper()
{
return Up2;
}

double LinearCalibrator::mappedLower()
{
return Lo1;
}

double LinearCalibrator::mappedUpper()
{
return Up1;
}

bool LinearCalibrator::isClosedRange()
{
return clamp;
}

void LinearCalibrator::setMeasuredLower(double lower)
{
Lo2= lower;
}

void LinearCalibrator::setMeasuredUpper(double upper)
{
Up2= upper;
}

void LinearCalibrator::setMappedLower(double lower)
{
Lo1= lower;
}

void LinearCalibrator::setMappedUpper(double upper)
{
Up1= upper;
}

void LinearCalibrator::setClosedRange(bool closed)
{
clamp= closed;
}

void LinearCalibrator::setSensitivity(double sensitivity)
{
sensitivitySetting= sensitivity;
}

double LinearCalibrator::sensitivity()
{
return sensitivitySetting;
}

/*:356*/
#line 603 "./typica.w"

/*361:*/
#line 8075 "./typica.w"

void LinearSplineInterpolator::add_pair(double source,double destination)
{
pairs->insert(source,destination);
make_interpolators();
}

void LinearSplineInterpolator::make_interpolators()
{
if(pairs->size()> 1)
{
while(interpolators->size()> 0)
{
LinearCalibrator*removed= interpolators->takeFirst();
removed->deleteLater();
}
QMap<double,double> ::const_iterator i= pairs->constBegin();
QMap<double,double> ::const_iterator j= i+1;
while(j!=pairs->constEnd())
{
LinearCalibrator*segment= new LinearCalibrator();
segment->setMeasuredLower(i.key());
segment->setMappedLower(i.value());
segment->setMeasuredUpper(j.key());
segment->setMappedUpper(j.value());
segment->setClosedRange(false);
interpolators->append(segment);
connect(segment,SIGNAL(measurement(Measurement)),this,SIGNAL(newData(Measurement)));
i++;
j++;
}
}
}

LinearSplineInterpolator::LinearSplineInterpolator(QObject*parent):
QObject(parent),pairs(new QMap<double,double> ),
interpolators(new QList<LinearCalibrator*> )
{

}

Measurement LinearSplineInterpolator::newMeasurement(Measurement measure)
{
QMap<double,double> ::const_iterator i= pairs->constBegin();
int index= -1;
while(i!=pairs->constEnd())
{
if(measure.temperature()<=i.key())
{
break;
}
i++;
index++;
}
if(index<0)
{
index= 0;
}
if(index>=interpolators->size())
{
index= interpolators->size()-1;
}
if(interpolators->at(index)!=NULL)
{
return interpolators->at(index)->newMeasurement(measure);
}
return Measurement();
}

/*:361*/
#line 604 "./typica.w"

/*1014:*/
#line 19959 "./typica.w"

LinearSplineInterpolationConfWidget::LinearSplineInterpolationConfWidget(DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),tablemodel(new SaltModel(2))
{
QFormLayout*layout= new QFormLayout;
QLineEdit*source= new QLineEdit;
layout->addRow(tr("Source column name:"),source);
QLineEdit*destination= new QLineEdit;
layout->addRow(tr("Destination column name:"),destination);
tablemodel->setHeaderData(0,Qt::Horizontal,"Input");
tablemodel->setHeaderData(1,Qt::Horizontal,"Output");
QTableView*mappingTable= new QTableView;
mappingTable->setModel(tablemodel);
NumericDelegate*delegate= new NumericDelegate;
mappingTable->setItemDelegate(delegate);
layout->addRow(tr("Mapping data:"),mappingTable);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 19975 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="source")
{
source->setText(node.attribute("value"));
}
else if(node.attribute("name")=="destination")
{
destination->setText(node.attribute("value"));
}
else if(node.attribute("name")=="sourcevalues")
{
/*1015:*/
#line 20014 "./typica.w"

QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
QStringList itemList= data.split(",");

/*:1015*/
#line 19989 "./typica.w"

int column= 0;
/*1016:*/
#line 20026 "./typica.w"

for(int j= 0;j<itemList.size();j++)
{
tablemodel->setData(tablemodel->index(j,column),
QVariant(itemList.at(j).toDouble()),
Qt::DisplayRole);
}

/*:1016*/
#line 19991 "./typica.w"


}
else if(node.attribute("name")=="destinationvalues")
{
/*1015:*/
#line 20014 "./typica.w"

QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
QStringList itemList= data.split(",");

/*:1015*/
#line 19996 "./typica.w"

int column= 1;
/*1016:*/
#line 20026 "./typica.w"

for(int j= 0;j<itemList.size();j++)
{
tablemodel->setData(tablemodel->index(j,column),
QVariant(itemList.at(j).toDouble()),
Qt::DisplayRole);
}

/*:1016*/
#line 19998 "./typica.w"

}
}
updateSourceColumn(source->text());
updateDestinationColumn(destination->text());
updateKnots();
connect(source,SIGNAL(textEdited(QString)),this,SLOT(updateSourceColumn(QString)));
connect(destination,SIGNAL(textEdited(QString)),this,SLOT(updateDestinationColumn(QString)));
connect(tablemodel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(updateKnots()));
setLayout(layout);
}

/*:1014*//*1017:*/
#line 20037 "./typica.w"

void LinearSplineInterpolationConfWidget::updateKnots()
{
updateAttribute("sourcevalues",tablemodel->arrayLiteral(0,Qt::DisplayRole));
updateAttribute("destinationvalues",tablemodel->arrayLiteral(1,Qt::DisplayRole));
}

void LinearSplineInterpolationConfWidget::updateSourceColumn(const QString&source)
{
updateAttribute("source",source);
}

void LinearSplineInterpolationConfWidget::updateDestinationColumn(const QString&dest)
{
updateAttribute("destination",dest);
}

/*:1017*/
#line 605 "./typica.w"

/*1034:*/
#line 20508 "./typica.w"

TranslationConfWidget::TranslationConfWidget(DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
temperatureValue(new QDoubleSpinBox),unitSelector(new QComboBox),
delaySelector(new QSpinBox)
{
unitSelector->addItem("Fahrenheit");
unitSelector->addItem("Celsius");
temperatureValue->setMinimum(0);
temperatureValue->setMaximum(1000);
QFormLayout*layout= new QFormLayout;
QLineEdit*column= new QLineEdit;
layout->addRow(tr("Column to match:"),column);
layout->addRow(tr("Unit:"),unitSelector);
layout->addRow(tr("Value:"),temperatureValue);
layout->addRow(tr("Start of batch safety delay:"),delaySelector);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 20524 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="column")
{
column->setText(node.attribute("value"));
}
else if(node.attribute("name")=="unit")
{
unitSelector->setCurrentIndex(unitSelector->findText(node.attribute("value")));
}
else if(node.attribute("name")=="value")
{
temperatureValue->setValue(node.attribute("value").toDouble());
}
else if(node.attribute("name")=="delay")
{
delaySelector->setValue(node.attribute("value").toInt());
}
}
updateMatchingColumn(column->text());
updateTemperature();
updateDelay();
connect(column,SIGNAL(textEdited(QString)),this,SLOT(updateMatchingColumn(QString)));
connect(unitSelector,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateTemperature()));
connect(temperatureValue,SIGNAL(valueChanged(double)),this,SLOT(updateTemperature()));
connect(delaySelector,SIGNAL(valueChanged(int)),this,SLOT(updateDelay()));
setLayout(layout);
}

/*:1034*//*1035:*/
#line 20559 "./typica.w"

void TranslationConfWidget::updateTemperature()
{
updateAttribute("unit",unitSelector->currentText());
updateAttribute("value",QString("%1").arg(temperatureValue->value()));
if(unitSelector->currentText()=="Fahrenheit")
{
updateAttribute("FValue",QString("%1").arg(temperatureValue->value()));
}
else
{
updateAttribute("FValue",QString("%1").arg(temperatureValue->value()*9/5+32));
}
}

void TranslationConfWidget::updateMatchingColumn(const QString&column)
{
updateAttribute("column",column);
}

void TranslationConfWidget::updateDelay()
{
updateAttribute("delay",QString("%1").arg(delaySelector->value()));
}

/*:1035*/
#line 606 "./typica.w"

/*873:*/
#line 24 "./freeannotation.w"

FreeAnnotationConfWidget::FreeAnnotationConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QLineEdit*labelEdit= new QLineEdit;
layout->addRow(tr("Label Text:"),labelEdit);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 32 "./freeannotation.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="labeltext")
{
labelEdit->setText(node.attribute("value"));
}
}
updateLabel(labelEdit->text());
connect(labelEdit,SIGNAL(textEdited(QString)),
this,SLOT(updateLabel(QString)));
setLayout(layout);
}

/*:873*//*874:*/
#line 49 "./freeannotation.w"

void FreeAnnotationConfWidget::updateLabel(const QString&text)
{
updateAttribute("labeltext",text);
}

/*:874*/
#line 607 "./typica.w"

/*1038:*/
#line 39 "./rate.w"

void RateOfChange::newMeasurement(Measurement measure)
{
cache.append(measure);
/*1039:*/
#line 64 "./rate.w"

if(cache.size()> 2)
{
bool done= false;
while(!done)
{
if(cache.front().time().secsTo(cache.back().time())> ct)
{
cache.removeFirst();
}
else if(cache.back().time()<cache.front().time())
{
cache.removeFirst();
done= true;
}
else
{
done= true;
}
if(cache.size()<3)
{
done= true;
}
}
}

/*:1039*/
#line 43 "./rate.w"

if(cache.size()>=2)
{
/*1040:*/
#line 96 "./rate.w"

int N= cache.size();
double SXY= 0;
double SX= 0;
double SXX= 0;
double SY= 0;
double y;
double x;
for(int i= 0;i<N;i++)
{
y= cache.at(i).temperature();
SY+= y;
x= cache.at(0).time().msecsTo(cache.at(i).time())/1000.0;
SX+= x;
SXX+= (x*x);
SXY+= (x*y);
}
double M= ((N*SXY)-(SX*SY))/((N*SXX)-(SX*SX));
Measurement value(M*st,cache.back().time(),cache.back().scale());
value.insert("relative",true);
emit newData(value);

/*:1040*/
#line 46 "./rate.w"

}
}

/*:1038*//*1041:*/
#line 120 "./rate.w"

RateOfChange::RateOfChange(int cachetime,int scaletime):ct(cachetime),st(1)
{
setScaleTime(scaletime);
}

void RateOfChange::setCacheTime(int seconds)
{
ct= seconds;
}

void RateOfChange::setScaleTime(int seconds)
{
st= (seconds> 0?seconds:1);
}

/*:1041*/
#line 608 "./typica.w"

/*877:*/
#line 26 "./settings.w"

SettingsWindow::SettingsWindow():QMainWindow(NULL)
{
QTabWidget*settingsTab= new QTabWidget;
DeviceConfigurationWindow*deviceSettings= new DeviceConfigurationWindow;
settingsTab->addTab(deviceSettings,tr("Roasters"));
GraphSettingsWidget*graphSettings= new GraphSettingsWidget;
settingsTab->addTab(graphSettings,tr("Graph"));
ColorSettingsWidget*colorSettings= new ColorSettingsWidget;
settingsTab->addTab(colorSettings,tr("Color"));
AdvancedSettingsWidget*advancedSettings= new AdvancedSettingsWidget;
settingsTab->addTab(advancedSettings,tr("Advanced"));
setCentralWidget(settingsTab);
}

/*:877*/
#line 609 "./typica.w"

/*882:*/
#line 27 "./graphsettings.w"

GraphSettingsWidget::GraphSettingsWidget():QWidget(NULL)
{
QTabWidget*graphCategories= new QTabWidget;
GraphSettingsRelativeTab*relative= new GraphSettingsRelativeTab;
graphCategories->addTab(relative,tr("Relative Temperatures"));
QVBoxLayout*layout= new QVBoxLayout;
layout->addWidget(graphCategories);
setLayout(layout);
}

/*:882*//*884:*/
#line 69 "./graphsettings.w"

GraphSettingsRelativeTab::GraphSettingsRelativeTab():QWidget(NULL),
colorEdit(new QLineEdit)
{
QSettings settings;
QVBoxLayout*layout= new QVBoxLayout;
QCheckBox*enable= new QCheckBox(tr("Graph relative temperatures"));
enable->setChecked(settings.value("settings/graph/relative/enable",true).toBool());
updateEnableSetting(enable->isChecked());
connect(enable,SIGNAL(toggled(bool)),this,SLOT(updateEnableSetting(bool)));
layout->addWidget(enable);
QHBoxLayout*colorLayout= new QHBoxLayout;
QLabel*colorLabel= new QLabel(tr("Axis color:"));
colorEdit->setText(settings.value("settings/graph/relative/color","#000000").toString());
updateColorSetting(colorEdit->text());
connect(colorEdit,SIGNAL(textChanged(QString)),this,SLOT(updateColorSetting(QString)));
QToolButton*colorPickerButton= new QToolButton();
colorPickerButton->setIcon(QIcon::fromTheme("applications-graphics"));
connect(colorPickerButton,SIGNAL(clicked()),this,SLOT(showColorPicker()));
colorLayout->addWidget(colorLabel);
colorLayout->addWidget(colorEdit);
colorLayout->addWidget(colorPickerButton);
colorLayout->addStretch();
layout->addLayout(colorLayout);
QHBoxLayout*unitLayout= new QHBoxLayout;
QLabel*unitLabel= new QLabel(tr("Unit"));
QComboBox*unitSelector= new QComboBox;
unitSelector->addItem(tr("Fahrenheit"));
unitSelector->addItem(tr("Celsius"));
unitSelector->setCurrentIndex(settings.value("settings/graph/relative/unit",0).toInt());
updateUnit(unitSelector->currentIndex());
connect(unitSelector,SIGNAL(currentIndexChanged(int)),this,SLOT(updateUnit(int)));
unitLayout->addWidget(unitLabel);
unitLayout->addWidget(unitSelector);
unitLayout->addStretch();
layout->addLayout(unitLayout);
QHBoxLayout*axisLayout= new QHBoxLayout;
QLabel*axisLabel= new QLabel(tr("Grid line positions (comma separated):"));
QLineEdit*axisEdit= new QLineEdit;
axisEdit->setText(settings.value("settings/graph/relative/grid","-300, -100, 0, 30, 65, 100").toString());
updateAxisSetting(axisEdit->text());
connect(axisEdit,SIGNAL(textChanged(QString)),this,SLOT(updateAxisSetting(QString)));
axisLayout->addWidget(axisLabel);
axisLayout->addWidget(axisEdit);
layout->addLayout(axisLayout);
layout->addStretch();
setLayout(layout);
}

/*:884*//*885:*/
#line 120 "./graphsettings.w"

void GraphSettingsRelativeTab::updateEnableSetting(bool enabled)
{
QSettings settings;
settings.setValue("settings/graph/relative/enable",enabled);
}

void GraphSettingsRelativeTab::updateColorSetting(const QString&color)
{
QSettings settings;
settings.setValue("settings/graph/relative/color",color);
}

void GraphSettingsRelativeTab::updateAxisSetting(const QString&gridList)
{
QSettings settings;
QString settingValue;
QStringList points= gridList.split(QRegExp("[\\s,]+"),QString::SkipEmptyParts);
QStringList numbers;
foreach(QString text,points)
{
bool okay= false;
text.toDouble(&okay);
if(okay)
{
numbers.append(text);
}
}
numbers.removeDuplicates();
settings.setValue("settings/graph/relative/grid",numbers.join(","));
}

void GraphSettingsRelativeTab::updateUnit(int unit)
{
QSettings settings;
settings.setValue("settings/graph/relative/unit",unit);
}

/*:885*//*886:*/
#line 163 "./graphsettings.w"

void GraphSettingsRelativeTab::showColorPicker()
{
QColor color= QColorDialog::getColor(QColor(colorEdit->text()),this);
colorEdit->setText(color.name());
}
#line 64 "./settings.w"

#line 1 "./colorsettings.w"
/*:886*/
#line 610 "./typica.w"

/*1087:*/
#line 682 "./dataqsdk.w"

DataqSdkDeviceConfWidget::DataqSdkDeviceConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
deviceIdStack(new QStackedWidget)
{
QVBoxLayout*layout= new QVBoxLayout;
QCheckBox*autoDetect= new QCheckBox("Automatically select device");
layout->addWidget(autoDetect);
QWidget*autoLayerWidget= new QWidget;
QHBoxLayout*autoLayerLayout= new QHBoxLayout;
QLabel*autoLabel= new QLabel(tr("Device number"));
QSpinBox*autoNumber= new QSpinBox;
autoNumber->setMinimum(1);
autoNumber->setMaximum(99);
autoLayerLayout->addWidget(autoLabel);
autoLayerLayout->addWidget(autoNumber);
autoLayerWidget->setLayout(autoLayerLayout);
QWidget*fixedLayerWidget= new QWidget;
QHBoxLayout*fixedLayerLayout= new QHBoxLayout;
QLabel*fixedLabel= new QLabel(tr("Device port"));
QComboBox*portSelection= new QComboBox;
portSelection->setEditable(true);
portSelection->addItems(DataqSdkDevice::detectHardware());
fixedLayerLayout->addWidget(fixedLabel);
fixedLayerLayout->addWidget(portSelection);
fixedLayerWidget->setLayout(fixedLayerLayout);
deviceIdStack->addWidget(autoLayerWidget);
deviceIdStack->addWidget(fixedLayerWidget);
layout->addWidget(deviceIdStack);
QPushButton*addChannelButton= new QPushButton(tr("Add Channel"));
layout->addWidget(addChannelButton);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 714 "./dataqsdk.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="autoSelect")
{
autoDetect->setChecked(node.attribute("value")=="true"?true:false);
}
else if(node.attribute("name")=="deviceNumber")
{
autoNumber->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="port")
{
int index= portSelection->findText(node.attribute("value"));
if(index> -1)
{
portSelection->setCurrentIndex(index);
}
else
{
portSelection->setEditText(node.attribute("value"));
}
}
}
updateAutoSelect(autoDetect->isChecked());
updateDeviceNumber(autoNumber->value());
updatePort(portSelection->currentText());
connect(autoDetect,SIGNAL(toggled(bool)),this,SLOT(updateAutoSelect(bool)));
connect(autoNumber,SIGNAL(valueChanged(int)),this,SLOT(updateDeviceNumber(int)));
connect(portSelection,SIGNAL(currentIndexChanged(QString)),this,SLOT(updatePort(QString)));
connect(addChannelButton,SIGNAL(clicked()),this,SLOT(addChannel()));
setLayout(layout);
}

/*:1087*//*1088:*/
#line 758 "./dataqsdk.w"

void DataqSdkDeviceConfWidget::updateAutoSelect(bool automatic)
{
if(automatic)
{
updateAttribute("autoSelect","true");
deviceIdStack->setCurrentIndex(0);
}
else
{
updateAttribute("autoSelect","false");
deviceIdStack->setCurrentIndex(1);
}
}

/*:1088*//*1089:*/
#line 775 "./dataqsdk.w"

void DataqSdkDeviceConfWidget::updateDeviceNumber(int deviceNumber)
{
updateAttribute("deviceNumber",QString("%1").arg(deviceNumber));
}

void DataqSdkDeviceConfWidget::updatePort(QString portId)
{
updateAttribute("port",portId);
}

/*:1089*//*1090:*/
#line 788 "./dataqsdk.w"

void DataqSdkDeviceConfWidget::addChannel()
{
insertChildNode(tr("Channel"),"dataqsdkchannel");
}

/*:1090*//*1093:*/
#line 868 "./dataqsdk.w"

DataqSdkChannelConfWidget::DataqSdkChannelConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
startButton(new QPushButton(tr("Start"))),
resetButton(new QPushButton(tr("Reset"))),
stopButton(new QPushButton(tr("Stop"))),
calibrator(new LinearCalibrator),
currentMeasurement(new QLineEdit),minimumMeasurement(new QLineEdit),
maximumMeasurement(new QLineEdit),averageMeasurement(new QLineEdit),
currentMapped(new QLineEdit),minimumMapped(new QLineEdit),
maximumMapped(new QLineEdit),averageMapped(new QLineEdit),
rmCount(0),cmCount(0),
rmin(std::numeric_limits<double> ::max()),
rmax(std::numeric_limits<double> ::min()),rmean(0),
cmin(std::numeric_limits<double> ::max()),
cmax(std::numeric_limits<double> ::min()),cmean(0)
{
/*1097:*/
#line 1107 "./dataqsdk.w"

QDomElement parentReference= model->referenceElement(model->data(index.parent(),Qt::UserRole).toString());
QDomNodeList deviceConfigData= parentReference.elementsByTagName("attribute");
QDomElement deviceNode;
QString configPort;
QString configAuto;
for(int i= 0;i<deviceConfigData.size();i++)
{
deviceNode= deviceConfigData.at(i).toElement();
if(deviceNode.attribute("name")=="autoSelect")
{
autoSelect= (deviceNode.attribute("value")=="true");
}
else if(deviceNode.attribute("name")=="deviceNumber")
{
configAuto= deviceNode.attribute("value");
}
else if(deviceNode.attribute("name")=="port")
{
configPort= deviceNode.attribute("value");
}
}
deviceID= autoSelect?configAuto:configPort;
channelOfInterest= index.row();

/*:1097*/
#line 886 "./dataqsdk.w"

resetButton->setEnabled(false);
stopButton->setEnabled(false);
connect(startButton,SIGNAL(clicked()),this,SLOT(startCalibration()));
connect(resetButton,SIGNAL(clicked()),this,SLOT(resetCalibration()));
connect(stopButton,SIGNAL(clicked()),this,SLOT(stopCalibration()));
QVBoxLayout*layout= new QVBoxLayout;
QFormLayout*topLayout= new QFormLayout;
QLineEdit*columnEdit= new QLineEdit;
topLayout->addRow(tr("Column name"),columnEdit);
QComboBox*unitSelector= new QComboBox;
unitSelector->addItem(tr("Temperature"));
unitSelector->addItem(tr("Control"));
topLayout->addRow(tr("Measurement type"),unitSelector);
QCheckBox*smoothingBox= new QCheckBox(tr("Enable smoothing"));
topLayout->addRow(smoothingBox);
layout->addLayout(topLayout);
QCheckBox*hideSeries= new QCheckBox(tr("Hide this channel"));
topLayout->addRow(hideSeries);
QLabel*calibrationLabel= new QLabel(tr("Calibration settings"));
layout->addWidget(calibrationLabel);
QHBoxLayout*calibrationLayout= new QHBoxLayout;
QFormLayout*calibrationControlsLayout= new QFormLayout;
QLineEdit*measuredLowerEdit= new QLineEdit;
measuredLowerEdit->setText("0");
QLineEdit*measuredUpperEdit= new QLineEdit;
measuredUpperEdit->setText("10");
QLineEdit*mappedLowerEdit= new QLineEdit;
mappedLowerEdit->setText("0");
QLineEdit*mappedUpperEdit= new QLineEdit;
mappedUpperEdit->setText("10");
calibrationControlsLayout->addRow(tr("Measured lower value"),measuredLowerEdit);
calibrationControlsLayout->addRow(tr("Mapped lower value"),mappedLowerEdit);
calibrationControlsLayout->addRow(tr("Measured upper value"),measuredUpperEdit);
calibrationControlsLayout->addRow(tr("Mapped upper value"),mappedUpperEdit);
QCheckBox*closedBox= new QCheckBox(tr("Closed range"));
calibrationControlsLayout->addRow(closedBox);
QLineEdit*sensitivityEdit= new QLineEdit;
sensitivityEdit->setText("0");
calibrationControlsLayout->addRow(tr("Discrete interval skip"),sensitivityEdit);
QVBoxLayout*calibrationTestLayout= new QVBoxLayout;
QHBoxLayout*deviceControlLayout= new QHBoxLayout;
deviceControlLayout->addWidget(startButton);
deviceControlLayout->addWidget(resetButton);
deviceControlLayout->addWidget(stopButton);
QFormLayout*indicatorLayout= new QFormLayout;
currentMeasurement->setReadOnly(true);
minimumMeasurement->setReadOnly(true);
maximumMeasurement->setReadOnly(true);
averageMeasurement->setReadOnly(true);
currentMapped->setReadOnly(true);
minimumMapped->setReadOnly(true);
maximumMapped->setReadOnly(true);
averageMapped->setReadOnly(true);
indicatorLayout->addRow(tr("Measured Values"),new QWidget);
indicatorLayout->addRow(tr("Current"),currentMeasurement);
indicatorLayout->addRow(tr("Minimum"),minimumMeasurement);
indicatorLayout->addRow(tr("Maximum"),maximumMeasurement);
indicatorLayout->addRow(tr("Mean"),averageMeasurement);
indicatorLayout->addRow(tr("Mapped Values"),new QWidget);
indicatorLayout->addRow(tr("Current Mapped"),currentMapped);
indicatorLayout->addRow(tr("Minimum Mapped"),minimumMapped);
indicatorLayout->addRow(tr("Maximum Mapped"),maximumMapped);
indicatorLayout->addRow(tr("Mean Mapped"),averageMapped);
calibrationTestLayout->addLayout(deviceControlLayout);
calibrationTestLayout->addLayout(indicatorLayout);
calibrationLayout->addLayout(calibrationControlsLayout);
calibrationLayout->addLayout(calibrationTestLayout);
layout->addLayout(calibrationLayout);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 955 "./dataqsdk.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="column")
{
columnEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="type")
{
unitSelector->setCurrentIndex(unitSelector->findText(node.attribute("value")));
}
else if(node.attribute("name")=="smoothing")
{
smoothingBox->setChecked(node.attribute("value")=="true");
}
else if(node.attribute("name")=="calibrationMeasuredLower")
{
measuredLowerEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="calibrationMeasuredUpper")
{
measuredUpperEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="calibrationMappedLower")
{
mappedLowerEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="calibrationMappedUpper")
{
mappedUpperEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="calibrationClosedInterval")
{
closedBox->setChecked(node.attribute("value")=="true");
}
else if(node.attribute("name")=="calibrationSensitivity")
{
sensitivityEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="hidden")
{
hideSeries->setChecked(node.attribute("value")=="true");
}
}
updateColumnName(columnEdit->text());
updateUnits(unitSelector->currentText());
updateSmoothingEnabled(smoothingBox->isChecked());
updateMeasuredLower(measuredLowerEdit->text());
updateMeasuredUpper(measuredUpperEdit->text());
updateMappedLower(mappedLowerEdit->text());
updateMappedUpper(mappedUpperEdit->text());
updateClosedInterval(closedBox->isChecked());
updateSensitivity(sensitivityEdit->text());
updateHidden(hideSeries->isChecked());
connect(columnEdit,SIGNAL(textChanged(QString)),
this,SLOT(updateColumnName(QString)));
connect(unitSelector,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updateUnits(QString)));
connect(smoothingBox,SIGNAL(toggled(bool)),
this,SLOT(updateSmoothingEnabled(bool)));
connect(measuredLowerEdit,SIGNAL(textChanged(QString)),
this,SLOT(updateMeasuredLower(QString)));
connect(mappedLowerEdit,SIGNAL(textChanged(QString)),
this,SLOT(updateMappedLower(QString)));
connect(measuredUpperEdit,SIGNAL(textChanged(QString)),
this,SLOT(updateMeasuredUpper(QString)));
connect(mappedUpperEdit,SIGNAL(textChanged(QString)),
this,SLOT(updateMappedUpper(QString)));
connect(closedBox,SIGNAL(toggled(bool)),
this,SLOT(updateClosedInterval(bool)));
connect(sensitivityEdit,SIGNAL(textChanged(QString)),
this,SLOT(updateSensitivity(QString)));
connect(hideSeries,SIGNAL(toggled(bool)),this,SLOT(updateHidden(bool)));
setLayout(layout);
}

/*:1093*//*1094:*/
#line 1038 "./dataqsdk.w"

void DataqSdkChannelConfWidget::updateUnits(const QString&unit)
{
updateAttribute("type",unit);
}

/*:1094*//*1095:*/
#line 1047 "./dataqsdk.w"

void DataqSdkChannelConfWidget::updateMeasuredLower(const QString&value)
{
updateAttribute("calibrationMeasuredLower",value);
calibrator->setMeasuredLower(value.toDouble());
}

void DataqSdkChannelConfWidget::updateMeasuredUpper(const QString&value)
{
updateAttribute("calibrationMeasuredUpper",value);
calibrator->setMeasuredUpper(value.toDouble());
}

void DataqSdkChannelConfWidget::updateMappedLower(const QString&value)
{
updateAttribute("calibrationMappedLower",value);
calibrator->setMappedLower(value.toDouble());
}

void DataqSdkChannelConfWidget::updateMappedUpper(const QString&value)
{
updateAttribute("calibrationMappedUpper",value);
calibrator->setMappedUpper(value.toDouble());
}

void DataqSdkChannelConfWidget::updateClosedInterval(bool closed)
{
updateAttribute("calibrationClosedInterval",closed?"true":"false");
calibrator->setClosedRange(closed);
}

void DataqSdkChannelConfWidget::updateSmoothingEnabled(bool enabled)
{
updateAttribute("smoothing",enabled?"true":"false");
}

void DataqSdkChannelConfWidget::updateSensitivity(const QString&value)
{
updateAttribute("calibrationSensitivity",value);
calibrator->setSensitivity(value.toDouble());
}

void DataqSdkChannelConfWidget::updateHidden(bool hidden)
{
updateAttribute("hidden",hidden?"true":"false");
}

/*:1095*//*1098:*/
#line 1136 "./dataqsdk.w"

void DataqSdkChannelConfWidget::startCalibration()
{
startButton->setEnabled(false);
stopButton->setEnabled(true);
resetButton->setEnabled(true);
calibrationDevice= new DataqSdkDevice(deviceID);
Channel*channel;
for(unsigned int i= 0;i<=channelOfInterest;i++)
{
channel= calibrationDevice->newChannel(Units::Unitless);
}
connect(channel,SIGNAL(newData(Measurement)),this,SLOT(updateInput(Measurement)));
connect(channel,SIGNAL(newData(Measurement)),calibrator,SLOT(newMeasurement(Measurement)));
connect(calibrator,SIGNAL(newData(Measurement)),this,SLOT(updateOutput(Measurement)));
calibrationDevice->setClockRate(6.0/(1.0+channelOfInterest));
calibrationDevice->start();
}

void DataqSdkChannelConfWidget::stopCalibration()
{
startButton->setEnabled(true);
stopButton->setEnabled(false);
resetButton->setEnabled(false);
calibrationDevice->deleteLater();
/*1100:*/
#line 1181 "./dataqsdk.w"

rmCount= 0;
cmCount= 0;
rmin= std::numeric_limits<double> ::max();
rmax= std::numeric_limits<double> ::min();
rmean= 0;
cmin= std::numeric_limits<double> ::max();
cmax= std::numeric_limits<double> ::min();
cmean= 0;

/*:1100*/
#line 1161 "./dataqsdk.w"

}

/*:1098*//*1099:*/
#line 1172 "./dataqsdk.w"

void DataqSdkChannelConfWidget::resetCalibration()
{
/*1100:*/
#line 1181 "./dataqsdk.w"

rmCount= 0;
cmCount= 0;
rmin= std::numeric_limits<double> ::max();
rmax= std::numeric_limits<double> ::min();
rmean= 0;
cmin= std::numeric_limits<double> ::max();
cmax= std::numeric_limits<double> ::min();
cmean= 0;

/*:1100*/
#line 1175 "./dataqsdk.w"

}

/*:1099*//*1101:*/
#line 1195 "./dataqsdk.w"

void DataqSdkChannelConfWidget::updateInput(Measurement measure)
{
double nv= measure.temperature();
currentMeasurement->setText(QString("%1").arg(nv));
rmin= qMin(nv,rmin);
minimumMeasurement->setText(QString("%1").arg(rmin));
rmax= qMax(nv,rmax);
maximumMeasurement->setText(QString("%1").arg(rmax));
rmean= ((rmean*rmCount)+nv)/(rmCount+1);
rmCount++;
averageMeasurement->setText(QString("%1").arg(rmean));
}

void DataqSdkChannelConfWidget::updateOutput(Measurement measure)
{
double nv= measure.temperature();
currentMapped->setText(QString("%1").arg(nv));
cmin= qMin(nv,cmin);
minimumMapped->setText(QString("%1").arg(cmin));
cmax= qMax(nv,cmax);
maximumMapped->setText(QString("%1").arg(cmax));
cmean= ((cmean*cmCount)+nv)/(cmCount+1);
cmCount++;
averageMapped->setText(QString("%1").arg(cmean));
}

/*:1101*//*1102:*/
#line 1224 "./dataqsdk.w"

void DataqSdkChannelConfWidget::updateColumnName(const QString&value)
{
updateAttribute("column",value);
}


/*:1102*/
#line 611 "./typica.w"

/*1126:*/
#line 423 "./scales.w"

SerialScaleConfWidget::SerialScaleConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
port(new PortSelector),baud(new BaudSelector),parity(new ParitySelector),
flow(new FlowSelector),stop(new StopSelector),
weighcommand(new QLineEdit("!KP")),commandterminator(new QComboBox)
{
QFormLayout*layout= new QFormLayout;
layout->addRow(tr("Port:"),port);
connect(port,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updatePort(QString)));
connect(port,SIGNAL(editTextChanged(QString)),
this,SLOT(updatePort(QString)));
layout->addRow(tr("Baud:"),baud);
connect(baud,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updateBaudRate(QString)));
layout->addRow(tr("Parity:"),parity);
connect(parity,SIGNAL(currentIndexChanged(int)),
this,SLOT(updateParity(int)));
layout->addRow(tr("Flow Control:"),flow);
connect(flow,SIGNAL(currentIndexChanged(int)),
this,SLOT(updateFlowControl(int)));
layout->addRow(tr("Stop Bits:"),stop);
connect(stop,SIGNAL(currentIndexChanged(int)),
this,SLOT(updateStopBits(int)));
layout->addRow(tr("Weigh Command:"),weighcommand);
connect(weighcommand,SIGNAL(textChanged(QString)),
this,SLOT(updateWeighCommand(QString)));
commandterminator->addItem("CRLF");
commandterminator->addItem("CR");
commandterminator->addItem("LF");
layout->addRow(tr("Command Terminator:"),commandterminator);
connect(commandterminator,SIGNAL(currentIndexChanged(QString)),
this,SLOT(updateCommandTerminator(QString)));

/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 459 "./scales.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="port")
{
int j= port->findText(node.attribute("value"));
if(j>=0)
{
port->setCurrentIndex(j);
}
else
{
port->insertItem(0,node.attribute("value"));
port->setCurrentIndex(0);
}
}
else if(node.attribute("name")=="baudrate")
{
baud->setCurrentIndex(baud->findText(node.attribute("value")));
}
else if(node.attribute("name")=="parity")
{
parity->setCurrentIndex(parity->findData(node.attribute("value")));
}
else if(node.attribute("name")=="flowcontrol")
{
flow->setCurrentIndex(flow->findData(node.attribute("value")));
}
else if(node.attribute("name")=="stopbits")
{
stop->setCurrentIndex(stop->findData(node.attribute("value")));
}
else if(node.attribute("name")=="weighcommand")
{
weighcommand->setText(node.attribute("value"));
}
else if(node.attribute("name")=="commandterminator")
{
commandterminator->setCurrentIndex(
commandterminator->findText(node.attribute("value")));
}
}
updatePort(port->currentText());
updateBaudRate(baud->currentText());
updateParity(parity->currentIndex());
updateFlowControl(flow->currentIndex());
updateStopBits(stop->currentIndex());
updateWeighCommand(weighcommand->text());
updateCommandTerminator(commandterminator->currentText());
setLayout(layout);
}

/*:1126*//*1127:*/
#line 514 "./scales.w"

void SerialScaleConfWidget::updatePort(const QString&newPort)
{
updateAttribute("port",newPort);
}

void SerialScaleConfWidget::updateBaudRate(const QString&rate)
{
updateAttribute("baudrate",rate);
}

void SerialScaleConfWidget::updateParity(int index)
{
updateAttribute("parity",parity->itemData(index).toString());
}

void SerialScaleConfWidget::updateFlowControl(int index)
{
updateAttribute("flowcontrol",flow->itemData(index).toString());
}

void SerialScaleConfWidget::updateStopBits(int index)
{
updateAttribute("stopbits",stop->itemData(index).toString());
}

void SerialScaleConfWidget::updateWeighCommand(const QString&command)
{
updateAttribute("weighcommand",command);
}

void SerialScaleConfWidget::updateCommandTerminator(const QString&terminator)
{
updateAttribute("commandterminator",terminator);
}

/*:1127*/
#line 612 "./typica.w"

/*1139:*/
#line 195 "./valueannotation.w"

void ValueAnnotation::newMeasurement(Measurement measure)
{
for(int i= 0;i<values.size();i++)
{
if(measure.temperature()> values.at(i)-tolerance&&
measure.temperature()<values.at(i)+tolerance)
{
if(i!=lastIndex)
{
lastIndex= i;
emit annotation(annotations.at(i),measurementColumn,annotationColumn);
}
}
}
}

/*:1139*//*1140:*/
#line 216 "./valueannotation.w"

void ValueAnnotation::annotate()
{
if(lastIndex> -1)
{
emit annotation(annotations.at(lastIndex),measurementColumn,annotationColumn);
}
}

/*:1140*//*1141:*/
#line 228 "./valueannotation.w"

void ValueAnnotation::setAnnotation(double value,const QString&annotation)
{
values.append(value);
annotations.append(annotation);
}

/*:1141*//*1142:*/
#line 237 "./valueannotation.w"

void ValueAnnotation::setAnnotationColumn(int column)
{
annotationColumn= column;
}

void ValueAnnotation::setTemperatureColumn(int column)
{
measurementColumn= column;
}

void ValueAnnotation::setTolerance(double epsilon)
{
tolerance= epsilon;
}

/*:1142*//*1143:*/
#line 255 "./valueannotation.w"

ValueAnnotation::ValueAnnotation():QObject(),
lastIndex(-1),annotationColumn(2),measurementColumn(1),tolerance(0.05)
{

}

/*:1143*/
#line 613 "./typica.w"

/*1131:*/
#line 33 "./valueannotation.w"

ValueAnnotationConfWidget::ValueAnnotationConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
tablemodel(new SaltModel(2))
{
QFormLayout*layout= new QFormLayout;
QLineEdit*source= new QLineEdit;
layout->addRow(tr("Source column name:"),source);
QCheckBox*noteOnStart= new QCheckBox(tr("Produce Start State Annotation"));
noteOnStart->setChecked(true);
layout->addRow(noteOnStart);
tablemodel->setHeaderData(0,Qt::Horizontal,"Value");
tablemodel->setHeaderData(1,Qt::Horizontal,"Annotation");
QTableView*annotationTable= new QTableView;
annotationTable->setModel(tablemodel);
NumericDelegate*delegate= new NumericDelegate;
annotationTable->setItemDelegateForColumn(0,delegate);
layout->addRow(tr("Annotations for values:"),annotationTable);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 52 "./valueannotation.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="source")
{
source->setText(node.attribute("value"));
}
else if(node.attribute("name")=="emitOnStart")
{
noteOnStart->setChecked(node.attribute("value")=="true"?true:false);
}
else if(node.attribute("name")=="measuredValues")
{
/*1015:*/
#line 20014 "./typica.w"

QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
QStringList itemList= data.split(",");

/*:1015*/
#line 66 "./valueannotation.w"

int column= 0;
/*1016:*/
#line 20026 "./typica.w"

for(int j= 0;j<itemList.size();j++)
{
tablemodel->setData(tablemodel->index(j,column),
QVariant(itemList.at(j).toDouble()),
Qt::DisplayRole);
}

/*:1016*/
#line 68 "./valueannotation.w"

}
else if(node.attribute("name")=="annotations")
{
/*1132:*/
#line 89 "./valueannotation.w"

QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
QStringList itemList= data.split(",");
for(int i= 0;i<itemList.size();i++)
{
itemList[i]= itemList[i].simplified();
}

/*:1132*/
#line 72 "./valueannotation.w"

int column= 1;
/*1133:*/
#line 104 "./valueannotation.w"

for(int i= 0;i<itemList.size();i++)
{
tablemodel->setData(tablemodel->index(i,column),
QVariant(itemList.at(i)),
Qt::DisplayRole);
}

/*:1133*/
#line 74 "./valueannotation.w"

}
}
updateSourceColumn(source->text());
updateStart(noteOnStart->isChecked());
updateAnnotations();
connect(source,SIGNAL(textEdited(QString)),this,SLOT(updateSourceColumn(QString)));
connect(noteOnStart,SIGNAL(toggled(bool)),this,SLOT(updateStart(bool)));
connect(tablemodel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(updateAnnotations()));
setLayout(layout);
}

/*:1131*//*1134:*/
#line 115 "./valueannotation.w"

void ValueAnnotationConfWidget::updateAnnotations()
{
updateAttribute("measuredValues",tablemodel->arrayLiteral(0,Qt::DisplayRole));
updateAttribute("annotations",tablemodel->arrayLiteral(1,Qt::DisplayRole));
}

/*:1134*//*1135:*/
#line 125 "./valueannotation.w"

void ValueAnnotationConfWidget::updateSourceColumn(const QString&source)
{
updateAttribute("source",source);
}

void ValueAnnotationConfWidget::updateStart(bool noteOnStart)
{
updateAttribute("emitOnStart",noteOnStart?"true":"false");
}

/*:1135*/
#line 614 "./typica.w"

/*916:*/
#line 44 "./modbus.w"

ModbusNGConfWidget::ModbusNGConfWidget(DeviceTreeModel*model,const QModelIndex&index):
BasicDeviceConfigurationWidget(model,index),m_parity(new ParitySelector),
m_flow(new FlowSelector),m_stop(new StopSelector)
{
QFormLayout*layout= new QFormLayout;
PortSelector*port= new PortSelector;
BaudSelector*baud= new BaudSelector;
QPushButton*newInput= new QPushButton(tr("Add Input Channel"));
layout->addRow(QString(tr("Port:")),port);
layout->addRow(QString(tr("Baud rate:")),baud);
layout->addRow(QString(tr("Parity:")),m_parity);
layout->addRow(QString(tr("Flow control:")),m_flow);
layout->addRow(QString(tr("Stop bits:")),m_stop);
layout->addRow(newInput);

/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 60 "./modbus.w"


for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="port")
{
int idx= port->findText(node.attribute("value"));
if(idx>=0)
{
port->setCurrentIndex(idx);
}
else
{
port->addItem(node.attribute("value"));
}
}
else if(node.attribute("name")=="baud")
{
baud->setCurrentIndex(baud->findText(node.attribute("value")));
}
else if(node.attribute("name")=="parity")
{
m_parity->setCurrentIndex(m_parity->findData(node.attribute("value")));
}
else if(node.attribute("name")=="flow")
{
m_flow->setCurrentIndex(m_flow->findData(node.attribute("value")));
}
else if(node.attribute("name")=="stop")
{
m_stop->setCurrentIndex(m_stop->findData(node.attribute("value")));
}
}

updatePort(port->currentText());
updateBaudRate(baud->currentText());
updateParity(m_parity->currentIndex());
updateFlowControl(m_flow->currentIndex());
updateStopBits(m_stop->currentIndex());
connect(port,SIGNAL(currentIndexChanged(QString)),this,SLOT(updatePort(QString)));
connect(port,SIGNAL(editTextChanged(QString)),this,SLOT(updatePort(QString)));
connect(baud,SIGNAL(currentIndexChanged(QString)),this,SLOT(updateBaudRate(QString)));
connect(m_parity,SIGNAL(currentIndexChanged(int)),this,SLOT(updateParity(int)));
connect(m_flow,SIGNAL(currentIndexChanged(int)),
this,SLOT(updateFlowControl(int)));
connect(m_stop,SIGNAL(currentIndexChanged(int)),this,SLOT(updateStopBits(int)));
connect(newInput,SIGNAL(clicked()),this,SLOT(addInput()));

setLayout(layout);
}

void ModbusNGConfWidget::updatePort(const QString&value)
{
updateAttribute("port",value);
}

void ModbusNGConfWidget::updateBaudRate(const QString&value)
{
updateAttribute("baud",value);
}

void ModbusNGConfWidget::updateParity(int value)
{
updateAttribute("parity",m_parity->itemData(value).toString());
}

void ModbusNGConfWidget::updateFlowControl(int value)
{
updateAttribute("flow",m_flow->itemData(value).toString());
}

void ModbusNGConfWidget::updateStopBits(int value)
{
updateAttribute("stop",m_stop->itemData(value).toString());
}

void ModbusNGConfWidget::addInput()
{
insertChildNode(tr("Input"),"modbusnginput");
}

/*:916*//*918:*/
#line 164 "./modbus.w"

ModbusNGInputConfWidget::ModbusNGInputConfWidget(DeviceTreeModel*model,const QModelIndex&index):BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QSpinBox*station= new QSpinBox;
station->setMinimum(1);
station->setMaximum(247);
layout->addRow(tr("Station ID"),station);
QComboBox*function= new QComboBox;
function->addItem("3","3");
function->addItem("4","4");
function->setCurrentIndex(1);
layout->addRow(tr("Function"),function);
ShortHexSpinBox*address= new ShortHexSpinBox;
layout->addRow(tr("Address"),address);
QComboBox*format= new QComboBox;
format->addItem(tr("16 bits fixed point"),"16fixedint");
format->addItem(tr("32 bits floating point (High Low)"),"32floathl");
format->addItem(tr("32 bits floating point (Low High)"),"32floatlh");
layout->addRow(tr("Data format"),format);
QSpinBox*decimals= new QSpinBox;
decimals->setMinimum(0);
decimals->setMaximum(9);
layout->addRow(tr("Decimal places"),decimals);
QComboBox*unit= new QComboBox;
unit->addItem("Celsius","C");
unit->addItem("Fahrenheit","F");
unit->addItem("Control","Control");
unit->setCurrentIndex(1);
layout->addRow(tr("Unit"),unit);
QLineEdit*column= new QLineEdit;
layout->addRow(tr("Column name"),column);
QCheckBox*hidden= new QCheckBox(tr("Hide this channel"));
layout->addRow(hidden);

/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 199 "./modbus.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="station")
{
station->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="function")
{
function->setCurrentIndex(function->findText(node.attribute("value")));
}
else if(node.attribute("name")=="address")
{
address->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="format")
{
format->setCurrentIndex(format->findData(node.attribute("value")));
}
else if(node.attribute("name")=="decimals")
{
decimals->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="unit")
{
unit->setCurrentIndex(unit->findData(node.attribute("value")));
}
else if(node.attribute("name")=="column")
{
column->setText(node.attribute("value"));
}
else if(node.attribute("name")=="hidden")
{
hidden->setChecked(node.attribute("value")=="true"?true:false);
}
}
updateStation(station->value());
updateFunction(function->currentIndex());
updateAddress(address->value());
updateFormat(format->currentIndex());
updateDecimals(decimals->value());
updateUnit(unit->currentIndex());
updateColumnName(column->text());
updateHidden(hidden->isChecked());

connect(station,SIGNAL(valueChanged(int)),this,SLOT(updateStation(int)));
connect(function,SIGNAL(currentIndexChanged(int)),this,SLOT(updateFunction(int)));
connect(address,SIGNAL(valueChanged(int)),this,SLOT(updateAddress(int)));
connect(format,SIGNAL(currentIndexChanged(int)),this,SLOT(updateFormat(int)));
connect(decimals,SIGNAL(valueChanged(int)),this,SLOT(updateDecimals(int)));
connect(unit,SIGNAL(currentIndexChanged(int)),this,SLOT(updateUnit(int)));
connect(column,SIGNAL(textEdited(QString)),this,SLOT(updateColumnName(QString)));
connect(hidden,SIGNAL(toggled(bool)),this,SLOT(updateHidden(bool)));

setLayout(layout);
}

void ModbusNGInputConfWidget::updateStation(int value)
{
updateAttribute("station",QString("%1").arg(value));
}

void ModbusNGInputConfWidget::updateFunction(int value)
{
updateAttribute("function",QString("%1").arg(value==0?"3":"4"));
}

void ModbusNGInputConfWidget::updateAddress(int value)
{
updateAttribute("address",QString("%1").arg(value));
}

void ModbusNGInputConfWidget::updateFormat(int value)
{
switch(value)
{
case 0:
updateAttribute("format","16fixedint");
break;
case 1:
updateAttribute("format","32floathl");
break;
case 2:
updateAttribute("format","32floatlh");
break;
}
}

void ModbusNGInputConfWidget::updateDecimals(int value)
{
updateAttribute("decimals",QString("%1").arg(value));
}

void ModbusNGInputConfWidget::updateUnit(int value)
{
switch(value)
{
case 0:
updateAttribute("unit","C");
break;
case 1:
updateAttribute("unit","F");
break;
case 2:
updateAttribute("unit","Control");
break;
}
}

void ModbusNGInputConfWidget::updateColumnName(const QString&value)
{
updateAttribute("column",value);
}

void ModbusNGInputConfWidget::updateHidden(bool value)
{
updateAttribute("hidden",value?"true":"false");
}

/*:918*//*923:*/
#line 403 "./modbus.w"

ModbusNG::ModbusNG(DeviceTreeModel*model,const QModelIndex&index):
QObject(NULL),messageDelayTimer(new QTimer),commTimeout(new QTimer),
rateLimiter(new QTimer),scanPosition(0),waiting(false)
{
QDomElement portReferenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList portConfigData= portReferenceElement.elementsByTagName("attribute");
QDomElement node;
QVariantMap attributes;
for(int i= 0;i<portConfigData.size();i++)
{
node= portConfigData.at(i).toElement();
attributes.insert(node.attribute("name"),node.attribute("value"));
}
port= new QextSerialPort(attributes.value("port").toString(),
QextSerialPort::EventDriven);
port->setBaudRate((BaudRateType)(attributes.value("baud").toInt()));
port->setDataBits(DATA_8);
port->setParity((ParityType)attributes.value("parity").toInt());
port->setStopBits((StopBitsType)attributes.value("stop").toInt());
port->setFlowControl((FlowType)attributes.value("flow").toInt());
delayTime= (int)(((double)(1)/(double)(attributes.value("baud").toInt()))*144000.0);
messageDelayTimer->setSingleShot(true);
commTimeout->setSingleShot(true);
rateLimiter->setSingleShot(true);
rateLimiter->setInterval(0);
connect(messageDelayTimer,SIGNAL(timeout()),this,SLOT(sendNextMessage()));
connect(commTimeout,SIGNAL(timeout()),this,SLOT(timeout()));
connect(port,SIGNAL(readyRead()),this,SLOT(dataAvailable()));
connect(rateLimiter,SIGNAL(timeout()),this,SLOT(rateLimitTimeout()));
if(!port->open(QIODevice::ReadWrite))
{
qDebug()<<"Failed to open serial port";
}
for(int i= 0;i<model->rowCount(index);i++)
{
QModelIndex channelIndex= model->index(i,0,index);
QDomElement channelReferenceElement= 
model->referenceElement(model->data(channelIndex,Qt::UserRole).toString());
QDomNodeList channelConfigData= 
channelReferenceElement.elementsByTagName("attribute");
QDomElement channelNode;
QVariantMap channelAttributes;
for(int j= 0;j<channelConfigData.size();j++)
{
channelNode= channelConfigData.at(j).toElement();
channelAttributes.insert(channelNode.attribute("name"),
channelNode.attribute("value"));
}
ModbusScanItem scanItem;
QString format= channelAttributes.value("format").toString();
if(format=="16fixedint")
{
scanItem.format= Int16;
}
else if(format=="32floathl")
{
scanItem.format= FloatHL;
}
else if(format=="32floatlh")
{
scanItem.format= FloatLH;
}
scanItem.request.append((char)channelAttributes.value("station").toInt());
scanItem.request.append((char)channelAttributes.value("function").toInt());
quint16 startAddress= (quint16)channelAttributes.value("address").toInt();
char*startAddressBytes= (char*)&startAddress;
scanItem.request.append(startAddressBytes[1]);
scanItem.request.append(startAddressBytes[0]);
scanItem.request.append((char)0x00);
if(scanItem.format==Int16)
{
scanItem.request.append((char)0x01);
}
else
{
scanItem.request.append((char)0x02);
}
quint16 crc= calculateCRC(scanItem.request);
char*crcBytes= (char*)&crc;
scanItem.request.append(crcBytes[0]);
scanItem.request.append(crcBytes[1]);
scanItem.decimalPosition= channelAttributes.value("decimals").toInt();
if(channelAttributes.value("unit").toString()=="C")
{
scanItem.unit= Units::Celsius;
channelTypeList.append("T");
}
else if(channelAttributes.value("unit").toString()=="F")
{
scanItem.unit= Units::Fahrenheit;
channelTypeList.append("T");
}
else
{
scanItem.unit= Units::Unitless;
channelTypeList.append("C");
}
scanList.append(scanItem);
lastMeasurement.append(0.0);
channels.append(new Channel);
channelNames.append(channelAttributes.value("column").toString());
hiddenStates.append(
channelAttributes.value("hidden").toString()=="true"?true:false);
channelLabels.append(model->data(channelIndex,0).toString());
}
messageDelayTimer->start();
}

ModbusNG::~ModbusNG()
{
commTimeout->stop();
messageDelayTimer->stop();
port->close();
}

void ModbusNG::sendNextMessage()
{
if(scanList.length()> 0&&!waiting)
{
port->write(scanList.at(scanPosition).request);
commTimeout->start(2000);
messageDelayTimer->start(delayTime);
waiting= true;
}
}

void ModbusNG::timeout()
{
qDebug()<<"Communications timeout.";
messageDelayTimer->start();
}

void ModbusNG::rateLimitTimeout()
{
messageDelayTimer->start();
}

void ModbusNG::dataAvailable()
{
if(messageDelayTimer->isActive())
{
messageDelayTimer->stop();
}
responseBuffer.append(port->readAll());
if(responseBuffer.size()<5)
{
return;
}
if(responseBuffer.size()<5+responseBuffer.at(2))
{
return;
}
responseBuffer= responseBuffer.left(5+responseBuffer.at(2));
commTimeout->stop();
if(calculateCRC(responseBuffer)==0)
{
quint16 intresponse;
float floatresponse;
char*ibytes= (char*)&intresponse;
char*fbytes= (char*)&floatresponse;
double output;
switch(scanList.at(scanPosition).format)
{
case Int16:
ibytes[0]= responseBuffer.at(4);
ibytes[1]= responseBuffer.at(3);
output= intresponse;
for(int i= 0;i<scanList.at(scanPosition).decimalPosition;i++)
{
output/= 10;
}
break;
case FloatHL:
fbytes[0]= responseBuffer.at(4);
fbytes[1]= responseBuffer.at(3);
fbytes[2]= responseBuffer.at(6);
fbytes[3]= responseBuffer.at(5);
output= floatresponse;
break;
case FloatLH:
fbytes[0]= responseBuffer.at(6);
fbytes[1]= responseBuffer.at(5);
fbytes[2]= responseBuffer.at(4);
fbytes[3]= responseBuffer.at(3);
output= floatresponse;
break;
}
if(scanList.at(scanPosition).unit==Units::Celsius)
{
output= output*9.0/5.0+32.0;
}
scanList.at(scanPosition).lastValue= output;
}
else
{
qDebug()<<"CRC failed";
}
scanPosition= (scanPosition+1)%scanList.size();
if(scanPosition==0)
{
QTime time= QTime::currentTime();
bool doOutput= false;
for(int i= 0;i<scanList.size();i++)
{
if(scanList.at(i).lastValue!=lastMeasurement.at(i))
{
doOutput= true;
break;
}
}
if(doOutput)
{
for(int i= 0;i<scanList.size();i++)
{
lastMeasurement[i]= scanList.at(i).lastValue;
if(scanList.at(scanPosition).unit==Units::Unitless)
{
channels.at(i)->input(Measurement(scanList.at(i).lastValue,time,Units::Unitless));
}
else
{
channels.at(i)->input(Measurement(scanList.at(i).lastValue,time,Units::Fahrenheit));
}
}
}
}
responseBuffer.clear();
waiting= false;
if(scanPosition==0)
{
rateLimiter->start();
}
else
{
messageDelayTimer->start(delayTime);
}
}

quint16 ModbusNG::calculateCRC(QByteArray data)
{
quint16 retval= 0xFFFF;
int i= 0;
while(i<data.size())
{
retval^= 0x00FF&(quint16)data.at(i);
for(int j= 0;j<8;j++)
{
if(retval&1)
{
retval= (retval>>1)^0xA001;
}
else
{
retval>>= 1;
}
}
i++;
}
return retval;
}

int ModbusNG::channelCount()
{
return channels.size();
}

Channel*ModbusNG::getChannel(int channel)
{
return channels.at(channel);
}

QString ModbusNG::channelColumnName(int channel)
{
return channelNames.at(channel);
}

QString ModbusNG::channelIndicatorText(int channel)
{
return channelLabels.at(channel);
}

bool ModbusNG::isChannelHidden(int channel)
{
return hiddenStates.at(channel);
}

QString ModbusNG::channelType(int channel)
{
return channelTypeList.at(channel);
}

/*:923*/
#line 615 "./typica.w"

/*1148:*/
#line 33 "./thresholdannotation.w"

ThresholdAnnotationConfWidget::ThresholdAnnotationConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QLineEdit*source= new QLineEdit;
layout->addRow(tr("Source column name:"),source);
QDoubleSpinBox*value= new QDoubleSpinBox;
value->setMinimum(-9999.99);
value->setMaximum(9999.99);
value->setDecimals(2);
layout->addRow(tr("Threshold value:"),value);
QComboBox*direction= new QComboBox;
direction->addItem(tr("Ascending"));
direction->addItem(tr("Descending"));
layout->addRow(tr("Direction:"),direction);
QLineEdit*annotation= new QLineEdit;
layout->addRow(tr("Annotation:"),annotation);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 52 "./thresholdannotation.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="source")
{
source->setText(node.attribute("value"));
}
else if(node.attribute("name")=="value")
{
value->setValue(node.attribute("value").toDouble());
}
else if(node.attribute("name")=="direction")
{
direction->setCurrentIndex(node.attribute("value").toInt());
}
else if(node.attribute("name")=="annotation")
{
annotation->setText(node.attribute("value"));
}
}
updateSourceColumn(source->text());
updateThreshold(value->value());
updateDirection(direction->currentIndex());
updateAnnotation(annotation->text());
connect(source,SIGNAL(textEdited(QString)),this,SLOT(updateSourceColumn(QString)));
connect(value,SIGNAL(valueChanged(double)),this,SLOT(updateThreshold(double)));
connect(direction,SIGNAL(currentIndexChanged(int)),this,SLOT(updateDirection(int)));
connect(annotation,SIGNAL(textEdited(QString)),this,SLOT(updateAnnotation(QString)));
setLayout(layout);
}

/*:1148*//*1149:*/
#line 86 "./thresholdannotation.w"

void ThresholdAnnotationConfWidget::updateSourceColumn(const QString&source)
{
updateAttribute("source",source);
}

void ThresholdAnnotationConfWidget::updateThreshold(double value)
{
updateAttribute("value",QString("%1").arg(value));
}

void ThresholdAnnotationConfWidget::updateDirection(int direction)
{
updateAttribute("direction",QString("%1").arg(direction));
}

void ThresholdAnnotationConfWidget::updateAnnotation(const QString&annotation)
{
updateAttribute("annotation",annotation);
}

/*:1149*/
#line 616 "./typica.w"

/*1153:*/
#line 152 "./thresholdannotation.w"

Annotator::Annotator(const QString&text):QObject(NULL),note(text)
{
t.setInterval(0);
t.setSingleShot(true);
connect(&t,SIGNAL(timeout()),this,SLOT(catchTimer()));
}

void Annotator::setAnnotation(const QString&annotation)
{
note= annotation;
}

void Annotator::setTemperatureColumn(int tempcolumn)
{
tc= tempcolumn;
}

void Annotator::setAnnotationColumn(int annotationcolumn)
{
ac= annotationcolumn;
}

/*:1153*//*1154:*/
#line 181 "./thresholdannotation.w"

void Annotator::catchTimer()
{
emit annotation(note,tc,ac);
}

void Annotator::annotate()
{
t.start();
}

/*:1154*/
#line 617 "./typica.w"


/*:4*//*267:*/
#line 6262 "./typica.w"

/*264:*/
#line 6225 "./typica.w"

void ScriptValidator::fixup(QString&input)const
{
QScriptEngine*engine= AppInstance->engine;
engine->pushContext();
input= engine->evaluate(input).toString();
engine->popContext();
}

/*:264*//*265:*/
#line 6238 "./typica.w"

QValidator::State ScriptValidator::validate(QString&input,int&pos)const
{
if(v)
{
if(v->validate(input,pos)==QValidator::Acceptable)
{
return QValidator::Acceptable;
}
}
return QValidator::Intermediate;
}

/*:265*//*266:*/
#line 6253 "./typica.w"

ScriptValidator::ScriptValidator(QValidator*validator,QObject*parent)
:QValidator(parent),v(validator)
{

}

/*:266*/
#line 6263 "./typica.w"


/*:267*//*709:*/
#line 160 "./plugins.w"

/*706:*/
#line 92 "./plugins.w"

PluginAction::PluginAction(const QFileInfo&info,QObject*parent):
QAction(parent),preRunScript(""),postRunScript("")
{
pluginFile= info.absoluteFilePath();
setText(info.baseName());
connect(this,SIGNAL(triggered()),this,SLOT(runScript()));
}

void PluginAction::runScript()
{
QFile file(pluginFile);
if(file.open(QIODevice::ReadOnly))
{
QScriptEngine*engine= AppInstance->engine;
QScriptContext*context= engine->pushContext();
if(parent()->dynamicPropertyNames().contains("activationObject"))
{
QScriptValue activationObject= 
parent()->property("activationObject").value<QScriptValue> ();
context->setActivationObject(activationObject);
}
QString script(file.readAll());
QScriptValue retval= engine->evaluate(preRunScript+script+postRunScript,pluginFile);
if(engine->hasUncaughtException())
{
qDebug()<<"Uncaught exception: "<<
engine->uncaughtException().toString()<<
" in "<<pluginFile<<" line: "<<
engine->uncaughtExceptionLineNumber();
}
engine->popContext();
file.close();
}
}

/*:706*//*707:*/
#line 131 "./plugins.w"

QString PluginAction::preRun()
{
return preRunScript;
}

QString PluginAction::postRun()
{
return postRunScript;
}

void PluginAction::setPreRun(const QString&script)
{
preRunScript= script;
}

void PluginAction::setPostRun(const QString&script)
{
postRunScript= script;
}

/*:707*/
#line 161 "./plugins.w"


#line 14889 "./typica.w"

#line 1 "./daterangeselector.w"
/*:709*//*890:*/
#line 89 "./colorsettings.w"

/*888:*/
#line 40 "./colorsettings.w"

ColorSettingsWidget::ColorSettingsWidget():QWidget(NULL)
{
QFormLayout*layout= new QFormLayout;
QCheckBox*enable= new QCheckBox(tr("Enable Javalytics communication"));
QSettings settings;
enable->setChecked(settings.value("settings/color/javalytics/enable",false).toBool());
QLineEdit*address= new QLineEdit();
address->setText(settings.value("settings/color/javalytics/address","192.168.1.10").toString());
QSpinBox*scale= new QSpinBox();
scale->setMinimum(1);
scale->setMaximum(4);
scale->setValue(settings.value("settings/color/javalytics/scale",1).toInt());
connect(enable,SIGNAL(toggled(bool)),this,SLOT(updateEnable(bool)));
connect(address,SIGNAL(textChanged(QString)),this,SLOT(updateAddress(QString)));
connect(scale,SIGNAL(valueChanged(int)),this,SLOT(updateScale(int)));
layout->addRow(enable);
layout->addRow(tr("IP Address:"),address);
layout->addRow(tr("Scale Number:"),scale);
updateEnable(enable->isChecked());
updateAddress(address->text());
updateScale(scale->value());
setLayout(layout);
}

/*:888*//*889:*/
#line 68 "./colorsettings.w"

void ColorSettingsWidget::updateEnable(bool enable)
{
QSettings settings;
settings.setValue("settings/color/javalytics/enable",enable);
}

void ColorSettingsWidget::updateAddress(const QString&address)
{
QSettings settings;
settings.setValue("settings/color/javalytics/address",address);
}

void ColorSettingsWidget::updateScale(int scale)
{
QSettings settings;
settings.setValue("settings/color/javalytics/scale",scale);
}

/*:889*/
#line 90 "./colorsettings.w"

#line 66 "./settings.w"

#line 1 "./advancedsettings.w"
/*:890*//*894:*/
#line 60 "./advancedsettings.w"

/*892:*/
#line 26 "./advancedsettings.w"

AdvancedSettingsWidget::AdvancedSettingsWidget():QWidget(NULL)
{
QSettings settings;
QFormLayout*layout= new QFormLayout;
QCheckBox*logDiagnostics= new QCheckBox;
logDiagnostics->setCheckState(
settings.value("settings/advanced/logging",false).toBool()?
Qt::Checked:Qt::Unchecked);
connect(logDiagnostics,SIGNAL(toggled(bool)),this,SLOT(enableDiagnosticLogging(bool)));
layout->addRow(tr("Enable diagnostic logging"),logDiagnostics);
setLayout(layout);
}

/*:892*//*893:*/
#line 43 "./advancedsettings.w"

void AdvancedSettingsWidget::enableDiagnosticLogging(bool enabled)
{
QSettings settings;
settings.setValue("settings/advanced/logging",enabled);
if(enabled)
{
qInstallMsgHandler(messageFileOutput);
}
else
{
qInstallMsgHandler(0);
}
}

/*:893*/
#line 61 "./advancedsettings.w"

#line 18693 "./typica.w"

/*:894*//*953:*/
#line 642 "./unsupportedserial.w"

/*928:*/
#line 58 "./unsupportedserial.w"

UnsupportedSerialDeviceConfWidget::UnsupportedSerialDeviceConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
deviceSettingsModel(new SaltModel(2)),
scriptEditor(new QTextEdit)
{
scriptEditor->setTabStopWidth(20);
QVBoxLayout*dummyLayout= new QVBoxLayout;
QTabWidget*central= new QTabWidget;
QWidget*deviceConfigurationWidget= new QWidget;
QVBoxLayout*deviceConfigurationLayout= new QVBoxLayout;
QPushButton*addChannelButton= new QPushButton(tr("Add Channel"));
deviceConfigurationLayout->addWidget(addChannelButton);
connect(addChannelButton,SIGNAL(clicked()),this,SLOT(addChannel()));
QLabel*deviceSettingsLabel= new QLabel(tr("Device Settings:"));
deviceConfigurationLayout->addWidget(deviceSettingsLabel);
QTableView*deviceSettingsView= new QTableView;
deviceSettingsModel->setHeaderData(0,Qt::Horizontal,tr("Key"));
deviceSettingsModel->setHeaderData(1,Qt::Horizontal,tr("Value"));
deviceSettingsView->setModel(deviceSettingsModel);
deviceConfigurationLayout->addWidget(deviceSettingsView);

deviceConfigurationWidget->setLayout(deviceConfigurationLayout);
central->addTab(deviceConfigurationWidget,tr("Configuration"));
central->addTab(scriptEditor,tr("Script"));
dummyLayout->addWidget(central);

/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 86 "./unsupportedserial.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="keys"||node.attribute("name")=="values")
{
int column= 0;
if(node.attribute("name")=="values")
{
column= 1;
}
QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
QStringList keyList= data.split(", ");
for(int j= 0;j<keyList.size();j++)
{
deviceSettingsModel->setData(deviceSettingsModel->index(j,column),
QVariant(keyList.at(j)),
Qt::EditRole);
}
}
else if(node.attribute("name")=="script")
{
scriptEditor->setPlainText(node.attribute("value"));
}
}

connect(deviceSettingsModel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),
this,SLOT(updateConfiguration()));
connect(scriptEditor,SIGNAL(textChanged()),this,SLOT(saveScript()));
setLayout(dummyLayout);
}

/*:928*//*929:*/
#line 131 "./unsupportedserial.w"

void UnsupportedSerialDeviceConfWidget::updateConfiguration()
{
updateAttribute("keys",deviceSettingsModel->arrayLiteral(0,Qt::DisplayRole));
updateAttribute("values",deviceSettingsModel->arrayLiteral(1,Qt::DisplayRole));
}

/*:929*//*930:*/
#line 144 "./unsupportedserial.w"

void UnsupportedSerialDeviceConfWidget::saveScript()
{
updateAttribute("script",scriptEditor->toPlainText());
}

/*:930*//*931:*/
#line 155 "./unsupportedserial.w"

void UnsupportedSerialDeviceConfWidget::addChannel()
{
insertChildNode(tr("Channel"),"unsupporteddevicechannel");
}

/*:931*//*933:*/
#line 183 "./unsupportedserial.w"

UnsupportedDeviceChannelConfWidget::UnsupportedDeviceChannelConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
channelSettingsModel(new SaltModel(2))
{
QFormLayout*layout= new QFormLayout;
QLineEdit*columnName= new QLineEdit;
layout->addRow(tr("Column Name:"),columnName);
QCheckBox*hideSeries= new QCheckBox("Hide this channel");
layout->addRow(hideSeries);
QTableView*channelSettings= new QTableView;
channelSettingsModel->setHeaderData(0,Qt::Horizontal,"Key");
channelSettingsModel->setHeaderData(1,Qt::Horizontal,"Value");
channelSettings->setModel(channelSettingsModel);
layout->addRow(channelSettings);
setLayout(layout);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 200 "./unsupportedserial.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="columnname")
{
columnName->setText(node.attribute("value"));
}
else if(node.attribute("name")=="hidden")
{
hideSeries->setChecked(node.attribute("value")=="true");
}
else if(node.attribute("name")=="keys"||node.attribute("name")=="values")
{
int column= 0;
if(node.attribute("name")=="values")
{
column= 1;
}
QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
QStringList keyList= data.split(", ");
for(int j= 0;j<keyList.size();j++)
{
channelSettingsModel->setData(channelSettingsModel->index(j,column),
QVariant(keyList.at(j)),
Qt::EditRole);
}
}
}
updateColumnName(columnName->text());
updateHidden(hideSeries->isChecked());
updateConfiguration();
connect(columnName,SIGNAL(textEdited(QString)),this,SLOT(updateColumnName(QString)));
connect(hideSeries,SIGNAL(toggled(bool)),this,SLOT(updateHidden(bool)));
connect(channelSettingsModel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),
this,SLOT(updateConfiguration()));
}

/*:933*//*934:*/
#line 247 "./unsupportedserial.w"

void UnsupportedDeviceChannelConfWidget::updateColumnName(const QString&value)
{
updateAttribute("columnname",value);
}

void UnsupportedDeviceChannelConfWidget::updateHidden(bool hidden)
{
updateAttribute("hidden",hidden?"true":"false");
}

void UnsupportedDeviceChannelConfWidget::updateConfiguration()
{
updateAttribute("keys",channelSettingsModel->arrayLiteral(0,Qt::DisplayRole));
updateAttribute("values",channelSettingsModel->arrayLiteral(1,Qt::DisplayRole));
}

/*:934*/
#line 643 "./unsupportedserial.w"

/*941:*/
#line 374 "./unsupportedserial.w"

void JavaScriptDevice::start()
{
QScriptValue object= scriptengine->newQObject(this);
/*942:*/
#line 393 "./unsupportedserial.w"

QScriptValue settingsObject= scriptengine->newObject();
QVariantMap::const_iterator i= deviceSettings.constBegin();
while(i!=deviceSettings.constEnd())
{
settingsObject.setProperty(i.key(),i.value().toString());
i++;
}
object.setProperty("settings",settingsObject);

/*:942*/
#line 378 "./unsupportedserial.w"

/*943:*/
#line 408 "./unsupportedserial.w"

QScriptValue channelsArray= scriptengine->newArray(channelCount());
for(int i= 0;i<channelCount();i++)
{
QScriptValue channelObject= scriptengine->newQObject(getChannel(i));
QScriptValue channelSettingsObject= scriptengine->newObject();
QVariantMap::const_iterator j= channelSettings.at(i).constBegin();
while(j!=channelSettings.at(i).constEnd())
{
channelSettingsObject.setProperty(j.key(),j.value().toString());
j++;
}
channelObject.setProperty("settings",channelSettingsObject);
channelsArray.setProperty(i,channelObject);
}
object.setProperty("channels",channelsArray);

/*:943*/
#line 379 "./unsupportedserial.w"

QScriptContext*context= scriptengine->currentContext();
QScriptValue oldThis= context->thisObject();
context->setThisObject(object);
QScriptValue result= scriptengine->evaluate(deviceScript);
QScriptEngine*engine= scriptengine;
/*202:*/
#line 4629 "./typica.w"

if(engine->hasUncaughtException())
{
int line= engine->uncaughtExceptionLineNumber();
qDebug()<<"Uncaught excpetion at line "<<line<<" : "<<
result.toString();
QString trace;
foreach(trace,engine->uncaughtExceptionBacktrace())
{
qDebug()<<trace;
}
}

/*:202*/
#line 385 "./unsupportedserial.w"

context->setThisObject(oldThis);
}

/*:941*//*946:*/
#line 449 "./unsupportedserial.w"

void JavaScriptDevice::stop()
{
emit deviceStopRequested();
}

/*:946*//*947:*/
#line 462 "./unsupportedserial.w"

JavaScriptDevice::JavaScriptDevice(const QModelIndex&index,
QScriptEngine*engine):
QObject(NULL),scriptengine(engine)
{
DeviceTreeModel*model= (DeviceTreeModel*)(index.model());
QDomElement deviceReferenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList deviceConfigData= deviceReferenceElement.elementsByTagName("attribute");
QDomElement node;
QStringList deviceKeys;
QStringList deviceValues;
for(int i= 0;i<deviceConfigData.size();i++)
{
node= deviceConfigData.at(i).toElement();
if(node.attribute("name")=="keys")
{
QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
deviceKeys= data.split(", ");
}
else if(node.attribute("name")=="values")
{
QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
deviceValues= data.split(", ");
}
else if(node.attribute("name")=="script")
{
deviceScript= node.attribute("value");
}
deviceSettings.insert(node.attribute("name"),node.attribute("value"));
}
for(int i= 0;i<qMin(deviceKeys.length(),deviceValues.length());i++)
{
deviceSettings.insert(deviceKeys[i],deviceValues[i]);
}
if(model->hasChildren(index))
{
for(int i= 0;i<model->rowCount(index);i++)
{
QModelIndex channelIndex= model->index(i,0,index);
QDomElement channelReference= model->referenceElement(model->data(channelIndex,32).toString());
channelList.append(new Channel);
QDomElement channelReferenceElement= 
model->referenceElement(model->data(channelIndex,Qt::UserRole).toString());
QDomNodeList channelConfigData= 
channelReferenceElement.elementsByTagName("attribute");
QStringList channelKeys;
QStringList channelValues;
for(int j= 0;j<channelConfigData.size();j++)
{
node= channelConfigData.at(j).toElement();
if(node.attribute("name")=="keys")
{
QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
channelKeys= data.split(", ");
}
else if(node.attribute("name")=="values")
{
QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
channelValues= data.split(", ");
}
else if(node.attribute("name")=="hidden")
{
hiddenState.append(node.attribute("value")=="true");
}
else if(node.attribute("name")=="columnname")
{
columnNames.append(node.attribute("value"));
}
}
QVariantMap cs;
for(int j= 0;j<qMin(channelKeys.length(),channelValues.length());j++)
{
cs.insert(channelKeys[j],channelValues[j]);
}
channelSettings.append(cs);
indicatorTexts.append(model->data(channelIndex,Qt::DisplayRole).toString());
channelUnits.append(Units::Fahrenheit);
}
}
}

/*:947*//*948:*/
#line 567 "./unsupportedserial.w"

int JavaScriptDevice::channelCount()
{
return channelList.length();
}

Channel*JavaScriptDevice::getChannel(int channel)
{
return channelList.at(channel);
}

bool JavaScriptDevice::isChannelHidden(int channel)
{
return hiddenState.at(channel);
}

Units::Unit JavaScriptDevice::expectedChannelUnit(int channel)
{
return channelUnits.at(channel);
}

QString JavaScriptDevice::channelColumnName(int channel)
{
if(channel>=0&&channel<columnNames.length())
{
return columnNames.at(channel);
}
return QString();
}

QString JavaScriptDevice::channelIndicatorText(int channel)
{
return indicatorTexts.at(channel);
}

/*:948*//*949:*/
#line 604 "./unsupportedserial.w"

void JavaScriptDevice::setTemperatureColumn(int tcol)
{
annotationTemperatureColumn= tcol;
}

void JavaScriptDevice::setAnnotationColumn(int ncol)
{
annotationNoteColumn= ncol;
}

/*:949*/
#line 644 "./unsupportedserial.w"


/*:953*//*976:*/
#line 444 "./phidgets.w"

/*960:*/
#line 31 "./phidgets.w"

PhidgetsTemperatureSensorConfWidget::PhidgetsTemperatureSensorConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QPushButton*addChannelButton= new QPushButton(tr("Add Channel"));
QSpinBox*sampleRate= new QSpinBox;
sampleRate->setMinimum(40);
sampleRate->setMaximum(600);
sampleRate->setSingleStep(40);
sampleRate->setValue(360);

/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 44 "./phidgets.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="sampleRate")
{
sampleRate->setValue(node.attribute("value").toInt());
}
}
updateRate(sampleRate->value());

connect(sampleRate,SIGNAL(valueChanged(int)),this,SLOT(updateRate(int)));
connect(addChannelButton,SIGNAL(clicked()),this,SLOT(addChannel()));

layout->addRow(addChannelButton);
layout->addRow(tr("Sample rate:"),sampleRate);
setLayout(layout);
}

/*:960*//*961:*/
#line 66 "./phidgets.w"

void PhidgetsTemperatureSensorConfWidget::addChannel()
{
insertChildNode(tr("Channel"),"phidgets1048channel");
}

/*:961*//*962:*/
#line 74 "./phidgets.w"

void PhidgetsTemperatureSensorConfWidget::updateRate(int ms)
{
updateAttribute("sampleRate",QString("%1").arg(ms));
}

/*:962*//*964:*/
#line 103 "./phidgets.w"

PhidgetTemperatureSensorChannelConfWidget::PhidgetTemperatureSensorChannelConfWidget(
DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
tcType(new QComboBox)
{
QFormLayout*layout= new QFormLayout;
QLineEdit*columnName= new QLineEdit;
layout->addRow(tr("Column Name:"),columnName);
QCheckBox*hideSeries= new QCheckBox("Hide this channel");
layout->addRow(hideSeries);
layout->addRow(tr("Thermocouple Type:"),tcType);
tcType->addItem("Type K","1");
tcType->addItem("Type J","2");
tcType->addItem("Type E","3");
tcType->addItem("Type T","4");
QSpinBox*channel= new QSpinBox;
layout->addRow(tr("Channel:"),channel);
channel->setMinimum(0);
channel->setMaximum(3);
setLayout(layout);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 124 "./phidgets.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="columnname")
{
columnName->setText(node.attribute("value"));
}
else if(node.attribute("name")=="hidden")
{
hideSeries->setChecked(node.attribute("value")=="true");
}
else if(node.attribute("name")=="tctype")
{
tcType->setCurrentIndex(tcType->findData(node.attribute("value")));
}
else if(node.attribute("name")=="channel")
{
channel->setValue(node.attribute("value").toInt());
}
}
updateColumnName(columnName->text());
updateHidden(hideSeries->isChecked());
updateTC(tcType->currentIndex());
updateChannel(channel->value());
connect(columnName,SIGNAL(textEdited(QString)),this,SLOT(updateColumnName(QString)));
connect(hideSeries,SIGNAL(toggled(bool)),this,SLOT(updateHidden(bool)));
connect(tcType,SIGNAL(currentIndexChanged(int)),this,SLOT(updateTC(int)));
connect(channel,SIGNAL(valueChanged(int)),this,SLOT(updateChannel(int)));
}

/*:964*//*965:*/
#line 157 "./phidgets.w"

void PhidgetTemperatureSensorChannelConfWidget::updateColumnName(const QString&value)
{
updateAttribute("columnname",value);
}

void PhidgetTemperatureSensorChannelConfWidget::updateHidden(bool hidden)
{
updateAttribute("hidden",hidden?"true":"false");
}

void PhidgetTemperatureSensorChannelConfWidget::updateTC(int index)
{
updateAttribute("tctype",tcType->itemData(index).toString());
}

void PhidgetTemperatureSensorChannelConfWidget::updateChannel(int channel)
{
updateAttribute("channel",QString("%1").arg(channel));
}

/*:965*//*969:*/
#line 246 "./phidgets.w"

PhidgetsTemperatureSensor::PhidgetsTemperatureSensor(const QModelIndex&index)
:QObject(NULL),driver("phidget21"),device(NULL)
{
DeviceTreeModel*model= (DeviceTreeModel*)(index.model());
QDomElement deviceReferenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList deviceConfigData= deviceReferenceElement.elementsByTagName("attribute");
QDomElement node;
for(int i= 0;i<deviceConfigData.size();i++)
{
node= deviceConfigData.at(i).toElement();
if(node.attribute("name")=="sampleRate")
{
sampleTimer.setInterval(node.attribute("value").toInt());
}
}
if(model->hasChildren(index))
{
for(int i= 0;i<model->rowCount(index);i++)
{
QModelIndex channelIndex= model->index(i,0,index);
QDomElement channelReference= model->referenceElement(model->data(channelIndex,32).toString());
QDomElement channelReferenceElement= model->referenceElement(model->data(channelIndex,Qt::UserRole).toString());
QDomNodeList channelConfigData= channelReferenceElement.elementsByTagName("attribute");
for(int j= 0;j<channelConfigData.size();j++)
{
node= channelConfigData.at(j).toElement();
if(node.attribute("name")=="channel")
{
int channelID= node.attribute("value").toInt();
channelIndices.append(channelID);
Channel*channel= new Channel;
channelList.append(channel);
channelMap.insert(channelID,channel);
}
else if(node.attribute("name")=="hidden")
{
hiddenState.append(node.attribute("value")=="true");
}
else if(node.attribute("name")=="columnname")
{
columnNames.append(node.attribute("value"));
}
else if(node.attribute("name")=="tctype")
{
tctypes.append(node.attribute("value").toInt());
}
}
indicatorTexts.append(model->data(channelIndex,Qt::DisplayRole).toString());
}
}
}

/*:969*//*970:*/
#line 306 "./phidgets.w"

int PhidgetsTemperatureSensor::channelCount()
{
return channelList.length();
}

Channel*PhidgetsTemperatureSensor::getChannel(int channel)
{
return channelList.at(channel);
}

/*:970*//*971:*/
#line 319 "./phidgets.w"

bool PhidgetsTemperatureSensor::isChannelHidden(int channel)
{
return hiddenState.at(channel);
}

QString PhidgetsTemperatureSensor::channelColumnName(int channel)
{
if(channel>=0&&channel<columnNames.length())
{
return columnNames.at(channel);
}
return QString();
}

QString PhidgetsTemperatureSensor::channelIndicatorText(int channel)
{
if(channel>=0&&channel<indicatorTexts.length())
{
return indicatorTexts.at(channel);
}
return QString();
}

/*:971*//*973:*/
#line 371 "./phidgets.w"

void PhidgetsTemperatureSensor::start()
{
if(!driver.load())
{
driver.setFileName("Phidget21.framework/Phidget21");
if(!driver.load())
{
QMessageBox::critical(NULL,tr("Typica: Driver not found"),
tr("Failed to find phidget21. Please install it."));
return;
}
}
if((createDevice= (PhidgetHandleOnly)driver.resolve("CPhidgetTemperatureSensor_create"))==0||
(openDevice= (PhidgetHandleInt)driver.resolve("CPhidget_open"))==0||
(waitForOpen= (PhidgetHandleInt)driver.resolve("CPhidget_waitForAttachment"))==0||
(setTCType= (PhidgetHandleIntInt)driver.resolve("CPhidgetTemperatureSensor_setThermocoupleType"))==0||
(getTemperature= (PhidgetHandleIntDoubleOut)driver.resolve("CPhidgetTemperatureSensor_getTemperature"))==0||
(closeDevice= (PhidgetHandleOnly)driver.resolve("CPhidget_close"))==0||
(deleteDevice= (PhidgetHandleOnly)driver.resolve("CPhidget_delete"))==0)
{
QMessageBox::critical(NULL,tr("Typica: Link error"),
tr("Failed to link a required symbol in phidget21."));
return;
}
createDevice(&device);
openDevice(device,-1);
int error;
if((error= waitForOpen(device,10000)))
{
closeDevice(device);
deleteDevice(device);
QMessageBox::critical(NULL,tr("Typica: Failed to Open Device"),
tr("CPhidget_waitForAttachment returns error %n",0,error));
return;
}
for(int i= 0;i<channelIndices.length();i++)
{
setTCType(device,channelIndices.at(i),tctypes.at(i));
}
connect(&sampleTimer,SIGNAL(timeout()),this,SLOT(getMeasurements()));
sampleTimer.start();
}

/*:973*//*974:*/
#line 418 "./phidgets.w"

void PhidgetsTemperatureSensor::getMeasurements()
{
double value= 0.0;
QTime time= QTime::currentTime();
foreach(int i,channelIndices)
{
getTemperature(device,i,&value);
Measurement measure(value*9.0/5.0+32.0,time);
channelMap[i]->input(measure);
}
}

/*:974*//*975:*/
#line 433 "./phidgets.w"

void PhidgetsTemperatureSensor::stop()
{
sampleTimer.stop();
closeDevice(device);
deleteDevice(device);
driver.unload();
}

/*:975*/
#line 445 "./phidgets.w"


/*:976*//*1008:*/
#line 792 "./phidget22.w"

/*984:*/
#line 60 "./phidget22.w"

PhidgetConfWidget::PhidgetConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QHBoxLayout*layout= new QHBoxLayout;
QPushButton*addChannelButton= new QPushButton(tr("Add Channel"));
connect(addChannelButton,SIGNAL(clicked()),this,SLOT(addChannel()));
layout->addWidget(addChannelButton);
setLayout(layout);
}

void PhidgetConfWidget::addChannel()
{
insertChildNode(tr("Channel"),"phidgetchannel");
}

/*:984*//*989:*/
#line 179 "./phidget22.w"

PhidgetChannelSelector::PhidgetChannelSelector():QComboBox(),manager(NULL)
{
#if __APPLE__
driver.setFileName("Phidget22.framework/Phidget22");
#else
driver.setFileName("phidget22");
#endif
if(!driver.load())
{
QMessageBox::critical(NULL,tr("Typica: Driver not found"),
tr("Failed to find phidget22. Please install it."));
return;
}
/*988:*/
#line 157 "./phidget22.w"

if((createManager= (PhidgetPointer)driver.resolve("PhidgetManager_create"))==0||
(setOnAttachManager= (PhidgetPointerCallbackPointer)driver.resolve("PhidgetManager_setOnAttachHandler"))==0||
(setOnDetachManager= (PhidgetPointerCallbackPointer)driver.resolve("PhidgetManager_setOnDetachHandler"))==0||
(openManager= (PhidgetPointer)driver.resolve("PhidgetManager_open"))==0||
(getDeviceName= (PhidgetPointerStringOut)driver.resolve("Phidget_getDeviceName"))==0||
(getDeviceSerialNumber= (PhidgetPointerIntOut)driver.resolve("Phidget_getDeviceSerialNumber"))==0||
(getChannel= (PhidgetPointerIntOut)driver.resolve("Phidget_getChannel"))==0||
(getChannelClass= (PhidgetPointerIntOut)driver.resolve("Phidget_getChannelClass"))==0||
(getChannelSubclass= (PhidgetPointerIntOut)driver.resolve("Phidget_getChannelSubclass"))==0||
(getHubPort= (PhidgetPointerIntOut)driver.resolve("Phidget_getHubPort"))==0||
(closeManager= (PhidgetPointer)driver.resolve("PhidgetManager_close"))==0||
(deleteManager= (PhidgetPointer)driver.resolve("PhidgetManager_delete"))==0)
{
QMessageBox::critical(NULL,tr("Typica: Link error"),
tr("Failed to link a required symbol in phidget22."));
return;
}

/*:988*/
#line 193 "./phidget22.w"

createManager(&manager);
setOnAttachManager(manager,ChannelListAddChannel,this);
setOnDetachManager(manager,ChannelListRemoveChannel,this);
openManager(manager);
}

/*:989*//*992:*/
#line 228 "./phidget22.w"

void PhidgetChannelSelector::addChannel(void*device)
{
char*deviceName;
int deviceSerialNumber;
int channel;
int channelClass;
int channelSubclass;
int hubPort;

getDeviceName(device,&deviceName);
getDeviceSerialNumber(device,&deviceSerialNumber);
getChannel(device,&channel);
getChannelClass(device,&channelClass);
getChannelSubclass(device,&channelSubclass);
getHubPort(device,&hubPort);

QMap<QString,QVariant> itemData;

if(channelClass==28)
{
itemData.insert("serialNumber",QString("%1").arg(deviceSerialNumber));
itemData.insert("channel",QString("%1").arg(channel));
itemData.insert("class",QString("%1").arg(channelClass));
itemData.insert("subclass",QString("%1").arg(channelSubclass));
itemData.insert("hubport",QString("%1").arg(hubPort));
addItem(QString("%1: %2").arg(deviceName).arg(channel),QVariant(itemData));
}
}

/*:992*//*993:*/
#line 266 "./phidget22.w"

void PhidgetChannelSelector::removeChannel(void*device)
{
int deviceSerialNumber;

getDeviceSerialNumber(device,&deviceSerialNumber);

for(int i= count()-1;i>=0;i--)
{
QMap<QString,QVariant> data= itemData(i).toMap();
if(data.value("serialNumber").toInt()==deviceSerialNumber)
{
removeItem(i);
}
}
}

/*:993*//*994:*/
#line 285 "./phidget22.w"

PhidgetChannelSelector::~PhidgetChannelSelector()
{
if(manager!=NULL)
{
closeManager(manager);
deleteManager(&manager);
}
}

/*:994*//*996:*/
#line 330 "./phidget22.w"

PhidgetChannelConfWidget::PhidgetChannelConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),
channelSelector(new PhidgetChannelSelector),
serialNumber(new QLineEdit),
channel(new QLineEdit),
hubPort(new QLineEdit),
subtype(new QComboBox),
subtypeLayout(new QStackedLayout),
tctype(new QComboBox),
rtdtype(new QComboBox),
rtdwiring(new QComboBox)
{
QVBoxLayout*outerLayout= new QVBoxLayout;
QFormLayout*layout= new QFormLayout;
QLineEdit*columnName= new QLineEdit;
subtype->addItem(tr("IC"),QVariant(1));
subtype->addItem(tr("RTD"),QVariant(32));
subtype->addItem(tr("Thermocouple"),QVariant(33));
layout->addRow(tr("Channels:"),channelSelector);
layout->addRow(tr("Column Name:"),columnName);
QCheckBox*hidden= new QCheckBox(tr("Hide channel"));
layout->addRow(hidden);
layout->addRow(tr("Serial Number:"),serialNumber);
layout->addRow(tr("Hub Port:"),hubPort);
layout->addRow(tr("Channel Number:"),channel);
layout->addRow(tr("Channel Type:"),subtype);
serialNumber->setEnabled(false);
channel->setEnabled(false);
subtype->setEnabled(false);
outerLayout->addLayout(layout);
QWidget*icconfiguration= new QWidget;
QWidget*rtdconfiguration= new QWidget;
QFormLayout*rtdconfigurationLayout= new QFormLayout;
rtdtype->addItem(tr("PT100 with .00385 curve"),QVariant(1));
rtdtype->addItem(tr("PT1000 with .00385 curve"),QVariant(2));
rtdtype->addItem(tr("PT100 with .00392 curve"),QVariant(3));
rtdtype->addItem(tr("PT1000 with .00392 curve"),QVariant(4));
rtdconfigurationLayout->addRow(tr("RTD type:"),rtdtype);
rtdwiring->addItem(tr("2 wire"),QVariant(1));
rtdwiring->addItem(tr("3 wire"),QVariant(2));
rtdwiring->addItem(tr("4 wire"),QVariant(3));
rtdconfigurationLayout->addRow(tr("RTD wiring:"),rtdwiring);
rtdconfiguration->setLayout(rtdconfigurationLayout);
QWidget*tcconfiguration= new QWidget;
QFormLayout*tcconfigurationLayout= new QFormLayout;
tctype->addItem(tr("Type J"),QVariant(1));
tctype->addItem(tr("Type K"),QVariant(2));
tctype->addItem(tr("Type E"),QVariant(3));
tctype->addItem(tr("Type T"),QVariant(4));
tcconfigurationLayout->addRow(tr("Thermocouple type:"),tctype);
tcconfiguration->setLayout(tcconfigurationLayout);
subtypeLayout->addWidget(icconfiguration);
subtypeLayout->addWidget(rtdconfiguration);
subtypeLayout->addWidget(tcconfiguration);

/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 387 "./phidget22.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="serialnumber")
{
serialNumber->setText(node.attribute("value"));
}
else if(node.attribute("name")=="channel")
{
channel->setText(node.attribute("value"));
}
else if(node.attribute("name")=="columnname")
{
columnName->setText(node.attribute("value"));
}
else if(node.attribute("name")=="channeltype")
{
subtype->setCurrentIndex(subtype->
findData(QVariant(node.attribute("value").toInt())));
subtypeLayout->setCurrentIndex(subtype->currentIndex());
}
else if(node.attribute("name")=="tctype")
{
tctype->setCurrentIndex(tctype->
findData(QVariant(node.attribute("value").toInt())));
}
else if(node.attribute("name")=="rtdtype")
{
rtdtype->setCurrentIndex(rtdtype->
findData(QVariant(node.attribute("value").toInt())));
}
else if(node.attribute("name")=="rtdwiring")
{
rtdwiring->setCurrentIndex(rtdwiring->
findData(QVariant(node.attribute("value").toInt())));
}
else if(node.attribute("name")=="hubport")
{
hubPort->setText(node.attribute("value"));
}
else if(node.attribute("name")=="hidden")
{
hidden->setCheckState(node.attribute("value")=="true"?Qt::Checked:Qt::Unchecked);
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
connect(channelSelector,SIGNAL(currentIndexChanged(int)),
this,SLOT(changeSelectedChannel(int)));
connect(subtype,SIGNAL(currentIndexChanged(int)),
subtypeLayout,SLOT(setCurrentIndex(int)));
connect(serialNumber,SIGNAL(textChanged(QString)),
this,SLOT(updateSerialNumber(QString)));
connect(channel,SIGNAL(textChanged(QString)),
this,SLOT(updateChannel(QString)));
connect(columnName,SIGNAL(textEdited(QString)),
this,SLOT(updateColumnName(QString)));
connect(subtype,SIGNAL(currentIndexChanged(int)),
this,SLOT(updateChannelType(int)));
connect(tctype,SIGNAL(currentIndexChanged(int)),
this,SLOT(updateTCType(int)));
connect(rtdtype,SIGNAL(currentIndexChanged(int)),
this,SLOT(updateRTDType(int)));
connect(rtdwiring,SIGNAL(currentIndexChanged(int)),
this,SLOT(updateRTDWiring(int)));
connect(hubPort,SIGNAL(textChanged(QString)),
this,SLOT(updateHubPort(QString)));
connect(hidden,SIGNAL(stateChanged(int)),
this,SLOT(updateHidden(int)));
}

/*:996*//*997:*/
#line 471 "./phidget22.w"

void PhidgetChannelConfWidget::changeSelectedChannel(int index)
{
QMap<QString,QVariant> data= channelSelector->itemData(index).toMap();
serialNumber->setText(data.value("serialNumber").toString());
channel->setText(data.value("channel").toString());
subtype->setCurrentIndex(subtype->
findData(QVariant(data.value("subclass").toString().toInt())));
hubPort->setText(data.value("hubport").toString());
}

/*:997*//*998:*/
#line 484 "./phidget22.w"

void PhidgetChannelConfWidget::updateSerialNumber(const QString&value)
{
updateAttribute("serialnumber",value);
}

void PhidgetChannelConfWidget::updateChannel(const QString&value)
{
updateAttribute("channel",value);
}

void PhidgetChannelConfWidget::updateColumnName(const QString&value)
{
updateAttribute("columnname",value);
}

void PhidgetChannelConfWidget::updateChannelType(int value)
{
updateAttribute("channeltype",subtype->itemData(value).toString());
}

void PhidgetChannelConfWidget::updateTCType(int value)
{
updateAttribute("tctype",tctype->itemData(value).toString());
}

void PhidgetChannelConfWidget::updateRTDType(int value)
{
updateAttribute("rtdtype",rtdtype->itemData(value).toString());
}

void PhidgetChannelConfWidget::updateRTDWiring(int value)
{
updateAttribute("rtdwiring",rtdwiring->itemData(value).toString());
}

void PhidgetChannelConfWidget::updateHubPort(const QString&value)
{
updateAttribute("hubport",value);
}

void PhidgetChannelConfWidget::updateHidden(int value)
{
updateAttribute("hidden",value==0?"false":"true");
}

/*:998*//*1001:*/
#line 593 "./phidget22.w"

Phidget22::Phidget22(const QModelIndex&index):QObject(NULL)
{
DeviceTreeModel*model= (DeviceTreeModel*)(index.model());
if(model->hasChildren(index))
{
for(int i= 0;i<model->rowCount(index);i++)
{
QModelIndex channelIndex= model->index(i,0,index);
QDomElement channelReference= model->
referenceElement(model->data(channelIndex,32).toString());
QDomElement channelReferenceElement= model->
referenceElement(model->
data(channelIndex,Qt::UserRole).toString());
QDomNodeList channelConfigData= 
channelReferenceElement.elementsByTagName("attribute");
PhidgetChannelData*c= new PhidgetChannelData;
c->channel= new Channel;
c->indicatorLabel= 
model->data(channelIndex,Qt::DisplayRole).toString();
c->device= NULL;
c->hubPort= -1;
for(int j= 0;j<channelConfigData.size();j++)
{
QDomElement node= channelConfigData.at(j).toElement();
if(node.attribute("name")=="serialnumber")
{
c->serialNumber= node.attribute("value").toInt();
}
else if(node.attribute("name")=="channel")
{
c->channelNumber= node.attribute("value").toInt();
}
else if(node.attribute("name")=="channeltype")
{
c->channelType= node.attribute("value").toInt();
}
else if(node.attribute("name")=="tctype")
{
c->tcType= node.attribute("value").toInt();
}
else if(node.attribute("name")=="rtdtype")
{
c->rtdType= node.attribute("value").toInt();
}
else if(node.attribute("name")=="rtdwiring")
{
c->wiring= node.attribute("value").toInt();
}
else if(node.attribute("name")=="hidden")
{
c->hidden= (node.attribute("value")=="true");
}
else if(node.attribute("name")=="columnname")
{
c->columnName= node.attribute("value");
}
else if(node.attribute("name")=="hubport")
{
c->hubPort= node.attribute("value").toInt();
}
}
channelConfiguration.append(c);
}
}
}

/*:1001*//*1002:*/
#line 663 "./phidget22.w"

int Phidget22::channelCount()
{
return channelConfiguration.length();
}

Channel*Phidget22::getChannel(int channel)
{
return channelConfiguration.at(channel)->channel;
}

/*:1002*//*1003:*/
#line 677 "./phidget22.w"

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

/*:1003*//*1004:*/
#line 696 "./phidget22.w"

void Phidget22::start()
{
#if __APPLE__
driver.setFileName("Phidget22.framework/Phidget22");
#else
driver.setFileName("phidget22");
#endif
if(!driver.load())
{
QMessageBox::critical(NULL,tr("Typica: Driver not found"),
tr("Failed to find phidget22. Please install it."));
return;
}
if((p_createTemperatureSensor= (PhidgetPointer)driver.resolve("PhidgetTemperatureSensor_create"))==0||
(p_setSerialNumber= (PhidgetPointerIntIn)driver.resolve("Phidget_setDeviceSerialNumber"))==0||
(p_setChannelNumber= (PhidgetPointerIntIn)driver.resolve("Phidget_setChannel"))==0||
(p_setTCType= (PhidgetPointerIntIn)driver.resolve("PhidgetTemperatureSensor_setThermocoupleType"))==0||
(p_setRTDType= (PhidgetPointerIntIn)driver.resolve("PhidgetTemperatureSensor_setRTDType"))==0||
(p_setRTDWiring= (PhidgetPointerIntIn)driver.resolve("PhidgetTemperatureSensor_setRTDWireSetup"))==0||
(p_setNewDataCallback= (PhidgetPointerVCPointer)driver.resolve("PhidgetTemperatureSensor_setOnTemperatureChangeHandler"))==0||
(p_open= (PhidgetPointerIntIn)driver.resolve("Phidget_openWaitForAttachment"))==0||
(p_close= (PhidgetPointer)driver.resolve("Phidget_close"))==0||
(p_delete= (PhidgetPointer)driver.resolve("PhidgetTemperatureSensor_delete"))==0||
(p_setHubPort= (PhidgetPointerIntIn)driver.resolve("Phidget_setHubPort"))==0)
{
QMessageBox::critical(NULL,tr("Typica: Link error"),
tr("Failed to link a required symbol in phidget22."));
return;
}
for(int i= 0;i<channelConfiguration.length();i++)
{
PhidgetChannelData*c= channelConfiguration.at(i);
p_createTemperatureSensor(&(c->device));
p_setSerialNumber(c->device,c->serialNumber);
p_setChannelNumber(c->device,c->channelNumber);
switch(c->channelType)
{
case 32:
p_setRTDType(c->device,c->rtdType);
p_setRTDWiring(c->device,c->wiring);
break;
case 33:
p_setTCType(c->device,c->tcType);
break;
default:
break;
}
if(c->hubPort>=0)
{
p_setHubPort(c->device,c->hubPort);
}
p_setNewDataCallback(c->device,Phidget22ValueCallback,c->channel);
p_open(c->device,5000);
}
}

/*:1004*//*1007:*/
#line 779 "./phidget22.w"

void Phidget22::stop()
{
for(int i= 0;i<channelConfiguration.length();i++)
{
PhidgetChannelData*c= channelConfiguration.at(i);
p_close(c->device);
p_delete(&(c->device));
}
}

/*:1007*/
#line 793 "./phidget22.w"


/*:1008*//*1022:*/
#line 20122 "./typica.w"

/*1020:*/
#line 20084 "./typica.w"

CoolingTimerConfWidget::CoolingTimerConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QHBoxLayout*layout= new QHBoxLayout;
QLabel*label= new QLabel(tr("Cooling Time: "));
QTimeEdit*editor= new QTimeEdit;
editor->setDisplayFormat("mm:ss");
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 20093 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="reset")
{
editor->setTime(QTime::fromString(node.attribute("value"),"mm:ss"));
}
}
updateResetTime(editor->time());
connect(editor,SIGNAL(timeChanged(QTime)),
this,SLOT(updateResetTime(QTime)));
layout->addWidget(label);
layout->addWidget(editor);
setLayout(layout);
}

void CoolingTimerConfWidget::updateResetTime(QTime time)
{
updateAttribute("reset",time.toString("mm:ss"));
}

/*:1020*/
#line 20123 "./typica.w"


/*:1022*//*1027:*/
#line 20381 "./typica.w"

/*1024:*/
#line 20155 "./typica.w"

RangeTimerConfWidget::RangeTimerConfWidget(DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QVBoxLayout*layout= new QVBoxLayout;

QGroupBox*startConfigurationGroup= new QGroupBox(tr("Start trigger"));
QRadioButton*startBatchOption= new QRadioButton(tr("Start of batch"));
QRadioButton*buttonOption= new QRadioButton(tr("Manual"));
QRadioButton*thresholdOption= new QRadioButton(tr("At temperature"));
QButtonGroup*startOptionGroup= new QButtonGroup;
startOptionGroup->addButton(startBatchOption,1);
startOptionGroup->addButton(buttonOption,2);
startOptionGroup->addButton(thresholdOption,3);
startBatchOption->setChecked(true);
QGridLayout*startOptions= new QGridLayout;
startOptions->addWidget(startBatchOption,0,0);
startOptions->addWidget(buttonOption,1,0);
startOptions->addWidget(thresholdOption,2,0);
QLabel*buttonTextLabel= new QLabel(tr("Button Text: "));
QLineEdit*buttonTextEdit= new QLineEdit;
QHBoxLayout*buttonTextOptions= new QHBoxLayout;
buttonTextOptions->addWidget(buttonTextLabel);
buttonTextOptions->addWidget(buttonTextEdit);
startOptions->addLayout(buttonTextOptions,1,1);
QFormLayout*thresholdOptions= new QFormLayout;
QLineEdit*startColumnName= new QLineEdit;
QLineEdit*startValue= new QLineEdit;
thresholdOptions->addRow(tr("Column Name: "),startColumnName);
thresholdOptions->addRow(tr("Value: "),startValue);
startOptions->addLayout(thresholdOptions,2,1);
startConfigurationGroup->setLayout(startOptions);
layout->addWidget(startConfigurationGroup);

QGroupBox*stopConfigurationGroup= new QGroupBox(tr("Stop trigger"));
QRadioButton*stopBatchOption= new QRadioButton(tr("End of batch"));
QRadioButton*stopButtonOption= new QRadioButton(tr("Manual"));
QRadioButton*stopThresholdOption= new QRadioButton(tr("At temperature"));
QButtonGroup*stopOptionGroup= new QButtonGroup;
stopOptionGroup->addButton(stopBatchOption,1);
stopOptionGroup->addButton(stopButtonOption,2);
stopOptionGroup->addButton(stopThresholdOption,3);
stopBatchOption->setChecked(true);
QGridLayout*stopOptions= new QGridLayout;
stopOptions->addWidget(stopBatchOption,0,0);
stopOptions->addWidget(stopButtonOption,1,0);
stopOptions->addWidget(stopThresholdOption,2,0);
QLabel*stopButtonLabel= new QLabel(tr("Button Text: "));
QLineEdit*stopButtonEdit= new QLineEdit;
QHBoxLayout*stopButtonTextOptions= new QHBoxLayout;
stopButtonTextOptions->addWidget(stopButtonLabel);
stopButtonTextOptions->addWidget(stopButtonEdit);
stopOptions->addLayout(stopButtonTextOptions,1,1);
QLineEdit*stopColumnName= new QLineEdit;
QLineEdit*stopValue= new QLineEdit;
QFormLayout*stopThresholdOptions= new QFormLayout;
stopThresholdOptions->addRow(tr("Column Name: "),stopColumnName);
stopThresholdOptions->addRow(tr("Value: "),stopValue);
stopOptions->addLayout(stopThresholdOptions,2,1);
stopConfigurationGroup->setLayout(stopOptions);
layout->addWidget(stopConfigurationGroup);

/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 20217 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="startbuttontext")
{
buttonTextEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="stopbuttontext")
{
stopButtonEdit->setText(node.attribute("value"));
}
else if(node.attribute("name")=="startcolumnname")
{
startColumnName->setText(node.attribute("value"));
}
else if(node.attribute("name")=="stopcolumnname")
{
stopColumnName->setText(node.attribute("value"));
}
else if(node.attribute("name")=="startvalue")
{
startValue->setText(node.attribute("value"));
}
else if(node.attribute("name")=="stopvalue")
{
stopValue->setText(node.attribute("value"));
}
else if(node.attribute("name")=="starttrigger")
{
if(node.attribute("value")=="batch")
{
startBatchOption->setChecked(true);
}
else if(node.attribute("value")=="manual")
{
buttonOption->setChecked(true);
}
else if(node.attribute("value")=="value")
{
thresholdOption->setChecked(true);
}
}
else if(node.attribute("name")=="stoptrigger")
{
if(node.attribute("value")=="batch")
{
stopBatchOption->setChecked(true);
}
else if(node.attribute("value")=="manual")
{
stopButtonOption->setChecked(true);
}
else if(node.attribute("value")=="value")
{
stopThresholdOption->setChecked(true);
}
}
}
updateStartButtonText(buttonTextEdit->text());
updateStopButtonText(stopButtonEdit->text());
updateStartColumnName(startColumnName->text());
updateStopColumnName(stopColumnName->text());
updateStartValue(startValue->text());
updateStopValue(stopValue->text());
updateStartTrigger(startOptionGroup->checkedId());
updateStopTrigger(stopOptionGroup->checkedId());

setLayout(layout);

connect(buttonTextEdit,SIGNAL(textChanged(QString)),
this,SLOT(updateStartButtonText(QString)));
connect(stopButtonEdit,SIGNAL(textChanged(QString)),
this,SLOT(updateStopButtonText(QString)));
connect(startColumnName,SIGNAL(textChanged(QString)),
this,SLOT(updateStartColumnName(QString)));
connect(stopColumnName,SIGNAL(textChanged(QString)),
this,SLOT(updateStopColumnName(QString)));
connect(startValue,SIGNAL(textChanged(QString)),
this,SLOT(updateStartValue(QString)));
connect(stopValue,SIGNAL(textChanged(QString)),
this,SLOT(updateStopValue(QString)));
connect(startOptionGroup,SIGNAL(buttonClicked(int)),
this,SLOT(updateStartTrigger(int)));
connect(stopOptionGroup,SIGNAL(buttonClicked(int)),
this,SLOT(updateStopTrigger(int)));
}

/*:1024*//*1025:*/
#line 20307 "./typica.w"

void RangeTimerConfWidget::updateStartButtonText(const QString&text)
{
updateAttribute("startbuttontext",text);
}

void RangeTimerConfWidget::updateStopButtonText(const QString&text)
{
updateAttribute("stopbuttontext",text);
}

void RangeTimerConfWidget::updateStartColumnName(const QString&text)
{
updateAttribute("startcolumnname",text);
}

void RangeTimerConfWidget::updateStopColumnName(const QString&text)
{
updateAttribute("stopcolumnname",text);
}

void RangeTimerConfWidget::updateStartValue(const QString&text)
{
updateAttribute("startvalue",text);
}

void RangeTimerConfWidget::updateStopValue(const QString&text)
{
updateAttribute("stopvalue",text);
}

void RangeTimerConfWidget::updateStartTrigger(int option)
{
switch(option)
{
case 1:
updateAttribute("starttrigger","batch");
break;
case 2:
updateAttribute("starttrigger","manual");
break;
case 3:
updateAttribute("starttrigger","value");
break;
default:
break;
}
}

void RangeTimerConfWidget::updateStopTrigger(int option)
{
switch(option)
{
case 1:
updateAttribute("stoptrigger","batch");
break;
case 2:
updateAttribute("stoptrigger","manual");
break;
case 3:
updateAttribute("stoptrigger","value");
break;
default:
break;
}
}

/*:1025*/
#line 20382 "./typica.w"


/*:1027*//*1032:*/
#line 20482 "./typica.w"

/*1029:*/
#line 20406 "./typica.w"

MultiRangeTimerConfWidget::MultiRangeTimerConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index),tablemodel(new SaltModel(2))
{
QFormLayout*layout= new QFormLayout;
QLineEdit*trigger= new QLineEdit;
layout->addRow(tr("Trigger column name:"),trigger);
tablemodel->setHeaderData(0,Qt::Horizontal,"Range Name");
tablemodel->setHeaderData(1,Qt::Horizontal,"End Temperature");
QTableView*rangeTable= new QTableView;
rangeTable->setModel(tablemodel);
layout->addRow(tr("Range data:"),rangeTable);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 20419 "./typica.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="trigger")
{
trigger->setText(node.attribute("value"));
}
else if(node.attribute("name")=="rangenames")
{
QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
QStringList itemList= data.split(", ");
for(int j= 0;j<itemList.size();j++)
{
QString item= itemList.at(j);
item.chop(1);
item= item.remove(0,1);
tablemodel->setData(tablemodel->index(j,0),
QVariant(item),Qt::DisplayRole);
}
}
else if(node.attribute("name")=="endtemps")
{
/*1015:*/
#line 20014 "./typica.w"

QString data= node.attribute("value");
if(data.length()> 3)
{
data.chop(2);
data= data.remove(0,2);
}
QStringList itemList= data.split(",");

/*:1015*/
#line 20447 "./typica.w"

int column= 1;
/*1016:*/
#line 20026 "./typica.w"

for(int j= 0;j<itemList.size();j++)
{
tablemodel->setData(tablemodel->index(j,column),
QVariant(itemList.at(j).toDouble()),
Qt::DisplayRole);
}

/*:1016*/
#line 20449 "./typica.w"

}
}
updateColumnName(trigger->text());
updateRangeData();
connect(trigger,SIGNAL(textEdited(QString)),this,SLOT(updateColumnName(QString)));
connect(tablemodel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(updateRangeData()));
setLayout(layout);
}

/*:1029*//*1030:*/
#line 20463 "./typica.w"

void MultiRangeTimerConfWidget::updateRangeData()
{
updateAttribute("rangenames",tablemodel->quotedArrayLiteral(0,Qt::DisplayRole));
updateAttribute("endtemps",tablemodel->arrayLiteral(1,Qt::DisplayRole));
}

void MultiRangeTimerConfWidget::updateColumnName(const QString&text)
{
updateAttribute("trigger",text);
}

/*:1030*/
#line 20483 "./typica.w"


/*:1032*//*1050:*/
#line 265 "./rate.w"

/*1046:*/
#line 191 "./rate.w"

RateOfChangeConfWidget::RateOfChangeConfWidget(DeviceTreeModel*model,const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QLineEdit*column= new QLineEdit;
layout->addRow(tr("Primary series column name:"),column);
QSpinBox*cacheTime= new QSpinBox;
cacheTime->setMinimum(0);
cacheTime->setMaximum(300);
layout->addRow(tr("Cache time:"),cacheTime);
QSpinBox*scaleTime= new QSpinBox;
scaleTime->setMinimum(1);
scaleTime->setMaximum(300);
layout->addRow(tr("Scale time:"),scaleTime);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 206 "./rate.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="column")
{
column->setText(node.attribute("value"));
}
else if(node.attribute("name")=="cache")
{
cacheTime->setValue(node.attribute("value").toInt());
}
else if(node.attribute("name")=="scale")
{
scaleTime->setValue(node.attribute("value").toInt());
}
}
updateColumn(column->text());
updateCacheTime(cacheTime->text());
updateScaleTime(scaleTime->text());
connect(column,SIGNAL(textEdited(QString)),this,SLOT(updateColumn(QString)));
connect(cacheTime,SIGNAL(valueChanged(QString)),this,SLOT(updateCacheTime(QString)));
connect(scaleTime,SIGNAL(valueChanged(QString)),this,SLOT(updateScaleTime(QString)));
setLayout(layout);
}

/*:1046*//*1047:*/
#line 235 "./rate.w"

void RateOfChangeConfWidget::updateColumn(const QString&column)
{
updateAttribute("column",column);
}

void RateOfChangeConfWidget::updateCacheTime(const QString&seconds)
{
updateAttribute("cache",seconds);
}

void RateOfChangeConfWidget::updateScaleTime(const QString&seconds)
{
updateAttribute("scale",seconds);
}

/*:1047*/
#line 266 "./rate.w"

#line 20590 "./typica.w"

#line 1 "./mergeseries.w"
/*:1050*//*1064:*/
#line 282 "./mergeseries.w"

/*1060:*/
#line 183 "./mergeseries.w"

MergeSeriesConfWidget::MergeSeriesConfWidget(DeviceTreeModel*model,
const QModelIndex&index)
:BasicDeviceConfigurationWidget(model,index)
{
QFormLayout*layout= new QFormLayout;
QComboBox*type= new QComboBox;
type->addItem(tr("Difference"),QVariant("Difference"));
type->addItem(tr("Mean"),QVariant("Mean"));
layout->addRow(tr("Series type:"),type);
QLineEdit*column1= new QLineEdit;
layout->addRow(tr("First input column name:"),column1);
QLineEdit*column2= new QLineEdit;
layout->addRow(tr("Second input column name:"),column2);
QLineEdit*output= new QLineEdit;
layout->addRow(tr("Output column name:"),output);
/*816:*/
#line 16928 "./typica.w"

QDomElement referenceElement= 
model->referenceElement(model->data(index,Qt::UserRole).toString());
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;

/*:816*/
#line 199 "./mergeseries.w"

for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
if(node.attribute("name")=="type")
{
type->setCurrentIndex(type->findData(node.attribute("value")));
}
else if(node.attribute("name")=="column1")
{
column1->setText(node.attribute("value"));
}
else if(node.attribute("name")=="column2")
{
column2->setText(node.attribute("value"));
}
else if(node.attribute("name")=="output")
{
output->setText(node.attribute("value"));
}
}
updateColumn1(column1->text());
updateColumn2(column2->text());
updateOutput(output->text());
updateType(type->currentIndex());
connect(column1,SIGNAL(textEdited(QString)),this,SLOT(updateColumn1(QString)));
connect(column2,SIGNAL(textEdited(QString)),this,SLOT(updateColumn2(QString)));
connect(output,SIGNAL(textEdited(QString)),this,SLOT(updateOutput(QString)));
connect(type,SIGNAL(currentIndexChanged(int)),this,SLOT(updateType(int)));
setLayout(layout);
}

/*:1060*//*1061:*/
#line 233 "./mergeseries.w"

void MergeSeriesConfWidget::updateColumn1(const QString&column)
{
updateAttribute("column1",column);
}

void MergeSeriesConfWidget::updateColumn2(const QString&column)
{
updateAttribute("column2",column);
}

void MergeSeriesConfWidget::updateOutput(const QString&column)
{
updateAttribute("output",column);
}

void MergeSeriesConfWidget::updateType(int index)
{
switch(index)
{
case 0:
updateAttribute("type","Difference");
break;
case 1:
updateAttribute("type","Mean");
break;
default:
break;
}
}

/*:1061*/
#line 283 "./mergeseries.w"

/*1052:*/
#line 59 "./mergeseries.w"

void MergeSeries::in1(Measurement measure)
{
last1= measure;
received1= true;
if(received1&&received2)
{
calculate(last1,last2);
received1= false;
received2= false;
}
}

void MergeSeries::in2(Measurement measure)
{
last2= measure;
received2= true;
if(received1&&received2)
{
calculate(last1,last2);
received1= false;
received2= false;
}
}

/*:1052*//*1053:*/
#line 86 "./mergeseries.w"

MergeSeries::MergeSeries():QObject(NULL),received1(false),received2(false)
{

}

/*:1053*//*1054:*/
#line 97 "./mergeseries.w"

void DifferenceSeries::calculate(Measurement m1,Measurement m2)
{
Measurement outval(m1.temperature()-m2.temperature(),
(m1.time()> m2.time()?m1.time():m2.time()));
outval.insert("relative",true);
emit newData(outval);
}

void MeanSeries::calculate(Measurement m1,Measurement m2)
{
Measurement outval((m1.temperature()+m2.temperature())/2,
(m1.time()> m2.time()?m1.time():m2.time()));
emit newData(outval);
}

/*:1054*//*1055:*/
#line 115 "./mergeseries.w"

DifferenceSeries::DifferenceSeries():MergeSeries()
{

}

MeanSeries::MeanSeries():MergeSeries()
{

}

/*:1055*/
#line 284 "./mergeseries.w"


#line 20592 "./typica.w"

#line 1 "./dataqsdk.w"
/*:1064*//*1179:*/
#line 344 "./user.w"

/*1174:*/
#line 232 "./user.w"

NewTypicaUser::NewTypicaUser():QDialog(),
userField(new QLineEdit),passwordField(new QLineEdit),
autoLogin(new QCheckBox(tr("Log in automatically"))),
saveAndCloseButton(new QPushButton(tr("Save and Close"))),
saveAndNewButton(new QPushButton(tr("Save and Create Another"))),
cancelButton(new QPushButton(tr("Cancel")))
{
setModal(true);
QVBoxLayout*mainLayout= new QVBoxLayout;
QFormLayout*form= new QFormLayout;
QHBoxLayout*buttons= new QHBoxLayout;
form->addRow(tr("Name:"),userField);
passwordField->setEchoMode(QLineEdit::Password);
form->addRow(tr("Password:"),passwordField);
form->addRow(autoLogin);
buttons->addWidget(cancelButton);
buttons->addStretch();
buttons->addWidget(saveAndNewButton);
buttons->addWidget(saveAndCloseButton);
mainLayout->addLayout(form);
mainLayout->addLayout(buttons);
setLayout(mainLayout);
setWindowTitle(tr("Create New User"));
connect(cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
connect(saveAndCloseButton,SIGNAL(clicked()),this,SLOT(createAndClose()));
connect(saveAndNewButton,SIGNAL(clicked()),this,SLOT(createAndReset()));
connect(userField,SIGNAL(textChanged(QString)),this,SLOT(validate()));
}

/*:1174*//*1175:*/
#line 264 "./user.w"

void NewTypicaUser::createAndReset()
{
createNewUser();
userField->setText("");
passwordField->setText("");
autoLogin->setChecked(false);
}

void NewTypicaUser::createAndClose()
{
createNewUser();
accept();
}

void NewTypicaUser::createNewUser()
{
SqlQueryConnection h;
QSqlQuery*dbquery= h.operator->();
dbquery->prepare("INSERT INTO typica_users (name, password, active, auto_login) VALUES (:name, :password, true, :auto)");
dbquery->bindValue(":name",userField->text());
dbquery->bindValue(":password",passwordField->text());
dbquery->bindValue(":auto",autoLogin->isChecked());
dbquery->exec();
cancelButton->setEnabled(true);
}

void NewTypicaUser::validate()
{
if(!userField->text().isEmpty())
{
saveAndCloseButton->setEnabled(true);
saveAndNewButton->setEnabled(true);
}
else
{
saveAndCloseButton->setEnabled(false);
saveAndNewButton->setEnabled(false);
}
}

void NewTypicaUser::cancelValidate()
{
SqlQueryConnection h;
QSqlQuery*dbquery= h.operator->();
dbquery->exec("SELECT count(1) FROM typica_users");
if(dbquery->next())
{
if(dbquery->value(0).toInt()> 0)
{
cancelButton->setEnabled(true);
return;
}
}
cancelButton->setEnabled(false);
}

/*:1175*/
#line 345 "./user.w"

/*1170:*/
#line 177 "./user.w"

UserLabel::UserLabel():QLabel()
{
setTextFormat(Qt::PlainText);
updateLabel(AppInstance->currentTypicaUser());
connect(AppInstance,SIGNAL(userChanged(QString)),
this,SLOT(updateLabel(QString)));
}

/*:1170*//*1171:*/
#line 188 "./user.w"

void UserLabel::updateLabel(const QString&user)
{
setText(QString(tr("Current operator: %1").arg(user)));
}

/*:1171*//*1172:*/
#line 196 "./user.w"

void UserLabel::mouseReleaseEvent(QMouseEvent*)
{
LoginDialog*dialog= new LoginDialog;
dialog->exec();
}

/*:1172*/
#line 346 "./user.w"

/*1164:*/
#line 95 "./user.w"

LoginDialog::LoginDialog():QDialog(),
user(new QLineEdit),password(new QLineEdit),
warning(new QLabel(tr("Log in failed."))),
login(new QPushButton(tr("Log In")))
{
setModal(true);
QVBoxLayout*mainLayout= new QVBoxLayout;
warning->setVisible(false);
password->setEchoMode(QLineEdit::Password);
QFormLayout*form= new QFormLayout;
form->addRow(tr("Name:"),user);
form->addRow(tr("Password:"),password);
form->addRow(warning);
QHBoxLayout*buttonBox= new QHBoxLayout;
buttonBox->addStretch();
buttonBox->addWidget(login);
mainLayout->addLayout(form);
mainLayout->addLayout(buttonBox);
connect(login,SIGNAL(clicked()),this,SLOT(attemptLogin()));
setLayout(mainLayout);
}

/*:1164*//*1165:*/
#line 120 "./user.w"

void LoginDialog::attemptLogin()
{
if(AppInstance->login(user->text(),password->text()))
{
accept();
}
else
{
warning->setVisible(true);
}
}

/*:1165*/
#line 347 "./user.w"

#line 20602 "./typica.w"

#line 1 "./roastcoloredit.w"
/*:1179*//*1187:*/
#line 149 "./roastcoloredit.w"

/*1181:*/
#line 31 "./roastcoloredit.w"

RoastColorEdit::RoastColorEdit():edit(new QLineEdit)
{
QHBoxLayout*layout= new QHBoxLayout;
layout->setContentsMargins(0,0,0,0);
layout->addWidget(edit);
QSettings settings;
if(settings.value("settings/color/javalytics/enable",false).toBool())
{
QPushButton*button= new QPushButton(tr("Measure"));
layout->addWidget(button);
connect(button,SIGNAL(clicked()),this,SLOT(readColor()));
}
setLayout(layout);
}

/*:1181*//*1182:*/
#line 50 "./roastcoloredit.w"

void RoastColorEdit::readColor()
{
QSettings settings;
QUrl postData;
postData.addQueryItem("calscale",settings.value("settings/color/javalytics/scale",1).toString());
postData.addQueryItem("webcontrol","20");
QNetworkRequest request(QUrl("http://"+settings.value("settings/color/javalytics/address","192.168.1.10").toString()+"/index.zhtml"));
request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
networkReply= AppInstance->network->post(request,postData.encodedQuery());
connect(networkReply,SIGNAL(finished()),this,SLOT(measureFinished()));
}

/*:1182*//*1183:*/
#line 66 "./roastcoloredit.w"

void RoastColorEdit::measureFinished()
{
QSettings settings;
networkReply->deleteLater();
networkReply= AppInstance->network->get(QNetworkRequest(QUrl("http://"+settings.value("settings/color/javalytics/address","192.168.1.10").toString()+"/data.csv")));
connect(networkReply,SIGNAL(finished()),this,SLOT(readFinished()));
}

/*:1183*//*1184:*/
#line 93 "./roastcoloredit.w"

void RoastColorEdit::readFinished()
{
QByteArray response= networkReply->readAll();
networkReply->deleteLater();
networkReply= 0;
if(response.size()==0)
{
return;
}
QList<QByteArray> lines= response.split('\n');
if(lines.last().size()==0)
{
lines.removeLast();
}
if(lines.size()==0)
{
return;
}
QList<QByteArray> fields= lines.last().split(',');
if(fields.size()<3)
{
return;
}
edit->setText(QString(fields.at(2)));
}

/*:1184*//*1185:*/
#line 122 "./roastcoloredit.w"

void RoastColorEdit::setValue(const QString&color)
{
edit->setText(color);
}

QString RoastColorEdit::value()
{
return edit->text();
}

/*:1185*/
#line 150 "./roastcoloredit.w"

#line 20604 "./typica.w"

/*:1187*/
#line 532 "./typica.w"

/*8:*/
#line 679 "./typica.w"

template<class TYPE> TYPE getself(QScriptContext*context)
{
TYPE self= qobject_cast<TYPE> (context->thisObject().toQObject());
return self;
}

template<> QTime getself(QScriptContext*context)
{
QTime self= context->thisObject().toVariant().toTime();
return self;
}

template<> QByteArray getself(QScriptContext*context)
{
QByteArray self= context->thisObject().toVariant().toByteArray();
return self;
}

template<> SqlQueryConnection*getself(QScriptContext*context)
{
SqlQueryConnection*self= 
(SqlQueryConnection*)qscriptvalue_cast<void*> (context->thisObject());
return self;
}

template<> QXmlQuery*getself(QScriptContext*context)
{
QXmlQuery*self= 
(QXmlQuery*)qscriptvalue_cast<void*> (context->thisObject());
return self;
}

template<> QXmlStreamWriter*getself(QScriptContext*context)
{
QXmlStreamWriter*self= 
(QXmlStreamWriter*)qscriptvalue_cast<void*> (context->thisObject());
return self;
}

template<> QXmlStreamReader*getself(QScriptContext*context)
{
QXmlStreamReader*self= 
(QXmlStreamReader*)qscriptvalue_cast<void*> (context->thisObject());
return self;
}

/*:8*//*9:*/
#line 730 "./typica.w"

template<class TYPE> TYPE argument(int arg,QScriptContext*context)
{
TYPE argument= qobject_cast<TYPE> (context->argument(arg).toQObject());
return argument;
}

template<> QString argument(int arg,QScriptContext*context)
{
return context->argument(arg).toString();
}

template<> QVariant argument(int arg,QScriptContext*context)
{
return context->argument(arg).toVariant();
}

template<> int argument(int arg,QScriptContext*context)
{
return context->argument(arg).toInt32();
}

template<> SqlQueryConnection*argument(int arg,QScriptContext*context)
{
return(SqlQueryConnection*)
qscriptvalue_cast<void*> (context->argument(arg));
}

template<> QModelIndex argument(int arg,QScriptContext*context)
{
return qscriptvalue_cast<QModelIndex> (context->argument(arg));
}

template<> double argument(int arg,QScriptContext*context)
{
return(double)(context->argument(arg).toNumber());
}

template<> Units::Unit argument(int arg,QScriptContext*context)
{
return(Units::Unit)(context->argument(arg).toInt32());
}

template<> QByteArray argument(int arg,QScriptContext*context)
{
return qscriptvalue_cast<QByteArray> (context->argument(arg));
}

template<> bool argument(int arg,QScriptContext*context)
{
return context->argument(arg).toBool();
}

/*:9*//*13:*/
#line 829 "./typica.w"

void setQObjectProperties(QScriptValue value,QScriptEngine*engine)
{
value.setProperty("setProperty",engine->newFunction(QObject_setProperty));
}

QScriptValue QObject_setProperty(QScriptContext*context,QScriptEngine*)
{
QObject*self= getself<QObject*> (context);
self->setProperty(argument<QString> (0,context).toUtf8().constData(),
argument<QVariant> (1,context));
return QScriptValue();
}

/*:13*//*15:*/
#line 851 "./typica.w"

void setQPaintDeviceProperties(QScriptValue,QScriptEngine*)
{

}

void setQLayoutItemProperties(QScriptValue,QScriptEngine*)
{

}

/*:15*//*18:*/
#line 883 "./typica.w"

void setQTimerProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}

QScriptValue constructQTimer(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QTimer);
setQTimerProperties(object,engine);
return object;
}


/*:18*//*21:*/
#line 925 "./typica.w"

QScriptValue constructQWidget(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QWidget);
setQWidgetProperties(object,engine);
return object;
}

void setQWidgetProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
setQPaintDeviceProperties(value,engine);
value.setProperty("setLayout",engine->newFunction(QWidget_setLayout));
value.setProperty("activateWindow",
engine->newFunction(QWidget_activateWindow));
}

/*:21*//*22:*/
#line 947 "./typica.w"

QScriptValue QWidget_setLayout(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==1)
{
QWidget*self= getself<QWidget*> (context);
QLayout*layout= argument<QLayout*> (0,context);
if(layout)
{
self->setLayout(layout);
}
else
{
context->throwError("Incorrect argument type passed to "
"QWidget::setLayout(). This method requires "
"a QLayout.");
}
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QWidget::setLayout(). This method takes one "
"QLayout as an argument.");
}
return QScriptValue();
}

QScriptValue QWidget_activateWindow(QScriptContext*context,
QScriptEngine*)
{
QWidget*self= getself<QWidget*> (context);
self->activateWindow();
return QScriptValue();
}

/*:22*//*25:*/
#line 1012 "./typica.w"

QScriptValue displayWarning(QScriptContext*context,QScriptEngine*)
{
QMessageBox::StandardButton selection= QMessageBox::warning(NULL,
argument<QString> (0,context),
argument<QString> (1,context),
QMessageBox::Ok|QMessageBox::Cancel);
if(selection==QMessageBox::Ok){
return QScriptValue(true);
}
return QScriptValue(false);
}

QScriptValue displayError(QScriptContext*context,QScriptEngine*)
{
QMessageBox::critical(NULL,argument<QString> (0,context),
argument<QString> (1,context));
return QScriptValue();
}

QScriptValue displayInfo(QScriptContext*context,QScriptEngine*)
{
QMessageBox::information(NULL,argument<QString> (0,context),
argument<QString> (1,context));
return QScriptValue();
}

/*:25*//*27:*/
#line 1097 "./typica.w"

ScriptQMainWindow::ScriptQMainWindow():QMainWindow(NULL),
cprompt(tr("Closing this window may result in loss of data. Continue?"))
{
if(!AppInstance->databaseConnected())
{
statusBar()->addWidget(new QLabel(tr("Not connected to database")));
}
else
{
statusBar()->addWidget(new UserLabel);
}
}

void ScriptQMainWindow::saveSizeAndPosition(const QString&key)
{
QSettings settings;
settings.beginGroup(key);
settings.setValue("pos",pos());
settings.setValue("size",size());
settings.endGroup();
}

void ScriptQMainWindow::restoreSizeAndPosition(const QString&key)
{
QSettings settings;
settings.beginGroup(key);
if(settings.contains("size"))
{
resize(settings.value("size").toSize());
}
if(settings.contains("pos"))
{
move(settings.value("pos").toPoint());
}
settings.endGroup();
}

void ScriptQMainWindow::displayStatus(const QString&message)
{
statusBar()->showMessage(message);
}

void ScriptQMainWindow::showEvent(QShowEvent*event)
{
if(!event->spontaneous())
{
/*32:*/
#line 1221 "./typica.w"

QSettings settings;
restoreGeometry(settings.value(QString("geometries/%1").arg(objectName())).
toByteArray());

/*:32*/
#line 1144 "./typica.w"

event->accept();
}
else
{
event->ignore();
}
}

void ScriptQMainWindow::show()
{
QMainWindow::show();
}

void ScriptQMainWindow::setupFinished()
{
emit windowReady();
}

/*:27*//*28:*/
#line 1170 "./typica.w"

void ScriptQMainWindow::closeEvent(QCloseEvent*event)
{
if(isWindowModified()){
/*29:*/
#line 1184 "./typica.w"

QMessageBox::StandardButton result;
result= QMessageBox::warning(this,"Typica",closePrompt(),
QMessageBox::Ok|QMessageBox::Cancel);
if(result==QMessageBox::Cancel)
{
event->ignore();
return;
}

/*:29*/
#line 1174 "./typica.w"

}
emit aboutToClose();
/*31:*/
#line 1215 "./typica.w"

QSettings settings;
settings.setValue(QString("geometries/%1").arg(objectName()),saveGeometry());

/*:31*/
#line 1177 "./typica.w"

event->accept();
}

/*:28*//*30:*/
#line 1196 "./typica.w"

QString ScriptQMainWindow::closePrompt()
{
return cprompt;
}

void ScriptQMainWindow::setClosePrompt(QString prompt)
{
cprompt= prompt;
}

/*:30*//*35:*/
#line 1249 "./typica.w"

QScriptValue constructQMainWindow(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new ScriptQMainWindow);
setQMainWindowProperties(object,engine);
return object;
}

void setQMainWindowProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
value.setProperty("setCentralWidget",
engine->newFunction(QMainWindow_setCentralWidget));
value.setProperty("menuBar",engine->newFunction(QMainWindow_menuBar));
}

/*:35*//*36:*/
#line 1271 "./typica.w"

QScriptValue QMainWindow_setCentralWidget(QScriptContext*context,
QScriptEngine*)
{
if(context->argumentCount()==1)
{
QMainWindow*self= getself<QMainWindow*> (context);
QWidget*widget= argument<QWidget*> (0,context);
if(widget)
{
self->setCentralWidget(widget);
}
else
{
context->throwError("Incorrect argument type passed to "
"QMainWindow::setCentralWidget(). This "
"method requires a QWidget.");
}
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QMainWindow::setCentralWidget(). This method "
"takes one QWidget as an argument.");
}
return QScriptValue();
}

/*:36*//*37:*/
#line 1305 "./typica.w"

QScriptValue QMainWindow_menuBar(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==0)
{
QMainWindow*self= getself<QMainWindow*> (context);
QMenuBar*bar= self->menuBar();
object= engine->newQObject(bar);
setQMenuBarProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QMainWindow::menuBar(). This method takes no "
"arguments.");
}
return object;
}

/*:37*//*39:*/
#line 1335 "./typica.w"

void setQMenuBarProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
value.setProperty("addMenu",engine->newFunction(QMenuBar_addMenu));
}

/*:39*//*40:*/
#line 1350 "./typica.w"

QScriptValue QMenuBar_addMenu(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==1)
{
QMenuBar*self= getself<QMenuBar*> (context);
QString title= argument<QString> (0,context);
object= engine->newQObject(self->addMenu(title));
setQMenuProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QMenuBar::addMenu(). This method takes one "
"string as an argument.");
}
return object;
}

/*:40*//*42:*/
#line 1380 "./typica.w"

void setQMenuProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
value.setProperty("addAction",engine->newFunction(QMenu_addAction));
value.setProperty("addSeparator",engine->newFunction(QMenu_addSeparator));
}

/*:42*//*43:*/
#line 1390 "./typica.w"

QScriptValue QMenu_addAction(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==1)
{
QMenu*self= getself<QMenu*> (context);
QAction*action= argument<QAction*> (0,context);
if(action)
{
self->addAction(action);
}
else
{
context->throwError("Incorrect argument type passed to "
"QMenu::addAction(). This method requires a "
"QAction.");
}
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QMenu::addAction(). This method takes one "
"QAction as an argument.");
}
return QScriptValue();
}

QScriptValue QMenu_addSeparator(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==0)
{
QMenu*self= getself<QMenu*> (context);
self->addSeparator();
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QMenu::addSeparator(). This method takes no "
"arguments.");
}
return QScriptValue();
}

/*:43*//*46:*/
#line 1452 "./typica.w"

QScriptValue constructQFrame(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QFrame);
setQFrameProperties(object,engine);
return object;
}

void setQFrameProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
}

/*:46*//*49:*/
#line 1486 "./typica.w"

QScriptValue constructQLabel(QScriptContext*context,QScriptEngine*engine)
{
QString text;
if(context->argumentCount()==1)
{
text= argument<QString> (0,context);
}
QScriptValue object= engine->newQObject(new QLabel(text));
setQLabelProperties(object,engine);
return object;
}

void setQLabelProperties(QScriptValue value,QScriptEngine*engine)
{
setQFrameProperties(value,engine);
}

/*:49*//*52:*/
#line 1528 "./typica.w"

QScriptValue constructQSvgWidget(QScriptContext*,
QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QSvgWidget);
setQSvgWidgetProperties(object,engine);
return object;
}

/*:52*//*53:*/
#line 1539 "./typica.w"

void setQSvgWidgetProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
value.setProperty("loadDevice",
engine->newFunction(QSvgWidget_loadDevice));
}

QScriptValue QSvgWidget_loadDevice(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==1)
{
QSvgWidget*self= getself<QSvgWidget*> (context);
QIODevice*device= argument<QIODevice*> (0,context);
device->reset();
QByteArray data= device->readAll();
self->load(data);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QSvgWidget::loadData(). This method takes one "
"QIODevice as an argument.");
}
return QScriptValue();
}

/*:53*//*55:*/
#line 1577 "./typica.w"

void addSvgWidgetToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
QSvgWidget*widget= new QSvgWidget;
layout->addWidget(widget);
QString id= element.attribute("id");
if(!id.isEmpty())
{
widget->setObjectName(id);
}
}

/*:55*//*58:*/
#line 1610 "./typica.w"

QScriptValue constructQLineEdit(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QLineEdit());
setQLineEditProperties(object,engine);
return object;
}

/*:58*//*59:*/
#line 1621 "./typica.w"

void setQLineEditProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
}

/*:59*//*62:*/
#line 1659 "./typica.w"

QScriptValue constructQSplitter(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QSplitter);
setQSplitterProperties(object,engine);
return object;
}

void setQSplitterProperties(QScriptValue value,QScriptEngine*engine)
{
setQFrameProperties(value,engine);
value.setProperty("addWidget",engine->newFunction(QSplitter_addWidget));
value.setProperty("saveState",engine->newFunction(QSplitter_saveState));
value.setProperty("restoreState",
engine->newFunction(QSplitter_restoreState));
value.setProperty("count",engine->newFunction(QSplitter_count));
value.setProperty("setCollapsible",engine->newFunction(QSplitter_setCollapsible));
}

/*:62*//*63:*/
#line 1681 "./typica.w"

QScriptValue QSplitter_addWidget(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==1)
{
QSplitter*self= getself<QSplitter*> (context);
QWidget*widget= argument<QWidget*> (0,context);
if(widget)
{
self->addWidget(widget);
}
else
{
context->throwError("Incorrect argument type passed to "
"QSplitter::addWidget(). This method "
"requires a QWidget.");
}
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QSplitter::addWidget(). This method takes one "
"QWidget as an argument.");
}
return QScriptValue();
}

/*:63*//*64:*/
#line 1718 "./typica.w"

QScriptValue QSplitter_count(QScriptContext*context,QScriptEngine*)
{
QSplitter*self= getself<QSplitter*> (context);
return QScriptValue(self->count());
}

/*:64*//*65:*/
#line 1731 "./typica.w"

QScriptValue QSplitter_saveState(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==1)
{
QSplitter*self= getself<QSplitter*> (context);
QString key= argument<QString> (0,context);
QSettings settings;
settings.setValue(key,self->saveState());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QSplitter::saveState(). This method takes one "
"string as an argument.");
}
return QScriptValue();
}

QScriptValue QSplitter_restoreState(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==1)
{
QSplitter*self= getself<QSplitter*> (context);
QString key= argument<QString> (0,context);
QSettings settings;
self->restoreState(settings.value(key).toByteArray());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QSplitter::restoreState(). This method takes "
"one string as an argument.");
}
return QScriptValue();
}

/*:65*//*66:*/
#line 1772 "./typica.w"

QScriptValue QSplitter_setCollapsible(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==2)
{
QSplitter*self= getself<QSplitter*> (context);
self->setCollapsible(argument<int> (0,context),argument<bool> (1,context));
}
else
{
context->throwError("Incorrect number of arguments");
}
return QScriptValue();
}

/*:66*//*68:*/
#line 1803 "./typica.w"

void setQLayoutProperties(QScriptValue value,QScriptEngine*engine)
{
setQLayoutItemProperties(value,engine);
value.setProperty("addWidget",engine->newFunction(QLayout_addWidget));
}

QScriptValue QLayout_addWidget(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==1)
{
QLayout*self= getself<QLayout*> (context);
QWidget*widget= argument<QWidget*> (0,context);
if(widget)
{
self->addWidget(widget);
}
else
{
context->throwError("Incorrect argument type passed to "
"QLayout::addWidget(). This method requires "
"a QWidget.");
}
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QLayout::addWidget(). This method takes one "
"QWidget as an argument.");
}
return QScriptValue();
}

/*:68*//*71:*/
#line 1870 "./typica.w"

QScriptValue constructQBoxLayout(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= 
engine->newQObject(new QBoxLayout(QBoxLayout::LeftToRight));
setQBoxLayoutProperties(object,engine);
return object;
}

void setQBoxLayoutProperties(QScriptValue value,QScriptEngine*engine)
{
setQLayoutProperties(value,engine);
value.setProperty("addLayout",engine->newFunction(QBoxLayout_addLayout));
value.setProperty("addWidget",engine->newFunction(QBoxLayout_addWidget));
}

QScriptValue QBoxLayout_addLayout(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()> 0&&context->argumentCount()<3)
{
QBoxLayout*self= getself<QBoxLayout*> (context);
QLayout*layout= argument<QLayout*> (0,context);
int stretch= 0;
if(context->argumentCount()==2)
{
stretch= argument<int> (1,context);
}
if(layout)
{
self->addLayout(layout,stretch);
}
else
{
context->throwError("Incorrect argument type passed to "
"QLayout::addLayout(). This method requires "
"a QLayout.");
}
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QLayout::addLayout(). This method takes one "
"QLayout as an argument and optionally one integer.");
}
return QScriptValue();
}

/*:71*//*72:*/
#line 1921 "./typica.w"

QScriptValue QBoxLayout_addWidget(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()> 0&&context->argumentCount()<4)
{
QBoxLayout*self= getself<QBoxLayout*> (context);
QWidget*widget= argument<QWidget*> (0,context);
int stretch= 0;
Qt::Alignment alignment= 0;
if(context->argumentCount()> 1)
{
stretch= argument<int> (1,context);
}
if(context->argumentCount()> 2)
{
alignment= (Qt::Alignment)(argument<int> (2,context));
}
if(widget)
{
self->addWidget(widget,stretch,alignment);
}
else
{
context->throwError("Incorrect argument type passed to "
"QBoxLayout::addWidget(). This method requires "
"a QWidget.");
}
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QBoxLayout::addWidget(). This method takes one "
"QWidget and optionally up to two integers as "
"arguments.");
}
return QScriptValue();
}

/*:72*//*75:*/
#line 1985 "./typica.w"

QScriptValue constructQAction(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QAction(NULL));
setQActionProperties(object,engine);
return object;
}

void setQActionProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
value.setProperty("setShortcut",engine->newFunction(QAction_setShortcut));
}

QScriptValue QAction_setShortcut(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==1)
{
QAction*self= getself<QAction*> (context);
self->setShortcut(argument<QString> (0,context));
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QAction::setShortcut(). This method takes one "
"string as an argument.");
}
return QScriptValue();
}

/*:75*//*78:*/
#line 2043 "./typica.w"

QScriptValue QFileDialog_getOpenFileName(QScriptContext*context,
QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==3)
{
QWidget*widget= argument<QWidget*> (0,context);
if(widget)
{
QString caption= argument<QString> (1,context);
QString dir= argument<QString> (2,context);
retval= QScriptValue(engine,
QFileDialog::getOpenFileName(widget,caption,
dir,"",0,0));
setQFileDialogProperties(retval,engine);
}
else
{
context->throwError("Incorrect argument type passed to "
"QFileDialog::getOpenFileName(). The first "
"argument to this method must be a QWidget.");
}
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QFileDialog::getOpenFileName(). This method "
"takes one QWidget followed by two strings for a "
"total of three arguments.");
}
return retval;
}

/*:78*//*79:*/
#line 2079 "./typica.w"

QScriptValue QFileDialog_getSaveFileName(QScriptContext*context,
QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==3)
{
QWidget*widget= argument<QWidget*> (0,context);
if(widget)
{
QString caption= argument<QString> (1,context);
QString dir= argument<QString> (2,context);
retval= QScriptValue(engine,
QFileDialog::getSaveFileName(widget,caption,
dir,"",0,0));

setQFileDialogProperties(retval,engine);
}
else
{
context->throwError("Incorrect argument type passed to "
"QFileDialog::getSaveFileName(). The first "
"argument to this method must be a QWidget.");
}
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QFileDialog::getSaveFileName(). This method "
"takes one QWidget followed by two strings for a "
"total of three arguments.");
}
return retval;
}

/*:79*//*80:*/
#line 2116 "./typica.w"

void setQFileDialogProperties(QScriptValue value,QScriptEngine*engine)
{
setQDialogProperties(value,engine);
}

void setQDialogProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
}

/*:80*//*83:*/
#line 2157 "./typica.w"

QScriptValue constructQFile(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object= 
engine->newQObject(new QFile(argument<QString> (0,context)));
setQFileProperties(object,engine);
return object;
}

/*:83*//*84:*/
#line 2168 "./typica.w"

void setQFileProperties(QScriptValue value,QScriptEngine*engine)
{
setQIODeviceProperties(value,engine);
value.setProperty("remove",engine->newFunction(QFile_remove));
}

QScriptValue QFile_remove(QScriptContext*context,QScriptEngine*engine)
{
QFile*self= getself<QFile*> (context);
bool retval= self->remove();
return QScriptValue(engine,retval);
}

/*:84*//*85:*/
#line 2190 "./typica.w"

void setQIODeviceProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
value.setProperty("open",engine->newFunction(QIODevice_open));
value.setProperty("close",engine->newFunction(QIODevice_close));
value.setProperty("readToString",
engine->newFunction(QIODevice_readToString));
value.setProperty("putChar",engine->newFunction(QIODevice_putChar));
value.setProperty("writeString",engine->newFunction(QIODevice_writeString));
value.setProperty("writeBytes",engine->newFunction(QIODevice_writeBytes));
value.setProperty("readBytes",engine->newFunction(QIODevice_readBytes));
value.setProperty("peek",engine->newFunction(QIODevice_peek));
value.setProperty("read",engine->newFunction(QIODevice_read));
}

/*:85*//*86:*/
#line 2211 "./typica.w"

QScriptValue QIODevice_open(QScriptContext*context,QScriptEngine*)
{
QIODevice*self= getself<QIODevice*> (context);
bool retval= false;
if(context->argumentCount()==1)
{
switch(argument<int> (0,context))
{
case 1:
retval= self->open(QIODevice::ReadOnly);
break;
case 2:
retval= self->open(QIODevice::WriteOnly);
break;
case 3:
retval= self->open(QIODevice::ReadWrite);
break;
default:
break;
}
}
else
{
retval= self->open(QIODevice::ReadWrite);
}
return QScriptValue(retval);
}

QScriptValue QIODevice_close(QScriptContext*context,QScriptEngine*)
{
QIODevice*self= getself<QIODevice*> (context);
self->close();
return QScriptValue();
}

/*:86*//*87:*/
#line 2251 "./typica.w"

QScriptValue QIODevice_readToString(QScriptContext*context,QScriptEngine*)
{
QIODevice*self= getself<QIODevice*> (context);
self->reset();
return QScriptValue(QString(self->readAll()));
}

/*:87*//*88:*/
#line 2267 "./typica.w"

QScriptValue QIODevice_putChar(QScriptContext*context,QScriptEngine*)
{
QIODevice*self= getself<QIODevice*> (context);
if(context->argumentCount()==1)
{
return QScriptValue(self->putChar(argument<QString> (0,context).toUtf8().at(0)));
}
context->throwError("Incorrect number of arguments passed to "
"QIODevice::putChar()");
return QScriptValue();
}

/*:88*//*89:*/
#line 2285 "./typica.w"

QScriptValue QIODevice_writeString(QScriptContext*context,QScriptEngine*)
{
QIODevice*self= getself<QIODevice*> (context);
if(context->argumentCount()==1)
{
self->write(argument<QString> (0,context).toUtf8());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QIODevice::writeString()");
}
return QScriptValue();
}

QScriptValue QIODevice_writeBytes(QScriptContext*context,QScriptEngine*)
{
QIODevice*self= getself<QIODevice*> (context);
if(context->argumentCount()==1)
{
self->write(argument<QByteArray> (0,context));
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QIODevice::writeBytes()");
}
return QScriptValue();
}

/*:89*//*90:*/
#line 2319 "./typica.w"

QScriptValue QIODevice_readBytes(QScriptContext*context,QScriptEngine*engine)
{
QIODevice*self= getself<QIODevice*> (context);
QScriptValue value= engine->toScriptValue<QByteArray> (self->readAll());
setQByteArrayProperties(value,engine);
return value;
}

/*:90*//*91:*/
#line 2330 "./typica.w"

QScriptValue QIODevice_peek(QScriptContext*context,QScriptEngine*engine)
{
QIODevice*self= getself<QIODevice*> (context);
QScriptValue value= engine->toScriptValue<QByteArray> (
self->peek(argument<int> (0,context)));
setQByteArrayProperties(value,engine);
return value;
}

QScriptValue QIODevice_read(QScriptContext*context,QScriptEngine*engine)
{
QIODevice*self= getself<QIODevice*> (context);
QScriptValue value= engine->toScriptValue<QByteArray> (
self->read(argument<int> (0,context)));
setQByteArrayProperties(value,engine);
return value;
}

/*:91*//*94:*/
#line 2375 "./typica.w"

QScriptValue constructQProcess(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QProcess);
setQProcessProperties(object,engine);
return object;
}

/*:94*//*95:*/
#line 2386 "./typica.w"

void setQProcessProperties(QScriptValue value,QScriptEngine*engine)
{
setQIODeviceProperties(value,engine);
value.setProperty("execute",engine->newFunction(QProcess_execute));
value.setProperty("startDetached",engine->newFunction(QProcess_startDetached));
value.setProperty("setWorkingDirectory",engine->newFunction(QProcess_setWorkingDirectory));
value.setProperty("start",engine->newFunction(QProcess_start));
}

/*:95*//*96:*/
#line 2400 "./typica.w"

QScriptValue QProcess_execute(QScriptContext*context,QScriptEngine*)
{
QProcess*self= getself<QProcess*> (context);
QString program= argument<QString> (0,context);
QStringList arguments= QStringList();
if(context->argumentCount()> 1){
arguments= argument<QVariant> (1,context).toStringList();
}
int retval= self->execute(program,arguments);
return QScriptValue(retval);
}

/*:96*//*97:*/
#line 2415 "./typica.w"

QScriptValue QProcess_startDetached(QScriptContext*context,QScriptEngine*)
{
QProcess*self= getself<QProcess*> (context);
QString program= argument<QString> (0,context);
QStringList arguments= QStringList();
if(context->argumentCount()> 1){
arguments= argument<QVariant> (1,context).toStringList();
}
QString workingDirectory= "";
if(context->argumentCount()> 2){
workingDirectory= argument<QString> (2,context);
}
bool retval;
switch(context->argumentCount())
{
case 1:
retval= self->startDetached(program);
break;
case 2:
retval= self->startDetached(program,arguments);
break;
case 3:
retval= self->startDetached(program,arguments,workingDirectory);
break;
default:
retval= false;
}
return QScriptValue(retval);
}

/*:97*//*98:*/
#line 2448 "./typica.w"

QScriptValue QProcess_setWorkingDirectory(QScriptContext*context,QScriptEngine*)
{
QProcess*self= getself<QProcess*> (context);
QString directory= argument<QString> (0,context);
self->setWorkingDirectory(directory);
return QScriptValue();
}

/*:98*//*99:*/
#line 2460 "./typica.w"

QScriptValue QProcess_start(QScriptContext*context,QScriptEngine*)
{
QProcess*self= getself<QProcess*> (context);
QString program= argument<QString> (0,context);
QStringList arguments= QStringList();
if(context->argumentCount()> 1){
arguments= argument<QVariant> (1,context).toStringList();
}
self->start(program,arguments);
return QScriptValue();
}

/*:99*//*101:*/
#line 2501 "./typica.w"

QScriptValue QByteArray_toScriptValue(QScriptEngine*engine,const QByteArray&bytes)
{
QScriptValue object= engine->newVariant(QVariant(bytes));
setQByteArrayProperties(object,engine);
return object;
}

void QByteArray_fromScriptValue(const QScriptValue&value,QByteArray&bytes)
{
bytes= value.toVariant().toByteArray();
}

/*:101*//*103:*/
#line 2524 "./typica.w"

QScriptValue constructQByteArray(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->toScriptValue<QByteArray> (QByteArray());
setQByteArrayProperties(object,engine);
return object;
}

/*:103*//*104:*/
#line 2535 "./typica.w"

void setQByteArrayProperties(QScriptValue value,QScriptEngine*engine)
{
value.setProperty("fromHex",engine->newFunction(QByteArray_fromHex));
value.setProperty("getAt",engine->newFunction(QByteArray_getAt));
value.setProperty("setAt",engine->newFunction(QByteArray_setAt));
value.setProperty("appendBytes",engine->newFunction(QByteArray_appendBytes));
value.setProperty("appendString",engine->newFunction(QByteArray_appendString));
value.setProperty("size",engine->newFunction(QByteArray_size));
value.setProperty("left",engine->newFunction(QByteArray_left));
value.setProperty("right",engine->newFunction(QByteArray_right));
value.setProperty("mid",engine->newFunction(QByteArray_mid));
value.setProperty("chop",engine->newFunction(QByteArray_chop));
value.setProperty("remove",engine->newFunction(QByteArray_remove));
value.setProperty("toInt8",engine->newFunction(QByteArray_toInt8));
value.setProperty("toInt16",engine->newFunction(QByteArray_toInt16));
value.setProperty("toInt32",engine->newFunction(QByteArray_toInt32));
value.setProperty("toFloat",engine->newFunction(QByteArray_toFloat));
value.setProperty("toDouble",engine->newFunction(QByteArray_toDouble));
}

/*:104*//*105:*/
#line 2559 "./typica.w"

QScriptValue QByteArray_fromHex(QScriptContext*context,QScriptEngine*engine)
{
QByteArray self= getself<QByteArray> (context);
QByteArray retval;
retval= self.fromHex(argument<QString> (0,context).toUtf8());
QScriptValue value= engine->toScriptValue<QByteArray> (retval);
setQByteArrayProperties(value,engine);
return value;
}

/*:105*//*106:*/
#line 2573 "./typica.w"

QScriptValue QByteArray_getAt(QScriptContext*context,QScriptEngine*)
{
QByteArray self= getself<QByteArray> (context);
return QScriptValue((int)(self.at(argument<int> (0,context))));
}

QScriptValue QByteArray_setAt(QScriptContext*context,QScriptEngine*)
{
QByteArray self= getself<QByteArray> (context);
self[argument<int> (0,context)]= (char)(argument<int> (1,context));
return QScriptValue();
}

/*:106*//*107:*/
#line 2591 "./typica.w"

QScriptValue QByteArray_appendBytes(QScriptContext*context,QScriptEngine*engine)
{
QByteArray self= getself<QByteArray> (context);
QScriptValue value= 
engine->toScriptValue<QByteArray> (
self.append(argument<QByteArray> (0,context)));
setQByteArrayProperties(value,engine);
return value;
}

QScriptValue QByteArray_appendString(QScriptContext*context,QScriptEngine*engine)
{
QByteArray self= getself<QByteArray> (context);
QScriptValue value= engine->toScriptValue<QByteArray> (
self.append(argument<QString> (0,context)));
setQByteArrayProperties(value,engine);
return value;
}

/*:107*//*108:*/
#line 2613 "./typica.w"

QScriptValue QByteArray_size(QScriptContext*context,QScriptEngine*)
{
QByteArray self= getself<QByteArray> (context);
return QScriptValue(self.size());
}

/*:108*//*109:*/
#line 2623 "./typica.w"

QScriptValue QByteArray_left(QScriptContext*context,QScriptEngine*engine)
{
QByteArray self= getself<QByteArray> (context);
QScriptValue value= engine->toScriptValue<QByteArray> (
self.left(argument<int> (0,context)));
setQByteArrayProperties(value,engine);
return value;
}

QScriptValue QByteArray_right(QScriptContext*context,QScriptEngine*engine)
{
QByteArray self= getself<QByteArray> (context);
QScriptValue value= engine->toScriptValue<QByteArray> (
self.right(argument<int> (0,context)));
setQByteArrayProperties(value,engine);
return value;
}

QScriptValue QByteArray_mid(QScriptContext*context,QScriptEngine*engine)
{
QByteArray self= getself<QByteArray> (context);
int length= -1;
if(context->argumentCount()> 1)
{
length= argument<int> (1,context);
}
QScriptValue value= engine->toScriptValue<QByteArray> (
self.mid(argument<int> (0,context),length));
setQByteArrayProperties(value,engine);
return value;
}

/*:109*//*110:*/
#line 2658 "./typica.w"

QScriptValue QByteArray_chop(QScriptContext*context,QScriptEngine*)
{
QByteArray self= getself<QByteArray> (context);
self.chop(argument<int> (0,context));
return QScriptValue();
}

QScriptValue QByteArray_remove(QScriptContext*context,QScriptEngine*engine)
{
QByteArray self= getself<QByteArray> (context);
QScriptValue value= engine->toScriptValue<QByteArray> (
self.remove(argument<int> (0,context),argument<int> (1,context)));
setQByteArrayProperties(value,engine);
return value;
}

/*:110*//*111:*/
#line 2681 "./typica.w"

QScriptValue QByteArray_toInt8(QScriptContext*context,QScriptEngine*)
{
QByteArray self= getself<QByteArray> (context);
int value= 0;
char*bytes= (char*)&value;
bytes[0]= self[0];
return QScriptValue(value);
}

QScriptValue QByteArray_toInt16(QScriptContext*context,QScriptEngine*)
{
QByteArray self= getself<QByteArray> (context);
int value= 0;
char*bytes= (char*)&value;
bytes[0]= self[0];
bytes[1]= self[1];
return QScriptValue(value);
}

QScriptValue QByteArray_toInt32(QScriptContext*context,QScriptEngine*)
{
QByteArray self= getself<QByteArray> (context);
int value= 0;
char*bytes= (char*)&value;
bytes[0]= self[0];
bytes[1]= self[1];
bytes[2]= self[2];
bytes[3]= self[3];
return QScriptValue(value);
}

/*:111*//*112:*/
#line 2717 "./typica.w"

QScriptValue QByteArray_toFloat(QScriptContext*context,QScriptEngine*)
{
QByteArray self= getself<QByteArray> (context);
float value= 0.0;
char*bytes= (char*)&value;
bytes[0]= self[0];
bytes[1]= self[1];
bytes[2]= self[2];
bytes[3]= self[3];
return QScriptValue(value);
}

QScriptValue QByteArray_toDouble(QScriptContext*context,QScriptEngine*)
{
QByteArray self= getself<QByteArray> (context);
double value= 0.0;
char*bytes= (char*)&value;
bytes[0]= self[0];
bytes[1]= self[1];
bytes[2]= self[2];
bytes[3]= self[3];
bytes[4]= self[4];
bytes[5]= self[5];
bytes[6]= self[6];
bytes[7]= self[7];
return QScriptValue(value);
}

/*:112*//*115:*/
#line 2772 "./typica.w"

QScriptValue bytesFromInt8(QScriptContext*context,QScriptEngine*engine)
{
qint8 value= (qint8)(argument<int> (0,context));
char*bytes= (char*)&value;
QByteArray retval;
retval.resize(1);
retval[0]= bytes[0];
QScriptValue v= engine->toScriptValue<QByteArray> (retval);
setQByteArrayProperties(v,engine);
return v;
}

QScriptValue bytesFromInt16(QScriptContext*context,QScriptEngine*engine)
{
qint16 value= (qint16)(argument<int> (0,context));
char*bytes= (char*)&value;
QByteArray retval;
retval.resize(2);
retval[0]= bytes[0];
retval[1]= bytes[1];
QScriptValue v= engine->toScriptValue<QByteArray> (retval);
setQByteArrayProperties(v,engine);
return v;
}

QScriptValue bytesFromInt32(QScriptContext*context,QScriptEngine*engine)
{
qint32 value= (qint32)(argument<int> (0,context));
char*bytes= (char*)&value;
QByteArray retval;
retval.resize(4);
retval[0]= bytes[0];
retval[1]= bytes[1];
retval[2]= bytes[2];
retval[3]= bytes[3];
QScriptValue v= engine->toScriptValue<QByteArray> (retval);
setQByteArrayProperties(v,engine);
return v;
}

QScriptValue bytesFromFloat(QScriptContext*context,QScriptEngine*engine)
{
float value= (float)(argument<double> (0,context));
char*bytes= (char*)&value;
QByteArray retval;
retval.resize(4);
retval[0]= bytes[0];
retval[1]= bytes[1];
retval[2]= bytes[2];
retval[3]= bytes[3];
QScriptValue v= engine->toScriptValue<QByteArray> (retval);
setQByteArrayProperties(v,engine);
return v;
}

QScriptValue bytesFromDouble(QScriptContext*context,QScriptEngine*engine)
{
double value= (double)(argument<double> (0,context));
char*bytes= (char*)&value;
QByteArray retval;
retval.resize(8);
retval[0]= bytes[0];
retval[1]= bytes[1];
retval[2]= bytes[2];
retval[3]= bytes[3];
retval[4]= bytes[4];
retval[5]= bytes[5];
retval[6]= bytes[6];
retval[7]= bytes[7];
QScriptValue v= engine->toScriptValue<QByteArray> (retval);
setQByteArrayProperties(v,engine);
return v;
}

/*:115*//*118:*/
#line 2870 "./typica.w"

QScriptValue constructQBuffer(QScriptContext*context,QScriptEngine*engine)
{
QByteArray*array= new QByteArray(argument<QString> (0,context).toAscii());
QScriptValue object= engine->newQObject(new QBuffer(array));
setQBufferProperties(object,engine);
return object;
}

void setQBufferProperties(QScriptValue value,QScriptEngine*engine)
{
setQIODeviceProperties(value,engine);
value.setProperty("setData",engine->newFunction(QBuffer_setData));
value.setProperty("data",engine->newFunction(QBuffer_data));
}

QScriptValue QBuffer_setData(QScriptContext*context,QScriptEngine*)
{
QBuffer*self= getself<QBuffer*> (context);
self->setData(argument<QString> (0,context).toAscii());
return QScriptValue();
}

QScriptValue QBuffer_data(QScriptContext*context,QScriptEngine*)
{
QBuffer*self= getself<QBuffer*> (context);
return QScriptValue(QString(self->data()));
}

/*:118*//*121:*/
#line 2926 "./typica.w"

QScriptValue constructXQuery(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->toScriptValue<void*> (new QXmlQuery);
setXQueryProperties(object,engine);
return object;
}

QScriptValue XQuery_invalidate(QScriptContext*context,QScriptEngine*)
{
QXmlQuery*self= getself<QXmlQuery*> (context);
delete self;
return QScriptValue();
}

void setXQueryProperties(QScriptValue value,QScriptEngine*engine)
{
value.setProperty("bind",engine->newFunction(XQuery_bind));
value.setProperty("exec",engine->newFunction(XQuery_exec));
value.setProperty("setQuery",engine->newFunction(XQuery_setQuery));
value.setProperty("invalidate",engine->newFunction(XQuery_invalidate));
}

/*:121*//*122:*/
#line 2952 "./typica.w"

QScriptValue XQuery_bind(QScriptContext*context,QScriptEngine*)
{
QXmlQuery*self= getself<QXmlQuery*> (context);
QIODevice*buffer= argument<QIODevice*> (1,context);
self->bindVariable(argument<QString> (0,context),buffer);
return QScriptValue();
}

/*:122*//*123:*/
#line 2963 "./typica.w"

QScriptValue XQuery_setQuery(QScriptContext*context,QScriptEngine*)
{
QXmlQuery*self= getself<QXmlQuery*> (context);
self->setQuery(argument<QString> (0,context));
return QScriptValue();
}

/*:123*//*124:*/
#line 2973 "./typica.w"

QScriptValue XQuery_exec(QScriptContext*context,QScriptEngine*)
{
QXmlQuery*self= getself<QXmlQuery*> (context);
QString result;
self->evaluateTo(&result);
return QScriptValue(result);
}

/*:124*//*127:*/
#line 3028 "./typica.w"

QScriptValue constructXmlWriter(QScriptContext*context,QScriptEngine*engine)
{
QXmlStreamWriter*retval;
if(context->argumentCount()==1)
{
retval= new QXmlStreamWriter(argument<QIODevice*> (0,context));
}
else
{
retval= new QXmlStreamWriter;
}
QScriptValue object= engine->toScriptValue<void*> (retval);
setXmlWriterProperties(object,engine);
return object;
}

void setXmlWriterProperties(QScriptValue value,QScriptEngine*engine)
{
value.setProperty("setDevice",engine->newFunction(XmlWriter_setDevice));
value.setProperty("writeAttribute",
engine->newFunction(XmlWriter_writeAttribute));
value.setProperty("writeCDATA",engine->newFunction(XmlWriter_writeCDATA));
value.setProperty("writeCharacters",
engine->newFunction(XmlWriter_writeCharacters));
value.setProperty("writeDTD",engine->newFunction(XmlWriter_writeDTD));
value.setProperty("writeEmptyElement",
engine->newFunction(XmlWriter_writeEmptyElement));
value.setProperty("writeEndDocument",
engine->newFunction(XmlWriter_writeEndDocument));
value.setProperty("writeEndElement",
engine->newFunction(XmlWriter_writeEndElement));
value.setProperty("writeEntityReference",
engine->newFunction(XmlWriter_writeEntityReference));
value.setProperty("writeProcessingInstruction",
engine->newFunction(XmlWriter_writeProcessingInstruction));
value.setProperty("writeStartDocument",
engine->newFunction(XmlWriter_writeStartDocument));
value.setProperty("writeStartElement",
engine->newFunction(XmlWriter_writeStartElement));
value.setProperty("writeTextElement",
engine->newFunction(XmlWriter_writeTextElement));
}

/*:127*//*128:*/
#line 3075 "./typica.w"

QScriptValue XmlWriter_setDevice(QScriptContext*context,QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
QIODevice*device= argument<QIODevice*> (0,context);
self->setDevice(device);
return QScriptValue();
}

/*:128*//*129:*/
#line 3089 "./typica.w"

QScriptValue XmlWriter_writeStartDocument(QScriptContext*context,
QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeStartDocument(argument<QString> (0,context));
return QScriptValue();
}

QScriptValue XmlWriter_writeEndDocument(QScriptContext*context,
QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeEndDocument();
return QScriptValue();
}

/*:129*//*130:*/
#line 3108 "./typica.w"

QScriptValue XmlWriter_writeDTD(QScriptContext*context,QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeDTD(argument<QString> (0,context));
return QScriptValue();
}

/*:130*//*131:*/
#line 3119 "./typica.w"

QScriptValue XmlWriter_writeStartElement(QScriptContext*context,
QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeStartElement(argument<QString> (0,context));
return QScriptValue();
}

QScriptValue XmlWriter_writeAttribute(QScriptContext*context,QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeAttribute(argument<QString> (0,context),
argument<QString> (1,context));
return QScriptValue();
}

QScriptValue XmlWriter_writeCharacters(QScriptContext*context,QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeCharacters(argument<QString> (0,context));
return QScriptValue();
}

QScriptValue XmlWriter_writeEndElement(QScriptContext*context,QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeEndElement();
return QScriptValue();
}

/*:131*//*132:*/
#line 3155 "./typica.w"

QScriptValue XmlWriter_writeEmptyElement(QScriptContext*context,
QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeEmptyElement(argument<QString> (0,context));
return QScriptValue();
}

QScriptValue XmlWriter_writeTextElement(QScriptContext*context,
QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeTextElement(argument<QString> (0,context),
argument<QString> (1,context));
return QScriptValue();
}

/*:132*//*133:*/
#line 3176 "./typica.w"

QScriptValue XmlWriter_writeCDATA(QScriptContext*context,QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeCDATA(argument<QString> (0,context));
return QScriptValue();
}

QScriptValue XmlWriter_writeEntityReference(QScriptContext*context,
QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeEntityReference(argument<QString> (0,context));
return QScriptValue();
}

QScriptValue XmlWriter_writeProcessingInstruction(QScriptContext*context,
QScriptEngine*)
{
QXmlStreamWriter*self= getself<QXmlStreamWriter*> (context);
self->writeProcessingInstruction(argument<QString> (0,context),
argument<QString> (1,context));
return QScriptValue();
}

/*:133*//*136:*/
#line 3235 "./typica.w"

QScriptValue constructXmlReader(QScriptContext*context,QScriptEngine*engine)
{
QXmlStreamReader*retval= 
new QXmlStreamReader(argument<QIODevice*> (0,context));
QScriptValue object= engine->toScriptValue<void*> (retval);
setXmlReaderProperties(object,engine);
return object;
}

void setXmlReaderProperties(QScriptValue value,QScriptEngine*engine)
{
value.setProperty("atEnd",engine->newFunction(XmlReader_atEnd));
value.setProperty("attribute",engine->newFunction(XmlReader_attribute));
value.setProperty("hasAttribute",
engine->newFunction(XmlReader_hasAttribute));
value.setProperty("isDTD",engine->newFunction(XmlReader_isDTD));
value.setProperty("isStartElement",
engine->newFunction(XmlReader_isStartElement));
value.setProperty("name",engine->newFunction(XmlReader_name));
value.setProperty("readElementText",
engine->newFunction(XmlReader_readElementText));
value.setProperty("readNext",
engine->newFunction(XmlReader_readNext));
value.setProperty("text",engine->newFunction(XmlReader_text));
}

/*:136*//*137:*/
#line 3265 "./typica.w"

QScriptValue XmlReader_attribute(QScriptContext*context,QScriptEngine*)
{
QXmlStreamReader*self= getself<QXmlStreamReader*> (context);
QString retval= 
self->attributes().value(argument<QString> (0,context)).toString();
return QScriptValue(retval);
}

QScriptValue XmlReader_hasAttribute(QScriptContext*context,QScriptEngine*)
{
QXmlStreamReader*self= getself<QXmlStreamReader*> (context);
bool retval= 
self->attributes().hasAttribute(argument<QString> (0,context));
return QScriptValue(retval);
}

/*:137*//*138:*/
#line 3285 "./typica.w"

QScriptValue XmlReader_atEnd(QScriptContext*context,QScriptEngine*)
{
QXmlStreamReader*self= getself<QXmlStreamReader*> (context);
return QScriptValue(self->atEnd());
}

QScriptValue XmlReader_isDTD(QScriptContext*context,QScriptEngine*)
{
QXmlStreamReader*self= getself<QXmlStreamReader*> (context);
return QScriptValue(self->isDTD());
}

QScriptValue XmlReader_isStartElement(QScriptContext*context,QScriptEngine*)
{
QXmlStreamReader*self= getself<QXmlStreamReader*> (context);
return QScriptValue(self->isStartElement());
}

/*:138*//*139:*/
#line 3306 "./typica.w"

QScriptValue XmlReader_readNext(QScriptContext*context,QScriptEngine*)
{
QXmlStreamReader*self= getself<QXmlStreamReader*> (context);
self->readNext();
return QScriptValue();
}

/*:139*//*140:*/
#line 3316 "./typica.w"

QScriptValue XmlReader_name(QScriptContext*context,QScriptEngine*)
{
QXmlStreamReader*self= getself<QXmlStreamReader*> (context);
return QScriptValue(self->name().toString());
}

QScriptValue XmlReader_readElementText(QScriptContext*context,QScriptEngine*)
{
QXmlStreamReader*self= getself<QXmlStreamReader*> (context);
return QScriptValue(self->readElementText());
}

QScriptValue XmlReader_text(QScriptContext*context,QScriptEngine*)
{
QXmlStreamReader*self= getself<QXmlStreamReader*> (context);
return QScriptValue(self->text().toString());
}

/*:140*//*143:*/
#line 3358 "./typica.w"

void setQSettingsProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
value.setProperty("value",engine->newFunction(QSettings_value));
value.setProperty("setValue",engine->newFunction(QSettings_setValue));
}

/*:143*//*144:*/
#line 3370 "./typica.w"

QScriptValue QSettings_value(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==1||context->argumentCount()==2)
{
QSettings settings;
QString key= argument<QString> (0,context);
QVariant value;
QVariant retval;
if(context->argumentCount()> 1)
{
value= argument<QVariant> (1,context);
retval= settings.value(key,value);
}
else
{
retval= settings.value(key);
}
object= engine->newVariant(retval);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QSettings::value(). This method takes one "
"string and one optional variant type.");
}
return object;
}

QScriptValue QSettings_setValue(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==2)
{
QSettings settings;
QString key= argument<QString> (0,context);
QVariant value= argument<QVariant> (1,context);
settings.setValue(key,value);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QSettings::setValue(). This method takes one "
"string and one variant type for a total of two "
"arguments.");
}
return QScriptValue();
}

/*:144*//*147:*/
#line 3439 "./typica.w"

QScriptValue constructQLCDNumber(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QLCDNumber());
setQLCDNumberProperties(object,engine);
return object;
}

void setQLCDNumberProperties(QScriptValue value,QScriptEngine*engine)
{
setQFrameProperties(value,engine);
}

/*:147*//*150:*/
#line 3497 "./typica.w"

QScriptValue constructQTime(QScriptContext*context,
QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==0||
(context->argumentCount()>=2&&context->argumentCount()<=4))
{
int arg1= 0;
int arg2= 0;
int arg3= 0;
int arg4= 0;
switch(context->argumentCount())
{
case 4:
arg4= argument<int> (3,context);
case 3:
arg3= argument<int> (2,context);
case 2:
arg2= argument<int> (1,context);
arg1= argument<int> (0,context);
default:
break;
}
if(context->argumentCount())
{
object= engine->toScriptValue<QTime> (QTime(arg1,arg2,arg3,
arg4));
}
else
{
object= engine->toScriptValue<QTime> (QTime());
}
setQTimeProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::QTime(). This method takes zero, two, "
"three, or four integer arguments.");
}
return object;
}

/*:150*//*151:*/
#line 3545 "./typica.w"

void setQTimeProperties(QScriptValue value,QScriptEngine*engine)
{
value.setProperty("addMSecs",engine->newFunction(QTime_addMSecs));
value.setProperty("addSecs",engine->newFunction(QTime_addSecs));
value.setProperty("elapsed",engine->newFunction(QTime_elapsed));
value.setProperty("hour",engine->newFunction(QTime_hour));
value.setProperty("isNull",engine->newFunction(QTime_isNull));
value.setProperty("isValid",engine->newFunction(QTime_isValid));
value.setProperty("minute",engine->newFunction(QTime_minute));
value.setProperty("msec",engine->newFunction(QTime_msec));
value.setProperty("msecsTo",engine->newFunction(QTime_msecsTo));
value.setProperty("restart",engine->newFunction(QTime_restart));
value.setProperty("second",engine->newFunction(QTime_second));
value.setProperty("secsTo",engine->newFunction(QTime_secsTo));
value.setProperty("setHMS",engine->newFunction(QTime_setHMS));
value.setProperty("start",engine->newFunction(QTime_start));
value.setProperty("toString",engine->newFunction(QTime_toString));
value.setProperty("currentTime",engine->newFunction(QTime_currentTime));
value.setProperty("fromString",engine->newFunction(QTime_fromString));
value.setProperty("valueOf",engine->newFunction(QTime_valueOf));
}

/*:151*//*152:*/
#line 3574 "./typica.w"

QScriptValue QTime_valueOf(QScriptContext*context,QScriptEngine*)
{
QTime self= getself<QTime> (context);
int retval= (self.hour()*60*60*1000)+(self.minute()*60*1000)+
(self.second()*1000)+self.msec();
return QScriptValue(retval);
}

/*:152*//*153:*/
#line 3588 "./typica.w"

QScriptValue QTime_addMSecs(QScriptContext*context,QScriptEngine*engine)
{
QTime time;
QScriptValue retval;
if(context->argumentCount()==1)
{
QTime self= getself<QTime> (context);
time= self.addMSecs(argument<int> (0,context));
retval= engine->toScriptValue<QTime> (time);
setQTimeProperties(retval,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::addMSecs(). This method takes one "
"integer as an argument.");
}
return retval;
}

QScriptValue QTime_addSecs(QScriptContext*context,QScriptEngine*engine)
{
QTime time;
QScriptValue retval;
if(context->argumentCount()==1)
{
QTime self= getself<QTime> (context);
time= self.addSecs(argument<int> (0,context));
retval= engine->toScriptValue<QTime> (time);
setQTimeProperties(retval,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::addSecs(). This method takes one "
"integer as an argument.");
}
return retval;
}

/*:153*//*154:*/
#line 3631 "./typica.w"

QScriptValue QTime_elapsed(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==0)
{
QTime self= getself<QTime> (context);
retval= QScriptValue(engine,self.elapsed());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::elapsed(). This method takes no "
"arguments.");
}
return retval;
}

/*:154*//*155:*/
#line 3652 "./typica.w"

QScriptValue QTime_hour(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==0)
{
QTime self= getself<QTime> (context);
retval= QScriptValue(engine,self.hour());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::hour(). This method takes no "
"arguments.");
}
return retval;
}

/*:155*//*156:*/
#line 3672 "./typica.w"

QScriptValue QTime_minute(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==0)
{
QTime self= getself<QTime> (context);
retval= QScriptValue(engine,self.minute());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::minute(). This method takes no "
"arguments.");
}
return retval;
}

QScriptValue QTime_second(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==0)
{
QTime self= getself<QTime> (context);
retval= QScriptValue(engine,self.second());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::second(). This method takes no "
"arguments.");
}
return retval;
}

QScriptValue QTime_msec(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==0)
{
QTime self= getself<QTime> (context);
retval= QScriptValue(engine,self.msec());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::msec(). This method takes no "
"arguments.");
}
return retval;
}

/*:156*//*157:*/
#line 3728 "./typica.w"

QScriptValue QTime_isNull(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==0)
{
QTime self= getself<QTime> (context);
retval= QScriptValue(engine,self.isNull());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::isNull(). This method takes no "
"arguments.");
}
return retval;
}

QScriptValue QTime_isValid(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==0)
{
QTime self= getself<QTime> (context);
retval= QScriptValue(engine,self.isValid());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::isValid(). This method takes no "
"arguments.");
}
return retval;
}

/*:157*//*158:*/
#line 3766 "./typica.w"

QScriptValue QTime_msecsTo(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==1)
{
QTime self= getself<QTime> (context);
QTime arg= argument<QVariant> (0,context).toTime();
retval= QScriptValue(engine,self.msecsTo(arg));
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::msecsTo(). This method takes one QTime.");
}
return retval;
}

QScriptValue QTime_secsTo(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==1)
{
QTime self= getself<QTime> (context);
QTime arg= argument<QVariant> (0,context).toTime();
retval= QScriptValue(engine,self.secsTo(arg));
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::secsTo(). This method takes one QTime.");
}
return retval;
}

/*:158*//*159:*/
#line 3805 "./typica.w"

QScriptValue QTime_restart(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==0)
{
QTime self= getself<QTime> (context);
retval= QScriptValue(engine,self.restart());
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::restart(). This method takes no "
"arguments.");
}
return retval;
}

QScriptValue QTime_start(QScriptContext*context,QScriptEngine*)
{
if(context->argumentCount()==0)
{
QTime self= getself<QTime> (context);
self.start();
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::start(). This method takes no arguments.");
}
return QScriptValue();
}

/*:159*//*160:*/
#line 3841 "./typica.w"

QScriptValue QTime_setHMS(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==3||context->argumentCount()==4)
{
QTime self= getself<QTime> (context);
int arg1= 0;
int arg2= 0;
int arg3= 0;
int arg4= 0;
switch(context->argumentCount())
{
case 4:
arg4= argument<int> (3,context);
case 3:
arg3= argument<int> (2,context);
arg2= argument<int> (1,context);
arg1= argument<int> (0,context);
default:
break;
}
retval= QScriptValue(engine,self.setHMS(arg1,arg2,arg3,arg4));
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::setHMS(). This method takes three or "
"four integer arguments.");
}
return retval;
}

/*:160*//*161:*/
#line 3877 "./typica.w"

QScriptValue QTime_toString(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue retval;
if(context->argumentCount()==1)
{
QTime self= getself<QTime> (context);
retval= QScriptValue(engine,self.toString(argument<QString> (0,context)));
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::toString(). This method takes one QString "
"as an argument.");
}
return retval;
}

/*:161*//*162:*/
#line 3898 "./typica.w"

QScriptValue QTime_currentTime(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object;
object= engine->toScriptValue<QTime> (QTime::currentTime());
setQTimeProperties(object,engine);
return object;
}

QScriptValue QTime_fromString(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==2)
{
QString time= argument<QString> (0,context);
QString format= argument<QString> (1,context);
object= engine->toScriptValue<QTime> (QTime::fromString(time,format));
setQTimeProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTime::fromString(). This method takes two "
"string arguments.");
}
return object;
}

/*:162*//*163:*/
#line 3929 "./typica.w"

template<> QTime argument(int arg,QScriptContext*context)
{
return qscriptvalue_cast<QTime> (context->argument(arg));
}

/*:163*//*166:*/
#line 3952 "./typica.w"

QScriptValue constructQColor(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object= engine->toScriptValue<QColor> (QColor(argument<QString> (0,context)));
return object;
}

/*:166*//*169:*/
#line 3975 "./typica.w"

QScriptValue constructQBrush(QScriptContext*context,QScriptEngine*engine)
{
QBrush theBrush= QBrush(QColor(argument<QString> (0,context)));
QScriptValue object= engine->toScriptValue(theBrush);
return object;
}

/*:169*//*171:*/
#line 3995 "./typica.w"

void setQAbstractScrollAreaProperties(QScriptValue value,QScriptEngine*engine)
{
setQFrameProperties(value,engine);
}

/*:171*//*173:*/
#line 4009 "./typica.w"

void setQAbstractItemViewProperties(QScriptValue value,QScriptEngine*engine)
{
setQAbstractScrollAreaProperties(value,engine);
}

/*:173*//*175:*/
#line 4023 "./typica.w"

void setQGraphicsViewProperties(QScriptValue value,QScriptEngine*engine)
{
setQAbstractScrollAreaProperties(value,engine);
}

void setQTableViewProperties(QScriptValue value,QScriptEngine*engine)
{
setQAbstractItemViewProperties(value,engine);
}

/*:175*//*178:*/
#line 4056 "./typica.w"

QScriptValue constructQPushButton(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QPushButton());
setQPushButtonProperties(object,engine);
return object;
}

void setQPushButtonProperties(QScriptValue value,QScriptEngine*engine)
{
setQAbstractButtonProperties(value,engine);
}

void setQAbstractButtonProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
}

/*:178*//*185:*/
#line 4168 "./typica.w"

QScriptValue constructQSqlQuery(QScriptContext*,QScriptEngine*engine)
{
SqlQueryConnection*obj= new SqlQueryConnection();
QScriptValue object= 
engine->toScriptValue<void*> (obj);
setQSqlQueryProperties(object,engine);
return object;
}

/*:185*//*186:*/
#line 4181 "./typica.w"

void setQSqlQueryProperties(QScriptValue value,QScriptEngine*engine)
{
value.setProperty("bind",engine->newFunction(QSqlQuery_bind));
value.setProperty("bindFileData",
engine->newFunction(QSqlQuery_bindFileData));
value.setProperty("bindDeviceData",
engine->newFunction(QSqlQuery_bindDeviceData));
value.setProperty("exec",engine->newFunction(QSqlQuery_exec));
value.setProperty("executedQuery",engine->newFunction(QSqlQuery_executedQuery));
value.setProperty("invalidate",engine->newFunction(QSqlQuery_invalidate));
value.setProperty("next",engine->newFunction(QSqlQuery_next));
value.setProperty("prepare",engine->newFunction(QSqlQuery_prepare));
value.setProperty("value",engine->newFunction(QSqlQuery_value));
}

/*:186*//*187:*/
#line 4199 "./typica.w"

QScriptValue QSqlQuery_exec(QScriptContext*context,QScriptEngine*engine)
{
QSqlQuery*q= getself<SqlQueryConnection*> (context)->operator->();
QScriptValue retval;
if(context->argumentCount()==1)
{
retval= QScriptValue(engine,
q->exec(argument<QString> (0,context)));
}
else
{
retval= QScriptValue(engine,q->exec());
}
if(q->lastError().isValid())
{
qDebug()<<q->lastQuery();
qDebug()<<q->lastError().text();
}
return retval;
}

QScriptValue QSqlQuery_executedQuery(QScriptContext*context,QScriptEngine*)
{
QSqlQuery*query= getself<SqlQueryConnection*> (context)->operator->();
return QScriptValue(query->lastQuery());
}

QScriptValue QSqlQuery_next(QScriptContext*context,QScriptEngine*engine)
{
QSqlQuery*query= getself<SqlQueryConnection*> (context)->operator->();
return QScriptValue(engine,query->next());
}

QScriptValue QSqlQuery_value(QScriptContext*context,QScriptEngine*engine)
{
QSqlQuery*query= getself<SqlQueryConnection*> (context)->operator->();
return QScriptValue(engine,
query->value(argument<int> (0,context)).toString());
}

/*:187*//*188:*/
#line 4243 "./typica.w"

QScriptValue QSqlQuery_prepare(QScriptContext*context,QScriptEngine*engine)
{
QSqlQuery*query= getself<SqlQueryConnection*> (context)->operator->();
return QScriptValue(engine,query->prepare(argument<QString> (0,context)));
}

QScriptValue QSqlQuery_bind(QScriptContext*context,QScriptEngine*)
{
QSqlQuery*query= getself<SqlQueryConnection*> (context)->operator->();
query->bindValue(argument<QString> (0,context),
argument<QVariant> (1,context));
return QScriptValue();
}

QScriptValue QSqlQuery_bindFileData(QScriptContext*context,
QScriptEngine*)
{
QSqlQuery*query= getself<SqlQueryConnection*> (context)->operator->();
QString placeholder= argument<QString> (0,context);
QString filename= argument<QString> (1,context);
QFile file(filename);
QByteArray data;
if(file.open(QIODevice::ReadOnly))
{
data= file.readAll();
file.close();
}
query->bindValue(placeholder,data);
return QScriptValue();
}

QScriptValue QSqlQuery_bindDeviceData(QScriptContext*context,
QScriptEngine*)
{
QSqlQuery*query= getself<SqlQueryConnection*> (context)->operator->();
QString placeholder= argument<QString> (0,context);
QIODevice*device= argument<QIODevice*> (1,context);
device->reset();
QByteArray data;
data= device->readAll();
query->bindValue(placeholder,data);
return QScriptValue();
}

/*:188*//*189:*/
#line 4295 "./typica.w"

QScriptValue QSqlQuery_invalidate(QScriptContext*context,QScriptEngine*)
{
SqlQueryConnection*query= getself<SqlQueryConnection*> (context);
delete query;
return QScriptValue::UndefinedValue;
}

/*:189*//*192:*/
#line 4342 "./typica.w"

QScriptValue baseName(QScriptContext*context,QScriptEngine*engine)
{
QFileInfo info(argument<QString> (0,context));
QScriptValue retval(engine,info.baseName());
return retval;
}

QScriptValue dir(QScriptContext*context,QScriptEngine*engine)
{
QFileInfo info(argument<QString> (0,context));
QDir dir= info.dir();
QScriptValue retval(engine,dir.path());
return retval;
}

/*:192*//*193:*/
#line 4361 "./typica.w"

QScriptValue saveFileFromDatabase(QScriptContext*context,QScriptEngine*)
{
SqlQueryConnection h;
QSqlQuery*query= h.operator->();
QString q= "SELECT file FROM files WHERE id = :file";
query->prepare(q);
query->bindValue(":file",argument<int> (0,context));
query->exec();
query->next();
QByteArray array= query->value(0).toByteArray();
QFile file(argument<QString> (1,context));
file.open(QIODevice::WriteOnly);
file.write(array);
file.close();
return QScriptValue();
}

/*:193*//*194:*/
#line 4382 "./typica.w"

QScriptValue sqlToArray(QScriptContext*context,QScriptEngine*engine)
{
QString source= argument<QString> (0,context);
source.remove(0,1);
source.chop(1);
QStringList elements= source.split(",");
QString element;
QScriptValue dest= engine->newArray(elements.size());
int i= 0;
foreach(element,elements)
{
if(element.startsWith("\"")&&element.endsWith("\""))
{
element.chop(1);
element= element.remove(0,1);
}
dest.setProperty(i,QScriptValue(engine,element));
i++;
}
return dest;
}

/*:194*//*195:*/
#line 4408 "./typica.w"

QScriptValue setFont(QScriptContext*context,QScriptEngine*)
{
QString font= argument<QString> (0,context);
QString classname;
if(context->argumentCount()> 1)
{
classname= argument<QString> (1,context);
QApplication::setFont(QFont(font),classname.toLatin1().constData());
}
else
{
QApplication::setFont(QFont(font));
}
return QScriptValue();
}

/*:195*//*196:*/
#line 4428 "./typica.w"

QScriptValue annotationFromRecord(QScriptContext*context,QScriptEngine*)
{
SqlQueryConnection h;
QSqlQuery*query= h.operator->();
QString q= "SELECT file FROM files WHERE id = :file";
query->prepare(q);
query->bindValue(":file",argument<int> (0,context));
query->exec();
query->next();
QByteArray array= query->value(0).toByteArray();
QBuffer buffer(&array);
buffer.open(QIODevice::ReadOnly);
QXmlQuery xquery;
xquery.bindVariable("profile",&buffer);
QString xq;
xq= "for $b in doc($profile) //tuple where exists($b/annotation) return $b";
xquery.setQuery(xq);
QString result;
xquery.evaluateTo(&result);
return QScriptValue(result);
}

/*:196*//*197:*/
#line 4455 "./typica.w"

QScriptValue setTabOrder(QScriptContext*context,QScriptEngine*)
{
QWidget::setTabOrder(argument<QWidget*> (0,context),
argument<QWidget*> (1,context));
return QScriptValue();
}

/*:197*//*198:*/
#line 4466 "./typica.w"

QScriptValue scriptTr(QScriptContext*context,QScriptEngine*)
{
return QScriptValue(QCoreApplication::translate(
"configuration",
argument<QString> (1,context).toUtf8().data()));
}

/*:198*//*205:*/
#line 4735 "./typica.w"

QScriptValue createWindow(QScriptContext*context,QScriptEngine*engine)
{
QString targetID= argument<QString> (0,context);
QDomNode element;
QScriptValue object;
/*207:*/
#line 4782 "./typica.w"

QDomNodeList windows= 
AppInstance->configuration()->documentElement().elementsByTagName("window");
QDomNode nullNode;
int i= 0;
element= nullNode;
while(i<windows.count())
{
element= windows.at(i);
QDomNamedNodeMap attributes= element.attributes();
if(attributes.contains("id"))
{
if(attributes.namedItem("id").toAttr().value()==targetID)
{
break;
}
}
element= nullNode;
i++;
}

/*:207*/
#line 4741 "./typica.w"

if(!element.isNull())
{
/*208:*/
#line 4814 "./typica.w"

ScriptQMainWindow*window= new ScriptQMainWindow;
window->setObjectName(targetID);
object= engine->newQObject(window);
setQMainWindowProperties(object,engine);
QWidget*central= new(QWidget);
central->setParent(window);
central->setObjectName("centralWidget");
window->setCentralWidget(central);
if(element.hasChildNodes())
{
/*209:*/
#line 4850 "./typica.w"

QStack<QWidget*> widgetStack;
QStack<QLayout*> layoutStack;
QString windowScript;
widgetStack.push(central);
QDomNodeList windowChildren= element.childNodes();
int i= 0;
while(i<windowChildren.count())
{
QDomNode current;
QDomElement element;
current= windowChildren.at(i);
if(current.isElement())
{
element= current.toElement();
if(element.tagName()=="program")
{
windowScript.append(element.text());
}
else if(element.tagName()=="layout")
{
element.setAttribute("trcontext","configuration");
addLayoutToWidget(element,&widgetStack,&layoutStack);
}
else if(element.tagName()=="menu")
{
/*210:*/
#line 4898 "./typica.w"

QMenuBar*bar= window->menuBar();
bar->setParent(window);
bar->setObjectName("menuBar");
if(element.hasAttribute("name"))
{
QMenu*menu= bar->addMenu(QCoreApplication::translate("configuration",
element.attribute("name").toUtf8().data()));
menu->setParent(bar);
if(element.hasAttribute("type"))
{
if(element.attribute("type")=="reports")
{
if(element.hasAttribute("src"))
{
/*679:*/
#line 14431 "./typica.w"

QSettings settings;
QString reportDirectory= QString("%1/%2").arg(settings.value("config").
toString()).
arg(element.attribute("src"));
QDir::addSearchPath("reports",reportDirectory);
QDir directory(reportDirectory);
directory.setFilter(QDir::Files);
directory.setSorting(QDir::Name);
QStringList nameFilter;
nameFilter<<"*.xml";
directory.setNameFilters(nameFilter);
QFileInfoList reportFiles= directory.entryInfoList();
for(int i= 0;i<reportFiles.size();i++)
{
QFileInfo reportFile= reportFiles.at(i);
/*683:*/
#line 14511 "./typica.w"

QString path= reportFile.absoluteFilePath();
QFile file(path);
if(file.open(QIODevice::ReadOnly))
{
QDomDocument document;
document.setContent(&file,true);
QDomElement root= document.documentElement();
QString translationContext= root.attribute("id");
QDomNode titleNode= root.elementsByTagName("reporttitle").at(0);
if(!titleNode.isNull())
{
QDomElement titleElement= titleNode.toElement();
QString title= QCoreApplication::translate("configuration",
titleElement.text().toUtf8().data());
if(!title.isEmpty())
{
QStringList hierarchy= title.split(":->");
QMenu*insertionPoint= menu;
/*684:*/
#line 14540 "./typica.w"

for(int j= 0;j<hierarchy.size()-1;j++)
{
QObjectList menuList= insertionPoint->children();
bool menuFound= false;
for(int k= 0;k<menuList.size();k++)
{
QMenu*currentItem= qobject_cast<QMenu*> (menuList.at(k));
if(currentItem)
{
if(currentItem->title()==hierarchy.at(j))
{
menuFound= true;
insertionPoint= currentItem;
break;
}
}
}
if(!menuFound)
{
insertionPoint= insertionPoint->addMenu(hierarchy.at(j));
}
}

/*:684*/
#line 14530 "./typica.w"

ReportAction*action= new ReportAction(path,hierarchy.last());
insertionPoint->addAction(action);
}
}
}

/*:683*/
#line 14447 "./typica.w"

}

/*:679*/
#line 4913 "./typica.w"

}
}
}
if(element.hasChildNodes())
{
/*211:*/
#line 4926 "./typica.w"

QDomNodeList menuItems= element.childNodes();
int j= 0;
while(j<menuItems.count())
{
QDomNode item= menuItems.at(j);
if(item.isElement())
{
QDomElement itemElement= item.toElement();
if(itemElement.tagName()=="item")
{
QAction*itemAction= new QAction(QCoreApplication::translate("configuration",
itemElement.text().toUtf8().data()),menu);
if(itemElement.hasAttribute("id"))
{
itemAction->setObjectName(itemElement.attribute("id"));
}
if(itemElement.hasAttribute("shortcut"))
{
itemAction->setShortcut(itemElement.attribute("shortcut"));
}
menu->addAction(itemAction);
}
else if(itemElement.tagName()=="separator")
{
menu->addSeparator();
}
else if(itemElement.tagName()=="plugins")
{
/*704:*/
#line 21 "./plugins.w"

QMenu*pluginMenu= new QMenu(menu);
if(itemElement.hasAttribute("id"))
{
pluginMenu->setObjectName(itemElement.attribute("id"));
}
if(itemElement.hasAttribute("title"))
{
pluginMenu->setTitle(itemElement.attribute("title"));
}
if(itemElement.hasAttribute("src"))
{
QSettings settings;
QString pluginDirectory= QString("%1/%2").
arg(settings.value("config").toString()).
arg(itemElement.attribute("src"));
QDir directory(pluginDirectory);
directory.setFilter(QDir::Files);
directory.setSorting(QDir::Name);
QStringList nameFilter;
nameFilter<<"*.js";
directory.setNameFilters(nameFilter);
QFileInfoList pluginFiles= directory.entryInfoList();
for(int k= 0;k<pluginFiles.size();k++)
{
PluginAction*pa= new PluginAction(pluginFiles.at(k),pluginMenu);
if(itemElement.hasAttribute("preRun"))
{
pa->setPreRun(itemElement.attribute("preRun"));
}
if(itemElement.hasAttribute("postRun"))
{
pa->setPostRun(itemElement.attribute("postRun"));
}
pluginMenu->addAction(pa);
}
}
menu->addMenu(pluginMenu);

/*:704*/
#line 4955 "./typica.w"

}
}
j++;
}

#line 1 "./helpmenu.w"
/*:211*/
#line 4919 "./typica.w"

}
}

/*:210*/
#line 4876 "./typica.w"

}
}
i++;
}
QScriptValue oldThis= context->thisObject();
context->setThisObject(object);
QScriptValue result= engine->evaluate(windowScript);
/*202:*/
#line 4629 "./typica.w"

if(engine->hasUncaughtException())
{
int line= engine->uncaughtExceptionLineNumber();
qDebug()<<"Uncaught excpetion at line "<<line<<" : "<<
result.toString();
QString trace;
foreach(trace,engine->uncaughtExceptionBacktrace())
{
qDebug()<<trace;
}
}

/*:202*/
#line 4884 "./typica.w"

context->setThisObject(oldThis);

/*:209*/
#line 4825 "./typica.w"

}
/*212:*/
#line 9 "./helpmenu.w"

HelpMenu*helpMenu= new HelpMenu();
window->menuBar()->addMenu(helpMenu);

/*:212*/
#line 4827 "./typica.w"

window->show();
window->setupFinished();

/*:208*/
#line 4744 "./typica.w"

}
return object;
}

/*:205*//*206:*/
#line 4755 "./typica.w"

QScriptValue createReport(QScriptContext*context,QScriptEngine*engine)
{
QString targetID= argument<QString> (0,context);
QFile file(QString("reports:%1").arg(targetID));
QScriptValue object;
if(file.open(QIODevice::ReadOnly))
{
QDomDocument document;
document.setContent(&file,true);
QDomElement element= document.documentElement();
if(!element.isNull())
{
/*208:*/
#line 4814 "./typica.w"

ScriptQMainWindow*window= new ScriptQMainWindow;
window->setObjectName(targetID);
object= engine->newQObject(window);
setQMainWindowProperties(object,engine);
QWidget*central= new(QWidget);
central->setParent(window);
central->setObjectName("centralWidget");
window->setCentralWidget(central);
if(element.hasChildNodes())
{
/*209:*/
#line 4850 "./typica.w"

QStack<QWidget*> widgetStack;
QStack<QLayout*> layoutStack;
QString windowScript;
widgetStack.push(central);
QDomNodeList windowChildren= element.childNodes();
int i= 0;
while(i<windowChildren.count())
{
QDomNode current;
QDomElement element;
current= windowChildren.at(i);
if(current.isElement())
{
element= current.toElement();
if(element.tagName()=="program")
{
windowScript.append(element.text());
}
else if(element.tagName()=="layout")
{
element.setAttribute("trcontext","configuration");
addLayoutToWidget(element,&widgetStack,&layoutStack);
}
else if(element.tagName()=="menu")
{
/*210:*/
#line 4898 "./typica.w"

QMenuBar*bar= window->menuBar();
bar->setParent(window);
bar->setObjectName("menuBar");
if(element.hasAttribute("name"))
{
QMenu*menu= bar->addMenu(QCoreApplication::translate("configuration",
element.attribute("name").toUtf8().data()));
menu->setParent(bar);
if(element.hasAttribute("type"))
{
if(element.attribute("type")=="reports")
{
if(element.hasAttribute("src"))
{
/*679:*/
#line 14431 "./typica.w"

QSettings settings;
QString reportDirectory= QString("%1/%2").arg(settings.value("config").
toString()).
arg(element.attribute("src"));
QDir::addSearchPath("reports",reportDirectory);
QDir directory(reportDirectory);
directory.setFilter(QDir::Files);
directory.setSorting(QDir::Name);
QStringList nameFilter;
nameFilter<<"*.xml";
directory.setNameFilters(nameFilter);
QFileInfoList reportFiles= directory.entryInfoList();
for(int i= 0;i<reportFiles.size();i++)
{
QFileInfo reportFile= reportFiles.at(i);
/*683:*/
#line 14511 "./typica.w"

QString path= reportFile.absoluteFilePath();
QFile file(path);
if(file.open(QIODevice::ReadOnly))
{
QDomDocument document;
document.setContent(&file,true);
QDomElement root= document.documentElement();
QString translationContext= root.attribute("id");
QDomNode titleNode= root.elementsByTagName("reporttitle").at(0);
if(!titleNode.isNull())
{
QDomElement titleElement= titleNode.toElement();
QString title= QCoreApplication::translate("configuration",
titleElement.text().toUtf8().data());
if(!title.isEmpty())
{
QStringList hierarchy= title.split(":->");
QMenu*insertionPoint= menu;
/*684:*/
#line 14540 "./typica.w"

for(int j= 0;j<hierarchy.size()-1;j++)
{
QObjectList menuList= insertionPoint->children();
bool menuFound= false;
for(int k= 0;k<menuList.size();k++)
{
QMenu*currentItem= qobject_cast<QMenu*> (menuList.at(k));
if(currentItem)
{
if(currentItem->title()==hierarchy.at(j))
{
menuFound= true;
insertionPoint= currentItem;
break;
}
}
}
if(!menuFound)
{
insertionPoint= insertionPoint->addMenu(hierarchy.at(j));
}
}

/*:684*/
#line 14530 "./typica.w"

ReportAction*action= new ReportAction(path,hierarchy.last());
insertionPoint->addAction(action);
}
}
}

/*:683*/
#line 14447 "./typica.w"

}

/*:679*/
#line 4913 "./typica.w"

}
}
}
if(element.hasChildNodes())
{
/*211:*/
#line 4926 "./typica.w"

QDomNodeList menuItems= element.childNodes();
int j= 0;
while(j<menuItems.count())
{
QDomNode item= menuItems.at(j);
if(item.isElement())
{
QDomElement itemElement= item.toElement();
if(itemElement.tagName()=="item")
{
QAction*itemAction= new QAction(QCoreApplication::translate("configuration",
itemElement.text().toUtf8().data()),menu);
if(itemElement.hasAttribute("id"))
{
itemAction->setObjectName(itemElement.attribute("id"));
}
if(itemElement.hasAttribute("shortcut"))
{
itemAction->setShortcut(itemElement.attribute("shortcut"));
}
menu->addAction(itemAction);
}
else if(itemElement.tagName()=="separator")
{
menu->addSeparator();
}
else if(itemElement.tagName()=="plugins")
{
/*704:*/
#line 21 "./plugins.w"

QMenu*pluginMenu= new QMenu(menu);
if(itemElement.hasAttribute("id"))
{
pluginMenu->setObjectName(itemElement.attribute("id"));
}
if(itemElement.hasAttribute("title"))
{
pluginMenu->setTitle(itemElement.attribute("title"));
}
if(itemElement.hasAttribute("src"))
{
QSettings settings;
QString pluginDirectory= QString("%1/%2").
arg(settings.value("config").toString()).
arg(itemElement.attribute("src"));
QDir directory(pluginDirectory);
directory.setFilter(QDir::Files);
directory.setSorting(QDir::Name);
QStringList nameFilter;
nameFilter<<"*.js";
directory.setNameFilters(nameFilter);
QFileInfoList pluginFiles= directory.entryInfoList();
for(int k= 0;k<pluginFiles.size();k++)
{
PluginAction*pa= new PluginAction(pluginFiles.at(k),pluginMenu);
if(itemElement.hasAttribute("preRun"))
{
pa->setPreRun(itemElement.attribute("preRun"));
}
if(itemElement.hasAttribute("postRun"))
{
pa->setPostRun(itemElement.attribute("postRun"));
}
pluginMenu->addAction(pa);
}
}
menu->addMenu(pluginMenu);

/*:704*/
#line 4955 "./typica.w"

}
}
j++;
}

#line 1 "./helpmenu.w"
/*:211*/
#line 4919 "./typica.w"

}
}

/*:210*/
#line 4876 "./typica.w"

}
}
i++;
}
QScriptValue oldThis= context->thisObject();
context->setThisObject(object);
QScriptValue result= engine->evaluate(windowScript);
/*202:*/
#line 4629 "./typica.w"

if(engine->hasUncaughtException())
{
int line= engine->uncaughtExceptionLineNumber();
qDebug()<<"Uncaught excpetion at line "<<line<<" : "<<
result.toString();
QString trace;
foreach(trace,engine->uncaughtExceptionBacktrace())
{
qDebug()<<trace;
}
}

/*:202*/
#line 4884 "./typica.w"

context->setThisObject(oldThis);

/*:209*/
#line 4825 "./typica.w"

}
/*212:*/
#line 9 "./helpmenu.w"

HelpMenu*helpMenu= new HelpMenu();
window->menuBar()->addMenu(helpMenu);

/*:212*/
#line 4827 "./typica.w"

window->show();
window->setupFinished();

/*:208*/
#line 4768 "./typica.w"

}
file.close();
}
return object;
}

/*:206*//*224:*/
#line 4975 "./typica.w"

void addLayoutToWidget(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
if(element.hasAttribute("type"))
{
/*225:*/
#line 4996 "./typica.w"

QLayout*layout;
QString layoutType= element.attribute("type");
if(layoutType=="horizontal")
{
layout= new QHBoxLayout;
layoutStack->push(layout);
populateBoxLayout(element,widgetStack,layoutStack);
}
else if(layoutType=="vertical")
{
layout= new QVBoxLayout;
layoutStack->push(layout);
populateBoxLayout(element,widgetStack,layoutStack);
}
else if(layoutType=="grid")
{
layout= new QGridLayout;
layoutStack->push(layout);
populateGridLayout(element,widgetStack,layoutStack);
}
else if(layoutType=="stack")
{
layout= new QStackedLayout;
layoutStack->push(layout);
populateStackedLayout(element,widgetStack,layoutStack);
}
if(element.hasAttribute("id"))
{
layout->setObjectName(element.attribute("id"));
}
if(element.hasAttribute("spacing"))
{
layout->setSpacing(element.attribute("spacing").toInt());
}
if(element.hasAttribute("margin"))
{
int m= element.attribute("margin").toInt();
layout->setContentsMargins(m,m,m,m);
}

/*:225*/
#line 4981 "./typica.w"

QWidget*widget= widgetStack->top();
if(layout)
{
widget->setLayout(layout);
}
layoutStack->pop();
}
}

/*:224*//*226:*/
#line 5043 "./typica.w"

void populateStackedLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
QDomNodeList children= element.childNodes();
QStackedLayout*layout= qobject_cast<QStackedLayout*> (layoutStack->top());
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
if(currentElement.tagName()=="page")
{
QWidget*widget= new QWidget;
layout->addWidget(widget);
widgetStack->push(widget);
currentElement.setAttribute("trcontext","configuration");
populateWidget(currentElement,widgetStack,layoutStack);
widgetStack->pop();
}
}
}
}

/*:226*//*228:*/
#line 5082 "./typica.w"

void addTabBarToLayout(QDomElement element,QStack<QWidget*> *,QStack<QLayout*> *layoutStack)
{
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
QTabBar*widget= new QTabBar;
layout->addWidget(widget);
if(!element.attribute("id").isEmpty())
{
widget->setObjectName(element.attribute("id"));
}
}

/*:228*//*230:*/
#line 5104 "./typica.w"

QScriptValue constructQTabBar(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QTabBar);
setQTabBarProperties(object,engine);
return object;
}

/*:230*//*231:*/
#line 5115 "./typica.w"

void setQTabBarProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
value.setProperty("addTab",engine->newFunction(QTabBar_addTab));
}

QScriptValue QTabBar_addTab(QScriptContext*context,QScriptEngine*)
{
QTabBar*self= getself<QTabBar*> (context);
if(context->argumentCount()> 0)
{
self->addTab(argument<QString> (0,context));
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QTabBar::addTab().");
}
return QScriptValue();
}

/*:231*//*233:*/
#line 5150 "./typica.w"

void populateGridLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
QDomNodeList children= element.childNodes();
int row= -1;
QGridLayout*layout= qobject_cast<QGridLayout*> (layoutStack->top());
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
if(currentElement.tagName()=="row")
{
row++;
if(currentElement.hasAttribute("height"))
{
layout->setRowMinimumHeight(row,
currentElement.attribute("height").toInt());
}
if(currentElement.hasAttribute("stretch"))
{
layout->setRowStretch(row,
currentElement.attribute("stretch").toInt());
}
/*234:*/
#line 5206 "./typica.w"

int column= -1;
QDomNodeList rowChildren= currentElement.childNodes();
for(int j= 0;j<rowChildren.count();j++)
{
QDomNode columnNode;
QDomElement columnElement;
columnNode= rowChildren.at(j);
if(columnNode.isElement())
{
columnElement= columnNode.toElement();
if(columnElement.tagName()=="column")
{
column++;
if(columnElement.hasAttribute("column"))
{
column= columnElement.attribute("column").toInt();
}
if(columnElement.hasAttribute("width"))
{
layout->setColumnMinimumWidth(column,
columnElement.attribute("width").toInt());
}
if(columnElement.hasAttribute("stretch"))
{
layout->setColumnStretch(column,
columnElement.attribute("stretch").toInt());
}
int hspan= 1;
int vspan= 1;
if(columnElement.hasAttribute("rowspan"))
{
vspan= columnElement.attribute("rowspan").toInt();
}
if(columnElement.hasAttribute("colspan"))
{
hspan= columnElement.attribute("colspan").toInt();
}
QHBoxLayout*cell= new QHBoxLayout;
layout->addLayout(cell,row,column,vspan,hspan);
layoutStack->push(cell);
columnElement.setAttribute("trcontext","configuration");
populateBoxLayout(columnElement,widgetStack,layoutStack);
layoutStack->pop();
}
}
}

/*:234*/
#line 5178 "./typica.w"

}
}
}
}

/*:233*//*235:*/
#line 5257 "./typica.w"

void populateBoxLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
QDomNodeList children= element.childNodes();
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
currentElement.setAttribute("trcontext","configuration");
if(currentElement.tagName()=="button")
{
addButtonToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="calendar")
{
addCalendarToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="timeedit")
{
addTimeEditToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="decoration")
{
addDecorationToLayout(currentElement,widgetStack,
layoutStack);
}
else if(currentElement.tagName()=="layout")
{
addLayoutToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="splitter")
{
addSplitterToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="label")
{
QBoxLayout*layout= 
qobject_cast<QBoxLayout*> (layoutStack->top());
QLabel*label= new QLabel(QCoreApplication::translate(
"configuration",
currentElement.text().toUtf8().data()));
if(currentElement.hasAttribute("id"))
{
label->setObjectName(currentElement.attribute("id"));
}
layout->addWidget(label);
}
else if(currentElement.tagName()=="lcdtemperature")
{
addTemperatureDisplayToLayout(currentElement,widgetStack,
layoutStack);
}
else if(currentElement.tagName()=="lcdtimer")
{
addTimerDisplayToLayout(currentElement,widgetStack,
layoutStack);
}
else if(currentElement.tagName()=="line")
{
addLineToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="report")
{
addReportToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="sqldrop")
{
addSqlDropToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="sqltablearray")
{
addSaltToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="sqlview")
{
addSqlQueryViewToLayout(currentElement,widgetStack,
layoutStack);
}
else if(currentElement.tagName()=="textarea")
{
addTextToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="spinbox")
{
addSpinBoxToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="formarray")
{
addFormArrayToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="hscale")
{
addScaleControlToLayout(currentElement,widgetStack,
layoutStack);
}
else if(currentElement.tagName()=="vscale")
{
addIntensityControlToLayout(currentElement,widgetStack,
layoutStack);
}
else if(currentElement.tagName()=="webview")
{
addWebViewToLayout(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="stretch")
{
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addStretch();
}
/*54:*/
#line 1569 "./typica.w"

else if(currentElement.tagName()=="svgwidget")
{
addSvgWidgetToLayout(currentElement,widgetStack,layoutStack);
}

/*:54*//*227:*/
#line 5074 "./typica.w"

else if(currentElement.tagName()=="tabbar")
{
addTabBarToLayout(currentElement,widgetStack,layoutStack);
}

/*:227*//*606:*/
#line 111 "./printerselector.w"

else if(currentElement.tagName()=="printerselector")
{
addPrinterSelectorToLayout(currentElement,widgetStack,layoutStack);
}

#line 13005 "./typica.w"

/*:606*//*727:*/
#line 451 "./daterangeselector.w"

else if(currentElement.tagName()=="daterange")
{
addDateRangeToLayout(currentElement,widgetStack,layoutStack);
}

/*:727*//*1186:*/
#line 135 "./roastcoloredit.w"

else if(currentElement.tagName()=="roastcoloredit")
{
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
RoastColorEdit*edit= new RoastColorEdit;
if(currentElement.hasAttribute("id"))
{
edit->setObjectName(currentElement.attribute("id"));
}
layout->addWidget(edit);
}

/*:1186*/
#line 5371 "./typica.w"

}
}
}

/*:235*//*236:*/
#line 5379 "./typica.w"

void addLayoutToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
QLayout*targetLayout= layoutStack->pop();
QBoxLayout*boxLayout= qobject_cast<QBoxLayout*> (targetLayout);
if(element.hasAttribute("type"))
{
/*225:*/
#line 4996 "./typica.w"

QLayout*layout;
QString layoutType= element.attribute("type");
if(layoutType=="horizontal")
{
layout= new QHBoxLayout;
layoutStack->push(layout);
populateBoxLayout(element,widgetStack,layoutStack);
}
else if(layoutType=="vertical")
{
layout= new QVBoxLayout;
layoutStack->push(layout);
populateBoxLayout(element,widgetStack,layoutStack);
}
else if(layoutType=="grid")
{
layout= new QGridLayout;
layoutStack->push(layout);
populateGridLayout(element,widgetStack,layoutStack);
}
else if(layoutType=="stack")
{
layout= new QStackedLayout;
layoutStack->push(layout);
populateStackedLayout(element,widgetStack,layoutStack);
}
if(element.hasAttribute("id"))
{
layout->setObjectName(element.attribute("id"));
}
if(element.hasAttribute("spacing"))
{
layout->setSpacing(element.attribute("spacing").toInt());
}
if(element.hasAttribute("margin"))
{
int m= element.attribute("margin").toInt();
layout->setContentsMargins(m,m,m,m);
}

/*:225*/
#line 5387 "./typica.w"

boxLayout->addLayout(layout);
layoutStack->pop();
}
layoutStack->push(targetLayout);
}

/*:236*//*237:*/
#line 5398 "./typica.w"

void addSplitterToLayout(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
QSplitter*splitter= new(QSplitter);
layout->addWidget(splitter);
/*238:*/
#line 5411 "./typica.w"

QString orientation= element.attribute("type");
if(orientation=="horizontal")
{
splitter->setOrientation(Qt::Horizontal);
}
else if(orientation=="vertical")
{
splitter->setOrientation(Qt::Vertical);
}
QString id= element.attribute("id");
if(!id.isEmpty())
{
splitter->setObjectName(id);
}
if(element.hasChildNodes())
{
widgetStack->push(splitter);
populateSplitter(element,widgetStack,layoutStack);
widgetStack->pop();
}

/*:238*/
#line 5405 "./typica.w"

}

/*:237*//*239:*/
#line 5437 "./typica.w"

void populateSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
QDomNodeList children= element.childNodes();
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
currentElement.setAttribute("trcontext","configuration");
if(currentElement.tagName()=="decoration")
{
addDecorationToSplitter(currentElement,widgetStack,
layoutStack);
}
else if(currentElement.tagName()=="graph")
{
addGraphToSplitter(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="splitter")
{
addSplitterToSplitter(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="lcdtemperature")
{
addTemperatureDisplayToSplitter(currentElement,widgetStack,
layoutStack);
}
else if(currentElement.tagName()=="lcdtimer")
{
addTimerDisplayToSplitter(currentElement,widgetStack,
layoutStack);
}
else if(currentElement.tagName()=="measurementtable")
{
addZoomLogToSplitter(currentElement,widgetStack,layoutStack);
}
else if(currentElement.tagName()=="widget")
{
addWidgetToSplitter(currentElement,widgetStack,layoutStack);
}
}
}
}

/*:239*//*240:*/
#line 5488 "./typica.w"

void addSplitterToSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
QSplitter*parent= qobject_cast<QSplitter*> (widgetStack->top());
QSplitter*splitter= new(QSplitter);
splitter->setParent(parent);
parent->addWidget(splitter);
/*238:*/
#line 5411 "./typica.w"

QString orientation= element.attribute("type");
if(orientation=="horizontal")
{
splitter->setOrientation(Qt::Horizontal);
}
else if(orientation=="vertical")
{
splitter->setOrientation(Qt::Vertical);
}
QString id= element.attribute("id");
if(!id.isEmpty())
{
splitter->setObjectName(id);
}
if(element.hasChildNodes())
{
widgetStack->push(splitter);
populateSplitter(element,widgetStack,layoutStack);
widgetStack->pop();
}

/*:238*/
#line 5496 "./typica.w"

}

/*:240*//*241:*/
#line 5505 "./typica.w"

void addTemperatureDisplayToSplitter(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *)
{
TemperatureDisplay*display= new(TemperatureDisplay);
if(element.hasAttribute("id"))
{
display->setObjectName(element.attribute("id"));
}
QSplitter*splitter= qobject_cast<QSplitter*> (widgetStack->top());
splitter->addWidget(display);
}

void addTemperatureDisplayToLayout(QDomElement element,
QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
TemperatureDisplay*display= new(TemperatureDisplay);
if(element.hasAttribute("id"))
{
display->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(display);
}

/*:241*//*242:*/
#line 5536 "./typica.w"

void addTimerDisplayToSplitter(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *)
{
TimerDisplay*display= new(TimerDisplay);
if(element.hasAttribute("id"))
{
display->setObjectName(element.attribute("id"));
}
if(element.hasAttribute("format"))
{
display->setDisplayFormat(element.attribute("format"));
}
QSplitter*splitter= qobject_cast<QSplitter*> (widgetStack->top());
splitter->addWidget(display);
}

void addTimerDisplayToLayout(QDomElement element,
QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
TimerDisplay*display= new(TimerDisplay);
if(element.hasAttribute("id"))
{
display->setObjectName(element.attribute("id"));
}
if(element.hasAttribute("format"))
{
display->setDisplayFormat(element.attribute("format"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(display);
}

/*:242*//*243:*/
#line 5574 "./typica.w"

void addDecorationToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
/*244:*/
#line 5595 "./typica.w"

QString labelText= 
QCoreApplication::translate("configuration",
element.attribute("name").toUtf8().data());
Qt::Orientations orientation= Qt::Horizontal;
if(element.hasAttribute("type"))
{
if(element.attribute("type")=="horizontal")
{
orientation= Qt::Horizontal;
}
else if(element.attribute("type")=="vertical")
{
orientation= Qt::Vertical;
}
}
/*245:*/
#line 5622 "./typica.w"

QWidget*theWidget= NULL;
QDomNodeList children= element.childNodes();
for(int i= 0;i<children.count();i++)
{
QDomNode item= children.at(i);
if(item.isElement())
{
QDomElement itemElement= item.toElement();
if(itemElement.tagName()=="lcdtemperature")
{
TemperatureDisplay*display= new TemperatureDisplay;
if(itemElement.hasAttribute("id"))
{
display->setObjectName(itemElement.attribute("id"));
}
theWidget= display;
}
else if(itemElement.tagName()=="lcdtimer")
{
TimerDisplay*display= new TimerDisplay;
if(itemElement.hasAttribute("id"))
{
display->setObjectName(itemElement.attribute("id"));
}
if(itemElement.hasAttribute("format"))
{
display->setDisplayFormat(itemElement.attribute("format"));
}
theWidget= display;
}
}
}

/*:245*/
#line 5611 "./typica.w"

WidgetDecorator*decoration= new WidgetDecorator(theWidget,labelText,
orientation);
if(element.hasAttribute("id"))
{
decoration->setObjectName(element.attribute("id"));
}

/*:244*/
#line 5578 "./typica.w"

QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(decoration);
}

void addDecorationToSplitter(QDomElement element,
QStack<QWidget*> *widgetStack,
QStack<QLayout*> *)
{
/*244:*/
#line 5595 "./typica.w"

QString labelText= 
QCoreApplication::translate("configuration",
element.attribute("name").toUtf8().data());
Qt::Orientations orientation= Qt::Horizontal;
if(element.hasAttribute("type"))
{
if(element.attribute("type")=="horizontal")
{
orientation= Qt::Horizontal;
}
else if(element.attribute("type")=="vertical")
{
orientation= Qt::Vertical;
}
}
/*245:*/
#line 5622 "./typica.w"

QWidget*theWidget= NULL;
QDomNodeList children= element.childNodes();
for(int i= 0;i<children.count();i++)
{
QDomNode item= children.at(i);
if(item.isElement())
{
QDomElement itemElement= item.toElement();
if(itemElement.tagName()=="lcdtemperature")
{
TemperatureDisplay*display= new TemperatureDisplay;
if(itemElement.hasAttribute("id"))
{
display->setObjectName(itemElement.attribute("id"));
}
theWidget= display;
}
else if(itemElement.tagName()=="lcdtimer")
{
TimerDisplay*display= new TimerDisplay;
if(itemElement.hasAttribute("id"))
{
display->setObjectName(itemElement.attribute("id"));
}
if(itemElement.hasAttribute("format"))
{
display->setDisplayFormat(itemElement.attribute("format"));
}
theWidget= display;
}
}
}

/*:245*/
#line 5611 "./typica.w"

WidgetDecorator*decoration= new WidgetDecorator(theWidget,labelText,
orientation);
if(element.hasAttribute("id"))
{
decoration->setObjectName(element.attribute("id"));
}

/*:244*/
#line 5587 "./typica.w"

QSplitter*splitter= qobject_cast<QSplitter*> (widgetStack->top());
splitter->addWidget(decoration);
}

/*:243*//*246:*/
#line 5667 "./typica.w"

void addWidgetToSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
QSplitter*splitter= qobject_cast<QSplitter*> (widgetStack->top());
QWidget*widget= new QWidget;
if(element.hasAttribute("id"))
{
widget->setObjectName(element.attribute("id"));
}
if(element.hasAttribute("ignoreSizePolicy"))
{
if(element.attribute("ignoreSizePolicy")=="true")
{
widget->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
}
}
splitter->addWidget(widget);
if(element.hasChildNodes())
{
widgetStack->push(widget);
populateWidget(element,widgetStack,layoutStack);
widgetStack->pop();
}
}

void populateWidget(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *layoutStack)
{
QDomNodeList children= element.childNodes();
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
if(currentElement.tagName()=="layout")
{
currentElement.setAttribute("trcontext","configuration");
addLayoutToWidget(currentElement,widgetStack,layoutStack);
}
}
}
}

/*:246*//*247:*/
#line 5718 "./typica.w"

void addButtonToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
QAbstractButton*button= NULL;
QString text= 
QCoreApplication::translate("configuration",
element.attribute("name").toUtf8().data());
if(element.hasAttribute("type"))
{
QString type= element.attribute("type");
if(type=="annotation")
{
AnnotationButton*abutton= new AnnotationButton(text);
if(element.hasAttribute("annotation"))
{
abutton->setAnnotation(element.attribute("annotation"));
}
if(element.hasAttribute("series"))
{
abutton->setTemperatureColumn(element.attribute("series").
toInt());
}
if(element.hasAttribute("column"))
{
abutton->setAnnotationColumn(element.attribute("column").
toInt());
}
button= abutton;
}
else if(type=="check")
{
button= new QCheckBox(text);
}
else if(type=="push")
{
button= new QPushButton(text);
}
}
if(element.hasAttribute("id"))
{
button->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(button);
}

/*:247*//*248:*/
#line 5772 "./typica.w"

void addSpinBoxToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
AnnotationSpinBox*box= new AnnotationSpinBox("","",NULL);
if(element.hasAttribute("pretext"))
{
box->setPretext(QCoreApplication::translate(
"configuration",
element.attribute("pretext").toUtf8().data()));
}
if(element.hasAttribute("posttext"))
{
box->setPosttext(QCoreApplication::translate(
"configuration",
element.attribute("posttext").toUtf8().data()));
}
if(element.hasAttribute("series"))
{
box->setTemperatureColumn(element.attribute("series").toInt());
}
if(element.hasAttribute("column"))
{
box->setAnnotationColumn(element.attribute("column").toInt());
}
if(element.hasAttribute("min"))
{
box->setMinimum(element.attribute("min").toDouble());
}
if(element.hasAttribute("max"))
{
box->setMaximum(element.attribute("max").toDouble());
}
if(element.hasAttribute("decimals"))
{
box->setDecimals(element.attribute("decimals").toInt());
}
if(element.hasAttribute("step"))
{
box->setSingleStep(element.attribute("step").toDouble());
}
if(element.hasAttribute("id"))
{
box->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(box);
}

/*:248*//*249:*/
#line 5832 "./typica.w"

void addZoomLogToSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *)
{
ZoomLog*widget= new ZoomLog;
if(element.hasAttribute("id"))
{
widget->setObjectName(element.attribute("id"));
}
if(element.hasChildNodes())
{
QDomNodeList children= element.childNodes();
int column= 0;
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
if(currentElement.tagName()=="column")
{
QString text= 
QCoreApplication::translate(
"configuration",
currentElement.text().toUtf8().data());
widget->setHeaderData(column,text);
column++;
}
}
}
}
QSplitter*splitter= qobject_cast<QSplitter*> (widgetStack->top());
if(splitter)
{
splitter->addWidget(widget);
}
else
{
qDebug()<<"Splitter not found at top of widget stack!";
}
}

/*:249*//*250:*/
#line 5879 "./typica.w"

void addGraphToSplitter(QDomElement element,QStack<QWidget*> *widgetStack,
QStack<QLayout*> *)
{
GraphView*view= new GraphView;
if(element.hasAttribute("id"))
{
view->setObjectName(element.attribute("id"));
}
QSplitter*splitter= qobject_cast<QSplitter*> (widgetStack->top());
splitter->addWidget(view);
}

/*:250*//*251:*/
#line 5896 "./typica.w"

void addSqlDropToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
SqlComboBox*box= new SqlComboBox();
if(element.hasAttribute("data"))
{
box->setDataColumn(element.attribute("data").toInt());
}
if(element.hasAttribute("display"))
{
box->setDisplayColumn(element.attribute("display").toInt());
}
if(element.hasAttribute("showdata"))
{
if(element.attribute("showdata")=="true")
{
box->showData(true);
}
}
if(element.hasAttribute("editable"))
{
if(element.attribute("editable")=="true")
{
box->setEditable(true);
}
}
if(element.hasChildNodes())
{
QDomNodeList children= element.childNodes();
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
if(currentElement.tagName()=="null")
{
box->addNullOption();
}
else if(currentElement.tagName()=="query")
{
box->addSqlOptions(currentElement.text());
}
}
}
}
if(element.hasAttribute("id"))
{
box->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(box);
}

/*:251*//*252:*/
#line 5975 "./typica.w"

void addSaltToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
QTableView*view= new QTableView;
view->setProperty("tabletype",QVariant(QString("SaltTable")));
SaltModel*model= new SaltModel(element.childNodes().count());
if(element.hasAttribute("id"))
{
view->setObjectName(element.attribute("id"));
}
if(element.hasChildNodes())
{
QDomNodeList children= element.childNodes();
int currentColumn= 0;
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
if(currentElement.tagName()=="column")
{
if(currentElement.hasAttribute("name"))
{
model->setHeaderData(currentColumn,
Qt::Horizontal,
QCoreApplication::translate(
"configuration",
currentElement.attribute("name").toUtf8().data()));
}
if(currentElement.hasAttribute("delegate"))
{
/*253:*/
#line 6026 "./typica.w"

if(currentElement.attribute("delegate")=="sql")
{
/*254:*/
#line 6046 "./typica.w"

SqlComboBoxDelegate*delegate= new SqlComboBoxDelegate;
SqlComboBox*widget= new SqlComboBox();
if(currentElement.hasAttribute("nulltext"))
{
widget->setNullText(currentElement.attribute("nulltext"));
}
if(currentElement.hasAttribute("nulldata"))
{
widget->setNullData(QVariant(currentElement.attribute("nulldata")));
}
if(currentElement.hasAttribute("null"))
{
if(currentElement.attribute("null")=="true")
{
widget->addNullOption();
}
}
if(currentElement.hasAttribute("showdata"))
{
if(currentElement.attribute("showdata")=="true")
{
widget->showData(true);
}
}
if(currentElement.hasAttribute("data"))
{
widget->setDataColumn(currentElement.attribute("data").toInt());
}
if(currentElement.hasAttribute("display"))
{
widget->setDisplayColumn(currentElement.attribute("display").toInt());
}
widget->addSqlOptions(currentElement.text());
delegate->setWidget(widget);
view->setItemDelegateForColumn(currentColumn,delegate);

/*:254*/
#line 6029 "./typica.w"

}
else if(currentElement.attribute("delegate")=="numeric")
{
/*255:*/
#line 6085 "./typica.w"

NumericDelegate*delegate= new NumericDelegate;
view->setItemDelegateForColumn(currentColumn,delegate);

/*:255*/
#line 6033 "./typica.w"

}
else if(currentElement.attribute("delegate")=="positivenumeric")
{
/*256:*/
#line 6092 "./typica.w"

NumericDelegate*delegate= new NumericDelegate(true);
view->setItemDelegateForColumn(currentColumn,delegate);

/*:256*/
#line 6037 "./typica.w"

}

/*:253*/
#line 6010 "./typica.w"

}
currentColumn++;
}
}
}
}
view->setModel(model);
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(view);
}

/*:252*//*268:*/
#line 6281 "./typica.w"

void addLineToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
QLineEdit*widget= new QLineEdit(element.text());
if(element.hasAttribute("id"))
{
widget->setObjectName(element.attribute("id"));
}
if(element.hasAttribute("writable"))
{
if(element.attribute("writable")=="false")
{
widget->setReadOnly(true);
}
}
if(element.hasAttribute("validator"))
{
if(element.attribute("validator")=="numeric")
{
widget->setValidator(new ScriptValidator(new QDoubleValidator));
}
else if(element.attribute("validator")=="integer")
{
widget->setValidator(new ScriptValidator(new QIntValidator));
}
else if(element.attribute("validator")=="expression"&&
element.hasAttribute("expression"))
{
widget->setValidator(new QRegExpValidator(
QRegExp(element.attribute("expression")),
NULL));
}
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(widget);
}

/*:268*//*269:*/
#line 6322 "./typica.w"

void addTextToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
QTextEdit*widget= new QTextEdit;
if(element.hasAttribute("id"))
{
widget->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(widget);
}

/*:269*//*270:*/
#line 6339 "./typica.w"

void addSqlQueryViewToLayout(QDomElement element,
QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
SqlQueryView*view= new SqlQueryView;
if(element.hasAttribute("id"))
{
view->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(view);
}

/*:270*//*271:*/
#line 6356 "./typica.w"

void addCalendarToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
QWidget*widget;
if(element.hasAttribute("time"))
{
if(element.attribute("time")=="true")
{
QDateTimeEdit*edit= new QDateTimeEdit;
edit->setDateTime(QDateTime::currentDateTime());
edit->setCalendarPopup(true);
edit->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
widget= qobject_cast<QWidget*> (edit);
}
else
{
QDateEdit*edit= new QDateEdit;
edit->setDate(QDate::currentDate());
edit->setCalendarPopup(true);
edit->setDisplayFormat("yyyy-MM-dd");
widget= qobject_cast<QWidget*> (edit);
}
}
else
{
QDateEdit*edit= new QDateEdit;
edit->setDate(QDate::currentDate());
edit->setCalendarPopup(true);
edit->setDisplayFormat("yyyy-MM-dd");
widget= qobject_cast<QWidget*> (edit);
}
if(element.hasAttribute("id"))
{
widget->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(widget);
}

/*:271*//*272:*/
#line 6399 "./typica.w"

void setQDateEditProperties(QScriptValue value,QScriptEngine*engine)
{
setQDateTimeEditProperties(value,engine);
}

void setQDateTimeEditProperties(QScriptValue value,QScriptEngine*engine)
{
setQAbstractSpinBoxProperties(value,engine);
value.setProperty("setDate",engine->newFunction(QDateTimeEdit_setDate));
value.setProperty("day",engine->newFunction(QDateTimeEdit_day));
value.setProperty("month",engine->newFunction(QDateTimeEdit_month));
value.setProperty("year",engine->newFunction(QDateTimeEdit_year));
value.setProperty("setToCurrentTime",
engine->newFunction(QDateTimeEdit_setToCurrentTime));
}

/*:272*//*273:*/
#line 6421 "./typica.w"

QScriptValue QDateTimeEdit_setDate(QScriptContext*context,QScriptEngine*)
{
QDateTimeEdit*self= getself<QDateTimeEdit*> (context);
if(context->argumentCount()==3)
{
self->setDate(QDate(argument<int> (0,context),
argument<int> (1,context),
argument<int> (2,context)));
}
else
{
context->throwError("Incorrect number of arguments passed to "
"QDateTimeEdit::setDate(). This method takes three integer arguments "
"specifying the year, month, and day.");
}
return QScriptValue();
}

QScriptValue QDateTimeEdit_day(QScriptContext*context,QScriptEngine*)
{
QDateTimeEdit*self= getself<QDateTimeEdit*> (context);
return QScriptValue(self->date().day());
}

QScriptValue QDateTimeEdit_month(QScriptContext*context,QScriptEngine*)
{
QDateTimeEdit*self= getself<QDateTimeEdit*> (context);
return QScriptValue(self->date().month());
}

QScriptValue QDateTimeEdit_year(QScriptContext*context,QScriptEngine*)
{
QDateTimeEdit*self= getself<QDateTimeEdit*> (context);
return QScriptValue(self->date().year());
}

QScriptValue QDateTimeEdit_setToCurrentTime(QScriptContext*context,QScriptEngine*)
{
QDateTimeEdit*self= getself<QDateTimeEdit*> (context);
self->setDateTime(QDateTime::currentDateTime());
return QScriptValue();
}

/*:273*//*275:*/
#line 6481 "./typica.w"

void addTimeEditToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
QTimeEdit*edit= new QTimeEdit;
if(element.hasAttribute("displayFormat"))
{
edit->setDisplayFormat(element.attribute("displayFormat"));
}
else
{
edit->setDisplayFormat("mm:ss.zzz");
}
if(element.hasAttribute("id"))
{
edit->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(edit);
}

/*:275*//*276:*/
#line 6504 "./typica.w"

void setQTimeEditProperties(QScriptValue value,QScriptEngine*engine)
{
setQDateTimeEditProperties(value,engine);
}

/*:276*//*280:*/
#line 6533 "./typica.w"

QScriptValue findChildObject(QScriptContext*context,QScriptEngine*engine)
{
QObject*parent= argument<QObject*> (0,context);
QString name= argument<QString> (1,context);
QObject*object= parent->findChild<QObject*> (name);
QScriptValue value;
if(object)
{
value= engine->newQObject(object);
QString className= object->metaObject()->className();
/*281:*/
#line 6551 "./typica.w"

if(className=="TemperatureDisplay")
{
setTemperatureDisplayProperties(value,engine);
}
else if(className=="TimerDisplay")
{
setTimerDisplayProperties(value,engine);
}
else if(className=="QAction")
{
setQActionProperties(value,engine);
}
else if(className=="QBoxLayout")
{
setQBoxLayoutProperties(value,engine);
}
else if(className=="QDateEdit")
{
setQDateEditProperties(value,engine);
}
else if(className=="QDateTimeEdit")
{
setQDateTimeEditProperties(value,engine);
}
else if(className=="QFrame")
{
setQFrameProperties(value,engine);
}
else if(className=="QHBoxLayout")
{
setQBoxLayoutProperties(value,engine);
}
else if(className=="QLCDNumber")
{
setQLCDNumberProperties(value,engine);
}
else if(className=="QMenu")
{
setQMenuProperties(value,engine);
}
else if(className=="QMenuBar")
{
setQMenuBarProperties(value,engine);
}
else if(className=="QPushButton")
{
setQPushButtonProperties(value,engine);
}
else if(className=="QSplitter")
{
setQSplitterProperties(value,engine);
}
else if(className=="QTableView")
{
if(object->property("tabletype").isValid())
{
if(object->property("tabletype").toString()=="SaltTable")
{
setSaltTableProperties(value,engine);
}
}
}
else if(className=="QVBoxLayout")
{
setQBoxLayoutProperties(value,engine);
}
else if(className=="QWidget")
{
setQWidgetProperties(value,engine);
}
else if(className=="ScriptQMainWindow")
{
setQMainWindowProperties(value,engine);
}
else if(className=="SqlComboBox")
{
setSqlComboBoxProperties(value,engine);
}
else if(className=="SqlQueryView")
{
setSqlQueryViewProperties(value,engine);
}
else if(className=="ZoomLog")
{
setZoomLogProperties(value,engine);
}
else if(className=="QTextEdit")
{
setQTextEditProperties(value,engine);
}
else if(className=="QWebView")
{
setQWebViewProperties(value,engine);
}
else if(className=="QLineEdit")
{
setQLineEditProperties(value,engine);
}
else if(className=="QSvgWidget")
{
setQSvgWidgetProperties(value,engine);
}
else if(className=="QTabBar")
{
setQTabBarProperties(value,engine);
}
else if(className=="PrinterSelector")
{
setQComboBoxProperties(value,engine);
}

/*:281*/
#line 6544 "./typica.w"

}
return value;
}

/*:280*//*283:*/
#line 6692 "./typica.w"

QScriptValue SaltTable_columnSum(QScriptContext*context,QScriptEngine*engine)
{
QTableView*self= getself<QTableView*> (context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
QString datum;
double total= 0.0;
int column= argument<int> (0,context);
int role= argument<int> (1,context);
for(int i= 0;i<model->rowCount();i++)
{
datum= model->data(model->index(i,column),role).toString();
if(!datum.isEmpty())
{
total+= datum.toDouble();
}
}
return QScriptValue(engine,total);
}

/*:283*//*284:*/
#line 6716 "./typica.w"

QScriptValue SaltTable_columnArray(QScriptContext*context,
QScriptEngine*engine)
{
QTableView*self= getself<QTableView*> (context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
int column= argument<int> (0,context);
int role= argument<int> (1,context);
QString literal= model->arrayLiteral(column,role);
return QScriptValue(engine,literal);
}

QScriptValue SaltTable_quotedColumnArray(QScriptContext*context,
QScriptEngine*engine)
{
QTableView*self= getself<QTableView*> (context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
int column= argument<int> (0,context);
int role= argument<int> (1,context);
QString literal= model->quotedArrayLiteral(column,role);
return QScriptValue(engine,literal);
}

QScriptValue SaltTable_bindableColumnArray(QScriptContext*context,
QScriptEngine*engine)
{
QTableView*self= getself<QTableView*> (context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
int column= argument<int> (0,context);
int role= argument<int> (1,context);
QString literal= model->arrayLiteral(column,role);
literal.chop(1);
literal= literal.remove(0,1);
return QScriptValue(engine,literal);
}

QScriptValue SaltTable_bindableQuotedColumnArray(QScriptContext*context,
QScriptEngine*engine)
{
QTableView*self= getself<QTableView*> (context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
int column= argument<int> (0,context);
int role= argument<int> (1,context);
QString literal= model->quotedArrayLiteral(column,role);
literal.chop(1);
literal= literal.remove(0,1);
return QScriptValue(engine,literal);
}

/*:284*//*285:*/
#line 6768 "./typica.w"

QScriptValue SaltTable_model(QScriptContext*context,QScriptEngine*engine)
{
QTableView*self= getself<QTableView*> (context);
QScriptValue value= engine->newQObject(self->model());
return value;
}

/*:285*//*286:*/
#line 6782 "./typica.w"

QScriptValue SaltTable_setData(QScriptContext*context,QScriptEngine*)
{
QTableView*self= getself<QTableView*> (context);
int row= argument<int> (0,context);
int column= argument<int> (1,context);
QVariant value= argument<QVariant> (2,context);
int role= argument<int> (3,context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
QModelIndex cell= model->index(row,column);
model->setData(cell,value,role);
self->update(cell);
return QScriptValue();
}

/*:286*//*287:*/
#line 6800 "./typica.w"

QScriptValue SaltTable_data(QScriptContext*context,QScriptEngine*engine)
{
QTableView*self= getself<QTableView*> (context);
int row= argument<int> (0,context);
int column= argument<int> (1,context);
int role= argument<int> (2,context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
QModelIndex cell= model->index(row,column);
QVariant value= model->data(cell,role);
QScriptValue retval= engine->newVariant(value);
retval.setProperty("value",QScriptValue(value.toString()));
return retval;
}

/*:287*//*288:*/
#line 6820 "./typica.w"

QScriptValue SaltTable_clear(QScriptContext*context,QScriptEngine*)
{
QTableView*self= getself<QTableView*> (context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
model->clear();
return QScriptValue();
}

/*:288*//*289:*/
#line 6832 "./typica.w"

QScriptValue SaltTable_removeRow(QScriptContext*context,QScriptEngine*engine)
{
QTableView*self= getself<QTableView*> (context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
int row= argument<int> (0,context);
return engine->newVariant(model->removeRow(row));
}

/*:289*//*290:*/
#line 6845 "./typica.w"

QScriptValue SaltTable_findData(QScriptContext*context,QScriptEngine*engine)
{
QTableView*self= getself<QTableView*> (context);
SaltModel*model= qobject_cast<SaltModel*> (self->model());
QVariant value= argument<QVariant> (0,context);
int column= argument<int> (1,context);
return engine->newVariant(model->findData(value,column));
}

/*:290*//*291:*/
#line 6858 "./typica.w"

void setSaltTableProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
value.setProperty("columnArray",
engine->newFunction(SaltTable_columnArray));
value.setProperty("quotedColumnArray",
engine->newFunction(SaltTable_quotedColumnArray));
value.setProperty("bindableColumnArray",
engine->newFunction(SaltTable_bindableColumnArray));
value.setProperty("bindableQuotedColumnArray",
engine->newFunction(SaltTable_bindableQuotedColumnArray));
value.setProperty("columnSum",engine->newFunction(SaltTable_columnSum));
value.setProperty("data",engine->newFunction(SaltTable_data));
value.setProperty("model",engine->newFunction(SaltTable_model));
value.setProperty("setData",engine->newFunction(SaltTable_setData));
value.setProperty("clear",engine->newFunction(SaltTable_clear));
value.setProperty("removeRow",engine->newFunction(SaltTable_removeRow));
value.setProperty("findData",engine->newFunction(SaltTable_findData));
}

/*:291*//*293:*/
#line 6895 "./typica.w"

void setSqlComboBoxProperties(QScriptValue value,QScriptEngine*engine)
{
setQComboBoxProperties(value,engine);
}

void setQComboBoxProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
value.setProperty("currentData",
engine->newFunction(QComboBox_currentData));
value.setProperty("addItem",engine->newFunction(QComboBox_addItem));
value.setProperty("setModel",engine->newFunction(QComboBox_setModel));
value.setProperty("findText",engine->newFunction(QComboBox_findText));
value.setProperty("findData",engine->newFunction(QComboBox_findData));
}

QScriptValue QComboBox_currentData(QScriptContext*context,
QScriptEngine*engine)
{
QComboBox*self= getself<QComboBox*> (context);
return QScriptValue(engine,
self->itemData(self->currentIndex()).toString());
}

QScriptValue QComboBox_addItem(QScriptContext*context,QScriptEngine*)
{
QComboBox*self= getself<QComboBox*> (context);
self->addItem(argument<QString> (0,context));
return QScriptValue();
}

QScriptValue QComboBox_setModel(QScriptContext*context,QScriptEngine*)
{
QComboBox*self= getself<QComboBox*> (context);
self->setModel(argument<QAbstractItemModel*> (0,context));
return QScriptValue();
}

QScriptValue QComboBox_findText(QScriptContext*context,QScriptEngine*engine)
{
QComboBox*self= getself<QComboBox*> (context);
return QScriptValue(engine,self->findText(argument<QString> (0,context)));
}

QScriptValue QComboBox_findData(QScriptContext*context,QScriptEngine*engine)
{
QComboBox*self= getself<QComboBox*> (context);
return QScriptValue(engine,self->findData(argument<QVariant> (0,context)));
}

#line 1 "./abouttypica.w"
/*:293*//*306:*/
#line 401 "./units.w"

QScriptValue Units_convertTemperature(QScriptContext*context,QScriptEngine*)
{
return QScriptValue(Units::convertTemperature(argument<double> (0,context),
argument<Units::Unit> (1,context),
argument<Units::Unit> (2,context)));
}

QScriptValue Units_convertRelativeTemperature(QScriptContext*context,
QScriptEngine*)
{
return QScriptValue(Units::convertRelativeTemperature(
argument<double> (0,context),
argument<Units::Unit> (1,context),
argument<Units::Unit> (2,context)));
}

QScriptValue Units_isTemperatureUnit(QScriptContext*context,QScriptEngine*)
{
return QScriptValue(Units::isTemperatureUnit(argument<Units::Unit> (0,context)));
}

QScriptValue Units_convertWeight(QScriptContext*context,QScriptEngine*)
{
return QScriptValue(Units::convertWeight(argument<double> (0,context),
argument<Units::Unit> (1,context),
argument<Units::Unit> (2,context)));
}

QScriptValue Units_isWeightUnit(QScriptContext*context,QScriptEngine*)
{
return QScriptValue(Units::isWeightUnit(argument<Units::Unit> (0,context)));
}

/*:306*//*309:*/
#line 449 "./units.w"

QScriptValue Unit_toScriptValue(QScriptEngine*engine,const Units::Unit&value)
{
return engine->newVariant(QVariant(value));
}

void Unit_fromScriptValue(const QScriptValue&sv,Units::Unit&value)
{
value= sv.toVariant().value<Units::Unit> ();
}

/*:309*//*319:*/
#line 149 "./measurement.w"

QScriptValue constructMeasurement(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==2||context->argumentCount()==3)
{
double measurement= argument<double> (0,context);
QTime timestamp= argument<QTime> (1,context);
Units::Unit unit= Units::Fahrenheit;
if(context->argumentCount()==3)
{
unit= argument<Units::Unit> (2,context);
}
object= engine->toScriptValue<Measurement> (Measurement(measurement,timestamp,unit));
setMeasurementProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"Measurement::Measurement(). This method takes two "
"or three arguments.");
}
return object;
}

/*:319*//*320:*/
#line 176 "./measurement.w"

void setMeasurementProperties(QScriptValue,QScriptEngine*)
{

}

/*:320*//*321:*/
#line 184 "./measurement.w"

QScriptValue Measurement_toScriptValue(QScriptEngine*engine,const Measurement&measurement)
{
QVariant var;
var.setValue(measurement);
return engine->newVariant(var);
}

void Measurement_fromScriptValue(const QScriptValue&value,Measurement&measurement)
{
measurement= value.toVariant().value<Measurement> ();
}
#line 6964 "./typica.w"

/*:321*//*339:*/
#line 7542 "./typica.w"

QScriptValue constructDAQ(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==1)
{
object= engine->newQObject(new DAQ(argument<QString> (0,context)),
QScriptEngine::ScriptOwnership);
setDAQProperties(object,engine);
}
else if(context->argumentCount()==2)
{
object= engine->newQObject(new DAQ(argument<QString> (0,context),
argument<QString> (1,context)),
QScriptEngine::ScriptOwnership);
setDAQProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to DAQ"
"constructor. The DAQ constructor takes one"
"string as an argument specifying a device name."
"Example: Dev1");
}
return object;
}

/*:339*//*340:*/
#line 7572 "./typica.w"

void setDAQProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
value.setProperty("newChannel",engine->newFunction(DAQ_newChannel));
}

/*:340*//*341:*/
#line 7582 "./typica.w"

QScriptValue DAQ_newChannel(QScriptContext*context,QScriptEngine*engine)
{
DAQ*self= getself<DAQ*> (context);
QScriptValue object;
if(self)
{
object= 
engine->newQObject(self->newChannel(argument<int> (0,context),
argument<int> (1,context)));
setChannelProperties(object,engine);
}
return object;
}

/*:341*//*348:*/
#line 7738 "./typica.w"

QScriptValue constructFakeDAQ(QScriptContext*context,
QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==1)
{
object= 
engine->newQObject(new FakeDAQ(argument<QString> (0,context)),
QScriptEngine::ScriptOwnership);
setFakeDAQProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to DAQ"
"constructor. The DAQ constructor takes one"
"string as an argument specifying a device name."
"Example: Dev1");
}
return object;
}

void setFakeDAQProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
value.setProperty("newChannel",engine->newFunction(FakeDAQ_newChannel));
}

QScriptValue FakeDAQ_newChannel(QScriptContext*context,QScriptEngine*engine)
{
FakeDAQ*self= getself<FakeDAQ*> (context);
QScriptValue object;
if(self)
{
object= 
engine->newQObject(self->newChannel(argument<int> (0,context),
argument<int> (1,context)));
setChannelProperties(object,engine);
}
return object;
}

/*:348*//*352:*/
#line 7829 "./typica.w"

void setChannelProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}

/*:352*//*359:*/
#line 8021 "./typica.w"

QScriptValue constructLinearCalibrator(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new LinearCalibrator(NULL));
setLinearCalibratorProperties(object,engine);
return object;
}

void setLinearCalibratorProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}

/*:359*//*364:*/
#line 8159 "./typica.w"

QScriptValue constructLinearSplineInterpolator(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new LinearSplineInterpolator(NULL));
setLinearSplineInterpolatorProperties(object,engine);
return object;
}

void setLinearSplineInterpolatorProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}


/*:364*//*374:*/
#line 8368 "./typica.w"

QScriptValue constructTemperatureDisplay(QScriptContext*,
QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new TemperatureDisplay);
setTemperatureDisplayProperties(object,engine);
return object;
}

void setTemperatureDisplayProperties(QScriptValue value,QScriptEngine*engine)
{
setQLCDNumberProperties(value,engine);
value.setProperty("setDisplayUnits",
engine->newFunction(TemperatureDisplay_setDisplayUnits));
}

/*:374*//*375:*/
#line 8392 "./typica.w"

QScriptValue TemperatureDisplay_setDisplayUnits(QScriptContext*context,QScriptEngine*)
{
TemperatureDisplay*self= getself<TemperatureDisplay*> (context);
self->setDisplayUnits((Units::Unit)argument<int> (0,context));
return QScriptValue();
}

/*:375*//*382:*/
#line 8529 "./typica.w"

QScriptValue constructMeasurementTimeOffset(QScriptContext*,
QScriptEngine*engine)
{
QScriptValue object= 
engine->newQObject(new MeasurementTimeOffset(QTime::currentTime()));
setMeasurementTimeOffsetProperties(object,engine);
return object;
}

void setMeasurementTimeOffsetProperties(QScriptValue value,
QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}

/*:382*//*387:*/
#line 8648 "./typica.w"

QScriptValue constructThresholdDetector(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new ThresholdDetector(300));
return object;
}

void setThresholdDetectorProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}

/*:387*//*392:*/
#line 8745 "./typica.w"

QScriptValue constructZeroEmitter(QScriptContext*context,
QScriptEngine*engine)
{
QScriptValue object= 
engine->newQObject(new ZeroEmitter(argument<int> (0,context)));
setZeroEmitterProperties(object,engine);
return object;
}

void setZeroEmitterProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}

/*:392*//*397:*/
#line 8825 "./typica.w"

QScriptValue constructMeasurementAdapter(QScriptContext*context,
QScriptEngine*engine)
{
QScriptValue object= 
engine->newQObject(new MeasurementAdapter(argument<int> (0,context)));
setMeasurementAdapterProperties(object,engine);
return object;
}

void setMeasurementAdapterProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}

/*:397*//*414:*/
#line 9287 "./typica.w"

QScriptValue constructGraphView(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new GraphView);
setGraphViewProperties(object,engine);
return object;
}

void setGraphViewProperties(QScriptValue value,QScriptEngine*engine)
{
setQGraphicsViewProperties(value,engine);
}

/*:414*//*437:*/
#line 9937 "./typica.w"

QScriptValue constructZoomLog(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new ZoomLog);
setZoomLogProperties(object,engine);
return object;
}

void setZoomLogProperties(QScriptValue value,QScriptEngine*engine)
{
setQTableViewProperties(value,engine);
value.setProperty("saveXML",engine->newFunction(ZoomLog_saveXML));
value.setProperty("saveCSV",engine->newFunction(ZoomLog_saveCSV));
value.setProperty("saveState",engine->newFunction(ZoomLog_saveState));
value.setProperty("restoreState",
engine->newFunction(ZoomLog_restoreState));
value.setProperty("lastTime",engine->newFunction(ZoomLog_lastTime));
value.setProperty("saveTemporary",
engine->newFunction(ZoomLog_saveTemporary));
value.setProperty("setDisplayUnits",engine->newFunction(ZoomLog_setDisplayUnits));
}

/*:437*//*438:*/
#line 9964 "./typica.w"

QScriptValue ZoomLog_saveXML(QScriptContext*context,QScriptEngine*engine)
{
ZoomLog*self= getself<ZoomLog*> (context);
bool retval= self->saveXML(argument<QIODevice*> (0,context));
return QScriptValue(engine,retval);
}

QScriptValue ZoomLog_saveCSV(QScriptContext*context,QScriptEngine*engine)
{
ZoomLog*self= getself<ZoomLog*> (context);
bool retval= self->saveCSV(argument<QIODevice*> (0,context));
return QScriptValue(engine,retval);
}

QScriptValue ZoomLog_saveTemporary(QScriptContext*context,
QScriptEngine*engine)
{
ZoomLog*self= getself<ZoomLog*> (context);
QString filename= QDir::tempPath();
filename.append("/");
filename.append(QUuid::createUuid().toString());
filename.append(".xml");
QFile*file= new QFile(filename);
self->saveXML(file);
file->close();
delete file;
return QScriptValue(engine,filename);
}

/*:438*//*439:*/
#line 10012 "./typica.w"

QScriptValue ZoomLog_saveState(QScriptContext*context,QScriptEngine*)
{
ZoomLog*self= getself<ZoomLog*> (context);
QString key= argument<QString> (0,context);
int columns= argument<int> (1,context);
QSettings settings;
for(int i= 0;i<columns;i++)
{
if(self->columnWidth(i))
{
settings.beginGroup(key);
settings.setValue(QString("%1").arg(i),self->columnWidth(i));
settings.endGroup();
}
}
return QScriptValue();
}

QScriptValue ZoomLog_restoreState(QScriptContext*context,QScriptEngine*)
{
ZoomLog*self= getself<ZoomLog*> (context);
QString key= argument<QString> (0,context);
int columns= argument<int> (1,context);
QSettings settings;
for(int i= 0;i<columns;i++)
{
settings.beginGroup(key);
self->setColumnWidth(i,
settings.value(QString("%1").arg(i),80).toInt());
if(settings.value(QString("%1").arg(i),80).toInt()==0)
{
self->setColumnWidth(i,80);
}
settings.endGroup();
}
return QScriptValue();
}

QScriptValue ZoomLog_lastTime(QScriptContext*context,QScriptEngine*engine)
{
ZoomLog*self= getself<ZoomLog*> (context);
return QScriptValue(engine,self->lastTime(argument<int> (0,context)));
}

/*:439*//*440:*/
#line 10065 "./typica.w"

QScriptValue ZoomLog_setDisplayUnits(QScriptContext*context,QScriptEngine*)
{
ZoomLog*self= getself<ZoomLog*> (context);
self->setDisplayUnits((Units::Unit)argument<int> (0,context));
return QScriptValue();
}

/*:440*//*477:*/
#line 10940 "./typica.w"

QScriptValue constructAnnotationButton(QScriptContext*context,
QScriptEngine*engine)
{
QScriptValue object= 
engine->newQObject(new AnnotationButton(argument<QString> (0,context)));
setAnnotationButtonProperties(object,engine);
return object;
}

void setAnnotationButtonProperties(QScriptValue value,QScriptEngine*engine)
{
setQPushButtonProperties(value,engine);
}

/*:477*//*485:*/
#line 11083 "./typica.w"

QScriptValue constructAnnotationSpinBox(QScriptContext*context,
QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new AnnotationSpinBox(
argument<QString> (0,context),argument<QString> (1,context)));
setAnnotationSpinBoxProperties(object,engine);
return object;
}

void setAnnotationSpinBoxProperties(QScriptValue value,QScriptEngine*engine)
{
setQDoubleSpinBoxProperties(value,engine);
}

void setQDoubleSpinBoxProperties(QScriptValue value,QScriptEngine*engine)
{
setQAbstractSpinBoxProperties(value,engine);
}

void setQAbstractSpinBoxProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
}

/*:485*//*506:*/
#line 11506 "./typica.w"

QScriptValue constructTimerDisplay(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new TimerDisplay);
setTimerDisplayProperties(object,engine);
return object;
}

void setTimerDisplayProperties(QScriptValue value,QScriptEngine*engine)
{
setQLCDNumberProperties(value,engine);
value.setProperty("setTimerMode",engine->newFunction(TimerDisplay_setTimerMode));
}

/*:506*//*507:*/
#line 11525 "./typica.w"

QScriptValue TimerDisplay_setTimerMode(QScriptContext*context,QScriptEngine*)
{
TimerDisplay*self= getself<TimerDisplay*> (context);
if(self)
{
switch(argument<int> (0,context))
{
case 0:
self->setMode(TimerDisplay::CountUp);
break;
case 1:
self->setMode(TimerDisplay::CountDown);
break;
case 2:
self->setMode(TimerDisplay::Clock);
break;
default:
break;
}
}
return QScriptValue();
}


/*:507*//*534:*/
#line 12031 "./typica.w"

QScriptValue constructWidgetDecorator(QScriptContext*context,
QScriptEngine*engine)
{
QWidget*widget= argument<QWidget*> (0,context);
QString text= argument<QString> (1,context);
Qt::Orientations orientation;
switch(argument<int> (2,context))
{
case 2:
orientation= Qt::Vertical;
break;
default:
orientation= Qt::Horizontal;
break;
}
QScriptValue object= 
engine->newQObject(new WidgetDecorator(widget,text,orientation));
setWidgetDecoratorProperties(object,engine);
return object;
}

void setWidgetDecoratorProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
}

/*:534*//*547:*/
#line 12312 "./typica.w"

QScriptValue constructLogEditWindow(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new LogEditWindow);
return object;
}

/*:547*//*566:*/
#line 12839 "./typica.w"

QScriptValue constructXMLInput(QScriptContext*context,QScriptEngine*engine)
{
QIODevice*device= argument<QIODevice*> (0,context);
QScriptValue object= engine->newQObject(new XMLInput(&*device,
argument<int> (1,context)));
object.setProperty("input",engine->newFunction(XMLInput_input));
return object;
}

QScriptValue XMLInput_input(QScriptContext*context,QScriptEngine*)
{
XMLInput*self= getself<XMLInput*> (context);
self->input();
return QScriptValue();
}

/*:566*//*581:*/
#line 172 "./webview.w"

QScriptValue constructWebView(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new TypicaWebView);
setQWebViewProperties(object,engine);
return object;
}

void setQWebViewProperties(QScriptValue value,QScriptEngine*engine)
{
setQWidgetProperties(value,engine);
}

/*:581*//*582:*/
#line 189 "./webview.w"

void addWebViewToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
TypicaWebView*view= new TypicaWebView;
int stretch= 0;
if(element.hasAttribute("id"))
{
view->setObjectName(element.attribute("id"));
}
if(element.hasAttribute("stretch"))
{
stretch= element.attribute("stretch").toInt();
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(view,stretch);
}

/*:582*//*587:*/
#line 245 "./webview.w"

QScriptValue QWebElement_toScriptValue(QScriptEngine*engine,const QWebElement&element)
{
QVariant var;
var.setValue(element);
QScriptValue object= engine->newVariant(var);
return object;
}

void QWebElement_fromScriptValue(const QScriptValue&value,QWebElement&element)
{
element= value.toVariant().value<QWebElement> ();
}

/*:587*//*592:*/
#line 310 "./webview.w"

template<> QWebElement argument(int arg,QScriptContext*context)
{
return qscriptvalue_cast<QWebElement> (context->argument(arg));
}

/*:592*//*593:*/
#line 319 "./webview.w"

QScriptValue constructWebElement(QScriptContext*context,
QScriptEngine*engine)
{
QWebElement element= argument<QWebElement> (0,context);
QScriptValue object= engine->newQObject(new TypicaWebElement(element));
return object;
}

/*:593*//*604:*/
#line 85 "./printerselector.w"

QScriptValue constructPrinterSelector(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new PrinterSelector);
setQComboBoxProperties(object,engine);
return object;
}

/*:604*//*605:*/
#line 96 "./printerselector.w"

void addPrinterSelectorToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
PrinterSelector*selector= new PrinterSelector;
if(element.hasAttribute("id"))
{
selector->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(selector);
}

/*:605*//*618:*/
#line 13203 "./typica.w"

QScriptValue Application_subscribe(QScriptContext*context,
QScriptEngine*engine)
{
return engine->newQObject(
AppInstance->subscribe(argument<QString> (0,context)));
}

/*:618*//*677:*/
#line 14345 "./typica.w"

QScriptValue constructSqlQueryView(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new SqlQueryView);
setSqlQueryViewProperties(object,engine);
return object;
}

void setSqlQueryViewProperties(QScriptValue value,QScriptEngine*engine)
{
setQTableViewProperties(value,engine);
value.setProperty("setHeaderData",
engine->newFunction(SqlQueryView_setHeaderData));
value.setProperty("setQuery",engine->newFunction(SqlQueryView_setQuery));
value.setProperty("rows",engine->newFunction(SqlQueryView_rows));
}

/*:677*//*678:*/
#line 14364 "./typica.w"

QScriptValue SqlQueryView_setQuery(QScriptContext*context,QScriptEngine*)
{
SqlQueryView*self= getself<SqlQueryView*> (context);
QString query= argument<QString> (0,context);
self->setQuery(query);
self->reset();
return QScriptValue();
}

QScriptValue SqlQueryView_setHeaderData(QScriptContext*context,
QScriptEngine*)
{
SqlQueryView*self= getself<SqlQueryView*> (context);
int section= argument<int> (0,context);
QString data= argument<QString> (1,context);
self->setHeaderData(section,Qt::Horizontal,data,Qt::DisplayRole);
return QScriptValue();
}

QScriptValue SqlQueryView_rows(QScriptContext*context,QScriptEngine*)
{
SqlQueryView*self= getself<SqlQueryView*> (context);
return QScriptValue(self->model()->rowCount());
}

/*:678*//*686:*/
#line 14579 "./typica.w"

void addReportToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
QTextEdit*widget= new QTextEdit;
if(element.hasAttribute("id"))
{
widget->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(widget);
QTextDocument*document= new QTextDocument;
QFont defaultFont;
defaultFont.setPointSize(11);
document->setDefaultFont(defaultFont);
QTextCursor cursor(document);
/*687:*/
#line 14602 "./typica.w"

QDomNodeList children= element.childNodes();
for(int i= 0;i<children.count();i++)
{
QDomNode current;
QDomElement currentElement;
current= children.at(i);
if(current.isElement())
{
currentElement= current.toElement();
/*688:*/
#line 14619 "./typica.w"

if(currentElement.tagName()=="style")
{
document->setDefaultStyleSheet(currentElement.text());
}

/*:688*//*689:*/
#line 14630 "./typica.w"

if(currentElement.tagName()=="html")
{
cursor.insertHtml(currentElement.text());
}

/*:689*//*690:*/
#line 14640 "./typica.w"

if(currentElement.tagName()=="text")
{
cursor.insertText(currentElement.text());
}

/*:690*//*691:*/
#line 14650 "./typica.w"

if(currentElement.tagName()=="table")
{
QTextFrame*frame= cursor.insertFrame(QTextFrameFormat());
ReportTable*table= new ReportTable(frame,currentElement);
table->setParent(widget);
if(currentElement.hasAttribute("id"))
{
table->setObjectName(currentElement.attribute("id"));
}
}

/*:691*/
#line 14612 "./typica.w"

}
}

/*:687*/
#line 14595 "./typica.w"

widget->setDocument(document);
}

/*:686*//*702:*/
#line 14863 "./typica.w"

QScriptValue QTextEdit_print(QScriptContext*context,QScriptEngine*)
{
QTextEdit*self= getself<QTextEdit*> (context);
QTextDocument*document= self->document();
QPrinter printer;

QPrintDialog printwindow(&printer,self);
if(printwindow.exec()!=QDialog::Accepted)
{
return QScriptValue();
}
document->print(&printer);
return QScriptValue();
}

/*:702*//*703:*/
#line 14881 "./typica.w"

void setQTextEditProperties(QScriptValue value,QScriptEngine*engine)
{
setQAbstractScrollAreaProperties(value,engine);
value.setProperty("print",engine->newFunction(QTextEdit_print));
}

#line 1 "./plugins.w"
/*:703*//*728:*/
#line 461 "./daterangeselector.w"

void addDateRangeToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
DateRangeSelector*widget= new DateRangeSelector;
if(element.hasAttribute("id"))
{
widget->setObjectName(element.attribute("id"));
}
if(element.hasAttribute("initial"))
{
widget->setCurrentIndex(element.attribute("initial").toInt());
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(widget);
}

/*:728*//*739:*/
#line 15063 "./typica.w"

void addFormArrayToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
FormArray*widget= new FormArray(element);
if(element.hasAttribute("id"))
{
widget->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(widget);
}

/*:739*//*760:*/
#line 15650 "./typica.w"

void addScaleControlToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
ScaleControl*scale= new ScaleControl;
if(element.hasAttribute("id"))
{
scale->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(scale);
}

void addIntensityControlToLayout(QDomElement element,QStack<QWidget*> *,
QStack<QLayout*> *layoutStack)
{
IntensityControl*scale= new IntensityControl;
if(element.hasAttribute("id"))
{
scale->setObjectName(element.attribute("id"));
}
QBoxLayout*layout= qobject_cast<QBoxLayout*> (layoutStack->top());
layout->addWidget(scale);
}



/*:760*//*786:*/
#line 16240 "./typica.w"

QScriptValue constructDeviceTreeModel(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new DeviceTreeModel);
setDeviceTreeModelProperties(object,engine);
return object;
}

/*:786*//*788:*/
#line 16263 "./typica.w"

void setDeviceTreeModelProperties(QScriptValue value,QScriptEngine*engine)
{
setQAbstractItemModelProperties(value,engine);
value.setProperty("referenceElement",
engine->newFunction(DeviceTreeModel_referenceElement));
}

void setQAbstractItemModelProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
value.setProperty("data",engine->newFunction(QAbstractItemModel_data));
value.setProperty("index",engine->newFunction(QAbstractItemModel_index));
value.setProperty("rowCount",engine->newFunction(QAbstractItemModel_rowCount));
value.setProperty("hasChildren",engine->newFunction(QAbstractItemModel_hasChildren));
}

/*:788*//*789:*/
#line 16290 "./typica.w"

QScriptValue DeviceTreeModel_referenceElement(QScriptContext*context,
QScriptEngine*engine)
{
DeviceTreeModel*model= getself<DeviceTreeModel*> (context);
QDomElement referenceElement= model->referenceElement(argument<QString> (0,context));
QDomNodeList configData= referenceElement.elementsByTagName("attribute");
QDomElement node;
QVariantMap retval;
retval.insert("driver",referenceElement.attribute("driver"));
for(int i= 0;i<configData.size();i++)
{
node= configData.at(i).toElement();
retval.insert(node.attribute("name"),node.attribute("value"));
}
return engine->toScriptValue(retval);
}

QScriptValue QAbstractItemModel_data(QScriptContext*context,QScriptEngine*engine)
{
QAbstractItemModel*model= getself<QAbstractItemModel*> (context);
QModelIndex index= argument<QModelIndex> (0,context);
int role= argument<int> (1,context);
return engine->toScriptValue(model->data(index,role));
}

QScriptValue QAbstractItemModel_index(QScriptContext*context,QScriptEngine*engine)
{
QAbstractItemModel*model= getself<QAbstractItemModel*> (context);
int row= 0;
int column= 0;
QModelIndex index;
if(context->argumentCount()> 1)
{
row= argument<int> (0,context);
column= argument<int> (1,context);
}
if(context->argumentCount()> 2)
{
index= argument<QModelIndex> (2,context);
}
QModelIndex retval= model->index(row,column,index);
return engine->toScriptValue(retval);
}

QScriptValue QAbstractItemModel_rowCount(QScriptContext*context,
QScriptEngine*)
{
QAbstractItemModel*model= getself<QAbstractItemModel*> (context);
QModelIndex index;
if(context->argumentCount()==1)
{
index= argument<QModelIndex> (0,context);
}
return QScriptValue(model->rowCount(index));
}

QScriptValue QAbstractItemModel_hasChildren(QScriptContext*context,
QScriptEngine*engine)
{
QAbstractItemModel*model= getself<QAbstractItemModel*> (context);
QModelIndex index;
if(context->argumentCount()==1)
{
index= argument<QModelIndex> (0,context);
}
return QScriptValue(engine,model->hasChildren(index));
}

/*:789*//*792:*/
#line 16374 "./typica.w"

QScriptValue QModelIndex_toScriptValue(QScriptEngine*engine,const QModelIndex&index)
{
QVariant var;
var.setValue(index);
QScriptValue object= engine->newVariant(var);
return object;
}

void QModelIndex_fromScriptValue(const QScriptValue&value,QModelIndex&index)
{
index= value.toVariant().value<QModelIndex> ();
}

/*:792*//*808:*/
#line 16672 "./typica.w"

QScriptValue constructDeviceConfigurationWindow(QScriptContext*,
QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new DeviceConfigurationWindow);
return object;
}

/*:808*//*879:*/
#line 49 "./settings.w"

QScriptValue constructSettingsWindow(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new SettingsWindow);
return object;
}

/*:879*//*908:*/
#line 19322 "./typica.w"

QScriptValue constructModbusRTUDevice(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==2)
{
object= engine->newQObject(new ModbusRTUDevice(argument<DeviceTreeModel*> (0,context),
argument<QModelIndex> (1,context)),
QScriptEngine::ScriptOwnership);
setModbusRTUDeviceProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"ModbusRTUDevice constructor. This takes the configuration model "
"and an index.");
}
return object;
}

/*:908*//*909:*/
#line 19344 "./typica.w"

QScriptValue ModbusRTUDevice_pVChannel(QScriptContext*context,QScriptEngine*engine)
{
ModbusRTUDevice*self= getself<ModbusRTUDevice*> (context);
QScriptValue object;
if(self)
{
if(self->channels.size()> 0)
{
object= engine->newQObject(self->channels.at(0));
setChannelProperties(object,engine);
}
}
return object;
}

QScriptValue ModbusRTUDevice_sVChannel(QScriptContext*context,QScriptEngine*engine)
{
ModbusRTUDevice*self= getself<ModbusRTUDevice*> (context);
QScriptValue object;
if(self)
{
if(self->channels.size()> 1)
{
object= engine->newQObject(self->channels.at(1));
setChannelProperties(object,engine);
}
}
return object;
}

/*:909*//*910:*/
#line 19377 "./typica.w"

void setModbusRTUDeviceProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
value.setProperty("pVChannel",engine->newFunction(ModbusRTUDevice_pVChannel));
value.setProperty("sVChannel",engine->newFunction(ModbusRTUDevice_sVChannel));
}

/*:910*//*926:*/
#line 713 "./modbus.w"

QScriptValue constructModbusNG(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==2)
{
object= engine->newQObject(new ModbusNG(argument<DeviceTreeModel*> (0,context),
argument<QModelIndex> (1,context)),
QScriptEngine::ScriptOwnership);
setModbusNGProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"ModbusNG constructor.");
}
return object;
}

void setModbusNGProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
value.setProperty("getChannel",engine->newFunction(ModbusNG_getChannel));
}

QScriptValue ModbusNG_getChannel(QScriptContext*context,QScriptEngine*engine)
{
ModbusNG*self= getself<ModbusNG*> (context);
QScriptValue object;
if(self)
{
object= engine->newQObject(self->getChannel(argument<int> (0,context)));
setChannelProperties(object,engine);
}
return object;
}
#line 19928 "./typica.w"

#line 1 "./unsupportedserial.w"
/*:926*//*940:*/
#line 360 "./unsupportedserial.w"

QScriptValue createDevice(QScriptContext*context,QScriptEngine*engine)
{
QModelIndex deviceIndex= argument<QModelIndex> (0,context);
JavaScriptDevice*device= new JavaScriptDevice(deviceIndex,engine);
QScriptValue object= engine->newQObject(device);
setQObjectProperties(object,engine);
object.setProperty("getChannel",engine->newFunction(JavaScriptDevice_getChannel));
return object;
}

/*:940*//*945:*/
#line 433 "./unsupportedserial.w"

QScriptValue JavaScriptDevice_getChannel(QScriptContext*context,QScriptEngine*engine)
{
JavaScriptDevice*self= getself<JavaScriptDevice*> (context);
QScriptValue object;
if(self)
{
object= engine->newQObject(self->getChannel(argument<int> (0,context)));
setChannelProperties(object,engine);
}
return object;
}

/*:945*//*952:*/
#line 633 "./unsupportedserial.w"

QScriptValue getMeasurementTimestamp(QScriptContext*,QScriptEngine*engine)
{
return engine->toScriptValue<QTime> (QTime::currentTime());
}

/*:952*//*956:*/
#line 670 "./unsupportedserial.w"

QScriptValue constructSerialPort(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new QextSerialPort());
setSerialPortProperties(object,engine);
return object;
}

/*:956*//*957:*/
#line 681 "./unsupportedserial.w"

void setSerialPortProperties(QScriptValue value,QScriptEngine*engine)
{
setQIODeviceProperties(value,engine);
value.setProperty("flush",engine->newFunction(SerialPort_flush));
}

/*:957*//*958:*/
#line 690 "./unsupportedserial.w"

QScriptValue SerialPort_flush(QScriptContext*context,QScriptEngine*)
{
QextSerialPort*self= getself<QextSerialPort*> (context);
self->flush();
return QScriptValue();
}





#line 19930 "./typica.w"

#line 1 "./phidgets.w"
/*:958*//*979:*/
#line 463 "./phidgets.w"

QScriptValue constructPhidgetsTemperatureSensor(QScriptContext*context,QScriptEngine*engine)
{
if(context->argumentCount()!=1)
{
context->throwError("Incorrect number of arguments passed to "
"PhidgetsTemperatureSensor constructor. This takes "
"a QModelIndex.");
}
QScriptValue object= engine->newQObject(new PhidgetsTemperatureSensor(argument<QModelIndex> (0,context)),QScriptEngine::ScriptOwnership);
setQObjectProperties(object,engine);
object.setProperty("getChannel",engine->newFunction(Phidgets_getChannel));
return object;
}

/*:979*//*980:*/
#line 480 "./phidgets.w"

QScriptValue Phidgets_getChannel(QScriptContext*context,QScriptEngine*engine)
{
PhidgetsTemperatureSensor*self= getself<PhidgetsTemperatureSensor*> (context);
QScriptValue object;
if(self)
{
object= engine->newQObject(self->getChannel(argument<int> (0,context)));
setChannelProperties(object,engine);
}
return object;
}
#line 19932 "./typica.w"

#line 1 "./phidget22.w"
/*:980*//*1011:*/
#line 811 "./phidget22.w"

QScriptValue constructPhidget22(QScriptContext*context,QScriptEngine*engine)
{
if(context->argumentCount()!=1)
{
context->throwError("Incorrect number of arguments");
}
QScriptValue object= engine->newQObject(new Phidget22(argument<QModelIndex> (0,context)),QScriptEngine::ScriptOwnership);
setQObjectProperties(object,engine);
object.setProperty("getChannel",engine->newFunction(Phidget22_getChannel));
return object;
}

/*:1011*//*1012:*/
#line 826 "./phidget22.w"

QScriptValue Phidget22_getChannel(QScriptContext*context,QScriptEngine*engine)
{
Phidget22*self= getself<Phidget22*> (context);
QScriptValue object;
if(self)
{
object= engine->newQObject(self->getChannel(argument<int> (0,context)));
setChannelProperties(object,engine);
}
return object;
}
#line 19934 "./typica.w"

/*:1012*//*1044:*/
#line 151 "./rate.w"

QScriptValue constructRateOfChange(QScriptContext*context,QScriptEngine*engine)
{
int cachetime= 1;
int scaletime= 1;
if(context->argumentCount()> 0)
{
cachetime= argument<int> (0,context);
if(context->argumentCount()> 1)
{
scaletime= argument<int> (1,context);
}
}
QScriptValue object= engine->newQObject(new RateOfChange(cachetime,scaletime));
setRateOfChangeProperties(object,engine);
return object;
}

void setRateOfChangeProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}

/*:1044*//*1058:*/
#line 148 "./mergeseries.w"

QScriptValue constructDifferenceSeries(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new DifferenceSeries);
setQObjectProperties(object,engine);
return object;
}

QScriptValue constructMeanSeries(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new MeanSeries);
setQObjectProperties(object,engine);
return object;
}

/*:1058*//*1083:*/
#line 614 "./dataqsdk.w"

QScriptValue constructDataqSdkDevice(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==1)
{
object= engine->newQObject(new DataqSdkDevice(argument<QString> (0,context)),
QScriptEngine::ScriptOwnership);
setDataqSdkDeviceProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"DataqSdkDevice. The constructor takes one string "
"as an argument specifying a device name. "
"Example: Dev1");
}
return object;
}

/*:1083*//*1084:*/
#line 637 "./dataqsdk.w"

void setDataqSdkDeviceProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
value.setProperty("newChannel",engine->newFunction(DataqSdkDevice_newChannel));
}

/*:1084*//*1085:*/
#line 647 "./dataqsdk.w"

QScriptValue DataqSdkDevice_newChannel(QScriptContext*context,QScriptEngine*engine)
{
DataqSdkDevice*self= getself<DataqSdkDevice*> (context);
QScriptValue object;
if(self)
{
object= engine->newQObject(self->newChannel((Units::Unit)argument<int> (0,context)));
setChannelProperties(object,engine);
}
return object;
}

/*:1085*//*1110:*/
#line 80 "./scales.w"

QScriptValue constructDragLabel(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
QString labelText= "";
if(context->argumentCount()==1)
{
labelText= argument<QString> (0,context);
}
object= engine->newQObject(new DragLabel(labelText));
setDragLabelProperties(object,engine);
return object;
}

void setDragLabelProperties(QScriptValue value,QScriptEngine*engine)
{
setQLabelProperties(value,engine);
}

/*:1110*//*1120:*/
#line 298 "./scales.w"

QScriptValue BaudRateType_toScriptValue(QScriptEngine*engine,const BaudRateType&value)
{
return engine->newVariant(QVariant((int)(value)));
}

void BaudRateType_fromScriptValue(const QScriptValue&sv,BaudRateType&value)
{
value= (BaudRateType)(sv.toVariant().toInt());
}

QScriptValue DataBitsType_toScriptValue(QScriptEngine*engine,const DataBitsType&value)
{
return engine->newVariant(QVariant((int)(value)));
}

void DataBitsType_fromScriptValue(const QScriptValue&sv,DataBitsType&value)
{
value= (DataBitsType)(sv.toVariant().toInt());
}

QScriptValue ParityType_toScriptValue(QScriptEngine*engine,const ParityType&value)
{
return engine->newVariant(QVariant((int)(value)));
}

void ParityType_fromScriptValue(const QScriptValue&sv,ParityType&value)
{
value= (ParityType)(sv.toVariant().toInt());
}

QScriptValue StopBitsType_toScriptValue(QScriptEngine*engine,const StopBitsType&value)
{
return engine->newVariant(QVariant((int)(value)));
}

void StopBitsType_fromScriptValue(const QScriptValue&sv,StopBitsType&value)
{
value= (StopBitsType)(sv.toVariant().toInt());
}

QScriptValue FlowType_toScriptValue(QScriptEngine*engine,const FlowType&value)
{
return engine->newVariant(QVariant((int)(value)));
}

void FlowType_fromScriptValue(const QScriptValue&sv,FlowType&value)
{
value= (FlowType)(sv.toVariant().toInt());
}

/*:1120*//*1123:*/
#line 367 "./scales.w"

void setSerialScaleProperties(QScriptValue value,QScriptEngine*engine)
{
setQIODeviceProperties(value,engine);
}

/*:1123*//*1124:*/
#line 375 "./scales.w"

QScriptValue constructSerialScale(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object;
if(context->argumentCount()==1)
{
object= engine->newQObject(new SerialScale(argument<QString> (0,context)));
setSerialScaleProperties(object,engine);
}
else
{
context->throwError("Incorrect number of arguments passed to "
"SerialScale. The constructor takes one string "
"as an argument specifying a port name.");
}
return object;
}

/*:1124*//*1146:*/
#line 278 "./valueannotation.w"

QScriptValue constructValueAnnotation(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new ValueAnnotation);
setValueAnnotationProperties(object,engine);
return object;
}

void setValueAnnotationProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}
#line 20598 "./typica.w"

#line 1 "./thresholdannotation.w"
/*:1146*//*1157:*/
#line 208 "./thresholdannotation.w"

QScriptValue constructAnnotator(QScriptContext*context,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new Annotator(argument<QString> (0,context)));
setAnnotatorProperties(object,engine);
return object;
}

void setAnnotatorProperties(QScriptValue value,QScriptEngine*engine)
{
setQObjectProperties(value,engine);
}

#line 20600 "./typica.w"

#line 1 "./user.w"
/*:1157*//*1167:*/
#line 142 "./user.w"

QScriptValue constructLoginDialog(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new LoginDialog);
return object;
}

/*:1167*//*1177:*/
#line 330 "./user.w"

QScriptValue constructNewTypicaUser(QScriptContext*,QScriptEngine*engine)
{
QScriptValue object= engine->newQObject(new NewTypicaUser);
return object;
}

/*:1177*/
#line 533 "./typica.w"

/*656:*/
#line 13962 "./typica.w"

void messageFileOutput(QtMsgType,const char*msg)
{
QFile output("Typica-"+QDate::currentDate().toString("yyyy-MM-dd")+".log");
output.open(QIODevice::WriteOnly|QIODevice::Append);
QTextStream outstream(&output);
outstream<<msg<<"\r\n";
}

/*:656*/
#line 534 "./typica.w"

/*653:*/
#line 13923 "./typica.w"

int main(int argc,char**argv)
{
int*c= &argc;
Application app(*c,argv);
QSettings settings;
/*654:*/
#line 13949 "./typica.w"

if(settings.value("settings/advanced/logging",false).toBool())
{
qInstallMsgHandler(messageFileOutput);
}

/*:654*/
#line 13929 "./typica.w"

/*657:*/
#line 13975 "./typica.w"

QStringList themeSearchPath= QIcon::themeSearchPaths();
themeSearchPath.append(":/resources/icons/tango");
QIcon::setThemeSearchPaths(themeSearchPath);
QIcon::setThemeName(":/resources/icons/tango");
app.setWindowIcon(QIcon(":/resources/icons/appicons/logo.svg"));

/*:657*/
#line 13930 "./typica.w"

/*658:*/
#line 13995 "./typica.w"

QFile entypo(":/resources/fonts/entypo.ttf");
entypo.open(QIODevice::ReadOnly);
QFontDatabase::addApplicationFontFromData(entypo.readAll());
entypo.close();
QFontDatabase::addApplicationFont(":/resources/fonts/texgyrepagella-regular.otf");
QFontDatabase::addApplicationFont(":/resources/fonts/texgyrepagella-bold.otf");
QFontDatabase::addApplicationFont(":/resources/fonts/texgyrepagella-bolditalic.otf");
QFontDatabase::addApplicationFont(":/resources/fonts/texgyrepagella-italic.otf");
QWebSettings::globalSettings()->setFontFamily(QWebSettings::StandardFont,"Tex Gyre Pagella");

/*:658*/
#line 13931 "./typica.w"


/*818:*/
#line 16962 "./typica.w"

app.registerDeviceConfigurationWidget("roaster",RoasterConfWidget::staticMetaObject);

/*:818*//*828:*/
#line 17204 "./typica.w"

app.registerDeviceConfigurationWidget("nidaqmxbase",
NiDaqMxBaseDriverConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("nidaqmxbase9211series",
NiDaqMxBase9211ConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("ni9211seriestc",
Ni9211TcConfWidget::staticMetaObject);

/*:828*//*836:*/
#line 17435 "./typica.w"

app.registerDeviceConfigurationWidget("nidaqmx",NiDaqMxDriverConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("nidaqmx9211series",NiDaqMx9211ConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("nidaqmxtc01",NiDaqMxTc01ConfWidget::staticMetaObject);

/*:836*//*860:*/
#line 18404 "./typica.w"

app.registerDeviceConfigurationWidget("modbusrtuport",ModbusRtuPortConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("modbusrtudevice",ModbusRtuDeviceConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("modbustemperaturepv",ModbusRtuDeviceTPvConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("modbustemperaturesv",ModbusRtuDeviceTSvConfWidget::staticMetaObject);

/*:860*//*865:*/
#line 18489 "./typica.w"

app.registerDeviceConfigurationWidget("annotationbutton",AnnotationButtonConfWidget::staticMetaObject);

/*:865*//*868:*/
#line 18560 "./typica.w"

app.registerDeviceConfigurationWidget("reconfigurablebutton",ReconfigurableAnnotationButtonConfWidget::staticMetaObject);

/*:868*//*871:*/
#line 18687 "./typica.w"

app.registerDeviceConfigurationWidget("annotationspinbox",NoteSpinConfWidget::staticMetaObject);

#line 1 "./freeannotation.w"
/*:871*//*875:*/
#line 57 "./freeannotation.w"

app.registerDeviceConfigurationWidget("freeannotation",
FreeAnnotationConfWidget::staticMetaObject);
#line 18691 "./typica.w"

#line 1 "./settings.w"
/*:875*//*913:*/
#line 19918 "./typica.w"

app.registerDeviceConfigurationWidget("modbusrtu",ModbusConfigurator::staticMetaObject);

/*:913*//*919:*/
#line 321 "./modbus.w"

app.registerDeviceConfigurationWidget("modbusngport",ModbusNGConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("modbusnginput",
ModbusNGInputConfWidget::staticMetaObject);

/*:919*//*935:*/
#line 267 "./unsupportedserial.w"

app.registerDeviceConfigurationWidget("unsupporteddevicechannel",
UnsupportedDeviceChannelConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("unsupporteddevice",
UnsupportedSerialDeviceConfWidget::staticMetaObject);

/*:935*//*966:*/
#line 181 "./phidgets.w"

app.registerDeviceConfigurationWidget("phidgets1048",
PhidgetsTemperatureSensorConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("phidgets1048channel",
PhidgetTemperatureSensorChannelConfWidget::staticMetaObject);

/*:966*//*982:*/
#line 35 "./phidget22.w"

app.registerDeviceConfigurationWidget("phidget22",
PhidgetConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("phidgetchannel",
PhidgetChannelConfWidget::staticMetaObject);

/*:982*//*1018:*/
#line 20056 "./typica.w"

app.registerDeviceConfigurationWidget("linearspline",LinearSplineInterpolationConfWidget::staticMetaObject);

/*:1018*//*1021:*/
#line 20116 "./typica.w"

app.registerDeviceConfigurationWidget("coolingtimer",
CoolingTimerConfWidget::staticMetaObject);

/*:1021*//*1026:*/
#line 20375 "./typica.w"

app.registerDeviceConfigurationWidget("rangetimer",
RangeTimerConfWidget::staticMetaObject);

/*:1026*//*1031:*/
#line 20476 "./typica.w"

app.registerDeviceConfigurationWidget("multirangetimer",
MultiRangeTimerConfWidget::staticMetaObject);

/*:1031*//*1036:*/
#line 20586 "./typica.w"

app.registerDeviceConfigurationWidget("translation",TranslationConfWidget::staticMetaObject);

#line 1 "./rate.w"
/*:1036*//*1048:*/
#line 253 "./rate.w"

app.registerDeviceConfigurationWidget("rate",RateOfChangeConfWidget::staticMetaObject);

/*:1048*//*1062:*/
#line 266 "./mergeseries.w"

app.registerDeviceConfigurationWidget("mergeseries",
MergeSeriesConfWidget::staticMetaObject);

/*:1062*//*1103:*/
#line 1233 "./dataqsdk.w"

app.registerDeviceConfigurationWidget("dataqsdk",DataqSdkDeviceConfWidget::staticMetaObject);
app.registerDeviceConfigurationWidget("dataqsdkchannel",
DataqSdkChannelConfWidget::staticMetaObject);

/*:1103*//*1128:*/
#line 552 "./scales.w"

app.registerDeviceConfigurationWidget("scale",SerialScaleConfWidget::staticMetaObject);

/*:1128*//*1136:*/
#line 138 "./valueannotation.w"

app.registerDeviceConfigurationWidget("valueannotation",
ValueAnnotationConfWidget::staticMetaObject);

/*:1136*//*1150:*/
#line 109 "./thresholdannotation.w"

app.registerDeviceConfigurationWidget("thresholdannotation",
ThresholdAnnotationConfWidget::staticMetaObject);

/*:1150*/
#line 13933 "./typica.w"

/*659:*/
#line 14012 "./typica.w"

if(settings.value("database/exists","false").toString()=="true")
{
/*664:*/
#line 14146 "./typica.w"

QSqlDatabase database= 
QSqlDatabase::addDatabase(settings.value("database/driver").toString());
database.setConnectOptions("application_name=Typica");
database.setHostName(settings.value("database/hostname").toString());
database.setPort(settings.value("database/portnumber",5432).toInt());
database.setDatabaseName(settings.value("database/dbname").toString());
database.setUserName(settings.value("database/user").toString());
database.setPassword(settings.value("database/password").toString());
if(!database.open())
{
settings.setValue("database/exists","false");
}
else
{
AppInstance->setDatabaseConnected(true);
}

/*:664*/
#line 14015 "./typica.w"

}
if(settings.value("database/exists","false").toString()=="false")
{
/*663:*/
#line 14137 "./typica.w"

SqlConnectionSetup dialog;
dialog.exec();

/*:663*/
#line 14019 "./typica.w"

}


/*:659*/
#line 13934 "./typica.w"

/*199:*/
#line 4503 "./typica.w"

QStringList arguments= QCoreApplication::arguments();
int position= arguments.indexOf("-c");
QString filename= QString();
if(position!=-1)
{
if(arguments.size()>=position+1)
{
filename= arguments.at(position+1);
}
}else{
QDir checkPath(QCoreApplication::applicationDirPath()+"/../config/");
if(checkPath.exists("config.xml")){
filename= checkPath.filePath("config.xml");
}else{
checkPath= QDir(QCoreApplication::applicationDirPath()+"/config/");
if(checkPath.exists("config.xml")){
filename= checkPath.filePath("config.xml");
}
}
}
if(filename.isEmpty())
{
filename= QFileDialog::getOpenFileName(NULL,"Open Configuration File",
settings.value("config","").toString());
}
QDir directory;
if(!filename.isEmpty())
{
QFile file(filename);
QFileInfo info(filename);
directory= info.dir();
QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
QTranslator*configtr= new QTranslator;
if(configtr->load(QString("config.%1").arg(QLocale::system().name()),
QString("%1/Translations").arg(directory.canonicalPath())))
{
QCoreApplication::installTranslator(configtr);
}
settings.setValue("config",directory.path());
if(file.open(QIODevice::ReadOnly))
{
app.configuration()->setContent(&file,true);
}
}else{
return 1;
}
/*200:*/
#line 4556 "./typica.w"

QDomElement root= app.configuration()->documentElement();
QDomNodeList children= root.childNodes();
QString replacementDoc;
QDomDocument includedDoc;
QDomDocumentFragment fragment;
for(int i= 0;i<children.size();i++)
{
QDomNode currentNode= children.at(i);
QDomElement currentElement;
if(currentNode.nodeName()=="include")
{
currentElement= currentNode.toElement();
if(currentElement.hasAttribute("src"))
{
replacementDoc= directory.path();
replacementDoc.append('/');
replacementDoc.append(currentElement.attribute("src"));
QFile doc(replacementDoc);
if(doc.open(QIODevice::ReadOnly))
{
includedDoc.setContent(&doc,true);
fragment= includedDoc.createDocumentFragment();
fragment.appendChild(includedDoc.documentElement());
root.replaceChild(fragment,currentNode);
doc.close();
}
}
}
}

/*:200*/
#line 4550 "./typica.w"


/*:199*/
#line 13935 "./typica.w"

/*7:*/
#line 667 "./typica.w"

QScriptEngine*engine= new QScriptEngine;
QScriptValue constructor;
QScriptValue value;

/*:7*//*17:*/
#line 875 "./typica.w"

constructor= engine->newFunction(constructQTimer);
value= engine->newQMetaObject(&QTimer::staticMetaObject,constructor);
engine->globalObject().setProperty("Timer",value);

/*:17*//*20:*/
#line 914 "./typica.w"

constructor= engine->newFunction(constructQWidget);
value= engine->newQMetaObject(&QWidget::staticMetaObject,constructor);
engine->globalObject().setProperty("QWidget",value);

/*:20*//*24:*/
#line 1002 "./typica.w"

constructor= engine->newFunction(displayWarning);
engine->globalObject().setProperty("displayWarning",constructor);
constructor= engine->newFunction(displayError);
engine->globalObject().setProperty("displayError",constructor);
constructor= engine->newFunction(displayInfo);
engine->globalObject().setProperty("displayInfo",constructor);

/*:24*//*34:*/
#line 1240 "./typica.w"

constructor= engine->newFunction(constructQMainWindow);
value= engine->newQMetaObject(&ScriptQMainWindow::staticMetaObject,
constructor);
engine->globalObject().setProperty("QMainWindow",value);

/*:34*//*45:*/
#line 1445 "./typica.w"

constructor= engine->newFunction(constructQFrame);
value= engine->newQMetaObject(&QFrame::staticMetaObject,constructor);
engine->globalObject().setProperty("QFrame",value);

/*:45*//*48:*/
#line 1478 "./typica.w"

constructor= engine->newFunction(constructQLabel);
value= engine->newQMetaObject(&QLabel::staticMetaObject,constructor);
engine->globalObject().setProperty("QLabel",value);

/*:48*//*51:*/
#line 1521 "./typica.w"

constructor= engine->newFunction(constructQSvgWidget);
value= engine->newQMetaObject(&QSvgWidget::staticMetaObject,constructor);
engine->globalObject().setProperty("QSvgWidget",value);

/*:51*//*57:*/
#line 1603 "./typica.w"

constructor= engine->newFunction(constructQLineEdit);
value= engine->newQMetaObject(&QLineEdit::staticMetaObject,constructor);
engine->globalObject().setProperty("QLineEdit",value);

/*:57*//*61:*/
#line 1652 "./typica.w"

constructor= engine->newFunction(constructQSplitter);
value= engine->newQMetaObject(&QSplitter::staticMetaObject,constructor);
engine->globalObject().setProperty("QSplitter",value);

/*:61*//*70:*/
#line 1861 "./typica.w"

constructor= engine->newFunction(constructQBoxLayout);
value= engine->newQMetaObject(&QBoxLayout::staticMetaObject,constructor);
engine->globalObject().setProperty("QBoxLayout",value);

/*:70*//*74:*/
#line 1973 "./typica.w"

constructor= engine->newFunction(constructQAction);
value= engine->newQMetaObject(&QAction::staticMetaObject,constructor);
engine->globalObject().setProperty("QAction",value);

/*:74*//*77:*/
#line 2032 "./typica.w"

value= engine->newQMetaObject(&QFileDialog::staticMetaObject);
value.setProperty("getOpenFileName",
engine->newFunction(QFileDialog_getOpenFileName));
value.setProperty("getSaveFileName",
engine->newFunction(QFileDialog_getSaveFileName));
engine->globalObject().setProperty("QFileDialog",value);

/*:77*//*82:*/
#line 2150 "./typica.w"

constructor= engine->newFunction(constructQFile);
value= engine->newQMetaObject(&QFile::staticMetaObject,constructor);
engine->globalObject().setProperty("QFile",value);

/*:82*//*93:*/
#line 2368 "./typica.w"

constructor= engine->newFunction(constructQProcess);
value= engine->newQMetaObject(&QProcess::staticMetaObject,constructor);
engine->globalObject().setProperty("QProcess",value);

/*:93*//*102:*/
#line 2517 "./typica.w"

qScriptRegisterMetaType(engine,QByteArray_toScriptValue,QByteArray_fromScriptValue);
constructor= engine->newFunction(constructQByteArray);
engine->globalObject().setProperty("QByteArray",constructor);

/*:102*//*114:*/
#line 2759 "./typica.w"

engine->globalObject().setProperty("bytesFromInt8",engine->newFunction(bytesFromInt8));
engine->globalObject().setProperty("bytesFromInt16",engine->newFunction(bytesFromInt16));
engine->globalObject().setProperty("bytesFromInt32",engine->newFunction(bytesFromInt32));
engine->globalObject().setProperty("bytesFromFloat",engine->newFunction(bytesFromFloat));
engine->globalObject().setProperty("bytesFromDouble",engine->newFunction(bytesFromDouble));

/*:114*//*117:*/
#line 2863 "./typica.w"

constructor= engine->newFunction(constructQBuffer);
value= engine->newQMetaObject(&QBuffer::staticMetaObject,constructor);
engine->globalObject().setProperty("QBuffer",value);

/*:117*//*120:*/
#line 2919 "./typica.w"

constructor= engine->newFunction(constructXQuery);
engine->globalObject().setProperty("XQuery",constructor);

/*:120*//*126:*/
#line 3021 "./typica.w"

constructor= engine->newFunction(constructXmlWriter);
engine->globalObject().setProperty("XmlWriter",constructor);

/*:126*//*135:*/
#line 3227 "./typica.w"

constructor= engine->newFunction(constructXmlReader);
engine->globalObject().setProperty("XmlReader",constructor);

/*:135*//*142:*/
#line 3351 "./typica.w"

value= engine->newQObject(&settings);
setQSettingsProperties(value,engine);
engine->globalObject().setProperty("QSettings",value);

/*:142*//*146:*/
#line 3432 "./typica.w"

constructor= engine->newFunction(constructQLCDNumber);
value= engine->newQMetaObject(&QLCDNumber::staticMetaObject,constructor);
engine->globalObject().setProperty("QLCDNumber",value);

/*:146*//*149:*/
#line 3488 "./typica.w"

constructor= engine->newFunction(constructQTime);
engine->globalObject().setProperty("QTime",constructor);

/*:149*//*165:*/
#line 3946 "./typica.w"

constructor= engine->newFunction(constructQColor);
engine->globalObject().setProperty("QColor",constructor);

/*:165*//*168:*/
#line 3969 "./typica.w"

constructor= engine->newFunction(constructQBrush);
engine->globalObject().setProperty("QBrush",constructor);

/*:168*//*177:*/
#line 4049 "./typica.w"

constructor= engine->newFunction(constructQPushButton);
value= engine->newQMetaObject(&QPushButton::staticMetaObject,constructor);
engine->globalObject().setProperty("QPushButton",value);

/*:177*//*184:*/
#line 4160 "./typica.w"

constructor= engine->newFunction(constructQSqlQuery);
engine->globalObject().setProperty("QSqlQuery",constructor);

/*:184*//*191:*/
#line 4324 "./typica.w"

engine->globalObject().setProperty("baseName",engine->newFunction(baseName));
engine->globalObject().setProperty("dir",engine->newFunction(dir));
engine->globalObject().setProperty("sqlToArray",
engine->newFunction(sqlToArray));
engine->globalObject().setProperty("setFont",engine->newFunction(setFont));
engine->globalObject().setProperty("annotationFromRecord",
engine->newFunction(annotationFromRecord));
engine->globalObject().setProperty("setTabOrder",
engine->newFunction(setTabOrder));
engine->globalObject().setProperty("saveFileFromDatabase",
engine->newFunction(saveFileFromDatabase));
engine->globalObject().setProperty("TTR",engine->newFunction(scriptTr));

/*:191*//*204:*/
#line 4725 "./typica.w"

engine->globalObject().setProperty("createWindow",
engine->newFunction(createWindow));
engine->globalObject().setProperty("createReport",
engine->newFunction(createReport));

/*:204*//*229:*/
#line 5097 "./typica.w"

constructor= engine->newFunction(constructQTabBar);
value= engine->newQMetaObject(&QTabBar::staticMetaObject,constructor);
engine->globalObject().setProperty("QTabBar",value);

/*:229*//*279:*/
#line 6525 "./typica.w"

engine->globalObject().setProperty("findChildObject",
engine->newFunction(findChildObject));

/*:279*//*305:*/
#line 389 "./units.w"

value= engine->newQMetaObject(&Units::staticMetaObject);
value.setProperty("convertTemperature",engine->newFunction(Units_convertTemperature));
value.setProperty("convertRelativeTemperature",
engine->newFunction(Units_convertRelativeTemperature));
value.setProperty("isTemperatureUnit",engine->newFunction(Units_isTemperatureUnit));
value.setProperty("convertWeight",engine->newFunction(Units_convertWeight));
value.setProperty("isWeightUnit",engine->newFunction(Units_isWeightUnit));
engine->globalObject().setProperty("Units",value);

/*:305*//*310:*/
#line 462 "./units.w"

qScriptRegisterMetaType(engine,Unit_toScriptValue,Unit_fromScriptValue);

#line 6957 "./typica.w"

/*:310*//*318:*/
#line 141 "./measurement.w"

constructor= engine->newFunction(constructMeasurement);
engine->globalObject().setProperty("Measurement",constructor);
qScriptRegisterMetaType(engine,Measurement_toScriptValue,Measurement_fromScriptValue);

/*:318*//*338:*/
#line 7528 "./typica.w"

constructor= engine->newFunction(constructDAQ);
value= engine->newQMetaObject(&DAQ::staticMetaObject,constructor);
value.setProperty("Fahrenheit",Units::Fahrenheit);
value.setProperty("Celsius",Units::Celsius);
value.setProperty("Kelvin",Units::Kelvin);
value.setProperty("Rankine",Units::Rankine);
engine->globalObject().setProperty("DAQ",value);

/*:338*//*347:*/
#line 7730 "./typica.w"

constructor= engine->newFunction(constructFakeDAQ);
value= engine->newQMetaObject(&FakeDAQ::staticMetaObject,constructor);
engine->globalObject().setProperty("FakeDAQ",value);

/*:347*//*358:*/
#line 8013 "./typica.w"

constructor= engine->newFunction(constructLinearCalibrator);
value= engine->newQMetaObject(&LinearCalibrator::staticMetaObject,
constructor);
engine->globalObject().setProperty("LinearCalibrator",value);

/*:358*//*363:*/
#line 8152 "./typica.w"

constructor= engine->newFunction(constructLinearSplineInterpolator);
value= engine->newQMetaObject(&LinearSplineInterpolator::staticMetaObject,constructor);
engine->globalObject().setProperty("LinearSplineInterpolator",value);

/*:363*//*373:*/
#line 8360 "./typica.w"

constructor= engine->newFunction(constructTemperatureDisplay);
value= engine->newQMetaObject(&TemperatureDisplay::staticMetaObject,
constructor);
engine->globalObject().setProperty("TemperatureDisplay",value);

/*:373*//*381:*/
#line 8518 "./typica.w"

constructor= engine->newFunction(constructMeasurementTimeOffset);
value= engine->newQMetaObject(&MeasurementTimeOffset::staticMetaObject,
constructor);
engine->globalObject().setProperty("MeasurementTimeOffset",value);

/*:381*//*386:*/
#line 8639 "./typica.w"

constructor= engine->newFunction(constructThresholdDetector);
value= engine->newQMetaObject(&ThresholdDetector::staticMetaObject,constructor);
engine->globalObject().setProperty("ThresholdDetector",value);

/*:386*//*391:*/
#line 8738 "./typica.w"

constructor= engine->newFunction(constructZeroEmitter);
value= engine->newQMetaObject(&ZeroEmitter::staticMetaObject,constructor);
engine->globalObject().setProperty("ZeroEmitter",value);

/*:391*//*396:*/
#line 8817 "./typica.w"

constructor= engine->newFunction(constructMeasurementAdapter);
value= engine->newQMetaObject(&MeasurementAdapter::staticMetaObject,
constructor);
engine->globalObject().setProperty("MeasurementAdapter",value);

/*:396*//*413:*/
#line 9280 "./typica.w"

constructor= engine->newFunction(constructGraphView);
value= engine->newQMetaObject(&GraphView::staticMetaObject,constructor);
engine->globalObject().setProperty("GraphView",value);

/*:413*//*436:*/
#line 9929 "./typica.w"

constructor= engine->newFunction(constructZoomLog);
value= engine->newQMetaObject(&ZoomLog::staticMetaObject,constructor);
engine->globalObject().setProperty("ZoomLog",value);

/*:436*//*476:*/
#line 10932 "./typica.w"

constructor= engine->newFunction(constructAnnotationButton);
value= engine->newQMetaObject(&AnnotationButton::staticMetaObject,
constructor);
engine->globalObject().setProperty("AnnotationButton",value);

/*:476*//*484:*/
#line 11074 "./typica.w"

constructor= engine->newFunction(constructAnnotationSpinBox);
value= engine->newQMetaObject(&AnnotationSpinBox::staticMetaObject,
constructor);
engine->globalObject().setProperty("AnnotationSpinBox",value);

/*:484*//*505:*/
#line 11499 "./typica.w"

constructor= engine->newFunction(constructTimerDisplay);
value= engine->newQMetaObject(&TimerDisplay::staticMetaObject,constructor);
engine->globalObject().setProperty("TimerDisplay",value);

/*:505*//*533:*/
#line 12023 "./typica.w"

constructor= engine->newFunction(constructWidgetDecorator);
value= engine->newQMetaObject(&WidgetDecorator::staticMetaObject,constructor);
engine->globalObject().setProperty("WidgetDecorator",value);

/*:533*//*546:*/
#line 12305 "./typica.w"

constructor= engine->newFunction(constructLogEditWindow);
value= engine->newQMetaObject(&LogEditWindow::staticMetaObject,constructor);
engine->globalObject().setProperty("LogEditWindow",value);

/*:546*//*565:*/
#line 12832 "./typica.w"

constructor= engine->newFunction(constructXMLInput);
value= engine->newQMetaObject(&XMLInput::staticMetaObject,constructor);
engine->globalObject().setProperty("XMLInput",value);

/*:565*//*580:*/
#line 164 "./webview.w"

constructor= engine->newFunction(constructWebView);
value= engine->newQMetaObject(&TypicaWebView::staticMetaObject,constructor);
engine->globalObject().setProperty("WebView",value);

/*:580*//*588:*/
#line 261 "./webview.w"

qScriptRegisterMetaType(engine,QWebElement_toScriptValue,QWebElement_fromScriptValue);

/*:588*//*591:*/
#line 303 "./webview.w"

constructor= engine->newFunction(constructWebElement);
engine->globalObject().setProperty("WebElement",constructor);

/*:591*//*603:*/
#line 76 "./printerselector.w"

constructor= engine->newFunction(constructPrinterSelector);
engine->globalObject().setProperty("PrinterSelector",constructor);

/*:603*//*611:*/
#line 13094 "./typica.w"

value= engine->newQObject(AppInstance);
value.setProperty("subscribe",engine->newFunction(Application_subscribe));
engine->globalObject().setProperty("Application",value);

/*:611*//*676:*/
#line 14337 "./typica.w"

constructor= engine->newFunction(constructSqlQueryView);
value= engine->newQMetaObject(&SqlQueryView::staticMetaObject,constructor);
engine->globalObject().setProperty("SqlQueryView",value);

/*:676*//*787:*/
#line 16250 "./typica.w"

constructor= engine->newFunction(constructDeviceTreeModel);
value= engine->newQMetaObject(&DeviceTreeModel::staticMetaObject,
constructor);
engine->globalObject().setProperty("DeviceTreeModel",value);

/*:787*//*793:*/
#line 16390 "./typica.w"

qScriptRegisterMetaType(engine,QModelIndex_toScriptValue,QModelIndex_fromScriptValue);

/*:793*//*809:*/
#line 16682 "./typica.w"

constructor= engine->newFunction(constructDeviceConfigurationWindow);
value= engine->newQMetaObject(&DeviceConfigurationWindow::staticMetaObject,
constructor);
engine->globalObject().setProperty("DeviceConfigurationWindow",value);

/*:809*//*880:*/
#line 58 "./settings.w"

constructor= engine->newFunction(constructSettingsWindow);
value= engine->newQMetaObject(&DeviceConfigurationWindow::staticMetaObject,constructor);
engine->globalObject().setProperty("SettingsWindow",value);

#line 1 "./graphsettings.w"
/*:880*//*907:*/
#line 19313 "./typica.w"

constructor= engine->newFunction(constructModbusRTUDevice);
value= engine->newQMetaObject(&ModbusRTUDevice::staticMetaObject,constructor);
engine->globalObject().setProperty("ModbusRTUDevice",value);

/*:907*//*925:*/
#line 705 "./modbus.w"

constructor= engine->newFunction(constructModbusNG);
value= engine->newQMetaObject(&ModbusNG::staticMetaObject,constructor);
engine->globalObject().setProperty("ModbusNG",value);

/*:925*//*939:*/
#line 353 "./unsupportedserial.w"

engine->globalObject().setProperty("createDevice",
engine->newFunction(createDevice));

/*:939*//*951:*/
#line 625 "./unsupportedserial.w"

engine->globalObject().setProperty("getMeasurementTimestamp",
engine->newFunction(getMeasurementTimestamp));

/*:951*//*955:*/
#line 661 "./unsupportedserial.w"

constructor= engine->newFunction(constructSerialPort);
value= engine->newQMetaObject(&QextSerialPort::staticMetaObject,constructor);
engine->globalObject().setProperty("SerialPort",value);

/*:955*//*977:*/
#line 450 "./phidgets.w"

constructor= engine->newFunction(constructPhidgetsTemperatureSensor);
value= engine->newQMetaObject(&PhidgetsTemperatureSensor::staticMetaObject,constructor);
engine->globalObject().setProperty("PhidgetsTemperatureSensor",value);

/*:977*//*1009:*/
#line 798 "./phidget22.w"

constructor= engine->newFunction(constructPhidget22);
value= engine->newQMetaObject(&Phidget22::staticMetaObject,constructor);
engine->globalObject().setProperty("Phidget22",value);

/*:1009*//*1043:*/
#line 144 "./rate.w"

constructor= engine->newFunction(constructRateOfChange);
value= engine->newQMetaObject(&RateOfChange::staticMetaObject,constructor);
engine->globalObject().setProperty("RateOfChange",value);

/*:1043*//*1057:*/
#line 137 "./mergeseries.w"

constructor= engine->newFunction(constructDifferenceSeries);
value= engine->newQMetaObject(&DifferenceSeries::staticMetaObject,
constructor);
engine->globalObject().setProperty("DifferenceSeries",value);
constructor= engine->newFunction(constructMeanSeries);
value= engine->newQMetaObject(&MeanSeries::staticMetaObject,constructor);
engine->globalObject().setProperty("MeanSeries",value);

/*:1057*//*1082:*/
#line 604 "./dataqsdk.w"

constructor= engine->newFunction(constructDataqSdkDevice);
value= engine->newQMetaObject(&DataqSdkDevice::staticMetaObject,constructor);
engine->globalObject().setProperty("DataqSdkDevice",value);

/*:1082*//*1109:*/
#line 73 "./scales.w"

constructor= engine->newFunction(constructDragLabel);
value= engine->newQMetaObject(&DragLabel::staticMetaObject,constructor);
engine->globalObject().setProperty("DragLabel",value);

/*:1109*//*1117:*/
#line 265 "./scales.w"

constructor= engine->newFunction(constructSerialScale);
value= engine->newQMetaObject(&SerialScale::staticMetaObject,constructor);
engine->globalObject().setProperty("SerialScale",value);

/*:1117*//*1121:*/
#line 351 "./scales.w"

qScriptRegisterMetaType(engine,BaudRateType_toScriptValue,BaudRateType_fromScriptValue);
qScriptRegisterMetaType(engine,DataBitsType_toScriptValue,DataBitsType_fromScriptValue);
qScriptRegisterMetaType(engine,ParityType_toScriptValue,ParityType_fromScriptValue);
qScriptRegisterMetaType(engine,StopBitsType_toScriptValue,StopBitsType_fromScriptValue);
qScriptRegisterMetaType(engine,FlowType_toScriptValue,FlowType_fromScriptValue);

/*:1121*//*1145:*/
#line 271 "./valueannotation.w"

constructor= engine->newFunction(constructValueAnnotation);
value= engine->newQMetaObject(&ValueAnnotation::staticMetaObject,constructor);
engine->globalObject().setProperty("ValueAnnotation",value);

/*:1145*//*1156:*/
#line 201 "./thresholdannotation.w"

constructor= engine->newFunction(constructAnnotator);
value= engine->newQMetaObject(&Annotator::staticMetaObject,constructor);
engine->globalObject().setProperty("Annotator",value);

/*:1156*//*1166:*/
#line 135 "./user.w"

constructor= engine->newFunction(constructLoginDialog);
value= engine->newQMetaObject(&LoginDialog::staticMetaObject,constructor);
engine->globalObject().setProperty("LoginDialog",value);

/*:1166*//*1176:*/
#line 323 "./user.w"

constructor= engine->newFunction(constructNewTypicaUser);
value= engine->newQMetaObject(&NewTypicaUser::staticMetaObject,constructor);
engine->globalObject().setProperty("NewTypicaUser",value);

/*:1176*/
#line 13936 "./typica.w"

app.engine= engine;
/*201:*/
#line 4604 "./typica.w"

QString styleText;
QString programText;
QDomElement currentElement;
for(int i= 0;i<children.size();i++)
{
QDomNode currentNode= children.at(i);
if(currentNode.nodeName()=="style")
{
currentElement= currentNode.toElement();
styleText.append(currentElement.text());
}
else if(currentNode.nodeName()=="program")
{
currentElement= currentNode.toElement();
programText.append(currentElement.text());
}
}
app.setStyleSheet(styleText);
QScriptValue result= engine->evaluate(programText);
/*202:*/
#line 4629 "./typica.w"

if(engine->hasUncaughtException())
{
int line= engine->uncaughtExceptionLineNumber();
qDebug()<<"Uncaught excpetion at line "<<line<<" : "<<
result.toString();
QString trace;
foreach(trace,engine->uncaughtExceptionBacktrace())
{
qDebug()<<trace;
}
}

/*:202*/
#line 4624 "./typica.w"


/*:201*/
#line 13938 "./typica.w"


int retval= app.exec();
delete engine;
return retval;
}

/*:653*/
#line 535 "./typica.w"

#include "moc_typica.cpp"

/*:3*/

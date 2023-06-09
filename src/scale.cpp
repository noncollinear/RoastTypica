/*1112:*/
#line 135 "./scales.w"

#include "scale.h"
#include <QStringList> 

SerialScale::SerialScale(const QString&port):
QextSerialPort(port,QextSerialPort::EventDriven)
{
connect(this,SIGNAL(readyRead()),this,SLOT(dataAvailable()));
}

/*:1112*//*1113:*/
#line 153 "./scales.w"

void SerialScale::dataAvailable()
{
responseBuffer.append(readAll());
if(responseBuffer.contains("\x0D"))
{
if(responseBuffer.contains("!"))
{
responseBuffer.clear();
}
else
{
/*1114:*/
#line 193 "./scales.w"

QStringList responseParts= QString(responseBuffer.simplified()).split(' ');
if(responseParts.size()> 2)
{
responseParts.removeFirst();
responseParts.replace(0,QString("-%1").arg(responseParts[0]));
}
double weight= responseParts[0].toDouble();
Units::Unit unit= Units::Unitless;
if(responseParts[1].compare("lb",Qt::CaseInsensitive)==0)
{
unit= Units::Pound;
}
else if(responseParts[1].compare("kg",Qt::CaseInsensitive)==0)
{
unit= Units::Kilogram;
}
else if(responseParts[1].compare("g",Qt::CaseInsensitive)==0)
{
unit= Units::Gram;
}
else if(responseParts[1].compare("oz",Qt::CaseInsensitive)==0)
{
unit= Units::Ounce;
}
emit newMeasurement(weight,unit);

/*:1114*/
#line 165 "./scales.w"

responseBuffer.clear();
}
}
}

/*:1113*//*1115:*/
#line 224 "./scales.w"

void SerialScale::tare()
{
write("!KT\x0D");
}

void SerialScale::weigh()
{

write(weighCommand+commandTerminator);
}

void SerialScale::setWeighCommand(const QString&command)
{
weighCommand= command.toAscii();
}

void SerialScale::setCommandTerminator(const QString&terminator)
{
if(terminator=="CRLF")
{
commandTerminator= "\x0D\x0A";
}
else if(terminator=="CR")
{
commandTerminator= "\x0D";
}
else if(terminator=="LF")
{
commandTerminator= "\x0A";
}
}

/*:1115*/

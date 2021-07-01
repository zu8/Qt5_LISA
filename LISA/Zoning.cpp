#include"Zoning.h"
#include"core.h"
#include"Sprinkler.h"



Zoning::Zoning(QObject *parent): QObject(parent)
{
    currentBody = new Core;
    currentBody = nullptr;
    MaxFlow = 0;
    zone = 1;
    TotalFlow = 0;
    AreaZones[zone] = TotalFlow;
}

Zoning::Zoning(const Zoning &other)
{    
   MaxFlow = other.MaxFlow;
   zone = other.zone;
   TotalFlow = other.TotalFlow;
   AreaZones = other.AreaZones;
   currentBody = new Core(*(other.currentBody));

}
Zoning::~Zoning(){}

QMap<int, double> Zoning::getAreaZones()
{
    return AreaZones;
}

void Zoning::setAreaZones(QMap<int, double> map)
{
    AreaZones = map;
}

Core* Zoning::getCurrentBody()
{
    return currentBody;
}

void Zoning::setCurrentBody(Core * curbody)
{
    currentBody = curbody;
};

void Zoning::SelectedBody(Core* body)
{
    currentBody = body;
    if(body == nullptr)
    {
        emit textChanged();
        emit coreChange("");
        emit newFlowValue(AreaZones.value(zone));
    }
    else
    {
        emit textChanged();
        emit coreChange(body->getAreal()->getModel());
        if (currentBody->getAreal()->getLabelText().toInt() == zone)
        { emit newFlowValue(AreaZones.value(zone));}
        else
        { emit newFlowValue(AreaZones.value(zone) + currentBody->getCoreFlow());}
    }

}

void Zoning::changeZnumber(int num)
{
    zone = num;
    if (!currentBody) emit newFlowValue(AreaZones.value(zone));
    else if (currentBody->getAreal()->getLabelText().toInt() == zone)
    {
        emit newFlowValue(AreaZones.value(zone));
    }
    else
    {
        emit newFlowValue(AreaZones.value(zone) + currentBody->getCoreFlow());
    }
}

void Zoning::AddFlowSprinkler()
{
    qDebug() << "add sprinkler";
    if(!currentBody) return;
    else if (currentBody->getAreal()->getLabelText().toInt() == zone) return;
    else if(currentBody->getAreal()->getLabelText().toInt() == 0)
    {
        AreaZones[zone] += currentBody->getCoreFlow(); // add flow value to zoneFlow
        currentBody->getAreal()->setZoneNumLabel(QString::number(zone)); // set zone num to label
        currentBody->getAreal()->ShowZoneNumLabel(true); // show label
        emit newFlowValue(AreaZones.value(zone));
    }
    else
    {
        AreaZones[zone] += currentBody->getCoreFlow();  // add flow value to zoneFlow
        AreaZones[currentBody->getAreal()->getLabelText().toInt()] -= currentBody->getCoreFlow(); // deduct flow from old sprinkler zone
        currentBody->getAreal()->setZoneNumLabel(QString::number(zone)); // set new zone num to label
        emit newFlowValue(AreaZones.value(zone));
    }
}

void Zoning::RemoveFlowSprinkler()
{
    qDebug() << "del sprinker";
    if(!currentBody) return;
    else if(currentBody->getAreal()->getLabelText().toInt() == 0) return;
    else if(currentBody->getAreal()->getLabelText().toInt() == zone)
    {
        AreaZones[zone] -= currentBody->getCoreFlow();
        currentBody->getAreal()->setZoneNumLabel("0");
        currentBody->getAreal()->ShowZoneNumLabel(false);
        emit newFlowValue(AreaZones.value(zone) + currentBody->getCoreFlow());
    }
    else
    {
      AreaZones[currentBody->getAreal()->getLabelText().toInt()] -= currentBody->getCoreFlow();
      currentBody->getAreal()->setZoneNumLabel("0");
      currentBody->getAreal()->ShowZoneNumLabel(false);
    }
}

void Zoning::UserFlow(double DC, double Pr)
{
    MaxFlow = DC;
    Q_UNUSED(Pr);
}


QDataStream & operator<<(QDataStream & out,const   Zoning & Z)
{
    out << Z.zone;
    out << Z.MaxFlow;
    out << Z.TotalFlow;
    out << Z.AreaZones;    
    return out;
}
QDataStream & operator>>(QDataStream & in,  Zoning & Z)
{
    in>> Z.zone;
    in>> Z.MaxFlow;
    in>> Z.TotalFlow;
    in>> Z.AreaZones;    
    return in;
}

#include "currentconditiondisplay.h"
#include <iostream>

CurrentConditionDisplay::CurrentConditionDisplay(Subject &weatherData)
{
    _weatherData = &weatherData;
    _weatherData->RegisterObserver(*this);
}

void CurrentConditionDisplay::Update(float temp, float humidity, float /*pressure*/)
{
    _temp = temp;
    _humidity = humidity;
    Display();
}

void CurrentConditionDisplay::Display()
{
    std::cout << "T=" << _temp << " C h=" << _humidity << " %" << std::endl;
}

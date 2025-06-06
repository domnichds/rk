#ifndef CURRENTCONDITIONDISPLAY_H
#define CURRENTCONDITIONDISPLAY_H

#include "displayelement.h"
#include "subject.h"
#include "observer.h"

class CurrentConditionDisplay : public Observer, public DisplayElement
{
    float _temp{};
    float _humidity{};
    Subject *_weatherData;

public:
    explicit CurrentConditionDisplay(Subject &weatherData);
    void Update(float temp, float humidity, float pressure) override;
    void Display() override;
};

#endif // CURRENTCONDITIONDISPLAY_H

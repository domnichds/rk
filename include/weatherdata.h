#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "subject.h"
#include <vector>

class WeatherData : public Subject
{
    std::vector<Observer *> _observerList;
    float _temp{};
    float _humidity{};
    float _pressure{};

public:
    void RegisterObserver(Observer &observer) override;
    void RemoveObserver(Observer &observer) override;
    void NotifyObservers() override;
    void MeasurementChanged();
    void SetMeasurement(float temp, float humidity, float pressure);
    WeatherData();
};

#endif // WEATHERDATA_H

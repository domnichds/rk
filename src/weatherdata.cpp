#include "weatherdata.h"
#include <algorithm>

WeatherData::WeatherData() {}

void WeatherData::RegisterObserver(Observer &observer)
{
    _observerList.push_back(&observer);
}

void WeatherData::RemoveObserver(Observer &observer)
{
    _observerList.erase(std::remove(_observerList.begin(), _observerList.end(), &observer), _observerList.end());
}

void WeatherData::NotifyObservers()
{
    for (auto &observer : _observerList)
        observer->Update(_temp, _humidity, _pressure);
}

void WeatherData::MeasurementChanged()
{
    NotifyObservers();
}

void WeatherData::SetMeasurement(float temp, float humidity, float pressure)
{
    _temp = temp;
    _humidity = humidity;
    _pressure = pressure;
    MeasurementChanged();
}

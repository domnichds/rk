#include "weatherdata.h"
#include "currentconditiondisplay.h"

int main()
{
    WeatherData weatherData;
    CurrentConditionDisplay display(weatherData);

    weatherData.SetMeasurement(1, 2, 3);

    return 0;
}

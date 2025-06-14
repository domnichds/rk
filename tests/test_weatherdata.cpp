#include "weatherdata.h"
#include <cassert>
#include <cmath>

#define APPROX_EQUAL(a, b) (std::fabs((a)-(b)) < 1e-4)

class TestObs : public Observer {
public:
    float t = 0, h = 0, p = 0;
    void Update(float temp, float hum, float pres) override {
        t = temp; h = hum; p = pres;
    }
};

int main() {
    WeatherData w;
    TestObs o;
    w.RegisterObserver(o);
    w.SetMeasurement(4.2, 5.1, 9.9);
    assert(APPROX_EQUAL(o.t, 4.2) && APPROX_EQUAL(o.h, 5.1) && APPROX_EQUAL(o.p, 9.9));
    w.RemoveObserver(o);
    o.t = 0; o.h = 0; o.p = 0;
    w.SetMeasurement(1,1,1);
    assert(APPROX_EQUAL(o.t, 0) && APPROX_EQUAL(o.h, 0) && APPROX_EQUAL(o.p, 0));
    return 0;
}

#include "weatherdata.h"
#include "currentconditiondisplay.h"
#include <sstream>
#include <iostream>
#include <cassert>

class CoutRedirect {
    std::streambuf* old;
    std::ostringstream oss;
public:
    CoutRedirect() : old(std::cout.rdbuf(oss.rdbuf())) {}
    ~CoutRedirect() { std::cout.rdbuf(old); }
    std::string str() const { return oss.str(); }
};

int main() {
    WeatherData wd;
    {
        CoutRedirect r;
        CurrentConditionDisplay disp(wd);
        wd.SetMeasurement(99, 88, 77);
        std::string out = r.str();
        assert(out.find("T=99") != std::string::npos);
        assert(out.find("h=88") != std::string::npos);
    }
    return 0;
}

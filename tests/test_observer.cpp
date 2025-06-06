#include "observer.h"
#include <cassert>

class TestObserver : public Observer {
public:
    bool updated = false;
    void Update(float, float, float) override { updated = true; }
};

int main() {
    TestObserver o;
    o.Update(1,2,3);
    assert(o.updated);
    return 0;
}

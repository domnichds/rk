#include "subject.h"
#include "observer.h"
#include <cassert>

class DummyObserver : public Observer {
public:
    bool called = false;
    void Update(float, float, float) override { called = true; }
};

class DummySubject : public Subject {
    Observer* obs = nullptr;
public:
    void RegisterObserver(Observer &o) override { obs = &o; }
    void RemoveObserver(Observer&) override { obs = nullptr; }
    void NotifyObservers() override { if (obs) obs->Update(0,0,0); }
};

int main() {
    DummySubject subj;
    DummyObserver obs;
    subj.RegisterObserver(obs);
    subj.NotifyObservers();
    assert(obs.called);
    subj.RemoveObserver(obs);
    obs.called = false;
    subj.NotifyObservers();
    assert(!obs.called);
    return 0;
}

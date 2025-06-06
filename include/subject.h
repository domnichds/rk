#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"

class Subject
{
public:
    virtual void RegisterObserver(Observer &ob) = 0;
    virtual void RemoveObserver(Observer &ob) = 0;
    virtual void NotifyObservers() = 0;
    virtual ~Subject() = default;
};

#endif // SUBJECT_H

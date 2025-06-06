#ifndef DISPLAYELEMENT_H
#define DISPLAYELEMENT_H

class DisplayElement
{
public:
    virtual void Display() = 0;
    virtual ~DisplayElement() = default;
};

#endif // DISPLAYELEMENT_H

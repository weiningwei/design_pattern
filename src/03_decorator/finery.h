#ifndef _FINERY_H
#define _FINERY_H

#include <iostream>
#include <string>

class Human
{
public:
    Human(){};
    Human(std::string name);
    virtual void show() = 0;

protected:
    std::string m_sName;
};

class Finery : public Human
{
public:
    Finery(){};
    void decorate(Human *component);
    void show();

protected:
    Human *m_component;
};

#endif
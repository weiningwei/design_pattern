#include <iostream>
#include <string>
#include "leifeng.h"

void LeiFeng::sweep()
{
    std::cout << "sweep\n";
}

void LeiFeng::wash()
{
    std::cout << "wash\n";
}

void LeiFeng::buyRice()
{
    std::cout << "buyRice\n";
}

class UnderGraduate : public LeiFeng
{
};
class Volunteer : public LeiFeng
{
};

class UnderGraduateLeiFeng : public ILeiFeng
{
public:
    UnderGraduateLeiFeng(){};
    LeiFeng *createLeiFeng() const override
    {
        return new UnderGraduate();
    }
};

class VolunteerLeiFeng : public ILeiFeng
{
public:
    VolunteerLeiFeng(){};
    LeiFeng *createLeiFeng() const override
    {
        return new Volunteer();
    }
};

int main()
{
    ILeiFeng *factoty = new VolunteerLeiFeng();
    LeiFeng *stu_volun = factoty->createLeiFeng();
    stu_volun->sweep();
    stu_volun->wash();
    stu_volun->buyRice();

    return 0;
}
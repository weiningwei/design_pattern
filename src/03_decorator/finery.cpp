#include "finery.h"

class Person : public Human
{
public:
    explicit Person(std::string name)
    {
        m_sName = name;
    }
    void show() override
    {
        std::cout << m_sName << "\n";
    }
};

void Finery::decorate(Human *component)
{
    m_component = component;
}

void Finery::show()
{
    m_component->show();
}

// 装饰类
class TShirt : public Finery
{
public:
    void show() override
    {
        std::cout << "Tshirt\n";
        Finery::show();
    }
};

class Tie : public Finery
{
public:
    void show() override
    {
        std::cout << "Tie\n";
        Finery::show();
    }
};

class Suit : public Finery
{
public:
    void show() override
    {
        std::cout << "Suit\n";
        Finery::show();
    }
};

int main(void)
{
    Person *wei = new Person("weiningwei");

    std::cout << "*****first finery*****\n";
    TShirt *tshirt = new TShirt();
    Tie *tie = new Tie();

    tshirt->decorate(wei);
    tie->decorate(tshirt);
    tie->show();

    // second finery
    std::cout << "*****second finery*****\n";
    Suit *suit = new Suit();
    suit->decorate(wei);
    suit->show();

    return 0;
}
#include <iostream>
#include <string>
#include "pursuit.h"

class SchoolGirl
{
public:
    SchoolGirl(){};
    void setName(std::string name)
    {
        m_sName = name;
        return;
    }
    std::string getName()
    {
        return m_sName;
    }

private:
    std::string m_sName;
};

class Pursuit : public IGiveGift
{
public:
    Pursuit(SchoolGirl *girl)
    {
        m_girl = girl;
    }
    void giveDollors() const override
    {
        std::cout << m_girl->getName() << " give dollor\n";
        return;
    }

    void giveFlowers() const override
    {
        std::cout << m_girl->getName() << " give flower\n";
        return;
    }

    void giveChocolate() const override
    {
        std::cout << m_girl->getName() << " give chocolate\n";
        return;
    }

private:
    SchoolGirl *m_girl;
};

class Proxy : IGiveGift
{
public:
    Proxy(SchoolGirl *girl)
    {
        m_girl = new Pursuit(girl);
    }
    void giveDollors() const override
    {
        m_girl->giveDollors();
        return;
    }

    void giveFlowers() const override
    {
        m_girl->giveFlowers();
        return;
    }

    void giveChocolate() const override
    {
        m_girl->giveChocolate();
        return;
    }

private:
    Pursuit *m_girl;
};

int main()
{
    SchoolGirl *girl = new SchoolGirl();
    girl->setName("xiao-mei");

    Proxy *proxy = new Proxy(girl);
    proxy->giveDollors();
    proxy->giveFlowers();
    proxy->giveChocolate();

    return 0;
}
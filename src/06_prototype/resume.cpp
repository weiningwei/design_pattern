#include <iostream>
#include <string>
#include "resume.h"

class WorkExperience : public Cloneable
{
public:
    void setWorkDate(std::string work_date)
    {
        m_sWorkDate = work_date;
    }
    void setCompany(std::string company)
    {
        m_sCompany = company;
    }

    std::string getWorkDate()
    {
        return m_sWorkDate;
    }

    std::string getCompany()
    {
        return m_sCompany;
    }

    WorkExperience *clone() const override
    {
        return new WorkExperience(*this);
    }

private:
    std::string m_sWorkDate;
    std::string m_sCompany;
};

class Resume : public Cloneable
{
public:
    Resume(std::string name)
    {
        m_sName = name;
        m_work = new WorkExperience();
    }

    Resume(WorkExperience *work)
    {
        m_work = work->clone();
    }

    void setInfo(std::string sex, int age)
    {
        m_sSex = sex;
        m_iAge = age;
        return;
    }

    void setWorkExperience(std::string work_date, std::string company)
    {
        m_work->setWorkDate(work_date);
        m_work->setCompany(company);
    }

    Resume *clone() const override
    {
        Resume *resume = new Resume(m_work);
        resume->m_sName = m_sName;
        resume->m_sSex = m_sSex;
        resume->m_iAge = m_iAge;
        return resume;
    }

    void display()
    {
        std::cout << m_sName << "\t" << m_sSex << "\t" << m_iAge << "\t"
                  << m_work->getWorkDate() << "\t"
                  << m_work->getCompany() << "\n";
        return;
    }

private:
    std::string m_sName;
    std::string m_sSex;
    int m_iAge;
    WorkExperience *m_work;
};

int main()
{

    Resume *a = new Resume("aaa");
    a->setInfo("man", 10);
    a->setWorkExperience("2000", "XXX");

    Resume *b = a->clone();
    b->setWorkExperience("2001", "YYY");

    Resume *c = a->clone();
    c->setInfo("woman", 12);
    c->setWorkExperience("2002", "ZZZ");

    a->display();
    b->display();
    c->display();
    return 0;
}
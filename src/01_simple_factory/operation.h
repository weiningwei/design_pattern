#ifndef OPERATION_H
#define OPERATION_H

class Operation
{
private:
    /* data */
public:

    virtual double getResult() const = 0;
    void setNumberA(double numberA)
    {
        m_dNumberA = numberA;
    }
    void setNumberB(double numberB)
    {
        m_dNumberB = numberB;
    }

protected:
    double m_dNumberA;
    double m_dNumberB;
};

class OperationFactory
{
public:
    static Operation *createOperate(const char operate);
};

#endif
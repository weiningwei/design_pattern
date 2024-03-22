#include <iostream>
#include <string>
#include "operation.h"

class OperateAdd : public Operation
{
public:
    double getResult() const override
    {
        double result = 0;
        result = m_dNumberA + m_dNumberB;
        return result;
    }
};

class OperateSub : public Operation
{
public:
    double getResult() const override
    {
        double result = 0;
        result = m_dNumberA - m_dNumberB;
        return result;
    }
};

class OperateMul : public Operation
{
public:
    double getResult() const override
    {
        double result = 0;
        result = m_dNumberA * m_dNumberB;
        return result;
    }
};

class OperateDiv : public Operation
{
public:
    double getResult() const override
    {
        double result = 0;
        result = m_dNumberA / m_dNumberB;
        return result;
    }
};

Operation *OperationFactory::createOperate(const char operate)
{
    Operation *oper;
    switch (operate)
    {
    case '+':
        oper = new OperateAdd();
        break;
    case '-':
        oper = new OperateSub();
        break;
    case '*':
        oper = new OperateMul();
        break;
    case '/':
        oper = new OperateDiv();
        break;

    default:
        break;
    }
    return oper;
}

int main(void)
{
    // std::string opertate;
    // std::cin >> opertate;
    std::string opertate = "+-*/";
    double numA = 4;
    double numB = 2;
    Operation *oper;

    for (size_t i = 0; i < 4; ++i)
    {
        oper = OperationFactory::createOperate(opertate[i]);
        oper->setNumberA(numA);
        oper->setNumberB(numB);
        double result = oper->getResult();

        std::cout << numA << " " << opertate[i] << " " << numB << " = " << result << "\n";
    }

    return 0;
}
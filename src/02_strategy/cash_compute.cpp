#include <iostream>
#include <math.h>
#include "cash_compute.h"

class CashNormal : public Cash
{
public:
    double acceptCash(double money) const override
    {
        return money;
    }
};

class CashRebate : public Cash
{
public:
    double acceptCash(double money) const override
    {
        return (money * m_dMoneyRate);
    }
    CashRebate(double money_rate)
    {
        m_dMoneyRate = money_rate;
    }

private:
    double m_dMoneyRate = 1.0;
};

class CashReturn : public Cash
{
public:
    CashReturn(double money_condition, double money_return)
    {
        m_dMoneyCondition = money_condition;
        m_dMoneyReturn = money_return;
    }
    double acceptCash(double money) const override
    {
        double result = money;
        if (money >= m_dMoneyCondition)
        {
            result = money - floor(money / m_dMoneyCondition) * m_dMoneyReturn;
        }
        return result;
    }

private:
    double m_dMoneyCondition = 0.0;
    double m_dMoneyReturn = 0.0;
};

class CashContext
{
public:
    CashContext(Cash *cash)
    {
        m_cash = cash;
    }
    void setStrategy(Cash *cash)
    {
        m_cash = cash;
    }
    double getResult(double monry)
    {
        return m_cash->acceptCash(monry);
    }

private:
    Cash *m_cash;
};

int main(void)
{
    CashNormal *normal = new CashNormal();
    CashRebate *rebate = new CashRebate(0.8);
    CashReturn *resub = new CashReturn(500, 100);

    CashContext *ctx = new CashContext(normal);
    double init_price = 1000;
    double total_price = 0.0;

    total_price += ctx->getResult(init_price);

    ctx->setStrategy(rebate);
    total_price += ctx->getResult(init_price);

    ctx->setStrategy(resub);
    total_price += ctx->getResult(init_price);

    std::cout << total_price << "\n";
    return 0;
}
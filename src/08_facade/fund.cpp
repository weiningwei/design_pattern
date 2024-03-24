#include <iostream>
#include <string>
#include "Fund.h"

void Stock1::buy()
{
    std::cout << "stock1 buy\n";
}

void Stock1::sell()
{
    std::cout << "stock1 sell\n";
}

void Stock2::buy()
{
    std::cout << "stock2 buy\n";
}

void Stock2::sell()
{
    std::cout << "stock2 sell\n";
}

void Stock3::buy()
{
    std::cout << "stock3 buy\n";
}

void Stock3::sell()
{
    std::cout << "stock3 sell\n";
}

void NationalDebt1::buy()
{
    std::cout << "national_debt1 buy\n";
}

void NationalDebt1::sell()
{
    std::cout << "national_debt1 sell\n";
}

void Realty1::buy()
{
    std::cout << "realty1 buy\n";
}

void Realty1::sell()
{
    std::cout << "realty1 sell\n";
}

void Fund::buyFund()
{
    m_gu1->buy();
    m_gu2->buy();
    m_gu3->buy();
    m_nd1->buy();
    m_rt1->buy();
}

void Fund::sellFund()
{
    m_gu1->sell();
    m_gu2->sell();
    m_gu3->sell();
    m_nd1->sell();
    m_rt1->sell();
}

int main()
{
    Fund *jijin = new Fund();
    jijin->buyFund();
    jijin->sellFund();

    return 0;
}
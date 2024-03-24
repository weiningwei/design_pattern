#ifndef _TEST_PAPER_H
#define _TEST_PAPER_H

#include <iostream>
#include <string>

class TestPaper
{
public:
    void testQuestion1();
    void testQuestion2();
    void testQuestion3();
    virtual std::string answer1() = 0;
    virtual std::string answer2() = 0;
    virtual std::string answer3() = 0;
};

class TestPaperA: public TestPaper
{
public:
    std::string answer1() override;
    std::string answer2() override;
    std::string answer3() override;
};

class TestPaperB: public TestPaper
{
public:
    std::string answer1() override;
    std::string answer2() override;
    std::string answer3() override;
};


#endif
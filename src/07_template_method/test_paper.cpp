#include <iostream>
#include "test_paper.h"

void TestPaper::testQuestion1()
{
    std::cout << "question1():\n";
    std::cout << "answer: " << answer1() << "\n";
}

void TestPaper::testQuestion2()
{
    std::cout << "question1():\n";
    std::cout << "answer: " << answer2() << "\n";
}

void TestPaper::testQuestion3()
{
    std::cout << "question3():\n";
    std::cout << "answer: " << answer3() << "\n";
}

std::string TestPaperA::answer1()
{
    return "a";
}

std::string TestPaperA::answer2()
{
    return "a";
}

std::string TestPaperA::answer3()
{
    return "a";
}

std::string TestPaperB::answer1()
{
    return "b";
}

std::string TestPaperB::answer2()
{
    return "b";
}

std::string TestPaperB::answer3()
{
    return "b";
}

int main()
{
    std::cout << "paper for student A:\n";
    TestPaper *studentA = new TestPaperA();
    studentA->testQuestion1();
    studentA->testQuestion2();
    studentA->testQuestion3();

    std::cout << "paper for student B:\n";
    TestPaper * studentB = new TestPaperB();
    studentB->testQuestion1();
    studentB->testQuestion2();
    studentB->testQuestion3();

    return 0;
}
#include <iostream>
#include <string>

// 抽象椅子接口
class Chair
{
public:
    virtual void showInfo() = 0;
};

// 具体现代风格椅子
class ModernChair : public Chair
{
public:
    void showInfo() override
    {
        std::cout << "modern chair" << std::endl;
    }
};

// 具体古典风格椅子
class ClassicalChair : public Chair
{
public:
    void showInfo() override
    {
        std::cout << "classical chair" << std::endl;
    }
};

// 抽象沙发接口
class Sofa
{
public:
    virtual void displayInfo() = 0;
};

// 具体现代风格沙发
class ModernSofa : public Sofa
{
public:
    void displayInfo() override
    {
        std::cout << "modern sofa" << std::endl;
    }
};

// 具体古典风格沙发
class ClassicalSofa : public Sofa
{
public:
    void displayInfo() override
    {
        std::cout << "classical sofa" << std::endl;
    }
};

// 抽象家居工厂接口
class FurnitureFactory
{
public:
    virtual Chair *createChair() = 0;
    virtual Sofa *createSofa() = 0;
};

// 具体现代风格家居工厂
class ModernFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair() override
    {
        return new ModernChair();
    }

    Sofa *createSofa() override
    {
        return new ModernSofa();
    }
};

// 具体古典风格家居工厂
class ClassicalFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair() override
    {
        return new ClassicalChair();
    }

    Sofa *createSofa() override
    {
        return new ClassicalSofa();
    }
};

int main()
{
    // 读取订单数量
    int N;
    std::cin >> N;

    // 处理每个订单
    for (int i = 0; i < N; i++)
    {
        // 读取家具类型
        std::string furnitureType;
        std::cin >> furnitureType;

        // 创建相应风格的家居装饰品工厂
        FurnitureFactory *factory = nullptr;
        if (furnitureType == "modern")
        {
            factory = new ModernFurnitureFactory();
        }
        else if (furnitureType == "classical")
        {
            factory = new ClassicalFurnitureFactory();
        }

        // 根据工厂生产椅子和沙发
        Chair *chair = factory->createChair();
        Sofa *sofa = factory->createSofa();

        // 输出家具信息
        chair->showInfo();
        sofa->displayInfo();

        // 释放动态分配的对象
        delete chair;
        delete sofa;
        delete factory;
    }

    return 0;
}
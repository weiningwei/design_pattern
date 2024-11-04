#include <iostream>
#include <string>

// 自行车产品
class Bike
{
public:
    std::string frame;
    std::string tires;

    void setFrame(const std::string &frame)
    {
        this->frame = frame;
    }

    void setTires(const std::string &tires)
    {
        this->tires = tires;
    }

    friend std::ostream &operator<<(std::ostream &os, const Bike &bike)
    {
        os << bike.frame << " " << bike.tires;
        return os;
    }
};

// 自行车建造者接口
class BikeBuilder
{
public:
    virtual void buildFrame() = 0;
    virtual void buildTires() = 0;
    virtual Bike getResult() = 0;
};

// 山地自行车建造者
class MountainBikeBuilder : public BikeBuilder
{
private:
    Bike bike;

public:
    void buildFrame() override
    {
        bike.setFrame("Aluminum Frame");
    }

    void buildTires() override
    {
        bike.setTires("Knobby Tires");
    }

    Bike getResult() override
    {
        return bike;
    }
};

// 公路自行车建造者
class RoadBikeBuilder : public BikeBuilder
{
private:
    Bike bike;

public:
    void buildFrame() override
    {
        bike.setFrame("Carbon Frame");
    }

    void buildTires() override
    {
        bike.setTires("Slim Tires");
    }

    Bike getResult() override
    {
        return bike;
    }
};

// 自行车Director，负责构建自行车
class BikeDirector
{
public:
    Bike construct(BikeBuilder &builder)
    {
        builder.buildFrame();
        builder.buildTires();
        return builder.getResult();
    }
};

int main()
{
    int N;
    std::cin >> N; // 订单数量

    BikeDirector director;

    for (int i = 0; i < N; i++)
    {
        std::string bikeType;
        std::cin >> bikeType;

        BikeBuilder *builder;

        // 根据输入类别，创建不同类型的具体建造者
        if (bikeType == "mountain")
        {
            builder = new MountainBikeBuilder();
        }
        else
        {
            builder = new RoadBikeBuilder();
        }

        // Director负责指导生产产品
        Bike bike = director.construct(*builder);
        std::cout << bike << std::endl;

        // 释放动态分配的对象
        delete builder;
    }

    return 0;
}
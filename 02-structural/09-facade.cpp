#include <iostream>
#include <vector>

class AirConditioner
{
public:
    void turnOff()
    {
        std::cout << "Air Conditioner is turned off." << std::endl;
    }
};

class DeskLamp
{
public:
    void turnOff()
    {
        std::cout << "Desk Lamp is turned off." << std::endl;
    }
};

class Television
{
public:
    void turnOff()
    {
        std::cout << "Television is turned off." << std::endl;
    }
};

class PowerSwitchFacade
{
private:
    DeskLamp deskLamp;
    AirConditioner airConditioner;
    Television television;

public:
    PowerSwitchFacade()
    {
    }

    void turnOffDevice(int deviceCode)
    {
        switch (deviceCode)
        {
        case 1:
            airConditioner.turnOff();
            break;
        case 2:
            deskLamp.turnOff();
            break;
        case 3:
            television.turnOff();
            break;
        case 4:
            std::cout << "All devices are off." << std::endl;
            break;
        default:
            std::cout << "Invalid device code." << std::endl;
        }
    }
};

int main()
{
    // 读取输入
    int n;
    std::cin >> n;
    std::vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> input[i];
    }

    // 创建电源总开关外观
    PowerSwitchFacade powerSwitch;

    // 执行操作
    for (int i = 0; i < n; i++)
    {
        powerSwitch.turnOffDevice(input[i]);
    }

    return 0;
}
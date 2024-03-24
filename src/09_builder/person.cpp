#include "person.h"

void Person::add(std::string part)
{
    m_lParts.push_back(part);
}

void Person::show()
{
    std::cout << "\nPerson Show ---\n";
    for (auto v : m_lParts)
    {
        std::cout << v << "\n";
    }
}

Pen::Pen(Color color)
{
    m_color = color;
}

void Pen::getColor()
{
    switch (m_color)
    {
    case Color::yellow:
        std::cout << "yellow pen\n";
        break;
    case Color::white:
        std::cout << "white pen\n";
        break;
    case Color::black:
        std::cout << "black pen";
        break;
    }
}

void print(std::string action, int a, int b, int c, int d)
{
    std::cout << action << " " << a << " " << b << " "
              << c << " " << d << "\n";
}

void Graphics::drawEllipse(Pen *p, int a, int b, int c, int d)
{
    p->getColor();
    print("drawEllipse: ", a, b, c, d);
}

void Graphics::drawRectangle(Pen *p, int a, int b, int c, int d)
{
    p->getColor();
    print("drawRectangle: ", a, b, c, d);
}

void Graphics::drawLine(Pen *p, int a, int b, int c, int d)
{
    p->getColor();
    print("drawLine: ", a, b, c, d);
}

ThinBuilder::ThinBuilder(Graphics *g, Pen *p)
{
    m_g = g;
    m_pen = p;
};

void ThinBuilder::buildHead()
{
    m_g->drawEllipse(m_pen, 50, 20, 30, 30);
    m_per->add("head");
}

void ThinBuilder::buildBody()
{
    m_g->drawRectangle(m_pen, 50, 20, 30, 30);
    m_per->add("body");
}

void ThinBuilder::buildArmLeft()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("arm_left");
}

void ThinBuilder::buildArmRight()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("arm_right");
}

void ThinBuilder::buildLegLeft()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("leg_left");
}

void ThinBuilder::buildLegRight()
{
    m_g->drawLine(m_pen, 50, 20, 30, 30);
    m_per->add("leg_right");
}

Person *ThinBuilder::getPerson()
{
    return m_per;
}

FatBuilder::FatBuilder(Graphics *g, Pen *p)
{
    m_g = g;
    m_pen = p;
};

void FatBuilder::buildHead()
{
    m_g->drawEllipse(m_pen, 50, 20, 30, 30);
    m_per->add("head");
}

void FatBuilder::buildBody()
{
    m_g->drawRectangle(m_pen, 60, 50, 10, 50);
    m_per->add("body");
}

void FatBuilder::buildArmLeft()
{
    m_g->drawLine(m_pen, 60, 50, 40, 100);
    m_per->add("arm_left");
}

void FatBuilder::buildArmRight()
{
    m_g->drawLine(m_pen, 70, 50, 40, 100);
    m_per->add("arm_right");
}

void FatBuilder::buildLegLeft()
{
    m_g->drawLine(m_pen, 60, 100, 45, 150);
    m_per->add("leg_left");
}

void FatBuilder::buildLegRight()
{
    m_g->drawLine(m_pen, 70, 100, 85, 150);
    m_per->add("leg_right");
}

Person *FatBuilder::getPerson()
{
    return m_per;
}

Director::Director(Builder *b)
{
    m_b = b;
}

void Director::createPerson()
{
    m_b->buildHead();
    m_b->buildBody();
    m_b->buildArmLeft();
    m_b->buildArmRight();
    m_b->buildLegLeft();
    m_b->buildLegRight();
}

int main()
{
    Pen *p = new Pen(Color::yellow);
    Graphics *g = new Graphics();

    std::cout << "thin person\n";
    ThinBuilder *tb = new ThinBuilder(g, p);
    Director *dtb = new Director(tb);
    dtb->createPerson();
    Person *tp = tb->getPerson();
    tp->show();

    std::cout << "fat person\n";
    FatBuilder *fb = new FatBuilder(g, p);
    Director *dfb = new Director(fb);
    dfb->createPerson();
    Person *fp = fb->getPerson();
    fp->show();

    return 0;
}
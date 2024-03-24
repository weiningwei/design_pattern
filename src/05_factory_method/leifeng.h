#ifndef _LEI_FENG_H
#define _LEI_FENG_H

class LeiFeng
{
public:
    LeiFeng(){};
    void sweep();
    void wash();
    void buyRice();
};

class ILeiFeng
{
public:
    ILeiFeng(){};
    virtual LeiFeng *createLeiFeng() const = 0;
};

#endif
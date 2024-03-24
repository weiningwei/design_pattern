#ifndef _PURSUIT_H
#define _PURSUIT_H

class IGiveGift
{
public:
    virtual void giveDollors() const = 0;
    virtual void giveFlowers() const = 0;
    virtual void giveChocolate() const = 0;
};

#endif
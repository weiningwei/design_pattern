#ifndef _RESUME_H
#define _RESUME_H

class Cloneable
{
public:
    virtual Cloneable *clone() const = 0;
};

#endif

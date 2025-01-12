#pragma once

#ifndef FIXCED_H__
#define FIXCED_H__
#include <iostream>

class Fixced
{
  private:
    int integer;
    static const int constInt = 8;
  public:

    Fixced();
    Fixced(const Fixced &other);
    Fixced &operator=(const Fixced &other);
    ~Fixced();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
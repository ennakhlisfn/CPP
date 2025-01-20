#pragma once

#ifndef FIXED_H__
#define FIXED_H__
#include <iostream>

class Fixed
{
  private:
    int fixedPointValue;
    static const int fracBits = 8;
  public:

    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    friend std::ostream &operator<<(std::ostream &out, const Fixed &value);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

#endif

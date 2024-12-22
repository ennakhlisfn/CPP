#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie
{
  private:
    std::string name;
  public:
    Zombie(std::string n = "") : name(n){}
    void announce(void);
    ~Zombie(){};
};

Zombie* zombieHorde(int N, std::string name);

#endif
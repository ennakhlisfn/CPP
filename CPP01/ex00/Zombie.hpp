#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie
{
  private:
    std::string name;
  public:
    Zombie(std::string n){
      name = n;
    };
    void announce(void);
    ~Zombie(){
      std::cout << name << " is destructed"<< std::endl;
    };
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
#pragma once

#ifndef HUMANB_H__
#define HUMANB_H__

#include "Weapon.hpp"

class HumanB
{
  const char *name;
public:
  Weapon *Weap;
  void attack();
  void setWeapon(Weapon &w);
  HumanB(const char *na):name(na){}

  ~HumanB(){}
};


#endif
#pragma once

#ifndef HUMANA_H__
#define HUMANA_H__

#include "Weapon.hpp"

class HumanA
{
private:
  const char *name;
  Weapon &Weap;
public:
  HumanA(const char *na, Weapon &W): name(na), Weap(W){
    name = na;
    Weap = W;
    if (Weap.getType() == NULL)
      Weap.setType("knife");
  }
  void attack();

  ~HumanA(){}
};



#endif
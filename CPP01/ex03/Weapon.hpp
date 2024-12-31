#pragma once

#ifndef WEAPON_H__
#define WEAPON_H__

#include <iostream>

class Weapon
{
private:
  const char *type;

public:
  const char *getType();
  void setType(const char *t);
  Weapon(const char *t): type(t){
    void setType(const char *t);
  }

  ~Weapon(){}
};


#endif
#include "Weapon.hpp"

void Weapon::setType(const char *t){
  type = t;
}

const char *Weapon::getType(){
  return type;
}
#include "HumanB.hpp"

void  HumanB::setWeapon(Weapon &w){
  Weap = &w;
}

void HumanB::attack(){
  const char *tmp = Weap->getType();
  if (tmp == NULL)
    std::cout << name << " attacks with their "<< std::endl;
  else
    std::cout << name << " attacks with their "<< tmp << std::endl;
}
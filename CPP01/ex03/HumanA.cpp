#include "HumanA.hpp"

void HumanA::attack(){
  std::cout << name << " attacks with their " << Weap.getType() << std::endl;
}
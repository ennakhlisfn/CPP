#include "Zombie.hpp"

int main(){
  Zombie *z1 = newZombie("FOO");
  z1->announce();
  delete(z1);

  randomChump("foo");

  return 0;
}
#include "Fixced.hpp"


Fixced::Fixced(void): integer(0){
  std::cout << "Default constructor called" << std::endl;
}

Fixced::Fixced(const Fixced &other){
  std::cout << "Copy constructor called" << std::endl;
  integer = other.getRawBits();
}

Fixced &Fixced::operator=(const Fixced &other){
  std::cout << "Copy assignment operator called" << std::endl;
  integer = other.getRawBits();
  return *this;
}

Fixced::~Fixced(void){
  std::cout << "Destructor called"<< std::endl;
};

int Fixced::getRawBits(void) const{
    std::cout << "getRawBits member function called" <<std::endl;
    return integer;
}

void Fixced::setRawBits(int const raw){
    std::cout << "setRawBits member function called" <<std::endl;
    integer = raw;
}


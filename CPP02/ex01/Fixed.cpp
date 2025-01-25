#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat(); // Convert Fixed object to float and output
    return out;
}


Fixed::Fixed(void): fixedPointValue(0){
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
  std::cout << "Int constructor called" << std::endl;
  fixedPointValue = value << fracBits;
}

int ft_roundf(float v){
	int tmp = (int)v;
	float cent = tmp + 0.5;
	int sing = 1;

	if (v < 0){
		sing = -1;
		tmp = -tmp;
		v = -v;
		cent = -cent;
	}
	if (v >= cent) return (tmp + 1) * sing;

	return tmp * sing;
}

Fixed::Fixed(const float value){
  std::cout << "Float constructor called" << std::endl;
  fixedPointValue = static_cast<int>(ft_roundf(value * (1 << fracBits)));
}

Fixed::Fixed(const Fixed &other){
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
  std::cout << "Copy assignment operator called" << std::endl;
  fixedPointValue = other.getRawBits();
  return *this;
}

Fixed::~Fixed(void){
  std::cout << "Destructor called"<< std::endl;
};

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" <<std::endl;
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" <<std::endl;
    fixedPointValue = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(fixedPointValue) / (1 << fracBits);
}

int Fixed::toInt() const {
    return fixedPointValue >> fracBits; // Right shift to get integer part
}

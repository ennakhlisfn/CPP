#include "Harl.hpp"

int main(){
    Harl harl;

    harl.complain("ERROR");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    return 0;
}
#include "Harl.hpp"

int main(int arc, char *arv[]){
    Harl harl;

    if (arc != 2){
        std::cout << "Number of argument is incorrect!"<< std::endl;
        return 1;
    }

    harl.complain(arv[1]);
    return 0;
}
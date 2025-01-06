#include "Harl.hpp"

void Harl::debug(void){
    std::cout <<"[DEBUG]:"<<std::endl;
    std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"<<std::endl;
}

void Harl::info(void){
    std::cout <<"[INFO]:"<<std::endl;
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"<<std::endl;
}

void Harl::warning(void){
    std::cout <<"[WARNING]:"<<std::endl;
    std::cout<<"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n"<<std::endl;
}

void Harl::error(void){
    std::cout <<"[ERROR]:"<<std::endl;
    std::cout<<"This is unacceptable! I want to speak to the manager now.\n"<<std::endl;
}

void Harl::complain(std::string level){
    int N = 4;
    const char *levels[N] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[N])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for(int i = 0; i < N; i++){
        if (level == levels[i])
            N = i;
    }

    switch (N){
        case 0:
            (this->*funcs[0])();
            (this->*funcs[1])();
            (this->*funcs[2])();
            (this->*funcs[3])();
            break;
        case 1:
            (this->*funcs[1])();
            (this->*funcs[2])();
            (this->*funcs[3])();
            break;
        case 2:
            (this->*funcs[2])();
            (this->*funcs[3])();
            break;
        case 3:
            (this->*funcs[3])();
            break;

        default:
            std::cout <<"[ Probably complaining about insignificant problems ]"<<std::endl;
            break;
    }
}
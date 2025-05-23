#include "Harl.hpp"

void Harl::debug(void){
    std::cout <<"[DEBUG]:"<<std::endl;
    std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void Harl::info(void){
    std::cout <<"[INFO]:"<<std::endl;
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"<<std::endl;
}

void Harl::warning(void){
    std::cout <<"[WARNING]:"<<std::endl;
    std::cout<<"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error(void){
    std::cout <<"[ERROR]:"<<std::endl;
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level){
    int N = 4;
    const char *levels[N] = {"DEBUG", "ERROR", "INFO", "WARNING"};
    void (Harl::*funcs[N])(void) = {
        &Harl::debug,
        &Harl::error,
        &Harl::info,
        &Harl::warning
    };

    for(int i = 0; i < N; i++){
        if (level == levels[i])
            (this->*funcs[i])();
    }
}
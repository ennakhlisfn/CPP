#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void  Account::_displayTimestamp(){
  std::time_t now = std::time(NULL);
  std::tm*    timeInfo = std::localtime(&now);

  std::cout << "["
            << std::setfill('0')
            << std::setw(4) << (timeInfo->tm_year + 1900)
            << std::setw(2) << (timeInfo->tm_mon + 1)
            << std::setw(2) << timeInfo->tm_mday << "_"
            << std::setw(2) << timeInfo->tm_hour
            << std::setw(2) << timeInfo->tm_min
            << std::setw(2) << timeInfo->tm_sec
            << "] ";
}

Account::Account(int initial_deposit){
  _amount = initial_deposit;
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _accountIndex = _nbAccounts - 1;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

int Account::getNbAccounts(){
  return _nbAccounts;
}

int Account::getTotalAmount(){
  return _totalAmount;
}

int Account::getNbDeposits(){
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(){
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(){
  _displayTimestamp();
  std::cout << "accounts:"<< getNbAccounts() << ";total:"<< getTotalAmount() <<";deposits:" << 
  getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void  Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount 
  << ";deposit:" << deposit << ";amount:" << _amount + deposit 
  << ";nb_deposits:" << ++_nbDeposits << std::endl;
  _amount += deposit;
  _totalAmount += deposit;
  _totalNbDeposits++;
}

bool  Account::makeWithdrawal(int withdrawal){
  _displayTimestamp();
  if (_amount - withdrawal < 0){
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount 
    << ";withdrawal:refused" << std::endl;
    return false;
  }
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount 
  << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal
  << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  return true;
}

void  Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" <<
  _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account::~Account(){
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}
#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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
  getNbAccounts();
  getTotalAmount();
  getNbDeposits();
  getNbWithdrawals();
}
#include <iostream>
#include "BankAccount.h"
#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(char *n, double b, double ir) : BankAccount(n,b){
this->ir = ir;
}
//calculate interest gained using balance and ir, and deposit it into the SavingsAccount
void SavingsAccount::addInterest(){
	BankAccount::deposit(BankAccount::getBalance() * ir);
}

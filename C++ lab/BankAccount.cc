#include <iostream>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

BankAccount::BankAccount(){
	strcpy(this->name,"");
	this->balance = 0.0;
}

BankAccount::BankAccount(char *n, double b){
	strcpy(this->name,n);
	this->balance = b;
}


char * BankAccount::getName(){
	return this->name;
}

double BankAccount::getBalance(){
	return this->balance;
}

void BankAccount::deposit(double a){
	this->balance += a;
}

bool BankAccount::withdraw(double amount){
	if (this->balance >amount){
		this->balance -= amount;
		return 1;
	}
	return 0;
}
// Print a formatted string with information about the account
void BankAccount::toString() {
	std::cout << this->name << ": $" << this->balance <<"\n"<<endl ;
}

//transfer between accounts. return false if balance is insufficient
bool BankAccount::transfer(BankAccount *account, double amount){
	if(withdraw(amount)){
		account->deposit(amount);
		return 1;
	}
	return 0;
}

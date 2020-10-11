#include <iostream>
#include "BankAccount.h"
#include "CheckingAccount.h"

using namespace std;

CheckingAccount::CheckingAccount(char *n,double b) : BankAccount(n,b){
	transactionCount = 0;
}

//calculate fees, attempt to with draw from the account. Print, return false if balance is in sufficient
bool CheckingAccount::deductFees(){
	double fees = transactionCount * TRANSACTION_FEE;
if(BankAccount::withdraw(fees)){
	transactionCount = 0;
	return 1;
}
	cout << "Insufficient money to pay fees."<<endl;
	return 0;
}
//deposit into the CheckingAccount
void CheckingAccount::deposit(double amount){
	transactionCount++;
	BankAccount::deposit(amount);
}
//withdraw from the CheckingAccount, return false if balance is insufficient
bool CheckingAccount::withdraw(double amount){
	transactionCount++;
	if(BankAccount::withdraw(amount)){
		return 1;
	}
	return 0;
}

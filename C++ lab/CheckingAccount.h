#ifndef CHECKINGACCOUNT_H_
#define CHECKINGACCOUNT_H_

#include "BankAccount.h"


class CheckingAccount : public BankAccount{

public:
	CheckingAccount(char *n,double b);

	bool withdraw(double a);
	void deposit(double a);

	bool deductFees();
private:
	int transactionCount;
	const double TRANSACTION_FEE = 3.0;
};

#endif

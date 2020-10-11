#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

#include "BankAccount.h"

class SavingsAccount : public BankAccount {

public:
	SavingsAccount(char *n, double b, double ir);

	void addInterest();
private:
  double ir;

};

#endif

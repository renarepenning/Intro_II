#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

class BankAccount{
public:
	BankAccount();
	BankAccount(char *n, double b);

	char *getName();
	double getBalance();
	void toString();

	void deposit(double a);
	bool withdraw(double a);

	bool transfer(BankAccount *a, double b);

private:
	char name[100];
	double balance;
};

#endif

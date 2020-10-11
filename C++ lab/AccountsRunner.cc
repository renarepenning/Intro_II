#include <iostream>
//Include relevant header files
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <string>
#include <sstream>
#include <cstring>

int main() {
  char* acctName = "Starter"; // create char array pointer to name the accounts
  //instantiate BankAccount on the heap
  BankAccount* starter = new BankAccount (acctName, 0);
  acctName = "Advanced";
  BankAccount* advanced = new BankAccount (acctName, 500);
  starter->deposit(1000);
  advanced->withdraw(100);
  starter->transfer(advanced, 200);
  //print changes
  starter->toString();
  advanced->toString();

  //Name and instantiate (on heap) instance of each subclass
  acctName = "Savings Acct";
  SavingsAccount* savAcct = new SavingsAccount (acctName, 0, .01);
  acctName = "Checking Acct";
  CheckingAccount* checkAcct = new CheckingAccount (acctName, 500);
  //Test superclass methods
  savAcct->deposit(1000);
  checkAcct->withdraw(100);
  savAcct->transfer(checkAcct, 200);
  //test sub class methods
  savAcct->addInterest();
  checkAcct->deductFees();
  //print changes
  savAcct->toString();
  checkAcct->toString();

  //Deconstructor
  //To free the memory allocated for the object, from the heap
  delete(starter);
  delete(advanced);
  delete(savAcct);
  delete(checkAcct);
}

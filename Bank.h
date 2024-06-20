#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string> // Include for string
#include "Account.h"

class Bank {
private:
  std::vector<Account> accounts;
  int nextAccountNumber;

public:
  Bank();

  // Create an account
  Account* createAccount(const std::string& ownerName, double initialDeposit);

  // Find an account by number
  const Account& findAccount(int accountNumber) const;

  // Transfer funds between accounts (using references)
  bool transfer(const Account& fromAccount, const Account& toAccount, double amount);

  // Apply for a loan (depositing to the account and adding a transaction)
  void applyForLoan(const Account& account, double amount);

  // Calculate interest on all accounts and add transactions
  void calculateInterest(double rate);

  // Format a double amount as currency
  std::string getFormattedCurrency(double amount) const;
};

#endif



#include "Account.h"
#include <iostream>
#include <iomanip> // Include for std::put_money
#include <sstream> // Include for string manipulation

Account::Account(int accountNumber, const std::string &ownerName, const std::string &address,
                  const std::string &contactDetails, const std::string &password, double initialDeposit)
  : accountNumber(accountNumber), ownerName(ownerName), address(address), contactDetails(contactDetails),
    password(password), balance(initialDeposit), closed(false) {
  addTransaction(Transaction("Deposit", "Income", initialDeposit, "Initial Deposit"));
}

int Account::getAccountNumber() const {
  return accountNumber;
}

std::string Account::getOwnerName() const {
  return ownerName;
}

std::string Account::getAddress() const {
  return address;
}

std::string Account::getContactDetails() const {
  return contactDetails;
}

double Account::getBalance() const {
  return balance;
}

std::string Account::getFormattedBalance() const {
  std::stringstream ss;
  ss.imbue(std::locale("")); // Set the locale to the default locale
  ss << std::put_money(balance * 100); // Multiply by 100 because std::put_money expects amount in cents
  return ss.str();
}

bool Account::isClosed() const {
  return closed;
}

void Account::updateAccountInfo(const std::string &newName, const std::string &newAddress,
                                 const std::string &newContactDetails, const std::string &newPassword) {
  if (!closed) {
    ownerName = newName;
    address = newAddress;
    contactDetails = newContactDetails;
    password = newPassword;
    std::cout << "Account information updated successfully." << std::endl;
  } else {
    std::cout << "Cannot update information for a closed account." << std::endl;
  }
}

void Account::closeAccount() {
  if (!closed) {
    balance = 0.0;
    closed = true;
    std::cout << "Account closed successfully." << std::endl;
  } else {
    std::cout << "Account is already closed." << std::endl;
  }
}

void Account::deposit(double amount) {
  if (amount > 0) {
    balance += amount;
    addTransaction(Transaction("Deposit", "Income", amount, "Deposit"));
  } else {
    std::cout << "Invalid deposit amount. Please enter a positive value." << std::endl;
  }
}

bool Account::withdraw(double amount) {
  if (amount > 0 && amount <= balance) {
    balance -= amount;
    addTransaction(Transaction("Withdrawal", "Expense", amount, "Withdrawal"));
    return true;
  } else {
    if (amount <= 0) {
      std::cout << "Invalid withdrawal amount. Please enter a positive value." << std::endl;
    } else {
      std::cout << "Insufficient balance!" << std::endl;
    }
    return false;
  }
}

void Account::addTransaction(const Transaction &transaction) {
  transactions.push_back(transaction);
}

void Account::printStatement() const {
  std::cout << "Account Statement for " << ownerName << " (Account Number: " << accountNumber << ")\n";
  std::cout << "Balance: " << getFormattedBalance() << "\n"; // Use getFormattedBalance()
  std::cout << "Transactions:\n";
  for (const auto &transaction : transactions) {
    std::cout << transaction.getDate() << " - " << transaction.getType() << ": "
              << transaction.getAmount() << " (" << transaction.getDescription() << ")\n";
  }
}

void Account::printCategorySummary() const {
  std::map<std::string, double> categoryTotals;
  for (const auto &transaction : transactions) {
    categoryTotals[transaction.getCategory()] += transaction.getAmount();
  }

  std::cout << "Category Summary for Account " << accountNumber << ":\n";
  for (const auto &entry : categoryTotals) {
    std::cout << entry.first << ": " << entry.second << "\n";
  }
}

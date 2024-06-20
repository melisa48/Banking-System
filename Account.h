#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <string>
#include <map> // Include for category summary reports
#include "Transaction.h"

class Account {
private:
    int accountNumber;
    std::string ownerName;
    std::string address;
    std::string contactDetails;
    std::string password;  // You might want to hash this for security reasons
    double balance;
    bool closed;
    std::vector<Transaction> transactions;

public:
    Account(int accountNumber, const std::string &ownerName, const std::string &address, 
            const std::string &contactDetails, const std::string &password, double initialDeposit);

    // Getters
    int getAccountNumber() const;
    std::string getOwnerName() const;
    std::string getAddress() const;
    std::string getContactDetails() const;
    double getBalance() const;
    std::string getFormattedBalance() const; // Add this for formatted balance
    bool isClosed() const;

    // Account management methods
    void updateAccountInfo(const std::string &newName, const std::string &newAddress, 
                           const std::string &newContactDetails, const std::string &newPassword);
    void closeAccount();

    // Transaction methods
    void deposit(double amount);
    bool withdraw(double amount);
    void addTransaction(const Transaction &transaction);
    void printStatement() const;

    // Transaction categorization
    void printCategorySummary() const; // Method to print summary of transactions by category
};

#endif

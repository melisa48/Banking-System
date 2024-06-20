#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
private:
    std::string transactionType;
    std::string category; // New field for transaction category
    double amount;
    std::time_t date;
    std::string description;

public:
    Transaction(const std::string &type, const std::string &category, double amount, const std::string &description);

    std::string getType() const;
    std::string getCategory() const; // Getter for category
    double getAmount() const;
    std::string getDate() const;
    std::string getDescription() const;
};

#endif

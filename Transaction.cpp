#include "Transaction.h"
#include <ctime>
#include <iomanip>
#include <sstream>

Transaction::Transaction(const std::string &type, const std::string &category, double amount, const std::string &description)
    : transactionType(type), category(category), amount(amount), description(description) {
    date = std::time(nullptr);
}

std::string Transaction::getType() const {
    return transactionType;
}

std::string Transaction::getCategory() const {
    return category;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDate() const {
    std::stringstream ss;
    ss << std::put_time(std::localtime(&date), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::string Transaction::getDescription() const {
    return description;
}


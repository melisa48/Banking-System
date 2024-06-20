#include "Bank.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Transaction.h"
#include "Account.h"

Bank::Bank() : nextAccountNumber(1) {}

Account* Bank::createAccount(const std::string& ownerName, double initialDeposit) {
    accounts.emplace_back(nextAccountNumber++, ownerName, initialDeposit);
    return &accounts.back();
}

const Account& Bank::findAccount(int accountNumber) const {
    for (const auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return account;
        }
    }
    throw std::runtime_error("Account not found");
}

bool Bank::transfer(const Account& fromAccount, const Account& toAccount, double amount) {
    Account& modFromAccount = const_cast<Account&>(fromAccount);
    Account& modToAccount = const_cast<Account&>(toAccount);

    if (!modFromAccount.withdraw(amount)) {
        return false;
    }

    modToAccount.deposit(amount);
    return true;
}

void Bank::applyForLoan(const Account& account, double amount) {
    Account& modAccount = const_cast<Account&>(account);
    modAccount.deposit(amount);
    modAccount.addTransaction(Transaction("Loan", "Loan", amount, "Loan Granted"));
}

void Bank::calculateInterest(double rate) {
    for (auto& account : accounts) {
        double interest = account.getBalance() * rate;
        account.deposit(interest);
        account.addTransaction(Transaction("Interest", "Interest", interest, "Interest Added"));
    }
}

std::string Bank::getFormattedCurrency(double amount) const {
    std::stringstream ss;
    ss.imbue(std::locale(""));
    ss << std::put_money(amount);
    return ss.str();
}


#include <iostream>
#include "Bank.h"
#include <limits>

void showMenu() {
    std::cout << "\nBanking System Menu:\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Transfer\n";
    std::cout << "5. View Statement\n";
    std::cout << "6. Apply for Loan\n";
    std::cout << "7. Calculate Interest\n";
    std::cout << "8. Exit\n";
}

int main() {
    Bank bank;
    int choice;

    while (true) {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 8) break;

        switch (choice) {
            case 1: {
                std::string name;
                double initialDeposit;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter owner name: ";
                std::getline(std::cin, name);
                std::cout << "Enter initial deposit: ";
                std::cin >> initialDeposit;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Account* account = bank.createAccount(name, initialDeposit);
                if (account) {
                    std::cout << "Account created. Account Number: " << account->getAccountNumber() << "\n";
                } else {
                    std::cout << "Failed to create account.\n";
                }
                break;
            }
            case 2: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                const Account& accountRef = bank.findAccount(accountNumber);
                Account* account = const_cast<Account*>(&accountRef);
                if (account) {
                    account->deposit(amount);
                    std::cout << "Deposit successful.\n";
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                const Account& accountRef = bank.findAccount(accountNumber);
                Account* account = const_cast<Account*>(&accountRef);
                if (account) {
                    if (account->withdraw(amount)) {
                        std::cout << "Withdrawal successful.\n";
                    } else {
                        std::cout << "Insufficient funds.\n";
                    }
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                int fromAccount, toAccount;
                double amount;
                std::cout << "Enter source account number: ";
                std::cin >> fromAccount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter destination account number: ";
                std::cin >> toAccount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter amount to transfer: ";
                std::cin >> amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                const Account& fromAccountRef = bank.findAccount(fromAccount);
                const Account& toAccountRef = bank.findAccount(toAccount);
                if (bank.transfer(fromAccountRef, toAccountRef, amount)) {
                    std::cout << "Transfer successful.\n";
                } else {
                    std::cout << "Transfer failed.\n";
                }
                break;
            }
            case 5: {
                int accountNumber;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                const Account& accountRef = bank.findAccount(accountNumber);
                Account* account = const_cast<Account*>(&accountRef);
                if (account) {
                    account->printStatement();
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 6: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter loan amount: ";
                std::cin >> amount;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                const Account& accountRef = bank.findAccount(accountNumber);
                bank.applyForLoan(accountRef, amount);
                std::cout << "Loan applied successfully.\n";
                break;
            }
            case 7: {
                double rate;
                std::cout << "Enter interest rate: ";
                std::cin >> rate;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                bank.calculateInterest(rate);
                std::cout << "Interest calculated for all accounts.\n";
                break;
            }
            default: {
                std::cout << "Invalid choice.\n";
                break;
            }
        }
    }

    return 0;
}
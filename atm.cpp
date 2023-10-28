#include <iostream>
#include <ctime>
#include <string>

class User {
private:
    std::string name;
    int accountNumber;
    int pin;
    double balance;

public:
    User(std::string userName, int accNumber, int userPin, double userBalance)
        : name(userName), accountNumber(accNumber), pin(userPin), balance(userBalance) {}

    int getAccountNumber() {
        return accountNumber;
    }

    int getPin() {
        return pin;
    }

    double getBalance() {
        return balance;
    }

    std::string getName() {
        return name;
    }

    void displayBalance() {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit successful. Current balance: $" << balance << std::endl;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal successful. Current balance: $" << balance << std::endl;
            return true;
        } else {
            std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
            return false;
        }
    }
};

class ATM {
public:
    void displayDateTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        std::cout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << std::endl;
        std::cout << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << std::endl;
    }

    void displayMenu() {
        std::cout << "ATM Menu:" << std::endl;
        std::cout << "1. Display Balance" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Exit" << std::endl;
    }
};

int main() {
    User user("Karan Thacker", 123456, 12345, 1000.00); // Creating a user

    ATM atm;

    int enteredAccountNumber, enteredPin;
    std::cout << "Enter Account Number: ";
    std::cin >> enteredAccountNumber;

    std::cout << "Enter PIN: ";
    std::cin >> enteredPin;

    if (enteredAccountNumber == user.getAccountNumber() && enteredPin == user.getPin()) {
        std::cout << "Welcome, " << user.getName() << "!" << std::endl;

        atm.displayDateTime(); // Display date and time

        int choice;
        do {
            atm.displayMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    user.displayBalance();
                    break;
                case 2:
                    double depositAmount;
                    std::cout << "Enter deposit amount: $";
                    std::cin >> depositAmount;
                    user.deposit(depositAmount);
                    break;
                case 3:
                    double withdrawAmount;
                    std::cout << "Enter withdrawal amount: $";
                    std::cin >> withdrawAmount;
                    user.withdraw(withdrawAmount);
                    break;
                case 4:
                    std::cout << "Exiting. Thank you!" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice != 4);
    } else {
        std::cout << "Invalid Account Number or PIN. Access denied." << std::endl;
    }

    return 0;
}
#include <stdio.h>
#include <time.h>

struct Bank {
    char name[50];
    float balance;
};

void deposit(struct Bank *bank, float amount) {
    if (amount > 0) {
        bank->balance += amount;
        printf("Deposited $%.2f. Current Balance: $%.2f\n", amount, bank->balance);
    } else {
        printf("Invalid amount. Please enter a valid amount.\n");
    }
}

void withdraw(struct Bank *bank, float amount) {
    if (amount > 0 && amount <= bank->balance) {
        bank->balance -= amount;
        printf("Withdrawn $%.2f. Current Balance: $%.2f\n", amount, bank->balance);
    } else {
        printf("Insufficient funds or invalid amount. Please try again.\n");
    }
}

void checkBalance(struct Bank *bank) {
    printf("Current Balance: $%.2f\n", bank->balance);
}

void showBankInfo(struct Bank *bank) {
    printf("Bank Information:\nName: %s\nEstablished: 2000\nLocation: Ahemdabad, India\n", bank->name);
}

void showDateTime() {
    time_t now = time(NULL);
    printf("Date and Time: %s", ctime(&now));
}

int main() {
    struct Bank myBank = {"TOPSBank", 1000};
    const int ATM_PIN = 12345;

    int enteredPIN;
    printf("Please enter your ATM PIN: ");
    scanf("%d", &enteredPIN);

    if (enteredPIN != ATM_PIN) {
        printf("Incorrect PIN. Exiting...\n");
        return 1;
    }

    showDateTime();

    while (1) {
        printf("\n===== Welcome to TOPSBank ATM =====\n");
        printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Bank Information\n5. Date and Time\n6. Exit\n");

        int choice;
        printf("Please choose an option: ");
        scanf("%d", &choice);

        float amount;
        switch (choice) {
            case 1:
                printf("Enter the amount to deposit: $");
                scanf("%f", &amount);
                deposit(&myBank, amount);
                break;
            case 2:
                printf("Enter the amount to withdraw: $");
                scanf("%f", &amount);
                withdraw(&myBank, amount);
                break;
            case 3:
                checkBalance(&myBank);
                break;
            case 4:
                showBankInfo(&myBank);
                break;
            case 5:
                showDateTime();
                break;
            case 6:
                printf("Thank you for using TOPSBank ATM. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}






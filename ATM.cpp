#include <iostream>
using namespace std;

int main() {
    int pin = 8822;        // predefined correct PIN
    int enterYourPin;
    int balance = 696969690;    // initial balance
    int choice;
    int amount;
    bool isAuthenticated = false;

    cout << "====== Welcome to ATM ======\n";
    

    // PIN validation
    for (int i = 0; i < 3; i++) {  // max 3 attempts
        cout << "Enter your ATM PIN: ";
        cin >> enterYourPin;

        if (enterYourPin == pin) {
            isAuthenticated = true;
            break;
        } else {
            cout << "Invalid PIN. Try again.\n";
        }
    }

    if (!isAuthenticated) {
        cout << "Too many wrong attempts. Exiting...\n";
        return 0;
    }

    do {
        cout << "\n===== ATM Menu =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Your current balance is: " << balance << "\n";
                
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << " Your amount is Successfully deposited. New balance: " << balance << "\n";
                } else {
                    cout << "Invalid amount.\n";
                }
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    cout << "Successfully withdrawn. New balance: " << balance << "\n";
                } else {
                    cout << "Insufficient balance.\n";
                }
                break;

            case 4:
                cout << "😊 Thank you for using the ATM 😊\n";
                break;

            default:
                cout << " ❌ Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
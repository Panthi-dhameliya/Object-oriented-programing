#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amount, string log[], int &i) {
        log[i++] = "Entered deposit()";

        if (amount <= 0) {
            throw "Invalid deposit amount!";
        }

        balance += amount;
        log[i++] = "Deposit successful";

        log[i++] = "Exiting deposit()";
    }

    void withdraw(double amount, string log[], int &i) {
        log[i++] = "Entered withdraw()";

        if (amount <= 0) {
            throw "Invalid withdrawal amount!";
        }

        if (amount > balance) {
            throw "Insufficient balance!";
        }

        balance -= amount;
        log[i++] = "Withdrawal successful";

        log[i++] = "Exiting withdraw()";
    }

    double getBalance() {
        return balance;
    }
};

// Function to simulate transaction flow
void processTransaction(BankAccount &acc, string log[], int &i) {
    log[i++] = "Entered processTransaction()";

    acc.deposit(500, log, i);
    acc.withdraw(2000, log, i);  // This will cause exception

    log[i++] = "Exiting processTransaction()";
}

int main() {
    string log[20];
    int i = 0;

    BankAccount acc(1000);

    try {
        log[i++] = "Entered main()";

        processTransaction(acc, log, i);

        log[i++] = "Exiting main()";
    }

    catch (const char* msg) {
        log[i++] = "Exception caught in main()";
        log[i++] = msg;
    }

    // Display logs
    cout << "\n--- Transaction Log ---\n";
    for (int j = 0; j < i; j++) {
        cout << log[j] << endl;
    }

    cout << "\nFinal Balance: " << acc.getBalance() << endl;

    return 0;
}

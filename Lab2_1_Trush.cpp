#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string owner;
    double balance;
public:
    BankAccount(const string& ownerName, double initialBalance = 0.0)
        : owner(ownerName), balance(initialBalance) {}

    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " to " << owner << "'s account.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " from " << owner << "'s account.\n";
        } else {
            cout << "Invalid withdraw amount or insufficient funds.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    string getOwner() const {
        return owner;
    }
};

class Bank {
private:
    vector<BankAccount> accounts;
public:
    void addAccount(const BankAccount& account) {
        accounts.push_back(account);
    }

    BankAccount* findAccount(const string& ownerName) {
        for(auto& acc : accounts) {
            if(acc.getOwner() == ownerName)
                return &acc;
        }
        return nullptr;
    }

    void showAllAccounts() const {
        cout << "\n--- All Accounts ---\n";
        for(const auto& acc : accounts) {
            cout << acc.getOwner() << ": " << fixed << setprecision(2) << acc.getBalance() << "\n";
        }
        cout << "-------------------\n";
    }
};

int main() {
    Bank myBank;
    myBank.addAccount(BankAccount("Alice", 1000));
    myBank.addAccount(BankAccount("Bob", 500));

    int choice;
    string name;
    double amount;

    do {
        cout << "\nBank Menu:\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Show All Accounts\n0. Exit\nChoice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter account owner: ";
                cin >> name;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if(auto acc = myBank.findAccount(name))
                    acc->deposit(amount);
                else
                    cout << "Account not found.\n";
                break;
            case 2:
                cout << "Enter account owner: ";
                cin >> name;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if(auto acc = myBank.findAccount(name))
                    acc->withdraw(amount);
                else
                    cout << "Account not found.\n";
                break;
            case 3:
                cout << "Enter account owner: ";
                cin >> name;
                if(auto acc = myBank.findAccount(name))
                    cout << acc->getOwner() << "'s balance: " << acc->getBalance() << "\n";
                else
                    cout << "Account not found.\n";
                break;
            case 4:
                myBank.showAllAccounts();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 0);

    return 0;
}





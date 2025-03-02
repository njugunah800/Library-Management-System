#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>  // For Sleep() function

using namespace std;

struct Record {
    char Bank_Name[50];
    char Branch[50];
    char Name[50];
    int PIN;
    int Account_No;
    int Amount;
};

void delay(int milliseconds) {
    Sleep(milliseconds); // Windows-specific function
}

int main() {
    Record r;
    int choice, inputPin, attempts = 0;
    bool accessGranted = false;

    FILE *fp;
    
    // Open file for reading & updating
    fp = fopen("Project.dat", "rb+");
    if (fp == NULL) {
        cout << "Error: File not found!" << endl;
        return 1;
    }

    cout << "\n\tWELCOME TO ATM SERVICE\n";
    cout << "----------------------------------\n";

    // PIN authentication (3 attempts)
    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> inputPin;

        while (fread(&r, sizeof(r), 1, fp)) {
            if (r.PIN == inputPin) {
                accessGranted = true;
                break;
            }
        }

        if (accessGranted) {
            cout << "Access Granted!\n";
            break;
        } else {
            cout << "Incorrect PIN! Try again.\n";
            attempts++;
            rewind(fp);  // Reset file pointer for next attempt
        }
    }

    if (!accessGranted) {
        cout << "Too many incorrect attempts! Exiting...\n";
        fclose(fp);
        return 1;
    }

    // ATM Menu
    do {
        cout << "\nATM MENU\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Your current balance: Rs." << r.Amount << endl;
                break;
            case 2: {
                int deposit;
                cout << "Enter amount to deposit: Rs.";
                cin >> deposit;
                r.Amount += deposit;
                cout << "Deposit successful! New balance: Rs." << r.Amount << endl;
                break;
            }
            case 3: {
                int withdraw;
                cout << "Enter amount to withdraw: Rs.";
                cin >> withdraw;
                if (withdraw > r.Amount) {
                    cout << "Insufficient balance!\n";
                } else {
                    r.Amount -= withdraw;
                    cout << "Withdrawal successful! Remaining balance: Rs." << r.Amount << endl;
                }
                break;
            }
            case 4:
                cout << "Thank you for using our ATM service!\n";
                fclose(fp);
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cout << "Press any key to continue...\n";
        getchar(); // Pause before next loop iteration
        getchar(); // To consume the newline character

    } while (true);

    fclose(fp);
    return 0;
}

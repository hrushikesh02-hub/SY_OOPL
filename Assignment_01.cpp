#include <iostream>
using namespace std;

class BankAccount
{
private:
    string name;
    long long mobile_number;
    int balance;
    int pin;
    string account_type;

public:
    int account_number;
    void CreateAccount()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Account Number: ";
        cin >> account_number;
        cout << "Enter Mobile Number: ";
        cin >> mobile_number;
        cout << "Enter Account Type (Savings/Current) : ";
        cin >> account_type;

        while (true)
        {
            cout << "Set 4-digit PIN: ";
            cin >> pin;
            if (pin >= 1000 && pin <= 9999)
                break;
            else
                cout << "Invalid PIN! Must be 4 digits.\n";
        }
        cout << "Enter Initial Amount : ";
        cin >> balance;

        cout << "Account Created Successfully!" << endl;
    }

    bool VerifyPIN()
    {
        int input_pin;
        cout << "Enter 4-digit PIN: ";
        cin >> input_pin;
        if (input_pin == pin)
            return true;
        else
        {
            cout << "Incorrect PIN!" << endl;
            return false;
        }
    }

    void DepositMoney()
    {
        int deposit;
        cout << "Enter Amount to Deposit: ";
        cin >> deposit;
        balance += deposit;
        cout << "Amount Deposited Successfully!" << endl;
        cout << "Available Balance: " << balance << endl;
    }

    void WithdrawMoney()
    {
        int withdraw;
        cout << "Enter Amount to Withdraw: ";
        cin >> withdraw;
        if (balance == 0 || balance < withdraw)
        {
            cout << "Insufficient Funds!" << endl;
        }
        else
        {
            balance -= withdraw;
            cout << "Withdrawal Successful!" << endl;
            cout << "Available Balance: " << balance << endl;
        }
    }

    void DisplayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Mobile No.: " << mobile_number << endl;
        cout << "Account Type : " << account_type << endl;
        cout << "Available Balance: " << balance << endl;
    }
};

int main()
{
    int choice, acc_no;
    BankAccount accounts[100];
    int total_accounts = 0;
    cout << "----------BANKING SYSTEM----------" << endl;
    while (true)
    {
        cout << "\n1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Display Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            accounts[total_accounts].CreateAccount();
            total_accounts++;
            break;

        case 2:
        case 3:
        case 4:
            cout << "Enter Account Number: ";
            cin >> acc_no;
            {
                bool found = false;
                for (int i = 0; i < total_accounts; i++)
                {
                    if (accounts[i].account_number == acc_no)
                    {
                        found = true;
                        if (accounts[i].VerifyPIN())
                        {
                            if (choice == 2)
                                accounts[i].DepositMoney();
                            else if (choice == 3)
                                accounts[i].WithdrawMoney();
                            else
                                accounts[i].DisplayDetails();
                        }
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Account Not Found!" << endl;
                }
            }
            break;

        case 5:
            cout << "Thank You.......!" << endl;
            return 0;

        default:
            cout << "Invalid Choice!" << endl;
        }
    }
}

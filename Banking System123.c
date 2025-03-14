#include<iostream>
using namespace std;

class Bank
{
    private:
        int acno;
        char name[30];
        long balance;
        
    public:
        void OpenAccount()
        {
            cout << "Enter the Account Number: ";
            cin >> acno;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> balance;
        } 

        void ShowAccount()
        {
            cout << "\nAccount Number: " << acno << endl;
            cout << "Name: " << name << endl;
            cout << "Balance: " << balance << endl;
        }

        void Deposit()
        {
            long amt;
            cout << "Enter Amount to Deposit: ";
            cin >> amt;
            balance = balance + amt;
            cout << "Amount Deposited Successfully.\n";
        }

        void Withdrawal()
        {
            long amt;
            cout << "Enter Amount to Withdraw: ";
            cin >> amt;
            if (amt <= balance) {
                balance = balance - amt;
                cout << "Amount Withdrawn Successfully.\n";
            } else {
                cout << "Insufficient Balance.\n";
            }
        }

        int Search(int a)
        {
            if (acno == a)
            {
                ShowAccount();
                return 1;
            }
            return 0;
        }
};

int main()
{
    Bank C[3];
    int found = 0, a, ch, i;

    for (i = 0; i < 3; i++)
    {
        C[i].OpenAccount();
    }

    do
    {
        cout << "\n\n1: Display All\n2: Search by Account No\n3: Deposit\n4: Withdraw\n5: Exit\n";
        cout << "Please input your choice: ";
        cin >> ch;
        
        switch (ch)
        {
            case 1:
                for (i = 0; i < 3; i++)
                {
                    C[i].ShowAccount();
                }
                break;

            case 2:
                cout << "Enter Account Number to Search: ";
                cin >> a;
                found = 0;
                for (i = 0; i < 3; i++)
                {
                    found = C[i].Search(a);
                    if (found) break;
                }
                if (!found) cout << "Record Not Found.\n";
                break;

            case 3:
                cout << "Enter Account Number to Deposit Amount: ";
                cin >> a;
                found = 0;
                for (i = 0; i < 3; i++)
                {
                    if (C[i].Search(a))
                    {
                        C[i].Deposit();
                        found = 1;
                        break;
                    }
                }
                if (!found) cout << "Record Not Found.\n";
                break;

            case 4:
                cout << "Enter Account Number to Withdraw Amount: ";
                cin >> a;
                found = 0;
                for (i = 0; i < 3; i++)
                {
                    if (C[i].Search(a))
                    {
                        C[i].Withdrawal();
                        found = 1;
                        break;
                    }
                }
                if (!found) cout << "Record Not Found.\n";
                break;

            case 5:
                cout << "Have a nice day!\n";
                break;

            default:
                cout << "Invalid Choice. Please try again.\n";
        }

    } while (ch != 5);

    return 0;
}

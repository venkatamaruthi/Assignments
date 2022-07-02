#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Account
{
    protected:
    
     string name;
     string accTy;
     int acctNo;
     int accBal;
     
    public:
        //Account (){}
        void createAcc();
        void getDetails();
        void displayDetails();
        void makeAccount();
};
void Account::getDetails()
        {
            cout<<"enter customer name: ";
            cin>>name;
            cout<<"enter Acoount number: ";
            cin>>acctNo;
            cout<<"enter Type of the account: ";
            cin>>accTy;
            cout<<"enter the initial amount :";
            cin>>accBal;
        }
void Account::displayDetails()
        {
            cout<<"Account Holder name: "<<name<<endl;
            cout<<"Account number: "<<acctNo<<endl;
            cout<<"Account type is : "<<accTy<<endl;
            cout<<"Amount is :"<<accBal<<endl;
        }
void Account::createAcc()
        {
            cout<<endl;
            cout<<"******Account created & Details are******* "<<endl;
            displayDetails();
        }
void Account::makeAccount()
{
    Account a;
    ofstream o;
    o.open("account.txt", ios::in|ios::app);
    getDetails();
    o.write(reinterpret_cast<char *> (&a), sizeof(Account));
    o.close();
}
/*class Login : public Account
{
    protected:
        Account a;
        char username[30];
        int password;
    public:
       /* char* getUser()
        {
            return username;
        }
        int getPass()
        {
            return password;
        }
        void loginGet()
        {
            cout<<"enter username :"<<endl;
            cin>>username;
            cout<<"enter the password :"<<endl;
            cin>>password;
        }
        void loginDisplay()
        {
            cout<<"userName is :"<<username<<endl;
            cout<<"password is : "<<password<<endl;
        }
       // a.displayDetails();
        
        };*/
        
    

class Savings  : public Account
{
    
    public:
        void moneyDisplay()
        {
            cout<<"\nBalance is : "<<accBal;
        }
        void moneyDeposite()
        {
            float dep;
            cout<<"Enter the amount to deposit : ";
            cin>>dep;
            accBal+=dep;
            cout<<"Balance is :"<<accBal<<endl;
            
            //cout<<accBal<<endl;
            
        }
        void moneyWithdraw()
        {
            float withDraw;
            cout<<"\nYour balance is : "<<accBal<<endl;
            cout<<"\nEnter amount to withdraw: ";
            cin>>withDraw;
            if(withDraw < accBal)
            {
                accBal-=withDraw;
                cout<<"After withdraw your balance is : "<<accBal<<endl;
            }
            else
            {
            cout<<"unable to withdraw due to insufficient balance";
            }
        }
};

int main()
{
    Account a;
    Savings s;
   // Login l;
    int choice;
    s.getDetails();
    //l.loginDisplay();
    do
    {
        cout<<"****************************"<<endl;
        cout<<"Enter your choice : "<<endl;
      //  cout<<"for login ............... type 1:"<<endl;
        cout<<"For Account creation..... type 2"<<endl;
        cout<<"For Money Deposit........ type 3 "<<endl;
        cout<<"For Money Withdraw....... type 4 "<<endl;
        cout<<"For Display your Bal....  type 5"<<endl;
        cout<<"For Display full details. type 6"<<endl;
        cout<<"To EXIT type 7"<<endl;
        cin>>choice;
        switch(choice)
        {
            //case 1:
                   // l.loginDisplay();
            case 2:
                    a.createAcc();
                    break;
            case 3: 
                    s.moneyDeposite();
                    break;
            case 4:
                    s.moneyWithdraw();
                    break;
            case 5:
                    s.moneyDisplay();
                    break;
            case 6:
                    s.displayDetails();
                    s.moneyDisplay();
                    break;
            case 7:
                    cout<<"Thanks for Axis Bank"<<endl;
                    break;
            default:
                    cout<<"\n The choice is invalid "<<endl;
                    cout<<"\a";
        }
    }
        while(choice!=6);
        return 0;
}
        
        
    
/*void makeAccount()
{
    Account a;
    ofstream o;
    o.open("account.txt", ios::in|ios::app);
    a.creatAcc();
    o.write(reinterpret_cast<char *> (&a), sizeof(Account));
    o.close();
}*/

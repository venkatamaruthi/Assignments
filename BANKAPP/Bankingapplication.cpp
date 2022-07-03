#include <iostream>
#include<string>
#include<fstream>

using namespace std;
class Account
{
    protected:
    
     string name;
     string accTy;
     long int dbcard;
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
            cout<<"enter Debit-card number: ";
            cin>>dbcard;
            cout<<"enter Type of the account: ";
            cin>>accTy;
            cout<<"enter the initial amount :";
            cin>>accBal;
        }
void Account::displayDetails()
        {
            cout<<"Account Holder name: "<<name<<endl;
            cout<<"Debit number: "<<dbcard<<endl;
            cout<<"Account type is : "<<accTy<<endl;
            cout<<"Amount is :"<<accBal<<endl;
        }
void Account::createAcc()
        {
            cout<<endl;
            cout<<"******Account created & Details are******* "<<endl;
            displayDetails();
        }
class Savings  : public Account
{
    
    public:
      /*  void moneyDisplay()
        {
            cout<<"\nBalance is : "<<accBal;
        }*/
        void moneyDeposite()
        {
            int dep;
            cout<<"Enter the amount to deposit : ";
            cin>>dep;
            accBal+=dep;
            cout<<"Balance is : "<<accBal<<endl;
            
            //cout<<accBal<<endl;
            
        }
         void moneyDisplay()
        {
            cout<<"\nBalance is : "<<accBal;
        }
        void moneyWithdraw()
        {
            cout<<"\nBalance is : "<<accBal;
            int withDraw;
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
        
/*void Account::makeAccount()
{
    Account a;
    ofstream o;
    o.open("account.txt", ios::in|ios::app);
    getDetails();
    o.write(reinterpret_cast<char *> (&a), sizeof(Account));
    o.close();
}*/
class Login : public Savings
{
    protected:
        string username;
        int password;
    public:
        Login(){}
      Login(string u, int p){
             username =u;
             password = p;
      }
        
    void loginDetails()
        {
            getDetails();
            cout<<"enter your username :";
            cin>>username;
            cout<<"enter your password : ";
            cin>>password;
            
            
        }
};


int main()
{
    Login l;
    Account a;
    Savings s;
    cout<<"Welcome to Axis Bank"<<endl;
    cout<<"Enter sign-up details"<<endl;
    l.loginDetails();
    l.displayDetails();
    

    ofstream o;
    o.open("account.txt", ios::in|ios::app);
    l.displayDetails();
    cout<<"data pushed to account.txt"<<endl;
    o.write(reinterpret_cast<char *> (&a), sizeof(Account));
    o.close();
    
    int choice;
     do
    {
        cout<<"****************************"<<endl;
        cout<<"Enter your choice : "<<endl;
      //  cout<<"for login ............... type 1:"<<endl;
        //cout<<"For Account creation..... type 1"<<endl;
        cout<<"For Money Deposit........ type 1 "<<endl;
        cout<<"For Money Withdraw....... type 2 "<<endl;
        cout<<"For Display your Bal....  type 3"<<endl;
        cout<<"For Display full details. type 4"<<endl;
        cout<<"To EXIT type 5"<<endl;
        cin>>choice;
        switch(choice)
        {
            //case 1:
                   // l.loginDisplay();
           // case 1:
                  //  a.createAcc();
                  //  break;
            case 1: 
                    l.moneyDeposite();
                    break;
            case 2:
                    l.moneyWithdraw();
                    break;
            case 3:
                    l.moneyDisplay();
                    break;
            case 4:
                    l.displayDetails();
                    l.moneyDisplay();
                    break;
            case 5:
                    cout<<"Thanks for visiting Axis Bank"<<endl;
                    break;
            default:
                    cout<<"\n The choice is invalid "<<endl;
                    cout<<"\a";
        }
    }
        while(choice!=4);
        return 0;
}
    
    
  
#include <iostream> 
#include <string>
 class BankAccount {
    private:
    double balance; std::string AccHolder;
     
       public:
    BankAccount(std::string name, double ibalance) //ibalance is initial balance 
    {
        AccHolder = name;
        if (ibalance>=0){
            balance=ibalance;} else
             {balance = 0;}
        }
    
    void Deposit(double amount){
        if(amount>=0){
            balance += amount;
        std::cout<<"Amount Deposited Successfully!\nyour Balnce is: "<<balance<<"\n\n";
         }else{std::cout<<"invalid Depositable Amount!";}
        }
    void Withdraw(double amount){
        if (amount<0){
            std::cout<<"Invalid withdrawal amount \n\n";
        } else if (amount <= balance){
            balance-=amount;
            std::cout<<"Transaction was Succesful\nYour Balance is: "<<balance<<"\n\n";
        } else {
            std::cout<<"Insufficient Funds For Withdrawal\n\n";
        }
    }
    void SeeBalance(){
        std::cout<<"Your Balance is: "<<balance<<"\n\n";
    }             

    
            };

int  main(){
int num;
double deposit, withdraw, BALANCE;
std::string name;



std::cout <<" \n \nWelcome to ABC BANK \n \n"<<
            "To Get Started Please Enter Your Name\n";
std::cin>>name;
std::cout<<"\nNow Kindly Enter Your Initial Balance\n";
std::cin>>BALANCE;
BankAccount MyAccount(name, BALANCE);            

            do {

    std::cout<< "\n\n\nEnter a number for Action \n 1. Create an Account \n 2. Deposit Money \n 3. Withdraw Money \n 4. View Balance \n 5. Exit \n\n\n\n";
   std::cin >> num;
   std::cout<<"\n\n";

 switch (num)
 {
    
    case 1:
    std::cout<<"\nYour Account has been already created\n";
    break;
   
    case 2 :
   std::cout<< "Deposit Selected\n"<<"Enter amount to be deposited\n\n";
   std::cin>>deposit;
   MyAccount.Deposit(deposit);
   break;
  
   case 3: 
  std::cout<<"Withdraw Selected\n"<<"Please Enter Money to be Withdrawn\n";
  std::cin>>withdraw;
   MyAccount.Withdraw(withdraw);
  break;
  
  case 4: 
  MyAccount.SeeBalance();
  break;
  
  case 5:
  std::cout << "Thanks for Interacting with ABC BANK"<<std::endl;
  break;  

  default:
  std::cout<<"ENTER A VALID NUMBER FOR ACTION!\n\n";
    break;
 }   
} while (num != 5);

return 0;
}
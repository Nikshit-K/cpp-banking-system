#include <iostream> 
#include <string>
#include <fstream>

 class BankAccount {
    private:
    double balance; std::string AccHolder;
     
       public:
       BankAccount() : AccHolder("Unknown"), balance(0.0) {}
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
        SaveToFile();
         }else{std::cout<<"invalid Depositable Amount!";}
        }
    void Withdraw(double amount){
        if (amount<0){
            std::cout<<"Invalid withdrawal amount \n\n";
        } else if (amount <= balance){
            balance-=amount;
            std::cout<<"Transaction was Succesful\nYour Balance is: "<<balance<<"\n\n";
            SaveToFile();
        } else {
            std::cout<<"Insufficient Funds For Withdrawal\n\n";
        }
    }
    void SeeBalance() const {
        std::cout<<"Your Balance is: "<<balance<<"\n\n";
    }  
    
    void SaveToFile() {
        std::ofstream outFile("account.txt");
        if (outFile.is_open())
        {
            outFile << AccHolder << std::endl;
            outFile << balance << std::endl;
            outFile.close();
         }
        }
       
    bool ReadFromFile() {
        std::ifstream inFile("account.txt");

        if(inFile.is_open()){
            std::getline(inFile, AccHolder);
            inFile >> balance;
            inFile.close();
            return true;          
           } else {return false;}
          } 
};

int  main(){
int num;
double deposit, withdraw, BALANCE;
std::string name;
BankAccount MyAccount;



std::cout <<" \n===================";
std::cout << "\nWelcome to ABC BANK \n";
std::cout <<  "===================\n";

if(MyAccount.ReadFromFile()){
    std::cout << "Existing Account Found! Loaded Your details Sccessfully.\n\n";
    MyAccount.SeeBalance();
} else {
  
    std::cout<<"To Get Started Please Enter Your Name\n";
std::cin>>std::ws;
std::getline(std::cin, name);
std::cout<<"\nNow Kindly Enter Your Initial Balance\n";
std::cin>>BALANCE;

MyAccount = BankAccount(name, BALANCE);
MyAccount.SaveToFile();
std::cout << "Account created Succesfully and saved to disk!\n\n";
 }           

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

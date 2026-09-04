#include <iostream> 
#include <string>
#include <fstream>
#include <vector>

 class BankAccount {
    private:
    int accountNum; std::string AccHolder; double balance;
     
       public:
       BankAccount() : accountNum(0), AccHolder("Unknown"), balance(0.0) {}
    BankAccount(int AccNo, std::string name, double ibalance) //ibalance is initial balance 
    {
        accountNum = AccNo;
        AccHolder = name;
        if (ibalance>=0){
            balance=ibalance;} else
             {balance = 0;}
        }

    int getaccnum() const {return accountNum;}
    std::string getHoldername() const {return AccHolder;}
    double getBalance() {return balance;}

    void Deposit(double amount){
        if(amount>0){
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
    void SeeBalance() const {
        std::cout << "\n----------------------------\n";
        std::cout << "Account Number: " << accountNum << "\n";
        std::cout << "Account Holder: " << AccHolder << "\n";
        std::cout << "Current Balance: " << balance << "\n";
        std::cout << "----------------------------\n\n";
    }
    
   
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

int  main(){
std::vector <BankAccount> UserAccount;    
int num, accno;
double deposit, withdraw, BALANCE;
std::string name;

std::ifstream inFile("accounts.txt");
if (inFile.is_open()) {
    while(inFile >> accno){
        inFile >> std::ws;
        std::getline(inFile, name);
        inFile >> BALANCE;

        UserAccount.push_back(BankAccount(accno, name, BALANCE));

    }inFile.close();
    std::cout << "Data Loaded\n Total Accounts Found :" << UserAccount.size() << "\n\n";
}


std::cout <<" \n===================";
std::cout << "\nWelcome to ABC BANK \n"; 
std::cout <<  "===================\n";



            do {

    std::cout<< "\n\n\nEnter a number for Action \n 1. Create New Account \n 2. Deposit Money \n 3. Withdraw Money \n 4. View Balance \n 5. Exit \n\n\n\n";
   if (!(std::cin >> num)) {
            clearInputBuffer();
            std::cout << "ENTER A VALID NUMBER FOR ACTION!\n\n";
            continue;
        }
   
   switch (num)
 {
    
    case 1:
    {std::cout << "\nEnter New Account Number:    ";
    if (!(std::cin>>accno)){
        clearInputBuffer();
        std::cout << "Invalid Input! Acoount Number Must Be Numeric \n\n";
        break;
    }
    bool exists = false;
    for (size_t i = 0; i < UserAccount.size(); i++){
        if (UserAccount[i].getaccnum() == accno){
            exists = true;
            break;
        }
    }
    if (exists) {
        std::cout << "Error: Account Number Already Exists \n\n";
    } else {
        std::cout << "Enter Name of Account Holder:  ";
        std::cin>>std::ws;
        std::getline(std::cin, name);
        std::cout<<"Enter Initial Balance:  ";
        if (!(std::cin >> BALANCE)) {
                            clearInputBuffer();
                            std::cout << "Invalid Balance!.. Creation Cancelled.\n\n";
                            break;
                        };
        UserAccount.push_back(BankAccount(accno, name, BALANCE));
        std::cout << "Account Successfully Created! \n\n";
    }
    break;}
   
    case 2 :  {
   std::cout<< "Deposit Selected\n"<<"Enter Your Account Number\n\n";
   if (!(std::cin >> accno)) {
                    clearInputBuffer();
                    std::cout << "Invalid input! Account Number must be numeric.\n\n";
                    break;
                }
   bool found = false;
   for (size_t i = 0; i < UserAccount.size(); i++){
    if (UserAccount[i].getaccnum() == accno){
        std::cout << "Enter Amount:   ";
       if (!(std::cin >> deposit)) {
                            clearInputBuffer();
                            std::cout << "Invalid Amount!\n\n";
                            break;
                        }
        UserAccount[i].Deposit(deposit);
        found=true;
        break;

    } }
    if (!found){
        std::cout<<"Account Not Found!\n\n";
        break;
    }
   
   
   break;}
  
   case 3: { 
  std::cout<<"Withdraw Selected\n"<<"Please Enter Account Number:  \n";
 if (!(std::cin >> accno)) {
                    clearInputBuffer();
                    std::cout << "Invalid input! Account Number must be numeric.\n\n";
                    break;
                }
  bool found = false;
   for (size_t i = 0; i < UserAccount.size(); i++){
    if (UserAccount[i].getaccnum() == accno){
        std::cout << "Enter Amount:   ";
       if (!(std::cin >> withdraw)) {
                            clearInputBuffer();
                            std::cout << "Invalid Amount!\n\n";
                            break;
                        };
        UserAccount[i].Withdraw(withdraw);
        found=true;
        break;

    } }
    if (!found){
        std::cout<<"Account Not Found!\n\n";
        break;
    } break; }
  
  case 4: { 
  std::cout<<"Please Enter Account Number To See Balance:  \n";
  if (!(std::cin >> accno)) {
                    clearInputBuffer();
                    std::cout << "Invalid input! Account Number must be numeric.\n\n";
                    break;
                }
  bool found = false;
   for (size_t i = 0; i < UserAccount.size(); i++){
    if (UserAccount[i].getaccnum() == accno){
        
        UserAccount[i].SeeBalance();
        found=true;
        break;

    } }
    if (!found){
        std::cout<<"Account Not Found!\n\n";
        break;
    } break;
            }
   
  
  case 5: {
  std::ofstream outFile("accounts.txt");
  if (outFile.is_open()){
    for (size_t i = 0; i < UserAccount.size(); i++){
        outFile << UserAccount[i].getaccnum() << "\n";
        outFile << UserAccount[i].getHoldername() << "\n";
        outFile << UserAccount[i].getBalance() << "\n";
    }
    outFile.close();
    std::cout<< "All Data Saved Successfully to Accounts.txt.\n\n";
  }
  std::cout << "Thanks for Interacting with ABC BANK"<<std::endl;
  break; } 

  default:
  std::cout<<"ENTER A VALID NUMBER FOR ACTION!\n\n";
    break;}
  }   while (num != 5);

 return 0;
  }

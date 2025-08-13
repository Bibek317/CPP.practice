/*
 * Project     : [Your Project Name Here]
 * Filename    : [e.g., main.cpp]
 * Author      : Bibek Kushwaha
 * GitHub      : https://github.com/Bibek317
 * Created On  : [2025-08-03 or your date]
 * Last Update : [Optional – update when needed]
 * Description : [Created simple banking program using Cpp or OOP 😁]

 *
 * © 2025 Bibek Kushwaha. All rights reserved.

 * Usage       : You are free to use, modify, and distribute this code 
 *               for educational or personal projects with proper credit.
 */
//Creating Bank Account functionality
#include <iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include<string>
#include<cstdlib>


// creating a function for user accountnumber where I will give random accountnumber 
std::string generateAccountNumber(){
    std::string AccNum ="";
    for(int i =0;i<16;++i){
        AccNum += '0'+ (rand()%10);
    }
    return AccNum;
};
//declaring class where I will create function or class
class BankAccount{
    private:
    	std::string name;
        std::string accountnumber;
        double balance;
        int pin;
    public:
    	BankAccount(std::string name,int pin){
            this->name = name;
            this->accountnumber = generateAccountNumber();
            this->balance = 1000;
            this->pin = pin;
            std::cout<<"Account is created for "<<name<<" With accountnumber "<<accountnumber<<" Of Opening balance is Rs."<<balance<<std::endl;
            
        }
        //Now method declaration or etc feature 
        void deposit(int ammount){
            if (ammount >0){
                balance += ammount;
                std::cout<<"Ammount into Your BankAccount . Your new balance is Rs."<<balance<<std::endl; 
            }
        };
        void withdraw(double ammount,int inputPin){
            if (ammount <= balance && inputPin == pin){
                balance -= ammount;
                std::cout<<"Rs."<<ammount<<"Withdrawed successfully now your current balance is Rs."<<balance<<std::endl;
            }else if(ammount > balance && inputPin == pin){
                std::cout<<"Insufficient balance.plz go to your nearest bank or deposit money in that or say someone to send money in your account then you give him cash"<<std::endl;
            }else{
                std::cout<<"Something went wrong or wrong pin "<<std::endl;
            }
        };
        void showbalance(int inputPin){
            if(inputPin == pin){
                std::cout<<"Sir your current balance is Rs."<<balance<<std::endl;
            }
        };
        void changepin(int Oldpin, int newPin){
            if(Oldpin == pin){
                pin = newPin;
                std::cout<<"☑️your newPin is updated successful"<<std::endl;
            }else{
                std::cout<<"❌ Wrong old pin try again"<<std::endl;
            }
        };
        std::string getAccountNumber(){
            return accountnumber;
        };
        std::string getname(){
            return name;
        }
};


int main(){
    std::cout << "Namaste sir 🙏. Welcome to our bank 🏦 🙏"<< std::endl;
    
    int num;
    std::cout<<"How many user you want ? =>"<<std::endl;
    std::cin>>num;
    std::vector<BankAccount> users;
    std::cin.ignore();
    for(int i =0;i<num;++i){
        std::string name;
        int Pin;
        std::cout<<"\n👨User"<<(i+1)<<" Name => "<<std::endl;
        //std::cin.ignore(); // Clear the input buffer
		std::getline(std::cin, name); // Read full name including spaces if any

		std::cout <<"🔒User" << (i+1) << " Pin is => " << std::endl;
		while (!(std::cin >> Pin)) {
    		std::cout << "Please enter a valid PIN (number): ";
    		std::cin.clear();            
    		std::cin.ignore(10000, '\n'); 
        }
        std::cin.ignore();

        //Creating a new bank account object
        BankAccount newuser(name,Pin);
        users.push_back(newuser);
        //Now going to store the detail of user in file 🗃️ 
        std::ofstream Myfile("Bank_user_detail.txt",std::ios::app);//opening the file in appending mode 
        Myfile<<"Name => "<<name<<"\nAccountNumber => "<<newuser.getAccountNumber()<<"\nPin is "<<Pin<<"\nWith initial balance of Rs."<<1000<<std::endl;
        Myfile.close();
    }    
    char choice ='y';
    while (choice =='y' || choice == 'Y'){
        std::string accnumber;
        int pin;
        std::cout<<"Enter your account number"<<std::endl;
        std::cin>>accnumber;
        std::cout<<"Enter your account pin number"<<std::endl;
        std::cin>>pin;
        BankAccount* user = nullptr;
        for(auto &u :users){
            if(u.getAccountNumber() == accnumber){
                user = &u;
                break;
            }
        }
        if(user == nullptr){
            std::cout<<"👨User account not found"<<std::endl;
        }else{
            int option;
            std::cout<<"1.Deposit \n2.Withdraw \n3.Showbalance \n4.ChangePin \n5. Exit"<<std::endl;
            std::cin>>option;
            //Now applying switch statement to add other functionality 
            switch(option){
                case 1:{
                    int Ammount;
                    std::cout<<"💵🪙Enter ammount you want to deposit => "<<std::endl;
                    std::cin>>Ammount;
                    user->deposit(Ammount);
                    break;
                }
                case 2:{
                    double Withdrawal_ammount;
                    std::cout<<"💸💷Enter the you want to withdraw => "<<std::endl; 
                    std::cin>>Withdrawal_ammount;
                    user->withdraw(Withdrawal_ammount,pin);
                    break;
                }
                case 3:{
                    user->showbalance(pin);
                    break;
                }
                case 4:{
                    int NewPin;
                    std::cout<<"Enter your new pin of your account"<<std::endl;
                    std::cin>>NewPin;
                    user->changepin(pin,NewPin);
                    break;
                }
                case 5:{
                    std::cout<<"Exiting BankAccount menu😊 "<<std::endl;
                    break;
                }
                default:{
                    std::cout<<"❌ Invalid option. plz select from valid option 🙏 thank you"<<std::endl;
                }
            }
        }
        std::cout<<"Do you want to continue (y/n)=> "<<std::endl;
        std::cin>>choice;
    }
    // Thanks for using message 
    std::cout<<"🥰 Thanks for using my Banking program 🥰.See 🙈 you again"<<std::endl;
    return 0;
};
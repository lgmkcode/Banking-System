#include <iostream>
#include <string>
#include "bank.h"
#include <fstream>

account::account(){ //constructor
    balance = 0;
}

void account::open_acc(){
    cout << "enter your name: ";
    cin >> name;
    cout << "enter your surename: ";
    cin >> surname;
    cout << "enter your id number: ";
    cin >> id;
    cout << "enter your date of birth(DD/MM/YYYY): ";
    cin >> date;
}

void account::scan_acc(){
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Id number: " << id << endl;
    cout << "Date of birth: " << date << endl;
}

void account::get_balance(){
    cout << "Your balance: " << balance << endl;
}

void account::get_deposit(){
    int tmp;
    cout << "Enter the amount you want to deposit: ";
    cin >> tmp;
    if(tmp<0){
        cout << "incorrect entry!" << endl;
    }
    else{
        balance += tmp;
    }
}

void account::get_withdraw(){
    int tmp;
    cout << "Enter the amount you want to withdraw: ";
    cin >> tmp;
    if((balance - tmp) <0){
        cout << "insufficient balance!" << endl;
    }
    else{
        balance -= tmp;
    }
}

void account::write_data(){
    ofstream file;
    file.open("data/account-data.txt",ios::app);
    if(file.is_open()){
        file << id << " " << name << " " << surname << " " << date << " " << balance << password <<"\n";
        file.close();
    }
    else{
        cout << "file could not be opened!" << endl;
    }
}
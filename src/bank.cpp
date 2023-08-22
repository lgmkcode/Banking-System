#include <iostream>
#include <string>
#include "bank.h"
#include <fstream>
#include <sstream>
#include <vector>

account::account(){ //constructor
    balance = 0;
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

void account::signup(account* acc){
    cout << "enter your name: ";
    cin >> name;
    cout << "enter your surename: ";
    cin >> surname;
    cout << "enter your id number: ";
    cin >> id;
    cout << "enter your date of birth(DD/MM/YYYY): ";
    cin >> date;
    cout << "enter your password :";
    cin >> password;

    acc->write_data();
    cout << "you are registered" << endl;
}

void account::write_data(){
    ofstream file;
    file.open("data/account-data.txt",ios::app);
    if(file.is_open()){
        file << id << " " << name << " " << surname << " " << date << " " << balance << " " << password <<"\n";
        file.close();
    }
    else{
        cout << "file could not be opened!" << endl;
    }
}

void account::acc_query(account* acc){
    int aim;
    bool a = true;
    
    while(a){
        cout << "==============\n" << "1.sign up\n" << "2.log in\n" << "==============" << endl;
        cin >> aim;

        switch(aim){
            case 1: acc->signup(acc);// sign up method
                a = true;
                break;
            case 2: acc->login(acc);// log in method
                a = false;
                break;
            default: cout << "incorrect entry!" << endl;
                a = true;
                break;
        }
    }    
}

void account::login_acc(account* acc){
    int aim = 0;
    while(aim != 5){

        cout << "=====================================" << endl;
        cout << "1.scan account" << endl;
        cout << "2.deposit" << endl << "3.withdraw" << endl;
        cout << "4.balance" << endl << "5.exit" << endl;
        cout << "=====================================" << endl;

        cin >> aim;
    
        switch(aim){
            case 1: acc->scan_acc();
                break;
            case 2: acc->get_deposit();
                break;
            case 3: acc->get_withdraw();
                break;
            case 4: acc->get_balance();
                break;
            case 5: // exit
                break;
            default: cout << "incorrect entry!" << endl;
                break;

        }
    }
    acc->syc_data();
}

void account::login(account* acc){
    int tmpid;
    string tmppassword;
    bool stop = false;
    int lineId;
    int lineBalance;
    string linePassword; 
    string lineName; 
    string lineSurname; 
    string lineDate;
    
    cout << "enter your id: ";
    cin >> tmpid;
    cout << "enter your password: ";
    cin >> tmppassword;

    string line; 
    ifstream file2("data/account-data.txt"); 

    if (file2.is_open()){
        while(getline(file2, line)){
            istringstream iss(line); 
            iss >> lineId >> lineName >> lineSurname >> lineDate >> lineBalance >> linePassword; // Satır ayrıştı
            
            if (lineId == tmpid && linePassword == tmppassword){ 
                stop = true;
                break;
            }
        }

        if(stop){
            cout << "logging in" << endl;
            
            name = lineName;
            surname = lineSurname;
            date = lineDate;
            id = lineId;
            balance = lineBalance;
            password = linePassword;
            acc->login_acc(acc);
        }
        else{
            cout << "incorrect id or password" << endl;
        }

        file2.close();
    }
}

void account::syc_data(){
    vector<string> lines; // A vector to store the lines of the file
    string line;

    ifstream filein("data/account-data.txt");
    while (getline(filein, line)) {
        lines.push_back(line); // Insert the lines of the file at the end of the vector.
    }
    filein.close();

    for(string& currentLine : lines){ //range-based for loop" structure to traverse the elements of a vector.
        istringstream iss(currentLine);
        int id, balance;
        string name, surname, date, password;

        iss >> id >> name >> surname >> date >> balance >> password;// with the spaces on the line, we separate the data one by one and place them in the variables.
        if (id == this->id && password == this->password) {
                balance = this->balance; 
                currentLine = to_string(id) + " " + name + " " + surname + " " + date + " " + to_string(balance) + " " + password;
            }
        }
        

    // güncel datanın saklanması
    ofstream fileout("data/account-data.txt");
    for (const string& updatedLine : lines) { //moves through the vector element by element with updatedline
        fileout << updatedLine << "\n"; //Write updated lines to file
    }
    fileout.close();

}


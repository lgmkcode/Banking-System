#include <iostream>
#include <string>
#include "bank.h"
using namespace std;

int main(){

account account1;
account1.open_acc();
int a = 0;

while(a != 5){

    cout << "=====================================" << endl;
    cout << "1.scan account" << endl;
    cout << "2.deposit" << endl << "3.withdraw" << endl;
    cout << "4.balance" << endl << "5.exit" << endl;
    cout << "=====================================" << endl;

    cin >> a;
/*
    if(a == 1){
        deneme1.open_acc();
    }
*/
    if(a == 1){
        account1.scan_acc();
    }
    else if(a == 2){
        account1.get_deposit();
    }
    else if(a == 3){
        account1.get_withdraw();
    }
    else if(a == 4){
        account1.get_balance();
    }
    else if(a == 5){
         break;
    }
    else{
         cout << "incorrect entry!" << endl;
    }
}


return 0;
}

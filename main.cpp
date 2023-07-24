#include <iostream>
#include <string>
#include "bank.h"
using namespace std;

int main(){

account account1;
account1.open_acc();
int aim = 0;

while(aim != 5){

    cout << "=====================================" << endl;
    cout << "1.scan account" << endl;
    cout << "2.deposit" << endl << "3.withdraw" << endl;
    cout << "4.balance" << endl << "5.exit" << endl;
    cout << "=====================================" << endl;

    cin >> aim;
/*
    if(a == 1){
        deneme1.open_acc();
    }
*/
    if(aim == 1){
        account1.scan_acc();
    }
    else if(aim == 2){
        account1.get_deposit();
    }
    else if(aim == 3){
        account1.get_withdraw();
    }
    else if(aim == 4){
        account1.get_balance();
    }
    else if(aim == 5){
         break;
    }
    else{
         cout << "incorrect entry!" << endl;
    }
}

return 0;
}

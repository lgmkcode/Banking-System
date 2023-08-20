#include <iostream>
#include <string>
#include "bank.h"
#include <fstream>
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
        case 1: deneme1.open_acc();
            break
    }
*/
    switch(aim){
        case 1: account1.scan_acc();
            break;
        case 2: account1.get_deposit();
            break;
        case 3: account1.get_withdraw();
            break;
        case 4: account1.get_balance();
            break;
        case 5: // exit
            break;
        default: cout << "incorrect entry!" << endl;
            break;

    }
}
account1.write_data();
return 0;
}

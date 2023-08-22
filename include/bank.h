#include <iostream>
using namespace std;

class account{
    private:
        string name;
        string surname;
        string date;
        int id;
        int balance;
        string password;

    public:
        account(); //constructor
        void signup(account* acc);
        void scan_acc();
        void get_balance();
        void get_deposit();
        void get_withdraw();
        void write_data();
        void acc_query(account* acc);
        void login_acc(account* acc);
        void login(account* acc);
        void syc_data();
};

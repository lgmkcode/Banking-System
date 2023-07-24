#include <iostream>
using namespace std;


class account{
    private:
        string name;
        string surname;
        string date;
        int id;
        int balance;

    public:
        account(); //constuructor
        void open_acc();
        void scan_acc();
        void get_balance();
        void get_deposit();
        void get_withdraw();
};

#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
class view
{
    public:
        //view();
        //virtual ~view();
        friend class controller;
        void menu1();
        void menu2();
        void nhaplai();
        void dangki();
        void dangnhap();
        void addFriend();
        void listFriend();
        void block();
        void sendMess();
        void sentMess();
        void inbox();

    protected:

    private:
        char *username;
        char *password;
        char *city;
        char *mess;
};

#include<iostream>
#include "view.h"
#include "model.h"
#include<string>
#include<string.h>
#include<stdio.h>
#include<ncurses.h>
#include<list>
#include<vector>

using namespace std;
class controller
{
    public:
        int id1 ;
        int id2;
        view v;
        model m;
        void controle();
        int login();
        void signUp();
        void addFriend();
        void loginThanhCong();
        void showFriend();
        void showFriendOrderByCity();
        void block();
        void sendMess();
        void sentMess();
        void inbox();  //virtual ~controller();
        void sendMessId(string s[],int index);
        void showFriendToSendMess();
        void sendMessNew();
        void showFriendNew();
        void repInbox();

    protected:

    private:
};

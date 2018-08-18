#include<iostream>
#include<sqlite3.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<list>
#include<vector>
using namespace std;
class model
{
    public:

        friend class controller;
        void open();
        int checkUser(char *user);
        int insertData(char *user, char *pass, int idCity);
        void insertCity(char *city);
        int checkCity(char *city);
        int checkLogin(char *user, char *pass);
        int checkFriend(int id1,int id2);
        int checkBlock(int id1, int id2);
        void addFriend(int id1,int id2);
        int showFriend(int id1);
        void showFriendByCity(int id1,string city);
        void block(int id1,int id2);
        void sendMess(int id1,int id2,char *mess);
        void showMessSent(int id1,int id2);
        void inbox(int id1,int id2);
        void showNguoiNhan(int id1);
        void showNguoiGui(int id1);
        void showMessInbox(int id1,int id2);
        int showCityFriend(int id1);
        void updateSeen(int id1, int id2);
        void timeMessFriend(int id1,int id2,char *t);
    protected:

    private:
        sqlite3 *db;
        char *zErrMsg = 0;
        int rc;
        const char *sql;
        const char *tailSql;
        sqlite3_stmt *stmt;
        list<string> myCity;
        vector<string> nguoiNhan;
        vector<string> nguoiGui;
        vector<string> fr;
};

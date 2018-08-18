#include "view.h"
#include<iostream>

using namespace std;
void view::menu1()
{
        cout<<"======MENU======"<<endl;
        cout<<"1. dang ki"<<endl;
        cout<<"2. dang nhap"<<endl;
        cout<<"3. thoat"<<endl;
        cout<<"======nhap lua chon======"<<endl;
}
void view::menu2(){
        cout<<"============"<<endl;
        cout<<"1. add friend"<<endl;
        cout<<"2. List friend"<<endl;
        cout<<"3. block"<<endl;
        cout<<"4. send messenger"<<endl;
        cout<<"5. sent"<<endl;
        cout<<"6. inbox"<<endl;
        cout<<"7. show friend by city"<<endl;
        cout<<"8. show friend to send messenger"<<endl;
        cout<<"9. dang xuat"<<endl;

}
void view::nhaplai(){
    cout<<"======vui long nhap lai======"<<endl;
}
void view::dangki(){
    username = new (char);
    password = new (char);
    string c;
    city = new (char);
    cout<<"======dang ki======"<<endl;
    cout<<"nhap username: ";
    cin>>username;
    cout<<"nhap password: ";
    cin>>password;
    cout<<"nhap city: ";
    getline(cin,c);
    getline(cin,c);
    city = new char[c.length() + 1];
    strcpy(city, c.c_str());


}
void view::dangnhap(){
    cout<<"======dang nhap======"<<endl;
    username = new (char);
    password = new (char);
    cout<<"username: ";
    cin>>username;
    cout<<"password: ";
    cin>>password;
}
void view::addFriend(){
    username= new (char);
    cout<<"====== add friend ======"<<endl;
    cout<<"nhap username: ";
    cin>>username;
}
void view::listFriend(){
    cout<<"====== List Friend ======"<<endl;
}
void view::block(){
    username = new (char);
    cout<<"nhap username can block"<<endl;
    cin>>username;
}
void view::sendMess(){
    username = new (char);
    cout<<"nguoi nhan: ";
    cin>>username;

}
void view::sentMess(){
    username = new (char);
    cout<<"====== hop thu di ======"<<endl;
    cout<<"nhap username: ";
    cin>>username;

}
void view::inbox(){
    username = new (char);
    cout<<"====== hop thu den ======"<<endl;
    cout<<"nhap username: ";
    cin>>username;
}

//view::~view()
//{
    //dtor
//}

#include "controller.h"


//#include "view.h"
//#include "model.h"
using namespace std;
void controller::signUp(){
            v.dangki();
            m.open();
            if(m.checkUser(v.username)>0){
                cout<<"username da co trong he thong, dang ki that bai"<<endl;
            }
            else {
                 int idCity;
                if(m.checkCity(v.city)<1){
                m.insertCity(v.city);
                idCity = m.checkCity(v.city);
                }
                else{
                    idCity = m.checkCity(v.city);
                    }
                m.insertData(v.username,v.password,idCity);
            }
}
void controller::addFriend(){
    v.addFriend();
    m.open();
    int id = m.checkUser(v.username);
    if(id>=1){
        int id3= m.checkFriend(id1,id);
        if(id3 == 0){
            cout<<"khong the them username nay vao list friend"<<endl;
        }
        else if(id3 == 1){
            cout<<"username da co trong list friend"<<endl;
        }
        else if(id3 = -1){

            m.addFriend(id1,id);
        }

    }
    else {
        cout<<"username khong ton tai trong he thong"<<endl;

    }

}
void controller::sendMessId(string s[],int index){
        nhaplai:cout<<"nhap id: "<<endl;
        int id;
        cin>>id;
        if(id<0 || id > index){
        cout<<"lua chon khong hop le, vui long nhap lai"<<endl;
        goto nhaplai;
        }
        else{

            cout<<"To: "<<s[id-1]<<endl;
            v.username = new char[s[id-1].length() +1];
            strcpy(v.username, s[id-1].c_str());
        //v.username = s[id-1].c_str();
            id2 = m.checkUser(v.username);
            cout<<"soan tin: "<<endl;
            string a;
            getline(cin,a);
            getline(cin,a);
            char *me;
            me = new char[a.length() + 1];
            strcpy(me, a.c_str());
            m.sendMess(id1,id2,me);
        }


}
void controller::showFriend(){

   // v.listFriend();
    m.open();
    m.showFriend(id1);
    vector<string> vt;
    vt = m.fr;
    for(int j=0;j<vt.size();j++){
        cout<<j+1<<"\t"<<vt[j]<<endl;
    }

   // sendMessId(s,index);


}
void controller::showFriendToSendMess(){
    m.open();
    m.showFriend(id1);
    vector<string> vt;
    vt = m.fr;
    for(int j=0;j<vt.size();j++){
        cout<<j+1<<"\t"<<vt[j]<<endl;
    }

    nhaplai: cout<<"nhap id: ";
   int id;
   cin>>id;

   if(id<0 || id>vt.size()){
        cout<<"lua chon khong hop le, vui long chon lai"<<endl;
        goto nhaplai;
   }
   else{
            cout<<"To: "<<vt[id-1]<<endl;
            v.username = new char[vt[id-1].length() +1];
            strcpy(v.username, vt[id-1].c_str());
        //v.username = s[id-1].c_str();
            id2 = m.checkUser(v.username);

            cout<<"soan tin: "<<endl;
            string a;
            getline(cin,a);
            getline(cin,a);
            char *me;
            me = new char[a.length() + 1];
            strcpy(me, a.c_str());
            m.sendMess(id1,id2,me);

   }
}
void controller::showFriendNew(){
                        cout<<"press ctrl + A to show friend order by city"<<endl;
                        cout<<"press ctrl + B to back"<<endl;
                        nhaplai: cbreak();
                                WINDOW *w;
                                char c;

                                w = initscr();
    //keypad(w, TRUE);
   // timeout(3000);
                                c = getch();
                                int key = c;
                                endwin();
                                if(key == 1){
                                    showFriendOrderByCity();
                                }
                                else if(key == 2){
                                    v.menu2();
                                }
                                else{
                                    showFriend();
                                    goto nhaplai;
                                }
}
void controller::showFriendOrderByCity(){
    m.open();
    m.showCityFriend(id1);
    list<string>::iterator i;
    for(i = m.myCity.begin(); i!=m.myCity.end();i++){
        cout<<*i<<endl;
        m.showFriendByCity(id1,*i);
    }
}

void controller::block(){
    v.block();
    m.open();
    int id = m.checkUser(v.username);
    if(id>0){
        id2 = id;
        m.block(id1,id2);
    }
    else{
        cout<<"username khong ton tai"<<endl;
    }


}
void controller::sendMessNew(){

    cout<<"press ctrl + L to show list friend"<<endl;
    cout<<"press ctrl + D to type username"<<endl;
   nhaplai: cbreak();
    WINDOW *w;
    char c;

    w = initscr();
    //keypad(w, TRUE);
   // timeout(3000);
    c = getch();
    int key = c;
    endwin();
    if(key == 12){
        showFriendToSendMess();
    }
    else if(key== 4){
        sendMess();
    }
    else{
        goto nhaplai;
    }
    //refresh();

}
void controller::sendMess(){
    string s;
    v.sendMess();
    m.open();
    int id = m.checkUser(v.username);
    if(id>0){
        if(m.checkFriend(id1,id)==0){
            cout<<"khong the nhan tin cho username nay"<<endl;

        }
        else{
            cout<<"soan tin: ";
            getline(cin,s);
            getline(cin,s);
            v.mess = new char[s.length() + 1];
            strcpy(v.mess, s.c_str());
            m.sendMess(id1,id,v.mess);
        }
    }
    else{
        cout<<"username khong ton tai"<<endl;
    }
}
void controller::sentMess(){
    m.open();
    cout<<"====== gan day ======"<<endl;

    m.showNguoiNhan(id1);
    vector<string> vt = m.nguoiNhan;
    //int index = m.showIndexNguoiNhan(id1);
    for(int i=0;i<vt.size();i++){
        cout<<i+1<<"\t"<<vt[i]<<endl;

    }
    cout<<"======"<<endl;
   // v.sentMess();
  nhaplai: cout<<"nhap id: ";
   int id;
   cin>>id;

   if(id<0 || id>vt.size()){
        cout<<"lua chon khong hop le, vui long chon lai"<<endl;
        goto nhaplai;
   }
   else{
            cout<<"messenger To: "<<vt[id-1]<<endl;
            v.username = new char[vt[id-1].length() +1];
            strcpy(v.username, vt[id-1].c_str());
        //v.username = s[id-1].c_str();
            id2 = m.checkUser(v.username);
            m.showMessSent(id1,id2);
   }

}
void controller::inbox(){
    m.open();
    cout<<"====== gan day ======"<<endl;
    m.showNguoiGui(id1);
    vector<string> vt;
    vt = m.nguoiGui;
    for(int i=0;i<vt.size();i++){
        cout<<i+1<<"\t"<<vt[i]<<endl;
    }
    cout<<"======"<<endl;
    nhaplai: cout<<"nhap id: ";
    int id;
    cin>>id;

    if(id<0 || id>vt.size()){
        cout<<"lua chon khong hop le, vui long chon lai"<<endl;
        goto nhaplai;
   }
   else{
            cout<<"messenger From: "<<vt[id-1]<<endl;
            v.username = new char[vt[id-1].length() +1];
            strcpy(v.username, vt[id-1].c_str());
        //v.username = s[id-1].c_str();
            id2 = m.checkUser(v.username);
            m.showMessInbox(id1,id2);
            m.updateSeen(id2,id1);
   }

}
void controller::repInbox(){
                cout<<"press ctrl + R to rep inbox"<<endl;
                cout<<"press ctrl + B to back"<<endl;
                 nhaplai: cbreak();
                WINDOW *w;
                char c;

                w = initscr();
    //keypad(w, TRUE);
   // timeout(3000);
                c = getch();
                int key = c;
                endwin();
                if(key == 18){
                    cout<<"to: "<<v.username<<endl;
                    cout<<"soan tin: ";
                    string s;
                    getline(cin,s);
                    getline(cin,s);
                    v.mess = new char[s.length() + 1];
                    strcpy(v.mess, s.c_str());
                    m.sendMess(id1,id2,v.mess);

                }
                else if(key == 2){
                    inbox();
                }
                else{
                    goto nhaplai;
                }

}
int controller::login(){
                v.dangnhap();
                m.open();
                int id = m.checkLogin(v.username,v.password);
                if(id>0){
                    cout<<"====== dang nhap thanh cong ======"<<endl;

                    id1 = id;
                    while(1){
                                            v.menu2();
                   cout<<"======"<<endl;
                    nhaplai:cout<<"nhap lua chon: ";
                    int luachon;
                    cin>>luachon;
                    if(luachon<0 || luachon>8){
                        cout<<"lua chon khong hop le, vui long chon lai"<<endl;
                        goto nhaplai;
                    }
                    else{
                        switch(luachon){
                            case 1: addFriend();
                                break;
                            case 2: showFriendNew();

                                break;
                            case 3: block();
                                break;
                            case 4:
                                sendMessNew();
                                break;
                            case 5: sentMess();
                                break;
                            case 6: inbox();
                                    repInbox();
                                break;
                            case 7: showFriendOrderByCity();
                                break;
                            case 8: showFriendToSendMess();
                                break;
                            case 9: cout<<"dang xuat thanh cong"<<endl;
                                cout<<"======"<<endl;
                                controle();
                                break;



        }
    }
                    }

                }
                else{
                    cout<<"====== username hoac password khong dung ======"<<endl;
                }
}
void controller::controle()
{   //controller c;
   while(1){
        v.menu1();
        int luachon;
        nhaplai:cout<<"nhap lua chon: ";
        cin>>luachon;
        if(luachon<0 || luachon>3){
        v.nhaplai();
        goto nhaplai;
        }
        else{
        switch(luachon){
            case 1: signUp();

                break;
            case 2: login();

                break;
           case 3: exit(0);
                break;
        }
    }
    }

}


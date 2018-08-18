#include "model.h"
#include<iostream>
using namespace std;
void model::open()
{
     rc = sqlite3_open("chat.db", &db);
        if( rc ){

          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          exit(0);
    }
}
int model::checkUser(char *user){
     int id=0;
        sql = "Select id from user where username = ?";
        rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
        if(rc == SQLITE_OK){
            sqlite3_bind_text(stmt,1,user,strlen(user),0);
            while(sqlite3_step(stmt)==SQLITE_ROW){
               id= sqlite3_column_int(stmt,0);
            }
        }
        return id;
}
int model::insertData(char *user, char *pass,int idCity){
     sql = "insert into user (username,password,idCity) values (?,?,?)";
        rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, &tailSql);
        if( rc == SQLITE_OK ) {
            sqlite3_bind_text(stmt, 1, user, strlen(user), 0);
            sqlite3_bind_text(stmt, 2, pass, strlen(pass), 0);
            //sqlite3_bind_text(stmt, 3, city, strlen(city), 0);
            sqlite3_bind_int(stmt,3,idCity);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
            cout<<"======dang ki thanh cong======"<<endl;
}
        else{
            cout<<"======dang ki that bai======"<<endl;
        }
}
void model::insertCity(char *city){
    sql = "insert into city (city) values (?)";
    rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
    if(rc ==SQLITE_OK){
        sqlite3_bind_text(stmt,1,city,strlen(city),0);
    }
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}
int model::checkCity(char *city){
    int id = -1;
    sql = "select id from city where city = ?";
    rc = sqlite3_prepare_v2(db,sql,strlen(sql), &stmt, &tailSql);
    if(rc == SQLITE_OK){
        sqlite3_bind_text(stmt,1,city,strlen(city),0);
        while(sqlite3_step(stmt)==SQLITE_ROW){
            id = sqlite3_column_int(stmt,0);
        }
    }
    sqlite3_finalize(stmt);
    return id;
}
int model::checkLogin(char *user, char *pass){
     int id=0;
        sql = "select id from user where username = ? and password = ?";
        rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
        if(rc == SQLITE_OK){
            sqlite3_bind_text(stmt,1,user,strlen(user),0);
            sqlite3_bind_text(stmt,2,pass,strlen(pass),0);
          while(sqlite3_step(stmt) == SQLITE_ROW){
                id = sqlite3_column_int(stmt, 0);
          }
          sqlite3_finalize(stmt);
          return id;

      }else{

          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);

        }
}
int model::checkFriend(int id1,int id2){
    int id=-1;
        sql = "select id from friend where ((id1 = ? and id2 = ?) or (id1 = ? and id2 = ?))";
        rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
        if(rc == SQLITE_OK){
            sqlite3_bind_int(stmt,1,id1);
            sqlite3_bind_int(stmt,2,id2);
            sqlite3_bind_int(stmt,3,id2);
            sqlite3_bind_int(stmt,4,id1);

            while(sqlite3_step(stmt)==SQLITE_ROW){
                id = sqlite3_column_int(stmt,0);
            }
        }
        sqlite3_finalize(stmt);
        return id;
}
int model::checkBlock(int id1, int id2){
        int id;
        sql = "select id from friend where (id1 = ? and id2 = ?) or (id1 = ? and id2 = ?)";
        rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
        if(rc == SQLITE_OK){
            sqlite3_bind_int(stmt,1,id1);
            sqlite3_bind_int(stmt,2,id2);
            sqlite3_bind_int(stmt,3,id2);
            sqlite3_bind_int(stmt,4,id1);

            while(sqlite3_step(stmt)==SQLITE_ROW){
                id = sqlite3_column_int(stmt,0);
            }
        }
        sqlite3_finalize(stmt);
        return id;
}
void model::addFriend(int id1,int id2){
            sql = "insert into friend(id,id1,id2) values(1,?,?)";
            rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
            if(rc==SQLITE_OK){
            sqlite3_bind_int(stmt,1,id1);
            sqlite3_bind_int(stmt,2,id2);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
            cout<<"addfriend sucessfully"<<endl;
            cout<<"=============================="<<endl;

        }
        else{
            cout<<"that bai"<<endl;
        }
}
int model::showFriend(int id1){
    fr.clear();
    sql = "SELECT distinct user.username from user, friend where (friend.id = 1 and ((friend.id1 = ? and friend.id2 = user.id) or (friend.id2 = ? and friend.id1 = user.id))) order by friend.timeMess desc";
    rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, &tailSql);
    if( rc == SQLITE_OK ) {
        sqlite3_bind_int(stmt,1,id1);
        sqlite3_bind_int(stmt,2,id1);
        int i =0;
        while(sqlite3_step(stmt) == SQLITE_ROW) {
           fr.push_back(string((const char *) sqlite3_column_text(stmt, 0)));
        }
        sqlite3_finalize(stmt);


            cout <<"-------------------------------------\n";
    }else{

          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
      }

}
int model::showCityFriend(int id1){
    myCity.clear();
    //int indexCity = showIndexCity();
    sql = "select distinct city.city from city, user, friend where ((friend.id = 1 and friend.id1 = ?) and (friend.id2 = user.id) and (user.idCity = city.id)) or ((friend.id = 1 and friend.id2 = ?) and (friend.id1 = user.id) and (user.idCity = city.id))";
    rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, &tailSql);
    if (rc == SQLITE_OK){
        sqlite3_bind_int(stmt,1,id1);
        sqlite3_bind_int(stmt,2,id1);
         while(sqlite3_step(stmt)== SQLITE_ROW){
            myCity.push_back(string((const char *) sqlite3_column_text(stmt,0)));
         }
    }
}
void model::block(int id1,int id2){
    if(checkFriend(id1,id2)==1){
            sql = "update friend set id = 0 where (id1= ? and id2 = ?) or (id1= ? and id2=?)";
            rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
            if(rc == SQLITE_OK){
                sqlite3_bind_int(stmt,1,id1);
                sqlite3_bind_int(stmt,2,id2);
                sqlite3_bind_int(stmt,3,id2);
                sqlite3_bind_int(stmt,4,id1);
                sqlite3_step(stmt);
                sqlite3_finalize(stmt);
                cout<<"block sucessfully"<<endl;
                cout<<"==========================================="<<endl;
            }
        }
        else{
            sql = "insert into friend (id,id1,id2) values(0,?,?)";
            rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
            if(rc == SQLITE_OK){
            sqlite3_bind_int(stmt,1,id1);
            sqlite3_bind_int(stmt,2,id2);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
            cout<<"block sucessfully"<<endl;
            cout<<"==========================================="<<endl;

        }
        }
}
void model::timeMessFriend(int id1,int id2,char *t){

    sql = "update friend set timeMess = ? where friend.id = 1 and ((friend.id1 = ? and friend.id2 = ?) or (friend.id1 = ? and friend.id2 = ?))";
    rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
    if(rc == SQLITE_OK){
        sqlite3_bind_text(stmt,1,t,strlen(t),0);
        sqlite3_bind_int(stmt,2,id1);
        sqlite3_bind_int(stmt,3,id2);
        sqlite3_bind_int(stmt,4,id2);
        sqlite3_bind_int(stmt,5,id1);
        sqlite3_step(stmt);

    }
    sqlite3_finalize(stmt);
}
void model::sendMess(int id1,int id2,char *mess){
        time_t hientai = time(0);
        char* t = ctime(&hientai);
        sql = "insert into mess(id1,id2,mess,time,seen) values(?,?,?,?,'chua xem')";
        rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
        if(rc == SQLITE_OK){
            sqlite3_bind_int(stmt,1,id1);
            sqlite3_bind_int(stmt,2,id2);
            sqlite3_bind_text(stmt,3,mess,strlen(mess),0);
            sqlite3_bind_text(stmt,4,t,strlen(t),0);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
            cout<<"gui tin nhan thanh cong"<<endl;
            timeMessFriend(id1,id2,t);
            cout<<"================================="<<endl;
        }
}
void model::showFriendByCity(int id1,string city){
    char *c;
    c = new char[city.length()+1];
    strcpy(c,city.c_str());
    sql = "select user.username from city, user,friend where (city.city = ? and city.id = user.idCity) and (((friend.id = 1 and friend.id1 = ?) and (user.id = friend.id2)) or ((friend.id =1 and friend.id2 = ?) and (user.id = friend.id1)))";
    rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
    if(rc == SQLITE_OK){
        sqlite3_bind_text(stmt,1,c,strlen(c),0);
        sqlite3_bind_int(stmt,2,id1);
        sqlite3_bind_int(stmt,3,id1);
        int i = 1;
        while(sqlite3_step(stmt)== SQLITE_ROW){
            cout<<i<<"\t"<<sqlite3_column_text(stmt,0)<<endl;
            i++;
        }
    }
    sqlite3_finalize(stmt);
}
void model::showNguoiNhan(int id1){
    nguoiNhan.clear();
    sql = "select distinct user.username from mess,user where (mess.id1 = ? and mess.id2 = user.id) order by mess.time desc";
    rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
    if(rc == SQLITE_OK){
        sqlite3_bind_int(stmt,1,id1);
        while(sqlite3_step(stmt)==SQLITE_ROW){
            nguoiNhan.push_back(string((const char *) sqlite3_column_text(stmt,0)));
        }
    }
    sqlite3_finalize(stmt);

}
void model::showNguoiGui(int id1){
    nguoiGui.clear();
    sql = "select distinct user.username from mess,user where (mess.id2 = ? and mess.id1 = user.id) order by mess.time desc";
    rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
    if(rc == SQLITE_OK){
        sqlite3_bind_int(stmt,1,id1);
        while(sqlite3_step(stmt)==SQLITE_ROW){
            nguoiGui.push_back(string((const char *) sqlite3_column_text(stmt,0)));
        }
    }
    sqlite3_finalize(stmt);
}
void model::showMessSent(int id1,int id2){
    sql = "select mess,time,seen from mess where id1 = ? and id2 = ?";
        rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
        if(rc == SQLITE_OK){
            sqlite3_bind_int(stmt,1,id1);
            sqlite3_bind_int(stmt,2,id2);
            while(sqlite3_step(stmt)==SQLITE_ROW){
                cout<<sqlite3_column_text(stmt,0)<<"\t"<<sqlite3_column_text(stmt,1)<<"\t"<<sqlite3_column_text(stmt,2)<<endl;
            }
        }
        cout<<"========================================="<<endl;
         sqlite3_finalize(stmt);
}
void model::updateSeen(int id1,int id2){
    sql = "update mess set seen = 'seen' where id1 = ? and id2 = ?";
    rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
    if (rc == SQLITE_OK){
        sqlite3_bind_int(stmt,1,id1);
        sqlite3_bind_int(stmt,2,id2);
        sqlite3_step(stmt);

    }
    sqlite3_finalize(stmt);
}

void model::showMessInbox(int id1,int id2){
    sql = "select mess,time from mess where id1 = ? and id2 = ?";
        rc = sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,&tailSql);
        if(rc == SQLITE_OK){
            sqlite3_bind_int(stmt,1,id2);
            sqlite3_bind_int(stmt,2,id1);
            while(sqlite3_step(stmt)==SQLITE_ROW){
                cout<<sqlite3_column_text(stmt,0)<<"\t"<<sqlite3_column_text(stmt,1)<<endl;
            }
        }
        cout<<"========================================="<<endl;
         sqlite3_finalize(stmt);
}


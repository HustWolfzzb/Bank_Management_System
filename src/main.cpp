#include <iostream>
#include <cstring>
#include <fstream>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#include "CardOperate.h"
#include "LogOperate.h"

#define Length 100·

using namespace std;

void  CreateNewCard();
void Logoperate(int cd);
void MainInterFace();
void  logcard();



int main()
{
    char select;
    int CardID;
    do
    {
        MainInterFace();
        cin>>select;
        switch(select)
        {
            case '1':
            {  CreateNewCard();   };
            case  '2':
            {
                cout<<"\n请输入卡号：";
                cin>>CardID;
                Logoperate(CardID);
            }
            case '0': break;
            default:cout<<"Man? F**k U!\n"<<endl;

        }
    } while(select!='0');

return 0;
}


void  CreateNewCard()
{
    char filename[Length];
    Card t_cd;
    int i_cd;
    char s_name[Length];
    cout<<"\n输入卡号吧：";
    cin>>i_cd;
    cout<<"请输入用户名：";
    cin>>s_name;
    t_cd.Cardno=i_cd;
    strcpy(t_cd.username,s_name);
    t_cd.sum=0;
    itoa(t_cd.Cardno,filename,10);
    fstream writefile(strcat(filename,".txt"),ios::out);
    writefile.write((char *)&t_cd,sizeof(t_cd));
    writefile.close();
}



void Logoperate( int CardID)
{
    char in;
    double money;
    CardOperate cdop(CardID);
    do
    {
        logcard();
        cin>>in;
        switch (in)
        {
            case '1': {
                cout << "请输入存款金额：";
                cin >> money;
                cdop.CardIn(money);
                break;}

            case '2': {
                cout << "请输入取款金额：";
                cin >> money;
                cdop.CardOut(money);
                break;

            }

            case '3':
            {
                cdop.listlog();
                break;

            }
            case '0':
            {
                break;

            }
            default:cout<<"FXXk you Man?\n";
        }
    } while (in!='0');
}




void MainInterFace()
{
    cout<<"*****************************"<<endl;
    cout<<"*       你的银行卡管家      *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*          1.创建新卡       *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*          2.登陆卡号       *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*          0. EXIT          *"<<endl;
    cout<<"*****************************"<<endl;
}




void  logcard()
{
    cout<<"*****************************"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*         1.存款            *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*         2.取款            *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*         3.读取日志        *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*         0.EXIT            *"<<endl;
    cout<<"*                           *"<<endl;
    cout<<"*****************************"<<endl;

}

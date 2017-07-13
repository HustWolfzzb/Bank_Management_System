#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#define CDNO 6
#include "CardOperate.h"
#include "Logoperate.h"

using namespace std;


void CardOperate::CardIn(double m)
{
    t=time(0);
    card.sum+=m;
    lg.Cardno=card.Cardno;
    strftime(datatime,sizeof(datatime),"%Y年/%m月/%d日%H时%M分%S秒",localtime(&t));
    strcpy(lg.date,datatime);
    strcpy(lg.type,"存钱");
    lg.money=m;
    lg.sum=card.sum;
    cout<<setiosflags(ios::fixed);
    cout<<endl<<"卡号："<<card.Cardno<<"   "<<"当前总金额："<<setprecision(2)<<card.sum<<endl;
    LogOperate l_file(card.Cardno);
    l_file.writelog(lg);
}

void CardOperate::CardOut(double m)
{
    if (card.sum>=m)
    {
        t=time(0);
        card.sum-=m;
        lg.Cardno=card.Cardno;
        strftime(datatime,sizeof(datatime),"%Y年/%m月/%d日%H时%M分%S秒",localtime(&t));
        strcpy(lg.date,datatime);
        strcpy(lg.type,"取钱");
        lg.money=m;
        lg.sum=card.sum;
        cout<<setiosflags(ios::fixed);
        cout<<endl<<"卡号："<<card.Cardno<<"   "<<"当前总金额："<<setprecision(2)<<card.sum<<endl;
        LogOperate l_file(card.Cardno);
        l_file.writelog(lg);

    }
    else
    {
        cout<<"\n警告："<<"交易失败，您的账户余额不足！存钱吧小伙子~~\n"<<endl;

    }
}


void CardOperate::listlog()
{
    LogOperate l_file(card.Cardno);
    l_file.listlog();

}

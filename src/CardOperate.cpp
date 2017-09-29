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
    strftime(datatime,sizeof(datatime),"%Y��/%m��/%d��%Hʱ%M��%S��",localtime(&t));
    strcpy(lg.date,datatime);
    strcpy(lg.type,"��Ǯ");
    lg.money=m;
    lg.sum=card.sum;
    cout<<setiosflags(ios::fixed);
    cout<<endl<<"���ţ�"<<card.Cardno<<"   "<<"��ǰ�ܽ�"<<setprecision(2)<<card.sum<<endl;
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
        strftime(datatime,sizeof(datatime),"%Y��/%m��/%d��%Hʱ%M��%S��",localtime(&t));
        strcpy(lg.date,datatime);
        strcpy(lg.type,"ȡǮ");
        lg.money=m;
        lg.sum=card.sum;
        cout<<setiosflags(ios::fixed);
        cout<<endl<<"���ţ�"<<card.Cardno<<"   "<<"��ǰ�ܽ�"<<setprecision(2)<<card.sum<<endl;
        LogOperate l_file(card.Cardno);
        l_file.writelog(lg);

    }
    else
    {
        cout<<"\n���棺"<<"����ʧ�ܣ������˻����㣡��Ǯ��С����~~\n"<<endl;

    }
}


void CardOperate::listlog()
{
    LogOperate l_file(card.Cardno);
    l_file.listlog();

}

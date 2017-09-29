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

void  LogOperate::readlog()
{
    Log l;
    itoa(Cardno,Cardlog,10);
    fstream file(strcat(Cardlog,"Log"),ios::in);
    while(1)
    {
        file.read((char *)&l, sizeof(l));
        if(!file) break;
        top++;
        lf[top]=l;
    }
    file.close();
}



void  LogOperate::writelog(Log lg)
{
    readlog();
    top++;
    lf[top]=lg;
    fstream file(Cardlog,ios::out);
    for (int i = 0; i <=top ; i++)
    {
        file.write((char *)&lf[i], sizeof(lf[i]));
    }
    file.close();
}


void LogOperate::listlog()
{
    readlog();
    for (int i = 0; i <= top; i++)
    {
        cout << "卡号：" << lf[i].Cardno << "日期：" << lf[i].date << "方式："
             << lf[i].type << "输入金额：" << lf[i].money << "总金额：" << lf[i].sum << endl;
    }
}
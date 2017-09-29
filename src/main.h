#define CDNO 6
#define LENGTH 20
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
struct Card  //定义卡的信息结构体
{
    int Cardno;

    char username[LENGTH];

    double sum;
};


struct Log    //定义登录日志信息
{

    int Cardno;

    char date[64];

    char type[6];

    double money;

    double sum;
};



#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#define CDNO 6
#include"main.h"


class CardOperate
{
public:

    CardOperate(int cardindex){};//构造函数

    ~CardOperate(){};//析构函数

    void CardIn(double m);//存款操作模块

    void CardOut(double m);//取款操作模块

    void listlog();//查询存取款日志

private:
    Card card;

    Log lg;

    char filename[CDNO];

    time_t t;

    char datatime[64];
};

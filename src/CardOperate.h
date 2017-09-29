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

    CardOperate(int cardindex){
        {
            t = time(0);
            itoa(cardindex, filename, 10);
            std::fstream file(strcat(filename, ".txt"), std::ios::in);//将两个char类型链接
            while (file)
            {
                file.read((char*)&card, sizeof(card));
            }
            file.close();

        }
    };//构造函数

    ~CardOperate(){
        std::fstream file(filename, std::ios::out);
        file.write((char *)&card, sizeof(card));
        file.close();
    };//析构函数

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

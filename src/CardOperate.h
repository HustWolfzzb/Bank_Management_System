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
            std::fstream file(strcat(filename, ".txt"), std::ios::in);//������char��������
            while (file)
            {
                file.read((char*)&card, sizeof(card));
            }
            file.close();

        }
    };//���캯��

    ~CardOperate(){
        std::fstream file(filename, std::ios::out);
        file.write((char *)&card, sizeof(card));
        file.close();
    };//��������

    void CardIn(double m);//������ģ��

    void CardOut(double m);//ȡ�����ģ��

    void listlog();//��ѯ��ȡ����־

private:
    Card card;

    Log lg;

    char filename[CDNO];

    time_t t;

    char datatime[64];
};

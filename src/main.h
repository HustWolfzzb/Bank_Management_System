#define CDNO 6
#define LENGTH 20
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
struct Card  //���忨����Ϣ�ṹ��
{
    int Cardno;

    char username[LENGTH];

    double sum;
};


struct Log    //�����¼��־��Ϣ
{

    int Cardno;

    char date[64];

    char type[6];

    double money;

    double sum;
};



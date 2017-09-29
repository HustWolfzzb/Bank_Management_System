
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#define CDNO 6

class LogOperate
{
    char Cardlog[CDNO];

    Log lf[100];

    int top;

    int Cardno;

public:

    LogOperate(int n)
    {
        Cardno=n;
        top=-1;
    };

    ~LogOperate()
    {   };

    void readlog();

    void writelog(Log lg);

    void listlog();
};
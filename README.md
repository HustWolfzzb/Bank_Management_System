# Bank_Management_System
这是我第一次写一个C++的项目 感觉还行，调BUG调到哭，在机械厂子里面实习但是在写C++的代码。我的良心一点都不痛啊！！
~\cmake-build-debug 下的那个CMakeFiles.zip压缩包你直接按照本来的名字解压到那个地址下就好了。文件夹实在太多了，懒得弄了



#正文之前

自从课程设计之后，我们就开始了生产实习，我们老师找的是河南卫华集团的技术部实习，经过一阵子的不适应（比如说河南这边的基本没味道的伙食，我们现在两个人中的一个就有一个下饭菜或者老干妈~~）之后，我总算开始了新的学习之旅。


![ My **Old dry mother**](http://upload-images.jianshu.io/upload_images/3810775-fd73132eb8b872c5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


我是一个迷茫的编程爱好者，不知道自己路在何方，当初因为不浪费分填的机械今天也有了报应。那就是我想做互联网的工作，但是又没有那个本事，虽然各方面的编程技能都会点：Web前端，Linux服务器运维，Python爬虫，算法分析，微信小程序，Javascript的一些别的应用，C语言，数据库，PHP多少都会点，但是估计都达不到工作的标准。没办法，我在学校又没有人找我做项目，而且自己也一直是个孤独行者，基本都是自己慢慢钻研，所以广而不精，或者说不得要领。真正强大的人，都是一个或者2个本命语言，然后其他的基本触类旁通几天就可以拿来开发，毕竟底子摆在那，技近乎道的话就是一法通而万法通了。好羡慕那种境界啊。所以，这次实习无聊的我就找到了C++这个被我学长十分看重的语言了。老实说，这个是我接触的第一种语言，大一上就上过课，之后考计算机二级又复习过（丢脸，没过，后来自己自学C过了）。下面是我学完基础之后，结合书上漏洞百出的案例分析以及网上的比较正确的C++实训内容改造而成的一个小项目，C++基础学完了不知道干啥的可以看下！

#正文之中
我呢，勉强算个程序猿，不多说，直接上图上代码(github上传居然被墙了，呵呵，我还能说啥，这都能墙)：
[https://github.com/HustWolfzzb/Bank_Management_System.git](https://github.com/HustWolfzzb/Bank_Management_System.git)

>对了最近好像墙的厉害啊！
![](http://upload-images.jianshu.io/upload_images/3810775-79a723c0dc75df0e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

######图片如下：

* 代码框架：

![](//upload-images.jianshu.io/upload_images/3810775-c8af360d586dcafc.jpg)
* 编辑界面

![](//upload-images.jianshu.io/upload_images/3810775-5dcb834c860f0004.jpg)


*清理完bug之后的场景

![](//upload-images.jianshu.io/upload_images/3810775-6f6b3e61a6a20d83.jpg)


* 产品之---弱智的银行卡

![](//upload-images.jianshu.io/upload_images/3810775-9fb58fafcf992369.jpg)


######代码如下：
>如果你是用的CMake系统，那么这个你得留着：

* CMakelists.txt

```
cmake_minimum_required(VERSION 3.7)
project(C__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)

file(GLOB SOURCES
        "src/**/*.cpp"
        "src/**/*.hpp"
        "src/**/*.h"
        "src/*.h"
        "src/*.cpp"
        "src/*.c"
        )

add_executable(C__ ${SOURCE_FILES} ${SOURCES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")
```
>下面是代码：

* main.cpp

```

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

```


*  main.h

```
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

```



*  CardOperate.h


```
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

```

* CardOperate.cpp

```

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
 
```

* LogOperate.h

```

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

```

* LogOperate.cpp

```
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

```


【Ps：刚刚修复的bug，新鲜出炉的代码咯】
* CardOperate.h  2.0

```
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

```

#正文之后
 
ok，其实是好久没更文了，所以一时忍不住要写点，撤军。在实习的时候还想要我认真的排版写一篇好好看的文？休想！

>另外，我最近一直在考虑要不要考研，还是去就业呢？华科的机械出去就业其实也还行，但是这几天在办公室看他们画图，然后把自己带入进去，发现我并不能接受以后就这么一直过日子，，我宁愿去写码到地老天荒，大学班主任给我的回复是：

>![](http://upload-images.jianshu.io/upload_images/3810775-bb9f578da28ebaf9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

>我得好好考虑下了~~诸位看官有没有好的说法呢？市场上对于非科班出身的程序猿是个啥看法呢？公司会不会因为学生的技能暂时达不到水准而不予招聘呢？

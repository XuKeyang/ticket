//
//  main.cpp
//  tickets
//
//  Created by XuKeyang on 16/10/1.
//  Copyright ? 2016年 XuKeyang. All rights reserved.
//
//  运用了“bool型的数组”将座位的状态转化为true和false 也就是1和0 进行处理
//  运用了宏替换 使得以后对座位总数的修改变得十分便捷

#include <iostream>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

using namespace std;
void welcome();                          //欢迎子函数
void choose();                           //选择子函数
void quit();                             //退出子函数
void shoupiao();                         //售票子函数
void goon();                             //继续子函数
void oneticket();                        //买一张票
void twotickets();                       //买两张票
void threetickets();                     //买三张票
void fourtickets();                      //买四张票
void special();                          //余票特殊处理
void twotickets_();                      //买两张票特殊处理
void threetickets_();                    //买三张票特殊处理
void fourtickets_();                     //买四张票特殊处理
void threetickets_2();                   //第三张票为什么总出错

int k=0;//特殊处理下的中间变量
int l=0;//特殊处理下的中间变量
int m=0;//特殊处理下的中间变量
int j=0;//是否售空变量
int number; //购买张数

#define num 80 //宏替换
int n=num;

//欢迎子函数
void welcome()
{
    cout<<"________________________________________________________"<<endl;
    cout<<"|   欢 * 迎 * 使 * 用 * 火 * 车 * 票 * 售 * 票 * 系 * 统   |"<<endl;
    cout<<"|                                                      |"<<endl;
    cout<<"|                                                      |"<<endl;
    cout<<"|                        1.买票                         |"<<endl;
    cout<<"|                        2.退出                         |"<<endl;
    cout<<"|                                                      |"<<endl;
    cout<<"|______________________________________________________|"<<endl;
    cout<<"请输入所要执行功能前的数字: "<<endl;
    choose();
}

//选择子函数
void choose()
{
    string i;
    cin>>i;
    if(i=="1")
        shoupiao();
    if(i=="2")
        quit();
    else
    {
        cout<<"输入有误!请在数字1-2之间重新输入选择!"<<endl;
        choose();
    }
}

//退出子函数
void quit()
{
    cout<<"*****************谢谢使用本系统，欢迎下次继续使用*****************"<<endl;
    exit(0);
}

//bool数组
//const int num = 80;
bool a[num];
void arr()
{
    memset(a,false,sizeof(a));
}

//继续子函数
void goon()
{
    int t;
    cout<<"是否继续买票?(是请输1,否请输任意键返回主菜单)"<<endl;
    cin>>t;
    if(t!=1)
        welcome();
    else shoupiao();
}

//买一张票
void oneticket()
{
    if(j<(num +1)){
        int i=0;//座位号
        cout << "系统正在分配，请稍后...";
        cout << "\n您要购买的张数是:"<< number<<"\n";
    re:if(a[i]==false && i<num ){
        cout << "给您分配的座位是:"<< i+1 <<"\n""\n";
        a[i]=true;
        goon();
    }
    else{
        i++;
        goto re;
    }
    }
    else
        special();
}

//买两张票
void twotickets()
{
    if(j<(num +1)){
        int i=0;
    re:if(a[i]==false && a[i+1]==false && i%2 ==0 && i<num ){
        cout << "系统正在分配，请稍后...";
        cout << "\n您要购买的张数是:"<< number<<"\n";
        cout << "给您分配的座位是:"<< i+1 <<"和"<< i+2 <<"\n""\n";
        a[i]=true;
        a[i+1]=true;
        goon();
    }
        
    else{
        i++;
        goto re;
    }
    }
    else
        special();
}

//买三张票
void threetickets()
{
    n=80;
    if(j<(num +1)){
        int i=0;//座位号
        cout << "系统正在分配，请稍后...";
        cout << "\n您要购买的张数是:"<< number<<"\n";
    re:if((a[i]==false && a[i+1]==false && a[i+4]==false && a[i+5]==false && (i+6)%8==0  && i<(num-6))||(a[i]==false && a[i+1]==false && a[i+4]==false && a[i+5]==false && (i+8)%8==0  && i<(num-6) )){
        cout << "给您分配的座位是:"<<i+1<<"和"<<i+2<<"和"<<i+5<<"\n""\n";
        a[i]=true;
        a[i+1]=true;
        a[i+4]=true;
        goon();
    }
        if((a[i]==true && a[i+1]==false && a[i+4]==false && a[i+5]==false && (i+6)%8==0 && i<(num-6) )||(a[i]==true && a[i+1]==false && a[i+4]==false && a[i+5]==false && (i+8)%8==0  && i<(num-6) )){
            cout << "给您分配的座位是:"<<i+2<<"和"<<i+5<<"和"<<i+6<<"\n""\n";
            a[i]=true;
            a[i+1]=true;
            a[i+4]=true;
            a[i+5]=true;
            goon();
        }
        if((a[i]==false && a[i+1]==true && a[i+4]==false && a[i+5]==false && (i+6)%8==0  && i<(num-6) )||(a[i]==false && a[i+1]==true && a[i+4]==false && a[i+5]==false && (i+8)%8==0  && i<(num-6) )){
            cout << "给您分配的座位是:"<<i+1<<"和"<<i+5<<"和"<<i+6<<"\n""\n";
            a[i]=true;
            a[i+1]=true;
            a[i+4]=true;
            a[i+5]=true;
            goon();
        }
        if((a[i]==false && a[i+1]==false && a[i+4]==true && a[i+5]==false && (i+6)%8==0  && i<(num-6) )||(a[i]==false && a[i+1]==false && a[i+4]==true && a[i+5]==false && (i+8)%8==0  && i<(num-5) )){
            cout << "给您分配的座位是:"<<i+1<<"和"<<i+2<<"和"<<i+6<<"\n""\n";
            a[i]=true;
            a[i+1]=true;
            a[i+4]=true;
            a[i+5]=true;
            goon();
        }
        if((a[i]==false && a[i+1]==false && a[i+4]==false && a[i+5]==true && (i+6)%8==0  && i<(num-6) )||(a[i]==false && a[i+1]==false && a[i+4]==false && a[i+5]==true && (i+8)%8==0  && i<(num-5) )){
            cout << "给您分配的座位是:"<<i+1<<"和"<<i+2<<"和"<<i+5<<"\n""\n";
            a[i]=true;
            a[i+1]=true;
            a[i+4]=true;
            a[i+5]=true;
            goon();
        }
        else{
            i++;
            if(i>80)
                threetickets_2();
            else{
                goto re;
            }
        }
    }
    else
        special();
}

//买四张票
void fourtickets()
{
    n=80;
    if(j<(num +1)){
        int i=0;//座位号
        cout << "系统正在分配，请稍后...";
        cout << "\n您要购买的张数是:"<< number<<"\n";
    re:if((a[i]==false && a[i+1]==false && a[i+4]==false && a[i+5]==false && (i+6)%8==0  && i<(num-5) )||(a[i]==false && a[i+1]==false && a[i+4]==false && a[i+5]==false && (i+8)%8==0  && i<(num-5))){
        cout << "给您分配的座位是:"<< i+1 <<"和"<<i+2<<"和"<<i+5<<"和"<<i+6<<"\n""\n";
        a[i]=true;
        a[i+1]=true;
        a[i+4]=true;
        a[i+5]=true;
        goon();
    }
    else{
        i++;
        goto re;
    }
    }
    else
        special();
}

//买两张票特殊处理
void twotickets_()
{
    if(a[n]==false && a[n-1]==false){
        twotickets();
    }
    else
    {
        k=0;
        if(j<(num +1)){
            int i=0;
        re:if(a[i]==false && i<num ){
            a[i]=true;
        }
        else{
            i++;
            goto re;
        }
        re2:if(a[k]==false && k<num){
            a[k]=true;
        }
        else {
            k++;
            goto re2;
        }
            cout << "系统正在分配，请稍后...";
            cout << "\n您要购买的张数是:"<< number<<"\n";
            cout << "给您分配的座位是:"<< i+1 <<"和"<< k+1 <<"\n""\n";
            goon();
        }
        else
            special();
    }
}

//买三张票特殊处理
void threetickets_()
{
    n=80;
    if((a[n -5]==false && a[n-4]==false && a[n-1]==false )||(a[n -5]==false && a[n-4]==false && a[n]==false)||(a[n -5]==false && a[n]==false && a[n-1]==false)||(a[n ]==false && a[n-4]==false && a[n-1]==false)){
        threetickets();
    }
    else{
        int i=0;
        k=0;
        l=0;
        if(j<(num +1)){
				    re:if(a[i]==false && i<=num ){
                        a[i]=true;
                    }
                    else{
                        i++;
                        goto re;
                    }
				    re2:if(a[k]==false && k<=num){
                        a[k]=true;
                    }
                    else {
                        k++;
                        goto re2;
                    }
				    re3:if(a[l]==false && l<=num){
                        a[l]=true;
                    }
                    else {
                        l++;
                        goto re3;
                    }
				        cout << "系统正在分配，请稍后...";
				        cout << "\n您要购买的张数是:"<< number<<"\n";
				        cout << "给您分配的座位是:"<< i+1 <<"和"<< k+1 <<"和"<< l+1<<"\n""\n";
				        goon();
        }
        else
            special();
    }
}

//第三张票为什么总出错
void threetickets_2()
{
    int i=0;
    k=0;
    l=0;
    if(j<(num +1)){
    re:if(a[i]==false && i<=num ){
        a[i]=true;
    }
    else{
        i++;
        goto re;
    }
    re2:if(a[k]==false && k<=num){
        a[k]=true;
    }
    else {
        k++;
        goto re2;
    }
    re3:if(a[l]==false && l<=num){
        a[l]=true;
    }
    else {
        l++;
        goto re3;
    }
        cout << "系统正在分配，请稍后...";
        cout << "\n您要购买的张数是:"<< number<<"\n";
        cout << "给您分配的座位是:"<< i+1 <<"和"<< k+1 <<"和"<< l+1<<"\n""\n";
        goon();
    }
    else
        special();
    
}

//买四张票特殊处理
void fourtickets_()
{
    n=80;
    if(a[n-5]==false && a[n-4]==false && a[n-1]==false && a[n]==false)
    {
        fourtickets();
    }
    else{
        int i=0;
        k=0;
        l=0;
        m=0;
        if(j<(num +1)){
        re:if(a[i]==false && i<num ){
            a[i]=true;
        }
        else{
            i++;
            goto re;
        }
        re2:if(a[k]==false && k<num){
            a[k]=true;
        }
        else {
            k++;
            goto re2;
        }
        re3:if(a[l]==false && l<num){
            a[l]=true;
        }
        else {
            l++;
            goto re3;
        }
        re4:if(a[m]==false && m<num){
            a[m]=true;
        }
        else {
            m++;
            goto re4;
        }
            cout << "系统正在分配，请稍后...";
            cout << "\n您要购买的张数是:"<< number<<"\n";
            cout << "给您分配的座位是:"<< i+1 <<"和"<< k+1 <<"和"<< l+1<<"和"<< m+1<<"\n""\n";
            goon();
        }
        else
            special();
    }
}

//余票特殊处理
void special()
{
    if(j<(num+1)){
    re:cout << "请输入你要买的张数:";
        cin >> number;
        if(number==1)
        {
            if(j<num)
            {
                j++;
                //                cout<<"余票处理j="<<j<<endl;
                oneticket();
            }
            else{
                goto qu;
            }
        }
        if(number==2)
        {
            if(j<(num-1))
            {
                j=j+2;
                //               cout<<"余票处理j="<<j<<endl;
                twotickets_();
            }
            else{
                cout<<"抱歉！当前票源不足两张。"<<endl;
                goto re;
            }
        }
        if(number==3)
        {
            if(j<(num-2))
            {
                j=j+3;
                //                  cout<<"余票处理j="<<j<<endl;
                threetickets_();
            }
            else{
                cout<<"抱歉！当前票源不足三张。"<<endl;
                goto re;
            }
        }
        if(number==4)
        {
            if(j<(num-3))
            {
                j=j+4;
                //                 cout<<"余票处理j="<<j<<endl;
                fourtickets_();
            }
            else{
                cout<<"抱歉！当前票源不足四张。"<<endl;
                goto re;
            }
        }
        else
        {
            cout<<"输入数据有误,需要输入1-4的整数.\n"<<endl;
            goto re;
        }
    }
    else
    {
    qu:cout<<"**********今天的票已售空**********\n"<<endl;
        quit();
    }
    
}

//售票子函数
void shoupiao()
{
    if(j<(num-22)){
    re:cout << "请输入你要买的张数:";
        cin >> number;
        if(number==1)
        {j++;
            //          cout<<"j="<<j<<endl;
            oneticket();
        }
        if(number==2)
        {
            j=j+2;
            //          cout<<"j="<<j<<endl;
            twotickets();}
        if(number==3)
        {
            j=j+3;
            //          cout<<"j="<<j<<endl;
            threetickets();}
        if(number==4)
        {
            j=j+4;
            //          cout<<"j="<<j<<endl;
            fourtickets();}
        else
        {
            cout<<"输入数据有误,需要输入1-4的整数.\n"<<endl;
            goto re;
        }
    }
    else
    {
        special();
    }
}

//主函数
int main()
{
    welcome();
    return 0;
}
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


#define INT_MAX 2147483647
#define INT_MIN -2147483678
int my_atoi(char *ptr)
{
    int ret=0;
    int sign=1;

    /*if(ptr==NULL)
    {
        cout<<"String::atoi() ptr is NULL"<<endl;
        return 0;
    }
    while(isspace(*ptr)!=0)
    {
        ptr++;
    }

    if(*ptr=='-')
        sign=-1;
    if(*ptr=='-' || *ptr=='+')
        ptr++;

    while (*ptr>='0' && *ptr<='9')
    {
        ret=ret*10+*ptr-'0';
        ptr++;
    }
    ret=sign*ret;

    return ret;*/

    long long num=0;
    if(ptr!=NULL && *ptr!='\0')
    {
        while(*ptr==' ')
        {
            ptr++;
            continue;
        }
        bool sign= false;
        if(*ptr=='+')
            ptr++;
        else if(*ptr=='-')
        {
            ptr++;
            sign=true;
        }
        if(*ptr!='\0')
        {
            num=stroi(ptr,sign);
        }

    }
}

long long stroi(const char* str,bool minus)
{
    long long num=0;
    while(*str!='\0')
    {
        if(*str>=0 && *str<=9)
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + (*str - '0') * flag;

            if (minus == false && num > (0x7FFFFFFF))
                return INT_MAX;
            else if (minus == true && num < (signed int) 0x80000000)
                return INT_MIN;
            str++;
        }
        else
            break;
    }
    return num;
}

int main()
{   
    printf("%d",my_atoi("  -2345"));

    
}
//
// Created by bokket on 2020/12/3.
//

#include "String.h"
#include <string>
/***
 * delete _str和delete [] _str的区别  
***/
String::~String() { delete [] _str; }
String::String()
{
    len_=0;
    _str= new char[len_+1];
    strcpy(_str,"");
}
String::String(const char *str)
{
    if(str==NULL)
    {
        len_=0;
        _str=new char[len_+1];
        strcpy(_str,"");
    }
    else
    {
        len_=strlen(str);
        _str=new char[len_+1];
        strcpy(_str,str);
    }
}
String::String(const String &str)
{
    if(str._str==NULL)
    {
        len_=0;
        _str=new char[len_+1];
        strcpy(_str,"");
    }
    if(_str!=NULL)
    {
        delete []_str;
    }
    len_=str.len_;
    _str=new char[len_+1];
    strcpy(_str,str._str);
}
String::String(size_t n, const char c)
{
    len_=n;
    _str=new char[len_+1];
    for(int i=0;i<n;i++)
    {
        _str[i]=c;
    }
}


String & String::operator=(char *) {}
String & String::operator=(const String &str) {}
String & String::operator=(String str) {}

String & String::operator!=(const String &, const String &) {}

String & String::operator+(char) {}
String & String::operator+(const String &str) const {}
String & String::operator+(char *) {}

String & String::operator+=(char c) {}
String & String::operator+=(const String &str) {}
String & String::operator+=(const char *s) {}

char & String::operator[](size_t n) {}
const char & String::operator[](size_t pos) const {}

bool String::operator==(const String &str) const {}

ostream & operator<<(ostream& os,String & str);
istream & operator>>(istream& is,String & str);
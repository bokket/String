//
// Created by bokket on 2020/12/3.
//

#include "String.h"
#include <cstring.h>
/***
 * delete _str和delete [] _str的区别  
***/
String::~String()
{
    if(_str!=NULL)
    {
        delete [] _str;
        _str=NULL;
    }
    capacity_=0;
    len_=0;
}
String::String()
        :_str(new char[1])
        ,capacity_(0)
        ,len_(0)
{
    strcpy(_str,"");
    /*
    len_=0;
    _str= new char[len_+1];
    strcpy(_str,"");*/
}
String::String(const char *s="")
        :capacity_(strlen(s)+1)
        ,len_(strlen(s))
        ,_str(new char[strlen(s)+1])
{
    strcpy(_str,s);
            /*
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
             */
}
String::String(const String &str)
        :capacity_(strlen(str._str)+1)
        ,len_(strlen(str._str))
        ,_str(new char[strlen(str._str)+1])
{
    strcpy(_str,str._str);
    /*if(str._str==NULL)
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
*/
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


void String::CheckCapacity(size_t pos)
{
    if(len_+1+pos >= capacity_)
    {
        capacity_=capacity_*2+10;
        char *tmp=new char[capacity_];
        strcpy(tmp,_str);
        delete [] _str;
        _str=tmp;
    }
}


String & String::operator=(const String &str)
{
    /*if(str==NULL)
        delete []_str;
    if(str._str==NULL)
    {
        len_=0;
        _str=new char[len_+1];
        strcpy(_str,"");
    }
    else
    {
        len_=str.len_;
        _str=new char[len_+1];
        strcpy(_str,str._str);
    }*/
    if(this!=&str)
    {
        delete []_str;
        _str=new char[strlen(str._str)+1];
        strcpy(_str,str._str);
    }
    return *this;
}
String & String::operator=(char *s)
{
    if(s==NULL)
    {
        len_=0;
        _str=new char[len_+1];
        strcpy(_str,"");
    }
    else
    {
        len_=strlen(s);
        _str=new char[len_+1];
        strcpy(_str,s);
    }
}


String & String::operator=(String str)
{
    cout<<"this is String & string::operator= (String str);"<<endl;

    swap(_str,str._str);
    capacity_=strlne(str._str+1);
    len_=str.len_;
    return *this;
}

char & String::operator[](size_t n)
{
    if(n<0 || n>len_)
        cout<<"数组越界"<<endl;
    return _str[n];
}
const char & String::operator[](size_t n) const
{
    if(n<0 || n>len_)
        cout<<"数组越界"<<endl;
    return _str[n];
}

char & String::at(size_t n)
{
    if(n<0 || n>len_)
        throw 0;
    return _str[n];
}

const char * String::c_str() const
{
    return _str;
}

String & String::operator!=(const String &, const String &)
{

}

String & String::operator+(char)
{

}
String & String::operator+(const String &str) const
{

}
String & String::operator+(char *)
{

}

String & String::operator+=(char c)
{
    CheckCapacity(1);
    _str[len_++]=c;
    _str[len_]='\0';
    return *this;
}
String & String::operator+=(const String &str)
{
    char* des;
    CheckCapacity(strlen(str._str));
    if(_str!=NULL)
    {
        des=new char[len_+1];
        strcpy(des,_str);
        delete []_str;
    }
    if(str._str!=NULL)
    {
        len_+=str.len_;
        _str=new char[len_+1];
        strcpy(_str,des);
        strcpy(_str,str._str);
    }
}
String & String::operator+=(const char *s)
{
    CheckCapacity(strlen(s));
    char* des;
    if(_str!=NULL)
    {
        des=new char[len_+1];
        strcpy(des,s);
        delete []_str;
    }
    if(s!=NULL)
    {
        len_+=strlen(s);
        _str=new char[len_+1];
        strcpy(_str,des);
        strcpy(_str,s);
    }
    return *this;
}



bool String::operator==(const String &str) const
{
    int size=strlen(str._str);
    if(size!=len_)
        return false;
    else
    {
        for(int i=0;i<size;i++)
        {
            if(_str[i]!=str._str[i])
                return false;
        }
    }
    return true;
}
bool String::operator==(const char *s) const
{
    int size=strlen(s);
    if(size!=len_)
        return false;
    else
    {
        for(int i=0;i<size;i++)
        {
            if(s[i]!=_str[i])
                return false;
        }
    }
    return true;
}
bool String::operator!=(const String &str)
{
    int size=strlen(str._str);
    if(size!=len_)
    {
        return true;
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            if(_str[i]!=str._str[i])
                return true;
        }
    }
    return false;
}
bool String::operator!=(const char *s)
{
    int size=strlen(s);
    if(size!=len_)
    {
        return true;
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            if(_str[i]!=s[i])
                return true;
        }
    }
    return false;
}
bool String::operator>(const String &str)
{
    if(strcmp(_str,str._str)>0)
        return true;
    else
        return false;
}
bool String::operator>(const char *s)
{
    if(strcmp(_str,s)>0)
        return true;
    else
        return false;
}
bool String::operator<(const String &str)
{
    if(strcmp(_str,str._str)<0)
        return true;
    else
        return false;
}
bool String::operator<(const char *s)
{
    if(strcmp(_str,s)<0)
        return true;
    else
        return false;
}
ostream & operator<<(ostream& os,String & str)
{
    os<<str._str;
    return os;
}
istream & operator>>(istream& is,String & str)
{
    is>>str._str;
    return in;
}
size_t String::size() const
{
    return len_;
}
size_t String::length()
{
    return len_;
}
void String::set_length(size_t len)
{

}

char * String::memcpy(char *des, const char *src, size_t n)
{
    static_assert(des && src, "des && src is empty");
    while(n--)
    {
        *des++=*src++;
    }
    return dest;
}

int String::strlen(const char *)
{}

void String::push_back(const char *s)
{

}
void String::push_back(const char c)
{
    CheckCapacity(1);
    _str[len_++]=c;
    _str[len_]='\0';
}

size_t String::find(const char *s, int pos)
{

}
size_t String::find(const String &str, int pos)
{

}
size_t String::find(const char c, int pos) const
{

}
bool String::Empty()
{
    if(_str==NULL)
        return true;
    else
        return false;
}
String & String::swap(const char *s)
{

}
String & String::swap(const String &str)
{

}

String String::substr(size_t begin, size_t end)
{

}
String & String::assign(const String &, size_t, size_t)
{

}

String & String::erase(size_t pos, size_t len)
{

}

String & String::append(const String &str)
{

}
String & String::append(const char *s)
{

}
String & String::append(size_t pos, const char c)
{

}
String & String::append(const String &str, size_t pos, size_t len)
{

}
size_t String::compare(const char *s) const
{

}
size_t String::compare(const String &str) const
{

}
int String::copy(char *s, size_t n, size_t pos) const
{

}
bool String::equals(const char *other)
{

}
bool String::equals(const String &other)
{

}
String & String::insert(size_t pos1, const char *s)
{

}
String & String::insert(size_t pos1, size_t n, char c)
{}

String & String::insert(size_t pos1, const String &str)
{

}
String & String::insert(size_t pos1, const char *s, size_t n)
{

}
String & String::insert(size_t pos1, const String &str, size_t pos2, size_t n)
{

}

String & String::replace(size_t begin, size_t end, const char c)
{

}
int String::replaceAll(char, char)
{

}
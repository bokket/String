//
// Created by bokket on 2020/12/3.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H
#include <iostream>
using namespace std;
class String
{
    friend ostream & operator<<(ostream& os,String & str);
    friend istream & operator>>(istream& is,String & str);
public:
    String();
    String(const char*);
    String(const String& str);
    String(const size_t,const char);
    ~String();
public:
    void push_back(const char* c);//
    size_t  length();
    bool Empty();

    String & insert(size_t pos1,const String & str);
    String & insert(size_t pos1,const String & str,size_t pos2,size_t n);
    String & insert(size_t pos1,const char* s,size_t n);
    String & insert(size_t pos1,const char* s);
    String & insert(size_t pos1,size_t n,char c);


    size_t size( ) const;
    void set_length(size_t len);
    const char *c_str() const;
    int replaceAll(char , char);
    String substr(size_t ,size_t);
    String & append(const String &);
    String & assign(const String& ,size_t,size_t);
    String & erase(size_t,size_t);

    int strlen(const char *);
    void memcpy(char*,size_t ,const chat*,size_t);
    String subString(size_t , size_t);
    bool equals(const String & other);
    bool equals(const char* other);


public:
    String & operator=(const String& str);
    String & operator=(String str);
    String & operator=(char *);
    String & operator+(const String & str) const;//
    String & operator+(char );
    String & operator+(char*);

    String & operator+=(const String & str);//
    String & operator+=(const char* s);
    String & operator+=(char c);

    String & operator!=(const String& ,const String &);


    bool operator==(const String & str) const;

    const char & operator[](size_t pos) const;
    char & operator[](size_t n);//



private:
    char *_str;
    size_t len_;

};


#endif //STRING_STRING_H

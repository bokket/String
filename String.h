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
    String(const char* str);
    String(const String& str);
    String(size_t n,const char c);
    ~String();

public:
    void push_back(const char* c);//

    size_t size();
    size_t length();

    size_t find(const char c,int pos) const;
    size_t find(const char* s,int pos);
    size_t find(const String & str,int pos);

    bool Empty();

    String & insert(size_t pos1,const String & str);
    String & insert(size_t pos1,const String & str,size_t pos2,size_t n);
    String & insert(size_t pos1,const char* s,size_t n);
    String & insert(size_t pos1,const char* s);
    String & insert(size_t pos1,size_t n,char c);


    size_t size( ) const;
    void set_length(size_t len);

    const char *c_str() const;
    char & at(size_t n);

    String & replace(size_t begin,size_t end,const char c);
    int replaceAll(char , char);

    String & append(const String & str);
    String & append(const char* s);
    String & append(size_t pos,const char c);
    String & append(const String & str,size_t pos,size_t len);


    String & assign(const String& ,size_t,size_t);

    String & erase(size_t pos,size_t len);

    String & swap(const char* s);
    String & swap(const String & str);

    String substr(size_t begin,size_t end);

    int strlen(const char *);
    void memcpy(char*,size_t ,const chat*,size_t);

    size_t compare(const String & str) const;
    size_t compare(const char* s) const;

    int copy(char *s,size_t n,size_t pos=0) const;

    bool equals(const String & other);
    bool equals(const char* other);


public:
    String & operator=(const String& str);
    String & operator=(String str);
    String & operator=(const char *s);



    String & operator+(const String & str) const;//
    String & operator+(char );
    String & operator+(char*);

    String & operator+=(const String & str);//
    String & operator+=(const char* s);
    String & operator+=(char c);

    String & operator!=(const String& ,const String &);


    bool operator==(const String & str) const;
    bool operator==(const char* s) const;
    bool operator!=(const String & str);
    bool operator!=(const char* s);
    bool operator>(const String & str);
    bool operator>(const char* s);
    bool operator<(const String & str);
    bool operator<(const char* s);

    const char & operator[](size_t pos) const;
    char & operator[](size_t n);//



private:
    char *_str;
    size_t len_;

};


#endif //STRING_STRING_H

//
// Created by bokket on 2020/12/3.
//

#include "String.h"
String::~String() { delete [] _str; }
String::String() {}
String::String(const char *) {}
String::String(const String &str) {}
String::String(const size_t, const char) {}


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
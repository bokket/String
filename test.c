#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   
    char p[10]="test";
    char s='g';
    memcpy(p+2,&s,1);
    puts(p);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   
    char p[10]="test";
    char *s="sdfgf";
    memcpy(p+strlen(p),s,strlen(s));
    puts(p);
}
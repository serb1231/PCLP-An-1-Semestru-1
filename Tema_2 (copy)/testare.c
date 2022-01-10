#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char*a = malloc(100);
    fgets(a,100,stdin);
    printf("%s",a);
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "structura.h"
void interschimbare(site_continut*a1,site_continut*a2)
{
    site_continut*tmp = a1;
    a1 = a2;
    a2 = tmp;
}
int main()
{
    site_continut *a1;
    a1 = malloc(100);
    strcpy(a1[1].titlu,"erds");
    strcpy(a1[2].titlu,"14231");
    site_continut a = a1[1];
    interschimbare(&(a1[1]),&(a1[2]));
    printf("%s,%s",a1[1].titlu,a1[2].titlu);

}
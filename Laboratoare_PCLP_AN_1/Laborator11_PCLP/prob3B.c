#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[])
{
    FILE* fisier;
    fisier = fopen(argv[argc-2],"r");
    if(fisier==NULL)
    {
        printf("negasit");
        return 0;
    }
    int notat_i = 0,notat_n = 0,notat_c = 0;
    for(int i=1;i<=argc-3;i++)
    {
        if(strcmp(argv[i],"i")==0)
        notat_i = 1;
        if(strcmp(argv[i],"n")==0)
        notat_n = 1;
        if(strcmp(argv[i],"c")==0)
        notat_c = 1;
    }
    char* linie = calloc(100,sizeof(char));
    char* linie_lower = calloc(100,sizeof(char));
    char*string = argv[argc-1];
    char*string_lower = calloc(100,sizeof(char));
    for (int i = 0; i < strlen(string); i++)
    {
        for(int i=0;i<strlen(string);i++)
        if(string[i]>=65&&string[i]<=90)
            string_lower[i] = string[i]+32;
        else
            string_lower[i] = string[i];
    }
    int a=0;
    int nr_linii = 0;
    while (fgets(linie,100,fisier))
    {
        for(int i=0;i<strlen(linie);i++)
        if(linie[i]>=65&&linie[i]<=90)
            linie_lower[i] = linie[i]+32;
        else
            linie_lower[i] = linie[i];
            a++;
            if(notat_n==1){
        if(notat_i==1&&strstr(linie_lower,string_lower)!=NULL)
        {printf("[%d]%s",a,linie);nr_linii++;}
        else
        if(strstr(linie,string)!=NULL)
        {printf("[%d]%s",a,linie);nr_linii++;}
            }
            else
            {
            if(notat_i==1&&strstr(linie_lower,string_lower)!=NULL)
        {printf("%s",linie);nr_linii++;}
        else
        if(strstr(linie,string)!=NULL)
        {printf("%s",linie);nr_linii++;}
            }
        memset(linie_lower,0,99);
    }
    if(notat_c==1)
    printf("Nr total de linii:%d\n",nr_linii);
    free(linie);
    free(linie_lower);
    free(string_lower);
    fclose(fisier);
    
    
}
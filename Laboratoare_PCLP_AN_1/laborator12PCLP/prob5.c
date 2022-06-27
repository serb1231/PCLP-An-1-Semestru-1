#include"header.h"
int main(int argc,char*argv[])
{
    creare(argv[1]);
    sortare_fisier(argv[1]);
    char *de_cautat = calloc(100,1);
    scanf("%s",de_cautat);
    strcpy(de_cautat,de_cautat);
    task5(argv[1],de_cautat);
}
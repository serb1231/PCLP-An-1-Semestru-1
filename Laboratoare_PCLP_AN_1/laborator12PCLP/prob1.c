#include"prob1_header.h"
int  main(int argc,char* argv[])
{
    Elev *elev1 = calloc(100,sizeof(Elev));
    for(int i=1;i<=argc - 1;i++)
    {
        if(i%3 == 1)
        elev1[(i-1)/3].cantitate = atoi(argv[i]);
        if(i%3 == 2)
        {int aux = atoi(argv[i]);elev1[(i-1)/3].pret_produs = aux;}
        if(i%3 == 0)
        strcpy(elev1[(i-1)/3].nume_produs,argv[i]);
    }
    for(int i=0;i<=argc/3;i++)
    printf("%s %d %f\n\n",elev1[i].nume_produs,elev1[i].cantitate,elev1[i].pret_produs);
}
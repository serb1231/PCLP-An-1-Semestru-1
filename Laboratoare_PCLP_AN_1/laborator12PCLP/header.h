#ifndef SET_H
    #define SET_H
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<math.h>
    void creare(char*nume);
    void afisare_ecran(char* nume_fisier);
    void sortare_fisier(char* nume_fisier);
    void task5(char*nume_fisier,char*nume_cautat);
    typedef struct{
        char produs[30];
        long int procent;
        float intrebare;
    }Produs;
    void swap(Produs*a1,Produs*a2);
#endif
void swap(Produs*a1,Produs*a2)
{
        Produs aux = *a1;
        *a1= *a2;
        *a2 = aux;
}
void creare(char*nume)
{
    FILE* scriere = fopen(nume,"wb");
    Produs element;
    for(int i=1;i<=100;i++)
    {
        int x = rand();
        sprintf(element.produs,"Produs%d",x);
        element.procent = x%100;
        element.intrebare = x<=100?x:x%100;
        fwrite(&element,sizeof(element),1,scriere);
    }
    fclose(scriere);
}
void afisare_ecran(char* nume_fisier)
{
    FILE* scriere = fopen(nume_fisier,"rb");
    Produs element;
    while (fread(&element,sizeof(element),1,scriere))
    {
        printf("%s %ld %f\n",element.produs,element.procent,element.intrebare);
    }
    
}
void sortare_fisier(char*nume_fisier)
{
    FILE* scriere = fopen(nume_fisier,"rb");
    Produs element;
    Produs *vector_elem = calloc(100,sizeof(Produs));
    int nr_elem = -1;
    while (fread(&element,sizeof(element),1,scriere))
    {
        nr_elem++;
        vector_elem[nr_elem].intrebare = element.intrebare;
        vector_elem[nr_elem].procent = element.procent;
        strcpy(vector_elem[nr_elem].produs,element.produs);
    }
    for(int i=0;i<=nr_elem;i++)
    for(int j=i+1;j<=nr_elem;j++)
    if(strcmp(vector_elem[i].produs,vector_elem[j].produs)<0)
    {
        swap(vector_elem+i,vector_elem+j);
    }
    fclose(scriere);
    scriere = fopen(nume_fisier,"wb");
    for(int i=0;i<=nr_elem;i++){
   Produs v;
   strcpy(v.produs,vector_elem[i].produs);
   v.intrebare = vector_elem[i].intrebare;
   v.procent = vector_elem[i].procent;
   //printf("%s\n",v.produs);
   fwrite(&v,sizeof(v),1,scriere);
    }
}
void task5(char*nume_fisier,char*nume_cautat)
{
    FILE*fisier = fopen(nume_fisier,"rb");
    Produs element;
    int gasit = 0;
    while(fread(&element,sizeof(element),1,fisier))
    {
        if(strcmp(element.produs,nume_cautat)==0)
        {
            gasit = 1;
            printf("%f %ld",element.intrebare,element.procent);
            break;
        }
    }
    if(gasit==0)
    printf("nu s-a gasit");
}
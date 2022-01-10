#include <stdio.h>

#include<stdlib.h>

#include<math.h>

#include<string.h>


#include "structura.h"
void swap(site_continut * a1,site_continut* a2)
{
    site_continut* tmp = a1;
    a1=a2;
    a2=tmp;
}
int main(void)
{
    site_continut *site = malloc(3);
    int site_problema[100],nr_site_problema = 0;
    int nr_site = 0;
    nr_site = depunere_in_memorie(site,0);
    //printf("%s %ld %s %d %d \n",site[1].url,site[1].nr_accesari,site[1].titlu,site[1].text,site[1].bkg);
    char *words = malloc(100);
    fgets(words,100,stdin);
    
    //printf("%s",words);
    //printf("fdsdsa");
    int lung = -1;
    
    char*cuv = malloc(100);
    words[strlen(words)]=' ';
    int *site_pus = calloc(100,sizeof(int));
    for(int i=0;i<strlen(words);i++)
    {
        if(words[i]!=' ')
            {
                lung++;
                cuv[lung]=words[i];
            }
        else
        {
            printf("\n%s\n",cuv);
            char *de_verificat = malloc(100);
            strcpy(de_verificat, cuv);
            printf("\n%s\n",de_verificat);
            for(int i=1;i<=nr_site;i++)
            {
                //printf("\n%s\n%s",de_verificat,site[i].continut);
                char * inceput = malloc(100);
                
                char * sfarsit =malloc(100);
                char *continut = malloc(strlen(site[i].continut)+10);
                continut[0]=' ';strcpy(continut+1,site[i].continut);
                continut[strlen(continut)]=' ';
                printf("%s \n %s",continut,de_verificat);
                inceput = strstr(continut,de_verificat);
                sfarsit = inceput + strlen(de_verificat) - 1;
                printf("\n\n%s   \n\n",inceput);
                if(inceput!=NULL&&sfarsit!=NULL)printf("\n\n%c  %c \n\n",inceput[0],sfarsit[0]);
                if(strstr(site[i].continut,de_verificat)!=NULL&&site_pus[i]==0)
                if(((inceput-1)[0]==' ')&&((sfarsit+1)[0]==' '))
                {
                    printf("\n%s\n%s",de_verificat,site[i].continut);
                    site_pus[i]=1;
                    printf("%d\n",i);
                    nr_site_problema++;
                    site_problema[nr_site_problema] = i;
                }
            }
            lung = -1;
            cuv = calloc(100,sizeof(char));
        }
         //printf("%d %s",lung, cuv);
    }
    for(int i=1;i<=nr_site_problema;i++)
    {
        for(int j=i+1;j<=nr_site_problema;j++)
        {
            if(strcmp(site[i].continut, site[j].continut) == 0 && site[i].nr_accesari<site[j].nr_accesari)
            swap(site+i,site+j);
            else
            if(strcmp(site[i].titlu,site[j].titlu)>0)
            swap(site+i,site+j);
        }
    }
    //for(int i=1;i<nr_site_problema;i++)
    //printf("%s",site[site_problema[i]].url);
}
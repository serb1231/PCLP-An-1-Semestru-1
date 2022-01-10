#include <stdio.h>

#include<stdlib.h>

#include<math.h>

#include<string.h>

#include "structura.h"

int main(void) {
  site_continut * site = malloc(3);
  int nr_site_problema = 0;
  int * site_problema = calloc(100, sizeof(int));
  int nr_site = 0;
  int nr_cuv_rele = -1;
  char*cuv_rele[100];
  nr_site = depunere_in_memorie(site, 0);
  char * words = malloc(100);
  fgets(words, 100, stdin);
  int lung = -1;
  char * cuv = malloc(100);
  words[strlen(words)] = ' ';
  int * site_pus = calloc(100, sizeof(int));
  for (int i = 0; i < strlen(words); i++) {
    if (words[i] == '"') {
      int * verificat_secventa = calloc(100, sizeof(int));
      int nr_verificari_secventa = 0;
      i++;
      while (words[i] != '"') {
        if (words[i] != ' ' && words[i] != '\n'&&words[i]!='"') {
          lung++;
          cuv[lung] = words[i];
        } else
        if (lung != -1) {printf("\n%s\n",cuv);
          nr_verificari_secventa++;
          char * de_verificat = calloc(100, sizeof(char));
          strcpy(de_verificat, cuv);
          for (int i = 1; i <= nr_site; i++) {
            char * inceput = malloc(100);
            char * sfarsit = malloc(100);
            char * continut = malloc(strlen(site[i].continut) + 10);
            continut[0] = ' ';
            strcpy(continut + 1, site[i].continut);
            continut[strlen(continut)] = ' ';
            inceput = strstr(continut, de_verificat);
            sfarsit = inceput + strlen(de_verificat) - 1;
            if (strstr(site[i].continut, de_verificat) != NULL && site_pus[i] == 0)
              if (((inceput - 1)[0] == ' ') && (((sfarsit)[1] == ' ')) || (sfarsit)[1] == '\n') {
                verificat_secventa[i]++;
                //site_pus[i]=1; de pus mai jos asta!!!!
                //nr_site_problema++;
                //site_problema[nr_site_problema] = i;
              }
          }
          lung = -1;
          cuv = calloc(100, sizeof(char));
        }
        i++;
      }
      for (int i = 1; i < nr_site_problema; i++)
        if (verificat_secventa[i] == nr_verificari_secventa) {
          site_pus[i] = 1;
          nr_site_problema++;
          site_problema[nr_site_problema] = i;
        }
        printf("\n%d\n",nr_verificari_secventa);
    }
    else{
    if (words[i] != ' ' && words[i] != '\n') {
      lung++;
      cuv[lung] = words[i];
    } else
    if (lung != -1&&cuv[0]!='-') {
      char * de_verificat = calloc(100, sizeof(char));
      strcpy(de_verificat, cuv);
      for (int i = 1; i <= nr_site; i++) {
        char * inceput = malloc(100);
        char * sfarsit = malloc(100);
        char * continut = malloc(strlen(site[i].continut) + 10);
        continut[0] = ' ';
        strcpy(continut + 1, site[i].continut);
        continut[strlen(continut)] = ' ';
        inceput = strstr(continut, de_verificat);
        sfarsit = inceput + strlen(de_verificat) - 1;
        if (strstr(site[i].continut, de_verificat) != NULL && site_pus[i] == 0)
          if (((inceput - 1)[0] == ' ') && (((sfarsit)[1] == ' ')) || (sfarsit)[1] == '\n') {
            site_pus[i] = 1;
            nr_site_problema++;
            site_problema[nr_site_problema] = i;
          }
      }
      lung = -1;
      cuv = calloc(100, sizeof(char));
    }
    else
    {
        nr_cuv_rele++;
        cuv_rele[nr_cuv_rele] = malloc(100*sizeof(char));
        strcpy(cuv_rele[nr_cuv_rele],cuv);
    }
    }
  }
  for (int i = 1; i <= nr_site_problema; i++)
    printf("%s\n", site[site_problema[i]].url);
}
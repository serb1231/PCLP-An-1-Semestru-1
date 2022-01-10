#include<stdio.h>

#include<stdlib.h>

#include<math.h>

#include<string.h>

#include "structura.h"

int detectare_culoare(char * s) {
  char * curent_character = s;
  while (strstr(curent_character, "<") != NULL) {
    char * inceput = strstr(curent_character, "<");
    char * sfarsit = strstr(curent_character, ">");
    curent_character = sfarsit + 1;
    char * substring = malloc(200);
    strncpy(substring, inceput, sfarsit - inceput);
    if (strstr(substring, "color") != NULL) { // aici de schombat if cu while intrucat va detecta daor o data color si ne trb de mai multe ori
      char * color_gasit = strstr(substring, "color");
      if ((color_gasit - 1)[0] != '-') {
        char * sf_color = strstr(color_gasit, ";");
        char * true_color = malloc(100); 
        strncpy(true_color, color_gasit + 6, sf_color - color_gasit - 6);
        //printf("%s", true_color);
        if(strcmp(true_color,"white")==0)
        return white;
        if(strcmp(true_color,"black")==0)
        return black;
        if(strcmp(true_color,"red")==0)
        return red;
        if(strcmp(true_color,"green")==0)
        return green;
        if(strcmp(true_color,"blue")==0)
        return blue;
        if(strcmp(true_color,"yellow")==0)
        return yellow;
      }
    }
  }
  return black;
}
int detectare_bkg(char * s) {
  char * curent_character = s;
  while (strstr(curent_character, "<") != NULL) {
    char * inceput = strstr(curent_character, "<");
    char * sfarsit = strstr(curent_character, ">");
    curent_character = sfarsit + 1;
    char * substring = malloc(200);
    strncpy(substring, inceput, sfarsit - inceput);
    while(strstr(substring, "color") != NULL) {
      char * color_gasit = strstr(substring, "color");
      substring = color_gasit +1;
      if ((color_gasit - 1)[0] == '-') {
        char * sf_color = strstr(color_gasit, ";");
        char * true_color = malloc(100); 
        strncpy(true_color, color_gasit + 6, sf_color - color_gasit - 6);
        //printf("%s", true_color);
        if(strcmp(true_color,"white")==0)
        return white;
        if(strcmp(true_color,"black")==0)
        return black;
        if(strcmp(true_color,"red")==0)
        return red;
        if(strcmp(true_color,"green")==0)
        return green;
        if(strcmp(true_color,"blue")==0)
        return blue;
        if(strcmp(true_color,"yellow")==0)
        return yellow;
      }
    }
  }
  return white;
}
int main() {
  FILE * master = fopen("master.txt", "rt");
  char * fisier_nume = malloc(100 * sizeof(char));
  int nr_site = 0;
  site_continut * site = malloc(3);
  FILE * (fisier)[100];
  char * f_to_open[100];
  while (fgets(fisier_nume, 100, master)) {
    nr_site++;
    f_to_open[nr_site] = malloc(strlen(fisier_nume) - 1);
    strncpy(f_to_open[nr_site], fisier_nume, strlen(fisier_nume) - 1);
    fisier[nr_site] = fopen(f_to_open[nr_site], "rt");

  }
  int dim_nr_site = 3;
  for (int i = 1; i <= nr_site; i++) {
    if (i > dim_nr_site) {
      site = realloc(site, dim_nr_site + 3);
      dim_nr_site += 3;
    }
    long int dimensiune_HTML;
    fscanf(fisier[i], "%s%ld%ld%ld", site[i].url, & dimensiune_HTML, & site[i].nr_accesari, & site[i].checksum);

    fgets(site[i].titlu, 200, fisier[i]);
    fgets(site[i].titlu, 200, fisier[i]);
    fgets(site[i].titlu, 200, fisier[i]);

    char * aux = malloc(200);
    strcpy(aux,site[i].titlu+7);
    strcpy(site[i].titlu, aux);
    char *aux2 = malloc(200);
    strncpy(aux2, aux, strlen(aux) - 9);
    strcpy(site[i].titlu, aux2);

    char * cod_aux_site = malloc(400);
    char * cod_total = malloc(200);
    while (fgets(cod_aux_site, 200, fisier[i])) {
      strcat(cod_total, cod_aux_site);
      cod_total = realloc(cod_total, strlen(cod_total) + 200);
    }
    //printf("%d ",detectare_culoare(cod_total));
    //printf("%d ",detectare_bkg(cod_total));
    site[i].text = detectare_culoare(cod_total);
    site[i].bkg = detectare_bkg(cod_total);

    for (int j = 0; j < strlen(cod_total); j++) {
      int uu = strlen(cod_total);
      int sarit_peste = 1;
      if (cod_total[j] == '<') {
        while (cod_total[j] != '>') {
          sarit_peste++;
          j++;
        }
        char * aux2 = malloc(200);
        strcpy(aux, cod_total + j + 1);
        strcpy(cod_total + j - sarit_peste + 1, aux);
        j = j - sarit_peste + 1;
      }

    }
    site[i].continut = malloc(strlen(cod_total));
    strcpy(site[i].continut,cod_total);
    //printf("%s %ld %s %d %d \n",site[i].url,site[i].nr_accesari,site[i].titlu,site[i].text,site[i].bkg);
    //printf("%s\n",site[i].continut);
    printf("%s %ld %s\n",site[i].url,site[i].nr_accesari,site[i].titlu);
  }

}
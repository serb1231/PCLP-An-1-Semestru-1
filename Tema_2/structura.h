#ifndef FOO_H_
#define FOO_H_

typedef struct aa {
    char url[200];
    long int nr_accesari;
    long int checksum;
    char titlu[200];
    char *continut;
    int text;
    int bkg;
}site_continut;
enum culori{white, black, red, green, blue, yellow};


int depunere_in_memorie(site_continut *site,int nr_site);

void sortare_site2(site_continut *site,int nr_site_problema,int * site_problema);

#endif
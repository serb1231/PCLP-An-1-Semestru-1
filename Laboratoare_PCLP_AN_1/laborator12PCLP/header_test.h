#ifndef SET_H
    #define SET_H
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    void creare(char * numef);
    void listare (char* numef);
    typedef struct {
    char nume[25];
    float medie;
    } Elev;
#endif

void creare(char * numef) {
FILE * f; Elev s;
f = fopen (numef, "wb");
if (f == NULL) return;
printf ("Nume şi medie ptr. fiecare student :\n");
while ( scanf ("%s%f", s.nume, &s.medie) != EOF)
fwrite (&s, sizeof(s), 1, f); // fwrite (&s, sizeof(Elev), 1, f);
fclose (f);
}

void listare (char* numef) {
FILE * f; Elev e;
f = fopen (numef, "rb"); if (f == NULL) return;
printf ("Nume şi medie: \n");
while ( fread (&e, sizeof(e), 1, f ) == 1 )
printf ("%-25s %6.2f \n", e.nume, e.medie);
fclose (f);
}
// adaugare articole la sfârşitul unui fişier existent
void adaugare (char * numef) {
FILE * f; Elev e;
f = fopen (numef, "ab"); if (f == NULL) return;
printf ("Adaugare nume şi medie:\n");
while (scanf ("%s%f", e.nume, &e.medie) != EOF)
fwrite (&e, sizeof(e), 1, f);
fclose (f);
}
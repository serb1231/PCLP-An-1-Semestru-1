#include<stdio.h>

#include<string.h>

#include<stdlib.h>
//aceasta functie determina daca 2 numere
//sunt anagrame,prin folosirea unui vector de frecventa pentru caracterele
//din cele 2 cuvinte (luam fiecare pereche la rand)
int is_anagram(char * s1, char * s2) {
  if (strlen(s1) != strlen(s2))
    return 0;
  int apar1[257];
  int apar2[257];
  for (int i = 0; i <= 255; i++) {
    apar1[i] = 0;
    apar2[i] = 0;
  }
  for (int i = 0; i < strlen(s1); i++) {
    int primul = s1[i];
    int doilea = s2[i];
    apar1[primul]++;
    apar2[doilea]++;
  }
  for (int i = 65; i <= 122; i++)
    if (apar1[i] != apar2[i])
      return 0;
  return 1;
}
//in aceasta functie vom compara caracterele de pe aceeasi poztiie
//in 2 string-uri diferite, iar de fiecare data cand detectam un caracter diferit 
//crestem un contor
double compute_grade(char * s1, char * s2) {
  int suma = 0;
  for (int i = 0; i < strlen(s1); i++) {
    if (s1[i] != s2[i])
      suma++;
  }
  double nr_cifre = strlen(s1);
  double returneaza = suma / nr_cifre;
  return returneaza;
}
int main() {
    //mai jos vom face calcularea gradului unei perechi
  int n; 
  char m1[1000][50], m2[1000][50];
  double v[1000];
  scanf("%d", & n);
  for (int i = 0; i < n; i++) {
    char s1[50], s2[50];
    scanf("%s", s1);
    strcpy(m1[i], s1);
    scanf("%s", s2);
    strcpy(m2[i], s2);
    v[i] = is_anagram(s1, s2);
    if (v[i] == 0) v[i] = -1;
    else
      v[i] = compute_grade(s1, s2);
  }
//aici vom sorta perechile de numere
//in momentul in care vedem ca o pereche are grad
//mai mare inversam colul gradelor, primului numar si locul celui de-al doilea
//numar cu locurile celei de-a 2 2perechi
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (v[j] > v[i]) {
        double aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        char aa[50];
        strcpy(aa, m1[j]);
        strcpy(m1[j], m1[i]);
        strcpy(m1[i], aa);
        strcpy(aa, m2[j]);
        strcpy(m2[j], m2[i]);
        strcpy(m2[i], aa);
      } else
      if (v[j] == v[i]) {
        if (strcmp(m1[j], m1[i]) > 0) {
          char aa[50];
          strcpy(aa, m1[j]);
          strcpy(m1[j], m1[i]);
          strcpy(m1[i], aa);
          strcpy(aa, m2[j]);
          strcpy(m2[j], m2[i]);
          strcpy(m2[i], aa);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    char s[50];
    strcpy(s, m1[i]);
    printf("%s ", s);
    strcpy(s, m2[i]);
    printf("%s\n", s);
  }

}
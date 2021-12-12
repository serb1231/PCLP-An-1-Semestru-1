#include<stdio.h>

#include<string.h>

#include<math.h>
//in aceasta functie vom transforma un numar din decimal
//in binar
void dec_to_bin(int n, char * s) {
  for (int i = 0; i <= 7; i++)
    s[i] = '0';
  int i = -1;
  while (n != 0) {
    i++;
    s[i] = (n % 2) + '0';
    n = n / 2;
  }
}
//in aceasta functie vom transforma un numar din binar
//in decimal
int bin_to_dec(char * s) {
  int n = 0;
  int count = 1;
  for (int i = 0; i < 8; i++) {
    int uu = s[i];
    n += count * uu;
    count *= 2;
  }
  return n;
}
//in aceasta functie vom inmulti 2 matrici
void inmultire(int a[8][8], int b[8][8], int( * c)[8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        c[i][j] = c[i][j] + a[i][k] * b[k][j];
      }
      if (c[i][j] >= 1) c[i][j] = 1;
    }
  }
}
//in aceasta functie vom calcula transpusa unei matrici
void transpusa(int a[][8], int b[][8]) {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      b[j][i] = a[i][j];
}
//in verificare vom calcula scorul unei patrimi dintr-o matrice
int verificare(int incl, int sfcl, int inln, int sfln, int a[8][8]) {
  int nr = 0;
  for (int i = incl; i < sfcl; i++) {
    int ver = 0;
    for (int j = inln; j < sfln; j++)
      if (a[i][j] == 0) ver = 1;
    if (ver == 0)
      nr++;
  }
  for (int i = inln; i < sfln; i++) {
    int ver = 0;
    for (int j = incl; j < sfcl; j++)
      if (a[j][i] == 0) ver = 1;
    if (ver == 0)
      nr++;
  }
  int ver = 0;
  for (int i = 0; i < 4; i++)
    if (a[inln + i][incl + i] == 0) ver = 1;
  if (ver == 0)
    nr++;
  ver = 0;
  for (int i = 0; i < 4; i++)
    if (a[inln + i][sfcl - i - 1] == 0) ver = 1;
  if (ver == 0)
    nr++;
  return nr;
}
//in aceasta functie vom calcula scorul unei matrici
int sum_X_0(int m[][8])

{
  int sum = 0;
  sum += verificare(0, 4, 0, 4, m) + verificare(4, 8, 4, 8, m) + verificare(0, 4, 4, 8, m) + verificare(4, 8, 0, 4, m);
  return sum;
}
int main() {
  int c[8][8];
  int pat[8][8], tran[8][8], aatran[8][8];
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      pat[i][j] = 0;
      aatran[i][j] = 0;
    }
  char s[8];
  for (int i = 0; i < 8; i++)
    s[i] = '0';
  for (int i = 0; i < 8; i++) {
    int x = 0;
    scanf("%d", & x);
    dec_to_bin(x, s);
    for (int k = 0; k < 4; k++) {
      char aux = s[7 - k];
      s[7 - k] = s[k];
      s[k] = aux;
    }
    for (int j = 0; j < 8; j++)
      c[i][j] = s[j] - '0';
  }
  inmultire(c, c, pat);
  transpusa(c, tran);
  inmultire(c, tran, aatran);
  int p1 = sum_X_0(pat);
  int p2 = sum_X_0(aatran);
  int p3 = sum_X_0(c);
  if (p3 >= p2 && p3 >= p1) {
    char hh[8];
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++)
        hh[7 - j] = c[i][j];

      printf("%d\n", bin_to_dec(hh));
    }
  } else
  if (p2 >= p1 && p2 > p3) {
    for (int i = 0; i < 8; i++) {
      char hh[8];
      for (int j = 0; j < 8; j++)
        hh[7 - j] = aatran[i][j];
      printf("%d\n", bin_to_dec(hh));
    }
  } else {
    for (int i = 0; i < 8; i++) {
      char hh[8];
      for (int j = 0; j < 8; j++)
        hh[7 - j] = pat[i][j];
      printf("%d\n", bin_to_dec(hh));

    }
  }
}

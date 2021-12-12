#include<stdio.h>
//in functia de mai jos vom determina daca
//2 nebuni se ataca unul pe celalalt, calculand
//diagonala principala si secundara pe care sa afla
int atac(int x1, int y1, int x2, int y2) {
  if (y2 - y1 == x2 - x1 || y2 - y1 == x1 - x2)
    return 1;
  else
    return 0;
}

int main() {
  int m, n, v1[10000], v2[10000];
  scanf("%d%d", & m, & n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", & v1[i], & v2[i]);
  int cont = -1, fin1[10000], fin2[10000];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int deci = atac(v1[i], v2[i], v1[j], v2[j]);
      if (deci == 1) {//in deci vedem daca sunt mai multe perechi de nebuni care se ataca
        cont++;
        fin1[cont] = i;
        fin2[cont] = j;
      }
    }
  if (cont > 0) {
    printf("%d\nNU\n", cont + 1);
    return 0;
  } else {//aici vom muta pozitiile nebuniilor care se ataca si vom verifica
    int x1 = v1[fin1[cont]];
    int y1 = v2[fin1[cont]];
    int x2 = v1[fin2[cont]];
    int y2 = v2[fin2[cont]];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) {
        int nemers = 0;
        for (int k = 0; k < n; k++) {
          if (v1[k] != x1 || v2[k] != y1) {
            int mers = atac(i, j, v1[k], v2[k]);
            if (mers == 1 && (v1[k] != x1 || v2[k] != y1))
              nemers = 1;
          }
        }
        if (nemers == 0) {
          printf("1\nDA\n");
          return 0;
        }
        nemers = 0;
        for (int k = 0; k < n; k++) {
          if (v1[k] != x2 || v2[k] != y2) {
            int mers = atac(i, j, v1[k], v2[k]);
            if (mers == 1 && (v1[k] != x2 || v2[k] != y2))
              nemers = 1;
          }
        }
        if (nemers == 0) {
          printf("1\nDA\n");
          return 0;
        }
      }
  }
  printf("1\nNU\n");
  return 0;
}
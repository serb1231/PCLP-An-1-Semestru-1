#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct entry {
   void * key;
   void * value;
} entry;
 
typedef struct map {
   entry ** elem; // vectorul de elemente; este alocat si realocat dinamic
   int n_elem; // numarul de elemente din vector
   int cap; // capacitatea vectorului
} map;
void init(map *m, int cap) {
   m->cap = cap;
   m->n_elem = 0;
   m->elem = calloc(cap,sizeof(entry));
}
void eliberare_elem(entry*a) {
    free(a->key);
    free(a->value);
    free(a);
}
void add(map *m, entry *e) {
   if(m->n_elem >= m->cap)
   {
      m->cap*=2;
      m->elem = realloc(m->elem,sizeof(entry)*m->cap);
   }
    m->elem[m->n_elem] = e;
    m->n_elem++;
}
void printEntry( const entry *a) {
   printf("%s\n%s\n\n",(char*)a->key,(char*)a->value);
}
void print(map *m, void ( *printEntry) ( const entry * ) ) {
   
   for(int i=0;i<(*m).n_elem;i++)
   {
      printEntry(m->elem[i]);
   }
}
int compareEntry( const void *a, const void *b) {
   entry * pa = *(entry**)a;
   entry * pb = *(entry**)b;
   if((char*)(pa->key)!=NULL&&(char*)(pb->key)!=NULL)
   return strcmp((char*)(pa->key),(char*)(pb->key));
   return 0;
}
void sort(map *m, int ( * fc ) ( const void *, const void * ) ) {
   qsort(m->elem,m->n_elem,sizeof(entry*),fc);
}
int compareKey( const void *a, const void *b) {
   char *ca = (char*)a;
   char *cb = (char*)b;
   return strcmp(ca,cb);
}
void del(map *m, void *k, int ( * fc2 ) ( const void *, const void * )) {
   for(int i=0;i<m->n_elem;i++)
   if(compareKey((char*)m->elem[i]->key,(char*)k)==0)
   {
      //free(m->elem[i]);
      for(int j=i;j<(m->n_elem) - 1;j++)
      {
         printf("%s\n%s\n",(char*)m->elem[j]->key,(char*)m->elem[j+1]->key);
         m->elem[j] = m->elem[j+1];
      }
      m->elem[m->n_elem]=NULL;
      m->n_elem--;
      break;
   }
}

int main()
{
   map *m,mapare;
   mapare.cap = 100;
   mapare.n_elem = 0;
   m = &mapare;
   init(m,100);


   entry valoare_entry;
   valoare_entry.value = calloc(100,sizeof(int));
   *(int*)valoare_entry.value = 100;
   valoare_entry.key = calloc(100,sizeof(char));
   strcpy((char*)valoare_entry.key,"wedsaerfd");

   entry valoare_entry1;
   valoare_entry1.value = calloc(100,sizeof(int));
   *(int*)valoare_entry1.value = 100;
   valoare_entry1.key = calloc(100,sizeof(char));
   strcpy((char*)valoare_entry1.key,"pppppppppppppp");

   entry valoare_entry2;
   valoare_entry2.value = calloc(100,sizeof(int));
   *(int*)valoare_entry2.value = 100;
   valoare_entry2.key = calloc(100,sizeof(char));
   strcpy((char*)valoare_entry2.key,"ppppewqewqewqeppppp");

   add(m,&valoare_entry);
   add(m,&valoare_entry1);

   //sort(m,*compareEntry);
   char*s = calloc(100,1);strcpy(s,"pppppppppppppp");
   del(m,s,compareKey);
   //print(m,*printEntry);

   free(valoare_entry.key);
   free(valoare_entry.value);
   free(valoare_entry1.key);
   free(valoare_entry1.value);
   free(valoare_entry2.key);
   free(valoare_entry2.value);
   free(m->elem);
   free(s);
   return 0;
}

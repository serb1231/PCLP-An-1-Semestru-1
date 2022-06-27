#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUFMAX 1005
 
int main(int argc, char *argv[])
{
    FILE* fisier1;
    fisier1 = fopen(argv[1],"r");
    if(fisier1==NULL){printf("terminated unexpectably");return 0;}
    char* string;
    string = argv[2];
    char* linie = calloc(100,sizeof(char));
    while(fgets(linie,100,fisier1))
    {
        if(strstr(linie,string)!=NULL)
        printf("%s",linie);
    }
    free(linie);
    fclose(fisier1);
	return 0;
}


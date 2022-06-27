#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
    FILE*codificare,*de_codificat,*de_scris;
    codificare = fopen(argv[1],"r");
    de_codificat = fopen(argv[2],"r");
    de_scris = fopen(argv[3],"w");
    if(codificare==NULL||de_scris==NULL||de_codificat==NULL)
    {
        printf("files not found\n");
        return 0;
    }
    int *codif = calloc(200,sizeof(int));
    char*linie_codif = calloc(10,1);
    while (fgets(linie_codif,10,codificare))
    {
        codif[linie_codif[0]] = linie_codif[2];
        codif[linie_codif[0]-32] = linie_codif[2]-32;
    }
    char*linie_citit = calloc(200,1);
    char*linie_de_scris = calloc(200,1);
    while (fgets(linie_citit,200,de_codificat))
    {
        for (int i = 0; i <strlen(linie_citit) ; i++)
        {
            if(codif[linie_citit[i]]>3)
            linie_de_scris[i] = codif[linie_citit[i]];
            else
            linie_de_scris[i] = linie_citit[i];
        }
        fprintf(de_scris,"%s",linie_de_scris);
        memset(linie_de_scris,0,200);
    }
    free(linie_de_scris);
    free(linie_citit);
    free(codif);
    free(linie_codif);
    fclose(codificare);
    fclose(de_codificat);
    fclose(de_scris);
    
    
}
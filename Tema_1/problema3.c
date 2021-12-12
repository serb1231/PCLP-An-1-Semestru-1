#include<stdio.h>
#include<string.h>
void rotire_fata(int fa[][3])
{
 int fa_prim[3][3];
 fa_prim[0][0]=fa[2][0];fa_prim[0][1]=fa[1][0];fa_prim[0][2]=fa[0][0]; 
 fa_prim[1][0]=fa[2][1];fa_prim[1][1]=fa[1][1];fa_prim[1][2]=fa[0][1];
 fa_prim[2][0]=fa[2][2];fa_prim[2][1]=fa[1][2];fa_prim[2][2]=fa[0][2];
 for(int i=0;i<3;i++)
 for(int j=0;j<3;j++)
 fa[i][j]=fa_prim[i][j];
}
void copiere(int m_ini[][3],int m_fin[][3])
{
 for(int i=0;i<3;i++)
 for(int j=0;j<3;j++)
 m_fin[i][j]=m_ini[i][j];
}
void Fata(int fa[][3],int sp[][3],int st[][3],int dr[][3],int sus[][3],int jos[][3])
{
 int sus_prim[3][3],dr_prim[3][3],st_prim[3][3],jos_prim[3][3],sp_prim[3][3];

 copiere(sus,sus_prim);copiere(jos,jos_prim);
 copiere(st,st_prim);copiere(dr,dr_prim);
 copiere(sp,sp_prim);

 rotire_fata(fa);

 sus_prim[2][0]=st[2][2];sus_prim[2][1]=st[1][2];sus_prim[2][2]=st[0][2];
 st_prim[0][2]=jos[0][0];st_prim[1][2]=jos[0][1];st_prim[2][2]=jos[0][2];
 jos_prim[0][0]=dr[2][0];jos_prim[0][1]=dr[1][0];jos_prim[0][2]=dr[0][0];
 dr_prim[0][0]=sus[2][0];dr_prim[1][0]=sus[2][1];dr_prim[2][0]=sus[2][2];

 copiere(sus_prim,sus);copiere(jos_prim,jos);
 copiere(st_prim,st);copiere(dr_prim,dr);
 copiere(sp_prim,sp);
}
void dreapta(int fa[][3],int sp[][3],int st[][3],int dr[][3],int sus[][3],int jos[][3])
{
 int sus_prim[3][3],dr_prim[3][3],st_prim[3][3],jos_prim[3][3],sp_prim[3][3],fa_prim[3][3];
 copiere(sus,sus_prim);copiere(jos,jos_prim);
 copiere(st,st_prim);copiere(dr,dr_prim);
 copiere(sp,sp_prim);copiere(fa,fa_prim);
    sus_prim[0][2]=fa[0][2];sus_prim[1][2]=fa[1][2];sus_prim[2][2]=fa[2][2];
    fa_prim[0][2]=jos[0][2];fa_prim[1][2]=jos[1][2];fa_prim[2][2]=jos[2][2];
    jos_prim[0][2]=sp[0][0];jos_prim[1][2]=sp[1][0];jos_prim[2][2]=sp[2][0];
    sp_prim[0][0]=sus[2][2];sp_prim[1][0]=sus[1][2];sp_prim[2][0]=sus[0][2];
    rotire_fata(dr_prim);

    copiere(sus_prim,sus);copiere(jos_prim,jos);
    copiere(st_prim,st);copiere(dr_prim,dr);
    copiere(sp_prim,sp);copiere(fa_prim,fa);
}
void spate(int fa[][3],int sp[][3],int st[][3],int dr[][3],int sus[][3],int jos[][3])
{
 int sus_prim[3][3],dr_prim[3][3],st_prim[3][3],jos_prim[3][3],sp_prim[3][3],fa_prim[3][3];
 copiere(sus,sus_prim);copiere(jos,jos_prim);
 copiere(st,st_prim);copiere(dr,dr_prim);
 copiere(sp,sp_prim);copiere(fa,fa_prim);
 sus_prim[0][0]=dr[0][2];sus_prim[0][1]=dr[1][2];sus_prim[0][2]=dr[2][2];
 dr_prim[0][2]=jos[2][2];dr_prim[1][2]=jos[2][1];dr_prim[2][2]=jos[2][0];
 jos_prim[2][0]=st[0][0];jos_prim[2][1]=st[1][0];jos_prim[2][2]=st[2][0];
 st_prim[0][0]=sus[0][2];st_prim[1][0]=sus[0][1];st_prim[2][0]=sus[0][0];
 rotire_fata(sp_prim);
 copiere(sus_prim,sus);copiere(jos_prim,jos);
    copiere(st_prim,st);copiere(dr_prim,dr);
    copiere(sp_prim,sp);copiere(fa_prim,fa);
}
void stanga(int fa[][3],int sp[][3],int st[][3],int dr[][3],int sus[][3],int jos[][3])
{
 int sus_prim[3][3],dr_prim[3][3],st_prim[3][3],jos_prim[3][3],sp_prim[3][3],fa_prim[3][3];
  copiere(sus,sus_prim);copiere(jos,jos_prim);
 copiere(st,st_prim);copiere(dr,dr_prim);
 copiere(sp,sp_prim);copiere(fa,fa_prim);
 fa_prim[0][0]=sus[0][0];fa_prim[1][0]=sus[1][0];fa_prim[2][0]=sus[2][0];
 sus_prim[0][0]=sp[0][2];sus_prim[1][0]=sp[1][2];sus_prim[2][0]=sp[2][2];
 sp_prim[0][2]=jos[2][0];sp_prim[1][2]=jos[1][0];sp_prim[2][2]=jos[0][0];
 jos_prim[0][0]=fa[0][0];jos_prim[1][0]=fa[1][0];jos_prim[2][0]=fa[2][0];
 rotire_fata(st);
    copiere(sus_prim,sus);copiere(jos_prim,jos);
    copiere(st_prim,st);copiere(dr_prim,dr);
    copiere(sp_prim,sp);copiere(fa_prim,fa);
}
void susu(int fa[][3],int sp[][3],int st[][3],int dr[][3],int sus[][3],int jos[][3])
{
 int sus_prim[3][3],dr_prim[3][3],st_prim[3][3],jos_prim[3][3],sp_prim[3][3],fa_prim[3][3];
 copiere(sus,sus_prim);copiere(jos,jos_prim);
 copiere(st,st_prim);copiere(dr,dr_prim);
 copiere(sp,sp_prim);copiere(fa,fa_prim);

 rotire_fata(sus_prim);
 fa_prim[0][0]=st[0][0];fa_prim[0][1]=st[0][1];fa_prim[0][2]=st[0][2];
 st_prim[0][0]=sp[0][0];st_prim[0][1]=sp[0][1];st_prim[0][2]=sp[0][2];
 sp_prim[0][0]=dr[0][0];sp_prim[0][1]=dr[0][1];sp_prim[0][2]=dr[0][2];
 dr_prim[0][0]=fa[0][0];dr_prim[0][1]=fa[0][1];dr_prim[0][2]=fa[0][2];
 //copiat codul de mai jos in alta fct 
 copiere(sus_prim,sus);copiere(jos_prim,jos);
 copiere(sp_prim,sp);copiere(fa_prim,fa);
 copiere(st_prim,st);copiere(dr_prim,dr);
}
void josu(int fa[][3],int sp[][3],int st[][3],int dr[][3],int sus[][3],int jos[][3])
{
 int sus_prim[3][3],dr_prim[3][3],st_prim[3][3],jos_prim[3][3],sp_prim[3][3],fa_prim[3][3];
 copiere(sus,sus_prim);copiere(jos,jos_prim);
 copiere(st,st_prim);copiere(dr,dr_prim);
 copiere(sp,sp_prim);copiere(fa,fa_prim);

 rotire_fata(jos_prim);
 fa_prim[2][0]=st[2][0];fa_prim[2][1]=st[2][1];fa_prim[2][2]=st[2][2];
 st_prim[2][0]=sp[2][0];st_prim[2][1]=sp[2][1];st_prim[2][2]=sp[2][2];
 sp_prim[2][0]=dr[2][0];sp_prim[2][1]=dr[2][1];sp_prim[2][2]=dr[2][2];
 dr_prim[2][0]=fa[2][0];dr_prim[2][1]=fa[2][1];dr_prim[2][2]=fa[2][2];
 //copiat codul de mai jos in alta fct 
 copiere(sus_prim,sus);copiere(jos_prim,jos);
 copiere(sp_prim,sp);copiere(fa_prim,fa);
 copiere(st_prim,st);copiere(dr_prim,dr);
}
int culoare(char *tok ,char culori[][11])
{
 //for(int i=0;i<6;i++)
 //printf("%s\n",culori[i]);
 //printf("\n%s\n",tok);
 for(int i=0;i<6;i++)
 if(strcmp(tok,culori[i])==0)
 {
 return i;
 }
}
void afisare(char culori[][11],int fa[][3],int sp[][3],int sus[][3],int jos[][3],int st[][3],int dr[][3])
{
 for(int i=0;i<3;i++)
 {
 for(int j=0;j<3;j++)
 {if(j!=2)printf("%s.",culori[fa[i][j]]);else printf("%s",culori[fa[i][j]]);}
 printf("\n");
 }
 for(int i=0;i<3;i++)
 {
 for(int j=0;j<3;j++)
 {if(j!=2)printf("%s.",culori[sp[i][j]]);else printf("%s",culori[sp[i][j]]);}
 printf("\n");
 }
 for(int i=0;i<3;i++)
 {
 for(int j=0;j<3;j++)
 {if(j!=2)printf("%s.",culori[sus[i][j]]);else printf("%s",culori[sus[i][j]]);}
 printf("\n");
 }
 for(int i=0;i<3;i++)
 {
 for(int j=0;j<3;j++)
 {if(j!=2)printf("%s.",culori[jos[i][j]]);else printf("%s",culori[jos[i][j]]);}
 printf("\n");
 }
 for(int i=0;i<3;i++)
 {
 for(int j=0;j<3;j++)
 {if(j!=2)printf("%s.",culori[st[i][j]]);else printf("%s",culori[st[i][j]]);}
 printf("\n");
 }
 for(int i=0;i<3;i++)
 {
 for(int j=0;j<3;j++)
 {if(j!=2)printf("%s.",culori[dr[i][j]]);else printf("%s",culori[dr[i][j]]);}
 printf("\n");
 }
}
int main()
{
 char culori[6][11],s[33];
 int fa[3][3],sp[3][3],st[3][3],dr[3][3],sus[3][3],jos[3][3];
 for(int i=0;i<6;i++)
 scanf("%s",culori[i]);
 for(int i=0;i<3;i++)
 {
 scanf("%s",s);
 for(int j=0;j<3;j++)
 {
 char *tok = strtok(s,".");
 fa[i][j]=culoare(tok,culori);
 }
 }
 for(int i=0;i<3;i++)
 {
 scanf("%s",s);
 for(int j=0;j<3;j++)
 {
 char *tok = strtok(s,".");
 //printf("\n de afisat tok si s in acest momemtn %s %s\n",tok,s);
 sp[i][j]=culoare(tok,culori);
 }
 }
 for(int i=0;i<3;i++)
 {
 scanf("%s",s);
 for(int j=0;j<3;j++)
 {
 char *tok = strtok(s,".");
 sus[i][j]=culoare(tok,culori);
 }
 }
 for(int i=0;i<3;i++)
 {
 scanf("%s",s);
 for(int j=0;j<3;j++)
 {
 char *tok = strtok(s,".");
 jos[i][j]=culoare(tok,culori);
 }
 }
 for(int i=0;i<3;i++)
 {
 scanf("%s",s);
 for(int j=0;j<3;j++)
 {
 char *tok = strtok(s,".");
 st[i][j]=culoare(tok,culori);
 }
 }
 for(int i=0;i<3;i++)
 {
 scanf("%s",s);
 for(int j=0;j<3;j++)
 {
 char *tok = strtok(s,".");
 dr[i][j]=culoare(tok,culori);
 }
 }
 /*
 for(int i=0;i<3;i++)
 {
 for(int j=0;j<3;j++)
 {
 printf("%d ",sp[i][j]);
 }
 printf("\n");
 */
 //for(int i=0;i<6;i++)
 //printf("%s\n",culori[i]);
 int miscari;
 char mutare[2];
 //afisare(culori,fa,sp,sus,jos,st,dr);
 scanf("%d",&miscari);
 for(int i=0;i<miscari;i++)
 {
 scanf("%s",mutare);
 if(strcmp(mutare,"U'")==0)
 susu(fa, sp, st, dr, sus, jos);
 if(strcmp(mutare,"U")==0)
 for(int i=0;i<3;i++)
 susu(fa, sp, st, dr, sus, jos);

 if(strcmp(mutare,"D")==0)
 josu(fa, sp, st, dr, sus, jos);
 if(strcmp(mutare,"D'")==0)
 for(int i=0;i<3;i++)
 josu(fa, sp, st, dr, sus, jos);

 if(strcmp(mutare,"R")==0)
 dreapta(fa, sp, st, dr, sus, jos);
 if(strcmp(mutare,"R'")==0)
 for(int i=0;i<3;i++)
 dreapta(fa, sp, st, dr, sus, jos);

 if(strcmp(mutare,"L")==0)
 stanga(fa, sp, st, dr, sus, jos);
 if(strcmp(mutare,"L'")==0)
 for(int i=0;i<3;i++)
 stanga(fa, sp, st, dr, sus, jos);
 
 if(strcmp(mutare,"F")==0)
 {Fata(fa, sp, st, dr, sus, jos);}
 if(strcmp(mutare,"F'")==0)
 for(int i=0;i<3;i++)
 Fata(fa, sp, st, dr, sus, jos);

 if(strcmp(mutare,"B")==0)
 spate(fa, sp, st, dr, sus, jos);
 if(strcmp(mutare,"B'")==0)
 for(int i=0;i<3;i++)
 spate(fa, sp, st, dr, sus, jos);
 }
 afisare(culori,fa,sp,sus,jos,st,dr);
 
}
/*
ros gal albs vd port alb
port.port.port
vd.vd.vd
vd.vd.vd
ros.ros.ros
albs.albs.albs
albs.albs.albs
alb.alb.alb
alb.alb.alb
alb.alb.alb
gal.gal.gal
gal.gal.gal
gal.gal.gal
albs.albs.albs
port.port.port
port.port.port
vd.vd.vd
ros.ros.ros
ros.ros.ros
1
R'


ros gal albs vd port alb
vd.vd.vd
vd.vd.vd
vd.vd.vd
albs.albs.albs
albs.albs.albs
albs.albs.albs
alb.alb.alb
alb.alb.alb
alb.alb.alb
gal.gal.gal
gal.gal.gal
gal.gal.gal
port.port.port
port.port.port
port.port.port
ros.ros.ros
ros.ros.ros
ros.ros.ros
3
F U L’


*/
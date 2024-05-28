#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"







//Reset
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>




//Defintion de processus1 de round Robin
typedef struct processus1 processus1;
struct processus1
{

    int pid ;
    int tempsArriver;
    int tempsExecution;
    int tempsFin;
    int debTempsExec;
    int saveTempsArriver;
    int saveTempsExecution;
    char *etatProcessus;
    processus1 *suivant;
};

//Definition de processus de Fifo
struct process{
int etat;
int pid;
int temps;
int duree;
int temps_execu;
int wait;
int terminer;
struct process *nxt;
};
int nb=0;

// fonction saisie//

//saisie de le premier processus//

void add(struct process** tete){
struct process* temp;
int i=1;
if (*tete==NULL){
*tete=malloc(sizeof(struct process));
temp=*tete;
}
else{
temp=*tete;
i++;
while(temp->nxt != NULL){
i++;
temp=temp->nxt;

}
temp->nxt=malloc(sizeof(struct process));
temp=temp->nxt;
}
temp->etat=0;
temp->pid=i;
temp->nxt=NULL;
temp->temps_execu=0;
temp->wait=0;
temp->terminer=0;
nb=nb+1;
int temps,duree;
printf(BBLU"\4Donner le temps d arrivees de processus nbr%i : "reset,i );
scanf("%i",&temps);
printf(BBLU"\4donner la duree de processus nbr%i : "reset,i);
scanf("%i",&duree);
temp->temps=temps;
temp->duree=duree;
}

//saisie les autres processus//
void add1(struct process** tete,int t,int d,int pid){
struct process *temp,*node=malloc(sizeof(struct process));
node->temps=t;
node->duree=d;
node->nxt=NULL;
node->pid=pid;
node->etat=0;
node->wait=0;
node->terminer=0;
node->temps_execu=0;
temp=*tete;
if (*tete==NULL){
*tete=node;
}
else{
while(temp->nxt!=NULL){
temp=temp->nxt;
}
temp->nxt=node;
}
}

//initialisation//
void* init(){
return NULL;
}

//fonction de finition//
void line(int i){
for (int k=0;k<i;k++){
printf("-------------+");
}
printf("\n");
}


void fifo_pr(){
  printf(BMAG"\t\t\t\t\t""-----------   ---    -----------   ---------""\t""\n"reset);
  printf(BMAG"\t\t\t\t\t""|         |   |  |   |         |   |        |""\t""\n"reset);
  printf(BMAG"\t\t\t\t\t""|   -------   |  |   |   -------   |  ----  |""\t""\n"reset);
  printf(BMAG"\t\t\t\t\t""|   |         |  |   |   |         | |    | |""\t""\n"reset);
printf(BMAG"\t\t\t\t\t""|   -------   |  |   |   -------   | |    | |""\t""\n"reset);
  printf(BMAG"\t\t\t\t\t""|         |   |  |   |         |   | |    | |""\t""\n"reset);
  printf(BMAG"\t\t\t\t\t""|   -------   |  |   |   -------   | |    | |""\t""\n"reset);
  printf(BMAG"\t\t\t\t\t""|   |         |  |   |   |         | |    | |""\t""\n"reset);
  printf(BMAG"\t\t\t\t\t""|   |         |  |   |   |         |  ----  |""\t""\n"reset);
  printf(BMAG"\t\t\t\t\t""|   |         |  |   |   |         |        |""\t""\n"reset);
  printf(BMAG"\t\t\t\t\t"" ---           ---    ----          --------""\t""\n"reset);
}


void RR_sym(){

printf ("                      \t\t____________\t\t____________\n");

printf ("                      \t\t" "|           |" "\t\t" "|           |\n");

printf ("                      \t\t" "|   ______  |" "\t\t" "|   ______  |\n");

printf ("                      \t\t" "|  |      | |" "\t\t" "|  |      | |\n");

printf ("                      \t\t" "|  |      | |" "\t\t" "|  |      | |\n");

printf ("                      \t\t" "|   ______  |" "\t\t" "|   ______  |\n");

printf ("                      \t\t" "| ____  ____|" "\t\t" "| ____  ____|\n");

printf ("                      \t\t" "| |  | |     " "\t\t" "| |  | |     \n");

printf ("                      \t\t" "| |  | |     " "\t\t" "| |  | |     \n");

printf ("                      \t\t" "| |  | |     " "\t\t" "| |  | |     \n");

printf ("                      \t\t" "| |  | |     " "\t\t" "| |  | |     \n");

printf ("                      \t\t" "|_|  |_|     " "\t\t" "|_|  |_|     \n");
}




// Fonction Affichage //
void show1(struct process *tete){
if (tete==NULL){
printf(BRED"     error      "reset);
}
else{
struct process *temp;
temp=tete;
int i=0;
while(temp!=NULL){
i++;
temp=temp->nxt;
};
temp=tete;
i++;
printf(BCYN"+"reset);
line(i);
printf(BCYN"|     PID     "reset);
do{
printf(BCYN"|      p%i     "reset,temp->pid);
temp=temp->nxt;
}while(temp!=NULL);
printf(BCYN"|\n+"reset);
line(i);
temp=tete;
printf(BCYN"|    time     "reset);
do{
printf(BCYN"|    %ims    "reset,temp->temps);
if (temp->temps<100){
printf(" ");
};
if (temp->temps<10){
printf(" ");
}
temp=temp->nxt;
}while(temp!=NULL);

printf(BCYN"|\n+"reset);
line(i);
temp=tete;
printf(BCYN"|    exec.T   "reset);
do {
printf(BCYN"|   %ims     "reset,temp->duree);
if (temp->duree<100){
printf(" ");
}
if(temp->duree<10){
printf(" ");
}
temp=temp->nxt;
}while(temp!=NULL);
printf(BCYN"|\n+"reset);
line(i);
printf(BYEL"press any key to exit...\n "reset);
}
}

// Fonction Menu //
char menu(){
printf("\n");
printf(BCYN"\n\n\t\t\t\t\t\4\4 BIENVENUE DANS PROGRAMME FIFO \4\4\n\n\n\n\n"reset);
  fifo_pr();
  printf("\n");
printf("\n\n\t\t\t\t\t1-AJOUTER UN PROCESSUS \1 \n\n");
printf("\n\n\t\t\t\t\t2-AFFICHER LES PROCESSUS \1\n\n");
printf("\n\n\t\t\t\t\t3-AFFICHER LE DIAGRAMME GE GANTT \1\n\n");
printf("\n\n\t\t\t\t\t4-SORTIR \1\n");
char a;
do {
  scanf("%c",&a);

}while(a!='1'&&a!='2'&&a!='3'&&a!='4');
if (a=='4'){

  system("cls");
}
system("cls");
return a;
}
//---------------------------------------------
int menu2(){
printf(BBLU"\n\n\t\t\t\t\t1-COMBIEN DE PROCESSUS VOULER VOUS AJOUTER \1 :\n\n"reset);
int a;
scanf("%i",&a);
system("cls");
return a;
}


//----------------------------------------------
int menu3(){
  printf(BBLU"\n\n\t\t\t\t\t\4\4QUEL ALGORITHME CHOISISSEZ VOUS\4\4 :\n\n"reset);
  printf("\n\n\t\t\t\t\t1-FIFO \6\n");
  printf("\n\n\t\t\t\t\t2-ROUND ROBIN \6\n\n");
  int choix;
  do{
    printf(BYEL"\n\n\t\t\t\t\t\4 Voici votre choix:"reset);
   scanf("%i",&choix);
    printf(BRED"choix incorrecte ressayer de nouveau ....""\n"reset);
  }while (choix!=1 && choix!=2);
  system("cls");
return choix;
}
//--------------------------------------------
int menu4(){
  printf("\n");
printf(BGRN"\n\n\t\t\t\t\t\4\4 BIENVENUE DANS PROGRAMME ROUND ROBIN \4\4\n\n"reset);
  RR_sym();
  printf("\n");
/*printf("1-ajouter un processus \n");
printf("2-afficher les processus\n");
printf("3-afficher diagramme de Gantt\n");
printf("4-SORTIR \n");
char a;
do {
  scanf("%c",&a);

}while(a!='1'&&a!='2'&&a!='3'&&a!='4');
if (a=='4'){

  system("clear");
}
system("clear");
return a;*/
}



// tri des processus //
struct process* triprocess(struct process *tete){
struct process* temp,*low,*new=NULL,temp1;
int min;
int last_one=-1,test=1;
int last_pid=-1;
if (tete!=NULL){
while (test!=0){
temp=tete;
test=0;
low=NULL;
min=999999;
while(temp!=NULL){
if( (temp->temps < min ) && (temp->temps >= last_one) && (temp->pid != last_pid)){
test=1;
low = temp;
min=temp->temps;
}
temp=temp->nxt;
};
if(low!=NULL){
last_one=low->temps;
last_pid=low->pid;
add1(&new,low->temps,low->duree,low->pid);
}
}
return new;
}
};
void line1(int i){
for (int k=0;k<i;k++){
printf(BMAG"+--------"reset);
}
printf(BMAG"+\n"reset);
}



 //Round Robin//
 void roundrobin(processus1 *l)
{
    int q ,j=l->tempsArriver,tp=l->tempsArriver,debut=l->tempsArriver;
    int M[2][100];
    processus1 *supp;
    float sm=0,am=0;
    do
    {
        printf(BRED"\n\n\t\t \4 Donner votre quantum : "reset);
        scanf("%d",&q);
    }while(q<=0);
    system("cls()");
    int maxi = max(l);
    while(l!= NULL)
    {
        tri(l);
        while(l->tempsArriver > j)
            {
                M[0][j]=0;
                M[1][j]=j;
                j++;
            }
            tp=j;
        if(l->tempsExecution > q)
        {
            /*while(l->tempsArriver > j)
            {
                M[0][j]=0;
                M[1][j]=j;
                j++;
            }
            tp=j;*/
            while(j< tp+q)
            {
                M[0][j]= l->pid;
                M[1][j]=j;
                j++;
            }
            tp=j;
            l->tempsExecution -= q ;
            l->tempsArriver = tp;
        }
        else
        {

            while(j< tp+l->tempsExecution)
            {
                M[0][j]= l->pid;
                M[1][j]=j;
                j++;
            }
            tp=j;
            supp = l;
            sm += tp - l->saveTempsArriver;
            am += tp - l->saveTempsArriver - l->saveTempsExecution;
            l = l->suivant;
            free(supp);
        }
    }
      printf(BBLU"\n\n\t\t\t\t\t\4VOTRE DIAGRAMME DE GANTT\4\n\n\n\n\n"reset);

    for(int k= debut;k<j;k++)
        {
            if(M[0][k]==0)
                printf("   -  ");
            else
                printf(" P[%d] ",M[0][k]);
        }
        printf("\n");
            for(int k= debut;k<j;k++)
            {
                printf(BYEL" T= %d "reset,M[1][k]);
            }
            printf("\n");
            printf(BGRN"\n\n\t\t \4 Le temps de reponse moyenne est = %.3f \n\n"reset,sm/maxi);
            printf(BGRN"\n\n\t\t \4 Le temps d'attente moyenne est = %.3f \n"reset,am/maxi);
            getch();
}

//Tri pour round Robin
void tri(processus1 *liste)
{

int swapped,i;
processus1 *ptr1;
processus1 *lptr=NULL;
if(liste==NULL)
    return;
do
{
    swapped = 0;
    ptr1 = liste;
    while(ptr1->suivant != lptr){
        if(ptr1->tempsArriver > ptr1->suivant->tempsArriver)
        {
            swap(ptr1,ptr1->suivant);
            swapped=1;
        }
        ptr1=ptr1->suivant;
    }
lptr=ptr1;}
while(swapped);
}


//Fonction max pour round robin
int max (processus1 *l)
{
    int max=1;
    while(l!=NULL)
    {
        if(l->pid>max)
            max=l->pid;
        l=l->suivant;
    }
    return(max);
}

//procedure swap pour round robin
void swap(processus1 *listea,processus1 *listeb){

int temp=listea->tempsArriver;
int temp1=listea->pid;
int temp2=listea->tempsExecution;
listea->tempsArriver = listeb->tempsArriver;
listea->pid=listeb->pid;
listea->tempsExecution=listeb->tempsExecution;
listeb->tempsArriver=temp;
listeb->pid=temp1;
listeb->tempsExecution=temp2;
}

//Saisie pour round robin
void saisieProcessus(processus1 **liste)
{
    int n;
    processus1 *nv,*tmp;
    nv=malloc(sizeof(processus1));
    if(nv!= NULL)
       {
       printf(BMAG"\n\n\t\t\t\t\t\4SAISIE PROCESSUS\4\n\n\n\n\n"reset);
       do{
       printf(BYEL"\n\n\t\t\4 Donner le temps d'arriver  : "reset);
       scanf("%d",&(nv->tempsArriver));
       }while((nv->tempsArriver)<0);
       do{
       printf(BYEL"\n\n\t\t\4 Donner le temps d'execution   : "reset);
       scanf("%d",&(nv->tempsExecution));
       }while((nv->tempsExecution)<=0);
       nv->etatProcessus="Pret";
       nv->tempsFin=0;
       nv->saveTempsArriver=nv->tempsArriver;
       nv->saveTempsExecution= nv->tempsExecution;
       nv->suivant= NULL;
       if((*liste)==NULL)
       {
           nv->pid=1;
           (*liste)=nv;
       }
       else
       {
           tmp = (*liste);
           while(tmp->suivant != NULL)
            tmp=tmp->suivant;
           nv->pid=max((*liste))+1;
           tmp->suivant=nv;
       }
    }

}


//Affichage pour round robin
void AffichageTabProcessus(processus1 *liste)
{
    printf(BRED"\n\n\t\t\t\t\t\4AFFICHAGE DES PROCESSUS\4\n\n\n\n\n"reset);
    printf(BYEL"+-----+--------------------+---------------------+ \n"reset);
    printf(BYEL"| PID |  TEMPS D'ARRIVER   |  TEMPS D'EXECUTION  |\n"reset);
    printf(BYEL"+-----+--------------------+---------------------+\n"reset);
    processus1 *temp=liste;
    while(temp != NULL)
    {

        printf(BBLU"|%3d  |%20d|%21d|\n"reset,temp->pid,temp->tempsArriver,temp->tempsExecution);
        printf(BYEL"+-----+--------------------+---------------------+\n"reset);
        temp = temp->suivant;
    }
    getch();
}

//Copier pour round robin
processus1* copier(processus1*l)
{
    processus1*l1=NULL,*q,*nv;
    while(l!=NULL)
    {
        nv = malloc(sizeof(processus1));
        if(nv!=NULL)
        {
            nv->pid=l->pid;
            nv->debTempsExec=l->debTempsExec;
            nv->saveTempsArriver=l->saveTempsArriver;
            nv->tempsArriver=l->tempsArriver;
            nv->tempsExecution=l->tempsExecution;
            nv->saveTempsExecution=l->saveTempsExecution;
            nv->suivant=NULL;
            l = l->suivant;
            if(l1==NULL)
            {
			    l1=nv;
			}
            else
            {
            	q->suivant=nv;
			}
			q=nv;
        }
    }
    return(l1);
}

//Menu pour round robin
void Menu()
{
    printf(BGRN"\n\n\t\t\t\t\t\4\4GESTION DES PROCESSUS\4\4 \n\n\n\n"reset);
    printf("\t\t\t 1- SAISIE PROCESSUS \1\n\n");
    printf("\t\t\t 2- AFFICHAGE PROCESSUS \1\n\n");
    printf("\t\t\t 3- DIAGRAMME DE GANTT ROUND ROBIN \1 \n\n");
    printf("\t\t\t 0- SORTIR \1\n\n");
}

//diagramme de gant
  void
Fifo (struct process *tete)
{

struct process *temp;

temp = tete;

int i = 0;

float s = 0, nb = 0;

float TEM = 0;

line1 (6);

printf ("|  PID   |  T.Arr  | T.Excu |  Debut |  attente  |  Fin  |\n");

line1 (6);

int wait;

while (temp != NULL)
    {

TEM = TEM + (temp->duree);


if (i - temp->temps < 0)
	{

wait = 0;

}

      else
	{

wait = i - temp->temps;

}

printf ("|  %d     |   %dms  |    %dms |  %dms   |   %dms     |   %dms",
	       temp->pid, temp->temps, temp->duree, i, wait, i + temp->duree);

if (i + temp->duree < 10)
	{

printf ("  |\n");

}

      else if (i + temp->duree < 100)
	{

printf (" |\n");

}

      else
	{

printf ("|\n");

}

temp->wait = i - temp->temps;

temp->terminer = i + temp->temps;

temp->temps_execu = temp->terminer - temp->temps;

i = i + temp->duree;

if (temp->wait < 0)
	{

temp->wait = 0;
	};

s = s + temp->wait;

temp = temp->nxt;

if (temp != NULL)
	{

if (i < temp->temps)
	    {

i = temp->temps;

}

};

nb += 1;

line1 (6);

};

float moy;

if (nb != 0)
    {

moy = s / nb;

}

  else
    {

moy = 0;

}

printf ("                             \4 TEMPS D'ATTENTE MOYEN : %f \n", moy);

printf ("                             \4 TEMPS D'EXECUTION MOYEN %f \n", TEM / nb);

while (temp != NULL)
    {

for (int i = 0; i < temp->duree; i++)
	{

printf ("[ P%i ]-->", temp->pid);

}

temp = temp->nxt;

}
printf ("+----+\n");




}
void diagrame1 (struct process *tete)
{
  struct process *temp;
  temp = tete;

  while (temp != NULL)
    {


      for (int i = 0; i < temp->duree; i++)
	{
	  printf ("[ P%i ]-->", temp->pid);
	}

      temp = temp->nxt;
    }
  printf (" \n +----+\n");


}

// Main Program //


int main(){
struct process *tete;
processus1 *liste,l;
processus1*proc=NULL,*proc1=NULL;
int choice;
tete=init();
while (1){
system("cls");

  int choix=menu3();
  if (choix==1){

char a=menu();

if (a=='1'){
int b=menu2();
for (int i=0;i<b;i++){
add(&tete);
}
tete=triprocess(tete);
}
else if (a=='2'){
show1(tete);
scanf(" %c",&a);
system("cls");
}
else if (a=='3'){
   Fifo(tete);

diagrame1 (tete);
scanf(" %c",&a);
system("cls");
}
else{
    printf("encore une fois ......\n ");
//printf("choix incorrecte");
    //system("clear");
 //menu();

}

}

  else if(choix==2){

    //char a=menu4();
/*
    if (a=='1'){
saisieProcessus(&liste);
}

else if (a=='2'){
AffichageTabProcessus(liste);
scanf(" %c",&a);
system("clear");
}
else if (a=='3'){
   roundrobin(&l);
scanf(" %c",&a);
system("clear");
}
else{
    printf("encore une fois ......\n ");
}

}
} */
/* switch (a)
            {
            case 1 : saisieProcessus(&proc);break;
            case 2 : tri(proc);AffichageTabProcessus(proc);break;
            case 3 : tri(proc);proc1=copier(proc);roundrobin(proc1);
            break;
            case 0 : break;
            default: printf("choix errone");getch();
            }
}

}*/
do
    {       system("cls()");
            menu4();
            Menu();
            printf(BCYN"\t\t\t  Taper votre choix  : "reset);
            scanf("%d",&choice);
            system("cls()");
            switch (choice)
            {
            case 1 : saisieProcessus(&proc);break;
            case 2 : tri(proc);AffichageTabProcessus(proc);break;

            case 3 : tri(proc);proc1=copier(proc);roundrobin(proc1);
            break;
            case 0 : break;
            default: printf(BRED"choix errone"reset);getch();
            }


    }while(choice != 0);
}
}
}

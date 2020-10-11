#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include<time.h>


typedef struct{
    char time[15];
    char grupo;
    float nota;
    int vitorias;
    int classificado;
    struct TNo *Lista;
    struct TNo *Filhos;
}TNo;
void carrega(TNo *Times){
    FILE *file;
    file = fopen("arvore.txt", "r");
    char texto[50];
    int i=0;
     while(!feof(file)){
        fscanf(file, "%s",&Times[i].time);
        fscanf(file, "%f",&Times[i].nota);
        fscanf(file, "%s",&Times[i].grupo);
        Times[i].classificado=0;
        Times[i].Filhos=NULL;
        Times[i].Lista=NULL;
        //printf(" Time: %s Nota %f Grupo %c\n", Times[i].time, Times[i].nota, Times[i].grupo);
        i++;

    }
    fclose(file);
    return;

}
int simulajogos(TNo *Time1, TNo *Time2){
    int i;

    printf("%s x %s\n", Time1->time, Time2->time);
    float t1, t2;
    int c1=0, c2=0;
    t1=Time1->nota - Time2->nota;
    t2=Time2->nota - Time1->nota;
    t1=(50+(t1*10));
    t2=(50+(t2*10));
    int aleatorio;
    printf("chances: %s %.2f%% %s %.2f%% \n", Time1->time, t1,Time2->time,t2);

     /* for (i=0; i < 10; i++)
  {
    // gerando valores aleatórios na faixa de 0 a 100
    printf("%d ", rand() % 100);

  }*/
    printf("Simulacao: ");
     for (i = 0; i < 10; i++){
        //srand(time(NULL));
        aleatorio=(rand() % 100);
        printf("%d ", aleatorio);
        if(aleatorio<=t1){
            c1++;
        }else{
            c2++;
        }
  }
  printf("\n%s %d x %s %d \n",Time1->time, c1,Time2->time,c2);
  if(c1>=c2){
    printf("%s ganhou\n", Time1->time);
     printf("\n\n\n");
     return 1;
  }else{
    printf("%s ganhou\n", Time2->time);
     printf("\n\n\n");
     return 2;
  }


}
void sGrupo(TNo *Time1,TNo *Time2,TNo *Time3,TNo *Time4){
    int wins[4]={0,0,0,0};
    printf("-------------GRUPO %c-----------\n", Time1->grupo);
    printf("TIMES : %s %s %s %s \n",Time1->time,Time2->time,Time3->time,Time4->time);
    srand(time(NULL));


    if(simulajogos(Time1,Time2)==1)
        wins[0]++;
    else
        wins[1]++;

    if(simulajogos(Time1,Time3)==1)
        wins[0]++;
    else
        wins[2]++;

    if(simulajogos(Time1,Time4)==1)
        wins[0]++;
    else
        wins[3]++;

    if(simulajogos(Time2,Time1)==1)
        wins[1]++;
    else
        wins[0]++;

    if(simulajogos(Time3,Time1)==1)
        wins[2]++;
    else
        wins[0]++;

    if(simulajogos(Time4,Time1)==1)
        wins[3]++;
    else
        wins[0]++;



    if(simulajogos(Time2,Time3)==1)
        wins[1]++;
    else
        wins[2]++;

    if(simulajogos(Time2,Time4)==1)
        wins[1]++;
    else
        wins[3]++;

    if(simulajogos(Time3,Time2)==1)
        wins[2]++;
    else
        wins[1]++;

    if(simulajogos(Time4,Time2)==1)
        wins[3]++;
    else
        wins[1]++;

    if(simulajogos(Time3,Time4)==1)
        wins[2]++;
    else
        wins[4]++;

    if(simulajogos(Time4,Time3)==1)
        wins[3]++;
    else
        wins[2]++;

    Time1->vitorias=wins[0];
    Time2->vitorias=wins[1];
    Time3->vitorias=wins[2];
    Time4->vitorias=wins[3];

    printf("vitorias: \n");
    printf("%s %d \n", Time1->time, Time1->vitorias);
    printf("%s %d \n", Time2->time, Time2->vitorias);
    printf("%s %d \n", Time3->time, Time3->vitorias);
    printf("%s %d \n", Time4->time, Time4->vitorias);

    int i,maior=0;
    for(i=1;i<4;i++){
        if(wins[i]>wins[maior])
            maior=i;
    }
    switch(maior){
        case 0:
            Time1->classificado=1;
            break;
        case 1:
            Time2->classificado=1;
            break;
        case 2:
            Time3->classificado=1;
            break;
        case 3:
            Time4->classificado=1;
            break;
    }
    wins[maior]=0;
    maior=0;
    for(i=1;i<4;i++){
        if(wins[i]>wins[maior])
            maior=i;
    }
    switch(maior){
            case 0:
            Time1->classificado=2;
            break;
        case 1:
            Time2->classificado=2;
            break;
        case 2:
            Time3->classificado=2;
            break;
        case 3:
            Time4->classificado=2;
            break;
    }
    system("pause");
    system("cls");
}
void FaseDeGrupos(TNo *Time ){
    sGrupo(&Time[0], &Time[1],&Time[2],&Time[3]);//simulando os jogos do grupo A
    sGrupo(&Time[4], &Time[5],&Time[6],&Time[7]);//simulando os jogos do grupo B
    sGrupo(&Time[8], &Time[9],&Time[10],&Time[11]);//simulando os jogos do grupo C
    sGrupo(&Time[12], &Time[13],&Time[14],&Time[15]);//simulando os jogos do grupo D

}
int Classificados(int f2[],TNo *Times){
    int i,j=0;
    for(i=0;i<16;i++){
        if(Times[i].classificado!=0){
            printf("[Grupo %c] %s  Classificado em %d \n",Times[i].grupo, Times[i].time, Times[i].classificado);
            f2[j]=i;
            j++;
        }
        if((i+1)%4 == 0 )
            printf("\n\n\n\n\n");
    }


}
void insere(TNo *Time1,int pos ){
 //   for(int i=0;i<)
}
void criarv(int i, TNo *Times){
    /*
    for(int i=0;i<16;i++){
        if(Times[ic[i]].classificado == 1)
            insere(Time[ic[i],1);
        else if(Times[ic[i]].classificado == 2)
            insere(Time[ic[i],2);




    }
*/



}

void BuscaGulosa(int i, TNo *Times){
    printf("Busca Gulosa:\n");
    printf("Primeiros Adjacentes equivalentes as quartas de final\n");
  //  printf("%s %d\n", Times[i].time,Times[i].classificado);
    int mnota=0;
    int pOp;
    if(Times[i].classificado==1)
        pOp=2;
    else
        pOp=1;
    int k=0;
    int quartas[3]={0,0,0};
    for(int j=0;j<16;j++){
       // printf("------------------------%d %d %s %d %c \n",pOp,j, Times[j].time, Times[j].classificado,Times[j].grupo);
        if(Times[j].classificado==pOp && Times[i].grupo!=Times[j].grupo){

            quartas[k]=j;
            k++;
            if(Times[j].nota<Times[mnota].nota)
                mnota=j;
        }
    }
    /*int aux;
     for (k = 1; k < 4; k++) {
        for (int j = 0; j < 4 - k; j++) {
            if (quartas[j] > quartas[j + 1]) {
                aux          = quartas[j];
                quartas[j]     = quartas[j + 1];
                quartas[j + 1] = aux;
            }
        }
    }*/
    for(int j=0;j<3;j++){
        printf("Possivel Adversario: %s (%.1f)\n", Times[quartas[j]].time, Times[quartas[j]].nota);
    }
    printf("Adversario mais facil das quartas: %s (%.1f) [ELIMINADO]\n\n\n", Times[mnota].time,Times[mnota].nota);
    int aux=Times[mnota].classificado;
    Times[mnota].classificado=0;
    int mnota2=0;

    int Semi[6];
    k=0;
    for(int j=0;j<16;j++){
        if(Times[j].classificado!=0 && Times[i].time!=Times[j].time){
            Semi[k]=j;
            k++;
            if(Times[j].nota<Times[mnota2].nota)
                mnota2=j;
        }
    }

    for(int j=0;j<16;j++){
        if(Times[j].classificado!=0 && Times[j].time!= Times[i].time)
            printf("Possivel adversario na semi:  %s (%.1f)\n", Times[j].time, Times[j].nota );
    }
    printf("Adversario mais facil da semi: %s (%.1f) [ELIMINADO] \n\n\n", Times[mnota2].time, Times[mnota2].nota);
    int aux2=Times[mnota2].classificado;
    Times[mnota2].classificado=0;
    int m3=0;
    for(int j=0;j<16;j++){
        if(Times[j].time!=Times[i].time && Times[j].classificado != 0){
            printf("Possivel adversario na final: %s (%.1f)\n", Times[j].time, Times[j].nota );
            if(Times[m3].nota>Times[j].nota)
                m3=j;
        }
    }
    printf("\n\n\nAdversario mais facil da final: %s", Times[m3].time);

    printf("\n\n\n\n\n");
    Times[mnota].classificado=aux;
    Times[mnota2].classificado=aux2;
}
int main(){
    TNo *Times = (TNo*)malloc(16*sizeof(TNo));
    int i,j,c[8];
    carrega(Times);

    for(i=0; i<16;i++){
        Times[i].vitorias=0;
         if((i)%4==0)
            printf("Grupo %c\n", Times[i].grupo);
        printf("Time: %s  Nota: %.1f \n", Times[i].time, Times[i].nota, Times[i].grupo);

        if((i+1)%4==0)
            printf("\n\n\n\n\n");
    }
    system("pause");
    system("cls");
    printf("\n\n\nSIMULANDO JOGOS\n\n\n\n");

    FaseDeGrupos(Times);
    Classificados(c,Times);
    /*system("pause");
    system("cls");*/
    printf("Caminhos ate a final: \n");
   for(i=0;i<8;i++){
        printf("%Time : %s\n", Times[c[i]].time);
        BuscaGulosa(c[i],Times);
    }


}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    struct Vert *cima;
    struct Vert *baixo;
    struct Vert *direita;
    struct Vert *esquerda;
    int max;
    char simbolo;
    int verific;
}Vert;
Vert CriaA(Vert **lab,int m,int n,int i,int j){
     if(lab[i][j].verific!=0){
        lab[i][j].verific=0;
        //printf("volta ---- max:%d max: %d\n\n",P0->lmax,P0->max);
        return;
    }
     if(lab[i][j+1].simbolo == '.' /*&& lab->direita==NULL*/){//ponto a direita
        printf("vert a direita\n");
        lab[i][j].max++;
        lab[i][j].verific++;
        lab[i][j].direita=lab[i][j+1];
        lab[i][j+1].esquerda=lab[i][j];
        CriaA(lab,m,n,i,j+1);
        /*if((P0->max)<(P0->lmax)){
            P0->max=P0->lmax;
        }
        printf("voltou para lab[%d][%d]  ------ max: %d lmax:%d \n",i,j,P0->max, P0->lmax);
        P0->lmax--;
     */}
     if(lab[i][j-1].simbolo=='.'/*&& PAtual->esquerda==NULL && PAtual->verific==0*/){//ponto a esquerda
        printf("vert a esquerda\n");
        lab[i][j].max++;
        lab[i][j].verific++;
        lab[i][j].esquerda=Aux;
        lab[i][j-1].direita=lab[i][j];
        CriaA(lab,m,n,i,j-1);
        /*if(P0->lmax>P0->max){
            P0->max=P0->lmax;
        }
        printf("voltou para lab[%d][%d] ------ max: %d lmax:%d \n",i,j,P0->max, P0->lmax);
        P0->lmax--;

     */}
    if(lab[i+1][j].simbolo=='.' /*&& PAtual->baixo==NULL && PAtual->verific==0*/){//ponto abaixo
        printf("vert embaixo\n");
        lab[i][j].max++;
        lab[i][j].verific++;
        lab[i][j].baixo=Aux;
        lab[i+1][j].=PAtual;
        CriaA(lab,m,n,i+1,j);
        /*if((P0->lmax)>(P0->max)){
            P0->max=P0->lmax;
        }
        printf("voltou para lab[%d][%d] ------ max: %d lmax:%d \n",i,j,P0->max, P0->lmax);
        P0->lmax--;
    */}
    if(lab[i-1][j].simbolo=='.'/* && PAtual->cima==NULL && PAtual->verific==0 */){// ponto em cima
        printf("vert acima \n");
        lab[i][j].lmax++;
        lab[i][j].verific++;
        lab[i][j].cima=lab[i-1][j];
        lab[i-1][j].baixo=lab[i][j];
        CriaA(lab,m,n,i-1,j);
        /*if((P0->lmax)>(P0->max)){
        P0->max=P0->lmax;
        }
        printf("voltou para lab[%d][%d] ------ max: %d lmax:%d \n",i,j,P0->max, P0->lmax);
        P0->lmax--;
    */}
    /*PAtual->verific=0;
    printf("retornou de td-----Lab[%d][%d]\n",i,j);
    if(PAtual->cima!=NULL){
        printf("NAO EH NULO==================================================================\n");
    }*/
}
int main(){
    Vert **lab;
    int m,n,i,j;
    char aux;
    //Vert *ant,**grafo;
    scanf("%d %d", &n,&m);
    //restricao


    lab=(Vert**)malloc(n*sizeof(Vert*));
    for(i=0;i<m;i++){
        lab[i]=(Vert*)malloc(sizeof(Vert));
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%s",&lab[i][j].simbolo);
            lab[i][j].max=0;
            lab[i][j].baixo=NULL;
            lab[i][j].cima=NULL;
            lab[i][j].direita=NULL;
            lab[i][j].esquerda=NULL;
            lab[i][j].verific=0;

        }
    }

    CriaA(lab,m,n,0,0);

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){

            printf("%c",lab[i][j].simbolo);
        }
        printf("\n");
    }

    return 0;

}

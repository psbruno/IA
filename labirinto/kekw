#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    struct Vert *cima;
    struct Vert *baixo;
    struct Vert *direita;
    struct Vert *esquerda;
    int lmax;
    int verific;
}Vert;

typedef Vert *fcv;//funcao cria vertice
fcv Aloca(){
    Vert *vertice;
    vertice=(Vert*)malloc(sizeof(Vert));

    vertice->lmax=0;
    vertice->baixo=NULL;
    vertice->baixo=NULL;
    vertice->direita=NULL;
    vertice->esquerda=NULL;
    vertice->verific=0;

    return vertice;
}

Vert CriaA(Vert *P0,Vert *PAtual,char **lab,int i,int j,int TL,int TC,int *vsaidas,int n){
    int m=0;
     printf("analisando lab[%d][%d]",i,j);
     if(PAtual->verific!=0 || i+1==TL||j+1==TC){
        vsaidas[m]=0;//P0->lmax;
        m++;
        realloc(vsaidas, n*sizeof(int));
        printf("\n\n%d %d\n",vsaidas[0],n);
        printf("volta\n");
        return;
    }
    Vert *Aux=Aloca();
     if(lab[i][j+1]=='.' && PAtual->direita==NULL){//ponto a direita
        printf("vert a direita\n");
        P0->lmax++;
        PAtual->verific++;
        PAtual->direita=Aux;
        Aux->esquerda=PAtual;
        CriaA(P0,Aux,lab,i,j+1,TL,TC,vsaidas,&n);
        P0->lmax--;
        printf("voltou para lab[%d][%d]\n",i,j);
     }
     if(j>0 && lab[i][j-1]=='.' && PAtual->esquerda==NULL){//ponto a esquerda
        printf("vert a esquerda\n");
        P0->lmax++;
        PAtual->verific++;
        PAtual->esquerda=Aux;
        Aux->direita=PAtual;
        CriaA(P0,Aux,lab,i,j-1,TL,TC,vsaidas,&n);
        P0->lmax--;
        printf("voltou para lab[%d][%d]\n",i,j);
     }
    if(lab[i+1][j]=='.'&& PAtual->baixo==NULL){//ponto abaixo
        printf("vert embaixo\n");
        P0->lmax++;
        PAtual->verific++;
        PAtual->baixo=Aux;
        Aux->cima=PAtual;
        CriaA(P0,Aux,lab,i+1,j,TL,TC,vsaidas,&n);
        P0->lmax--;
        printf("voltou para lab[%d][%d]\n",i,j);
    }
    printf("voltou de cima");
    if(i>0 && lab[i-1][j]=='.' && PAtual->cima==NULL ){// ponto em cima
        printf("vert acima \n");
        P0->lmax++;
        PAtual->verific++;
        PAtual->cima=Aux;
        Aux->baixo=PAtual;
        CriaA(P0,Aux,lab,i,j+1,TL,TC,vsaidas,&n);
        P0->lmax--;
        printf("voltou para lab[%d][%d]\n",i,j);
    }
    printf("retornou de td\n");
}
int BuscaA(char **lab, int TL, int TC){
    int i=0,j=0,k,x;
    int *Vsaidas;
    Vsaidas=malloc(2*sizeof(int));

    Vert *saidas=(Vert *)malloc(((TC*TL)-1)*sizeof(Vert));

    for(k=0;k<(TL+TC)-1;k++){
        saidas[k].lmax=0;
        saidas[k].baixo=NULL;
        saidas[k].baixo=NULL;
        saidas[k].direita=NULL;
        saidas[k].esquerda=NULL;
        saidas[k].verific=0;
    }

    printf("ponto atual: lab[%d][%d], TL %d TC %d\n",i,j,TL,TC);
    for(i=0;i<TL;i++){
         if(lab[i][0]=='.'){
            CriaA(&saidas[i],Aloca(),lab,i,j,TL,TC,Vsaidas, 0);



        }
    }


}

int proc1(char **lab, int m, int n){
    int i=0,j=0;
    Vert *P0;
   BuscaA(lab,m,n);
   return 0;
}

int main(){
    char **lab;
    int m,n,i,j;
    //Vert *ant,**grafo;
    scanf("%d %d", &n,&m);
    //restricao


    lab=(char**)malloc(n*sizeof(char*));
    for(i=0;i<m;i++){
        lab[i]=(char*)malloc(sizeof(char));
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%s",&lab[i][j]);
        }
    }

    proc1(lab, m,n);

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){

            printf("%c",lab[i][j]);
        }
        printf("\n");
    }

    return 0;

}

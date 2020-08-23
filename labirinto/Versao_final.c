#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    struct Vert *cima;
    struct Vert *baixo;
    struct Vert *direita;
    struct Vert *esquerda;
    int lmax;
    int max;
    int verific;
}Vert;

typedef struct{
    struct Vert *cima;
    struct Vert *baixo;
    struct Vert *direita;
    struct Vert *esquerda;
    int lmax;
    int max;
    int verific;
}P0Vert;
typedef struct{
    char simbolo;
    int verificacao;
}Tchar;
typedef Vert *fcv;//funcao cria vertice
fcv Aloca(){
    Vert *vertice;
    vertice=(Vert*)malloc(sizeof(Vert));

    vertice->lmax=0;
    vertice->baixo=NULL;
    vertice->cima=NULL;
    vertice->direita=NULL;
    vertice->esquerda=NULL;
    vertice->verific=0;
    vertice->max=0;
    return vertice;
}

Vert CriaA(P0Vert *P0,Vert *PAtual, Tchar **lab,int i,int j,int TL,int TC){
     lab[i][j].verificacao++;
    Vert *Aux=Aloca();
     if(j+1<TL && lab[i][j+1].simbolo=='.' && /*PAtual->direita==NULL &&*/ lab[i][j+1].verificacao ==0){//ponto a direita
        P0->lmax++;
        PAtual->direita=Aux;
        Aux->esquerda=PAtual;
        CriaA(P0,Aux,lab,i,j+1,TL,TC);
        if(P0->lmax>P0->max){
            P0->max=P0->lmax;
        }

        P0->lmax--;
     }
     if(j>0 && lab[i][j-1].simbolo=='.' && /*PAtual->esquerda==NULL &&*/ lab[i][j-1].verificacao==0){//ponto a esquerda

        P0->lmax++;
        lab[i][j-1].verificacao++;
        PAtual->esquerda=Aux;
        Aux->direita=PAtual;
        CriaA(P0,Aux,lab,i,j-1,TL,TC);
        if(P0->lmax>P0->max){
            P0->max=P0->lmax;
        }

        P0->lmax--;

     }
    if(i+1<TC && lab[i+1][j].simbolo=='.'/*&& PAtual->baixo==NULL */&& lab[i+1][j].verificacao==0){//ponto abaixo

        P0->lmax++;
        lab[i+1][j].verificacao++;
        PAtual->baixo=Aux;
        Aux->cima=PAtual;
        CriaA(P0,Aux,lab,i+1,j,TL,TC);
        if((P0->lmax)>(P0->max)){
            P0->max=P0->lmax;
        }

        P0->lmax--;
    }
    if(i>0 && lab[i-1][j].simbolo=='.' /*&& PAtual->cima==NULL */&& lab[i-1][j].verificacao==0 ){// ponto em cima

        P0->lmax++;
        PAtual->verific++;
        PAtual->cima=Aux;
        Aux->baixo=PAtual;
        CriaA(P0,Aux,lab,i-1,j,TL,TC);
        if((P0->lmax)>(P0->max)){
            P0->max=P0->lmax;
        }

        P0->lmax--;
    }
    lab[i][j].verificacao=0;


}
int BuscaA(char **lab, int TL, int TC){
    int i=0,j=0,k,aux;
    P0Vert *saidas=(Vert *)malloc((2*(TC+TL)-1)*sizeof(Vert));

    for(k=0;k<(TL+TC)-1;k++){

        saidas[k].lmax=0;
        saidas[k].baixo=NULL;
        saidas[k].cima=NULL;
        saidas[k].direita=NULL;
        saidas[k].esquerda=NULL;
        saidas[k].verific=0;
        saidas[k].max=0;
    }


    for(i=0;i<TL;i++){
         if(lab[i][0]=='.'){
            CriaA(&saidas[i],Aloca(),lab,i,j,TL,TC);
        }
    }
    for(i=0;i<TC;i++){
         if(lab[0][i]=='.'){
            CriaA(&saidas[i+TL],Aloca(),lab,i,j,TL,TC);
        }
    }for(i=0;i<TL;i++){
         if(lab[i][TL-1]=='.'){
            CriaA(&saidas[i+TC+TL],Aloca(),lab,i,j,TL,TC);
        }
    }for(i=0;i<TL;i++){
         if(lab[i][TC-1]=='.'){
            CriaA(&saidas[i+2*TL+TC],Aloca(),lab,i,j,TL,TC);
        }
    }
aux=saidas[0].max;
    for(i=1;i<TL;i++){
         if(aux<saidas[i].max){
            aux=saidas[i].max;
        }
    }
    printf("%d", aux);
}


int main(){
    Tchar **lab;
    int m,n,i,j;
    //Vert *ant,**grafo;
    scanf("%d %d", &n,&m);
    //restricao


    lab=(Tchar**)malloc(n*sizeof(Tchar*));
    for(i=0;i<m;i++){
        lab[i]=(Tchar*)malloc(sizeof(Tchar));
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%s",&lab[i][j].simbolo);
            lab[i][j].verificacao=0;
        }
    }

    BuscaA(lab, m,n);


    return 0;

}

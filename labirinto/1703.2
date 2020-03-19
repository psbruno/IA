
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
int CriaA(Vert *P0,char **lab,int i,int j, int TL, int TC){
    Vert *aux;
    printf("ponto atual: lab[%d][%d], TL %d TC %d\n",i,j,TL,TC);

    if(lab[i][j+1]=='.' && j<=TC){//ponto a direita
        if(j+1==TC){
            P0->verific=0;
            return P0->lmax;
        }
        P0->verific++;
        P0->lmax++;
        aux=Aloca();
        P0->direita=aux;
        aux->verific++;
        //aux->esquerda=P0;
        printf("Vertice a direita\n", P0->lmax);
        P0->lmax+=CriaA(aux,lab,i,j+1,TL,TC);
        printf("%d",P0->lmax);
    }else{
        printf("nao tem vertice a direita\n");
    }
    if(lab[i][j-1]=='.'){//ponto a esquerda
        if(j+1==TC){
            P0->verific=0;
            return P0->lmax;
        }
        P0->verific++;
        P0->lmax++;
        aux=Aloca();
        P0->esquerda=aux;
        //aux->direita=P0;
        printf("Vertice a esquerda\n");
        P0->lmax+=CriaA(aux,lab,i,j-1,TL,TC);
    }else{
        printf("nao tem vertice a esquerda\n");
    }
    if(lab[i+1][j]=='.'&& i+1<TL){//ponto abaixo
        if(P0->verific==1){
            P0->verific=0;
            return 0;
        }
        P0->verific++;
        P0->lmax++;
        aux=Aloca();
        P0->baixo=aux;
        aux->cima=P0;
        printf("Vertice abaixo\n");
        P0->lmax+=CriaA(aux,lab,i+1,j,TL,TC);
    }else{
        printf("nao tem vertice abaixo\n");
    }
    if(lab[i-1][j]=='.'){// ponto em cima
        if(P0->verific==1){
            P0->verific=0;
            return 0;
        }
        P0->verific++;
        P0->lmax++;
        aux=Aloca();
        P0->cima=aux;
        //aux->baixo=P0;
        printf("Vertice em cima\n");
        P0->lmax+=CriaA(aux,lab,i-1,j,TL,TC);
    }else{
        printf("nao tem vertice acima\n");
    }

    printf("voltou da recursao %d %d\n\n",i,j);
    return P0->lmax;
}

int proc1(char **lab, int m, int n){
    int i=0,j=0;
    Vert *P0;
    while(lab[i][j]=='#'){//laco pra achar o primeiro ponto
        i++;
            while(lab[i][j]=='#'){
                j++;
                if(j==m){
                 j=0;
                 break;
                }
            if(i==n){
                    break;
            }
        }
   }//laco pra achar o primeiro ponto


   P0=Aloca();
   CriaA(P0,lab,i,j,m,n);

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

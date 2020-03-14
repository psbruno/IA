#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    struct Vert *cima;
    struct Vert *baixo;
    struct Vert *direita;
    struct Vert *esquerda;
    int lmax;
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

    return vertice;
}
int CriaA(Vert *P0,char **lab,int i,int j){
    Vert *aux;
    printf("ponto atual: lab[%d][%d]\n",i,j);

    if(lab[i+1][j]=='.'){//ponto a direita
        P0->lmax++;
        aux=Aloca();
        P0->direita=aux;
        printf("Vertice a direita\n", P0->lmax);
        P0->lmax+=CriaA(aux,lab,i+1,j);
        printf("%d",P0->lmax);
    }else{
        printf("nao tem vertice a direita\n", P0->lmax);
    }
    if(lab[i-1][j]=='.'){//ponto a esquerda
        P0->lmax++;
        aux=Aloca();
        P0->esquerda=aux;
        printf("Vertice a esquerda\n");
        P0->lmax+=CriaA(aux,lab,i-1,j);
    }else{
        printf("nao tem vertice a esquerda\n", P0->lmax);
    }
    if(lab[i][j+1]=='.'){//ponto abaixo
        P0->lmax++;
        aux=Aloca();
        P0->baixo=aux;
        printf("Vertice abaixo\n");
        P0->lmax+=CriaA(aux,lab,i,j+1);
    }else{
        printf("nao tem vertice abaixo\n", P0->lmax);
    }
    if(lab[i][j-1]=='.'){// ponto em cima
        P0->lmax++;
        aux=Aloca();
        P0->cima=aux;
        printf("Vertice em cima\n");
        P0->lmax+=CriaA(aux,lab,i,j-1);
    }else{
        printf("nao tem vertice acima\n", P0->lmax);
    }

    return P0->lmax;
}
int conta(char **lab, int pl, int pc,int TL, int TC){//primeira linha, primeira coluna, total linhas, total colunas
     Vert *P0;
    int i,j;
    P0=Aloca();
    CriaA(P0,lab,i,j);
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
   CriaA(P0,lab,i,j);

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    struct Vert *cima;
    struct Vert *baixo;
    struct Vert *direita;
    struct Vert *esquerda;
    int lmax;
    char simb;
}Vert;


int main(){
    char Aux;
    int m,n,i,j;
    Vert **grafo,*ant,*aux1;
    scanf("%d %d", &n,&m);
    //restricao


    grafo=(Vert**)malloc(n*sizeof(Vert*));
    for(i=0;i<m;i++){
        grafo[i]=(Vert*)malloc(sizeof(Vert));
    }




    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%s",grafo[i][j].simb);
            if(grafo[i][j].simb=='.'){
                if(j!=0){
                    if(grafo[i][j-1].simb!='#'){
                        grafo[i][j-1].direita=&grafo[i][j];
                    }

                }
            ant=*grafo;
            }
        }
    }




    for(i=0;i<n;i++){
        for(j=0;j<m;j++){

            printf("%c",grafo[i][j].simb);
        }
        printf("\n");
    }

}

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



 int conta(Vert **grafo, int n, int m){
     int i,j;
for(i= 0;i<n;i++){
        for(j=0;j<m;j++){
                printf("%d %d: ",i,j);
            if(grafo[i][j].esquerda!=NULL){
                    printf(" <- ");
                    grafo[i][j].lmax++;
                    //conta(grafo,i,j-1);
            }
            if(grafo[i][j].direita!=NULL){
                    printf(" -> ");
                    grafo[i][j].lmax++;
                    //conta(grafo,i,j+1);
            }
            if(grafo[i][j].baixo!=NULL){
                    printf(" | ");
                    grafo[i][j].lmax++;
                    //conta(grafo,i+1,j);
            }
            if(grafo[i][j].cima!=NULL){
                printf(" 1 ");
                    grafo[i][j].lmax++;
                    //conta(grafo,i-1,j);
            }
    printf("\n");

        }printf("\n");


    }


}

void setag(char **lab, int m, int n){
    int i,j;
    Vert **grafo;

    grafo=(Vert**)malloc(n*sizeof(Vert*));

    for(i=0;i<m;i++){
        grafo[i]=(Vert*)malloc(sizeof(Vert));
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            grafo[i][j].baixo= NULL;
            grafo[i][j].cima=NULL;
            grafo[i][j].direita=NULL;
            grafo[i][j].esquerda=NULL;
            grafo[i][j].lmax=0;
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
                printf("casa atual: %d %d \n", i,j);
                if(lab[i][j]=='.'){
                    if(j+1<m){
                    if (lab[i][j+1] == '.' ) {
                                printf("%d %d <-> %d %d\n", i,j,i,j+1);
                                grafo[i][j].direita=&grafo[i][j+1];
                                grafo[i][j+1].esquerda=&grafo[i][j];
                        }
                    }if(i+1<n){
                    if (lab[i+1][j] == '.') {
                                printf("%d %d | %d %d\n", i,j,i+1,j);
                                grafo[i][j].baixo=&grafo[i+1][j];
                                grafo[i+1][j].cima=&grafo[i][j];
                        }
                    }
                }

        }
    }




   //conta(grafo,n,m);

    return 0;
}

int main(){
    char **lab;
    int m,n,i,j;
    Vert *ant,**grafo;
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


    setag(lab, m,n);




    for(i=0;i<n;i++){
        for(j=0;j<m;j++){

            printf("%c",lab[i][j]);
        }
        printf("\n");
    }

    return 0;

}

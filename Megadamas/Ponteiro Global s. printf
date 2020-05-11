#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int NCapturas;
    struct RESP *Prox;
}RESP;
typedef struct{
    int l;
    int c;
    int t;
}pecas;
RESP *RAtual;
int PCaptura(int t, pecas V,int N, int M,int tab[N][M],int tab2[N][M]){
    int i,j;
    RESP *aux;
    if(V.l>N || V.c>M || V.l<0 || V.c<0){//verificação pra ver se a casa eh válida, tava comparando com valores "fora" do tabuleiro
        return 0;
    }

    if(tab[V.l+1][V.c+1]==2 && tab[V.l+2][V.c+2]==0){//confere se pode capturar abaixo e a direita
        tab[V.l][V.c]=0;
        tab[V.l+1][V.c+1]=0;
        tab[V.l+2][V.c+2]=1;
        V.l+=2;
        V.c+=2;
        PCaptura(t+1,V,N,M,tab,tab);
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            tab[i][j]=tab2[i][j];
        }
    }


    if(tab[V.l+1][V.c-1]==2 && tab[V.l+2][V.c-2]==0){//confere se pode capturar abaixo e a esquerda
        tab[V.l][V.c]=0;
        tab[V.l+1][V.c-1]=0;
        tab[V.l+2][V.c-2]=1;
        V.l+=2;
        V.c-=2;
        PCaptura(t+1,V,N,M,tab,tab);
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            tab[i][j]=tab2[i][j];
        }
    }

    if(tab[V.l-1][V.c+1]==2 && tab[V.l-2][V.c+2]==0){//confere se pode capturar acima e a direita
        tab[V.l][V.c]=0;
        tab[V.l-1][V.c+1]=0;
        tab[V.l-2][V.c+2]=1;
        V.l-=2;
        V.c=2;
        PCaptura(t+1,V,N,M,tab,tab);
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            tab[i][j]=tab2[i][j];
        }
    }

    if(tab[V.l-1][V.c-1]==2 && tab[V.l-2][V.c-2]==0){//confere se pode capturar acima e a esquerda
        tab[V.l][V.c]=0;
        tab[V.l-1][V.c-1]=0;
        tab[V.l-2][V.c-2]=1;
        V.l-=2;
        V.c-=2;
        PCaptura(t+1,V,N,M,tab,tab);
    }

    aux=(RESP*)malloc(sizeof(RESP));
    aux->NCapturas=0;
    aux->Prox=NULL;
    RAtual->Prox=aux;
    RAtual->NCapturas=t;
    RAtual=aux;
    return 0;
}
int mat(int N, int M){
    int x=0,i, j,tab2[N][M],tab[N][M];
    RESP *resp0;//cabeca do encadeamento com a resposta final
    pecas V[M*N/2];
    RAtual=(RESP*)malloc(sizeof(RESP));
    resp0=RAtual;
    RAtual->NCapturas=0;
    RAtual->Prox=NULL;

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            tab[i][j]=9;
        }
    }

    for(i=N-1;i>=0;i--){
        for(j=0;j<M;j+=2){
            if(i%2==N%2 && j==0){
                j++;
            }
            scanf("%d", &tab[i][j]);
            if(tab[i][j]==1){
                V[x].l=i;
                V[x].c=j;
                V[x].t=0;
                x++;
            }
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            tab2[i][j]=tab[i][j];
        }
    }
    x--;
    while(x>=0){
        PCaptura(0,V[x],N,M, tab2,tab);
        x--;
    }
    x=0;

    while(resp0!=NULL){
        if(resp0->NCapturas>x){
            x=resp0->NCapturas;
        }
        resp0=resp0->Prox;
    }

    printf("%d\n", x);
    return M+N;
}
int main() {
    int N=1,M=1,i,j;


    while(M>0){
        scanf("%d %d", &N,&M);
        M=mat(N,M);
    }



    return 0;
}

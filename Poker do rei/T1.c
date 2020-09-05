#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cartas[3];
    struct TMao *filacat;
    struct TMao *f1_13;
}TMao;
TMao *Novo(int *c1, int *c2,int *c3){
    TMao *Aux=(TMao *)malloc(sizeof(TMao));
    Aux->cartas[0]=*c1;
    Aux->cartas[1]=*c2;
    Aux->cartas[2]=*c3;
}
typedef TMao *FNo;
void p3(int *c1,int *c2,int *c3){
    if(*c3==13)
        return;
if(*c1==*c2 &&*c2==*c3){
        *c3+=1;
        p3(c1,c2,c3);
        return;
    }

    printf("[%d %d %d] ", *c1,*c2,*c3);

    *c3+=1;
    p3(c1,c2,c3);
}

void comb(int c1,int c2,int c3){
    int aux3=c3;
    while(c1<=13){
        p3(&c1,&c2,&c3);
        printf("\n");

        c3=1;
        c1++;
        c2++;
        //printf("%d %d %d \n", c1,c2,c3);
    }

}


int main(){
    int c1=1,c2=1,c3=2;
   // TMao *FPoker=(TMao *)malloc(sizeof(pok))
    comb(c1,c2,c3);

}

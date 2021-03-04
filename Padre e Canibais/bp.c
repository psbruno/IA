#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int NumMis1, NumCan1,NumMis2,NumCan2;
    struct Estado *T01,*T10,*T11,*T20,*T02;
    int verific;
}Estado;
typedef Estado *FEstado;

FEstado Novo(int *m1, int *c1,int *m2, int *c2,int V){
    Estado *Espaco;
    Espaco=(Estado*)malloc(sizeof(Estado));
    Espaco->NumCan1=*c1;
    Espaco->NumMis1=*m1;
    Espaco->NumCan2=*c2;
    Espaco->NumMis2=*m2;
    Espaco->T01=NULL;
    Espaco->T02=NULL;
    Espaco->T11=NULL;
    Espaco->T20=NULL;
    Espaco->T10=NULL;
    Espaco->verific=V;

    return Espaco;
}

FEstado tent11(int *m1, int *c1,int *m2,int *c2,int *l){
    if(*m1==*c1){
        if(*l==1){
            *m1-=1, *m2+=1, *c1-=1,*c2+=1;
            *l=2;
        }else{
            *m2-=1, *m1+=1, *c2-=1,*c1+=1;
            *l=1;
        }
    }else{
        return NULL;
    }
    return Novo(m1,c1,m2,c2,11);

}

FEstado tent10(int *m1,int *m2,int *c1,int *c2, int *l,Estado *Espaco){
   if(*m1>=1 && *l==1 || *m2>=1 && *l==2 ){
        if(*l==1){
            if(*m1-1==0 ||*m1-1>=c1){
                *m1-=1;
                *m2+=1;
                *l=2;
                return (Novo(m1,c1,m2,c2,10));
           }
        }
        if(*l==2){
            if(*m2-1==0 ||*m2-1>=c2){
                *m2-=1;
                *m1+=1;
                *l=1;
                return (Novo(m1,c1,m2,c2,10));
            }
        }
   }

        return NULL;


}
FEstado tent01(int *m1,int *m2,int *c1,int *c2, int *l,Estado *Espaco){
    if(*c1>=1 && *l==1 || *c2>=1 && *l==2 ){
        if(*l==1){

            if(*c2+1<=*m2 || *m2==0){
                *c1-=1;
                *c2+=1;
                *l=2;
                return (Novo(m1,c1,m2,c2,1));
            }
        }
        if(*l==2){
            if(*c1+1<=*m1 || *m1==0){
                *c2-=1;
                *c1+=1;
                *l=1;
                return (Novo(m1,c1,m2,c2,1));

            }

        }
    }
    return NULL;

}

FEstado tent02(int *m1,int *m2,int *c1,int *c2, int *l,Estado *Espaco){
    if(*c1>=2 && *l==1 || *c2>=2 && *l==2){
        if(*l==1){
            if(*c2+2<=*m2 || *m2 ==0){
                *c1-=2;
                *c2+=2;
                *l=2;
                return (Novo(m1,c1,m2,c2,2));
            }
        }
         if(*l==2){
            if(*c1+2<=*m1 || *m1==0){
                *c2-=2;
                *c1+=2;
                *l=1;
                return Novo(m1,m2,c1,c2,2);
            }
        }
    }
        return NULL;
}
int tent20(int *m1,int *m2,int *c1,int *c2, int *l,Estado *Espaco){

    if(*m1>=2 && *l==1 || *m2>=2 && *l==2){
        if(*l==1){
            if((*m1-2)==0 ||(*m1-2)>=*c1){
                *m1-=2;
                *m2+=2;
                *l=2;
                return Novo(m1,c1,m2,c2,20);
            }
        }
        if(*l==2){
            if(*m2-2==0 ||*m2-2>=c2){
                *m2-=2;
                *m1+=2;
                *l=1;
                return Novo(m1,c1,m2,c2,20);
            }
        }
    }
        return NULL;
}
int TestaEstados(int *m1,int *m2,int *c1,int *c2,int *l,Estado *Espaco ){
        if(*c2==3 && *m2==3){
            return 0;
        }
        if(Espaco==NULL){
           return 0;
        }
        if(*c1==3 && *m1==3 && Espaco->verific!=-1){
            return 0;
        }

     Estado *aux;

    if(Espaco->verific!=11){
        Espaco->T11=tent11(m1,c1,m2,c2,l);
        TestaEstados(m1,m2,c1,c2,l,Espaco->T11);
    }

    if(Espaco->verific!=01){
        Espaco->T01=tent01(m1,m2,c1,c2,l,Espaco);
        /*if(Espaco->T01!=NULL)
        aux=Espaco->T01;
        if(aux->verific!=1)*/
        TestaEstados(m1,m2,c1,c2,l,Espaco->T01);
    }
     if(Espaco->verific!=10){
        Espaco->T10=tent10(m1,m2,c1,c2,l,Espaco);
        /*if(Espaco->T10!=NULL)
        aux=Espaco->T10;
        if(aux->verific!=10)*/
        TestaEstados(m1,m2,c1,c2,l,Espaco->T10);
    }

        if(Espaco->verific!=20){
            Espaco->T20=tent20(m1,m2,c1,c2,l,Espaco);
            /*if(Espaco->T20!=NULL)
            aux=Espaco->T20;
            if(aux->verific!=20)*/
            TestaEstados(m1,m2,c1,c2,l,Espaco->T20);
        }
    if(Espaco->verific!=2){
        Espaco->T02=tent02(m1,m2,c1,c2,l,Espaco);
        /*    if(Espaco->T02!=NULL)
        aux=Espaco->T02;
        if(aux->verific!=2)*/
        TestaEstados(m1,m2,c1,c2,l,Espaco->T02);
    }

        return 0;
}
int impP(Estado *Espaco, int *check){
    Estado *aux=Espaco;
    if(Espaco->NumCan2==3 && Espaco->NumMis2==3){
        printf("\n\n\n\n ESTADO FINAL ENCONTRADO ---- ");
        printf("lado 1 - %d missionarios %d canibais, lado 2 - %d missionarios %d canibais\n",aux->NumMis1, aux->NumCan1, aux->NumMis2, aux->NumCan2);
        printf("\n\n\n\n");
        return 1;
    }
    if(Espaco!=NULL){
        aux=Espaco;
    }else{
        return check;
    }

    printf("lado 1 - %d missionarios %d canibais, lado 2 - %d missionarios %d canibais\n",aux->NumMis1, aux->NumCan1, aux->NumMis2, aux->NumCan2);
    if(aux->T11!=NULL){
        printf("passando 1 missionario e 1 canibal\n");
        *check=impP(aux->T11,check);
        if(*check==1)
            return 1;
    }
    if(aux->T01!=NULL){
        printf("passando 0 missionarios e 1 canibal\n");
        *check=impP(aux->T01,check);
        if(*check==1)
            return 1;
    }
    if(aux->T10!=NULL){
        printf("passando 1 missionario e 0 canibais\n");
        *check=impP(aux->T10,check);
        if(*check==1)
            return 1;
    }
    if(aux->T20!=NULL){
        printf("passando 2 missionarios e 0 canibais\n");
        *check=impP(aux->T20,check);
        if(*check==1)
            return 1;
    }
    if(aux->T02!=NULL){
        printf("passando 0 missionario e 2 canibal\n");
        *check=impP(aux->T02,check);
        if(*check==1)
            return 1;
    }

}
int impAi(Estado *Espaco, int *check,int ai,int pAtual){
    if(pAtual==ai){
        printf("\nLimite de profundidade atingido!\n\n");
        return 0;
    }

    Estado *aux=Espaco;

    if(Espaco->NumCan2==3 && Espaco->NumMis2==3){
        printf("\n\n\n\n ESTADO FINAL ENCONTRADO ---- ");
        printf("lado 1 - %d missionarios %d canibais, lado 2 - %d missionarios %d canibais\n",aux->NumMis1, aux->NumCan1, aux->NumMis2, aux->NumCan2);
        printf("\n\n\n\n");
        return 1;
    }
    if(Espaco!=NULL){
        aux=Espaco;
    }else{
        return check;
    }

    printf("lado 1 - %d missionarios %d canibais, lado 2 - %d missionarios %d canibais\n",aux->NumMis1, aux->NumCan1, aux->NumMis2, aux->NumCan2);
    if(aux->T11!=NULL){
        printf("passando 1 missionario e 1 canibal\n");
        *check=impAi(aux->T11,check,ai,pAtual+1);
        if(*check==1)
            return 1;
    }
    if(aux->T01!=NULL){
        printf("passando 0 missionarios e 1 canibal\n");
        *check=impAi(aux->T01,check,ai,pAtual+1);
        if(*check==1)
            return 1;
    }
    if(aux->T10!=NULL){
        printf("passando 1 missionario e 0 canibais\n");
        *check=impAi(aux->T10,check,ai,pAtual+1);
        if(*check==1)
            return 1;
    }
    if(aux->T20!=NULL){
        printf("passando 2 missionarios e 0 canibais\n");
        *check=impAi(aux->T20,check,ai,pAtual+1);
        if(*check==1)
            return 1;
    }
    if(aux->T02!=NULL){
        printf("passando 0 missionario e 2 canibal\n");
        *check=impAi(aux->T02,check,ai,pAtual+1);
        if(*check==1)
            return 1;
    }

}

int main(){
    int check=0,ai;
    int m1=3,m2=0,c1=3,c2=0,l=1;
    Estado *Espaco=Novo(&m1,&c1,&m2,&c2,-1);

    TestaEstados(&m1,&m2,&c1,&c2,&l,Espaco);

    printf("busca por profundidade: \n\n");
    impP(Espaco,&check);
    printf("insira um numero para a busca de aprofundamento iterativo\n");
    scanf("%d",&ai);
    check=0;
    impAi(Espaco,&check,ai,0);
    return 0;
}

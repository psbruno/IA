#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int NumMis1, NumCan1,NumMis2,NumCan2;
    struct Estado *T01,*T10,*T11,*T20,*T02;
    int verific;
}Estado;
typedef Estado *FEstado;

FEstado Novo(int m1, int c1,int m2, int c2,int V){
    Estado *Espaco;
    Espaco=(Estado*)malloc(sizeof(Estado));
    Espaco->NumCan1=c1;
    Espaco->NumMis1=m1;
    Espaco->NumCan2=c2;
    Espaco->NumMis2=m2;
    Espaco->T01=NULL;
    Espaco->T02=NULL;
    Espaco->T11=NULL;
    Espaco->T20=NULL;
    Espaco->T10=NULL;
    Espaco->verific=V;

    return Espaco;
}

FEstado tent11(int *m1, int *c1,int *m2,int *c2,int *l){
    printf("Tentativa ------- passar 1 M 1 C\n");
    if(*m1==*c1){
        if(*l==1){
            *m1-=1, *m2+=1, *c1-=1,*c2+=1;
            *l=2;
        }else{
            *m2-=1, *m1+=1, *c2-=1,*c1+=1;
            *l=1;
        }
        printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);
    }else{
        printf("\nNEGADO\n");
        return NULL;
    }
    return Novo(m1,c1,m2,c2,11);

}

FEstado tent10(int *m1,int *m2,int *c1,int *c2, int *l,Estado *Espaco){
   printf("Tentativa ------- passar 1 M 0 C \n");
   if(*m1>=1 && *l==1 || *m2>=1 && *l==2 ){
        if(*l==1){
            if(*m1-1==0 ||*m1-1>=c1){
                *m1-=1;
                *m2+=1;
                *l=2;
                printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);
                return (Novo(m1,c1,m2,c2,10));
           }
        }
        if(*l==2){
            if(*m2-1==0 ||*m2-1>=c2){
                *m2-=1;
                *m1+=1;
                *l=1;
                printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);
                return (Novo(m1,c1,m2,c2,10));
            }
        }
   }else{
       printf("\nNEGADO\n");
        return NULL;
   }

}
FEstado tent01(int *m1,int *m2,int *c1,int *c2, int *l,Estado *Espaco){
    printf("Tentativa ------- passar 0 M 1 C \n");
    if(*c1>=1 && *l==1 || *c2>=1 && *l==2 ){
        if(*l==1){

            if(*c2+1<=*m2 || *m2==0){
                *c1-=1;
                *c2+=1;
                *l=2;
                printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);
                return (Novo(m1,c1,m2,c2,1));
            }
        }
        if(*l==2){
            if(*c1+1<=*m1 || *m1==0){
                *c2-=1;
                *c1+=1;
                *l=1;
                printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);
                return (Novo(m1,c1,m2,c2,1));

            }

        }
    }
    printf("negado\n");
    return NULL;

}

FEstado tent02(int *m1,int *m2,int *c1,int *c2, int *l,Estado *Espaco){
    printf("Tentativa ------- passar  0 M 2 C \n");
    if(*c1>=2 && *l==1 || *c2>=2 && *l==2){
        if(*l==1){
            if(*c2+2<=*m2 || *m2 ==0){
                *c1-=2;
                *c2+=2;
                *l=2;
                printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);
                return (Novo(m1,c1,m2,c2,2));
            }
        }
         if(*l==2){
            if(*c1+2<=*m1 || *m1==0){
                *c2-=2;
                *c1+=2;
                *l=1;
                printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);
                return Novo(m1,m2,c1,c2,2);
            }
        }
    }
        printf("\nNEGADO!\n");
        return NULL;





}
int tent20(int *m1,int *m2,int *c1,int *c2, int *l,Estado *Espaco){

    printf("Tentativa ------- passar 2 M 0C \n");

    if(*m1>=2 && *l==1 || *m2>=2 && *l==2){
        if(*l==1){
            if((*m1-2)==0 ||(*m1-2)>=*c1){
                *m1-=2;
                *m2+=2;
                *l=2;
                printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);
                return Novo(m1,c1,m2,c2,20);
            }
        }
        if(*l==2){
            if(*m2-2==0 ||*m2-2>=c2){
                *m2-=2;
                *m1+=2;
                *l=1;
                printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);
                return Novo(m1,c1,m2,c2,20);
            }
        }
    }
        printf("\nNEGADO!\n");
        return NULL;
}
int TestaEstados(int *m1,int *m2,int *c1,int *c2,int *l,Estado *Espaco ){
        if(*c2==3 && *m2==3){
            return 0;
        }
        if(Espaco==NULL){
           return 0;
        }

     Estado *aux;
     printf("\nESTADO ATUAL - Lado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);


        Espaco->T11=tent11(m1,c1,m2,c2,l);
        if(Espaco->T11!=NULL)
            aux=Espaco->T11;
            if(Espaco->verific!=11)
                TestaEstados(m1,m2,c1,c2,l,Espaco->T11);

        Espaco->T01=tent01(m1,m2,c1,c2,l,Espaco);
            if(Espaco->T01!=NULL)
                aux=Espaco->T01;
                if(aux->verific!=1)
                    TestaEstados(m1,m2,c1,c2,l,Espaco->T01);

        Espaco->T10=tent10(m1,m2,c1,c2,l,Espaco);
            if(Espaco->T10!=NULL)
                aux=Espaco->T10;
                if(aux->verific!=10)
                    TestaEstados(m1,m2,c1,c2,l,Espaco->T10);

        Espaco->T20=tent20(m1,m2,c1,c2,l,Espaco);

            if(Espaco->T20!=NULL)
                aux=Espaco->T20;
                if(aux->verific!=20)
                    TestaEstados(m1,m2,c1,c2,l,Espaco->T20);

        Espaco->T02=tent02(m1,m2,c1,c2,l,Espaco);
            if(Espaco->T02!=NULL)
                aux=Espaco->T02;
                if(aux->verific!=2)
                    TestaEstados(m1,m2,c1,c2,l,Espaco->T02);

        return 0;
}
int main(){


    Estado *Espaco=Novo(3,3,0,0,0);
    int m1=3,m2=0,c1=3,c2=0,l=1;

    printf("start");
    TestaEstados(&m1,&m2,&c1,&c2,&l,Espaco);
    printf("\n\nTravessia concluida!\n");

}

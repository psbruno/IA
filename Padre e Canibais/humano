#include <stdio.h>



int tent11(int *m1,int *m2,int *c1,int *c2, int *l){

    printf("Tentativa ------- passar 1 M 1 C\n");

    if(*l==1){

        *m1-=1, *m2+=1, *c1-=1,*c2+=1;

        *l=2;

    }else{

        *m2-=1, *m1+=1, *c2-=1,*c1+=1;

        *l=1;

    }

    printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);



    return 1;

}

int tent20(int *m1,int *m2,int *c1,int *c2, int *l){

    printf("Tentativa ------- passar 2 M 0C \n");

    if(*l==1){

        if((*m1-2)==0 ||(*m1-2)>=*c1){

            *m1-=2;

            *m2+=2;

            *l=2;

            printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);

            return 0;

        }

    }

    if(*l==2){

        if(*m2-2==0 ||*m2-2>=c2){

            *m2-=2;

            *m1+=2;

            *l=1;

            printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);

            return 0;

        }

    }



    printf("\nNEGADO!\n");



}

int tent02(int *m1,int *m2,int *c1,int *c2, int *l){

    printf("Tentativa ------- passar  0 M 2 C \n");

    if(*l==1){

        if(*c2+2<=*m2 || *m2 ==0){

            *c1-=2;

            *c2+=2;

            *l=2;

            printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);

            return 0;

        }

    }

     if(*l==2){

        if(*c1+2<=*m1 || *m1==0){

            *c2-=2;

            *c1+=2;

            *l=1;

            printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);

            return 0;

        }

    }

    printf("\nNEGADO!\n");



}

int tent10(int *m1,int *m2,int *c1,int *c2, int *l){

    printf("Tentativa ------- passar 1 M 0 C \n");

    if(*l==1){

       if(*m1-1==0 ||*m1-1>=c1){

           *m1-=1;

           *m2+=1;

            *l=2;

           printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);

           return 0;

       }

    }

    if(*l==2){

        if(*m2-1==0 ||*m2-1>=c2){

            *m2-=1;

            *m1+=1;

            *l=1;

            printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);

            return 0;

        }

    }



    printf("\nNEGADO!\n");

}

int tent01(int *m1,int *m2,int *c1,int *c2, int *l){

    printf("Tentativa ------- passar 0 M 1 C \n");

    if(*l==1){

        if(*c2+1<=*m2 || *m2==0){

            *c1-=1;

            *c2+=1;

            *l=2;

            printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);

            return 0;

        }

    }

    if(*l==2){

        if(*c1+1<=*m1 || *m1==0){

            *c2-=1;

            *c1+=1;

            *l=1;

            printf("Aceito!\nLado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", *m1,*c1,*m2,*c2, *l);

            return 0;

        }

    }
    printf("\nNEGADO!\n");
}

int main(){
    int m1=3,m2=0,c1=3,c2=0,l=1;
    while((m2 && c2)!=3){
        printf("\nESTADO ATUAL - Lado 1 - %d Missionarios, %d Canibais; Lado 2 - %d Missionarios, %d Canibais (lado atual - %d)\n", m1,c1,m2,c2, l);
        if(m1==c1)
            tent11(&m1,&m2,&c1,&c2,&l);
        if(m2==3 && c2==3){
            break;
        }
        if(m1>=2 && l==1 || m2>=2 && l==2){
            tent20(&m1,&m2,&c1,&c2,&l);
        }
        if(m2==3 && c2==3){
            break;
        }
        if(c1>=2 && l==1 || c2>=2 && l==2){
            tent02(&m1,&m2,&c1,&c2,&l);
        }if(m2==3 && c2==3){
            break;
        }
        if(c1>=1 && l==1 || c2>=1 && l==2 ){
            tent01(&m1,&m2,&c1,&c2,&l);
        }if(m2==3 && c2==3){
            break;
        }
        if(m1>=1 && l==1 || m2>=1 && l==2 ) {
            tent10(&m1, &m2, &c1, &c2, &l);
        }
    }

    printf("\n\nTravessia concluida!\n");

    return 0;
}

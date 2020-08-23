#include <stdio.h>
#include <stdlib.h>
void ki(int *co, int *r,int nbits){
    int i;
    for(i=0;i<nbits;i++){
        if(co[i]==r[i])
            co[i]=0;
        else
            co[i]=1;
    }


}
int *crossing(int *c1,int *c2, int poscorte,int nbits){
    int i;
    int *co=(int*)malloc(nbits*sizeof(int));
    for(i=0;i<poscorte;i++)
        co[i]=c1[i];
    for(i=poscorte;i<nbits;i++)
        co[i]=c2[i];
    return co;

}

float pm(int *co,float probm,int nbits){
    int i=0;
    float *pmx=(float*)malloc(nbits*sizeof(float));
    float pm;

    for(i=0;i<nbits;i++){
        if(co[i]==0)
            pmx[i]=1-probm;
        else
            pmx[i]=probm;
    }
    pm=pmx[0];
    for(i=1;i<nbits;i++){
        pm=pm*pmx[i];
    }
    return pm;
}
void le(int *c1,int *c2,int *r,int nbits){
    char *aux=(char*)malloc(nbits*sizeof(char));
    int i;
    scanf("%s", aux);
    for(i=0;i<nbits;i++){
        if(aux[i]=='1')
            c1[i]=1;
        else
            c1[i]=0;
    }
    scanf("%s", aux);
    for(i=0;i<nbits;i++){
        if(aux[i]=='1')
            c2[i]=1;
        else
            c2[i]=0;
    }
    scanf("%s", aux);
    for(i=0;i<nbits;i++){
        if(aux[i]=='1')
            r[i]=1;
        else
            r[i]=0;
    }
    /*printf("\n\n\ncromossomos 1 e 2\n\n");
    imp(c1,c2,nbits);
    printf("\n\n\ncromossomo resposta\n\n");
    imp(r,r,nbits);
    printf("\n\n");*/

}
void ag (int *c1, int *c2,int *r){
    int i,j,nbits,poscorte,*co1,*co2;
    float probm,pm1,pm2;
    scanf("%d %d %f", &nbits, &poscorte,&probm);



    c1=(int*)malloc(nbits*sizeof(int));
    c2=(int*)malloc(nbits*sizeof(int));
    r=(int*)malloc(nbits*sizeof(int));
    le(c1,c2,r,nbits);

   /*for(i=0;i<nbits;i++)
        scanf("%d", &c1[i]);

    for(i=0;i<nbits;i++)
        scanf("%d", &c2[i]);

    for(i=0;i<nbits;i++)
        scanf("%d", &r[i]);*/

    co1=crossing(c1,c2,poscorte,nbits);
    co2=crossing(c2,c1,poscorte,nbits);

    ki(co1,r,nbits);
    ki(co2,r,nbits);
    //printf("\nIndividuos 1 e 2\n");
    //imp(c1,c2,nbits);

    //printf("\nCROSSING :\n");
    //imp(co1,co2,nbits);

   // printf("\nVetor Mutacao 1 e 2\n");
    //imp(co1,co2,nbits);
    pm1=pm(co1,probm,nbits);
    pm2=pm(co2,probm,nbits);

    //printf("\n%.7f %.7f\n",pm1,pm2);
    pm1=pm2+pm1-(pm2*pm1);
    printf("%.7f\n",pm1);
    free(co1);
    free(co2);
}
void imp(int *c1,int *c2,int n){
    int i;
        for(i=0;i<n;i++)
        printf("%d ", c1[i]);
    printf("\n");

    for(i=0;i<n;i++)
        printf("%d ", c2[i]);
}
int main(){
    int *c1,*c2,*r;
    int i,n,j;
    scanf("%d", &j);

    for(i=0;i<j;i++){
        ag(c1,c2,r);
        free(c1);
        free(c2);
        free(r);
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
    char species[10];
    int treino_teste;//1 == treino, 0 == teste
    float distE;
    float distM;
}TConjunto;

void setadados(TConjunto *Dados){
    FILE *iris;
    iris = fopen("iris.txt", "r");
    char texto[50];
    int i=0;
     while(!feof(iris)){
        fscanf(iris, "%f",&Dados[i].sepal_length);
        fscanf(iris, "%f",&Dados[i].sepal_width);
        fscanf(iris, "%f",&Dados[i].petal_length);
        fscanf(iris, "%f",&Dados[i].petal_width);
        fscanf(iris, "%s",&Dados[i].species);
        Dados[i].treino_teste=0;
        Dados[i].distE=0;
        Dados[i].distM=0;
        i++;
    }
    fclose(iris);
    return;
}
int verific(int aux, int Indice[]){
    int i;



    for(int i=0;i<45;i++){
        if(aux==Indice[i]){
            return 0;
        }

    }
    return 1;
}

float DE(TConjunto *Dados, int Novo, int CC){//classe conhecida
    //p1 = parenteses 1, parenteses 2....
    float p1=(Dados[CC].sepal_length - Dados[Novo].sepal_length)*(Dados[CC].sepal_length - Dados[Novo].sepal_length);
    float p2=(Dados[CC].sepal_width - Dados[Novo].sepal_width)*(Dados[CC].sepal_width - Dados[Novo].sepal_width);
    float p3=(Dados[CC].petal_length - Dados[Novo].petal_length)*(Dados[CC].petal_length - Dados[Novo].petal_length);
    float p4=(Dados[CC].petal_width - Dados[Novo].petal_width)*(Dados[CC].petal_width - Dados[Novo].petal_width);
    float raiz=sqrt(p1+p2+p3+p4);
    return raiz;
}
float DM(TConjunto *Dados, int CC,int Novo){
    return (Dados[CC].sepal_length + Dados[Novo].sepal_length + Dados[CC].sepal_width + Dados[Novo].sepal_width + Dados[CC].petal_length + Dados[Novo].petal_length + Dados[CC].petal_width + Dados[Novo].petal_width);
}
void KNN(TConjunto *Dados,int i,int aux,int k){
    int x=0,j;
    printf("Indice do elemento que vai ser inserido  %d: \n", i);
    printf("atributos: %.1f    %.1f    %.1f    %.1f\n\n", Dados[i].sepal_length,Dados[i].sepal_width,Dados[i].petal_length,Dados[i].petal_width);
    for(j=0;j<150;j++){
        if(Dados[j].treino_teste==1){
            Dados[j].distE=DE(Dados,i,j);
            Dados[j].distM=DM(Dados,i,j);
            printf("%d) Elemento %d\n",x+1, j);
            x++;
            printf("atributos:    %.1f    %.1f    %.1f    %.1f Especie: %s\n", Dados[j].sepal_length,Dados[j].sepal_width,Dados[j].petal_length,Dados[j].petal_width,Dados[j].species);
            printf("dist. euclidiana entre os elementos %d e %d: %f ; dist. de manhattan : %f\n\n",i,j,Dados[j].distE,Dados[j].distM);
        }
    }
    if(aux==1)
        Euc(Dados,k,i);
    else if(aux==2)
        Man(Dados,k,i);
}

void Euc(TConjunto *Dados,int k,int i){
    int aux=0,kNear[k];
    while(Dados[aux].treino_teste!=1)
        aux++;
    int aux2=aux;
    printf("\n\n\n\n");
    for(int i=0;i<k;i++){
        aux=aux2;
        for(int j=0;j<150;j++){
            if(Dados[j].treino_teste==1 && Dados[aux].distE>Dados[j].distE){
                aux=j;
            }
        }
        printf("%d vizinho mais proximo: %d  distancia: %.5f; especie: %s\n",i+1,aux, Dados[aux].distE,Dados[aux].species);
        kNear[i]=aux;
        Dados[aux].distE=100000;
    }
    int esp[3]={0};
    for(i=0;i<k;i++){
        if(strcmp("setosa",Dados[kNear[i]].species)==0)
            esp[0]++;
        else if(strcmp("versicolor",Dados[kNear[i]].species)==0)
            esp[1]++;
        else if(strcmp("virginica",Dados[kNear[i]].species)==0)
            esp[2]++;
    }
    if(esp[0]>esp[1] && esp[0]> esp[2])
        printf("Especie segundo a busca euclidiana: Setosa");
    else if(esp[1]>esp[0] && esp[1]> esp[2])
        printf("Especie segundo a busca euclidiana: versicolor");
    else if(esp[2]>esp[1] && esp[0]< esp[2])
        printf("Especie segundo a busca euclidiana: virginica");
    printf("\n");
}
void Man(TConjunto *Dados,int k, int i){
int aux=0,kNear[k];
    while(Dados[aux].treino_teste!=1)
        aux++;
    int aux2=aux;
    printf("\n\n\n\n");
    for(int i=0;i<k;i++){
        aux=aux2;
        for(int j=0;j<150;j++){
            if(Dados[j].treino_teste==1 && Dados[aux].distM>Dados[j].distM){
                aux=j;
            }
        }
        printf("%d vizinho mais proximo: %d  distancia: %.5f; especie: %s\n",i+1,aux, Dados[aux].distM,Dados[aux].species);
        kNear[i]=aux;
        Dados[aux].distM=100000;
    }
    int esp[3]={0};
    for(i=0;i<k;i++){
        if(strcmp("setosa",Dados[kNear[i]].species)==0)
            esp[0]++;
        else if(strcmp("versicolor",Dados[kNear[i]].species)==0)
            esp[1]++;
        else if(strcmp("virginica",Dados[kNear[i]].species)==0)
            esp[2]++;
    }
    if(esp[0]>esp[1] && esp[0]> esp[2])
        printf("Especie segundo a busca de Manhattan : Setosa");
    else if(esp[1]>esp[0] && esp[1]> esp[2])
        printf("Especie segundo a busca de Manhattan: versicolor");
    else if(esp[2]>esp[1] && esp[0]< esp[2])
        printf("Especie segundo a busca de Manhattan: virginica");
    printf("\n");


}

int main(){
    TConjunto *Dados=(TConjunto*)malloc(150*sizeof(TConjunto));
    setadados(Dados);
    int Indices[105]={0};
    int i=0,aux,k;
    for (i = 0; i < 105; i++)
        Indices[i]=0;

    for (i = 0; i < 45; i++){
        aux=(rand() % 150);
        while(verific(aux,Indices)==0)
            aux=(rand() % 150);
        Indices[i]=aux;
        Dados[aux].treino_teste++;
    }


    int j=1;
    printf("70% ( == 105) dos elementos que vao ser inseridos:\n");
    for(i=0;i<150;i++){
           if(Dados[i].treino_teste==0){
                printf("Elemento %d (%d) : s.l = %.1f  s.w.=  %.1f  p.l = %.1f p.w. = %.1f  \n",j,i, Dados[i].sepal_length,Dados[i].sepal_width,Dados[i].petal_length,Dados[i].petal_width);
            j++;
           }

    }


    printf("insira k\n");
    scanf("%d", &k);
    printf("insira 1 para mostrar os k vizinhos mais proximos por distancia euclidiana, 2 por distancia de manhattam\n");
    scanf("%d", &aux);
    int x,cont=0;

    for(i=0;i<150;i++){
        if(Dados[i].treino_teste==0){
            printf("------------------->Insercao %d\n", cont+1);
            cont++;
            KNN(Dados,i,aux,k);
            printf("________________________________________________________________\n\n\n");

            printf("insira qqr valor pra continuar\n");
            scanf("%d",&x);
            system("cls");
        }

    }



    return 0;
}

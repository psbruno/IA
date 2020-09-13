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
}TConjunto;

void atribui(TConjunto *Dados){
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
        i++;
    }
    fclose(iris);
    return;
}
int verific(int aux, int Indice[]){
    int i;



    for(int i=0;i<105;i++){
        if(aux==Indice[i]){
            return 0;
        }

    }
    return 1;
}
void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j]= vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}
int main(){
    TConjunto *Dados=(TConjunto*)malloc(150*sizeof(TConjunto));
    atribui(Dados);
    int Indices[105]={0};
    int i=0,aux;
    for (i = 0; i < 105; i++)
        Indices[i]=0;

    for (i = 0; i < 105; i++){
        aux=(rand() % 150);
        while(verific(aux,Indices)==0)
            aux=(rand() % 150);
        Indices[i]= aux;
    }


    bubble_sort(Indices,105);

    for (i = 0; i < 105; i++)
        printf("%d ", Indices[i]);
    printf("\n");
    for(i=0;i<150;i++)
        printf("    %.1f    %.1f    %.1f    %.1f    %s \n", Dados[i].sepal_length,Dados[i].sepal_width,Dados[i].petal_length,Dados[i].sepal_width,Dados[i].species);

}

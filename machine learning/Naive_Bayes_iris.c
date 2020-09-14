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

typedef struct{
    int inter1[2];
    int inter2[2];
    int inter3[2];
    int total;
}NaiveBayes;//struct para contar os intervalos

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
int **pl(TConjunto *Dados,int Indices[], int *qtde){
    int i,j;
    int **dados;
    dados=(int**)malloc(3*sizeof(int*));

    for(i=0;i<3;i++)
        dados[i]=(int*)malloc(3*sizeof(int));

    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            dados[i][j]=0;
    }
    int x;

    for(i=0;i<45;i++){
        printf("   indice %d    pl %.1f  spe  %s \n",Indices[i],Dados[Indices[i]].petal_length,Dados[Indices[i]].species);
        if(Dados[Indices[i]].petal_length<=2 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][0]++;
        else if(Dados[Indices[i]].petal_length>2 && Dados[Indices[i]].petal_length<=4 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][1]++;
        else if(Dados[Indices[i]].petal_length>4 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][2]++;
        else if(Dados[Indices[i]].petal_length<=2 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][0]++;
        else if(Dados[Indices[i]].petal_length>2 && Dados[Indices[i]].petal_length<=4 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][1]++;
        else if(Dados[Indices[i]].petal_length>4 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][2]++;
        else if(Dados[Indices[i]].petal_length<=2 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][0]++;
        else if(Dados[Indices[i]].petal_length>2 && Dados[Indices[i]].petal_length<=4 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][1]++;
        else if(Dados[Indices[i]].petal_length>4 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][2]++;
        *qtde=*qtde+1;
    }
    printf("\n");


    return dados;
}
int **sl(TConjunto *Dados,int Indices[],int *qtde){
    int i,j;
    int **dados;
    dados=(int**)malloc(3*sizeof(int*));

    for(i=0;i<3;i++)
        dados[i]=(int*)malloc(2*sizeof(int));

    for(i=0;i<3;i++){
        for(j=0;j<2;j++)
            dados[i][j]=0;
    }
    int x;

    for(i=0;i<45;i++){
        printf("   indice %d    sl %.1f   spe  %s \n",Indices[i], Dados[Indices[i]].sepal_length,Dados[Indices[i]].species);
        if(Dados[Indices[i]].sepal_length<=6 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][0]++;
        else if(Dados[Indices[i]].sepal_length>6 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][1]++;
        else if(Dados[Indices[i]].sepal_length<=6 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][0]++;
        else if(Dados[Indices[i]].sepal_length>6 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][1]++;
        else if(Dados[Indices[i]].sepal_length<=6 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][0]++;
        else if(Dados[Indices[i]].sepal_length>6 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][1]++;
        *qtde=*qtde+1;

    }
    printf("\n");


    return dados;
}
int **pw(TConjunto *Dados,int Indices[], int *qtde){
    int i,j;
    int **dados;
    dados=(int**)malloc(3*sizeof(int*));

    for(i=0;i<3;i++)
        dados[i]=(int*)malloc(3*sizeof(int));

    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            dados[i][j]=0;
    }
    int x;

    for(i=0;i<45;i++){
        printf("   indice %d    pl %.1f  spe  %s \n",Indices[i],Dados[Indices[i]].petal_width,Dados[Indices[i]].species);
        if(Dados[Indices[i]].petal_width<=1 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][0]++;
        else if(Dados[Indices[i]].petal_width>1 && Dados[Indices[i]].petal_width<=2 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][1]++;
        else if(Dados[Indices[i]].petal_width>2 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][2]++;
        else if(Dados[Indices[i]].petal_width<=1 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][0]++;
        else if(Dados[Indices[i]].petal_width>1 && Dados[Indices[i]].petal_width<=2 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][1]++;
        else if(Dados[Indices[i]].petal_width>2 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][2]++;
        else if(Dados[Indices[i]].petal_width<=1 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][0]++;
        else if(Dados[Indices[i]].petal_width>1 && Dados[Indices[i]].petal_width<=2 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][1]++;
        else if(Dados[Indices[i]].petal_width>2 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][2]++;

    }
    printf("\n");


    return dados;

}
int **sw(TConjunto *Dados,int Indices[],int *qtde){
    int i,j;
    int **dados;
    dados=(int**)malloc(3*sizeof(int*));

    for(i=0;i<3;i++)
        dados[i]=(int*)malloc(2*sizeof(int));

    for(i=0;i<3;i++){
        for(j=0;j<2;j++)
            dados[i][j]=0;
    }
    int x;

    for(i=0;i<45;i++){
        printf("%d   indice %d    sl %.1f   spe  %s \n",i,Indices[i], Dados[Indices[i]].sepal_width,Dados[Indices[i]].species);
        if(Dados[Indices[i]].sepal_width<=2 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][0]++;
        else if(Dados[Indices[i]].sepal_width>2 && strcmp(Dados[Indices[i]].species, "setosa")==0)
            dados[0][1]++;
        else if(Dados[Indices[i]].sepal_width<=2 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][0]++;
        else if(Dados[Indices[i]].sepal_width>2 && strcmp(Dados[Indices[i]].species, "versicolor")==0)
            dados[1][1]++;
        else if(Dados[Indices[i]].sepal_width<=2 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][0]++;
        else if(Dados[Indices[i]].sepal_length>2 && strcmp(Dados[Indices[i]].species, "virginica")==0)
            dados[2][1]++;
        *qtde=*qtde+1;


    }
    printf("\n");


    return dados;

}
void teorema(int **NBpl,int **NBpw,int **NBsl,int **NBsw,TConjunto *Dados,int Indices[],int i){
    printf("%d   sl  %.1f   sw %.1f   pl %.1f    pw %.1f   \n",i+1, Dados[i].sepal_length,Dados[i].sepal_width,Dados[i].petal_length,Dados[i].petal_width);
    int prod[3][4];//

    for(int j=0;j<3;j++){
        for(int x=0;x<3;x++)
            prod[j][x]=1;
    }



    if(Dados[i].sepal_length<=6){
            prod[0][0]=1000*(NBsl[0][0])/(NBsl[0][0]+NBsl[0][1]);
            prod[1][0]=1000*NBsl[1][0]/(NBsl[1][0]+NBsl[1][1]);
            prod[2][0]=1000*NBsl[1][0]/(NBsl[2][0]+NBsl[2][1]);
        }else if(Dados[i].sepal_length>6){
            prod[0][0]=1000*NBsl[0][1]/NBsl[0][0]+NBsl[0][1];
            prod[1][0]=1000*NBsl[1][1]/(NBsl[1][0]+NBsl[1][1]);
            prod[2][0]=1000*NBsl[1][1]/(NBsl[2][0]+NBsl[2][1]);
        }

        if(Dados[i].sepal_width<=2){
            prod[0][1]=1000*NBsw[0][0]/(NBsw[0][0]+NBsw[0][1]);
            prod[1][1]=1000*NBsw[1][0]/(NBsw[1][0]+NBsw[2][1]);
            prod[2][1]=1000*NBsw[2][0]/(NBsw[2][0]+NBsw[2][1]);
        }else if(Dados[i].sepal_width>2){
            prod[0][1]=1000*NBsw[0][1]/(NBsw[0][0]+NBsw[0][1]);
            prod[1][1]=1000*NBsw[1][1]/(NBsw[1][0]+NBsw[1][1]);
            prod[2][1]=1000*NBsw[2][1]/(NBsw[2][0]+NBsw[2][1]);
        }

        if(Dados[i].petal_width<=1){
            prod[0][2]=1000*NBpw[0][0]/(NBpw[0][0]+NBpw[0][1]+NBpw[0][2]);
            prod[1][2]=1000*NBpw[1][0]/(NBpw[1][0]+NBpw[1][1]+NBpw[1][2]);
            prod[2][2]=1000*NBpw[2][0]/(NBpw[2][0]+NBpw[2][1]+NBpw[2][2]);
        }else if(Dados[i].petal_width>1){
            prod[0][2]=1000*NBpw[0][1]/(NBpw[0][0]+NBpw[0][1]+NBpw[0][2]);
            prod[1][2]=1000*NBpw[1][1]/(NBpw[1][0]+NBpw[1][1]+NBpw[1][2]);
            prod[2][2]=1000*NBpw[2][1]/(NBpw[2][0]+NBpw[2][1]+NBpw[2][2]);
        }else if(Dados[i].petal_width>2){
            prod[0][2]=1000*NBpw[0][2]/(NBpw[0][0]+NBpw[0][1]+NBpw[0][2]);
            prod[1][2]=1000*NBpw[1][2]/(NBpw[1][0]+NBpw[1][1]+NBpw[1][2]);
            prod[2][2]=1000*NBpw[2][2]/(NBpw[2][0]+NBpw[2][1]+NBpw[2][2]);
        }

        if(Dados[i].petal_length<=2){
            prod[0][3]=1000*NBpl[0][0]/(NBpl[0][0]+=NBpl[0][1]+NBpl[0][1]);
            prod[1][3]=1000*NBpl[1][0]/(NBpl[1][0]+=NBpl[1][1]+NBpl[1][1]);
            prod[2][3]=1000*NBpl[2][0]/(NBpl[2][0]+=NBpl[2][1]+NBpl[2][1]);
        }else if(Dados[i].petal_length>2){
            prod[0][3]=1000*NBpl[0][1]/(NBpl[0][0]+=NBpl[0][1]+NBpl[0][1]);
            prod[1][3]=1000*NBpl[1][1]/(NBpl[1][0]+=NBpl[1][1]+NBpl[1][1]);
            prod[2][3]=1000*NBpl[2][1]/(NBpl[2][0]+=NBpl[2][1]+NBpl[2][1]);
        }else if(Dados[i].petal_length>4){
            prod[0][3]=1000*NBpl[0][1]/(NBpl[0][0]+=NBpl[0][1]+NBpl[0][1]);
            prod[1][3]=1000*NBpl[1][1]/(NBpl[1][0]+=NBpl[1][1]+NBpl[1][1]);
            prod[2][3]=1000*NBpl[2][1]/(NBpl[2][0]+=NBpl[2][1]+NBpl[2][1]);
        }



    int a=1000*(prod[0][0]*prod[0][1]*prod[0][2]*prod[0][3]/((NBsl[0][0]+NBsl[0][1])* (NBsw[0][0]+NBsw[0][1])*(NBpw[0][0]+NBpw[0][1]+NBpw[0][2])*(NBpl[0][0]+=NBpl[0][1]+NBpl[0][1])));
    int b=1000*(prod[1][0]*prod[1][1]*prod[1][2]*prod[1][3]/((NBsl[1][0]+NBsl[1][1])* (NBsw[1][0]+NBsw[1][1])*(NBpw[1][0]+NBpw[1][1]+NBpw[1][2])*(NBpl[1][0]+=NBpl[1][1]+NBpl[1][1])));
    int c=1000*(prod[2][0]*prod[2][1]*prod[2][2]*prod[2][3]/((NBsl[0][0]+NBsl[2][1])* (NBsw[2][0]+NBsw[2][1])*(NBpw[2][0]+NBpw[2][1]+NBpw[2][2])*(NBpl[2][0]+=NBpl[2][1]+NBpl[2][1])));


    if(a>b && a>c)
        printf("especie: Setosa\n");
    else if(a<b && b>c)
        printf("especie: Versicolor\n");
    else if(c>b && b<c)
        printf("especie: Virginica\n");

}
int main(){
    TConjunto *Dados=(TConjunto*)malloc(150*sizeof(TConjunto));
    setadados(Dados);
    int Indices[105]={0};
    int i=0,aux;
    for (i = 0; i < 105; i++)
        Indices[i]=0;

      for (i = 0; i < 45; i++){
        aux=(rand() % 150);
        while(verific(aux,Indices)==0)
            aux=(rand() % 150);
        Indices[i]=aux;
        Dados[aux].treino_teste++;
    }


    //bubble_sort(Indices,105);


    //for(i=0;i<150;i++)
      //  printf("    %.1f    %.1f    %.1f    %.1f    %s \n", Dados[i].sepal_length,Dados[i].sepal_width,Dados[i].petal_length,Dados[i].petal_width,Dados[i].species);
int j;
    int qsl=0,qsw=0,qpl=0,qpw=0;
    int **NBsl=sl(Dados,Indices,&qsl);


    int **NBsw=sw(Dados,Indices,&qsw);

    int **NBpl=pl(Dados,Indices,&qpl);

    int **NBpw=pw(Dados,Indices,&qpw);
    printf("insira qualquer valor para a impressão das tabelas\n");
    scanf("%d", &j);
    system("cls");
    printf("Tabela sepal_length, aplicando laplace\n");
     for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("%d ",NBsl[i][j]);
            NBsl[i][j]=NBsl[i][j]+1;
            }
        printf("\n");
    }
    printf("Tabela sepal_width, aplicando laplace\n");
     for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("%d ",NBsw[i][j]);
            NBsw[i][j]=NBsw[i][j]+1;
        }
        printf("\n");
    }


    printf("Tabela petal_length, aplicando laplace\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",NBpl[i][j]);
            NBpl[i][j]=NBpl[i][j]+1;
        }
        printf("\n");
    }


    printf("Tabela petal_width, aplicando laplace\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",NBpw[i][j]);
            NBpw[i][j]=NBpw[i][j]+1;
        }
        printf("\n");
    }
    for(i=0;i<150;i++){
     if(Dados[i].treino_teste==0)
        teorema(NBpl,NBpw,NBsl,NBsw,Dados,Indices,i);
    }
}

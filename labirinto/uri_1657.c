#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int erro1(char *maior, char *menor){//letra a mais ou a menos
    int i,j=0,r=0;
    if(strlen(maior)-strlen(menor)>1){
        return 0;
    }

    for(i=0;i<strlen(maior);i++){

        if(maior[i]!=menor[j]){
            r++;
            j--;
        }
        if(r>1)
            return 0;
        j++;
    }



    return 1;

}

int adj(char *palavra, char *palavra2){

    int i=0,j=0;
    for(i=0;i<strlen(palavra);i++){
        if(palavra[i]!=palavra2[i]){
            if(j==1)
                return 0;
            if(palavra[i]==palavra2[i+1] && palavra2[i]==palavra[i+1])
                i++;
            j++;
        }
    }

    return 1;
}
int iscorrect(char *palavra,char *palavra2){//caso 1: verificar se as duas palavras sao iguais
    if(strlen(palavra2)-strlen(palavra)!=0){
        return 0;
    }
    for(int i=0;i<strlen(palavra2);i++){
        if(palavra2[i]!=palavra[i])
            return 0;
    }
    return 1;
}
int misspelling(char *palavra,char *palavra2){//caso 2: procurar se tem erro ortografico
    int caso2=0;

    if(strlen(palavra2)-strlen(palavra)!=0 && strlen(palavra2)-strlen(palavra)!=1  && strlen(palavra2)-strlen(palavra)!=-1){
        return 0;
    }

         //printf("-------- %s %s %d\n",palavra, palavra2,strlen(palavra2)-strlen(palavra));


    if(strlen(palavra2)-strlen(palavra)==0)
        caso2=adj(palavra2,palavra);
    else
        if(strlen(palavra)>strlen(palavra2))
            caso2=erro1(palavra,palavra2);
        else
            caso2=erro1(palavra2,palavra);

    if(caso2==1)
        return 2;

    return 0;

}



int main(){
    int N,i;
    char **palavra;

    scanf("%d", &N);

    palavra=(char**)malloc(25*sizeof(char*));
    for(i=0;i<N;i++){
        palavra[i]=(char*)malloc(sizeof(char));
    }

    for(i=0;i<N;i++)
        scanf("%s", palavra[i]);



    int Q;
    scanf("%d", &Q);
    char *palavra2;//=(char*)malloc(25*sizeof(char));
    int j;
    int r;
    int output;
    for(i=0;i<Q;i++){
        palavra2=(char*)malloc(25*sizeof(char));
        scanf("%s", palavra2);
        for(int j=0;j<N;j++){
            //printf("palavras: %s %s\n", palavra[j],palavra2);
            output=iscorrect(palavra[j],palavra2);
            if(output==1){
                printf("%s is correct\n", palavra2);
                /*printf("caso1 - iguais\n");
                 printf("palavras: %s %s\n\n\n", palavra[j],palavra2);*/
                break;
            }
            else
                output=misspelling(palavra[j],palavra2);

            if(output==2){
                printf("%s is a misspelling of %s\n", palavra2,palavra[j]);
                /*printf("caso2 - erro de 1 caracter\n");
                printf("palavras: %s %s\n\n\n", palavra[j],palavra2);*/
                break;
            }
            else if(j+1==N){
                printf("%s is unknown\n", palavra2);
                /*printf("caso3 dois ou mais chars diff\n");
                printf("palavras: %s %s\n\n\n", palavra[j],palavra2);*/
                break;
            }

        }
        free(palavra2);

    }
    return 0;
}

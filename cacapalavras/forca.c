#include <stdio.h>
#include <stdlib.h>
#include "forca.h"
#include <string.h>


struct noSecreto {
int status;
char palavra[31];
char assunto [255];
struct noSecreto * prox;
};

NoSecreto * inicializaListaSecreta()
{
    return NULL;
}

NoSecreto * carregaListaArquivo(NoSecreto * l,char nomeArq [255])
{
    int status=0;
    char palavra[31];
    char assunto [255];


    FILE * fWords;
    fWords = fopen(nomeArq,"r");
    if (fWords == NULL)
    {
      printf("Falha ao acessar base de dados!!! \n\n");
      exit(0);
    }
    while (!feof(fWords))
    {
            fscanf(fWords,"%30[^- ]",palavra);
    fscanf(fWords,"%99[^-\n]",assunto);

    fscanf(fWords, "%*[-\n]");
        l = inserePalavraSecreta(l,palavra,assunto);
    }
     fclose(fWords);
    return  l;
}

NoSecreto * inserePalavraSecreta(NoSecreto *l,char word[31],char subject[100])
{

 NoSecreto * novo;
 novo = (NoSecreto *) malloc(sizeof(NoSecreto));
 strcpy(novo->assunto,subject);
 strcpy(novo->palavra,word);
 novo->status=0;
 novo->prox = l;
 l=novo;
 return l;

}

void impimeListaSecreta(NoSecreto *l)
{
    for (NoSecreto * p=l;p!=NULL;p=p->prox)
    {
        printf("%0d | %5s | %5s |\n",p->status,p->palavra,p->assunto);
    }

}







#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forca.h"
void exibe()
{
    printf("Desenvolvido por:\n Victor Hugo da Silva Lima 18153 e Gustavo de Araujo Poffo 18132\n\n");

}

int main()
{
    char nome[20];
    printf("Digite seu nome:\n");
    gets(nome);

    char aux;
    int help = 0;
    int a = 0;
    int b = 0;
    int n = 0;
    int cont = 0;
    char letra;
do{
     system("cls");
     printf("Bem vindo ao jogo %s\n",nome);
     printf("Jogar - 1\n");
     printf("Sair - 0\n");
     printf("Configuracoes - 2\n");
     scanf("%d",&a);
    fflush(stdin);
      if(a == 1)
      {
       b = 0;
    exibe();
    int x;
    NoSecreto * lstSecreta = inicializaListaSecreta();
    NoSecreto * sorteada;
    char  aux1[31];
    NoSecreto * usadas = inicializaListaSecreta();
    lstSecreta = carregaListaArquivo(lstSecreta,"palavras.dat");
    imprimeListaSecreta(lstSecreta);

      do{
        cont = 0;
        system("cls");



        sorteada= sorteiaPalavra(lstSecreta);


        if(sorteada!=NULL){
                strcpy(aux1,sorteada->palavra);
            n = conta(sorteada->palavra);

            for(int i = 0; i<n; i++)
            {
                    sorteada->palavra[i] = '*';
            }
            for(int x = 0; x<n*3; x++){

                    help = 0;
           if(strcmp(aux1,sorteada->palavra) == 0)
                {
                    printf("\nVoce achou a palavra\n");
                    help = 1;
                    break;
                }
                else{
                        cont= cont+1;
            exibe();
            printf("%s\n", sorteada->palavra);

            printf("Digite uma letra:\n");

            scanf("%c",&letra);

            system("cls");

            fflush(stdin);

            for(int i = 0; i<n; i++)
                {
                if(aux1[i] == letra)
                {
                    sorteada->palavra[i] = aux1[i];
                }

            }
                }
            }
            if(help == 1)
            {
            system("cls");
            printf("\nEncontrou a palavra em %d tentaivas\n",cont);
            printf("Escolhendo nova palavra........\n");
            }
            else{
            system("cls");
            printf("\nEsgotou tentativas\n");
            printf("Numero de tentativas: %d\n",cont);
            printf("Escolhendo nova palavra...\n");
            }

            lstSecreta = retiraUmElemento(lstSecreta,sorteada->palavra);
            aux = lstSecreta;
        }
        else{
            printf("Nao existe palavra disponivel!\n\n");
            b = 1;



          }
       }while(getchar()!='f' && b == 0);

      }




}while(a != 0);



    return 0;
}

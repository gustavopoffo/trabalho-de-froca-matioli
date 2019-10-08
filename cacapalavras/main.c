#include <stdio.h>
#include <stdlib.h>
#include "forca.h"



int main()
{
printf("Feito por Gustavo Poffo 18132 e Victor Hugo Da Silva Lima\n\n");
NoSecreto * lstSecreta = inicializaListaSecreta();
lstSecreta = carregaListaArquivo(lstSecreta,"E:\\sugundo ano Matioli\\cacapalavras\\palavras.dat");
impimeListaSecreta(lstSecreta);


return 0;


}

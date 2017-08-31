#include "TypesAluno.h"
#include "AbbAluno.h"

#include <stdio.h>

void carregar(TAbbAluno **raiz, FILE *arq,int *indice);
 
void cadastar(TAbbAluno **raiz, FILE *arq, int *indice);

void alterar(TAbbAluno *raiz, FILE *arq, char mat[]);

void exibir () {}

void remover () {}

int consultar(TAbbAluno *raiz, char mat[]);
#include "AbbAluno.h"

#include <stdlib.h>
#include <string.h>


void inserir(TAbbAluno **raiz, char mat[], int ind) {
	if (*raiz == NULL) {
		*raiz = (TAbbAluno *) malloc (sizeof(TAbbAluno));
		strcpy((*raiz)->matriculaAbb, mat);
		(*raiz)->indice = ind;
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
	}
	else {
		if (strcomp(mat, (*raiz)->matriculaAbb) < 0) {
			inserir(&((*raiz)->esq), mat, ind);
		}
		else {
			inserir(&((*raiz)->dir), mat, ind);

		}
	}
}

void destruir(TAbbAluno **raiz) {
	if (*raiz != NULL) {
		destruir(&(*raiz)->esq);
		destruir(&(*raiz)->dir);
		free(*raiz);
	}
}
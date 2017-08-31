#ifndef ABBALUNO
#define ABBALUNO

#define ABBMT 12

typedef struct AbbAluno {
	char matriculaAbb[ABBMT];
	int indice;
	struct noAluno *esq;
	struct noAluno *dir;

}TAbbAluno;

#endif


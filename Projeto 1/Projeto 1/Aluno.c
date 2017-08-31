#include "Aluno.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void carregar(TAbbAluno **raiz, FILE *arq, int *indice) {
	Taluno aux;
	arq = fopen("Cadastro de Alunos.bin", "r+b");
	if (arq == NULL) {
		printf("\nFalha ao carregar Cadastro de a Alunos.bin");
		printf("\nO Cadastro de Alunos.bin nao foi encontrado ou nao exite");
		printf("\nGerando um novo arquivo");
		arq = fopen("Cadastro de Alunos.bin", "a+b");
		if (arq == NULL) {
			printf("\nFalha ao criar Cadastro de a Alunos.bin");
		}
		else {
			printf("\nCadastro de Alunos.bin criado com sucesso");
		}
	}
	else {
		while (feof(arq) == 0) {
			fread(&aux, sizeof(Taluno), 1, &arq);
			inserir(&(*raiz), aux.matricula, *indice);
			*indice++;
		}
	}
}

void cadastar(TAbbAluno **raiz, FILE *arq, int *indice) {
	Taluno novo = { .matricula = {'\0'},.nome = {'\0'},.email = {'\0'},.telefone = {'\0'},.qtdCad = 0,.regStat = 0};
	int i, flag1, flag2;
	novo.qtdCad = 0;
	// matricula
	printf("\nDigite a matricula, a matricula deve conter nove digitos");
	do {
		fgets(novo.matricula, 9, (stdin));
		flag1 = 0;
		flag2 = 1;
		i = 0;
		while (novo.matricula[i] != '\0') {
			if (novo.matricula[i] < '0' || novo.matricula[i] > '9') {
				flag1 = 1;
				printf("\nMatricula invalida, apenas numeros sao permitidos");
				printf("\nPor favor redigite a matricula");
				break;
			}
			i++;
		}
		if (consultar(*raiz, novo.matricula) == -1) {
			flag2 = 0;
		}
	} while (flag1 || flag2);
	// nome
	printf("\nDigite o nome completo");
	do {
		fgets(novo.nome, ANM, (stdin));
		flag1 = 0;
		i = 0;
		while (novo.nome[i] != '\0') {
			if (novo.nome[i] < 'A' || novo.nome[i] > 'Z') {
				if (novo.nome[i] < 'a' || novo.nome[i] >'z') {
					if (novo.nome[i] != ' ') {
						flag1 = 1;
						printf("\nNome invalido. apenas letras e espaço sao permitidos");
						printf("\nPor favor redigite o nome");
						break;
					}
				}
			}
			i++;
		}
	} while (flag1);



}

void alterar(TAbbAluno *raiz, FILE *arq, char mat[]) {


}

void exibir() {}

void remover() {}

int consultar(TAbbAluno *raiz, char mat[]) {
	while (raiz != NULL) {
		if (strcmp(mat, raiz->matriculaAbb) == 0) {
			return raiz->indice;
		}
		else if (strcmp(mat, raiz->matriculaAbb) < 0) {
			raiz = raiz->esq;
		}
		else {
			raiz = raiz->dir;
		}
	}
	return -1;
}
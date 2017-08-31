#ifndef ALUNO
#define ALUNO

#define AMT 12
#define ANM 101
#define AEM 101
#define ATF 12

typedef struct aluno {
	char matricula[AMT];
	char nome[ANM];
	char email[AEM];
	char telefone[ATF];
	float media;
	int qtdCad;
	int regStat;

}Taluno;

#endif

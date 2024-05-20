/*
1ª Questão: No colégio Minha Escolinha a média de um aluno em uma disciplina é calculada da seguinte
forma: (primeira nota * 2 + segunda nota * 3) / 5. Para se aprovado, o aluno deve ficar com média maior
ou igual a 7. Faça um programa para ler o nome, a primeira e a segunda nota dos alunos de uma turma de
20 alunos, e calcular a média de cada aluno. O programa deve utilizar quatro vetores: um para os nomes,
um para as primeiras notas, um para as segundas notas e um outro para as médias. Para cada aluno, o
programa deverá exibir a seguinte frase: O aluno <nome do aluno> obteve média <média do aluno> e
foi <situação final do aluno>. O programa deverá ainda calcular a média da turma e exibir a quantidade
de alunos cuja média ficou abaixo da média da turma juntamente com o nome de cada um deles.
*/

#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define QTD_ALUNOS 3

struct Aluno {
    char nome[TAM_NOME];
    double nota1, nota2, media;
};

void lerString(char *str, int maxTam);
void lerAlunos(struct Aluno alunos[], int tam);
void lerAluno(struct Aluno *aluno);
double calcularMedias(struct Aluno alunos[], int tam);
void imprimirMediasSituacao(struct Aluno alunos[], int tam);
void imprimirAbaixoMedia(struct Aluno alunos[], int tam, double media);

int main() {
    struct Aluno alunos[QTD_ALUNOS];
    lerAlunos(alunos, QTD_ALUNOS);
    double mediaTurma = calcularMedias(alunos, QTD_ALUNOS);
    printf("\n\nSituacao dos alunos\n");
    imprimirMediasSituacao(alunos, QTD_ALUNOS);
    printf("\n\nA media da turma foi %.2f\n\n", mediaTurma);
    imprimirAbaixoMedia(alunos, QTD_ALUNOS, mediaTurma);
    return 0;
}

void lerAlunos(struct Aluno alunos[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("\nDigitacao das informaoees do aluno %d\n", i + 1);
        lerAluno(&alunos[i]);
        printf("digitado: %s - %.2f - %.2f - %.2f\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].media);
    }
}

void lerAluno(struct Aluno *aluno) {
    char strTmp[TAM_NOME];
    printf("Digite o nome do aluno: ");
    lerString(aluno->nome, TAM_NOME);
    printf("Digite a primeira nota do aluno: ");
    scanf("%lf", &aluno->nota1);
    printf("Digite a segunda nota do aluno: ");
    scanf("%lf", &aluno->nota2);
    lerString(strTmp, TAM_NOME);
}

double calcularMedias(struct Aluno alunos[], int tam) {
    double somaMedias = 0.0;
    for (int i = 0; i < tam; ++i) {
        alunos[i].media = (alunos[i].nota1 * 2 + alunos[i].nota2 * 3) / 5;
        somaMedias += alunos[i].media;
    }
    return somaMedias / tam;
}

void imprimirMediasSituacao(struct Aluno alunos[], int tam) {
    for (int i = 0; i < tam; ++i) {
        // char situacao[11];
        // if (alunos[i].media >= 7.0) {
        //     strcpy(situacao, "aprovado");
        // } else {
        //     strcpy(situacao, "reprovado");
        // }
        printf("O(a) aluno(a) %s obteve media %.2f e foi %s\n",
            alunos[i].nome,
            alunos[i].media,
            alunos[i].media >= 7.0 ? "aprovado" : "reprovado"
        );
    }
}

void imprimirAbaixoMedia(struct Aluno alunos[], int tam, double media) {
    int qtd = 0;
    for (int i = 0; i < tam; ++i) {
        if (alunos[i].media < media) {
            qtd += 1;
            printf("O(a) aluno(a) %s ficou abaixo da média da turma\n", alunos[i].nome);
        }
    }
    printf("\nNo total, %d aluno(s) ficou(aram) abaixo da media da turma\n", qtd);
}

void lerString(char *str, int maxTam) {
    fgets(str, maxTam, stdin);
    int tam = strlen(str);
    if (str[tam - 1] == '\n') {
      str[tam - 1] = '\0';
    }
}
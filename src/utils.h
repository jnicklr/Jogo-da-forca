#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
	char nome[30];
	int pontos;
} JOGADOR;

int verificarAcerto(char letra_escolhida_jogador, char * letras_unicas, char * letras_chutadas){
	
	int acertando_letra = 0;
	
	for (int i = 0; i < strlen(letras_unicas); i++){
		if (letra_escolhida_jogador == letras_unicas[i]){
			acertando_letra = 1;
		}
	}
		
	if (strlen(letras_chutadas) > 0){
		for (int i = 0; i < strlen(letras_chutadas); i++){
			if (letra_escolhida_jogador == letras_chutadas[i]){
				acertando_letra = 0;
			}
		} 
	}
	
	return acertando_letra;
}

void verificarVitoria(int vidas_restantes, int quantidade_acertos, int quantidade_letras_unicas, JOGADOR * jogadores, int contador_jogadores, char palavra_aleatoria[]){
	system("cls");
	printf("----------------------------------\n");
	printf("|         Status do Jogo         |\n");
	printf("----------------------------------\n");
	estagiosBoneco(vidas_restantes);
	printf("----------------------------------\n");
	
	if (vidas_restantes == 0){	
		printf("Ninguém acertou. A palavra era %s.\n", palavra_aleatoria);
	} else {
		jogadores[contador_jogadores].pontos += 1;
		printf("O vencedor da partida é %s. A palavra era %s.\n", jogadores[contador_jogadores].nome, palavra_aleatoria);
	}
	system("pause");
	system("cls");
}

char * preencherArray(int tamanho_array){
	char * array_preenchido;
	
	array_preenchido = (char *)malloc(sizeof(array_preenchido) * (tamanho_array+1));
	memset(array_preenchido, '*', tamanho_array);
	array_preenchido[tamanho_array] = '\0';
	
	return array_preenchido;
}

char * pegarLetrasUnicas(int tamanho_palavra, char * palavra_aleatoria){
	
	char * array_descartavel = preencherArray(tamanho_palavra);
	
	int quantidade_letras = 0;
	int palavra_repetida = 0;
	
	for (int i = 0; i < tamanho_palavra; i++){
		for (int j = 0; j < tamanho_palavra; j++){
			if (array_descartavel[j] == palavra_aleatoria[i]){
				palavra_repetida = 1;
				break;
			}
		}
		if (!palavra_repetida){
			array_descartavel[quantidade_letras] = palavra_aleatoria[i];
			quantidade_letras++;
		}
		palavra_repetida = 0;
	}
	
	char* letras_unicas = (char*)malloc(quantidade_letras + 1);
	strncpy(letras_unicas, array_descartavel, quantidade_letras);
	letras_unicas[quantidade_letras] = '\0';
	
	free(array_descartavel);
	
	return letras_unicas;
}

int verificarFormato(char c) {
    return (c >= 'a' && c <= 'z');
}

void adicionarPalavra() {
	
    FILE *arquivo;
    char nova_palavra[100];

    arquivo = fopen("palavras.txt", "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Digite a nova palavra a ser adicionada: ");
    fgets(nova_palavra, sizeof(nova_palavra), stdin);

   
    size_t length = strlen(nova_palavra);
    if (nova_palavra[length - 1] == '\n') {
        nova_palavra[length - 1] = '\0';
    }

   
    for (int i = 0; nova_palavra[i] != '\0'; i++) {
        if (!verificarFormato(nova_palavra[i]) || nova_palavra[i] == ' ') {
            printf("Tentativa inválida. A palavra deve conter apenas letras minúsculas, sem acentos, e sem espaços.\n");
            printf("Apenas a primeira palavra será gravada.\n");
            fclose(arquivo);
        }
    }
   
    fprintf(arquivo, "%s\n", nova_palavra);
    fclose(arquivo);
    printf("Palavra(s) adicionada(s) com sucesso!\n");
}

char * pegarPalavraAleatoria() {
    FILE *arquivo;
    arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int num_palavras = 0;
    char c;
    for (c = getc(arquivo); c != EOF; c = getc(arquivo)) {
        if (c == '\n') {
            num_palavras++;
        }
    }

    srand(time(0));
    int indice_aleatorio = rand() % num_palavras;

    rewind(arquivo);

    char palavra[50];  // Supondo que nenhuma palavra tenha mais de 50 caracteres
    for (int i = 0; i <= indice_aleatorio; i++) {
        fscanf(arquivo, "%s", palavra);
    }

    fclose(arquivo);

    char *palavra_aleatoria = (char*)malloc(strlen(palavra) + 1);
    strcpy(palavra_aleatoria, palavra);

    return palavra_aleatoria;
}

void mostrarRanking(JOGADOR * jogadores, int quantidade_jogadores){
	
	system("cls");
	
	for (int i = 0; i < quantidade_jogadores - 1; i++) {
        for (int j = i + 1; j < quantidade_jogadores; j++) {
            if (jogadores[i].pontos < jogadores[j].pontos) {
                JOGADOR variavel_temporaria = jogadores[i];
                jogadores[i] = jogadores[j];
                jogadores[j] = variavel_temporaria;
            }
        }
    }
	printf("----------------------------------\n");
	printf("|         Ranking da Partida     |\n");
	printf("----------------------------------\n");
    for (int i = 0; i < quantidade_jogadores; i++) {
        printf("%d° %s - %d\n", i+1, jogadores[i].nome, jogadores[i].pontos);
    }
    printf("----------------------------------\n");
}

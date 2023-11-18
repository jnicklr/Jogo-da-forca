#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
#include "telas.h"
#include "utils.h"

char* pegarPalavraAleatoria() {
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

int iniciarJogo(JOGADOR * jogadores, int quantidade_jogadores);

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

    printf("Jogadores em ordem decrescente:\n");

    for (int i = 0; i < quantidade_jogadores; i++) {
        printf("%s - %d\n", jogadores[i].nome, jogadores[i].pontos);
    }
}

void criarPartida(){
	int quantidade_jogadores;
	printf("Digite quantas pessoas ir�o jogar: ");
	scanf("%d", &quantidade_jogadores);
	fflush(stdin);	
	
	JOGADOR * jogadores;
				    
	jogadores = (JOGADOR *)malloc(sizeof(JOGADOR) * quantidade_jogadores);
					    
	for (int i = 0; i < quantidade_jogadores; i++){
		printf("Digite o nome do %d� jogador: ", i+1);
		scanf("%50[^\n]s", &(jogadores[i].nome));
		fflush(stdin);
		jogadores[i].pontos = 0;
	}
	
	char repetir_jogo = 'S';
	while(repetir_jogo == 'S'){
		iniciarJogo(jogadores, quantidade_jogadores);
		printf("Digite 'S' caso queira iniciar um novo jogo: ");
		scanf("%c", &repetir_jogo);
		fflush(stdin);	
	}
	
	mostrarRanking(jogadores, quantidade_jogadores);
}

int main(){
	
	setlocale(0, "Portuguese");
	
	telaCarregamento();
	
	int opcao;
	int logado = 1;
	
	while (logado){
		
		system("cls");
		menuPrincipal();
	    scanf("%d", &opcao);
	    fflush(stdin);
	    
	    system("cls");
	    switch (opcao){
	    	case 1:
	    		criarPartida();
	    		break;
	    	case 2:
				menuCreditos();
		    	logado = 0;
	    		break;
	    	case 3:
				menuAdicionarPalavras();
				adicionarPalavra();
				break;
		    default:
		    	break;
		}
	
		system("pause");
	}
	
	return 0;
}

int iniciarJogo(JOGADOR * jogadores, int quantidade_jogadores){
	
	char * palavra_aleatoria = pegarPalavraAleatoria();
	int tamanho_palavra = strlen(palavra_aleatoria);
	
	char * letras_censuradas = preencherArray(tamanho_palavra);
	
	char * letras_unicas = pegarLetrasUnicas(tamanho_palavra, palavra_aleatoria);
	
	int quantidade_letras_unicas = strlen(letras_unicas);
	
	char * letras_chutadas = preencherArray(quantidade_letras_unicas+6);
	
	int quantidade_acertos = 0;
	int vidas_restantes = 6;
	int contador_letras = 0;
	int contador_jogadores = 0;
	char letra_escolhida_jogador;
	
	int continuar_jogo = 1;
	
	while (continuar_jogo){
		if (vidas_restantes == 0 || quantidade_acertos == quantidade_letras_unicas){
			verificarVitoria(vidas_restantes, quantidade_acertos, quantidade_letras_unicas, jogadores, contador_jogadores, palavra_aleatoria);
			continuar_jogo = 0;
		} else {
			system("cls");
		
			printf("----------------------------------\n");
			printf("|         Status do Jogo         |\n");
			printf("----------------------------------\n");
			estagiosBoneco(vidas_restantes);
			printf("----------------------------------\n");
			printf("Jogador Atual: %s\n", jogadores[contador_jogadores].nome);
			printf("Vidas Restantes: %d\n", vidas_restantes);
			printf("Quantidade de Acertos: %d\n", quantidade_acertos);
			printf("----------------------------------\n");
			printf("Contador: %d\n", contador_jogadores);
			printf("----------------------------------\n");
			printf("Letras Vis�veis: %s\n", letras_censuradas);
			printf("Letras Digitadas: %s\n", letras_chutadas);
			printf("----------------------------------\n");
			printf("Digite uma letras: ");
			scanf("%c", &letra_escolhida_jogador);
			fflush(stdin);
				
			if (verificarAcerto(letra_escolhida_jogador, letras_unicas, letras_chutadas) == 1){
				quantidade_acertos += 1;
				for (int i = 0; i < strlen(palavra_aleatoria); i++){
					if (letra_escolhida_jogador == palavra_aleatoria[i]){
						letras_censuradas[i] = letra_escolhida_jogador;
					}
				}
			} else {
				vidas_restantes -= 1;
				contador_jogadores++;
				if (contador_jogadores >= quantidade_jogadores){
					contador_jogadores = 0;
				}
			}
			
			letras_chutadas[contador_letras]=letra_escolhida_jogador;
			contador_letras++;
		}
	}
	
	free(letras_censuradas);
	free(letras_unicas);
	free(letras_chutadas);
}
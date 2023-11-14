#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include "hangman.h"

typedef struct {
	char nome[50];
} JOGADOR;



int iniciar_jogo(char* palavra, char* palavra_mostrada, char* letras_unicas, int quantidade_letras_unicas, JOGADOR * jogadores, int quantidade_jogadores);

int main(){
	
	setlocale(0, "Portuguese");
	
	char palavra_aleatoria[] = {"banana"};
	int tamanho_palavra = strlen(palavra_aleatoria);
	
	char array_descart[tamanho_palavra+1];
	memset(array_descart, '*', sizeof(array_descart));
	array_descart[tamanho_palavra] = '\0';
	
	int quantidade_letras = 0;
	int palavra_repetida = 0;
	
	for (int i = 0; i < tamanho_palavra; i++){
		for (int j = 0; j < tamanho_palavra; j++){
			if (array_descart[j] == palavra_aleatoria[i]){
				palavra_repetida = 1;
				break;
			}
		}
		if (!palavra_repetida){
			array_descart[quantidade_letras] = palavra_aleatoria[i];
			quantidade_letras++;
		}
		palavra_repetida = 0;
	}
	
	char letras_unicas[quantidade_letras+1];
	strncpy(letras_unicas, array_descart, quantidade_letras);
	letras_unicas[quantidade_letras] = '\0';
	
	tela_carregamento();
	
	int logado = 1;
	int opcao;
	char nova_palavra[50];
	
	while (logado){
			
		char * lista_vazia;
		lista_vazia = (char *)malloc(sizeof(lista_vazia) * (tamanho_palavra+1));
	    memset(lista_vazia, '*', tamanho_palavra);
	    lista_vazia[tamanho_palavra] = '\0';
		
		system("cls");
		printf("----------------------------------\n");
	    printf("|          Menu do Jogo          |\n");
	    printf("----------------------------------\n");
	    printf("|      1 - Iniciar o Jogo        |\n");
	    printf("|      2 - Sair do Jogo          |\n");
	    printf("|      3 - Adicionar Palavra     |\n");
	    printf("----------------------------------\n");
	    printf("Digite sua opção desejada: ");
	    scanf("%d", &opcao);
	    fflush(stdin);
	    
	    switch (opcao){
	    	case 1:
	    		{
	    			int quantidade_jogadores;
				    printf("Digite quantas pessoas irão jogar: ");
				    scanf("%d", &quantidade_jogadores);
				    fflush(stdin);
				    
				    JOGADOR * jogadores;
				    
				    jogadores = (JOGADOR *)malloc(sizeof(jogadores) * quantidade_jogadores);
				    
				    for (int i = 0; i < quantidade_jogadores; i++){
				    	printf("Digite o nome do %d° jogador: ", i+1);
				    	scanf("%50[^\n]s", jogadores[i].nome);
				    	fflush(stdin);
					}
				    
		    		iniciar_jogo(palavra_aleatoria, lista_vazia, letras_unicas, quantidade_letras, jogadores, quantidade_jogadores);
		    		free(jogadores);
		    		free(lista_vazia);
				}
	    		break;
	    	case 2:
	    		system("cls");
				printf("----------------------------------\n");
			    printf("|             Créditos           |\n");
			    printf("----------------------------------\n");
			    printf("|      1 - José Nichollas        |\n");
			    printf("|      2 - João Victor           |\n");
			    printf("|      3 - João Pedro            |\n");
			    printf("|      4 - Rodrigo Cordeiro      |\n");
			    printf("|      5 - Duan Oliveira         |\n");
			    printf("----------------------------------\n");
		    	logado = 0;
	    		break;
	    	case 3:
		    	system("cls");
				printf("----------------------------------\n");
			    printf("|              Regras            |\n");
			    printf("----------------------------------\n");
			    printf("|   1 - Não deve ter sinal       |\n");
			    printf("|   2 - Não deve ser muito longa |\n");
			    printf("----------------------------------\n");
			    printf("Digite a palavra desejada: ");
		    	scanf("%50[^\n]s", nova_palavra);
		    default:
		    	break;
		}
	
		system("pause");
	}
	
	return 0;
}

int iniciar_jogo(char* palavra, char* palavra_mostrada, char* letras_unicas, int quantidade_letras_unicas, JOGADOR * jogadores, int quantidade_jogadores){
	
	char letra_jogador;
	
	char letras_chutadas[quantidade_letras_unicas+7];
	memset(letras_chutadas, '*', sizeof(letras_chutadas));
    letras_chutadas[quantidade_letras_unicas+6] = '\0';	
	
	int acerto = 0;
	int acertos = 0;
	int jogando = 1;
	int contador_letras = 0;
	int vidas_restantes = 6;
	
	int contador_jogadores = 0;
	JOGADOR jogador_atual = jogadores[contador_jogadores];
	
	while (jogando){
		system("cls");
		printf("Jogador Atual: %s\n", jogador_atual.nome);
		printf("Vidas do jogador: %d\n", vidas_restantes);
		printf("Acertos: %d\n", acertos);
		printf("---------------\n");
		printf("Palavra: %s\n", palavra_mostrada);
		printf("Letras chutadas: %s\n", letras_chutadas);
		printf("---------------\n");
		printf("Escolha uma letra: ");
		scanf("%c", &letra_jogador);
		fflush(stdin);
		
		for (int i = 0; i < quantidade_letras_unicas; i++){
			if (letra_jogador == letras_unicas[i]){
				acerto = 1;
			}
		}
		
		if (strlen(letras_chutadas) > 0){
			for (int i = 0; i < strlen(letras_chutadas); i++){
				if (letra_jogador == letras_chutadas[i]){
					acerto = 0;
				}
			} 
		}
			
		if (acerto){
			acertos += 1;
			for (int i = 0; i < strlen(palavra); i++){
				if (letra_jogador == palavra[i]){
					palavra_mostrada[i] = letra_jogador;
				}
			}
		} else {
			vidas_restantes -= 1;
			contador_jogadores++;
			if (contador_jogadores >= quantidade_jogadores){
				contador_jogadores = 0;
			}
			jogador_atual = jogadores[contador_jogadores];
		}
			
		if (vidas_restantes == 0 || acertos == strlen(letras_unicas)){
			jogando = 0;
		}
			
		acerto = 0;
		letras_chutadas[contador_letras]=letra_jogador;
		contador_letras++;
	}
}

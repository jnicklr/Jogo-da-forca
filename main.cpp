#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include "hangman.h"

typedef struct {
	char nome[50];
	int vidas_restantes;
} JOGADOR;

int iniciar_jogo(char* palavra, char* palavra_mostrada, char* letras_unicas, int quantidade_letras_unicas, JOGADOR * jogador_1);

int main(){
	
	// Define a linguagem local como português.
	setlocale(0, "Portuguese");
	
	// Definindo o jogador da partida.
	JOGADOR jogador_1;
    strcpy(jogador_1.nome, "Nichollas");
    jogador_1.vidas_restantes = 6;
	
	char palavra_aleatoria[] = {"banana"}; // Palavra aleatória selecionada.
	int tamanho_palavra = strlen(palavra_aleatoria); // Tamanho da palavra aleatória selecionada.
	
	// Lista com caracteres * que vão ser substituidos durante o jogo à medida que as palavras são acertadas.
	char lista_vazia[tamanho_palavra + 1];
    memset(lista_vazia, '*', tamanho_palavra);
    lista_vazia[tamanho_palavra] = '\0';
	
	// Array descartável criado para pegar as palavras unicas da palavra aleatória de forma temporária
	// e depois para ser copiada em um novo array.
	char array_descart[tamanho_palavra+1];
	memset(array_descart, '*', sizeof(array_descart));
	array_descart[tamanho_palavra] = '\0';
	
	int quantidade_letras = 0; // Quantidade de letras únicas  na palavra, ex: banana = ban.
	int palavra_repetida = 0; // Variável com valor booleano para dizer se a letra está repetida ou não.
	
	// Iteração para pegar as letras únicas da palavra:
	// Iteração pela palavra aleatória.
	for (int i = 0; i < tamanho_palavra; i++){
		// Iteração pelo array descartável.
		for (int j = 0; j < tamanho_palavra; j++){
			if (array_descart[j] == palavra_aleatoria[i]){
				palavra_repetida = 1;
				break;
			}
		}
		// Se não estiver repetida, vai ser adicionada no array descartável.
		if (!palavra_repetida){
			array_descart[quantidade_letras] = palavra_aleatoria[i];
			quantidade_letras++;
		}
		palavra_repetida = 0;
	}
	
	// Array com as letras únicas.
	char letras_unicas[quantidade_letras+1];
	strncpy(letras_unicas, array_descart, quantidade_letras);
	letras_unicas[quantidade_letras] = '\0';
	
	tela_carregamento();
	
	int logado = 1;
	int opcao;
	char nova_palavra[50];
	
	while (logado){
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
	    		iniciar_jogo(palavra_aleatoria, lista_vazia, letras_unicas, quantidade_letras, &jogador_1);
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

int iniciar_jogo(char* palavra, char* palavra_mostrada, char* letras_unicas, int quantidade_letras_unicas, JOGADOR * jogador_1){
	
	char letra_jogador;
	
	// Lista com caracteres * que vão ser substituidos durante o jogo à medida que as palavras são digitadas.
	char letras_chutadas[quantidade_letras_unicas+7];
	memset(letras_chutadas, '*', sizeof(letras_chutadas));
    letras_chutadas[quantidade_letras_unicas+6] = '\0';	
	
	int acerto = 0;
	int acertos = 0;
	int jogando = 1;
	int contador_letras = 0;
	
	while (jogando){
		
		system("cls");
		printf("Vidas do jogador: %d\n", jogador_1->vidas_restantes);
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
			jogador_1->vidas_restantes -= 1;
		}
		
		if (jogador_1->vidas_restantes == 0 || acertos == strlen(letras_unicas)){
			jogando = 0;
		}
		
		acerto = 0;
		letras_chutadas[contador_letras]=letra_jogador;
		contador_letras++;
	}
}

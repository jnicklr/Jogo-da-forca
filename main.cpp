#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[50];
	int vidas_restantes;;
} JOGADOR;

int main(){
	
	char palavra_aleatoria[] = {"banana"}; // Palavra aleat�ria selecionada.
	int tamanho_palavra = strlen(palavra_aleatoria); // Tamanho da palavra aleat�ria selecionada.
	
	// Lista com caracteres * que v�o ser substituidos durante o jogo � medida que as palavras s�o acertadas.
	char lista_vazia[tamanho_palavra + 1];
    memset(lista_vazia, '*', tamanho_palavra);
    lista_vazia[tamanho_palavra] = '\0';
	
	// Array descart�vel criado para pegar as palavras unicas da palavra aleat�ria de forma tempor�ria
	// e depois para ser copiada em um novo array.
	char array_descart[tamanho_palavra+1];
	memset(array_descart, '*', sizeof(array_descart));
	array_descart[tamanho_palavra] = '\0';
	
	int quantidade_letras = 0; // Quantidade de letras �nicas  na palavra, ex: banana = ban.
	int palavra_repetida = 0; // Vari�vel com valor booleano para dizer se a letra est� repetida ou n�o.
	
	// Itera��o para pegar as letras �nicas da palavra:
	// Itera��o pela palavra aleat�ria.
	for (int i = 0; i < tamanho_palavra; i++){
		// Itera��o pelo array descart�vel.
		for (int j = 0; j < tamanho_palavra; j++){
			if (array_descart[j] == palavra_aleatoria[i]){
				palavra_repetida = 1;
				break;
			}
		}
		// Se n�o estiver repetida, vai ser adicionada no array descart�vel.
		if (!palavra_repetida){
			array_descart[quantidade_letras] = palavra_aleatoria[i];
			quantidade_letras++;
		}
		palavra_repetida = 0;
	}
	
	// Array com as letras �nicas.
	char letras_unicas[quantidade_letras+1];
	strncpy(letras_unicas, array_descart, quantidade_letras);
	letras_unicas[quantidade_letras] = '\0';
	
	printf("---------------\n");
	printf("Palavra aleatoria: %s\n", palavra_aleatoria);
	printf("Letras unicas: %s\n", letras_unicas);
	printf("Lista vazia: %s\n", lista_vazia);
	printf("---------------\n");	
	
	return 0;
}

#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[50];
	int vidas_restantes;;
} JOGADOR;

int main(){
	
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
	
	printf("---------------\n");
	printf("Palavra aleatoria: %s\n", palavra_aleatoria);
	printf("Letras unicas: %s\n", letras_unicas);
	printf("Lista vazia: %s\n", lista_vazia);
	printf("---------------\n");	
	
	return 0;
}

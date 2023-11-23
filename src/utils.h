#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	char nome[50];
	int pontos;
} JOGADOR;

int verificarAcerto(char letra_escolhida_jogador, char * letras_unicas, char * letras_chutadas){
	
	int acertando_letra = 0;
	
	// verifica se o jogador acertou a letra.
	for (int i = 0; i < strlen(letras_unicas); i++){
		if (letra_escolhida_jogador == letras_unicas[i]){
			acertando_letra = 1;
		}
	}
		
	// verifica se a letra digitada está repetida.
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
	
	if (vidas_restantes == 0){	// verifica se perdeu ou ganhou.
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
	memset(array_preenchido, '*', tamanho_array); // vai preencher o array com asteriscos para não ter problema com lixo de memória.
	array_preenchido[tamanho_array] = '\0';
	
	return array_preenchido;
}

char * pegarLetrasUnicas(int tamanho_palavra, char * palavra_aleatoria){
	
	// array criado apenas para armazenar as letras e depois copiar em letras únicas.
	char * array_descartavel = preencherArray(tamanho_palavra);
	
	int quantidade_letras = 0;
	int palavra_repetida = 0;
	
	for (int i = 0; i < tamanho_palavra; i++){
		// vai verificar cada letra e se ela já foi armazenada no array descartável, se não foi, vai ser adicionada.
		for (int j = 0; j < tamanho_palavra; j++){
			if (array_descartavel[j] == palavra_aleatoria[i]){
				// se a letra estiver no array descartável, significa que repetiu. 
				palavra_repetida = 1;
				break;
			}
		}
		// se não está repetida, deve ser adicionada ao array.
		if (!palavra_repetida){
			array_descartavel[quantidade_letras] = palavra_aleatoria[i];
			quantidade_letras++;
		}
		palavra_repetida = 0;
	}
	
	char* letras_unicas = (char*)malloc(quantidade_letras + 1);
	strncpy(letras_unicas, array_descartavel, quantidade_letras); // copiando as letras únicas à variável letra_unica para depois retornar o endereço.
	letras_unicas[quantidade_letras] = '\0';
	
	free(array_descartavel); // liberando a memória.
	
	return letras_unicas;
}

int verificarFormato(char c) {
    return (c >= 'a' && c <= 'z'); // verifica o intervalo no ascii.
}

void adicionarPalavra() {
	
    FILE *arquivo;

    arquivo = fopen("palavras.txt", "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo ou ele não existe\n");
        exit(1);
    }
    
    char nova_palavra[100];
    printf("Digite a nova palavra a ser adicionada: ");
    scanf("%50[^\n]s", nova_palavra);
	fflush(stdin);
   
	int palavra_valida = 1; 
    int tamanho_palavra = strlen(nova_palavra);
   
   // iteração pelos caracteres da palavra para verificar se está no formato correto.
    for (int i = 0; nova_palavra[i] != '\0'; i++) {
        if (!verificarFormato(nova_palavra[i])) {
            printf("Tentativa inválida. A palavra deve conter apenas letras minúsculas, sem acentos, e sem espaços.\n");
            palavra_valida = 0;
            break;
        }
    }
   
   // se a palavra for válida ela vai ser adicionada no banco de dados.
	if (palavra_valida){
		fprintf(arquivo, "%s\n", nova_palavra);
		printf("Palavra(s) adicionada(s) com sucesso!\n");
	}
	
    fclose(arquivo);
}

char * pegarPalavraAleatoria() {
	
    FILE *arquivo;
    
    arquivo = fopen("palavras.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int numero_palavras = 0;
    char c;
    
    // iteração para pegar cada caractere do arquivo txt e contar quantidade de linhas.
    while((c = fgetc(arquivo)) != EOF){
    	if (c == '\n') {
            numero_palavras++;
        }
	}

    srand(time(0));
    int indice_aleatorio = rand() % numero_palavras; // pega o resto da divisão do número aleatório.

    rewind(arquivo); // volta para o início do arquivo

    char palavra[100];
    for (int i = 0; i <= indice_aleatorio; i++) {
        fscanf(arquivo, "%s", palavra); // lendo cada palavra e descartando se não for a do número aleatório.
    }

    fclose(arquivo);

    char * palavra_aleatoria = (char*)malloc(strlen(palavra) + 1);
    strcpy(palavra_aleatoria, palavra);

    return palavra_aleatoria;
}

void mostrarRanking(JOGADOR * jogadores, int quantidade_jogadores){
	
	system("cls");
	
	// ordenando os jogadores com base nos seus pontos.
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

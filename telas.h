#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void menuPrincipal(){
	printf("----------------------------------\n");
	printf("|          Menu do Jogo          |\n");
	printf("----------------------------------\n");
	printf("|      1 - Iniciar o Jogo        |\n");
	printf("|      2 - Sair do Jogo          |\n");
	printf("|      3 - Adicionar Palavra     |\n");
	printf("----------------------------------\n");
	printf("Digite sua op��o desejada: ");
}

void menuCreditos(){
	printf("----------------------------------\n");
	printf("|             Cr�ditos           |\n");
	printf("----------------------------------\n");
	printf("|      1 - Jos� Nichollas        |\n");
	printf("|      2 - Jo�o Victor           |\n");
	printf("|      3 - Jo�o Pedro            |\n");
	printf("|      4 - Rodrigo Cordeiro      |\n");
	printf("|      5 - Duan Oliveira         |\n");
	printf("----------------------------------\n");
}

void menuAdicionarPalavras(){
	printf("----------------------------------\n");
	printf("|              Regras            |\n");
	printf("----------------------------------\n");
	printf("| 1 - N�o deve ter acentua��o    |\n");
	printf("| 2 - N�o deve ser uma frase     |\n");
	printf("| 3 - N�o pode conter mai�sculas |\n");
	printf("| 4 - N�o pode conter espa�os    |\n");
	printf("----------------------------------\n");
}

void telaCarregamento(){
	printf("   ___                         _        ______\n");
	Sleep(100);
	printf("  |_  |                       | |       |  ___|\n");
	Sleep(100);
	printf("    | | ___   __ _  ___     __| | __ _  | |_ ___  _ __ ___ __ _\n");
	Sleep(100);
	printf("    | |/ _ \\ / _` |/ _ \\   / _` |/ _` | |  _/ _ \\| '__/ __/ _` |\n");
	Sleep(100);
	printf("/\\__/ / (_) | (_| | (_) | | (_| | (_| | | || (_) | | | (_| (_| |\n");
	Sleep(100);
	printf("\\____/ \\___/ \\__, |\\___/   \\__,_|\\__,_| \\_| \\___/|_|  \\___\\__,_|\n");
	Sleep(100);
	printf("              __/ |\n");
	Sleep(100);
	printf("             |___/\n");
	Sleep(100);
	printf("Deseja iniciar um jogo?\n");
	Sleep(500);
	system("pause");
}

void estagiosBoneco(int vidas){
	switch (vidas){
		case 0:
			printf("  +---+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf(" /|\\  |\n");
			printf(" / \\  |\n");
			printf("      |\n");
			printf("=========\n");
			break;
		case 1:
			printf("  +---+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf(" /|\\  |\n");
			printf(" /    |\n");
			printf("      |\n");
			printf("=========\n");
			break;
		case 2:
			printf("  +---+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf(" /|\\  |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=========\n");
			break;
		case 3:
			printf("  +---+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf(" /|   |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=========\n");
			break;
		case 4:
			printf("  +---+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf("  |   |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=========\n");
			break;
		case 5:
			printf("  +---+\n");
			printf("  |   |\n");
			printf("  O   |\n");
			printf("      |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=========\n");
			break;
		case 6:
			printf("  +---+\n");
			printf("  |   |\n");
			printf("      |\n");
			printf("      |\n");
			printf("      |\n");
			printf("      |\n");
			printf("=========\n");
			break;
	}
}

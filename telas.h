#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void tela_carregamento(){
	printf("   ___                         _        ______\n");
	Sleep(200);
	printf("  |_  |                       | |       |  ___|\n");
	Sleep(200);
	printf("    | | ___   __ _  ___     __| | __ _  | |_ ___  _ __ ___ __ _\n");
	Sleep(200);
	printf("    | |/ _ \\ / _` |/ _ \\   / _` |/ _` | |  _/ _ \\| '__/ __/ _` |\n");
	Sleep(200);
	printf("/\\__/ / (_) | (_| | (_) | | (_| | (_| | | || (_) | | | (_| (_| |\n");
	Sleep(200);
	printf("\\____/ \\___/ \\__, |\\___/   \\__,_|\\__,_| \\_| \\___/|_|  \\___\\__,_|\n");
	Sleep(200);
	printf("              __/ |\n");
	Sleep(200);
	printf("             |___/\n");
	Sleep(200);
	printf("Deseja iniciar um jogo?\n");
	Sleep(1000);
	system("pause");
}

void estagios_boneco(int vidas){
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

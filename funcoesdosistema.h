#include "estruturas.h"

//Exibe uma pausa na tela para que o usu�rio possa ler e tomar decis�es
void pausa() {

	printf("\nPressione [ENTER] para continuar...");
	scanf("[^\n]");
}

////Limpa tudo que estiver na tela
//void limparTela() {
//	system("cls");
//system("tput reset");
//system("clear");
//}


//Fecha o programa
void sairDoPrograma() {
	exit(0);
}
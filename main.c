#include "inicializacao.h"

void main()
{
	//Declarar ponteiro da �rvore
	itemDaArvore* raiz = NULL;
	
	//Iniciar a execu��o do programa
	if (!inicializarPrograma())
	{
		imprimirListaDeErros();
		limparErros();
		pausa();
		main();
	}
}
#include "inicializacao.h"

void main()
{
	//Iniciar a execu��o do programa
	if (!inicializarPrograma())
	{
		imprimirListaDeErros();
		limparErros();
		pausa();
		main();
	}
}
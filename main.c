#include "inicializacao.h"

//Fun��o principal
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
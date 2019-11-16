#include "opcoesdomenu.h"

//Executar uma fun��o do menu de acordo com a op��o informada
bool executarFuncaoDoMenu(int opcao) {

	//Validar op��o informada
	if (!validarNumeroNaturalPositivo(opcao)) return false;

	switch (opcao) {

	case 1:
		if (criarArvore()) { break; }
		return false;
	case 2:
		if (inserirPalavraNaArvore()) { break; }
		return false;
	case 3:
		if (consultarPalavraNaArvore()) { break; }
		return false;
	case 4:
		if (listarPalavrasDaArvore()) { break; }
		return false;
	case 5:
		if (removerArvore()) { break; };
		return false;
	case 6:
		sairDoPrograma();
		break;
	default:
		printf("\nOp��o inv�lida\n");
		break;
	}

	return true;
}

//Imprimir op��es do menu
void imprimirOpcoesDoMenu() {

	printf(
		"\n=================== Trabalho pr�tico II ===================\n"
		" Alunos: Denise Alpim e Gabriel Trindade\n"

		"\n	1) Criar (zerar) a �rvore"
		"\n	2) Inserir valor (palavra) na �rvore pelo arquivo .txt"
		"\n	3) Consulta uma palavra na �rvore"
		"\n	4) Listar todas as palavras cadastradas na �rvore"
		"\n	5) Remover a �rvore"
		"\n	6) Encerrar o programa"
		"\n\n"
	);
}

//Executar o menu
bool menu() {

	//Declarar a variavel para guardar a opcao que o usuario escolher
	int opcao = 0;

	//Rodar o programa
	do {

		//Limpar a tela para o menu aparecer sempre em cima
		limparTela();

		//Mostrar as op��es do menu na tela
		imprimirOpcoesDoMenu();

		//Ler o conte�do digitado
		opcao = lerNumeroNaturalDoTeclado();

		//Validar conte�do digitado
		if (opcao == EOF) return false;

		//Executar fun��o do menu
		if (!executarFuncaoDoMenu(opcao)) return false;

		//Pausa antes de escolher uma nova opcao
		pausa();

	} while (opcao != CODIGO_FECHA_PROGRAMA);

	return true;
}

//Inicializar a execu��o do programa
bool inicializarPrograma() {

	//Configurar local para permitir acentua��o de caracteres especiais
	if (!configurarLocal()) return false;

	//Exucutar menu
	if (!menu()) return false;

	return true;
}
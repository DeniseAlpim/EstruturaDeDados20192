#include "opcoesdomenu.h"

//Executar uma funcao do menu de acordo com a opcao, retorna falso se alguma funcao qualquer der erro
bool executarFuncaoDoMenu(int opcao) {

	//Validar op��o informada
	if (!validarNumeroNaturalPositivo(opcao))
	{
		lancarErro(20);
		return false;
	}

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

//Imprimir opcoes do menu
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
	int opcao;

	//Limpar a tela para o menu aparecer sempre em cima
	limparTela();

	//Rodar o programa
	do {

		//Mostrar as op��es do menu na tela
		imprimirOpcoesDoMenu();

		//Ler o conte�do digitado
		opcao = lerNumeroNaturalDoTeclado();

		//Validar conte�do digitado
		if (opcao == EOF) {

			lancarErro(25);
			return false;
		}

		//Executar fun��o do menu
		if (!executarFuncaoDoMenu(opcao)) {

			lancarErro(27);
			return false;
		}

		//Pausa antes de escolher uma nova opcao
		pausa();

		//Limpar a tela para o menu aparecer sempre em cima
		limparTela();

	} while (opcao != 6);

	return true;
}

//Inicializar a execu��o do programa
bool inicializarPrograma() {

	//Configurar local para permitir acentua��o de caracteres especiais
	if (!configurarLocal()) {

		lancarErro(22);
		return false;
	}
	
	//Exucutar menu
	if (!menu()) {

		lancarErro(24);
		return false;
	}
	
	return true;
}
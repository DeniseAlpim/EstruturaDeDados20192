#include "validacoes.h"
/*
//Executar uma funcao do menu de acordo com a opcao, retorna falso se alguma funcao qualquer der erro
bool executarFuncaoDoMenu(int opcao, tipoLista* lista) {

1. Criar a �rvore. 2. Inserir valor (palavra) na �rvore. 3. Consulta uma
palavra na �rvore. 4. Listar todas as palavras na �rvore. 5. Remover a �rvore. 6.
Encerrar o programa



	//Validar aloca��o da lista
	if (!validarAlocacaoDeMemoria(lista)) return false;

	switch (opcao) {

	case 1:
		if (criarListaDePessoas(lista)) { break; }
		return false;
	case 2:
		if (cadastrarUmaPessoa(lista)) { break; }
		return false;
	case 3:
		if (consultarUmaPessoa(lista)) { break; }
		return false;
	case 4:
		if (removerUmaPessoaPeloCodigo(lista)) { break; }
		return false;
	case 5:
		if (destruirLista(lista)) { break; };
		return false;
	default:
		sairDoPrograma();
		break;
	}

	return true;
}
*/
//Imprimir opcoes do menu
void imprimirOpcoesDoMenu() {
	
	printf(
		"\n===== Trabalho pratico =====\n"
		"Alunos: Denise Alpim e Gabriel Trindade\n\n"

		"\n1) Criar a arvore"
		"\n2) Inserir valor (palavra) na arvore"
		"\n3) Consulta uma palavra na arvore"
		"\n4) Listar todas as palavras cadastradas na arvore"
		"\n5) Remover a �rvore"
		"\n6) Encerrar o programa"
		"\n\n"
	);
}

//Executar o menu
bool menu() {

	//Declarar a variavel para guardar a opcao que o usuario escolher
	int opcao;

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
		//pausa();

		//Limpar a tela para o menu aparecer sempre em cima
		//limparTela();

	} while (opcao != 5);

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
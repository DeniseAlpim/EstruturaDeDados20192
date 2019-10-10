#include "funcoesbase.h"

//A lista � vazia quando o inicio e o final s�o nulos, o tamanho � zero e a variavel listaZerada � true
bool listaVazia(tipoLista* lista) {

	if (
		lista->inicioDaLista == NULL &&
		lista->finalDaLista == NULL &&
		lista->tamanhoDaLista == 0 &&
		lista->listaZerada == (bool*)true
		) {
		//printf("\nA lista esta vazia.\n");
		return true;
	}

	return false;
}

//Se a pessoa pontar pra nulo, retorna falso e mostra erro na tela
bool validarAlocacaoPessoa(tipoPessoa* pessoa) {

	if (pessoa == NULL) {
		limparTela();
		printf("A pessoa esta apontando para nulo.\n");
		return false;
	}

	return true;
}

//Se a lista apontar pra nulo, exibe mensagem de erro e retorna falso
bool validarAlocacaoLista(tipoLista* lista) {

	if (lista == NULL) {
		
		//Exibe mensagem de erro
		printf("\nNao foi poss�vel alocar memoria para lista.\n");

		return false;
	}

	return true;
}

//Retorna false se a lista N�O for v�lida
bool validacaoListaCriada(tipoLista *lista){
			 
	if (lista->tamanhoDaLista == -1){		
		printf("Por favor, crie a lista primeiro.\n");
		pausa();
		return false;
	}

	return true;
}

//A lista � inv�lida se n�o conseguiu alocar memoria ou ainda n�o foi criada
bool validarLista(tipoLista* lista) {

	//Validar alocacao de memoria lista
	if (!validarAlocacaoLista(lista)) return false;

	//Verificar se a funcao criarListaDePessoas j� foi chamada
	if (!validacaoListaCriada(lista)) return false;

	return true;
}
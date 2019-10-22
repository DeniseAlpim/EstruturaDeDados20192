#include "excecao.h"


//Limpa o buffer do teclado (entrada padr�o)
void limparBufferDoTeclado() {

	setbuf(stdin, NULL);

}

//Ler texto do teclado at� o usu�rio apertar enter (quantidade "qualquer" de caracteres). Retorna nulo se der erro ou o ponteiro da string lida
string lerTextoDoTeclado() {

	//Limpar o buffer do teclado
	limparBufferDoTeclado();

	//Declarar variavel de retorno da leitura e string
	int retornoDaLeitura = 0;
	string texto;

	//Tentar ler pelo menos um caractere do teclado
	//Enquanto nenhum carcterer for lido, o programa tentar� ler de novo
	do
	{
		//Fazer a leitura e armazaenar o resultado da leitura na vari�vel
		//Para de ler quando o usu�rio apertar [ENTER]
		retornoDaLeitura = scanf("%[^\n]", texto);

		//Verificar se houver erro de leitura
		if (retornoDaLeitura == EOF)
		{
			lancarErro(13);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Erro inesperado
		if (retornoDaLeitura < 0 && retornoDaLeitura != EOF)
		{
			lancarErro(14);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Limpar o buffer do teclado
		limparBufferDoTeclado();

	} while (retornoDaLeitura == 0);

	return texto;

}

//=================================================================

// Retorna verdadeiro se for um n�mero natural
bool validarNumeroNatural(int numero) {

	if (numero < 0) {

		lancarErro(7);
		return false;
	}

	return true;
}

// Retorna verdadeiro se for um n�mero natural maior que zero
bool validarNumeroNaturalPositivo(int numero) {

	if (!validarNumeroNatural(numero)) {

		lancarErro(9);
		return false;
	}

	if (numero == 0)
	{
		lancarErro(10);
		return false;
	}

	return true;
}

//==========================================================





//Retorna true se a quantidade de caracteres impressos for maior que 0. Exibe mensagem de erro.
bool validarImpressao(int numero) {

	if (numero > 0)
		return true;

	printf("\nNenhum caractere foi impresso na tela.\n");

	return false;
}

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
		//limparTela();
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
bool validacaoListaCriada(tipoLista* lista) {

	if (lista->tamanhoDaLista == -1) {
		printf("Por favor, crie a lista primeiro.\n");
		//pausa();
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
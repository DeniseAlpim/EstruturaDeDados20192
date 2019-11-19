#include "excecao.h"

//Alterar localiza��o do programa para a localiza��o do sistema para permitir uso de caracteres especiais
bool configurarLocal() {

	string retorno = setlocale(LC_ALL, "Portuguese");

	if ((retorno == NULL) || (retorno == "") || (retorno == "\0")|| (retorno == " "))
	{

		retorno = setlocale(LC_ALL, "");

		if ((retorno == NULL) || (retorno == "") || (retorno == "\0")|| (retorno == " "))
		{
			lancarErro(18);
			perror(MENSAGEM_DE_ERRO);
			return false;
		}
	}

	return true;
}

//Limpa o buffer do teclado (entrada padr�o)
void limparBufferDoTeclado() {

	setbuf(stdin, NULL);
}

//Validar aloca��o de mem�ria, retorna falso se o ponteiro for nulo
bool validarAlocacaoDeMemoria(void* ponteiro) {

	if (ponteiro == NULL)
	{
		lancarErro(15);
		//perror(MENSAGEM_DE_ERRO);
		return false;
	}

	return true;
}

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

	if (numero == 0) {
		lancarErro(10);
		return false;
	}

	return true;
}

//Retorna o ponteiro do n�mero lido ou NULL em caso de erro (caso leia um n�mero maior que int o ponteiro retornar� o VALOR -1)
int* lerNumeroInteiroDoTeclado() {

	//Limpar o buffer do teclado
	limparBufferDoTeclado();

	//Declarar variavel de retorno da leitura e string
	int retornoDaLeitura = 0;

	//Declarar numero, alocar e validar mem�ria
	int* numero = (int*)malloc(sizeof(int));
	if (!validarAlocacaoDeMemoria(numero)) {
		lancarErro(16);
		perror(MENSAGEM_DE_ERRO);
		return NULL;
	}

	//Enquanto nenhum caractere for lido, o programa tentar� ler de novo
	do {
		//Ler do teclado e guardar o resultado. Para de ler quando o usu�rio apertar [ENTER]
		retornoDaLeitura = scanf("%d", numero);

		//Verificar se houver erro de leitura
		if (retornoDaLeitura == EOF) {
			lancarErro(13);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Erro inesperado
		if (retornoDaLeitura < 0 && retornoDaLeitura != EOF) {
			lancarErro(14);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Limpar o buffer do teclado
		limparBufferDoTeclado();
	} while (retornoDaLeitura == 0);

	//Limpar o buffer do teclado
	limparBufferDoTeclado();

	return numero;
}

//Retorna o n�mero NATURAL lido ou EOF (-1) em caso de erro
int lerNumeroNaturalDoTeclado() {

	//Declarar e ler o n�mero
	int* numero = lerNumeroInteiroDoTeclado();

	//Validar leitura do n�mero
	if (numero == NULL) {

		lancarErro(19);
		return EOF;
	}

	//Declarar n�mero natural
	int numeroNatural = *numero;

	//Validar n�mero natural
	if (!validarNumeroNatural(numeroNatural)) {

		lancarErro(9);
		return EOF;
	}

	return numeroNatural;
}

//Recebe a quantidade de caracteres que devem ser lidos. Retorna nulo se der erro ou o ponteiro da string lida.
string lerTextoDoTeclado(int quantidade) {

	//Limpar o buffer do teclado
	limparBufferDoTeclado();

	//Validar quantidade
	if (!validarNumeroNaturalPositivo(quantidade)) {

		lancarErro(20);
		return NULL;
	}

	//Declarar variavel de retorno da leitura e string
	int retornoDaLeitura = 0;
	string texto = (string)malloc(quantidade * sizeof(char));

	//Validar aloca��o
	if (!validarAlocacaoDeMemoria(texto)) {

		lancarErro(16);
		perror(MENSAGEM_DE_ERRO);
		return false;
	}

	//Enquanto nenhum caractere for lido, o programa tentar� ler de novo
	do {
		//Ler do teclado e guardar o resultado. Para de ler quando o usu�rio apertar [ENTER]
		retornoDaLeitura = scanf("%[^\n]", texto);

		//Verificar se houver erro de leitura
		if (retornoDaLeitura == EOF) {
			lancarErro(13);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Erro inesperado
		if (retornoDaLeitura < 0 && retornoDaLeitura != EOF) {
			lancarErro(14);
			perror(MENSAGEM_DE_ERRO);
			return NULL;
		}

		//Limpar o buffer do teclado
		limparBufferDoTeclado();
	} while (retornoDaLeitura == 0);

	//Validar tamanho da string lida
	if (strlen(texto) > quantidade) {

		lancarErro(17);
		perror(MENSAGEM_DE_ERRO);
		return NULL;
	}

	return texto;
}

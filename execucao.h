#include "validacoes.h"

//Imprime uma mensagem de sucesso na tela
void mensagemSucesso() {

	printf("\nOperacao realizada com sucesso.\n");
}

//Alocar mem�ria para um novo item da �rvore
itemDaArvore* alocarItemDaArvore() {

	if (DEBUG == true) printf("Iniciando a funcao, 'alocarItemDaArvore'...\n");

	itemDaArvore* novoItem = (itemDaArvore*)malloc(sizeof(itemDaArvore));

	if (!validarAlocacaoDeMemoria(novoItem)) return NULL;

	novoItem->chave = -1;

	for (int i = 0; i < TAMANHO_DO_ALFABETO; i++)
	{
		novoItem->proximaLetra[i] = NULL;
	}

	return novoItem;
}

//Verificar se uma determinada palavra est� cadastrada na arvore
bool consultarUmaDeterminadaPalavraNaArvore(string palavra) {

	if (DEBUG == true) printf("Iniciando a funcao, 'consultarUmaDeterminadaPalavraNaArvore'...\n");

	//Verificar se a palavra � nula
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	if (DEBUG == true) printf("A palavra recebida validada com sucesso. Validando raiz da arvore..\n");

	//Verificar se a raiz � nula
	if (!validarArvoreCriada()) return false;

	if (DEBUG == true) printf("Raiz validada com sucesso. Calculando tamanho da palavra...\n");

	//Criar ponteiro auxiliar do tipo 'item da arvore'
	itemDaArvore* itemAuxiliar = raiz;

	//Verificar o tamanho da palavra
	int tamanho = strlen(palavra);

	if (DEBUG == true) printf("Primeira letra da palavra: '%c'. Tamanho da palavra '%d'. Iniciando iteracao...\n", *palavra, tamanho);

	//Percorrer a �rvore at� o final da palavra ou a palavra n�o existir
	for (int i = 0; i < tamanho; i++)
	{
		if (DEBUG == true) printf("Iteracao '%d'. Verificando a letra '%c'. Codigo do item atual '%d'.\n", i, (*palavra), itemAuxiliar->chave);

		//Verifica se a letra corrente/atual est� na �rvore
		if (itemAuxiliar->proximaLetra[*palavra - 'a'] == NULL)
		{
			if (DEBUG == true) printf("A posicao %d do vetor e nula.\n", (*palavra - 'a');

			//Se ainda n�o tiver chegado no final da palavra
			if (i < (tamanho - 1))
			{
				if (DEBUG == true) printf("Esta nao e a ultima letra da palavra.\n");

				//Sai do la�o
				printf("\nA palavra n�o est� na �rvore. Apenas as %d primeiras letras est�o na �rvore.\n", i);

				return true;
			}

			//Se chegou no final da palavra
			if (i == (tamanho - 1))
			{
				if (DEBUG == true) printf("Esta e a ultima letra da arvore.\n");

				//Verifica se c�digo foi preenchido
				if (itemAuxiliar->chave > -1)
				{
					printf("\nA palavra '%s' est� na �rvore. Sua chave �: %d\n", (palavra - i), itemAuxiliar->chave);
					return true;
				}

				//Verifica se o c�digo � -1
				if (itemAuxiliar->chave <= -1)
				{
					printf("\nA(s) primeira(s) '%d' letra(s) da palavra '%s' est�o na �rvore. Por�m sua chave � igual a: '%d'\n", i, (palavra - i), itemAuxiliar->chave);
					return true;
				}

				lancarErro(29);
				return false;
			}
		}

		//Passa para o pr�ximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavra - 'a'];
		if (DEBUG == true) printf("Passando para o pr�ximo item... c�digo: %d iteracao %d\n", itemAuxiliar->chave, i);
		if (DEBUG == true) printf("letra %c\n", *palavra);
		palavra++;

		//Se for a ultima iteracao incrementa o tamanho
		if (i == (tamanho - 1)) tamanho++;
	}

	lancarErro(28);
	return false;
}

//Insere uma determinada palavra e um determinado c�digo na �rvore
bool inserirDeterminadaPalavraNaArvore(string palavraDaArvore, int codigo) {

	//Validar entradas
	if ((!validarAlocacaoDeMemoria(palavraDaArvore)) || (!validarNumeroNaturalPositivo(codigo)))
		return false;

	//Criar vari�vel auxiliar
	itemDaArvore* itemAuxiliar = raiz;
	if (DEBUG == true) printf("Argumentos recebidos na fun��o de inserir:\npalavra:%s\ncodigo:%d\n", palavraDaArvore, codigo);
	//Calcular tamanho da string para informar no 'for'
	int tamanho = (strlen(palavraDaArvore));
	if (DEBUG == true) printf("\ntamanho da palavra (for):%d\n", tamanho);
	//Percorrer a �rvore at� o final da palavra
	for (int i = 0; i < tamanho; i++)
	{
		//Aloca mem�ria para um novo item se o caractere for nulo
		if (itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] == NULL) {

			//Alocar novo item da �rvore
			itemDaArvore* novoItem = alocarItemDaArvore();
			if (DEBUG == true) printf("criando novo no...\n");
			//Validar aloca��o
			if (!validarAlocacaoDeMemoria(novoItem)) return false;

			//Colocar o novo item na arvore
			itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'] = novoItem;
		}
		if (DEBUG == true) printf("%c %d %d\n", *palavraDaArvore, i, (*palavraDaArvore - 'a'));
		//Passa para o pr�ximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavraDaArvore - 'a'];

		//Sair do la�o quando for a �ltima letra
		if (i == (tamanho - 1))
		{
			if (itemAuxiliar->chave == -1)
			{
				if (DEBUG == true) printf("a chave � -1. Inserido o c�digo %d na �rvore\n", codigo);
				//Inserir valor
				itemAuxiliar->chave = codigo;
				if (DEBUG == true) printf("chave inserida: %d\n", itemAuxiliar->chave);
				if (DEBUG == true) printf("ponteiro do item na letra '%c':%p\n", *palavraDaArvore, itemAuxiliar->proximaLetra[*palavraDaArvore - 'a']);
				return true;
			}

			if (itemAuxiliar->chave > -1)
			{
				if (DEBUG == true) printf("a chave � maior que -1... (chave = %d) incrementando tamanho.\n", itemAuxiliar->chave);
				tamanho++;
			}

			if (DEBUG == true) printf("a chave (%d) � menor que -1\n", itemAuxiliar->chave);
		}

		//Passar para o pr�ximo caractere
		palavraDaArvore++;
		if (DEBUG == true) printf("proxima letra... ");
	}
	if (DEBUG == true) printf("saiu do 'for': %c %d sem inserir a chave na �rvore.\n", *palavraDaArvore, (*palavraDaArvore - 'a'));

	return true;
}

//Ler uma quantidade de linhas de um arquivo
bool lerLinhasDoArquivo(string linha, FILE* arquivo, int entradas) {

	//Validar entradas da fun��o
	if (
		(!validarAlocacaoDeMemoria(linha)) ||
		(!validarAlocacaoDeMemoria(arquivo)) ||
		(!validarNumeroNaturalPositivo(entradas)) ||
		(!validarAlocacaoDeMemoria(raiz))
		)
		return false;

	//Iterar sobre as linhas
	for (int i = 0; i < entradas; i++)
	{
		//Pegar a linha do arquivo
		if (!validarAlocacaoDeMemoria(fgets(linha, TAMANHO_DA_LINHA, arquivo))) return false;
		if (DEBUG == true) printf("lendo linha do arquivo:%s;\n", linha);
		//Encontrar a v�rgula na linha
		string ponteiroDaVirgula = strchr(linha, ',');
		if (!validarAlocacaoDeMemoria(ponteiroDaVirgula)) return false;
		if (DEBUG == true) printf("resto da linha a partir da virgula:%s;\n", ponteiroDaVirgula);
		//Tamanho da palavra
		int tamanhoDaPalavra = strlen(linha) - strlen(ponteiroDaVirgula);
		if (DEBUG == true) printf("tamanhos: linha:%d resto da linha:%d; diferenca:%d\n", strlen(linha), strlen(ponteiroDaVirgula), tamanhoDaPalavra);
		//Palavra
		char palavra[tamanhoDaPalavra];
		memcpy(palavra, linha, tamanhoDaPalavra);
		if (DEBUG == true) printf("copiando palavra para o vetor. Palavra:%s\nlinha:%s\ntamanho:%d\n", palavra, linha, tamanhoDaPalavra);
		//Tamanho do c�digo
		int tamanhoDoCodigo = strlen(ponteiroDaVirgula) - 2;

		//C�digo
		char codigoEmTexto[tamanhoDoCodigo];
		memcpy(codigoEmTexto, (ponteiroDaVirgula + 2), tamanhoDoCodigo);

		//Converter c�digo para int
		int codigoEmInteiro = atoi(codigoEmTexto);
		if (!validarNumeroNaturalPositivo(codigoEmInteiro)) return false;

		//Criar vari�vel auxiliar
		itemDaArvore* itemAuxiliar = raiz;

		//Colocar a palavra em min�sculo
		for (int i = 0; i < (tamanhoDaPalavra - 1); i++) palavra[i] = tolower(palavra[i]);

		//Criar ponteiro da palavra
		string palavraDaArvore = &palavra[0];
		if (DEBUG == true) printf("passando palavra pro ponteiro:%s;\ntamanho:%d\n", palavraDaArvore, strlen(palavraDaArvore));
		//Inserir a palavra na �rvore
		if (!inserirDeterminadaPalavraNaArvore(palavraDaArvore, codigoEmInteiro)) return false;
		if (DEBUG == true) printf("terminou de ler a linha...\n\n");
		ponteiroDaVirgula = NULL;
	}
	if (DEBUG == true) printf("\nleu todas as linhas\n");
	return true;
}

//Inverter booleano de ativa��o do modo DEBUG
bool inverterDebug() {

	if (DEBUG == true)
	{
		DEBUG = false;
		printf("\nModo DEBUG desativado.\n");
		mensagemSucesso();
		return true;
	}

	if (DEBUG == false)
	{
		DEBUG = true;
		printf("\nModo DEBUG ativado.\n");
		mensagemSucesso();
		return true;
	}

	lancarErro(32);
	return false;
}

//Verificar se a raiz da �rvore � nula
bool validarArvoreCriada() {

	if (!validarAlocacaoDeMemoria(raiz))
	{
		lancarErro(33);
		return false;
	}

	return true;
}
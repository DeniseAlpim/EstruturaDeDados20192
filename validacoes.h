#include <stdbool.h>
#include <stdlib.h>

//Exibe uma pausa na tela para que o usu�rio possa ler e tomar decis�es
void pausa() {
	system("pause");
}

//Limpa tudo que estiver na tela
void limparTela() {
	system("cls");
}

//Fecha o programa
void sairDoPrograma() {
	exit(0);
}

//Retorna true se for um numero natural
bool numeroNatural(int numero) {

	if (numero >= 0) return true;

	return false;
}

//Se a lista apontar pra nulo, exibe mensagem de erro e retorna falso
bool validarAlocacaoLista(tipoLista* lista) {

	if (lista == NULL) {

		//Limpa a tela
		limparTela();

		//Exibe mensagem de erro
		printf("\nNao foi poss�vel alocar memoria para lista.\n");

		return false;
	}

	return true;
}

//Retorna true se a quantidade de caracteres impressos for maior que 0. Exibe mensagem de erro.
bool validarImpressao(int numero){
	
	if(numero>0)
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
		lista->listaZerada == (bool *) true
	){
		printf("\nA lista esta vazia.\n");
		return true;		
	}
	
	return false;
}

//Retorna false se a lista N�O for v�lida
bool validacaoListaCriada(tipoLista *lista){
			 
	if (lista->tamanhoDaLista == -1){
		limparTela();
		printf("Por favor, crie a lista primeiro.\n");
		pausa();
		return false;
	}

	return true;
}

// Se N�O for um n�mero natural, retorna -1
int lerNaturalValido(){

	int numero;	
	
	if(scanf("%d", &numero)){
		if(numeroNatural(numero))
			return numero;
	}
		
	limparTela();
	printf("Por favor, informe um n�mero natural.\n");	
	return(-1);
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

//A lista � inv�lida se n�o conseguiu alocar memoria ou ainda n�o foi criada
bool validarLista(tipoLista* lista) {

	//Validar alocacao de memoria lista
	if (!validarAlocacaoLista(lista)) return false;

	//Verificar se a funcao criarListaDePessoas j� foi chamada
	if (!validacaoListaCriada(lista)) return false;

	return true;
}

//Retorna true se conseguiu zerar a lista
bool zerarLista(tipoLista* lista) {

	//Validar aloca��o da lista
	if (!validarAlocacaoLista(lista)) return false;

	//Zerar lista
	lista->inicioDaLista = NULL;
	lista->finalDaLista = NULL;
	lista->tamanhoDaLista = 0;
	lista->listaZerada = (bool*)true;

	return true;
}

//Alocar memoria para uma pessoa
tipoPessoa* alocarPessoa(tipoPessoa* pessoa) {

	pessoa = NULL;

	//Alocar mem�ria para a pessoa
	pessoa = malloc(sizeof(tipoPessoa));

	//Validar aloca��o de mem�ria da pessoa
	if (!validarAlocacaoPessoa(pessoa)) pessoa = NULL;

	return pessoa;
}

//Ler dados de uma pesoa
tipoPessoa* lerDadosPessoa(tipoPessoa* pessoa) {

	printf("Digite os dados da pessoa, codigo, nome, idade e altura, repectivamente:\n(O codigo da pessoa nao pode ser zero)\n");
	scanf("%d", &pessoa->codigo);
	fflush(stdin);
	gets(pessoa->nome);
	fflush(stdin);
	scanf("%d", &pessoa->idade);
	fflush(stdin);
	scanf("%f", &pessoa->altura);
	fflush(stdin);

	return pessoa;
}

//Imprimir dados de uma pessoa
bool imprimirDadosDaPessoa(tipoPessoa* pessoa) {

	//Validar pessoa
	if (!validarAlocacaoPessoa(pessoa)) return false;

	//Imprimir dados da pessoa
	if (!validarImpressao(printf("Seguem os dados da pessoa:\n\n"))) return false;
	if (!validarImpressao(printf("1 - Codigo: %d\n", pessoa->codigo))) return false;
	if (!validarImpressao(printf("2 - Nome: %s\n", pessoa->nome))) return false;
	if (!validarImpressao(printf("3 - Idade: %d\n", pessoa->idade))) return false;
	if (!validarImpressao(printf("4 - Altura: %f\n", pessoa->altura))) return false;

	return true;
}

//Retorna -1 se n�o conseguiu ler o codigo
int lerCodigoPessoa() {

	//Imprimir solicita��o do c�digo
	if (!validarImpressao(printf("Informe o codigo da pessoa:"))) return false;

	//Ler o c�digo
	int codigo = lerNaturalValido();

	//Validar c�digo	
	if (!numeroNatural(codigo)) return (-1);

	return codigo;
}

//Retorna nulo quando o c�digo n�o foi encontrado.
tipoPessoa* buscarCodigoNaLista(tipoLista* lista, int codigo) {

	//Validar lista
	if (!validarLista(lista)) return NULL;

	//Validar codigo
	if (!numeroNatural(codigo)) return NULL;

	//Verificar se a lista � vazia
	if (listaVazia(lista)) return NULL;

	//Cria uma variavel auxiliar para procurar a pessoa
	tipoPessoa* pessoaAtual = lista->inicioDaLista;

	while (pessoaAtual != NULL) {

		//Verifica se o c�digo foi encontrado e retorna o ponteiro da pessoa
		if (pessoaAtual->codigo == codigo) {
			return pessoaAtual;
		}
		
		//Vai para a proxima pessoa
		if (pessoaAtual != NULL)
			pessoaAtual = pessoaAtual->proximo;
		
	}

	printf("\nO codigo informado nao esta na lista.\n\n");
	free(pessoaAtual);

	return NULL;
}

//Imprime uma mensagem de sucesso na tela
bool mensagemSucesso() {

	if (!validarImpressao(printf("\nOperacao realizada com sucesso.\n\n"))) return false;

	return true;
}

//Destroi uma pessoa da lista, a pessoa n�o pode ser nula
bool destruirPessoa(tipoLista* lista, tipoPessoa* pessoa) {

	//Validar lista
	if (!validarLista(lista)) return false;

	//Validar pessoa, a pessoa n�o pode ser nulo
	if (!validarAlocacaoPessoa(pessoa)) return false;

	//Caso 1 - A lista possui apenas um elemento
	if (
		pessoa->anterior == NULL &&
		pessoa->proximo == NULL &&
		lista->inicioDaLista == pessoa &&
		lista->finalDaLista == pessoa
		) {

		//Zerar lista
		if (!zerarLista(lista)) return false;
	}

	//Caso 2 - A lista possui mais de um elemento e o elemento a ser removido � o PRIMEIRO
	if (
		pessoa->anterior == NULL &&
		pessoa->proximo != NULL &&
		lista->inicioDaLista == pessoa &&
		lista->finalDaLista != pessoa
		) {

		//Atribuir o segundo item da lista como sendo o primeiro
		lista->inicioDaLista = pessoa->proximo;

		//O agora novo primeiro item da lista deve ter seu "anterior" apontado para nulo
		lista->inicioDaLista->anterior = NULL;

		//Decrementar o tamanho da lista
		lista->tamanhoDaLista--;
	}

	//Caso 3 - A lista possui mais de um elemento e o elemento a ser removido � o �LTIMO
	if (
		pessoa->anterior != NULL &&
		pessoa->proximo == NULL &&
		lista->inicioDaLista != pessoa &&
		lista->finalDaLista == pessoa
		) {

		//Atribuir o item anterior como �ltimo da lista
		lista->finalDaLista = pessoa->anterior;

		//O agora novo �ltimo item da lista deve ter seu "proximo" apontado para nulo
		lista->finalDaLista->proximo = NULL;

		//Decrementar o tamanho da lista
		lista->tamanhoDaLista--;
	}

	//Caso 4 - A lista possui mais de um elemento e o elemento a ser removido est� no MEIO da lista
	if (
		pessoa->anterior != NULL &&
		pessoa->proximo != NULL &&
		lista->inicioDaLista != pessoa &&
		lista->finalDaLista != pessoa
		) {

		//O "proximo" do item anterior ao que est� sendo removido deve apontar para o "proximo" do item removido
		tipoPessoa* pessoaAuxiliar = pessoa->anterior;
		pessoaAuxiliar->proximo = pessoa->proximo;

		//O "anterior" do item seguinte ao que est� sendo removido deve apontar para o "anterior" do item removido
		pessoaAuxiliar = pessoa->proximo;
		pessoaAuxiliar->anterior = pessoa->anterior;

		//Decrementar o tamanho da lista
		lista->tamanhoDaLista--;
	}

	//Limpa memoria (apagar de fato a pessoa
	free(pessoa);

	//Mensagem ao usuario
	if (!mensagemSucesso()) return false;
}
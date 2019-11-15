#include "validacoes.h"

//Imprime uma mensagem de sucesso na tela
void mensagemSucesso() {

	printf("\nOperacao realizada com sucesso.\n");
}

//Alocar mem�ria para um novo item da �rvore
itemDaArvore* alocarItemDaArvore() {

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

	//Verificar se a palavra � nula
	if (!validarAlocacaoDeMemoria(palavra)) return false;

	//Verificar se a raiz � nula
	if (!validarAlocacaoDeMemoria(raiz)) return false;

	//Criar ponteiro auxiliar do tipo 'item da arvore'
	itemDaArvore* itemAuxiliar = raiz;

	//Percorrer a �rvore at� o final da palavra ou a palavra n�o existir
	for (int i = 0; i < (strlen(palavra) - 1); i++)
	{
		//Verifica se a letra corrente/atual est� na �rvore
		if (itemAuxiliar->proximaLetra[*palavra - 'a'] == NULL) {

			//Se ainda n�o tiver chegado no final da palavra
			if (i < (strlen(palavra) - 2))
			{
				//Sai do la�o
				printf("\nA palavra nao esta na arvore.\n");
				return true;
			}

			//Se chegou no final da palavra
			if (i == (strlen(palavra) - 2))
			{
				//Verifica se c�digo foi preenchido
				if (itemAuxiliar->chave > -1)
				{
					printf("\nA palavra '%s' esta na arvore.\nSua chave e: %d\n", palavra, itemAuxiliar->chave);
					return true;
				}

				//Verifica se o c�digo � -1
				if (itemAuxiliar->chave == -1)
				{
					printf("\nA letras da palavra '%s' estao na arvore.\nPor�m sua chave/c�digo � igual a: %d\n", palavra, itemAuxiliar->chave);
					return true;
				}

				lancarErro(29);
				return false;
			}
		}

		//Passa para o pr�ximo item
		itemAuxiliar = itemAuxiliar->proximaLetra[*palavra - 'a'];
	}

	lancarErro(28);
	return false;
}

#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
    int numero;
    cout << "Digite um numero: ";
    cin >> numero;

    if (posicaoElemento(numero) != NULL) {
        cout << "Esse numero já foi inserido na lista. Insira outro.\n";
        return;
    }

    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        return;
    }

    novo->valor = numero;
    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
    } else {
        NO* aux = primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    cout << "Numero inserido.\n";
}

void excluirElemento()
{
    int numero;
    cout << "Digite o numero para excluir: ";
    cin >> numero;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        cout << "Numero não foi encontrado. Tente outro.\n";
        return;
    }

    if (anterior == NULL) { 
        primeiro = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    cout << "Numero excluido.\n";
}	
}

void buscarElemento()
{
	int numero;
	cout << "Digite o numero que deseja buscar: ";
	cin >> numero;

	NO* resultado = posicaoElemento(numero);

	if (resultado != NULL) {
		cout << "Numero encontrado\n";
	}
	else {
		cout << "Numero não encontrado\n";
	}	
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}

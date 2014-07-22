#include<stdio.h>
#include<conio.h>

/* ESTRUTURA */
typedef struct filaNo *No;

struct filaNo
{
	int dado;
	No proximo;
};

typedef struct
{
	No direita;
	No esquerda;
}fila;

/* ESTRUTURA DEQUE */
void inicializaDeque(fila *d)
{
	d->direita = NULL;
	d->esquerda = NULL;
}

/*VERIFICA SE ESTÁ VAZIO*/
int estaVazio(fila *d)
{
	if((d->esquerda)==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*INSERE PELA DIREITA*/
void InsereEsq(fila *d,int x)
{
	No t = (No)malloc(sizeof(struct filaNo));
	t->dado = x;
	t->proximo = NULL;

	if(estaVazio(d))
	{
		d->esquerda->proximo = t;
		d->esquerda = t;
	}
	else
	{
		d->direita = t;
		d->esquerda = t;
	}
}

/*INSERE PELA ESQUERDA*/
void InsereDir(fila *d,int x)
{
	No t = (No)malloc(sizeof(struct filaNo));
	t->dado = x;
	t->proximo = NULL;

	if(estaVazio(d))
	{
		t->proximo = d->direita;
		d->direita = t;
	}
	else
	{
		d->direita = t;
		d->esquerda = t;
	}
}


/*RETIRA PELA DIREITA*/
int RetiraEsq(fila *d)
{
	No t = d->direita;
	No tr = d->esquerda;
	int x = tr->dado;
	if(t==tr)
	{
		d->direita = NULL;
		d->esquerda = NULL;
	}
	else
	{
		while((t->proximo)!=tr)
		{
			t = t->proximo;
		}

		d->esquerda = t;
		t->proximo = NULL;
	}

	free(tr);
	return x;
}

/*RETIRA PELA ESQUERDA*/
int RetiraDir(fila *d)
{
	No t = d->direita;
	int x = t->dado;
	if((d->direita)==(d->esquerda))
	{
		d->direita = NULL;
		d->esquerda = NULL;
	}
	else
	{
		d->direita = t->proximo;
	}
	free(t);
	return x;
}

/*IMPRIME TODA A FILA*/
void printDeque(fila *d)
{
	if(d->direita==NULL && d->esquerda==NULL)
		printf("\nDeque vazio!\n");
	else
	{
    	No t = d->direita; //ALTERADO
    	printf("\n");
    	while(t!=NULL)
    	{
    		printf("/ %d ",t->dado);
    		t = t->proximo;
    	}
    	printf("/\n");
	}
}

/*REMOVE TODA A FILA*/
void ApagaTudo(fila *d)
{
	d->direita = NULL;
	d->esquerda = NULL;
	if(d->direita==NULL && d->esquerda==NULL)
		printf("\nElementos removidos com sucesso!\n");
	else
		printf("\nErro ao remover tudo!\n");
}


void Ordena(fila *d)
{
    int continua=0;
    No AntesdeAnt = d->direita, pos= d->direita, ant = d->direita;
    pos=pos->proximo;

	if(d->direita->proximo != d->esquerda && d->direita != d->esquerda)		// Só entra se tiver mais de 2 itens no Deque.
	{
	    do												// Enquanto não correr todo o fila SEM fazer NENHUMA alteração, ele continuará em loop (usa o 'continue' pra isso);
	    {
			continua=0;
			while(ant->proximo->proximo != NULL)				// Ele corre até a penultima casa.
			{
				if(ant->dado > pos->dado)
				{
					continua++;
					ant->proximo = pos->proximo;
					pos->proximo = ant;
					if(d->direita == ant)						// Se a troca foi feita na primeira e segunda casa, ele direciona d->fundo para a nova primeira posição;
					{
						d->direita = pos;
						AntesdeAnt = d->direita;
					}
					else
					{
						AntesdeAnt->proximo = pos;
						AntesdeAnt = AntesdeAnt->proximo;
					}
					if(ant->proximo->proximo != NULL)			// Tava dando erro qnd tentei ir até a ultima casa, então contornei o erro.
						pos=ant->proximo;
				}
				else										// Se não houve troca, então os ponteiros avançam pras próximas casas.
				{
					if(d->direita != ant)
						AntesdeAnt = AntesdeAnt->proximo;
					ant = ant->proximo;
					pos = pos->proximo;
				}
			}
			if(ant->dado > ant->proximo->dado)					// Devido ao erro que comentei acima, resolvo aqui a necessidade de troca da ultima e penultima casa.
			{	continua++;
				pos->proximo = d->esquerda;
				d->esquerda->proximo = ant;
				ant->proximo = NULL;
				d->esquerda = ant;
			}
			ant = d->direita;								// Os ponteiros voltam a apontar para as casas iniciais para um novo loop.
			pos = ant->proximo;
			AntesdeAnt = d->direita;
	    }while(continua >0);
	}
	else
	{
		if(d->direita->proximo == d->esquerda)						// Se o Deque tiver só 2 casas, será resolvido aqui.
		{
			d->direita = pos;
			d->esquerda = ant;
			pos->proximo = ant;
			ant->proximo = NULL;
		}
	}
	return;
}


/*QUANTIDADE DE ITENS*/
void Busca(fila *d, int x)
{
   No t = d->direita;
   int loop;

   while (t != NULL)
   {
		if( t->dado == x)
		    loop++;
			t = t->proximo;
	}
   printf("\nNumero de vezes encontrado: %d\n", loop);
   return;
}



int main()
{

	int x, op=-1, valor;
	fila *d;
	system("cls");
	d=(fila*)malloc(sizeof(fila));
	inicializaDeque(d);

	while(op != 0)
	{
		printf("\n====================================FILA DEQUE================================\n\n");
		printf("1 - Inserir pela direita\n");
		printf("2 - Inserir pela esquerda\n");
		printf("3 - Remover pela direita\n");
		printf("4 - Remover pela esquerda\n");
		printf("5 - Imprimir tudo\n");
		printf("7 - Organizar\n");
		printf("8 - Remover tudo\n");
		printf("\nDigite a opcao desejada ('0' para sair): ");
		scanf("%d", &op);

		switch(op)
		{
			case 1:
			{
				printf("\nDigite o valor (pela direita): ");
				scanf("%d", &valor);
				InsereFrent(d,valor);
				break;
			}
			case 2:
			{
				printf("\nDigite o valor (pela esquerda): ");
				scanf("%d", &valor);
				InsereFund(d,valor);
				break;
			}
			case 3:
			{
				if(estaVazio(d))
					RetiraFrent(d);
				break;
			}
			case 4:
			{
				if(estaVazio(d))
					RetiraFund(d);
				break;
			}
			case 5:
			{
				printDeque(d);
				break;
			}
			case 6:
			{
				printf("\nDigite o valor: ");
				scanf("%d", &valor);
				Busca(d,valor);
				break;
			}
			case 7:
			{
				Ordena(d);
				break;
			}
			case 8:
			{
				ApagaTudo(d);
				break;
			}
			default:
			{
				if (op == 0)
				{
					return 0;
				}
				else
				{
					printf("\nOpcao invalida! Digite a opcao novamente \n");
				}

			}

		}
	}

	system("pause");
	return 0;
}

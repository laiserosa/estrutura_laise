#include<stdio.h>
#include<conio.h>
#include <time.h>

	// ******* ESTRUTURA DEQUE *******

typedef struct dequeNo *link;
double tempoB=0, tempoO=0;
struct dequeNo
{
	int dado;
	link proximo;
};

typedef struct
{
	link fundo;
	link frente;
}deque;

	// ******* ESTRUTURA DEQUE *******
void inicializaDeque(deque *d)
{
	d->fundo = NULL;
	d->frente = NULL;
}


	// ******* VERIFICA SE TA VAZIO. *******
int taVazio(deque *d)
{
	if((d->frente)==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

	// ******* INSERE PELA frente (DIREITA) <- . *******
void InsereFrent(deque *d,int x)
{
	link t = (link)malloc(sizeof(struct dequeNo));
	t->dado = x;
	t->proximo = NULL;

	if(taVazio(d))
	{
		d->frente->proximo = t;
		d->frente = t;
	}
	else
	{
		d->fundo = t;
		d->frente = t;
	}
}

	// ******* INSERE PELO fundo (ESQUERDA) -> . *******
void InsereFund(deque *d,int x)
{
	link t = (link)malloc(sizeof(struct dequeNo));
	t->dado = x;
	t->proximo = NULL;

	if(taVazio(d))
	{
		t->proximo = d->fundo;
		d->fundo = t;
	}
	else
	{
		d->fundo = t;
		d->frente = t;
	}
}


	// ******* RETIRA PELA frente (DIREITA) <- . *******
int RetiraFrent(deque *d)
{
	link t = d->fundo;
	link tr = d->frente;
	int x = tr->dado;
	if(t==tr)
	{
		d->fundo = NULL;
		d->frente = NULL;
	}
	else
	{
		while((t->proximo)!=tr)
		{
			t = t->proximo;
		}

		d->frente = t;
		t->proximo = NULL;
	}

	free(tr);
	return x;
}

	// ******* RETIRA PELO fundo (ESQUERDA) -> . *******
int RetiraFund(deque *d)
{
	link t = d->fundo;
	int x = t->dado;
	if((d->fundo)==(d->frente))
	{
		d->fundo = NULL;
		d->frente = NULL;
	}
	else
	{
		d->fundo = t->proximo;
	}
	free(t);
	return x;
}

	// ******* IMPRIMI TODO O DEQUE. *******
void printDeque(deque *d)
{
	if(d->fundo==NULL && d->frente==NULL)
		printf("\nDeque vazio!\n");
	else
	{
    	link t = d->fundo; //ALTEREI
    	printf("\n");
    	while(t!=NULL)
    	{
    		printf("| %d ",t->dado);
    		t = t->proximo;
    	}
    	printf("|\n");
	}
}

	// ******* LIMPA TODO O DEQUE. *******
void ApagaTudo(deque *d)
{
	d->fundo = NULL;
	d->frente = NULL;
	if(d->fundo==NULL && d->frente==NULL)
		printf("\nDeque apagado com sucesso!\n");
	else
		printf("\nErro ao apagar tudo!\n");
}


void Ordena(deque *d)
{
	tempoO = clock();
    int continua=0;
    link AntesdeAnt = d->fundo, pos= d->fundo, ant = d->fundo;
    pos=pos->proximo;

	if(d->fundo->proximo != d->frente && d->fundo != d->frente)		// Só entra se tiver mais de 2 itens no Deque.
	{
	    do												// Enquanto não correr todo o deque SEM fazer NENHUMA alteração, ele continuará em loop (usa o 'continue' pra isso);
	    {
			continua=0;
			while(ant->proximo->proximo != NULL)				// Ele corre até a penultima casa.
			{
				if(ant->dado > pos->dado)
				{
					continua++;
					ant->proximo = pos->proximo;
					pos->proximo = ant;
					if(d->fundo == ant)						// Se a troca foi feita na primeira e segunda casa, ele direciona d->fundo para a nova primeira posição;
					{
						d->fundo = pos;
						AntesdeAnt = d->fundo;
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
					if(d->fundo != ant)
						AntesdeAnt = AntesdeAnt->proximo;
					ant = ant->proximo;
					pos = pos->proximo;
				}
			}
			if(ant->dado > ant->proximo->dado)					// Devido ao erro que comentei acima, resolvo aqui a necessidade de troca da ultima e penultima casa.
			{	continua++;
				pos->proximo = d->frente;
				d->frente->proximo = ant;
				ant->proximo = NULL;
				d->frente = ant;
			}
			ant = d->fundo;								// Os ponteiros voltam a apontar para as casas iniciais para um novo loop.
			pos = ant->proximo;
			AntesdeAnt = d->fundo;
	    }while(continua >0);
	}
	else
	{
		if(d->fundo->proximo == d->frente)						// Se o Deque tiver só 2 casas, será resolvido aqui.
		{
			d->fundo = pos;
			d->frente = ant;
			pos->proximo = ant;
			ant->proximo = NULL;
		}
	}
	tempoO = clock() - tempoO;
	return;
}


	// ******* LOCALIZA QUANTIDADE DE ITENS *******
void Busca(deque *d, int x)
{
	tempoB = clock();
   link t = d->fundo;
   int conta;

   while (t != NULL)
   {
		if( t->dado == x)
		    conta++;
			t = t->proximo;
	}
	tempoB = clock() - tempoB;
   printf("\nNumero de vezes encontrado: %d\n", conta);
   return;
}



int main()
{
	int i=0;
	int InfoInserir;
	int x, op=-1, valor;
	deque *d;
	system("cls");
	d=(deque*)malloc(sizeof(deque));
	inicializaDeque(d);

	while(op != 0)
	{
		system("pause");
		system("cls");
		printf("\n\n           DEQUE        \n\n");
		printf("( 1 ) Insere pela Direita.\n");
		printf("( 2 ) Insere pela Esquerda.\n");
		printf("( 3 ) Remove pela Direita. \n");
		printf("( 4 ) Remove pela Esquerda.\n");
		printf("( 5 ) Exibe.\n");
		printf("( 6 ) Busca. \n");
		printf("( 7 ) Organiza. \n");
		printf("( 8 ) Limpa Tudo. \n");
		printf("\nTempo na Busca: %f\n", tempoB/CLOCKS_PER_SEC);
		printf("Tempo no Organizar: %f\n", tempoO/CLOCKS_PER_SEC);
		printf("\nInforme a operacao: ");
		scanf("%d", &op);

		switch(op)
		{
			case 1:
			{
				printf("Diga quantos valores deseja inserir pela Direita <-: ");
				scanf("%d", &InfoInserir);
				for(i=InfoInserir; i>0; i--)
					InsereFrent(d,i);
				break;
			}
			case 2:
			{
				printf("Diga quantos valores deseja inserir pela Esquerda ->: ");
				scanf("%d", &InfoInserir);
				for(i=0; i<InfoInserir; i++)
				InsereFund(d,i);
				break;
			}
			case 3:
			{
				if(taVazio(d))
					RetiraFrent(d);
				break;
			}
			case 4:
			{
				if(taVazio(d))
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
				printf("Informe valor para busca :");
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
				printf("\nErro: Opcao invalida! Informe novamente.\n");
			}

		}
	}

	system("pause");
	return 0;
}

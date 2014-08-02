#include <stdio.h>
#include <string.h>

typedef struct Arvore{
        char nome[31];
        char sexo;

        struct Arvore *parents;
        struct Arvore *brot;
        struct Arvore *son;
        struct Arvore *conjuge;

}Arv;


struct Arvore * AddMembro(Arv *Membro);
struct Arvore * pos_ordem(Arv *Membro, char *buscaNome);
int relacaoParentesco();

int main()
{
    int k=0;
    Arv *Membro = NULL;

    while(!k)
    {
        Membro = AddMembro(Membro);
        printf("\n\n\n\n Teste: %s, %c", Membro->nome, Membro->sexo);
    }

    return 0;
}

struct Arvore *AddMembro(Arv *Membro)
{
	Arv *NovoMembro = (Arv*)malloc(sizeof(Arv));
	Arv *parente = NULL;
	char buscaNome[31];
	int op;

	if(Membro == NULL)	// Somente pra inserir a raiz, todos os outros membros é em else.
	{
		Membro = NovoMembro;

		printf("Nome: ");
		scanf("\n\r%[^\n]", &Membro->nome);
		setbuf(stdin,NULL);

		printf("Sexo: ");
		scanf("%c", &Membro->sexo);
		setbuf(stdin,NULL);
	}
	else
	{
		printf("Nome: ");
		scanf("\n\r%[^\n]", &Membro->nome);
		setbuf(stdin,NULL);

		printf("Sexo: ");
		scanf("%c", &Membro->sexo);
		setbuf(stdin,NULL);

		printf("Informe nome da pessoa que tera alguma relacao com a nova: ");
		scanf("\n\r%[^\n]", &buscaNome);
		setbuf(stdin,NULL);

		op = relacaoParentesco();


		if(op == 1)
		{
			parente = pos_ordem(Membro, buscaNome);
			/*sera inserido o conjuge. O ponteiro parente sera o Conjuge de NovoMembro.*/

/*			TENTATIVA DE BUSCAR O CONJUGE
            parente->conjuge = NewMembro;
            NewMembro->conjuge = parente; */
		}
		if(op == 2)
		{
			parente = pos_ordem(Membro, buscaNome);
			/*sera inserido o Filho. O ponteiro parente sera o Filho mais novo de NovoMembro.*/

		}
		if(op == 3)
		{
			parente = pos_ordem(Membro, buscaNome);
			/*sera inserido o irmao. O ponteiro parente sera o irmao mais velho em relacao ao NovoMembro.*/
		}
		else
			printf("Opcao errada, insira novamente esta pessoa.\n");
	}

	return Membro;
}

int relacaoParentesco()
{
	int op;
	printf("Infome relacao parentesco: ");
	printf("1 - Conjuge.");
	printf("2 - Filho.");
	printf("3 - irmao.");
	scanf("%d", &op);

	return op;
}


struct Arvore * pos_ordem(Arv *busca, char *buscaNome)
{
	if(busca != NULL)
	{
		if( (strcmp(buscaNome, busca->nome) == 0) )
			return busca;
		busca = pos_ordem(busca->brot, buscaNome);
		busca = pos_ordem(busca->son, buscaNome);
		busca = pos_ordem(busca->conjuge, buscaNome);
	}

	return NULL;
};

#define T 50/*NUMERO MAXIMO DE CADASTROS*/
/*ESTRUTURA DO CADASTRO*/
typedef struct{
        char nome[50], endereco[60], nomeMercado[30], dataCheque[12];
        int id, identidade, telefoneCliente;
        float valor;
}CLIENTE;/*FINAL DA ESTRUTURA DO CADASTRO*/

/*ESTRUTURA DA PILHA DE CADASTRO*/
typedef struct{
        int topo;
        CLIENTE cli[T];
}PILHA;/*FIM DA ESTRUTURA DA PILHA DE CADASTRO*/


void iniciarPilha(PILHA *);/*INICIALIZA A PILHA*/
int menu();/*MOSTRA MENU*/
int menuChefe();/*MENU DO CHEFE*/
int menuRelatorio();/*MENU DO RELATORIO*/


int overflow(PILHA *);/*VERIFICA SE A PILHA ESTÁ CHEIA*/
int underflow(PILHA *);/*VERIFICA SE A PILHA ESTÁ VAZIA*/
void push(PILHA *, CLIENTE *);/*INSERE NA PILHA*/
void pushPrioridade(PILHA *, PILHA * ,CLIENTE *);//INSERE QUANDO TEM PRIORIDADES
void OrganizarPIlhaPrioridadeValor(PILHA *, PILHA *);/*ORGANIZA A PILHA PELA PRIORIDADE DO VALOR DO CHEQUE*/
void OrganizarPIlhaPrioridadeMercado(PILHA *, PILHA *);/*ORGANIZA PRIORIDADE QUE O CHEFE DETERMINA PARA O MERCADO*/
void OrganizarDecrescente(PILHA *, PILHA *);/*PROCESSO DE ORGANIZAR EM ORDEM DECRESCENTE PELO MERCADO //
PREPARA PARA OS RETIRADOS RETORNAREM PARA A PILHA ORIGINAL */
void removerCasoResolvido(PILHA *, int processo);/*REMOVE CASO RESOLVIDO PELO CHEFE*/
void imprimirPilhaSimplificada(PILHA *);/*IMPRIME UM SÓ ELEMENTO*/
void imprimirPilhaEscolhido(PILHA *, int id);/*IMPRIME POR BUSCA ESCOLHIDA // POR ID, POR BASE, POR TOPO*/


CLIENTE pop(PILHA *);/*REMOVE UM SÓ ELEMENTO*/
void imprimirPilha(PILHA *);/*IMPRIME A PILHA INTEIRA COM TODOS OS ELEMENTOS*/
void removerEscolhido(PILHA *, PILHA *, int esc);/*REMOVE UM ELEMENTO DA PILHA ESCOLHIDO*/

void relatorio(PILHA *, int op);/*RELATORIO*/


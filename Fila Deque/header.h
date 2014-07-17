#define T 10

typedef struct{
    int num;
}NUMERO;

 typedef struct{
         int n, ini;
         NUMERO numero[T];
 }FILA;
 
 
//funções de controle
int menu();
void iniciarFila(FILA *f);//função para inciar a fila
void inserirInicio(FILA *f,NUMERO *n);
void inserirFim(FILA *f,NUMERO *n);
void removerInicio(FILA *f);
void removerFim(FILA *f);
int vazia(FILA *f);
int cheia(FILA *f);
void imprimir(FILA *f);
void ordenar(FILA *f);

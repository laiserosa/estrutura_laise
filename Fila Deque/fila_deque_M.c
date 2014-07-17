#include <stdio.h>
#include <time.h>
#include "header.h"

//função main
int main(){
	FILA fil;
	NUMERO numero;
    int opc;

    iniciarFila(&fil);
    do{
      opc = menu();
      switch(opc){
       	case 1:
       		getchar();
            if(!cheia(&fil)){
               printf("\nInforme um numero: ");
               scanf("%d",&numero.num);
               inserirInicio(&fil,&numero);
               printf("\nInserido no inicio da fila com sucesso\n");
               ordenar(&fil);
               }else
               printf("\nFila cheia!\n");


            getch();
            system("cls");
       	break;
       	case 2:
       		getchar();
            if(!cheia(&fil)){
               printf("\nInforme um numero: ");
               scanf("%d",&numero.num);
               inserirFim(&fil,&numero);
               printf("\nInserido no fim da fila com sucesso\n");
               ordenar(&fil);
               }else
               printf("\nFila cheia!\n");
            getch();
            system("cls");
       	break;
       	case 3:
            if(!vazia(&fil)){
            	printf("\nRemovido do inicio da fila com sucesso");
			   removerInicio(&fil);
            }

            else
               printf("\nFila vazia!\n\n");
            getch();
            system("cls");
       	break;
       	case 4:
       		if(!vazia(&fil)){
            	printf("\nRemovido do fim da fila com sucesso");
			   removerFim(&fil);
            }

            else
               printf("\nFila vazia!\n\n");
            getch();
            system("cls");
       	break;
       	case 5:
            if(!vazia(&fil))
               imprimir(&fil);
            else
               printf("\nFila vazia!\n\n");
            getch();
            system("cls");
       	break;
       	case 0: break;
       	default: printf("\nOpcao incorreta!\n\n");
      }
    }while(opc != 0);

}

int menu(){
    int opc;

    printf("=====================================FILA DEQUE=================================\n\n"
            "1-Inserir no inicio\n"
    		"2-Inserir no fim\n"
    		"3-Remover no inicio\n"
    		"4-Remover no fim\n"
            "5-Imprimir\n"
            "0-Sair\n"
            "\nDigite a opcao desejada: ");
    scanf("%d",&opc);
    return opc;
}

void iniciarFila(FILA *f){
     f->n =0;
     f->ini = 0;
}
void inserirInicio(FILA *f, NUMERO *n){//função para inserir
     int fim, aux, cont = 0, cont2 = 0, contN = 0, cont3 = 0;



     FILA temp;
     iniciarFila(&temp);
     temp = *f;
     iniciarFila(f);
     fim = (f-> ini + f-> n) % T;
     f->numero[fim] = *n;
     f->n++;
     for(aux = 0; aux < temp.n; aux++){

		fim = (f-> ini + f-> n) % T;
		f->numero[fim] = temp.numero[aux];
		f->n++;
	}

}
void inserirFim(FILA *f, NUMERO *n){
	int fim;


    fim = (f-> ini + f-> n) % T;
    f->numero[fim] = *n;
    f->n++;

}
void removerInicio(FILA *f){
      f->ini  =(f->ini +1) % T;
      f->n--;
}
void removerFim(FILA *f){
	f->n--;
}
int vazia(FILA *f){
    return f-> n == 0;
}
int cheia(FILA *f){
    return f-> n == T;
}
void imprimir(FILA *f){
    int aux, fim, cont = 0;

     fim = (f->ini + f-> n-1)% T;

     if(f->ini == 0 || f-> ini <= fim || fim == T -1)
       for(aux = f-> ini; aux<= fim; aux++)
       {
       	cont++;
       	  printf("[%d]->%d\t",cont,f->numero[aux].num);
       }

     else{
          for(aux = f->ini; aux < T; aux ++)
          {
          	cont++;
          	 printf("[%d]->%d\t",cont,f->numero[aux].num);
          }

          for(aux = 0; aux <=fim; aux++)
          {
          	cont++;
          	 printf("[%d]->%d\t",cont,f->numero[aux].num);
          }

     }
     printf("\n\n");

}
void ordenar(FILA *f){
	int x, y, aux;


		for(x=0;x<f->n;x++){
        for(y=0;y<f->n-1;y++){
          if(f->numero[y].num > f->numero[y+1].num){
             aux=f->numero[y].num;
             f->numero[y].num=f->numero[y+1].num;
             f->numero[y+1].num=aux;
             }
          }
    	}



}



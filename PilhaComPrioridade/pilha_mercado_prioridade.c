#include <stdio.h>
#include <time.h>
#include "header.h"
#define T 50/*NUMERO MAXIMO DE CADASTROS*/

int idCliente = 0;/*CADASTRO DOS ID*/
int contPrioridade = 0;//FAZ CONTAGEM DAS PRIORIDADES
int main(){


    PILHA pil, temp;/*PIL = PILHA ORIGINAL // TEMP = PILHA AUXILIAR*/
    CLIENTE cliente;/*EFETUAR O CADASTRO DO CLIENTE*/
    int opc, opChefe, opRelatorio,  processo;/*VARIÁVEIS PARA AUXILIAR OS MENUS E CASO RESOLVIDO*/
	double tempo_gasto;//tempo gasto
	clock_t tempo_inicial, tempo_final;


    iniciarPilha(&pil);/*INICIAR A PILHA ORIGINAL*/
    iniciarPilha(&temp);/*INICIAR A PILHA TEMP*/

    do{
       opc = menu();/*MENU PRINCIPAL*/
       switch(opc){
           case 1:

               system("cls");
               getchar();
               if(!overflow(&pil))/*VERIFICAR SE A PILHA ESTÁ CHEIA*/
               {
               		idCliente++;/*CADA CADASTRO TERÁ SEU ID, NÃO IMPORTA SE REMOVIDO OU NÃO*/
               		printf("Informe o nome do cliente: ");
               		gets(cliente.nome);
               		printf("Informe o endereco do cliente: ");
               		gets(cliente.endereco);
               		printf("Informe a identidade do cliente: ");
               		scanf("%d",&cliente.identidade);
               		printf("Informe o telefone do cliente: ");
               		scanf("%d",&cliente.telefoneCliente);
					printf("Informe o valor da conta: ");
               		scanf("%f",&cliente.valor);
               		getchar();
               		printf("Informe o nome do supermercado: ");
               		gets(cliente.nomeMercado);
               		printf("Informe a data do cheque: ");
               		gets(cliente.dataCheque);
               		//informações do cadastro

           	  tempo_inicial = clock();//tempo inicial

               		cliente.id = idCliente;
               		getchar();
               		if(contPrioridade == 0){
               			push(&pil, &cliente);//insere na pilha QUANDO NÃO TEM PRIORIDADE
               			OrganizarPIlhaPrioridadeValor(&pil, &temp);/*ORGANIZANDO A PILHA PELO VALOR DO CHEQUE MAIS ALTO*/
               		}else if(contPrioridade != 0){

               			pushPrioridade(&pil, &temp, &cliente);//QUANDO TEM PRIORIDADES FUNÇAÕ DIFIRENTE E CHAMADA

               		}

			tempo_final = clock();
			tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   			printf("\nTempo gasto: %lf s\n", tempo_gasto);

               		printf("\nCadastrado com sucesso");

     				getch();

               }
               else
               {
               		printf("\nPilha cheia");
               }
   			getch();

           break;
           case 2:
           		tempo_inicial = clock();//tempo inicial
           	  if(!underflow(&pil)){/*VERIFICA SE A PILHA ESTÁ VAZIA*/
           	  	imprimirPilha(&pil);
           	  }
           	  else{
           	  	printf("\nCadastro vazio");
           	  }
           	    tempo_final = clock();
				tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   				printf("\nTempo gasto: %lf s\n", tempo_gasto);

           	  getch();
           break;
           case 3:
           	   do{
           	   		opChefe = menuChefe();/*MENU DO CHEFE*/
           	   		switch(opChefe){
           	   			case 1:
           	   				tempo_inicial = clock();//tempo inicial
           	   				if(!underflow(&pil)){/*VERIFICA PILHA VAZIA*/
           	   					OrganizarPIlhaPrioridadeMercado(&pil, &temp);/*CHAMA A FUNÇÃO PARA ALOCAR OS MERCADOS QUE SÃO PRIORIDADE PARA O CHEFE*/
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);

           	   				getch();
           	   			break;
           	   			case 2:
           	   				tempo_inicial = clock();//tempo inicial
           	   				if(!underflow(&pil)){
           	   					imprimirPilhaSimplificada(&pil);/*MOSTRA CASO RESOLVIDO*/
           	   					printf("\nInforme o ID do caso ja resolvido para retirar do processo\n");
           	   					scanf("%d",&processo);
           	   					removerCasoResolvido(&pil, processo);/*CHAMA A FUNÇÃO PARA VERIFICAR QUAL É O PROCESSO
                                                                        E ELE É REMOVIDO*/
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           	   			break;
	           	   		case 0:
					   break;
			           default:
					    printf("Opcao invalida");
			           break;
           	   		}
           	   }while(opChefe != 0);

           	break;
           	case 4:
           		do{
           			opRelatorio = menuRelatorio();/*MENU DO RELATÓRIO*/
           			switch(opRelatorio){
           				case 1:
           						tempo_inicial = clock();//tempo inicial
           					if(!underflow(&pil)){/*VERIFICA SE ESTÁ VAZIA*/
           						printf("\n Identificadores dos processo:\n");
           	   					relatorio(&pil, 1);/*CHAMA A PILHA PARA IMPRIMIR SÓ OS IDENTIFICADORES*/
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           				break;
           				case 2:
           						tempo_inicial = clock();//tempo inicial
           					if(!underflow(&pil)){
           						printf("\n Nomes dos clientes dos processos:\n");
           	   					relatorio(&pil, 2);//2- para nomes dos processos
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           				break;
           				case 3:
           						tempo_inicial = clock();//tempo inicial
           					if(!underflow(&pil)){
           						printf("\n Valores dos cheques que estão na pilha\n");
           	   					relatorio(&pil, 3);
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           				break;
           				case 4:
           						tempo_inicial = clock();//tempo inicial
           					if(!underflow(&pil)){
           						printf("\nProcesso no topo\n");
           	   					relatorio(&pil, 4);
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           				break;
           				case 5:
           						tempo_inicial = clock();//tempo inicial
           					if(!underflow(&pil)){
           						printf("\nListar tudo\n");
           	   					imprimirPilha(&pil);
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           				break;
           				case 6:
           						tempo_inicial = clock();//tempo inicial
           					if(!underflow(&pil)){
           						printf("\nListar por ID\n");
           	   					relatorio(&pil, 6);
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           				break;
           				case 7:
           						tempo_inicial = clock();//tempo inicial
           					if(!underflow(&pil)){
           						printf("\nListar tudo que esta no topo\n");
           	   					relatorio(&pil, 7);
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           				break;
           				case 8:
           						tempo_inicial = clock();//tempo inicial
           					if(!underflow(&pil)){
           						printf("\nListar tudo que esta na base\n");
           	   					relatorio(&pil, 8);
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           				break;
           				case 9:
           						tempo_inicial = clock();//tempo inicial
           					if(!underflow(&pil)){
           	   					imprimirPilhaSimplificada(&pil);/*MOSTRA ALGUMAS CARACTERISTICAS DOS PROCESSOS*/
           	   					printf("\nInforme o ID que deseja remover.\n");
           	   					scanf("%d",&processo);
           	   					removerCasoResolvido(&pil, processo);/*CHAMA A FUNÇÃO PARA VERIFICAR QUAL É O PROCESSO
                                                                        E ELE É REMOVIDO*/
           	   				}
           	   				else{
           	   					printf("\nCadastro vazio");
           	   				}
           	   				tempo_final = clock();
							tempo_gasto = ( (double) (tempo_final - tempo_inicial) ) / CLOCKS_PER_SEC;
   							printf("\nTempo gasto: %lf s\n", tempo_gasto);


           	   				getch();
           				break;
           			   	case 0:
					   	break;
			           	default:
					    	printf("Opcao invalida");
			           	break;
           			}
           		}while(opRelatorio != 0);
           	break;
           case 0:
		   break;
           default:
		    printf("Opcao %d invalida",opc);
           break;

       }

    }while(opc != 0);
}
void iniciarPilha(PILHA *p){
     p->topo = -1;//inicia a pilha em -1, para quando começar a inserir, o elemento seja o 0, igual ao no vetor..
}


int menu(){/*MENU QUE IRÁ RETORNAR A OPÇÃO ESCOLHIDA*/

    int opc;
    system("cls");
    printf("=================SISTEMA DE CHEQUES SEM FUNDOS DOS SUPERMERCADOS===============\n\n"
           "1-Novo cadastro\n"
           "2-Imprimir cadastros\n"
           "3-Chefia\n"
           "4-Relatorio \n"
           "0-Sair\n"
           "\nDigite a opcao desejada: ");

    scanf("%d", &opc);
    return opc;

}


int menuChefe(){/*IRÁ RETORNAR ESCOLHA DO CHEFE*/
    int opc;
    system("cls");
    printf("====================================MENU DA CHEFIA===============================\n\n"
           "1-Supermercado com prioridade\n"
           "2-Caso resolvido\n"
           "0-Voltar\n\n"
           "Digite a opcao desejada: ");
    scanf("%d", &opc);
    return opc;
}
int menuRelatorio(){
	int opc;
    system("cls");
    printf("1-Identificadores\n"
           "2-Nomes dos clientes\n"
           "3-Valores dos cheques que estao na pilha\n"
           "4-Processo do topo\n"
           "5-Listar tudo\n"
           "6-Listar as caracteristicas por ID:\n"
           "7-Listar as caracteristicas do topo\n"
           "8-Listar as caracteristicas do base\n"
           "9-Remover um processo com ID\n"
           "0-Sair\n");
    scanf("%d", &opc);
    return opc;

}
int overflow(PILHA *p){//verifica se o topo ao T que o maximo de cadastro que pode ter, -1, pq, a pilha começa no zero, sempre T-1
    return p->topo == T-1;
}
int underflow(PILHA *p){//verifica se esta vazia, como a pilha foi iniciada em -1, se retorna em -1 segnifica que esta vazia
    return p->topo == -1;
}
void push(PILHA *p, CLIENTE *cli){/*INSERÇÃO NA PILHA*/
     p->topo++;/*INCREMENTANDO O NUMERO DO TOPO*/
     p->cli[p->topo] = *cli;/*ADICIONA ESTRUTURA CLIENTE NA PILHA*/


}

void pushPrioridade(PILHA *p, PILHA *temp ,CLIENTE *cli){/*INSERÇÃO DA PRIORIDADE NA PILHA*/

	CLIENTE c;
	PILHA pt;
	int i, cont= 0, aux = 0;

	iniciarPilha(&pt);

	for(i = p->topo; i >= 0; i--)/*REMOVE ELEMENTOS DA PRIORIDADE E COLOCA NUMA PILHA TEMPORÁRIA*/
	{

		cont++;
		if(cont <= contPrioridade){

			push(temp, &p->cli[i]);  /*TODOS OS ELEMENTOS EM UMA TEMPORÁRIA*/

			removerEscolhido(p, &pt, i);/*REMOVE OS ELEMENTOS DA PILHA PRINCIPAL*/
		}
	}

	/*ADICIONA NOVO ELEMENTO CADASTRADO*/
	p->topo++;
    p->cli[p->topo] = *cli;/*ADICIONA STRUCT CLIENTE NA PILHA*/
    iniciarPilha(&pt);
	OrganizarPIlhaPrioridadeValor(p, &pt);/*ORGANIZA A PILHA PELA ORDEM DE CHEQUE DE VALOR MAIS ALTO*/
	/*PRIORIDADE VOLTA PARA O TOPO*/
	if(!overflow(&temp)){

		cont = temp->topo;
		do{
			push(p, &temp->cli[cont]);/*TUDO VOLTA PARA A PILHA PRINCIPAL*/
			removerEscolhido(temp, &pt, cont);/*REMOVE TUDO DA PILHA TEMPORÁRIA*/
			cont--;
		}while(cont != -1);//ate que fique em -1
	}

}


CLIENTE pop(PILHA *p){/*REMOVE UM CLIENTE DA PILHA*/
    CLIENTE c;
	c = p->cli[p->topo];//c recebe o elemento do topo e retorna c
	p->topo--;
	return c;
}

void imprimirPilha(PILHA *p){/*IMPRIMIR TODA A PILHA*/
     int aux;
     system("cls");

     for(aux = p->topo; aux >= 0; aux--){
         printf("Elemento[%d]",aux+1);
         printf("\nProcesso:[%d]",p->cli[aux].id);
         printf("\nNome cliente: %s",p->cli[aux].nome);
         printf("\nNome do supermercado: %s",p->cli[aux].nomeMercado);
         printf("\nEndereco do cliente: %s",p->cli[aux].endereco);
         printf("\nidentidade do cliente: %d",p->cli[aux].identidade);
         printf("\nTelefone do cliente: %d",p->cli[aux].telefoneCliente);
         printf("\nData do cheque: %s",p->cli[aux].dataCheque);
         printf("\nValor do cheque: %.2f",p->cli[aux].valor);
         printf("\n\n");
    }

}
void imprimirPilhaSimplificada(PILHA *p){/*IMPRIME PILHA EM ALGUNS ELEMENTOS*/
     int aux;
     system("cls");

     for(aux = p->topo; aux >= 0; aux--){
         printf("Elemento[%d]",aux+1);
         printf("\nId do processo: %d",p->cli[aux].id);
         printf("\nNome cliente: %s",p->cli[aux].nome);
         printf("\nNome do supermercado: %s",p->cli[aux].nomeMercado);
         printf("\n\n");
    }

}

void OrganizarPIlhaPrioridadeValor(PILHA *p, PILHA *temp){/*ORGANIZA A PILHA PELO VALOR*/
	int i, x, cont = 0;


	for(i = p->topo; i >=0; i--)
	{

		for(x = p->topo; x >0; x--)
		{
				if(p->cli[x].valor < p->cli[x-1].valor)//se o elemento atual for menor que o elemento debaixo ,
                                                        //trocar de posições
				{
					temp->cli[cont] = p->cli[x];//temp recebe o valor atual
					p->cli[x] = p->cli[x-1];//o atual recebe o anterior
					p->cli[x-1] = temp->cli[cont];// e o anterior recebe o temp

				}
		}
	}

}

void OrganizarDecrescente(PILHA *p, PILHA *temp){/*ORGANIZAR DECRESCENTE, VALORES MAIORES EMBAIXO*/
	int i, x, cont = 0;


	for(i = p->topo; i >=0; i--)
	{

		for(x = p->topo; x >0; x--)
		{
				if(p->cli[x].valor > p->cli[x-1].valor)
				{
					temp->cli[cont] = p->cli[x];
					p->cli[x] = p->cli[x-1];
					p->cli[x-1] = temp->cli[cont];

				}
		}
	}




}


void OrganizarPIlhaPrioridadeMercado(PILHA *p, PILHA *temp){/*ORGANIZAR PELA PRIORIDADE DO MERCADO EM DIFICULDADE FINANCEIRA*/
	CLIENTE c;
	PILHA pt;
	int i, cont= -1, aux = 0;
	getchar();
	iniciarPilha(&pt);
	printf("\nInforme o nome do supermercado: ");
	gets(c.nomeMercado);//recebe o nome
	contPrioridade = 0;
	for(i = p->topo; i >=0; i--)
	{
		if(strcmp(p->cli[i].nomeMercado,c.nomeMercado)==0){//verifica se o nome existe no cadastro
		contPrioridade++;
			aux = 1;//aux para saber se existe mesmo o nome informado
			push(temp, &p->cli[i]);		//coloca todos elementos com o mesmo numa temporaria
			removerEscolhido(p, &pt, i);//remove esses elementos da principal
		}
	}
	if(aux == 1){//se for pq existe

		printf("\nAlocado com sucesso");
		//organizar a pilha temporaria
		OrganizarDecrescente(temp, &pt);/*ORGANIZA PARA VOLTAR À PILHA PRINCIPAL*/

		if(!overflow(&temp)){

			cont = temp->topo;
			do{
				push(p, &temp->cli[cont]);//volta para a pilha principal
				removerEscolhido(temp, &pt, cont);//remove da temporaria
				cont--;
			}while(cont != -1);//ate que fique em -1
		}
	}
	else{
		printf("\nNao foi encontrado o mercado informado");
	}
}

void removerEscolhido(PILHA *p, PILHA *pt, int esc){/*REMOVE CASO RESOLVIDO PELO ID INFORMADO*/
	CLIENTE cl;
	while(p->topo != esc){//se o id esc, for diferente do topo, pq se for so existe 1
		cl = pop(p);//remove
		push(pt, &cl);
	}
	cl = pop(p);//recebe o valor do topo

	while(pt->topo >= 0){
		cl = pop(pt);
		push(p, &cl);
	}
}

void removerCasoResolvido(PILHA *p, int processo){/*VERIFICA O CASO RESOLVIDO E REMOVE*/
	int i, aux = 0;
	PILHA pt;
	iniciarPilha(&pt);
	for(i = p->topo; i >=0; i--)
	{
		if(p->cli[i].id == processo){// se o processo informado existir, é removido ;
			aux = 1;//se existe este processo
			removerEscolhido(p, &pt, i);
		}
	}
	if(aux == 1){
		printf("\nRemovido com sucesso");

	}else{
		printf("\nNao existe este processo");
	}
}
void relatorio(PILHA *p, int op){/*FUNÇÃO PARA O RELATÓRIO*/
	int i, id, aux = 0;
	float valorTotal = 0;

	if(op == 6)//de acordo com a op vai ser um relatorio diferente
	{
		printf("\nInforme o ID para pesquisa: ");
		scanf("%d",&id);

	}


	for(i = p->topo; i >=0; i--)
	{
		if(op == 1)
		{
			printf("\n[%d]",p->cli[i].id);
		}
		else if( op == 2){

			printf("\n%s",p->cli[i].nome);
		}
		else if( op == 3){

			printf("\n%.2f",p->cli[i].valor);
		}

		valorTotal += p->cli[i].valor;
		if(op == 6){
			if(p->cli[i].id == id){
				imprimirPilhaEscolhido(p, i);
				aux = 1;
			}
		}

	}
	if(op == 3)
	{
		printf("\nValor total dos cheques: %.2f", valorTotal);

	}
	if(op == 4)
	{
		printf("\nIdentificador do processo: [%d]",p->cli[p->topo].id);
        printf("\nNome cliente: %s",p->cli[p->topo].nome);
        printf("\nValor do cheque: %.2f",p->cli[p->topo].valor);
	}
	if(op == 6)
	{
		if(aux == 0)
		{
			printf("\nNao existe esse id");
		}

	}
	if(op == 7){
		imprimirPilhaEscolhido(p, p->topo);
	}
	if(op == 8){
		imprimirPilhaEscolhido(p,0);
	}

}
void imprimirPilhaEscolhido(PILHA *p, int id){/*IMPRIME POR ID, TOPO E BASE*/
     int aux;



         printf("\nElemento[%d]",id+1);
         printf("\nProcesso:[%d]",p->cli[id].id);
         printf("\nNome do cliente: %s",p->cli[id].nome);
         printf("\nNome do supermercado: %s",p->cli[id].nomeMercado);
         printf("\nEndereco do cliente: %s",p->cli[id].endereco);
         printf("\nIdentidade do cliente: %d",p->cli[id].identidade);
         printf("\nTelefone do cliente: %d",p->cli[id].telefoneCliente);
         printf("\nData do cheque: %s",p->cli[id].dataCheque);
         printf("\nValor do cheque: %.2f",p->cli[id].valor);
         printf("\n\n");


}

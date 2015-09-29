/*Escalonador de Processos(Lista de Prioridades)******
**INF1019 2015.2 - PUC-RIO****************************
**Professor: Luiz Fernando Seibel*********************
**Nome: Fernando Homem da Costa - 1211971*************
**      Mateus Ribeiro de Castro - 1213068************
**
******************************************************/


#include<stdio.h>
#include<stdlib.h>

/*Estrutura de Processos*/

struct processo{
	int id; //identificador do processo
	int prio; //nivel de prioridade do processo
	struct processo *prox; // ponteiro para uma pr�xima estrutura de processo
};
typedef struct processo Processo;
typedef struct processo *Pprocesso;

/*Declara��es de Prot�tipos de Fun��o*/
/*************************************/

/*Interpretador de Comandos*/
void interpretador(char nome[], int prio){

	/*int i = 4;
	char mensagem[100];
	scanf("%[^\n]", mensagem);

	while (mensagem[i] != ' ') {
		nome[i - 4] = mensagem[i];
		i++;
	}

	while (mensagem[i] != '\n') {
		i++;
	}

	prio = mensagem[i - 1] - 49;


	return 0;*/
}


/*Inicializa��o de Lista de Processos*/
Pprocesso inicializaProcesso(int identificador, int prioridade){
	Pprocesso proc;
	proc = (Pprocesso)malloc(sizeof(Processo));

	if(proc == NULL) {
		printf("Erro ao alocar mem�ria\n");
		exit(1);
	}

	proc->id = identificador; 
	proc->prio = prioridade;
	proc->prox = NULL;

	return proc;
}

/*Adiciona Processo na Lista de Processos*/
void adicionaProcesso(Pprocesso *ListaProc, Pprocesso proc){
	int i = 0;
	
	if (ListaProc[0] == NULL){// Se o primeiro elemento da Lista de Processo for nulo, ou seja, sem processos.

		ListaProc[0] = proc;// Adiciona o primeiro processo a lista de processos.
	}

	else{// Caso j� tenha elementos inseridos na lista de Processos.
		while (ListaProc[i]->prox != NULL){//Vai at� o final da lista.
			i++;
		}
		ListaProc[i]->prox = proc;//Muda para quem o ultimo elemento da lista ir� apontar.
	}

	OrdenaProcessos(ListaProc, proc); //Ordena depois de ter ordenado.
}

/*Retira Processo da Lista de Processos*/
/*-----------> D�vida!
void retiraProcesso(Pprocesso *ListaProc, Pprocesso proc){

}*/

/*Fun��o de listagem dos processos*/
void listaProcessos(Pprocesso *ListaProc){//Printa na tela todos os procesos presente na Lista de Procesos
	int i = 0;
	printf("Lista de Processos: /n/n");

	while (ListaProc[i] != NULL) {
		printf("Processo: %d\tPrioridade: %d\n", ListaProc[i]->id, ListaProc[i]->prio);
		i++;
	}
	printf("\n");
}

/*Fun��o de Compara��o da Qsort*/
int ComparaQsort(const void *x, const void *y){
	const struct processo *comp1 = x;
	const struct processo *comp2 = y;

	if (comp1->prio > comp2->prio){
		return -1;
	}

	else if (comp1->prio < comp2->prio){
		return 1;
	}

	else{
		return 0;
	}
}

/*Fun��o para contar Elementos da Lista de Processos e Ordenh�-los*/
void OrdenaProcessos(Pprocesso *ListaProc, Pprocesso proc){/*ORDENADO ---> OBS: ORDENAR PROCESSOS!!!*/
	int i = 0;
	Pprocesso aux = proc;
	
	if (aux != NULL){
		while (aux->prox != NULL){
			i++;
		}

		qsort(ListaProc, i, sizeof(Processo), ComparaQsort);
	}
}

/*D�vidas:
interpretador:  
		Como ler do arquivo texto e armazenar?
		R:Ler do arquivo texto e armazenar num vetor de string(o nome do arquivo a ser executado) e num int(inteiro relacionado a prioridade).
		
		Como ler linha por linha?
		R: Ainda a pensar, DEVEMOS descartar "exec" e "prioridade".
		S� precisamos guardar string do nome do arquivo e o int.		
		
		Como retirar o processo que j� terminou da fila de execu��o?
		R: Utilizar kill, ou seja, matar o processo. Tamb�m podemos usar o PID do processo.

		Como saber que um processo j� terminou de executar?
		R:Todos os processos ser�o de loop.

		Como tirar um processo de execu��o para executar outro?
		R:SIGSTOP e SIGCONTINUE.

		OBS: Para cada processo criado dever� ter um fork, ou seja, cada processo novo ser� um filho novo. Para exec lido dever� executar um processo novo.
Com o PID do processo, conseguiremos para, continuar ou matar o processo.	
		
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TrabED.h"
//#include <conio.h>
int Time;
int ID;


Portos* CriaPortos(){
	/*REALIZA TODOS OS MALLOCS*/
	Portos* P = (Portos*)malloc(sizeof(struct portos));
	P->A1 = (Atracamento*)malloc(sizeof(struct atracamento));
	P->A2 = (Atracamento*)malloc(sizeof(struct atracamento));
	P->A3 = (Atracamento*)malloc(sizeof(struct atracamento));
	P->A4 = (Atracamento*)malloc(sizeof(struct atracamento));

	P->A1->P1 = (HeadP*)malloc(sizeof(struct headP));
	P->A1->P2 = (HeadP*)malloc(sizeof(struct headP));
	P->A1->P3 = (HeadP*)malloc(sizeof(struct headP));
	P->A1->P4 = (HeadP*)malloc(sizeof(struct headP));
	P->A1->P5 = (HeadP*)malloc(sizeof(struct headP));
	P->A1->P1->tam = 0;
	P->A1->P1->topo = NULL;
	P->A1->P2->tam = 0;
	P->A1->P2->topo = NULL;
	P->A1->P3->tam = 0;
	P->A1->P3->topo = NULL;
	P->A1->P4->tam = 0;
	P->A1->P4->topo = NULL;
	P->A1->P5->tam = 0;
	P->A1->P5->topo = NULL;

	P->A2->P1 = (HeadP*)malloc(sizeof(struct headP));
	P->A2->P2 = (HeadP*)malloc(sizeof(struct headP));
	P->A2->P3 = (HeadP*)malloc(sizeof(struct headP));
	P->A2->P4 = (HeadP*)malloc(sizeof(struct headP));
	P->A2->P5 = (HeadP*)malloc(sizeof(struct headP));
	P->A2->P1->tam = 0;
	P->A2->P1->topo = NULL;
	P->A2->P2->tam = 0;
	P->A2->P2->topo = NULL;
	P->A2->P3->tam = 0;
	P->A2->P3->topo = NULL;
	P->A2->P4->tam = 0;
	P->A2->P4->topo = NULL;
	P->A2->P5->tam = 0;
	P->A2->P5->topo = NULL;

	P->A3->P1 = (HeadP*)malloc(sizeof(struct headP));
	P->A3->P2 = (HeadP*)malloc(sizeof(struct headP));
	P->A3->P3 = (HeadP*)malloc(sizeof(struct headP));
	P->A3->P4 = (HeadP*)malloc(sizeof(struct headP));
	P->A3->P5 = (HeadP*)malloc(sizeof(struct headP));
	P->A3->P1->tam = 0;
	P->A3->P1->topo = NULL;
	P->A3->P2->tam = 0;
	P->A3->P2->topo = NULL;
	P->A3->P3->tam = 0;
	P->A3->P3->topo = NULL;
	P->A3->P4->tam = 0;
	P->A3->P4->topo = NULL;
	P->A3->P5->tam = 0;
	P->A3->P5->topo = NULL;

	P->A4->P1 = (HeadP*)malloc(sizeof(struct headP));
	P->A4->P2 = (HeadP*)malloc(sizeof(struct headP));
	P->A4->P3 = (HeadP*)malloc(sizeof(struct headP));
	P->A4->P4 = (HeadP*)malloc(sizeof(struct headP));
	P->A4->P5 = (HeadP*)malloc(sizeof(struct headP));
	P->A4->P1->tam = 0;
	P->A4->P1->topo = NULL;
	P->A4->P2->tam = 0;
	P->A4->P2->topo = NULL;
	P->A4->P3->tam = 0;
	P->A4->P3->topo = NULL;
	P->A4->P4->tam = 0;
	P->A4->P4->topo = NULL;

	P->A1->FNavios = (HeadF*)malloc(sizeof(struct head));
	P->A1->FNavios->tam = 0;
	P->A1->FNavios->inicio = NULL;
	P->A1->FNavios->fim = NULL;

	P->A2->FNavios = (HeadF*)malloc(sizeof(struct head));
	P->A2->FNavios->tam = 0;
	P->A2->FNavios->inicio = NULL;
	P->A2->FNavios->fim = NULL;

	P->A3->FNavios = (HeadF*)malloc(sizeof(struct head));
	P->A3->FNavios->tam = 0;
	P->A3->FNavios->inicio = NULL;
	P->A3->FNavios->fim = NULL;

	P->A4->FNavios = (HeadF*)malloc(sizeof(struct head));
	P->A4->FNavios->tam = 0;
	P->A4->FNavios->inicio = NULL;
	P->A4->FNavios->fim = NULL;
	return P;

}

HeadP*CriaHeapHead(HeadP* P){
	/*CRIA AS CABEÇAS DA PILHA*/
	P = (HeadP*)malloc(sizeof(struct headP));
	P->tam = 0;//ADICIONA TAM 0, OU SEJA TEM 0 ELEMENTOS NESSA PILHA
	P->topo = NULL;
	return P;
}
HeadP* AdicionaPilha(HeadP* P, int valor){
	Pilha* Novo = (Pilha*)malloc(sizeof(struct pilha));
	if(P->topo == NULL){//SE A PILHA FOR VAZIA COLOCA O PRIMEIRO ELEMENTO
		Novo->prox = NULL;
		Novo->valor = valor;
		P->topo = Novo;
		P->tam++;
	}
	else{
		Novo->valor = valor;//CASO JA EXISTA ELEMENTOS NA PILHA
		Novo->prox = P->topo;
		P->topo = Novo;
		P->tam++;
	}
	return P;
}
Fila* AdicionaItemNavio(Fila* Navio){
	int i = 0;
	int valor;
	valor = (rand()%20);
	printf("SORTEIO CONTAINER: %d\n",valor );
	while(i<valor){
		if(i<4){
			/* gerando valores aleatórios entre zero e 100 */
			if(Navio->P1->tam<5){ //so adiciona na pilha 1 do navio se não tiver cheio
				Navio->P1 = AdicionaPilha(Navio->P1,(rand()%100));//essa função recebe um numero aleatorio como valor do container e em qual pilha vai ser alocado
				Navio->qtd++;
        	}
       }
       else if((i>3)&&(i<8)){//adiciona aqui se nao ultrapassar 5 elementos
       		if(Navio->P2->tam<5){
				Navio->P2 = AdicionaPilha(Navio->P2,(rand()%100));
				Navio->qtd++;
       	 	}
       }
       else if((i>7)&&(i<12)){
       		if(Navio->P3->tam<5){
				Navio->P3 = AdicionaPilha(Navio->P3,(rand()%100));
	       		Navio->qtd++;
       		}
       }
       else if((i>11)&&(i<16)){
       		if(Navio->P4->tam<5){
				Navio->P4 = AdicionaPilha(Navio->P4,(rand()%100));
				Navio->qtd++;
	       	}
       }
       else{
       		printf("Container cheio,%d desses itens não foi adicionado.\n",valor-16 );
       		Navio->qtd = 16;
       }
       i++;
	}
	return Navio;
}

HeadF *AdicionaNavio(HeadF *FNavios){
	ID++;
	Time++;//a cada novo navio na lista o time aumenta
	Fila* Novo = (Fila*)malloc(sizeof(struct fila)); 
	if((FNavios->inicio == NULL)&&(FNavios->fim==NULL)){//Se for uma lista vazia, adiciona o primeiro elemento
		Novo->prox = NULL;
		Novo->ant = NULL;
		Novo->tempo = Time;
		Novo->id = ID;
		Novo->P1 = CriaHeapHead(Novo->P1);//cria as head para manter o dado consistente e evitar segmentation fault
		Novo->P2 = CriaHeapHead(Novo->P2);
		Novo->P3 = CriaHeapHead(Novo->P3);
		Novo->P4 = CriaHeapHead(Novo->P4);//apos adicionar os campos necessarios do navio falta os containers
		Novo = AdicionaItemNavio(Novo);//Dentro do novo navio será adicionado uma quantidade X de containers
		FNavios->inicio = Novo;//apos o preenchimento completo de cada campo do navio é feito a alocação na grua
		FNavios->fim = Novo;//os ponteiros são trocados e o navio é adicionado
		FNavios->tam++;//a quantidade total de navios nessa fila é aumentado
		printf("||||Novo Navio:||||\n");
		printf("ID:%d, QTD de Conteiner:%d,Tam da Lista: %d \n",FNavios->inicio->id,FNavios->inicio->qtd,FNavios->tam);
	}
	else{
		Novo->tempo = Time;//não é uma lista vazia. Realiza os mesmos passos do preenchimento dos dados do navio
		Novo->id = ID;
		Novo->P1 = CriaHeapHead(Novo->P1);
		Novo->P2 = CriaHeapHead(Novo->P2);
		Novo->P3 = CriaHeapHead(Novo->P3);
		Novo->P4 = CriaHeapHead(Novo->P4);
		Novo = AdicionaItemNavio(Novo);
		Novo->prox = NULL;
		Novo->ant = FNavios->fim;// troca os ponteiros adicionando o novo navio em ultimo lugar da fila
		FNavios->fim->prox = Novo;
		FNavios->fim = Novo;
		FNavios->tam++;
		printf("||||Novo Navio:||||\n");
		printf("ID;%d, QTD:%d,Tam da Lista: %d \n",FNavios->fim->id,FNavios->fim->qtd,FNavios->tam);
	}
	return FNavios;
}





Portos *VerificaAtracamento(Portos *P){
	Time++;
	if((P->A1->FNavios->tam == 0)||(P->A1->FNavios->tam == P->A4->FNavios->tam)){//verrifica qual ta vazio ou menor que os demasi
		printf("######Porto A1#####\n");
		P->A1->FNavios = AdicionaNavio(P->A1->FNavios);
		printf("##################\n");
	}
	else if((P->A2->FNavios->tam == 0)||(P->A2->FNavios->tam < P->A1->FNavios->tam)){
		printf("#####Porto A2#######\n");
		P->A2->FNavios = AdicionaNavio(P->A2->FNavios);
		printf("##################\n");
	}
	else if((P->A3->FNavios->tam == 0)||(P->A3->FNavios->tam < P->A2->FNavios->tam)){
		printf("######Porto A3#####\n");
		P->A3->FNavios = AdicionaNavio(P->A3->FNavios);
		printf("##################\n");
	}
	else if((P->A4->FNavios->tam == 0)||(P->A4->FNavios->tam < P->A1->FNavios->tam)){
		printf("######Porto A4#####\n");
		P->A4->FNavios = AdicionaNavio(P->A4->FNavios);
		printf("##################\n");
	}
	return P;
}
	

HeadP *EmpilhaNavio(HeadP *P,Pilha *item){
	item->prox = P->topo;
	P->topo = item;
	P->tam++; 
	return P;
}
Pilha* DesempilhaNavio(Fila *S){
	Pilha *Valor = (Pilha*)malloc(sizeof(struct pilha));
	if(S->P1->tam!=0){
		Valor = S->P1->topo;
		S->P1->topo = S->P1->topo->prox;
		Valor->prox = NULL;
		S->P1->tam--;
	}else if(S->P2->tam!=0){
		Valor = S->P2->topo;
		S->P2->topo = S->P2->topo->prox;
		Valor->prox = NULL;
		S->P2->tam--;
	}
	else if(S->P3->tam!=0){
		Valor = S->P3->topo;
		S->P3->topo = S->P3->topo->prox;
		Valor->prox = NULL;
		S->P3->tam--;
	}else if(S->P4->tam!=0){
		Valor = S->P4->topo;
		S->P4->topo = S->P4->topo->prox;
		Valor->prox = NULL;
		S->P4->tam--;
	}
	return Valor;
}

Pilha* DesempilhaGrua(HeadP *P){
	Pilha* R = (Pilha*)malloc(sizeof(struct pilha));
	if(P->tam!=0){
		R = P->topo;
		P->topo = P->topo->prox;
		P->tam--;
	}
	return R;
} 

Atracamento* Desenfila(Atracamento *P){
	/*Parte de desenfila*/
	Fila *Retira = (Fila*)malloc(sizeof(struct fila));
	Time++;
	printf("--------------Navios sendo antendidos:--------------------------------\n");
	if(P->FNavios->inicio!=P->FNavios->fim){
		Retira = P->FNavios->inicio;
		P->FNavios->inicio = P->FNavios->inicio->prox;
		Retira->prox = NULL;
		Retira->ant = NULL;
		P->FNavios->tam--; 
		printf("Navio ID:%d Tempo Médio Espera:%d \n",Retira->id,(Time-Retira->tempo));
		printf("Tamanho,quantidade de Navios:%d\n",P->FNavios->tam);
		//Apos desenfilar o elemento retirado começa a ser esvaziado
			while(Retira->qtd!=0){//se dentro do navio ainda existir containers o while rodará
				if((P->P1->tam!=5)&&(Retira->qtd!=0)){//se a pilha 1 da grua n tiver lotado e existir container no navio atendido
					P->P1 = EmpilhaNavio(P->P1,DesempilhaNavio(Retira));
					Retira->qtd--;
				}
				else if((P->P2->tam!=5)&&(Retira->qtd!=0)){//se pilha 2 da grua disponivel 
					P->P2 = EmpilhaNavio(P->P2,DesempilhaNavio(Retira));
					Retira->qtd--;
				}else if((P->P3->tam!=5)&&(Retira->qtd!=0)){//se pilha 3 da grua dispon
					P->P3 = EmpilhaNavio(P->P3,DesempilhaNavio(Retira));
					Retira->qtd--;
				}else if((P->P4->tam!=5)&&(Retira->qtd!=0)){
					P->P4 = EmpilhaNavio(P->P4,DesempilhaNavio(Retira));
					Retira->qtd--;
				}else if((P->P5->tam!=5)&&(Retira->qtd!=0)){
					P->P5 = EmpilhaNavio(P->P5,DesempilhaNavio(Retira));
					Retira->qtd--;
				}
				else{//se todas as gruas estiverem lotadas, n cabe mais ai esvazia
					printf("####################### UMA GRUA ESTÁ LOTADA ##################################\n");
						if(P->P1->tam==5){
							printf("STATUS: Pilha 1 da Grua lotada\n");
							while(P->P1->tam>0){
								free(DesempilhaGrua(P->P1));
							}
								Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
								printf("STATUS: Pilha 1 da Grua esvaziada. Total de P1:%d\n",P->P1->tam );
						}
						if(P->P2->tam==5){
							printf("STATUS: Pilha 2 da Grua lotada\n");
							while(P->P2->tam>0){
								free(DesempilhaGrua(P->P2));
						    }
						        Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
						    	printf("STATUS: Pilha 2 da Grua esvaziada.Total de P2:%d\n",P->P2->tam );
						}
						if(P->P3->tam==5){
								printf("STATUS:Pilha 3 da Grua lotada\n");
							while(P->P3->tam>0){
								free(DesempilhaGrua(P->P3));
						    }
						    	Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
						    	printf("STATUS: Pilha 3 da Grua esvaziada.Total de P3:%d\n",P->P3->tam );
						}
								printf("Pilha 4 da Grua lotada\n");
						if(P->P4->tam==5){
							while(P->P4->tam>0){
								free(DesempilhaGrua(P->P4));
						    }
						    	Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
						    	printf("STATUS: Pilha 4 da Grua esvaziada. Total de P4:%d\n",P->P4->tam );
						}
						if(P->P5->tam==5){
							printf("STATUS:Pilha 5 da Grua lotada\n");
							while(P->P5->tam>0){
								free(DesempilhaGrua(P->P5));
						    }
						    	Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
						    	printf("STATUS: Pilha 5 da Grua esvaziada.Total de P5:%d\n",P->P5->tam );
						}
						printf("####################################################################\n");
					
				}
				printf("Quantos conteiners ainda existem no Retira:%d\n",Retira->qtd);
			}
	
		}else{
						if(P->FNavios->tam==1){
							Retira = P->FNavios->fim;
							P->FNavios->inicio = NULL;
							P->FNavios->fim = NULL;
							Retira->prox = NULL;
							Retira->ant = NULL;
							P->FNavios->tam--; 
							printf("Navio ID:%d Tempo Médio Espera:%d \n",Retira->id,(Time-Retira->tempo));
							printf("Tamanho,quantidade de Navios:%d\n",P->FNavios->tam);
							while(Retira->qtd!=0){
				if((P->P1->tam!=5)&&(Retira->qtd!=0)){
					P->P1 = EmpilhaNavio(P->P1,DesempilhaNavio(Retira));
					Retira->qtd--;
				}
				else if((P->P2->tam!=5)&&(Retira->qtd!=0)){
					P->P2 = EmpilhaNavio(P->P2,DesempilhaNavio(Retira));
					Retira->qtd--;
				}else if((P->P3->tam!=5)&&(Retira->qtd!=0)){
					P->P3 = EmpilhaNavio(P->P3,DesempilhaNavio(Retira));
					Retira->qtd--;
				}else if((P->P4->tam!=5)&&(Retira->qtd!=0)){
					P->P4 = EmpilhaNavio(P->P4,DesempilhaNavio(Retira));
					Retira->qtd--;
				}else if((P->P5->tam!=5)&&(Retira->qtd!=0)){
					P->P5 = EmpilhaNavio(P->P5,DesempilhaNavio(Retira));
					Retira->qtd--;
				}
				else{
					printf("####################### UMA GRUA ESTÁ LOTADA ##################################\n");
						if(P->P1->tam==5){
							printf("STATUS: Pilha 1 da Grua lotada\n");
							while(P->P1->tam>0){
								free(DesempilhaGrua(P->P1));
							}
								Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
								printf("STATUS: Pilha 1 da Grua esvaziada. Total de P1:%d\n",P->P1->tam );
						}
						if(P->P2->tam==5){
							printf("STATUS: Pilha 2 da Grua lotada\n");
							while(P->P2->tam>0){
								free(DesempilhaGrua(P->P2));
						    }
						        Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
						    	printf("STATUS: Pilha 2 da Grua esvaziada.Total de P2:%d\n",P->P2->tam );
						}
						if(P->P3->tam==5){
								printf("STATUS:Pilha 3 da Grua lotada\n");
							while(P->P3->tam>0){
								free(DesempilhaGrua(P->P3));
						    }
						    	Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
						    	printf("STATUS: Pilha 3 da Grua esvaziada.Total de P3:%d\n",P->P3->tam );
						}
								printf("Pilha 4 da Grua lotada\n");
						if(P->P4->tam==5){
							while(P->P4->tam>0){
								free(DesempilhaGrua(P->P4));
						    }
						    	Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
						    	printf("STATUS: Pilha 4 da Grua esvaziada. Total de P4:%d\n",P->P4->tam );
						}
						if(P->P5->tam==5){
							printf("STATUS:Pilha 5 da Grua lotada\n");
							while(P->P5->tam>0){
								free(DesempilhaGrua(P->P5));
						    }
						    	Time++;
						        Time++;
						    	printf("TIME PARA A LIBERAÇÃO:%d\n",Time);
						    	printf("STATUS: Pilha 5 da Grua esvaziada.Total de P5:%d\n",P->P5->tam );
						}
						printf("####################################################################\n");
					
				}
				printf("Quantos conteiners ainda existem no Retira:%d\n",Retira->qtd);
			}
							
						}
			}
			printf("-------------------------------------------------------------------------\n");
			printf("STATUS GRUA:\n");
			printf("Quantidade Alocado na primeira Pilha:%d\n",P->P1->tam);
			printf("Quantidade Alocado na segunda Pilha:%d\n",P->P2->tam);
			printf("Quantidade Alocado na terceira Pilha:%d\n",P->P3->tam);
			printf("Quantidade Alocado na quarta Pilha:%d\n",P->P4->tam);
			printf("Quantidade Alocado na quinta Pilha:%d\n",P->P5->tam);
	return P; 
}


Portos *AtendeNavio(Portos *P){
	Time++;
	
		if(P->A1->FNavios->tam != 0){
			//verrifica qual ta vazio
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Porto A1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			P->A1 = Desenfila(P->A1);
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		}
		if(P->A2->FNavios->tam != 0){
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Porto A2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			P->A2 = Desenfila(P->A2);
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		}
		if(P->A3->FNavios->tam != 0){
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Porto A3!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			P->A3 = Desenfila(P->A3);
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		}
		if(P->A4->FNavios->tam != 0){
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Porto A4!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			P->A4 = Desenfila(P->A4);
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		}
	return P;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Time = 0;
	Portos *P = CriaPortos();
	int valor = rand()%20;
	printf("TOTAL SORTEADO DE NAVIOS %d\n",valor );
	int i = 0;
	while(i<valor){
		P = VerificaAtracamento(P);
		i++;
	}
		
		int Total = P->A1->FNavios->tam + P->A2->FNavios->tam + P->A3->FNavios->tam + P->A4->FNavios->tam;
			i = 0;
			while(Total>0){
				P = AtendeNavio(P);
				printf("******************Navios na Grua***********************\n");
				printf("Quantidade de Navios na Grua 1::%d\n",P->A1->FNavios->tam );
				printf("TQuantidade de Navios na Grua 2:%d\n",P->A2->FNavios->tam );
				printf("Quantidade de Navios na Grua 3:%d\n",P->A3->FNavios->tam );
				printf("Quantidade de Navios na Grua 4:%d\n",P->A4->FNavios->tam );
				Total = P->A1->FNavios->tam + P->A2->FNavios->tam + P->A3->FNavios->tam + P->A4->FNavios->tam;
				printf("Total de Navios que serão atendidos:%d\n",Total);
				i++;
				printf("*******************************************************\n");
		}
		printf("Todos os navios foram atendidos\n");
			
}
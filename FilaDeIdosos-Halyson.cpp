// ConsoleApplication1.cpp : define o ponto de entrada para o aplicativo do console.
//

#include <stdio.h>
#include <stdlib.h>

int main()	{
	
	struct filas{
		int fila;
		int filaIdosos;
	};
	
	struct filas teste[5];
	int entrada=0;
	int saida=0;
	int entradaIdosos=0;
	int saidaIdosos=0;
	int x;
	int i;
	int idade;
	int verif;
	
	
	for(i=0;i<5;i++){
			teste[i].fila=NULL;
			teste[i].filaIdosos=NULL;
		}


	while (1)	{
		printf("\n\n\n1-INSERT\n2-REMOVE\n3-SAIR\n");
		scanf("%d", &x);
		system("cls");
		if(x==3){
			break;
		}
		
			if(x==1){
				printf("Digite o que deseja inserir\n");
				scanf("%d", &idade);
			} if((x==1)&&(entrada==saida)&&(teste[entrada].fila!=NULL)&&(idade<60)){
				printf("\na fila de jovens ja esta cheia!\n");
			}else if((idade<60)&&(x==1)){
				if(idade!=0){
				
					teste[entrada].fila=idade;
					entrada++;
				}else{
					printf("\nNao e possível inserir 0\n");
				}
		 	}
			
			if((idade>=60)&&(entradaIdosos==saidaIdosos)&&(teste[entradaIdosos].filaIdosos!=NULL)){
				printf("\na fila de idosos ja esta cheia\n");
			}else if((idade>=60)&&(x==1)){
				if(idade!=0){
				
					teste[entradaIdosos].filaIdosos=idade;
					entradaIdosos++;
				}else{
					printf("\nNao e possível inserir 0\n");
				}
			}
		
			if(entrada==5){
				entrada=0;
			}
			
			if(entradaIdosos==5){
				entradaIdosos=0;
			}
			
			
			
		if((x==2)&&(entrada==saida)&&(teste[entrada+1].fila==NULL)&&(entradaIdosos==saidaIdosos)&&(teste[entradaIdosos+1].filaIdosos==NULL)){
			printf("\nas duas filas ja estao vazias\n");
		}else if((x==2)&&(teste[saidaIdosos].filaIdosos!=NULL)){
			teste[saidaIdosos].filaIdosos=NULL;
			saidaIdosos++;
			if(saidaIdosos==5){
				saidaIdosos=0;
			}
			}else if((x==2)&&(teste[saida].fila!=NULL)&&(entradaIdosos==saidaIdosos)&&(teste[entradaIdosos+1].filaIdosos==NULL)){
			teste[saida].fila=NULL;
			saida++;
			if(saida==5){
				saida=0;
			}
		}
		



		if(entrada>saida){
			for(i=saida;i<5;i++){
				if(teste[i].fila!=NULL){
					printf("%d ", teste[i].fila);
				}
			}
			for(i=0;i<saida;i++){
				if(teste[i].fila!=NULL){
					printf("%d ", teste[i].fila);
				}
			}	
		}else if(saida>entrada){
			for(i=entrada;i<5;i++){
				if(teste[i].fila!=NULL){
					printf("%d ", teste[i].fila);
				}
			}
			for(i=0;i<entrada;i++){
				if(teste[i].fila!=NULL){
					printf("%d ", teste[i].fila);
				}
			}
		}else{
				for(i=saida;i<5;i++){
					if(teste[i].fila!=NULL){
						printf("%d ", teste[i].fila);
					}	
				}
				for(i=0;i<saida;i++){
					if(teste[i].fila!=NULL){
						printf("%d ", teste[i].fila);
					}
				}
		}
			
				
			
			printf("\n\n\n\n\n");

			if(entradaIdosos>saidaIdosos){
			for(i=saidaIdosos;i<5;i++){
				if(teste[i].filaIdosos!=NULL){
					printf("%d ", teste[i].filaIdosos);
				}
			}
			for(i=0;i<saidaIdosos;i++){
				if(teste[i].filaIdosos!=NULL){
					printf("%d ", teste[i].filaIdosos);
				}
			}	
		}else if(saidaIdosos>entradaIdosos){
			for(i=entradaIdosos;i<5;i++){
				if(teste[i].filaIdosos!=NULL){
					printf("%d ", teste[i].filaIdosos);
				}
			}
			for(i=0;i<entradaIdosos;i++){
				if(teste[i].filaIdosos!=NULL){
					printf("%d ", teste[i].filaIdosos);
				}
			}
		}else{
				for(i=saidaIdosos;i<5;i++){
					if(teste[i].filaIdosos!=NULL){
						printf("%d ", teste[i].filaIdosos);
					}	
				}
				for(i=0;i<saidaIdosos;i++){
					if(teste[i].filaIdosos!=NULL){
						printf("%d ", teste[i].filaIdosos);
					}
				}
			
			
			}
		}
			

	system("pause");
	return 0;
}


#include <stdlib.h>
#include <stdio.h>

struct no{
		int cor=0;
		int tamanho=0;
		int incid;
		int flag=0;
	};
	
	struct no grafo[8][8];

int qualMaior(no[8][8]) {
	int maior=0;
	int i;
	
	for(i=0;i<8;i++){
		if(((grafo[i][0].tamanho)>maior)&&(grafo[i][0].flag==0)){
			maior = i+1;
			grafo[i][0].flag = 1;
		}
	}
	return maior;
}


main(){
	

	int i;
	int j;
	int cor=0;
	int maiorGraf=0;
	int maiorCor=0;
	
	
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			system("cls");
			printf("Qual a incidencia o no %d tem no no %d? ", i+1, j+1);
			scanf(" %d", &grafo[i][j].incid);
			if(grafo[i][j].incid>0){
				grafo[i][0].tamanho++;
			}
		}
	}
	
	printf("\na matriz de incidencia do grafo e:\n");
	
	for(i=0;i<8;i++){
		printf("o no %d do grafo tem incidencias: ", i+1);
		for(j=0;j<8;j++){
			printf("%d ", grafo[i][j].incid);
		}
		printf("\n");
	}
	
	
	printf("TESTE MAIOR %d", qualMaior(grafo));
	
	
		for(i=0;i<8;i++){
			maiorGraf = qualMaior(grafo);
			for(j=0;j<8;j++){
				if((grafo[maiorGraf][0].cor==grafo[j][0].cor)&&(grafo[maiorGraf][j].incid>0)){
					cor++;
					j=0;
				}
			}
			grafo[maiorGraf][0].cor=cor;
			if(cor>maiorCor){
				maiorCor=cor;
			}
			cor=0;
		}
		
	
	
	printf("\nA quantidade necessaria de cores para pintar esse grafo de forma que duas cores identicas nao se encostem e %d", maiorCor);
	
	return 0;
}



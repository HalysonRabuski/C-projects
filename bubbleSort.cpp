#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	int vet[5];
	int flag=2;
	int aux;
	FILE *arq;
	
	for(i=0;i<5;i++){
		printf("Digite um valor para inserir no vetor: ");
		scanf("%i", &vet[i]);
	}
	
	system("cls");
	printf("vetor desordenado:");
	for(i=0;i<5;i++){
		printf(" %i", vet[i]);
	}
	
	while(flag!=0){
		flag=0;
		for(i=0;i<5;i++){
			if(vet[i]>vet[i+1]){
				aux= vet[i];
				vet[i]=vet[i+1];
				vet[i+1]=aux;
				flag=1;
			}
		}
	}
	
	arq = fopen("BubbleSort.txt","w");

	for(i=1;i<=5;i++){
		fprintf(arq, "%i ", vet[i]);
	}
	fclose(arq);
	
	return 0;
}

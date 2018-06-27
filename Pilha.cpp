// ConsoleApplication1.cpp : define o ponto de entrada para o aplicativo do console.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	

	
	int pilha[5];
	int ponto = 0;
	int x;
	int i;
	

	while (1)
	{
		printf("\n\n\n\n1-Push\n2-Pop\n3-SAIR\n");
		scanf("%d", &x);
		fflush(stdin);
		
		if (x == 3)	{
			break;
		}
		
		if ((x == 1) && (ponto<5))
		{
			printf("\nDigite o que deseja inserir na posicao %d\n", ponto + 1);
			scanf("%d", &pilha[ponto]);
			fflush(stdin);
			ponto++;
		}
		

		else if ((x == 2) && (ponto >= 1))	{
			ponto--;
		}

		system("cls");
		printf("\nA pilha esta abaixo\n");

		for (i = ponto - 1;i >= 0;i--)
		{
			printf("\n%d", pilha[i]);
		}

	


	}
	system("pause");
	return 0;
}


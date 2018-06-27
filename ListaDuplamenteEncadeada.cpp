#include <stdio.h>
#include <stdlib.h>

struct lista{
		int valor;
		lista *pa;
		lista *pp;
	};

void inicializacao (lista **l){ 
	*l = NULL;
} 


void insertNull(lista **l, int v){
	lista *n;
	n = ((lista*)malloc (sizeof(lista)));
	n->pp=n;
	n->pa=n;	
	n->valor=v;
	*l = n;
}

void insert (lista **l, int v){
	lista *n;
	n = ((lista*)malloc (sizeof(lista)));
	n->pa=*l;
	n->pp=(*l)->pp;
	n->pa->pp=n;
	n->pp->pa=n;
	n->valor=v;
	
	*l = n;
}

void del(lista **l){
	lista *t;
	
		((*l)->pp->pa)=(*l)->pa;
		((*l)->pa->pp)=(*l)->pp;	
		t=(*l)->pa;
		free(*l);
		*l=t;
}


int main(){         
	
	
	int x;
	struct lista *list;	
	
	inicializacao(&list);
		
	while(1){
		
		system("cls");
		
		if(list!=NULL){
			printf("\n%d", list->valor);	
		}
		
		printf("\n\n\nDigite a operacao desejada\n 1-PROXIMO 2-ANTERIOR 3-CRIAR 4-REMOVER 5-SAIR\n\n\n\n");
		scanf("%d", &x);
		fflush(stdin);
		if((x==1)&&(list!=NULL)){
			list=list->pp;
		}else if((x==2)&&(list!=NULL)){
			list=list->pa;
		}else if((x==3)&&(list==NULL)){
			printf("Digite o valor que deseja inserir!\n\n");
			scanf("%d", &x);
			insertNull(&list, x);
		}else if((x==3)&&(list!=NULL)){
			printf("Digite o valor que deseja inserir!\n\n");
			scanf("%d", &x);
			insert(&list,x);
		}else if((x==4)&&(list!=NULL)&&(list->pa!=list)){
			del(&list);
		}else if((x==4)&&(list!=NULL)&&(list->pa==list)){
			del(&list);
			inicializacao(&list);
		}
		else if(x==5){
			break;
		}else if((x>5)||(x<1)){
			printf("Entrada invalida\n\n");
			system("pause");
		}
		
	
	}
	system("pause");
	return 0;
	
}

#include <stdio.h>
#include <stdlib.h>

struct arvore{
	int valor;
	arvore *pmenor;
	arvore *pmaior;
	arvore *pcima;
};

void inicializacao(arvore **l){
	*l=NULL;
}

void inserirPrimeiro(arvore **l, int x){
	arvore *n;
	n = ((arvore*) malloc (sizeof(arvore)));
	n->pcima=NULL;
	n->pmaior=NULL;
	n->pmenor=NULL;
	n->valor=x;
	*l=n;
}

void inserir(arvore **l, int x){
	while(1){
		if((*l)->pcima!=NULL){
			*l=(*l)->pcima;
		}else{
			break;
		}
	}
	
	arvore *n;
	
	n = ((arvore*) malloc (sizeof(arvore)));
	
	while(1){
		if(((*l)->valor>x)&&((*l)->pmenor==NULL)){
			(*l)->pmenor=n;
			break;
		}else if(((*l)->valor<x)&&((*l)->pmaior==NULL)){
			(*l)->pmaior=n;
			break;
		}else if((*l)->valor>x){
			*l=(*l)->pmenor;
		}else if((*l)->valor<x){
			*l=(*l)->pmaior;
		}
	}
	
	n->pcima = *l;
	n->pmaior=NULL;
	n->pmenor=NULL;
	n->valor=x;
	*l=n;
}

void del(arvore **l, int x){
	arvore *n;
	int flag=0;
	
	if(((*l)->pcima==NULL)&&((*l)->pmaior==NULL)&&((*l)->pmenor==NULL)){
		free(*l);
		*l = NULL;
	}else if(((*l)->pmaior==NULL)&&((*l)->pmenor==NULL)){
		n = (*l)->pcima;
		free(*l);
		*l=n;
	}else if(((*l)->pmaior!=NULL)||((*l)->pmenor!=NULL)){
		if((*l)->pmaior!=NULL){
			n=(*l)->pmaior;
			
			while(1){
				if(n->pmenor!=NULL){
					n=n->pmenor;
					flag=1;
				}else{
					break;
				}	
			}
			(*l)->valor=n->valor;
				if(flag==1){
					n->pcima->pmenor=n->pmaior;
					if(n->pmaior!=NULL){					
						n->pmaior->pcima=n->pcima;
					}
					flag=0;			
				}else{
					(*l)->pmaior=n->pmaior;
					if(n->pmaior!=NULL){
						n->pmaior->pcima=*l;
					}
				}					
		}else{
			n=(*l)->pmenor;
			
			while(1){
				if(n->pmaior!=NULL){
					n=n->pmaior;
					flag=1;
				}else{
					break;
				}	
			}
			(*l)->valor=n->valor;
				if(flag==1){
					n->pcima->pmaior=n->pmenor;
					if(n->pmenor!=NULL){
						n->pmenor->pcima=n->pcima;
					}
					flag=0;			
				}else{
					(*l)->pmenor=n->pmenor;
					if(n->pmenor!=NULL){
						n->pmenor->pcima=*l;
					}
				}	
		}
		free(n);
	}
}

main(){
	struct arvore *tree;
	int x;
	int raiz;
	
	inicializacao(&tree);
	
	while(1){
		system("cls");
		if(tree!=NULL){
		printf("Valor atual: %d \n\n", tree->valor);
		}else{
			printf("A arvore esta vazia!\n");
		}
		printf("Escolha a opcao desejada 1-inserir 2-direita 3-esquerda 4-cima 5-deletar 6-sair\n\n");
		scanf("%d", &x);
		
		if((x==1)&&(tree==NULL)){
			printf("Digite o Valor que deseja inserir na raiz\n\n");
			scanf("%d", &x);
			raiz=x;
			inserirPrimeiro(&tree, x);
		}else if((x==1)&&(tree!=NULL)){
			printf("digite o valor que deseja inserir\n");
			scanf("%d", &x);
			inserir(&tree, x);
		}else if((x==2)&&(tree!=NULL)&&(tree->pmaior!=NULL)){
			tree=tree->pmaior;
		}else if((x==3)&&(tree!=NULL)&&(tree->pmenor!=NULL)){
			if(tree!=NULL){
				tree=tree->pmenor;
			}
		}else if((x==4)&&(tree!=NULL)&&(tree->pcima!=NULL)){
			tree=tree->pcima;
		}else if((x==5)&&(tree!=NULL)){
			del(&tree, raiz);
		}else if(x==6){
			return 0;
		}
			
	}
}


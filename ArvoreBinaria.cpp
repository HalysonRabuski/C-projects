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

void preOrdem (arvore **l){
	if (*l != NULL){
		printf("%d ", (*l)->valor);
		
		if((*l)->pmenor!=NULL){
			preOrdem(&(*l)->pmenor);
		}
		if((*l)->pmaior!=NULL){
			preOrdem(&(*l)->pmaior);
		}
	}
}

void emOrdem (arvore **l){
		
		if((*l)->pmenor!=NULL){
			emOrdem(&(*l)->pmenor);
		}
		
		if (*l != NULL){
		printf("%d ", (*l)->valor);
		
		if((*l)->pmaior!=NULL){
			emOrdem(&(*l)->pmaior);
		}
	}
}

void posOrdem (arvore **l){
		
		if((*l)->pmenor!=NULL){
			posOrdem(&(*l)->pmenor);
		}
		if((*l)->pmaior!=NULL){
			posOrdem(&(*l)->pmaior);
		}
		if (*l != NULL){
		printf("%d ", (*l)->valor);
	}
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
		if((*l)->pcima->pmaior!=NULL){
			if((*l)->pcima->pmaior->valor==(*l)->valor){
				(*l)->pcima->pmaior=NULL;
			}
		}else if((*l)->pcima->pmenor!=NULL){
			if(((*l)->pcima->pmenor->valor)==((*l)->valor)){
				(*l)->pcima->pmenor=NULL;			
			}
		}
		
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

int profun(arvore **l){

int profunEsq=0;
int profunDir=0;

	if((*l)==NULL){
		return-1;
	}else{
			if((*l)->pmenor!=NULL){
				 profunEsq = profun(&(*l)->pmenor);
			}
			if((*l)->pmaior!=NULL){
				 profunDir = profun(&(*l)->pmaior);
			}
			
			if(profunEsq>profunDir){
				return profunEsq+1;
			}else{
				return profunDir+1;
			}
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
		printf("Escolha a opcao desejada \n1-Inserir \n2-Direita \n3-Esquerda \n4-Cima \n5-Deletar \n6-Pre Ordem \n7-Profundidade Maxima \n8-em ordem \n9-Pos Ordem \n10-SAIR\n\n");
		scanf("%d", &x);
		
		if((x==1)&&(tree==NULL)){
			printf("Digite o Valor que deseja inserir na raiz\n\n");
			scanf("%d", &x);
			raiz=x;
			inserirPrimeiro(&tree, x);
		}else if((x==1)&&(tree!=NULL)){
			printf("Digite o valor que deseja inserir\n");
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
		}else if((x==6)&&(tree!=NULL)){
			while(1){
				if (tree->pcima!=NULL){
					tree=tree->pcima;
				}else{
					break;
				}
			}
			system("cls");
			printf("Os valores encontrados na arvore sao: ");
			preOrdem(&tree);
			printf("\n");
			system("pause");
		}else if((x==7)&&(tree!=NULL)){
			while(1){
				if (tree->pcima!=NULL){
					tree=tree->pcima;
				}else{
					break;
				}
			}
				system("cls");				
				printf("A profundidade maxima da arvore e %d\n\n", profun(&tree)-1);
				system("pause");
		}else if((x==8)&&(tree!=NULL)){
			while(1){
				if (tree->pcima!=NULL){
					tree=tree->pcima;
				}else{
					break;
				}
			}
				system("cls");
				printf("os valores da arvore em ordem: ");
				emOrdem(&tree);
				printf("\n\n");
				system("pause");
		}else if((x==9)&&(tree!=NULL)){
			while(1){
				if (tree->pcima!=NULL){
					tree=tree->pcima;
				}else{
					break;
				}
			}
				system("cls");
				printf("os valores da arvore em pos ordem: ");
				posOrdem(&tree);
				printf("\n\n");
				system("pause");
		}else if(x==10){
			return 0;
		}
	
	}
}


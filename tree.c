#include<stdio.h>
#include<string.h>
#include"stack.h"


struct node {
	int data;
	struct node *l;
	struct node *r;
};

struct node *addnode(int data)
{

	struct node *new;
	new = malloc(sizeof(struct node));
	new->data = data;
	new->l = NULL;
	new->r = NULL;
	return new;
}

void deltree(struct node *t)
{
	struct node *temp;

	temp = t;
}


/*LRD*/
void postordertraverse(struct node *root)
{
	struct elem *stack = NULL;
	struct node *prev = NULL;

	do{

		while(root) {
			push(&root, &stack);
			root = root->l;
		}
		while (root == NULL && stack){
			root = stack->e;
			if(root->r == NULL || root->r == prev) {
				printf("%4d",root->data);
				pope(&stack);
				prev = root;
				root = NULL;
			} else {
				root = root->r;
			}
		}


	}while (stack);



}

/*LDR traversal*/
void inordertraverse(struct node *root)
{
	struct elem *stack = NULL;
	while (1) {
		while (root) {
			push(&root, &stack);
			root = root->l;
		}
		if (stack == NULL) break;
		root = pope(&stack);
		printf(" %4d \n", root->data);
		root = root->r;
	}
}
/*DLR*/
void preordtraverse(struct node *root)
{
	struct elem *stack = NULL;
	while (1) {

	while (root) {
		printf(" %4d \n", root->data);
		push(&root, &stack);
		root = root->l;
	}

	if (stack == NULL) 
		break;

	root =  (struct node*)pope(&stack);
	root = root->r;
	}


}

int main()
{
	struct node *tree;
	struct elem *stack;

	tree = addnode(1);
	tree->l = addnode(2);
	tree->r = addnode(3);
	tree->l->l = addnode(4);
	tree->l->r = addnode(5);
	tree->r->l = addnode(6);
	tree->r->r = addnode(7);

	//preordtraverse(tree);
	//inordertraverse(tree);
	postordertraverse(tree);
	//teststack();
}


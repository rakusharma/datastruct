#include<string.h>
#include<stdio.h>
#include"stack.h"

struct tnode {
	int data;
	struct tnode *l;
	struct tnode *r;
};
struct tnode *addnode(int data)
{

        struct tnode *new;
        new = malloc(sizeof(struct tnode));
        new->data = data;
        new->l = NULL;
        new->r = NULL;
        return new;
}

int nrmaxv(struct tnode *root)
{
	int max = 0;
	struct elem *stack = NULL;


	while (1) {
		while (root) {
			push(&root, &stack);
			root = root->l;
		}
		if (stack == NULL)break;
		root = pope(&stack);
		if ( root != NULL && (root->data > max)) max = root->data;
		root = root->r;

	}
	return max;
}


int maxv( struct tnode *root)
{
	int maxl = 0, maxr =0, max =0, rootv;

	if (root) {

		rootv = root->data;

		printf("root %4d\n", root->data);
		maxl = maxv(root->l);
		printf("l %4d \n", maxl);
		maxr = maxv(root->r);
		printf("r %4d \n", maxr);

		if (maxr  < maxl) 
			max = maxl;
		else  
			max = maxr;
		if(max < rootv) max = rootv;


		printf("val %4d \n", max);


	}

	return max;

}

void main()
{

	struct tnode *tree;
	int max;

        tree = addnode(1);
        tree->l = addnode(2);
        tree->r = addnode(33);
        tree->l->l = addnode(4);
        tree->l->r = addnode(5);
        tree->r->l = addnode(6);
        tree->r->r = addnode(7);
	max = nrmaxv(tree);
	printf("%4d", max);

	

}

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

	teststack();
}


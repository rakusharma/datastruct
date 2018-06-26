#include<stdio.h>
#include<string.h>
#include"stack.h"

void push(void **item, struct elem **elem)
{
        struct elem *t;
        t = (struct elem*)malloc(sizeof(struct elem));
        t->e = *item;
        t->next = *elem;
	*elem = t;
}
void *pope(struct elem **stack)
{
	void *t;
	if (*stack == NULL) return NULL;
	t = (*stack)->e;
	*stack = (*stack)->next;
	return t;
}

struct elem *pop(struct elem **stack)
{
	struct elem *t;
	if (*stack == NULL) return NULL;
	t = *stack;
	*stack = (*stack)->next;
	return t;
}

void printstack(struct elem *stack)
{

	while(stack != NULL) {
		printf("stack elem %4p\n", stack->e);
		stack = stack->next;
	}
}


int teststack()
{
	struct elem *stack = NULL, *t;
	int i = 110, j  = 10;

	push(&i, &stack);
	push(&j, &stack);

	printstack(stack);
	
	t = pop(&stack);
	printf("pop elem %4p\n", t->e);
	t = pop(&stack);
	t = pop(&stack);
	printf("pop elem %4p\n", t);

	return 1;
}

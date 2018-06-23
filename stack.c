#include<stdio.h>
#include<string.h>

/*stack*/
struct  elem {
        void *e;
        struct elem *next;
};

void push(void *item, struct elem **elem)
{
        struct elem *t;

        t = (struct elem*)malloc(sizeof(struct elem));
        t->e = item;
        t->next = *elem;

	*elem = t;
	

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
		printf("stack elem %4p %4d\n", stack->e, *(int*)(stack->e));
		stack = stack->next;
	}

}


int main()
{
	struct elem *stack = NULL, *t;
	int i = 110, j  = 10;

	push(&i, &stack);
	push(&j, &stack);

	printstack(stack);
	
	t = pop(&stack);
	printf("pop elem %4p %4d\n", t->e, *(int*)(t->e));
	t = pop(&stack);
	printf("pop elem %4p %4d\n", t->e, *(int*)(t->e));
	t = pop(&stack);
	printf("pop elem %4p\n", t);

}

#include<stdio.h>
struct node {
	void *i;
	struct node *next;	
};

struct queue {
	struct node *q;
	struct node *f;
	struct node *r;
};

void initq(struct queue **q)
{
	*q = (struct queue*)malloc(sizeof(struct queue));
	(*q)->q = NULL;
	(*q)->f = NULL;
	(*q)->r = NULL;
}

void* denq(struct queue **q)
{

	struct node *t;

	t = (*q)->f;
	(*q)->f = (*q)->f->next;
	(*q)->q = (*q)->f;
	return t;
}
void enq(struct queue **q, void **item)
{
	struct node *t;
	
	t = (struct node*)malloc(sizeof(struct node));
	t->i = *item;
	t->next = NULL;


	if((*q)->q == NULL) {
		(*q)->q = (*q)->r = (*q)->f = t;
	}else {
		(*q)->r->next = t;
		(*q)->r = t;
	}
}

void testq()
{
	struct queue *q;
	struct node *t;
	int i = 1;

	initq(&q);

	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);
	enq(&q, &i);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);
	enq(&q, &i);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);
	enq(&q, &i);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);
	enq(&q, &i);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);
	enq(&q, &i);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);

	t = q->q;
	while (t) {
		printf("%4p ", t);
		t = t->next;

	}
}

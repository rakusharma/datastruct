#include<stdio.h>
#include"queue.h"

void initq(struct queue **q)
{
	*q = (struct queue*)malloc(sizeof(struct queue));
	(*q)->q = NULL;
	(*q)->f = NULL;
	(*q)->r = NULL;
}

int emptyq(struct queue *q)
{
	if (q->q == NULL) return 1;
	return 0;
}

int *dequ(struct queue **q)
{

	struct qnode *t;

	t = (*q)->q;
	(*q)->q = (*q)->q->next;
	(*q)->f = (*q)->q;

	return t->i;
}
void enq(struct queue **q, void **item)
{
	struct qnode *t;
	
	t = (struct qnode*)malloc(sizeof(struct qnode));
	t->i = *item;
	t->next = NULL;


	if((*q)->q == NULL) {
		(*q)->q = (*q)->r = (*q)->f = t;
	}else {
		(*q)->r->next = t;
		(*q)->r = t;
	}
}

#ifdef QUEUE_TEST
struct testnode {
	int i;
	struct testnode *next;
};
void mainq()
{
	struct queue *q;
	struct qnode *t;
	void *x;
	int i = 1, *p = &i;

	struct testnode *tn, *tp;
       
	tn = malloc(sizeof(struct testnode));

	tn->i = 999;
	tn->next = NULL;

	initq(&q);

	printf("q-> %4p %4p %4p, %4p\n",q->q, q->f,  q->r, tn);
	enq(&q, &tn);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);
	enq(&q, &p);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);
	enq(&q, &p);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);
	enq(&q, &p);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);
	enq(&q, &p);++i;
	printf("q %4p %4p %4p\n",q->q, q->f,  q->r);

	t = q->q;
	while (t) {
		printf("%4p ", t);
		t = t->next;

	}

	x = dequ(&q);
	tp = x;

	printf("deq -> %4p \n", x);

}
#else

void mainq(){}

#endif

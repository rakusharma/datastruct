#include<stdio.h>
struct qnode {
        void *i;
        struct qnode *next;
};

struct queue {
        struct qnode *q;
        struct qnode *f;
        struct qnode *r;
}; 

int *dequ(struct queue **q);
void enq(struct queue **q, void **item);

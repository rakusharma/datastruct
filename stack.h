
/*stack*/
struct  elem {
        void *e;
        struct elem *next;
};

void push(void **item, struct elem **elem);

struct elem *pop(struct elem **stack);
void* pope(struct elem **stack);


int teststack();

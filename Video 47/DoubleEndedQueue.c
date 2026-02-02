#include<stdio.h>
#include<stdlib.h>

/* 
 * NOTE ON LINEAR DEQUEUE LIMITATIONS:
 * This implementation uses a linear array approach. 
 * 1. enqueueF will fail initially because f is -1.
 * 2. It only works after dequeueF has been called, which moves f forward, 
 *    creating empty slots at the beginning of the array.
 * 3. To fix this, one could:
 *    - Use Circular Array logic (modulus operator).
 *    - Initialize f and r to (size/2) to allow growth in both directions.
 */

struct DEqueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct DEqueue *q){
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct DEqueue *q){
    if(q->r == q->size -1){
        return 1;
    }
    return 0;
}

void enqueueR(struct DEqueue *q, int val){
    if(isFull(q)){
        printf("This queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

void enqueueF(struct DEqueue *q, int val){
    if(isFull(q) || q->f == -1){
        printf("This queue is full\n");
    }
    else{
        q->arr[q->f] = val;
        q->f--;
    }
}

int dequeueF(struct DEqueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This queue is Empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int dequeueR(struct DEqueue *q){
    int a = -1;
    if(isEmpty(q) || q->r == -1){
        printf("This queue is Empty\n");
    }
    else{
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}

int main()
{
    struct DEqueue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));
    
    printf("Enqueuing from Rear\n");
    enqueueR(&q, 12);
    enqueueR(&q, 15);

    printf("Dequeuing from front\n");
    printf("Dequeuing element %d\n", dequeueF(&q));
    printf("Dequeuing element %d\n", dequeueF(&q));

    printf("Enqueuing from front\n");
    enqueueF(&q, 2);
    enqueueF(&q, 7);


    printf("Dequeuing from rear\n");
    printf("Dequeuing element %d\n", dequeueR(&q));
    printf("Dequeuing element %d\n", dequeueR(&q));

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full\n");
    }
    return 0;
}
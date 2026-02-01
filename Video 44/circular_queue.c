#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q){
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){ // if circular increment of r matches q->f then queue is full
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("This queue is full(Overflow)\n");
    }
    else{
        printf("Enqueued element: %d\n", val);
        q->r = (q->r+1)%q->size; // Circular increment
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This queue is Empty(Underflow)\n");
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct circularQueue q;
    q.size = 4;
    // q.f = q.r = -1; //wrong
    q.f = q.r = 0; // f and r should intitially be 0 otherwise the queue will be never full because circular increment of r will never == f which is -1
    q.arr = (int *) malloc(q.size * sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 2);
    enqueue(&q, 1);
    // enqueue(&q, 15); Here you can enqueue upto size-1 because "f and r" has already index 0 so when enqueue -> first r incremented then puts into arr[1]

    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full\n");
    }
    return 0;
}
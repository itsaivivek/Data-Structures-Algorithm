#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL; // front pointer
struct Node *r = NULL; // rear pointer

struct Node
{
    int data;
    struct Node *next;
};

void LinkedlistTraversal()
{
    struct Node *ptr = f;
    printf("Printing the elements of this LinkedList\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    LinkedlistTraversal();

    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    return 0;
}
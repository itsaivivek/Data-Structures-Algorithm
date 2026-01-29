#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    return (top == NULL) ? 1 : 0;
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    return (p == NULL) ? 1 : 0; // if I am not able to dynamically allocate memory then it is full
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
    }
    return top;
}

int pop(struct Node **top) // pointer of pointer
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct Node *top, int position)
{
    struct Node *ptr = top;
    for (int i = 0; (i < position - 1) && (ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    return (ptr!=NULL)?ptr->data:-1;
}

int stackTop(struct Node *top){
    return top->data;
}

int stackBottom(struct Node *top){
    struct Node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);

    printf("After pushing\n");
    LinkedListTraversal(top);

    int i = 1;
    while(peek(top, i) != -1) // Looping until peek function returns -1 i.e, when stack ends
    {
        printf("Value at postion %d is: %d\n", i, peek(top, i));
        i++;
    }
    printf("\nThe value at stack Top is %d\n", stackTop(top));
    printf("The value at stack Bottom is %d\n", stackBottom(top));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Self referencing Structure
};

// This function Traverse through linkedlist and prints its data.
void LinkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}

struct Node *deleteNodeInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * deleteSpecificNode(struct Node *head, int key){
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->data != key)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linkedlist in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    LinkedlistTraversal(head);

    // printf("Deleting first Node\n");
    // head = deleteFirst(head);
    // LinkedlistTraversal(head);

    // printf("Deleting Node in Between\n");
    // head = deleteNodeInBetween(head, 2);
    // LinkedlistTraversal(head);

    // printf("Deleting the Last Node\n");
    // head = deleteLast(head);
    // LinkedlistTraversal(head);

    printf("Deleting the Node with given data\n");
    head = deleteSpecificNode(head, 41);
    LinkedlistTraversal(head);

    return 0;
}
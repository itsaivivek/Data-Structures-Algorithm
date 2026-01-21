#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Circular LinkedList Traversal
void LinkedlistTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next !=head)
    {
        p = p->next;
    }
    // At this point p points to the last node of the circular Linked List
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node*p = head;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
    
}


int main()
{
    printf("Circular Linked List\n");
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
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;

    // Link fourth and first
    fourth->data = 1;
    fourth->next = head;

    LinkedlistTraversal(head);

    // head =  insertAtFirst(head, 54);
    // printf("Inserting Node at First\n");
    // LinkedlistTraversal(head);

    head =  insertAtIndex(head, 54, 2);
    printf("Inserting Node at index\n");
    LinkedlistTraversal(head);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void LinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// void BackAndForthTraversal(struct Node *head){
//     struct Node *ptr = head;
//     do
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->next;
//     } while (ptr->next != NULL);

//     printf("Element: %d\n", ptr->data);

//     while (ptr!=NULL)
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->prev;
//     }
// }

// Alternative Method
void BackAndForthTraversal(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }

    struct Node *ptr = head;
    struct Node *tail = NULL;

    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        if(ptr->next == NULL){
            tail = ptr;
        }
        ptr = ptr->next;
    }

    // Backward traversal
    ptr = tail;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    struct Node *head;
    struct Node *N1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N4 = (struct Node *)malloc(sizeof(struct Node));

    head = N1;

    N1->prev = NULL;
    N1->data = 4;
    N1->next = N2;

    N2->prev = N1;
    N2->data = 6;
    N2->next = N3;

    N3->prev = N2;
    N3->data = 3;
    N3->next = N4;

    N4->prev = N3;
    N4->data = 11;
    N4->next = NULL;

    // LinkedListTraversal(head);
    printf("Back and forth Traversal\n");
    BackAndForthTraversal(head);

    return 0;
}
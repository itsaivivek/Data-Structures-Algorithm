#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    // sp->size = 100;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                // Clean up before returning!
                free(sp->arr);
                free(sp);
                return 0;
            }
            pop(sp);
        }
    }

    int result = isEmpty(sp);

    // 2. Clean up memory
    free(sp->arr);
    free(sp);

    return result;
}

int main()
{
    char *exp = "8*(9)";

    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching\n");
    }
    else
    {
        printf("The parenthesis is not matching\n");
    }
    return 0;
}
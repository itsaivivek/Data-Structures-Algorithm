#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

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

int isEmpty(struct stack *ptr)
{
    return (ptr->top == -1) ? 1 : 0;
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

int main()
{
    char exp[] = {'1', '-', '3', '*', '4', '(', '8', ')', '\0'};
    int size = sizeof(exp) / sizeof(exp[0]);
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    printf("Stack has been created successfully\n\n");

    for (int i = 0; i < size; i++)
    {
        if (exp[i] == '(')
        {
            prinf("Pushing ( into stack\n");
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            int response = pop(sp);
            if (response == -1)
            {
                printf("The expression is unbalanced due to stack underflow\n");
                exit(0);
            }
            else{
                printf("Popped %c from the stack\n", response);
            }
            
        }
        else
        {
            continue;
        }
    }
    
    if (isEmpty(sp))
    {
        printf("The expression is balanced\n");
    }
    else{
        printf("The expression is unbalanced because stack is not Empty\n");
    }
    

    return 0;
}
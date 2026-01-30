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

int stackTop(struct stack *ptr)
{ // Time : O(1)
    return ptr->arr[ptr->top];
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

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else
        return 0;
    
    // switch (ch)
    // {
    // case '*':
    // case '/':
    // case '%':
    //     return 3; // Multiplicative operators
    // case '+':
    // case '-':
    //     return 2; // Additive operators
    // default:
    //     // Handle unknown operators or spaces
    //     return 0;
    // }
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }
    else return 0;
}


char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    // Making the postfix array same size that of infix array
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        { // if infix[i] is not operator then put it into postfix array and update the counter
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp))) // if infix[i] precedence is greater than the operator at top of stack then push "infix[i] operator" to stack
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                // else pop out operator from stack and put into postfix array then update the counter of j
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    // After the infix expression is end check if stack is empty or not.
    while (!isEmpty(sp)) // If stack is not empty then pop out operators from stack and put into postfix[j]
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0'; // Then put \0 to end of expression and return it
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("\nInfix expression: %s\n", infix);
    printf("Infix to Postfix is: %s\n", infixToPostfix(infix));
    return 0;
}
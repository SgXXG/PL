#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define STACK_MAX_SIZE 30
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

typedef struct Stack_tag
{
    int data[STACK_MAX_SIZE];
    size_t size;
} Stack;

/* push element to the stack */
void push(Stack *stack, const int value)
{
    if (stack->size >= STACK_MAX_SIZE)
    {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = value;
    stack -> size++;
}

/* pop element from the stack */
int pop(Stack *stack)
{
    if (stack->size == 0)
    {
        exit(STACK_UNDERFLOW);
    }
    stack -> size--;
    return stack->data[stack->size];
}

/* print stack value */
void printStackValue(const int value)
{
    printf("%d", value);
}

/* print all stack */
void printStack(const Stack *stack)
{
    int i;
    int len = stack->size - 1;
    printf("stack > ");

    for (i = 0; i < len; i++)
    {
        printStackValue(stack->data[i]);
        printf(" | ");
    }
    if (stack->size != 0)
    {
        printStackValue(stack->data[i]);
    }
    printf("\n");
}

int main()
{
    Stack stack;
    stack.size = 0;

    push(&stack, 3);
    push(&stack, 5);
    push(&stack, 13);
    push(&stack, 4);
    push(&stack, 10);
    push(&stack, 121);
    push(&stack, 24);
    push(&stack, 99);

    printStack(&stack);

    printf("Result:\n");
    printf("stack > ");
    int len = stack.size - 1;
    for (int i = 0; i <= len; ++i)
    {
        if ((stack.data[i] % 2) != 0)
        {
            printStackValue(stack.data[i]);
            printf(" | ");
        }
    }
    _getch();

    return 0;
}

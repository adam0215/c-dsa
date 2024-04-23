#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Stack
{
    int top;
    unsigned int capacity;
    int *contents;

} Stack;

Stack *new_stack(unsigned int capacity)
{
    Stack *stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->contents = (int *)malloc(stack->capacity * sizeof(int));

    return stack;
}

bool stack_is_empty(Stack *stack)
{
    if (stack->top == -1)
    {
        return true;
    }

    return false;
}

bool stack_is_full(Stack *stack)
{
    if (stack->top + 1 > stack->capacity)
    {
        printf("STACK OUT OF CAPACITY");
        return true;
    }

    return false;
}

void stack_push(int value, Stack *stack)
{
    if (stack_is_full(stack))
    {
        return;
    }

    stack->contents[stack->top + 1] = value;
    stack->top++;
}

int stack_pop(Stack *stack)
{
    if (stack_is_empty(stack))
    {
        return INT_MIN;
    }

    int *popped_el = &stack->contents[stack->top];
    stack->top--;

    return *popped_el;
}

int stack_peek(Stack *stack)
{
    if (stack_is_empty(stack))
    {
        return INT_MIN;
    }

    return stack->contents[stack->top];
}

void print_stack(Stack *stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("STACK_VAL: %d\n", stack->contents[i]);
    }
}

int main(void)
{
    Stack *stack = new_stack(25);

    stack_push(1, stack);
    stack_push(2, stack);
    stack_push(3, stack);
    stack_push(4, stack);
    stack_push(5, stack);
    printf("POPPED: %d\n", stack_pop(stack));
    printf("PEEKED: %d\n", stack_peek(stack));

    print_stack(stack);
}
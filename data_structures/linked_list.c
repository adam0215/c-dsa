/*
*
*
CAUTION: Not fully implemented
*
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int number;
    struct Node *next;

} Node;

Node *ll_new_node(int number)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->number = number;
    new_node->next = NULL;

    return new_node;
}

Node *new_linked_list(int number)
{
    Node *root = ll_new_node(number);
    return root;
}

void ll_append(int number, Node **ll_head)
{
    Node *new_node = ll_new_node(number);
    Node *last_node = *ll_head;

    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    last_node->next = new_node;

    return;
}

void ll_prepend(int number, Node **ll_head)
{
    Node *new_node = ll_new_node(number);

    new_node->next = *ll_head;
    *ll_head = new_node;
}

void ll_insert_at(int number, Node **ll_head, int index)
{
    Node *new_node = ll_new_node(number);
    Node *last_node = *ll_head;

    for (int i = 0; i != index - 1; i++)
    {
        if (last_node->next)
        {
            last_node = last_node->next;
        }
        else
        {
            printf("INDEX OUT OF BOUNDS\n");
            return;
        }
    }

    new_node->next = last_node->next;
    last_node->next = new_node;
}

Node *linked_list_from_array(int *array, int array_length)
{
    Node *linked_list = new_linked_list(array[0]);

    for (int i = 1; i < array_length; i++)
    {
        ll_append(array[i], &linked_list);
    }

    return linked_list;
}

void print_linked_list(Node *linked_list)
{
    Node *curr_node = linked_list;

    while (curr_node)
    {
        printf("Node {number: %d}\n", curr_node->number);
        curr_node = curr_node->next;
    }

    return;
}

int main(void)
{
    int array[] = {1, 2, 3, 4, 5};
    int array_length = sizeof(array) / sizeof(array[0]);

    // Initialize linked list
    Node *linked_list = linked_list_from_array(array, array_length);

    ll_append(10, &linked_list);
    ll_prepend(25, &linked_list);
    ll_insert_at(15, &linked_list, 10);

    // Print values
    print_linked_list(linked_list);
}
#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - reverses a singly linked list
 * @head: double pointer to the head of the list
 * Return: pointer to the new head
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *second_half, *reversed;
    listint_t *temp1, *temp2;

    if (head == NULL || *head == NULL)
    {
        return (1);
    }

    slow = *head;
    fast = *head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    second_half = reverse_list(slow);
    reversed = second_half;

    temp1 = *head;
    temp2 = second_half;
    while (temp2 != NULL)
    {
        if (temp1->n != temp2->n)
        {
            reverse_list(reversed);
            return (0);
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    reverse_list(reversed);

    return (1);
}
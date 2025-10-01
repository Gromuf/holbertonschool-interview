## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` `and -pedantic`
- All your files should end with a new line
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `lists.h`
- Don’t forget to push your header file
- All your header files should be include guarded

## Tasks

### 10.

**Technical interview preparation**:

- You are not allowed to google anything
- Whiteboard first
- This task and all future technical interview prep tasks will include checks for the efficiency of your solution, i.e. is your solution’s runtime fast enough, does your solution require extra memory usage / mallocs, etc.

Write a function in C that checks if a singly linked list has a cycle in it.

- Prototype: `int check_cycle(listint_t *list);`
- Return: `0` if there is no cycle, `1` if there is a cycle

Requirements:

- Only these functions are allowed: `write`, `printf`, `putchar`, `puts`, `malloc`, `free`

```
carrie@ubuntu:~/$ cat lists.h
#ifndef LISTS\_H
#define LISTS\_H

#include <stdlib.h>

/\*\*
 \* struct listint\_s - singly linked list
 \* @n: integer
 \* @next: points to the next node
 \*
 \* Description: singly linked list node structure
 \* for Holberton project
 \*/
typedef struct listint\_s
{
    int n;
    struct listint\_s \*next;
} listint\_t;

size\_t print\_listint(const listint\_t \*h);
listint\_t \*add\_nodeint(listint\_t \*\*head, const int n);
void free\_listint(listint\_t \*head);
int check\_cycle(listint\_t \*list);

#endif /\* LISTS\_H \*/

carrie@ubuntu:~/$ cat 0-linked\_lists.c
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/\*\*
 \* print\_listint - prints all elements of a listint\_t list
 \* @h: pointer to head of list
 \* Return: number of nodes
 \*/
size\_t print\_listint(const listint\_t \*h)
{
    const listint\_t \*current;
    unsigned int n; /\* number of nodes \*/

    current = h;
    n = 0;
    while (current != NULL)
    {
        printf("%i\\n", current->n);
        current = current->next;
        n++;
    }

    return (n);
}

/\*\*
 \* add\_nodeint - adds a new node at the beginning of a listint\_t list
 \* @head: pointer to a pointer of the start of the list
 \* @n: integer to be included in node
 \* Return: address of the new element or NULL if it fails
 \*/
listint\_t \*add\_nodeint(listint\_t \*\*head, const int n)
{
    listint\_t \*new;

    new = malloc(sizeof(listint\_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = \*head;
    \*head = new;

    return (new);
}

/\*\*
 \* free\_listint - frees a listint\_t list
 \* @head: pointer to list to be freed
 \* Return: void
 \*/
void free\_listint(listint\_t \*head)
{
    listint\_t \*current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}

carrie@ubuntu:~/$ cat 0-main.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/\*\*
 \* main - check the code for Holberton School students.
 \*
 \* Return: Always 0.
 \*/
int main(void)
{
    listint\_t \*head;
    listint\_t \*current;
    listint\_t \*temp;
    int i;

    head = NULL;
    add\_nodeint(&head, 0);
    add\_nodeint(&head, 1);
    add\_nodeint(&head, 2);
    add\_nodeint(&head, 3);
    add\_nodeint(&head, 4);
    add\_nodeint(&head, 98);
    add\_nodeint(&head, 402);
    add\_nodeint(&head, 1024);
    print\_listint(head);

    if (check\_cycle(head) == 0)
        printf("Linked list has no cycle\\n");
    else if (check\_cycle(head) == 1)
        printf("Linked list has a cycle\\n");

    current = head;
    for (i = 0; i < 4; i++)
        current = current->next;
    temp = current->next;
    current->next = head;

    if (check\_cycle(head) == 0)
        printf("Linked list has no cycle\\n");
    else if (check\_cycle(head) == 1)
        printf("Linked list has a cycle\\n");

    current = head;
    for (i = 0; i < 4; i++)
        current = current->next;
    current->next = temp;

    free\_listint(head);

    return (0);
}

carrie@ubuntu:~/$ gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check\_cycle.c 0-linked\_lists.c -o cycle
carrie@ubuntu:~/$$ ./cycle
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
carrie@ubuntu:~/$
```

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

### 13.

**Technical interview preparation**:

- You are not allowed to google anything
- Whiteboard first

Write a function in C that checks if a singly linked list is a palindrome.

- Prototype: `int is_palindrome(listint_t **head);`
- Return: `0` if it is not a palindrome, `1` if it is a palindrome
- An empty list is considered a palindrome

```
carrie@ubuntu:0x03$ cat lists.h
#ifndef LISTS\_H
#define LISTS\_H

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
listint\_t \*add\_nodeint\_end(listint\_t \*\*head, const int n);
void free\_listint(listint\_t \*head);

int is\_palindrome(listint\_t \*\*head);

#endif /\* LISTS\_H \*/
carrie@ubuntu:0x03$

carrie@ubuntu:0x03$ cat linked\_lists.c
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
 \* add\_nodeint\_end - adds a new node at the end of a listint\_t list
 \* @head: pointer to pointer of first node of listint\_t list
 \* @n: integer to be included in new node
 \* Return: address of the new element or NULL if it fails
 \*/
listint\_t \*add\_nodeint\_end(listint\_t \*\*head, const int n)
{
    listint\_t \*new;
    listint\_t \*current;

    current = \*head;

    new = malloc(sizeof(listint\_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (\*head == NULL)
        \*head = new;
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }

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
carrie@ubuntu:0x03$

carrie@ubuntu:0x03$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/\*\*
 \* main - check the code for Holberton School students.
 \*
 \* Return: Always 0.
 \*/
int main(void)
{
    listint\_t \*head;

    head = NULL;
    add\_nodeint\_end(&head, 1);
    add\_nodeint\_end(&head, 17);
    add\_nodeint\_end(&head, 972);
    add\_nodeint\_end(&head, 50);
    add\_nodeint\_end(&head, 98);
    add\_nodeint\_end(&head, 98);
    add\_nodeint\_end(&head, 50);
    add\_nodeint\_end(&head, 972);
    add\_nodeint\_end(&head, 17);
    add\_nodeint\_end(&head, 1);
    print\_listint(head);

    if (is\_palindrome(&head) == 1)
        printf("Linked list is a palindrome\\n");
    else
        printf("Linked list is not a palindrome\\n");

    free\_listint(head);

    return (0);
}
carrie@ubuntu:0x03$

carrie@ubuntu:0x03$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked\_lists.c 0-is\_palindrome.c -o palindrome
carrie@ubuntu:0x03$ ./palindrome
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
carrie@ubuntu:0x03$
```

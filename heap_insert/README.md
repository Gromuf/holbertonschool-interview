## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the standard library
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `binary_trees.h`
- Don’t forget to push your header file
- All your header files should be include guarded

## Tasks

### 1.

Write a function that creates a binary tree node:

- Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
- `parent` is a pointer to the parent node of the node to create
- `value` is the value to put in the new node
- When created, a node does not have any children
- Your function must return a pointer to the new node, or `NULL` on failure

```
alex@/tmp/binary\_trees$ cat 0-main.c
#include <stdlib.h>
#include "binary\_trees.h"

/\*\*
 \* \_binary\_tree\_delete - Deallocate a binary tree
 \*
 \* @tree: Pointer to the root of the tree to delete
 \*/
static void \_binary\_tree\_delete(binary\_tree\_t \*tree)
{
    if (tree)
    {
        \_binary\_tree\_delete(tree->left);
        \_binary\_tree\_delete(tree->right);
        free(tree);
    }
}

/\*\*
 \* main - Entry point
 \*
 \* Return: Always 0 (Success)
 \*/
int main(void)
{
    binary\_tree\_t \*root;

    root = binary\_tree\_node(NULL, 98);

    root->left = binary\_tree\_node(root, 12);
    root->left->left = binary\_tree\_node(root->left, 6);
    root->left->right = binary\_tree\_node(root->left, 16);

    root->right = binary\_tree\_node(root, 402);
    root->right->left = binary\_tree\_node(root->right, 256);
    root->right->right = binary\_tree\_node(root->right, 512);

    binary\_tree\_print(root);
    \_binary\_tree\_delete(root);
    return (0);
}
alex@/tmp/binary\_trees$ gcc -Wall -Wextra -Werror -pedantic binary\_tree\_print.c 0-main.c 0-binary\_tree\_node.c -o 0-node
alex@/tmp/binary\_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
alex@/tmp/binary\_trees$
```

### 39.

Write a function that inserts a value into a Max Binary Heap:

- Prototype: `heap_t *heap_insert(heap_t **root, int value);`
- `root` is a double pointer to the root node of the Heap
- `value` is the value to store in the node to be inserted
- Your function must return a pointer to the inserted node, or `NULL` on failure
- If the address stored in `root` is `NULL`, the created node must become the root node.
- You have to respect a `Max Heap` ordering
- You are allowed to have up to `6` functions in your file

Your file `0-binary_tree_node.c` will be compiled during the correction

```
alex@/tmp/binary\_trees$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary\_trees.h"

/\*\*
 \* \_binary\_tree\_delete - Deallocate a binary tree
 \*
 \* @tree: Pointer to the root of the tree to delete
 \*/
static void \_binary\_tree\_delete(binary\_tree\_t \*tree)
{
    if (tree)
    {
        \_binary\_tree\_delete(tree->left);
        \_binary\_tree\_delete(tree->right);
        free(tree);
    }
}

/\*\*
 \* main - Entry point
 \*
 \* Return: 0 on success, error code on failure
 \*/
int main(void)
{
    heap\_t \*root;
    heap\_t \*node;

    root = NULL;
    node = heap\_insert(&root, 98);
    printf("Inserted: %d\\n", node->n);
    binary\_tree\_print(root);
    node = heap\_insert(&root, 402);
    printf("\\nInserted: %d\\n", node->n);
    binary\_tree\_print(root);
    node = heap\_insert(&root, 12);
    printf("\\nInserted: %d\\n", node->n);
    binary\_tree\_print(root);
    node = heap\_insert(&root, 46);
    printf("\\nInserted: %d\\n", node->n);
    binary\_tree\_print(root);
    node = heap\_insert(&root, 128);
    printf("\\nInserted: %d\\n", node->n);
    binary\_tree\_print(root);
    node = heap\_insert(&root, 256);
    printf("\\nInserted: %d\\n", node->n);
    binary\_tree\_print(root);
    node = heap\_insert(&root, 512);
    printf("\\nInserted: %d\\n", node->n);
    binary\_tree\_print(root);
    node = heap\_insert(&root, 50);
    printf("\\nInserted: %d\\n", node->n);
    binary\_tree\_print(root);
    \_binary\_tree\_delete(root);
    return (0);
}

alex@/tmp/binary\_trees$ gcc -Wall -Wextra -Werror -pedantic binary\_tree\_print.c 1-main.c 1-heap\_insert.c 0-binary\_tree\_node.c -o 1-heap\_insert
alex@/tmp/binary\_trees$ ./1-heap\_insert
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

Inserted: 46
       .--(402)--.
  .--(098)     (012)
(046)

Inserted: 128
       .-------(402)--.
  .--(128)--.       (012)
(046)     (098)

Inserted: 256
       .-------(402)-------.
  .--(128)--.         .--(256)
(046)     (098)     (012)

Inserted: 512
       .-------(512)-------.
  .--(128)--.         .--(402)--.
(046)     (098)     (012)     (256)

Inserted: 50
            .-------(512)-------.
       .--(128)--.         .--(402)--.
  .--(050)     (098)     (012)     (256)
(046)
alex@/tmp/binary\_trees$
```

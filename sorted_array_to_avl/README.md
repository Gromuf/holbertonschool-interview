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

Write a function that builds an AVL tree from an array

- Prototype: `avl_t *sorted_array_to_avl(int *array, size_t size);`
- Where `array` is a pointer to the first element of the array to be converted
- And `size` is the number of element in the array
- Your function must return a pointer to the root node of the created AVL tree, or `NULL` on failure
- You can assume there will be no duplicate value in the array
- You are not allowed to rotate
- You can only have 3 functions in your file

```
alex@~/sorted\_array\_to\_avl$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary\_trees.h"

/\*\*
 \* print\_array - Prints an array of integers
 \*
 \* @array: The array to be printed
 \* @size: Size of the array
 \*/
void print\_array(const int \*array, size\_t size)
{
    size\_t i;

    for (i = 0; i < size; ++i)
        printf("(%03d)", array\[i\]);
    printf("\\n");
}

/\*\*
 \* main - Entry point
 \*
 \* Return: 0 on success, error code on failure
 \*/
int main(void)
{
    avl\_t \*tree;
    int array\[\] = {
        1, 2, 20, 21, 22, 32, 34, 47, 62, 68,
        79, 84, 87, 91, 95, 98
    };
    size\_t n = sizeof(array) / sizeof(array\[0\]);

    tree = sorted\_array\_to\_avl(array, n);
    if (!tree)
        return (1);
    print\_array(array, n);
    binary\_tree\_print(tree);
    return (0);
}
alex@~/sorted\_array\_to\_avl$ gcc -Wall -Wextra -Werror -pedantic binary\_tree\_print.c 0-main.c 0-sorted\_array\_to\_avl.c -o 0-sorted\_array\_to\_avl
alex@~/sorted\_array\_to\_avl$ ./0-sorted\_array\_to\_avl
(001)(002)(020)(021)(022)(032)(034)(047)(062)(068)(079)(084)(087)(091)(095)(098)
                 .-----------------(047)-----------------.
       .-------(021)-------.                   .-------(084)-------.
  .--(002)--.         .--(032)--.         .--(068)--.         .--(091)--.
(001)     (020)     (022)     (034)     (062)     (079)     (087)     (095)--.
                                                                           (098)
alex@~/sorted\_array\_to\_avl$
```

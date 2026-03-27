## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl)
- You are not allowed to use global variables
- No more than 5 functions per file
- The only C standard library functions allowed are `malloc`, `free`, and `strdup`. Any use of functions like `printf`, `puts`, `calloc`, `realloc` etc… is forbidden
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don't have to push them to your repo (if you do we won't take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `list.h`
- Don't forget to push your header file
- All your header files should be include guarded

## Tasks

### 1.

"Create the source file \`0-add_node.c\` that contains the following functions:\\r\\n\\r\\n- Add a new node to \*\*the end\*\* of a double circular linked list:\\r\\n - Prototype: \`List \*add_node_end(List \*\*list, char \*str);\`\\r\\n - \`List\`: the list to modify\\r\\n\\t\\t- \`str\`: the string to copy into the new node\\r\\n\\t\\t- Returns: Address of the new node, or \`NULL\` on failure\\r\\n- Add a new node to \*\*the beginning\*\* of a double circular linked list:\\r\\n - Prototype: \`List \*add_node_begin(List \*\*list, char \*str);\`\\r\\n - \`List\`: the list to modify\\r\\n\\t\\t- \`str\`: the string to copy into the new node\\r\\n\\t\\t- Returns: Address of the new node, or \`NULL\` on failure\\r\\n\\r\\n\`\`\`\\r\\nalexa@ubuntu:double_circular_linked_list$ cat 0-main.c \\r\\n#include \\u003cstdio.h\\u003e\\r\\n#include \\u003cstdlib.h\\u003e\\r\\n#include \\"list.h\\"\\r\\n\\r\\n/\*\*\\r\\n \* print_list - Print informations about each element of a list\\r\\n \*\\r\\n \* @list: A pointer to the head of the linkd list\\r\\n \*\\r\\n \* Return: void\\r\\n \*/\\r\\nvoid print_list(List \*list)\\r\\n{\\r\\n\\tList \*tmp;\\r\\n\\r\\n\\ttmp = list;\\r\\n\\twhile (tmp)\\r\\n\\t{\\r\\n\\t\\tprintf(\\"%s\\\\n\\", tmp-\\u003estr);\\r\\n\\t\\tprintf(\\"\\\\t-\\u003eprev: %s\\\\n\\", tmp-\\u003eprev ? tmp-\\u003eprev-\\u003estr : \\"NULL\\");\\r\\n\\t\\tprintf(\\"\\\\t-\\u003enext: %s\\\\n\\", tmp-\\u003enext ? tmp-\\u003enext-\\u003estr : \\"NULL\\");\\r\\n\\t\\ttmp = tmp-\\u003enext;\\r\\n\\t\\tif (tmp == list)\\r\\n\\t\\t\\tbreak;\\r\\n\\t}\\r\\n}\\r\\n\\r\\n/\*\*\\r\\n \* main - check the code for Holberton School students.\\r\\n \*\\r\\n \* Return: Always 0.\\r\\n \*/\\r\\nint main(void)\\r\\n{\\r\\n\\tList \*list;\\r\\n\\r\\n\\tlist = NULL;\\r\\n\\tadd_node_end(\\u0026list, \\"Holberton\\");\\r\\n\\tadd_node_end(\\u0026list, \\"School\\");\\r\\n\\tadd_node_end(\\u0026list, \\"Full\\");\\r\\n\\tadd_node_end(\\u0026list, \\"Stack\\");\\r\\n\\tadd_node_end(\\u0026list, \\"Engineer\\");\\r\\n\\r\\n\\tprintf(\\"Added to the end:\\\\n\\");\\r\\n\\tprint_list(list);\\r\\n\\tlist = NULL;\\r\\n\\tadd_node_begin(\\u0026list, \\"Holberton\\");\\r\\n\\tadd_node_begin(\\u0026list, \\"School\\");\\r\\n\\tadd_node_begin(\\u0026list, \\"Full\\");\\r\\n\\tadd_node_begin(\\u0026list, \\"Stack\\");\\r\\n\\tadd_node_begin(\\u0026list, \\"Engineer\\");\\r\\n\\r\\n\\tprintf(\\"Added to the beginning:\\\\n\\");\\r\\n\\tprint_list(list);\\r\\n\\treturn (0);\\r\\n}\\r\\nalexa@ubuntu:double_circular_linked_list$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c\\r\\nalexa@ubuntu:double_circular_linked_list$ ./a.out \\r\\nHolberton\\r\\n -\\u003eprev: Engineer\\r\\n -\\u003enext: School\\r\\nSchool\\r\\n -\\u003eprev: Holberton\\r\\n -\\u003enext: Full\\r\\nFull\\r\\n -\\u003eprev: School\\r\\n -\\u003enext: Stack\\r\\nStack\\r\\n -\\u003eprev: Full\\r\\n -\\u003enext: Engineer\\r\\nEngineer\\r\\n -\\u003eprev: Stack\\r\\n -\\u003enext: Holberton\\r\\nAdded to the beginning:\\r\\nEngineer\\r\\n -\\u003eprev: Holberton\\r\\n -\\u003enext: Stack\\r\\nStack\\r\\n -\\u003eprev: Engineer\\r\\n -\\u003enext: Full\\r\\nFull\\r\\n -\\u003eprev: Stack\\r\\n -\\u003enext: School\\r\\nSchool\\r\\n -\\u003eprev: Full\\r\\n -\\u003enext: Holberton\\r\\nHolberton\\r\\n -\\u003eprev: School\\r\\n -\\u003enext: Engineer\\r\\nalexa@ubuntu:double_circular_linked_list$ \\r\\n\`\`\`"

Create the source file `0-add_node.c` that contains the following functions:

- Add a new node to **the end** of a double circular linked list:
  - Prototype: `List *add_node_end(List **list, char *str);`
  - `List`: the list to modify
    - `str`: the string to copy into the new node
    - Returns: Address of the new node, or `NULL` on failure
- Add a new node to **the beginning** of a double circular linked list:
  - Prototype: `List *add_node_begin(List **list, char *str);`
  - `List`: the list to modify
    - `str`: the string to copy into the new node
    - Returns: Address of the new node, or `NULL` on failure

alexa@ubuntu:double_circular_linked_list$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/\*\*

- print_list - Print informations about each element of a list
-
- @list: A pointer to the head of the linkd list
-
- Return: void
  */
  void print_list(List *list)
  {
  List \*tmp;

      tmp = list;
      while (tmp)
      {
          printf("%s\n", tmp->str);
          printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
          printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
          tmp = tmp->next;
          if (tmp == list)
              break;
      }

  }

/\*\*

- main - check the code for Holberton School students.
-
- Return: Always 0.
  */
  int main(void)
  {
  List *list;

      list = NULL;
      add_node_end(&list, "Holberton");
      add_node_end(&list, "School");
      add_node_end(&list, "Full");
      add_node_end(&list, "Stack");
      add_node_end(&list, "Engineer");

      printf("Added to the end:\n");
      print_list(list);
      list = NULL;
      add_node_begin(&list, "Holberton");
      add_node_begin(&list, "School");
      add_node_begin(&list, "Full");
      add_node_begin(&list, "Stack");
      add_node_begin(&list, "Engineer");

      printf("Added to the beginning:\n");
      print_list(list);
      return (0);

  }
  alexa@ubuntu:double_circular_linked_list$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c
  alexa@ubuntu:double_circular_linked_list$ ./a.out
  Holberton
  ->prev: Engineer
  ->next: School
  School
  ->prev: Holberton
  ->next: Full
  Full
  ->prev: School
  ->next: Stack
  Stack
  ->prev: Full
  ->next: Engineer
  Engineer
  ->prev: Stack
  ->next: Holberton
  Added to the beginning:
  Engineer
  ->prev: Holberton
  ->next: Stack
  Stack
  ->prev: Engineer
  ->next: Full
  Full
  ->prev: Stack
  ->next: School
  School
  ->prev: Full
  ->next: Holberton
  Holberton
  ->prev: School
  ->next: Engineer
  alexa@ubuntu:double_circular_linked_list$

**Repo:**

- GitHub repository: `holbertonschool-interview`
- **Directory:** `double_circular_linked_list`
- **File:** `0-add_node.c`

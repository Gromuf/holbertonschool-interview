## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl)
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the standard library
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don't have to push them to your repo (if you do we won't take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `binary_trees.h`
- Don't forget to push your header file
- All your header files should be include guarded

## Tasks

### 1.

"Write a function that checks if a binary tree is a valid \[AVL Tree\](/rltoken/702dClPKf4JcLP0unKbwgw)\\r\\n\\r\\n- Prototype: \`int binary_tree_is_avl(const binary_tree_t \*tree);\`\\r\\n- Where \`tree\` is a pointer to the root node of the tree to check\\r\\n- Your function must return \`1\` if \`tree\` is a valid AVL Tree, and \`0\` otherwise\\r\\n- If \`tree\` is \`NULL\`, return \`0\`\\r\\n\\r\\nProperties of an AVL Tree:\\r\\n\\r\\n- An AVL Tree is a BST\\r\\n- The difference between heights of left and right subtrees cannot be more than one\\r\\n- The left and right subtree each must also be a binary search tree\\r\\n\\r\\nNote: In order for the main file to compile, you are provided with \[this static library\](https://holbucket-prod.s3.fr-par.scw.cloud/projects/2290/libavl.a). This library won’t be used during correction, its only purpose is for testing.\\r\\n\\r\\n\`\`\`\\r\\nalex@/tmp/binary_trees$ cat 0-main.c\\r\\n#include \\u003cstdlib.h\\u003e\\r\\n#include \\u003cstdio.h\\u003e\\r\\n#include \\"binary_trees.h\\"\\r\\n\\r\\n/\*\*\\r\\n \* basic_tree - Build a basic binary tree\\r\\n \*\\r\\n \* Return: A pointer to the created tree\\r\\n \*/\\r\\nbinary_tree_t \*basic_tree(void)\\r\\n{\\r\\n\\tbinary_tree_t \*root;\\r\\n\\r\\n\\troot = binary_tree_node(NULL, 98);\\r\\n\\troot-\\u003eleft = binary_tree_node(root, 12);\\r\\n\\troot-\\u003eright = binary_tree_node(root, 128);\\r\\n\\troot-\\u003eleft-\\u003eright = binary_tree_node(root-\\u003eleft, 54);\\r\\n\\troot-\\u003eright-\\u003eright = binary_tree_node(root, 402);\\r\\n\\troot-\\u003eleft-\\u003eleft = binary_tree_node(root-\\u003eleft, 10);\\r\\n\\treturn (root);\\r\\n}\\r\\n\\r\\n/\*\*\\r\\n \* main - Entry point\\r\\n \*\\r\\n \* Return: Always 0 (Success)\\r\\n \*/\\r\\nint main(void)\\r\\n{\\r\\n\\tbinary_tree_t \*root;\\r\\n\\tint avl;\\r\\n\\r\\n\\troot = basic_tree();\\r\\n\\r\\n\\tbinary_tree_print(root);\\r\\n\\tavl = binary_tree_is_avl(root);\\r\\n\\tprintf(\\"Is %d avl: %d\\\\n\\", root-\\u003en, avl);\\r\\n\\tavl = binary_tree_is_avl(root-\\u003eleft);\\r\\n\\tprintf(\\"Is %d avl: %d\\\\n\\", root-\\u003eleft-\\u003en, avl);\\r\\n\\r\\n\\troot-\\u003eright-\\u003eleft = binary_tree_node(root-\\u003eright, 97);\\r\\n\\tbinary_tree_print(root);\\r\\n\\tavl = binary_tree_is_avl(root);\\r\\n\\tprintf(\\"Is %d avl: %d\\\\n\\", root-\\u003en, avl);\\r\\n\\r\\n\\troot = basic_tree();\\r\\n\\troot-\\u003eright-\\u003eright-\\u003eright = binary_tree_node(root-\\u003eright-\\u003eright, 430);\\r\\n\\tbinary_tree_print(root);\\r\\n\\tavl = binary_tree_is_avl(root);\\r\\n\\tprintf(\\"Is %d avl: %d\\\\n\\", root-\\u003en, avl);\\r\\n\\r\\n\\troot-\\u003eright-\\u003eright-\\u003eright-\\u003eleft = binary_tree_node(root-\\u003eright-\\u003eright-\\u003eright, 420);\\r\\n\\tbinary_tree_print(root);\\r\\n\\tavl = binary_tree_is_avl(root);\\r\\n\\tprintf(\\"Is %d avl: %d\\\\n\\", root-\\u003en, avl);\\r\\n\\treturn (0);\\r\\n}\\r\\nalex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c -L. -lavl -o 0-is_avl\\r\\nalex@/tmp/binary_trees$ ./0-is_avl\\r\\n .-------(098)--.\\r\\n .--(012)--. (128)--.\\r\\n(010) (054) (402)\\r\\nIs 98 avl: 1\\r\\nIs 12 avl: 1\\r\\n .-------(098)-------.\\r\\n .--(012)--. .--(128)--.\\r\\n(010) (054) (097) (402)\\r\\nIs 98 avl: 0\\r\\n .-------(098)--.\\r\\n .--(012)--. (128)--.\\r\\n(010) (054) (402)--.\\r\\n (430)\\r\\nIs 98 avl: 0\\r\\n .-------(098)--.\\r\\n .--(012)--. (128)--.\\r\\n(010) (054) (402)-------.\\r\\n .--(430)\\r\\n (420)\\r\\nIs 98 avl: 0\\r\\nalex@/tmp/binary_trees$\\r\\n\`\`\`"

Write a function that checks if a binary tree is a valid [AVL Tree](/rltoken/702dClPKf4JcLP0unKbwgw)

- Prototype: `int binary_tree_is_avl(const binary_tree_t *tree);`
- Where `tree` is a pointer to the root node of the tree to check
- Your function must return `1` if `tree` is a valid AVL Tree, and `0` otherwise
- If `tree` is `NULL`, return `0`

Properties of an AVL Tree:

- An AVL Tree is a BST
- The difference between heights of left and right subtrees cannot be more than one
- The left and right subtree each must also be a binary search tree

Note: In order for the main file to compile, you are provided with [this static library](https://holbucket-prod.s3.fr-par.scw.cloud/projects/2290/libavl.a). This library won’t be used during correction, its only purpose is for testing.

alex@/tmp/binary_trees$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/\*\*

- basic_tree - Build a basic binary tree
-
- Return: A pointer to the created tree
  */
  binary_tree_t *basic_tree(void)
  {
  binary_tree_t \*root;

      root = binary_tree_node(NULL, 98);
      root->left = binary_tree_node(root, 12);
      root->right = binary_tree_node(root, 128);
      root->left->right = binary_tree_node(root->left, 54);
      root->right->right = binary_tree_node(root, 402);
      root->left->left = binary_tree_node(root->left, 10);
      return (root);

  }

/\*\*

- main - Entry point
-
- Return: Always 0 (Success)
  */
  int main(void)
  {
  binary_tree_t *root;
  int avl;

      root = basic_tree();

      binary_tree_print(root);
      avl = binary_tree_is_avl(root);
      printf("Is %d avl: %d\n", root->n, avl);
      avl = binary_tree_is_avl(root->left);
      printf("Is %d avl: %d\n", root->left->n, avl);

      root->right->left = binary_tree_node(root->right, 97);
      binary_tree_print(root);
      avl = binary_tree_is_avl(root);
      printf("Is %d avl: %d\n", root->n, avl);

      root = basic_tree();
      root->right->right->right = binary_tree_node(root->right->right, 430);
      binary_tree_print(root);
      avl = binary_tree_is_avl(root);
      printf("Is %d avl: %d\n", root->n, avl);

      root->right->right->right->left = binary_tree_node(root->right->right->right, 420);
      binary_tree_print(root);
      avl = binary_tree_is_avl(root);
      printf("Is %d avl: %d\n", root->n, avl);
      return (0);

  }
  alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c -L. -lavl -o 0-is_avl
  alex@/tmp/binary_trees$ ./0-is_avl
  .-------(098)--.
  .--(012)--. (128)--.
  (010) (054) (402)
  Is 98 avl: 1
  Is 12 avl: 1
  .-------(098)-------.
  .--(012)--. .--(128)--.
  (010) (054) (097) (402)
  Is 98 avl: 0
  .-------(098)--.
  .--(012)--. (128)--.
  (010) (054) (402)--.
  (430)
  Is 98 avl: 0
  .-------(098)--.
  .--(012)--. (128)--.
  (010) (054) (402)-------.
  .--(430)
  (420)
  Is 98 avl: 0
  alex@/tmp/binary_trees$

**Repo:**

- GitHub repository: `holbertonschool-interview`
- **Directory:** `avl_trees`
- **File:** `0-binary_tree_is_avl.c`

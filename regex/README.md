## Requirements

### C

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl)
- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don't have to push them to your repo (if you do we won't take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `regex.h`
- Don't forget to push your header file
- All your header files should be include guarded

## Tasks

### 1.

"Write a function that checks whether a given pattern matches a given string.\\r\\n\\r\\n- Prototype: \`int regex_match(char const \*str, char const \*pattern);\`, where:\\r\\n\\t- \`str\` is the string to scan\\r\\n\\t- \`pattern\` is the regular expression\\r\\n- Your function must return \`1\` if the pattern matches the string, or \`0\` if it doesn't\\r\\n- \`str\` can be empty, and can contain any ASCII character in the exception of \`.\` and \`\*\`\\r\\n- \`pattern\` can be empty, and can contain any ASCII character, including \`.\` and \`\*\`\\r\\n- The regular expression matching must support the characters \`.\` and \`\*\`\\r\\n\\t- \`.\` matches any single character\\r\\n\\t- \`\*\` matches zero or more of the preceding character\\r\\n\\r\\n\`\`\`\\r\\nalex@~/holbertonschool-interview_prep/regex$ cat main.c\\r\\n#include \\u003cstdlib.h\\u003e\\r\\n#include \\u003cstdio.h\\u003e\\r\\n\\r\\n#include \\"regex.h\\"\\r\\n\\r\\n#define TEST_MATCH(s, p)\\tdo {\\\\\\r\\n\\t{\\\\\\r\\n\\t\\tint res = regex_match(s, p);\\\\\\r\\n\\t\\tprintf(\\"%s -\\u003e %s = %d\\\\n\\", s, p, res);\\\\\\r\\n\\t}\\\\\\r\\n} while(0)\\r\\n\\r\\n/\*\*\\r\\n \* main - Entry point\\r\\n \*\\r\\n \* Return: EXIT_SUCCESS or EXIT_FAILURE\\r\\n \*/\\r\\nint main(void)\\r\\n{\\r\\n\\tTEST_MATCH(\\"H\\", \\"H\\");\\r\\n\\tTEST_MATCH(\\"HH\\", \\"H\\");\\r\\n\\tTEST_MATCH(\\"HH\\", \\"H\*\\");\\r\\n\\tTEST_MATCH(\\"HHHHHHHHHHHHHHHHH\\", \\"H\*\\");\\r\\n\\r\\n\\tTEST_MATCH(\\"Holberton\\", \\".\*\\");\\r\\n\\tTEST_MATCH(\\"Alex\\", \\".\*\\");\\r\\n\\tTEST_MATCH(\\"Guillaume\\", \\".\*\\");\\r\\n\\tTEST_MATCH(\\"Julien\\", \\".\*\\");\\r\\n\\r\\n\\tTEST_MATCH(\\"Holberton\\", \\"Z\*H.\*\\");\\r\\n\\tTEST_MATCH(\\"Holberton\\", \\"Z\*H.\*olberton\\");\\r\\n\\tTEST_MATCH(\\"Holberton\\", \\"Z\*H.\*o.\\");\\r\\n\\tTEST_MATCH(\\"Holberton\\", \\"Z\*H.\*o\\");\\r\\n\\r\\n\\tTEST_MATCH(\\"Holberton\\", \\"holberton\\");\\r\\n\\tTEST_MATCH(\\"Holberton\\", \\".olberton\\");\\r\\n\\r\\n\\tTEST_MATCH(\\"!H@o#l$b%e^r\\u0026t(o)n\_\\", \\"!.@.#.$.%.^.\\u0026.(.).\_\\");\\r\\n\\r\\n\\treturn (EXIT_SUCCESS);\\r\\n}\\r\\nalex@~/holbertonschool-interview_prep/regex$ gcc -Wall -Wextra -Werror -pedantic main.c regex.c\\r\\nalex@~/holbertonschool-interview_prep/regex$ ./a.out\\r\\nH -\\u003e H = 1\\r\\nHH -\\u003e H = 0\\r\\nHH -\\u003e H\* = 1\\r\\nHHHHHHHHHHHHHHHHH -\\u003e H\* = 1\\r\\nHolberton -\\u003e .\* = 1\\r\\nAlex -\\u003e .\* = 1\\r\\nGuillaume -\\u003e .\* = 1\\r\\nJulien -\\u003e .\* = 1\\r\\nHolberton -\\u003e Z\*H.\* = 1\\r\\nHolberton -\\u003e Z\*H.\*olberton = 1\\r\\nHolberton -\\u003e Z\*H.\*o. = 1\\r\\nHolberton -\\u003e Z\*H.\*o = 0\\r\\nHolberton -\\u003e holberton = 0\\r\\nHolberton -\\u003e .olberton = 1\\r\\n!H@o#l$b%e^r\\u0026t(o)n\_ -\\u003e !.@.#.$.%.^.\\u0026.(.).\_ = 1\\r\\nalex@~/holbertonschool-interview_prep/regex$\\r\\n\`\`\`"

Write a function that checks whether a given pattern matches a given string.

- Prototype: `int regex_match(char const *str, char const *pattern);`, where:
  - `str` is the string to scan
  - `pattern` is the regular expression
- Your function must return `1` if the pattern matches the string, or `0` if it doesn't
- `str` can be empty, and can contain any ASCII character in the exception of `.` and `*`
- `pattern` can be empty, and can contain any ASCII character, including `.` and `*`
- The regular expression matching must support the characters `.` and `*`
  - `.` matches any single character
  - `*` matches zero or more of the preceding character

alex@~/holbertonschool-interview_prep/regex$ cat main.c
#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

#define TEST_MATCH(s, p) do {\
 {\
 int res = regex_match(s, p);\
 printf("%s -> %s = %d\n", s, p, res);\
 }\
} while(0)

/\*\*

- main - Entry point
-
- Return: EXIT_SUCCESS or EXIT_FAILURE
  _/
  int main(void)
  {
  TEST_MATCH("H", "H");
  TEST_MATCH("HH", "H");
  TEST_MATCH("HH", "H_");
  TEST_MATCH("HHHHHHHHHHHHHHHHH", "H\*");

      TEST_MATCH("Holberton", ".*");
      TEST_MATCH("Alex", ".*");
      TEST_MATCH("Guillaume", ".*");
      TEST_MATCH("Julien", ".*");

      TEST_MATCH("Holberton", "Z*H.*");
      TEST_MATCH("Holberton", "Z*H.*olberton");
      TEST_MATCH("Holberton", "Z*H.*o.");
      TEST_MATCH("Holberton", "Z*H.*o");

      TEST_MATCH("Holberton", "holberton");
      TEST_MATCH("Holberton", ".olberton");

      TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

      return (EXIT_SUCCESS);

  }
  alex@~/holbertonschool-interview*prep/regex$ gcc -Wall -Wextra -Werror -pedantic main.c regex.c
  alex@~/holbertonschool-interview_prep/regex$ ./a.out
  H -> H = 1
  HH -> H = 0
  HH -> H* = 1
  HHHHHHHHHHHHHHHHH -> H* = 1
  Holberton -> .* = 1
  Alex -> .* = 1
  Guillaume -> .* = 1
  Julien -> .* = 1
  Holberton -> Z*H.* = 1
  Holberton -> Z*H.*olberton = 1
  Holberton -> Z*H.*o. = 1
  Holberton -> Z*H.*o = 0
  Holberton -> holberton = 0
  Holberton -> .olberton = 1
  !H@o#l$b%e^r&t(o)n* -> !.@.#.$.%.^.&.(.)._ = 1
alex@~/holbertonschool-interview_prep/regex$

**Repo:**

- GitHub repository: `holbertonschool-interview`
- **Directory:** `regex`
- **File:** `regex.c, regex.h`

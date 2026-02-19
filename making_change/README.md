## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
- All your files should end with a new line
- The first line of all your files should be exactly `#!/usr/bin/python3`
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `PEP 8` style (version 1.7.x)
- All your files must be executable

## Tasks

### 1.

"Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount \`total\`.\\r\\n\\r\\n\* Prototype: \`def makeChange(coins, total)\`\\r\\n\* Return: fewest number of coins needed to meet \`total\`\\r\\n\\t\* If \`total\` is \`0\` or less, return \`0\`\\r\\n\\t\* If \`total\` cannot be met by any number of coins you have, return \`-1\`\\r\\n\* \`coins\` is a list of the values of the coins in your possession\\r\\n\* The value of a coin will always be an integer greater than \`0\`\\r\\n\* You can assume you have an infinite number of each denomination of coin in the list\\r\\n\* Your solution's runtime will be evaluated in this task\\r\\n\\r\\n\`\`\`\\r\\ncarrie@ubuntu:~/making_change$ cat 0-main.py\\r\\n#!/usr/bin/python3\\r\\n\\"\\"\\"\\r\\nMain file for testing\\r\\n\\"\\"\\"\\r\\n\\r\\nmakeChange = \_\_import\_\_('0-making_change').makeChange\\r\\n\\r\\nprint(makeChange(\[1, 2, 25\], 37))\\r\\n\\r\\nprint(makeChange(\[1256, 54, 48, 16, 102\], 1453))\\r\\n\\r\\ncarrie@ubuntu:~/making_change$\\r\\n\`\`\`\\r\\n\`\`\`\\r\\ncarrie@ubuntu:~/making\_change$ ./0-main.py\\r\\n7\\r\\n-1\\r\\ncarrie@ubuntu:~/making_change$\\r\\n\`\`\`"

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount `total`.

- Prototype: `def makeChange(coins, total)`
- Return: fewest number of coins needed to meet `total`
  - If `total` is `0` or less, return `0`
  - If `total` cannot be met by any number of coins you have, return `-1`
- `coins` is a list of the values of the coins in your possession
- The value of a coin will always be an integer greater than `0`
- You can assume you have an infinite number of each denomination of coin in the list
- Your solution's runtime will be evaluated in this task

carrie@ubuntu:~/making_change$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = **import**('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))

print(makeChange([1256, 54, 48, 16, 102], 1453))

carrie@ubuntu:~/making_change$
carrie@ubuntu:~/making_change$ ./0-main.py
7
-1
carrie@ubuntu:~/making_change$

**Repo:**

- GitHub repository: `holbertonschool-interview`
- **Directory:** `making_change`
- **File:** `0-making_change.py`

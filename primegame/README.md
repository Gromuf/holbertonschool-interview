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

"Maria and Ben are playing a game. Given a set of consecutive integers starting from \`1\` up to and including \`n\`, they take turns choosing a prime number from the set and removing that number and its multiples from the set. The player that cannot make a move loses the game.\\r\\n\\r\\nThey play \`x\` rounds of the game, where \`n\` may be different for each round. Assuming Maria always goes first and both players play optimally, determine who the winner of each game is.\\r\\n\\r\\n\* Prototype: \`def isWinner(x, nums)\`\\r\\n\* where \`x\` is the number of rounds and \`nums\` is an array of \`n\` \\r\\n\* Return: name of the player that won the most rounds\\r\\n\* If the winner cannot be determined, return \`None\`\\r\\n\* You can assume \`n\` and \`x\` will not be larger than 10000\\r\\n\* You cannot import any packages in this task\\r\\n\\r\\nExample:\\r\\n\\r\\n\* \`x\` = \`3\`, \`nums\` = \`\[4, 5, 1\]\`\\r\\n\\r\\nFirst round: \`4\`\\r\\n\\r\\n\* Maria picks 2 and removes 2, 4, leaving 1, 3\\r\\n\* Ben picks 3 and removes 3, leaving 1\\r\\n\* Ben wins because there are no prime numbers left for Maria to choose\\r\\n\\r\\nSecond round: \`5\`\\r\\n\\r\\n\* Maria picks 2 and removes 2, 4, leaving 1, 3, 5\\r\\n\* Ben picks 3 and removes 3, leaving 1, 5\\r\\n\* Maria picks 5 and removes 5, leaving 1\\r\\n\* Maria wins because there are no prime numbers left for Ben to choose\\r\\n\\r\\nThird round: \`1\`\\r\\n\\r\\n\* Ben wins because there are no prime numbers for Maria to choose\\r\\n\\r\\n\*\*Result: Ben has the most wins\*\*\\r\\n\\r\\n\`\`\`\\r\\ncarrie@ubuntu:~/primegame$ cat main_0.py\\r\\n#!/usr/bin/python3\\r\\n\\r\\nisWinner = \_\_import\_\_('0-prime_game').isWinner\\r\\n\\r\\n\\r\\nprint(\\"Winner: {}\\".format(isWinner(5, \[2, 5, 1, 4, 3\])))\\r\\n\\r\\ncarrie@ubuntu:~/primegame$\\r\\n\`\`\`\\r\\n\\r\\n\`\`\`\\r\\ncarrie@ubuntu:~/primegame$ ./main_0.py\\r\\nWinner: Ben\\r\\ncarrie@ubuntu:~/primegame$\\r\\n\`\`\`"

Maria and Ben are playing a game. Given a set of consecutive integers starting from `1` up to and including `n`, they take turns choosing a prime number from the set and removing that number and its multiples from the set. The player that cannot make a move loses the game.

They play `x` rounds of the game, where `n` may be different for each round. Assuming Maria always goes first and both players play optimally, determine who the winner of each game is.

- Prototype: `def isWinner(x, nums)`
- where `x` is the number of rounds and `nums` is an array of `n`
- Return: name of the player that won the most rounds
- If the winner cannot be determined, return `None`
- You can assume `n` and `x` will not be larger than 10000
- You cannot import any packages in this task

Example:

- `x` = `3`, `nums` = `[4, 5, 1]`

First round: `4`

- Maria picks 2 and removes 2, 4, leaving 1, 3
- Ben picks 3 and removes 3, leaving 1
- Ben wins because there are no prime numbers left for Maria to choose

Second round: `5`

- Maria picks 2 and removes 2, 4, leaving 1, 3, 5
- Ben picks 3 and removes 3, leaving 1, 5
- Maria picks 5 and removes 5, leaving 1
- Maria wins because there are no prime numbers left for Ben to choose

Third round: `1`

- Ben wins because there are no prime numbers for Maria to choose

**Result: Ben has the most wins**

carrie@ubuntu:~/primegame$ cat main_0.py
#!/usr/bin/python3

isWinner = **import**('0-prime_game').isWinner

print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))

carrie@ubuntu:~/primegame$
carrie@ubuntu:~/primegame$ ./main_0.py
Winner: Ben
carrie@ubuntu:~/primegame$

**Repo:**

- GitHub repository: `holbertonschool-interview`
- **Directory:** `primegame`
- **File:** `0-prime_game.py`

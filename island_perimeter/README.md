## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
- All your files should end with a new line
- The first line of all your files should be exactly `#!/usr/bin/python3`
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `PEP 8` style (version 1.7)
- You are not allowed to import any module
- All modules and functions must be documented
- All your files must be executable

## Tasks

### 1.

"Create a function \`def island_perimeter(grid):\` that returns the perimeter of the island described in \`grid\`:\\r\\n\\r\\n- \`grid\` is a list of list of integers:\\r\\n - 0 represents water\\r\\n - 1 represents land\\r\\n - Each cell is square, with a side length of 1\\r\\n - Cells are connected horizontally/vertically (not diagonally). \\r\\n - \`grid\` is rectangular, with its width and height not exceeding 100\\r\\n- The grid is completely surrounded by water\\r\\n- There is only one island (or nothing).\\r\\n- The island doesn't have \\"lakes\\" (water inside that isn't connected to the water surrounding the island).\\r\\n\\r\\n\`\`\`\\r\\nguillaume@ubuntu:~/$ cat 0-main.py\\r\\n#!/usr/bin/python3\\r\\n\\"\\"\\"\\r\\n0-main\\r\\n\\"\\"\\"\\r\\nisland_perimeter = \_\_import\_\_('0-island_perimeter').island_perimeter\\r\\n\\r\\nif \_\_name\_\_ == \\"\_\_main\_\_\\":\\r\\n grid = \[\\r\\n \[0, 0, 0, 0, 0, 0\],\\r\\n \[0, 1, 0, 0, 0, 0\],\\r\\n \[0, 1, 0, 0, 0, 0\],\\r\\n \[0, 1, 1, 1, 0, 0\],\\r\\n \[0, 0, 0, 0, 0, 0\]\\r\\n \]\\r\\n print(island_perimeter(grid))\\r\\n\\r\\nguillaume@ubuntu:~/$ \\r\\nguillaume@ubuntu:~/$ ./0-main.py\\r\\n12\\r\\nguillaume@ubuntu:~/$ \\r\\n\`\`\`\\r\\n"

Create a function `def island_perimeter(grid):` that returns the perimeter of the island described in `grid`:

- `grid` is a list of list of integers:
- 0 represents water
- 1 represents land
- Each cell is square, with a side length of 1
- Cells are connected horizontally/vertically (not diagonally).
- `grid` is rectangular, with its width and height not exceeding 100
- The grid is completely surrounded by water
- There is only one island (or nothing).
- The island doesn't have "lakes" (water inside that isn't connected to the water surrounding the island).

guillaume@ubuntu:~/$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
island_perimeter = **import**('0-island_perimeter').island_perimeter

if **name** == "**main**":
grid = [
[0, 0, 0, 0, 0, 0],
[0, 1, 0, 0, 0, 0],
[0, 1, 0, 0, 0, 0],
[0, 1, 1, 1, 0, 0],
[0, 0, 0, 0, 0, 0]
]
print(island_perimeter(grid))

guillaume@ubuntu:~/$
guillaume@ubuntu:~/$ ./0-main.py
12
guillaume@ubuntu:~/$

**Repo:**

- GitHub repository: `holbertonschool-interview`
- **Directory:** `island_perimeter`
- **File:** `0-island_perimeter.py`

## Tasks

### 1.

"Create a function \`def pascal_triangle(n):\` that returns a list of lists of integers representing the Pascal's triangle of \`n\`:\\r\\n\\r\\n- Returns an empty list if \`n \\u003c= 0\`\\r\\n- You can assume \`n\` will be always an integer\\r\\n\\r\\n\`\`\`\\r\\nguillaume@ubuntu:~/$ cat 0-main.py\\r\\n#!/usr/bin/python3\\r\\n\\"\\"\\"\\r\\n0-main\\r\\n\\"\\"\\"\\r\\npascal_triangle = \_\_import\_\_('0-pascal_triangle').pascal_triangle\\r\\n\\r\\ndef print_triangle(triangle):\\r\\n \\"\\"\\"\\r\\n Print the triangle\\r\\n \\"\\"\\"\\r\\n for row in triangle:\\r\\n print(\\"\[{}\]\\".format(\\",\\".join(\[str(x) for x in row\])))\\r\\n\\r\\n\\r\\nif \_\_name\_\_ == \\"\_\_main\_\_\\":\\r\\n print_triangle(pascal_triangle(5))\\r\\n\\r\\nguillaume@ubuntu:~/$ \\r\\nguillaume@ubuntu:~/$ ./0-main.py\\r\\n\[1\]\\r\\n\[1,1\]\\r\\n\[1,2,1\]\\r\\n\[1,3,3,1\]\\r\\n\[1,4,6,4,1\]\\r\\nguillaume@ubuntu:~/$ \\r\\n\`\`\`\\r\\n"

Create a function `def pascal_triangle(n):` that returns a list of lists of integers representing the Pascal's triangle of `n`:

- Returns an empty list if `n <= 0`
- You can assume `n` will be always an integer

guillaume@ubuntu:~/$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
pascal_triangle = **import**('0-pascal_triangle').pascal_triangle

def print_triangle(triangle):
"""
Print the triangle
"""
for row in triangle:
print("[{}]".format(",".join([str(x) for x in row])))

if **name** == "**main**":
print_triangle(pascal_triangle(5))

guillaume@ubuntu:~/$
guillaume@ubuntu:~/$ ./0-main.py
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
guillaume@ubuntu:~/$

**Repo:**

- GitHub repository: `holbertonschool-interview`
- **Directory:** `pascal_triangle`
- **File:** `0-pascal_triangle.py`

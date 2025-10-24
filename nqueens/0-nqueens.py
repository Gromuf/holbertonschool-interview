#!/usr/bin/python3
"""0-nqueens.py"""

import sys


def nqueens(n):
    """Solve the N-Queens problem and print all solutions."""
    if (not isinstance(n, int)):
        print("N must be a number")
        exit(1)
    if (n < 4):
        print("N must be at least 4")
        exit(1)
    solutions = []
    board = [-1] * n
    solve_nqueens(board, 0, n, solutions)
    for solution in solutions:
        print(solution)


def is_safe(board, row, col, n):
    """Check if it's safe to place a queen at board[col] = row."""
    for i in range(col):
        if board[i] == row or \
           board[i] - i == row - col or \
           board[i] + i == row + col:
            return False
    return True


def solve_nqueens(board, col, n, solutions):
    """Recursive utility to solve the N-Queens problem."""
    if col >= n:
        solution = []
        for i in range(n):
            solution.append([i, board[i]])
        solutions.append(solution)
        return
    for i in range(n):
        if is_safe(board, i, col, n):
            board[col] = i
            solve_nqueens(board, col + 1, n, solutions)
            board[col] = -1
    return


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)
    nqueens(n)

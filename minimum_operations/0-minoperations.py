#!/usr/bin/python3

def minOperations(n):
    """
    Calcule le nombre minimal d'opérations (Copy All, Paste)
    pour obtenir exactement n 'H' à partir d'un seul 'H'.

    Retourne 0 si n <= 1 (impossible/inutile).
    Stratégie: somme des facteurs premiers de n.
    """
    if n < 2:
        return 0

    res = 0
    x = 2

    while x * x <= n:
        while n % x == 0:
            res += x
            n //= x
        x += 1

    if n > 1:
        res += n

    return res

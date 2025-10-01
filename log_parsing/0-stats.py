#!/usr/bin/python3
"""
Log parsing script.

Ce script lit l'entrée standard ligne par ligne et calcule des statistiques :
- La taille totale des fichiers transférés (somme des <file size>).
- Le nombre d’occurrences des codes de statut HTTP.

Affichage des statistiques :
- Toutes les 10 lignes lues.
- Lors d'une interruption clavier (CTRL + C).
- À la fin de l'entrée.

Format attendu d'une ligne :
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

Toute ligne qui ne respecte pas ce format est ignorée.
"""

import sys


VALID_CODES = [200, 301, 400, 401, 403, 404, 405, 500]

total_size = 0
status_counts = {code: 0 for code in VALID_CODES}
line_count = 0


def print_stats():
    """Affiche les statistiques courantes"""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            parts = line.strip().split()
            if len(parts) < 2:
                continue
            try:
                status_code = int(parts[-2])
                file_size = int(parts[-1])
            except (ValueError, IndexError):
                continue
            total_size += file_size
            if status_code in status_counts:
                status_counts[status_code] += 1
            line_count += 1
            if line_count % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()

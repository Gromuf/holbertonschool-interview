#!/usr/bin/python3
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


try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) < 7:
            continue
        try:
            status_code = int(parts[-2])
            file_size = int(parts[-1])
        except ValueError:
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

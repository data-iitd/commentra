#!/usr/bin/env python

import sys

s = sys.stdin.readline().strip()

for r in s:
    if 'A' <= r and r <= 'Z':
        rr = r.lower()
    elif 'a' <= r and r <= 'z':
        rr = r.upper()
    print(rr, end='')
print()



#!/usr/bin/env python
# -*- coding: utf-8 -*-

# <START-OF-CODE>

import sys

def main():
    n = int(raw_input())
    a = map(int, raw_input().split())

    curr = 0
    for i in range(n):
        if a[i] == curr + 1:
            curr += 1

    if curr > 0:
        print n - curr
    else:
        print -1

if __name__ == '__main__':
    main()

# 
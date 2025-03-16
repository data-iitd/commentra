#!/usr/bin/env python

import sys

def main():
    s = sys.stdin.readline()
    s = sys.stdin.readline()
    ds = s.strip()

    dd = ds.split(" ")
    dn = []
    for d in dd:
        dn.append(int(d))

    sum = 0
    for i in range(len(dn)):
        for j in range(i+1, len(dn)):
            sum += dn[i] * dn[j]

    print(sum)

if __name__ == "__main__":
    main()


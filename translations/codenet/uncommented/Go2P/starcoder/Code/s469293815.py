# -*- coding: utf-8 -*-

# Package main provides
#
# File:  a.go
# Author: ymiyamoto
#
# Created on Sat Dec 29 04:47:30 2018
#

import sys

def main():
    A, B, C = map(int, sys.stdin.readline().split())
    if A+B >= C:
        print("Yes")
    else:
        print("No")

if __name__ == '__main__':
    main()


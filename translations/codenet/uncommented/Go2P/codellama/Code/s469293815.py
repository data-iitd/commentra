
# File:  a.py
# Author: ymiyamoto
#
# Created on Sat Dec 29 04:47:30 2018
#

import sys

A, B, C = map(int, sys.stdin.readline().split())

if A + B >= C:
    print("Yes")
else:
    print("No")


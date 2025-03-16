
import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(pandu, vundu, urdu):
    c = 0
    for i in range(1, urdu+1):
        c += i * pandu
    if c < vundu:
        print(0)
    else:
        print(c - vundu)

if __name__ == '__main__':
    pandu = int(input())

    vundu = int(input())

    urdu = int(input())

    solve(pandu, vundu, urdu)



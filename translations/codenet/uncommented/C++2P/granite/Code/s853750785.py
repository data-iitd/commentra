
# AtCoder.py

import math
import random
import re
import sys

# AtCoder.py :このファイルには'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
#

# AtCoder.py :このファイルには'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
#


def gcd(x, y):
    while y!= 0:
        (x, y) = (y, x % y)
    return x

def lcm(x, y):
    return x * y // gcd(x, y)

def read():
    return input()

def read_int():
    return int(input())

def read_ints():
    return list(map(int, input().split()))

def read_str():
    return input().strip()

def read_strs():
    return input().strip().split()

def solve():
    pass

if __name__ == '__main__':
    solve()
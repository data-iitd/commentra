
import sys
import math
import bisect
import numpy as np
from decimal import Decimal
from numba import njit, i8

mod = 10 ** 9 + 7
INF = float('inf')

def read_str():      return sys.stdin.readline().strip()
def read_int():      return int(sys.stdin.readline().strip())
def read_ints():     return map(int, sys.stdin.readline().strip().split())
def read_ints2(x):   return map(lambda num: int(num) - x, sys.stdin.readline().strip().split())
def read_str_list(): return list(sys.stdin.readline().strip().split())
def read_int_list(): return list(map(int, sys.stdin.readline().strip().split()))
def GCD(a: int, b: int) -> int: return b if a%b==0 else GCD(b, a%b)
def LCM(a: int, b: int) -> int: return (a * b) // GCD(a, b)

def Main_():
    k, a, b = read_ints()
    for i in range(a, b + 1):
        if i % k == 0:
            print("OK")
            return
    print("NG")

if __name__ == "__main__":
    Main_()


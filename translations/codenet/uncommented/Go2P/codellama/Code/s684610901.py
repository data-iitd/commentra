
import sys
import math
import string
import re

# scanner.Split(bufio.ScanWords) をコメントアウトしないと使用不可
def readLine():
    return sys.stdin.readline().rstrip()

def readInt():
    return int(sys.stdin.readline())

def readFloat():
    return float(sys.stdin.readline())

def readRunes():
    return sys.stdin.readline()

def readString():
    return sys.stdin.readline().rstrip()

def readStrings():
    return sys.stdin.readline().rstrip().split()

def s2i(s):
    return int(s)

def i2s(i):
    return str(i)

def s2f(s):
    return float(s)

def abs(i):
    return abs(i)

def max(a):
    return max(a)

def min(a):
    return min(a)

def sum(i):
    return sum(i)

def split(s):
    return s.split()

def strAry2intAry(strs):
    ret = []
    for str in strs:
        intVal = int(str)
        ret.append(intVal)
    return ret

def intAry2strAry(nums):
    ret = []
    for num in nums:
        strVal = str(num)
        ret.append(strVal)
    return ret

def ary2str(strs):
    return " ".join(strs)

def reverse(res):
    return res[::-1]

def reverseStr(res):
    return res[::-1]

def ini(res, init):
    res[0] = init
    for i in range(len(res)):
        res[i+1:] = res[:i]

#
# def regexpExample():
#     # Your code here!
#     str = "13:20"
#     r = re.compile(r"(\d+):(\d+)")
#     print(r.findall(str))
#
# class Country:
#     def __init__(self, gold, silver, blonze):
#         self.gold = gold
#         self.silver = silver
#         self.blonze = blonze
#
# # 複数ソートのサンプル
# def stableSortExample():
#     country = [
#         Country(1, 2, 3),
#         Country(1, 2, 3),
#         Country(1, 3, 2),
#         Country(1, 3, 3),
#     ]
#     country.sort(key=lambda x: x.blonze, reverse=True)
#     country.sort(key=lambda x: x.silver, reverse=True)
#     country.sort(key=lambda x: x.gold, reverse=True)
#     return country


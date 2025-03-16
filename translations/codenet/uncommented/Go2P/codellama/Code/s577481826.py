
import sys

a, b = map(int, sys.stdin.readline().split())

ret = a + b

if ret < (a - b):
    ret = a - b

if ret < (a * b):
    ret = a * b

print(ret)


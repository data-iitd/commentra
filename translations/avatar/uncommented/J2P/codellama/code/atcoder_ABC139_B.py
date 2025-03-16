
import sys

A = int(sys.stdin.readline().strip())
B = int(sys.stdin.readline().strip())

result = (B - 1) // (A - 1)
amari = (B - 1) % (A - 1)

if amari != 0:
    result += 1

print(result)


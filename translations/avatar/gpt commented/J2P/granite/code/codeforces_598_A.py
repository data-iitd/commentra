
import math

q = int(input())

while q > 0:
    n = int(input())
    x = math.floor(math.log2(n)) + 1
    s = -2**x + 2 + (n * (n + 1)) // 2 - 2**x
    print(s)
    q -= 1


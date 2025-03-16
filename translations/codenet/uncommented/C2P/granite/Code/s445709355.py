
# ABC 152-D
# 2020.1.19 bal4u

import sys

def in(): # 非負 integers の入力
    n = 0
    for c in sys.stdin.buffer.read():
        if c >= 0x30: n = 10 * n + (c & 0xf)
    return n

f1 = [0] * 100
f2 = [0] * 100

def calc(n):
    k = n % 10
    while n >= 10: n //= 10
    f1[10*k + n] += 1
    f2[n*10 + k] += 1

N = in()
while N: calc(N); N -= 1

ans = sum(f1[i] * f2[i] for i in range(100))
print(ans)

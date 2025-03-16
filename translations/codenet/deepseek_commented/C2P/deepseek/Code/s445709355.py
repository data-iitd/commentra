import sys
input = sys.stdin.read

def in():  # 非負整数の入力
    n = 0
    c = input().read1()
    while c >= '0':
        n = 10 * n + (ord(c) & 0xf)
        c = input().read1()
    return n

f1 = [0] * 100
f2 = [0] * 100

def calc(n):
    k = n % 10
    while n >= 10:
        n //= 10
    f1[10*k + n] += 1
    f2[n*10 + k] += 1

N = in()
while N:
    calc(N)
    N -= 1

ans = 0
for i in range(100):
    ans += f1[i] * f2[i]
print(ans)

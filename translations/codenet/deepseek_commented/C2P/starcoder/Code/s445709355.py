# ABC 152-D
# 2020.1.19 bal4u

def in():  # 非負整数の入力
    n = 0
    c = input()
    while c >= '0':
        n = 10 * n + ord(c) - ord('0')
        c = input()
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
    N = in()

ans = 0
for i in range(100):
    ans += f1[i] * f2[i]
print(ans)


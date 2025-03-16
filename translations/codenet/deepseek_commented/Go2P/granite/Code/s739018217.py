

n, m = map(int, input().split())
x = m*1900 + (n-m)*100
print(x * 2**m)


n = int(input())
a = list(map(int, input().split()))
print(a[-1], end='')
for i in range(1, n):
    print(" " + str(a[-i-1]), end='')
print()

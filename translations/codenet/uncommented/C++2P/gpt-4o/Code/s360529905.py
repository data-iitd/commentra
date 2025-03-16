N = int(input())
a = [int(input()) for _ in range(N)]
b = a.copy()

b.sort()
frontHalf = b[N // 2 - 1]
backHalf = b[N // 2]

for i in range(N):
    if a[i] < backHalf:
        print(backHalf)
    else:
        print(frontHalf)

# <END-OF-CODE>

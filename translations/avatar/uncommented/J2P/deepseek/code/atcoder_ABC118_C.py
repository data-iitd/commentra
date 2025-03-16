import sys

def func(A):
    a = A
    min_val = 0
    for i in range(len(a)):
        if a[i] == 0:
            a.pop(i)
            i -= 1
        else:
            if min_val != 0:
                a[i] = a[i] % min_val
                if a[i] == 1:
                    print(1)
                    sys.exit(0)
            else:
                min_val = a[i]
    a.sort()
    return a

# Read input
n = int(input().strip())
a = list(map(int, input().strip().split()))

if n == 1:
    print(a[0])
    sys.exit(0)

a.sort()

if a[-1] == 0:
    print(0)
    sys.exit(0)

ans = 0
while True:
    if len(a) == 1:
        ans = a[0]
        break
    a = func(a)

print(ans)

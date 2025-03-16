
# <START-OF-CODE>

def maxLeft(n):
    if n > 2:
        return n - 2
    else:
        return 0

t = int(input())
for i in range(t):
    n = int(input())
    print(maxLeft(n))

# 
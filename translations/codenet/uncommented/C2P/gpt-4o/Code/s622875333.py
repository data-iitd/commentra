n, r, i, j, p, c = 0, 0, 0, 0, 0, 0
a = [0] * 100
b = [0] * 100

while True:
    n, r = map(int, input().split())
    if n == 0 and r == 0:
        break
    
    for i in range(n):
        a[i] = n - i
    
    for i in range(r):
        for j in range(n):
            b[j] = a[j]
        p, c = map(int, input().split())

        for j in range(c):
            a[j] = b[p - 1 + j]
        
        for j in range(c, c + p - 1):
            a[j] = b[j - c]
    
    print(a[0])

# <END-OF-CODE>

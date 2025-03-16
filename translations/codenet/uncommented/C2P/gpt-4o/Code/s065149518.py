MAX = 21

def init(n):
    global x, y, fld
    x = y = 10
    fld = [[0] * MAX for _ in range(MAX)]
    for _ in range(n):
        a, b = map(int, input().split())
        fld[b][a] = 1

def move(m):
    global n, x, y, fld
    for _ in range(m):
        buf, a = input().split()
        a = int(a)
        if buf[0] == 'N':
            d = 0
        elif buf[0] == 'E':
            d = 1
        elif buf[0] == 'S':
            d = 2
        elif buf[0] == 'W':
            d = 3
        
        while a > 0:
            if d % 2:
                x += 1 if d == 1 else -1
            else:
                y += 1 if d == 0 else -1
            
            if fld[y][x]:
                fld[y][x] = 0
                n -= 1
            
            a -= 1

if __name__ == "__main__":
    while True:
        n = int(input())
        if n == 0:
            break
        init(n)
        m = int(input())
        move(m)
        print("No" if n else "Yes")

# <END-OF-CODE>

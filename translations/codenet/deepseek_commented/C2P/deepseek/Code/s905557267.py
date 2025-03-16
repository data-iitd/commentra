def min(a, b):
    if a <= b:
        return a
    return b

def Chain(b, n):
    a = b[:]
    i = 0
    while i < n - 3:
        if a[i] != 0 and a[i] == a[i + 1] == a[i + 2] == a[i + 3]:
            count = 0
            color = a[i]
            while i + count < n and a[i + count] == color:
                a[i + count] = 0
                count += 1
            for j in range(i, i + count):
                for k in range(i + count, n):
                    if a[k] != 0:
                        a[j], a[k] = a[k], a[j]
                        break
            i = 0
        else:
            i += 1
    return a.count(0)

def main():
    while True:
        n = int(input())
        if n == 0:
            break
        a = list(map(int, input().split()))
        ans = n
        for i in range(n - 3):
            count = [0, 0, 0]
            for j in range(i, i + 4):
                count[a[j] - 1] += 1
            color = 0
            for j in range(3):
                if count[j] >= 3:
                    color = j + 1
                    break
            if color != 0:
                for j in range(i, i + 4):
                    buf = a[j]
                    a[j] = color
                    ans = min(ans, Chain(a, n))
                    a[j] = buf
        print(ans)

main()

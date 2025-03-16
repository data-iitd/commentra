def min(a, b):
    if a <= b:
        return a
    return b

def Chain(b, n):
    a = b[:]  # Copy the input array
    i = 0
    while i < n - 4:
        if a[i] != 0 and a[i] == a[i + 1] and a[i] == a[i + 2] and a[i] == a[i + 3]:
            count = 0
            color = a[i]
            j = i
            while j < n and a[j] == color:
                a[j] = 0
                count += 1
                j += 1
            for j in range(i + count, n):
                a[j - count] = a[j]
                a[j] = 0
            i = 0
        else:
            i += 1
    count = 0
    while count < n and a[count] != 0:
        count += 1
    if count == 4 and a[0] == a[1] and a[0] == a[2] and a[0] == a[3]:
        return 0
    return count

def main():
    while True:
        n = int(input())
        if n == 0:
            break
        a = list(map(int, input().split()))
        ans = n
        for i in range(n - 4):
            count = [0, 0, 0]
            for j in range(i, i + 4):
                if a[j] - 1 >= 0:
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

import sys

N = 200 + 10
f = [0] * N
b = [''] * N

def getFail(b, m):
    j = 0
    f[0] = f[1] = 0
    for i in range(2, m + 1):
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    s1 = data[1]
    str_ = data[2]
    
    cnt = 0
    for i in range(n):
        b[cnt + 1] = str_[i]
        cnt += 1
    for i in range(n):
        b[cnt + 1] = s1[i]
        cnt += 1
    
    getFail(b, cnt)
    length = min(f[cnt], min(n, n))
    print(2 * n - length)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

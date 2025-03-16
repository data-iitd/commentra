import sys

def get_fail(b, m):
    f = [0] * (m + 1)
    j = 0
    f[0] = f[1] = 0
    for i in range(2, m + 1):
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j
    return f

def main():
    input_reader = sys.stdin
    n = int(input_reader.readline().strip())
    s1 = input_reader.readline().strip()
    str = input_reader.readline().strip()
    
    cnt = 0
    b = [0] * (2 * n + 1)
    for i in range(n):
        b[cnt + 1] = str[i]
        cnt += 1
    for i in range(n):
        b[cnt + 1] = s1[i]
        cnt += 1
    
    f = get_fail(b, cnt)
    len_pattern = min(f[cnt], min(n, n))
    print(2 * n - len_pattern)

if __name__ == "__main__":
    main()

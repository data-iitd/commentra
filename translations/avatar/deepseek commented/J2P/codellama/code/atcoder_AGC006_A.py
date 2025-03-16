
import sys

def get_fail(b, m):
    j = 0
    f = [0] * (m + 1)
    f[0] = f[1] = 0
    for i in range(2, m + 1):
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j

def main():
    n = int(sys.stdin.readline())
    s1 = sys.stdin.readline().strip()
    str = sys.stdin.readline().strip()

    # Construct a combined string
    cnt = 0
    for i in range(n):
        b[cnt + 1] = str[i]
    for i in range(n):
        b[cnt + 2 + i] = s1[i]

    # Compute the failure array for the combined string
    get_fail(b, cnt + 2 + n)

    # Calculate the result based on the failure array
    len = min(f[cnt + 2 + n], min(n, n))

    # Print the result
    print(2 * n - len)

if __name__ == '__main__':
    b = [0] * (200 + 10)
    main()


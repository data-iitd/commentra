
import sys

def get_fail(b, m):
    # Function declaration and initialization of variables
    j = 0
    f = [0] * (m + 1)
    f[0] = f[1] = 0

    # Main logic of the function
    for i in range(2, m + 1):
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]
        if b[j + 1] == b[i]:
            j += 1
        f[i] = j

def main():
    # Main function declaration and initialization of variables
    in = sys.stdin
    out = sys.stdout

    n = int(in.readline().strip())
    s1 = in.readline().strip()
    str = in.readline().strip()

    cnt = 0

    # Concatenating the two strings and creating character arrays for each
    for i in range(n):
        b[cnt + 1] = str[i]
    for i in range(n):
        b[cnt + 2 + i] = s1[i]

    get_fail(b, cnt + 2 + n)

    len = min(f[cnt + 2 + n], min(n, n))

    out.write(str(2 * n - len) + '\n')

    out.flush()

if __name__ == '__main__':
    b = [0] * (200 + 10)
    main()


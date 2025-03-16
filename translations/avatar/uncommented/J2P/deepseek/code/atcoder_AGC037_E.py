import sys

def main():
    n = int(input().strip())
    k = int(input().strip())
    s = input().strip()
    first_time = True
    step = 1

    while k > 0:
        t = s
        t = t[::-1]
        rev_u = s + t
        rev_u = rev_u[::-1]
        s_dash = s

        for i in range(n, -1, -step):
            tmp = rev_u[i:i+n]
            if s_dash > tmp:
                s_dash = tmp
            else:
                if not first_time:
                    break

        if first_time:
            first_time = False
            if 2 ** k > n:
                c = s_dash[0]
                for _ in range(n):
                    print(c, end='')
                print()
                sys.exit(0)
        else:
            step += step
        k -= 1
        s = s_dash
        s = s[::-1]

    s = s[::-1]
    print(s)

if __name__ == "__main__":
    main()

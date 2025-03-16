import sys

def main():
    c = []
    for _ in range(3):
        row = list(map(int, sys.stdin.readline().split()))
        c.append(row)

    a = [0] * 3
    b = [0] * 3

    b[0] = c[0][0] - a[0]
    b[1] = c[0][1] - a[0]
    b[2] = c[0][2] - a[0]
    a[1] = c[1][0] - c[0][0]
    a[2] = c[2][0] - c[0][0]

    if (a[1] == c[1][1] - c[0][1] and
        a[1] == c[1][2] - c[0][2] and
        a[2] == c[2][1] - c[0][1] and
        a[2] == c[2][2] - c[0][2]):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

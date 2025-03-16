
import sys

def main():
    x = input()
    a = list(x)
    b = list(x)
    a1 = 0
    a2 = 0

    for i in range(1, len(x)):
        if a[i] == a[i - 1]:
            if a[i] == '1':
                a[i] = '0'
            else:
                a[i] = '1'
            a1 += 1

    for i in range(len(x) - 1, 0, -1):
        if b[i] == b[i - 1]:
            if b[i - 1] == '1':
                b[i - 1] = '0'
            else:
                b[i - 1] = '1'
            a2 += 1

    print(min(a1, a2))

if __name__ == "__main__":
    sys.exit(main())


import sys

def main():
    n = int(input())

    if n == 0:
        print('0')
        return

    s = ""

    while n != 0:
        if n % 2 == 0:
            s += '0'
        else:
            s += '1'

        n -= abs(n % 2)
        n //= -2

    print(s[::-1])

if __name__ == "__main__":
    main()

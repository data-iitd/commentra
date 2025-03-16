
import sys

def main():
    A, B = map(int, sys.stdin.readline().split())
    result = (B - 1) // (A - 1)
    amari = (B - 1) % (A - 1)
    if amari!= 0:
        result += 1
    print(result)

if __name__ == '__main__':
    main()


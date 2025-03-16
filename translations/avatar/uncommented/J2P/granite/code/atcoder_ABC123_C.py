
import sys
import math

def main():
    N = int(input())
    min = int(input())
    for i in range(4):
        tmp = int(input())
        if tmp < min:
            min = tmp
    print(math.ceil(N / min) + 4)

if __name__ == '__main__':
    main()


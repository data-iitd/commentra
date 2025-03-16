
import bufio
import math
import os
import sys

def main():
    AB = list(map(int, input().split()))
    A = AB[0]
    B = AB[1]

    if (A+B)%2 == 0:
        print((A + B) // 2)
        return
    print("IMPOSSIBLE")

if __name__ == '__main__':
    main()



import bufio
import os
import sys

def main():
    H, W, N = map(int, input().split())
    A = max(H, W)
    print((N + A - 1) // A)

if __name__ == '__main__':
    main()


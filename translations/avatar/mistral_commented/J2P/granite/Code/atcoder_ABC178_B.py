

import sys
import math

def main():
    a = [int(x) for x in sys.stdin.readline().split()]
    result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])))
    print(result)

if __name__ == "__main__":
    main()

These comments should provide a clear understanding of the code for anyone who reads it.


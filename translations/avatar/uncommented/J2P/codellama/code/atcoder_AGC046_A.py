
import sys
import math

def main():
    x = int(sys.stdin.readline())
    count = 0
    tmp = x
    x = 0
    while x != 360:
        x = x + tmp
        if x > 360:
            x = x - 360
        count += 1
    print(count)

if __name__ == "__main__":
    main()


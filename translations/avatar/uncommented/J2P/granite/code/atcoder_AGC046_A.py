
import sys
import math

def main():
    x = int(input())
    count = 0
    tmp = x
    x = 0
    while x!= 360:
        x = x + tmp
        if x > 360:
            x = x - 360
        count = count + 1
    print(count)

if __name__ == "__main__":
    main()


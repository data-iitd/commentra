
import sys
import math
import re

def main():
    a = sys.stdin.readline().strip()
    a = re.sub(r',','', a)
    print(a)

if __name__ == '__main__':
    main()


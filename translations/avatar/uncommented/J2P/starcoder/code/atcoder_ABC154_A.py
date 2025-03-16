
# <START-OF-CODE>

import sys

def main():
    input = sys.stdin.readline()
    str = input.split()
    input = sys.stdin.readline()
    st = input.split()
    a = int(st[0])
    b = int(st[1])
    u = sys.stdin.readline()
    if u == str[0]:
        print(a-1, b)
    else:
        print(a, b-1)

if __name__ == '__main__':
    main()

# 
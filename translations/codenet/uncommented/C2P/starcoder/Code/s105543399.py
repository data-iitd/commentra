
#include <stdio.h>

def main():
    n = int(raw_input())
    a = 0
    m = 100000000
    M = -100000000
    c = 0
    for i in range(1,n+1):
        a = int(raw_input())
        if a > M:
            M = a
        if a < m:
            m = a
        c = c+a
    print m,M,c

if __name__ == "__main__":
    main()


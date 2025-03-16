
# <START-OF-CODE>

import sys

def main():
    n = int(sys.stdin.readline())
    a = [int(x) for x in sys.stdin.readline().split()]
    l = 0
    r = 0
    flag = False
    isTrue = False
    for i in range(n):
        if a[i]!= i+1 and not flag:
            l = i+1
            flag = True
            continue
        if a[i]!= i+1 and flag:
            r = i+1
            if (a[r-1] - a[r-2] > 0):
                isTrue = True
                break
    if not isTrue:
        print(l, r)
    else:
        print("0 0")

if __name__ == "__main__":
    main()

# 
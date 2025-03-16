
import sys

def main():
    n = int(input())
    a = []
    for i in range(n):
        a.append(int(input()))
    a.sort()
    if a[-1] == 0:
        print(0)
        sys.exit(0)
    while True:
        a = func(a)
        if len(a) == 1:
            print(a[0])
            sys.exit(0)

def func(a):
    a = a[:]
    min = 0
    for i in range(len(a)):
        if a[i] == 0:
            a.pop(i)
            i -= 1
        else:
            if min!= 0:
                a[i] = a[i] % min
                if a[i] == 1:
                    print(1)
                    sys.exit(0)
            else:
                min = a[i]
    a.sort()
    return a

if __name__ == "__main__":
    main()


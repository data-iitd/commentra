import sys

def printIsland(n, count):
    a = (n + 1) / 2
    b = n / 2
    max = a * a + b * b

    if count > max:
        print "NO"
        return

    print "YES"

    for i in range(n):
        sb = ""
        for j in range(n):
            if (i + j) % 2 == 0 and count > 0:
                sb += "L"
                count -= 1
            else:
                sb += "S"
        print sb

if __name__ == "__main__":
    n = int(raw_input())
    count = int(raw_input())
    printIsland(n, count)


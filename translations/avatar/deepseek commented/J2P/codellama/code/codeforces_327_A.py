import sys

def main():
    scanner = sys.stdin
    if scanner.readline():
        n = int(scanner.readline())
        arr = [int(i) for i in scanner.readline().split()]
        max = -1
        for i in range(n):
            for j in range(i, n):
                brr = arr[:]
                for k in range(i, j+1):
                    if brr[k] == 0:
                        brr[k] = 1
                    else:
                        brr[k] = 0
                count = checkNo(brr)
                if count > max:
                    max = count
        if n == 1:
            if arr[0] == 1:
                print(0)
            else:
                print(1)
        else:
            print(max)

def checkNo(brr):
    val = 0
    for i in brr:
        if i == 1:
            val += 1
    return val

if __name__ == "__main__":
    main()


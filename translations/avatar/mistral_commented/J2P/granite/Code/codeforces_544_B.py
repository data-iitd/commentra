
import sys

def printIsland(n, count):
    a = (n + 1) // 2
    b = n // 2
    max = a * a + b * b
    if count > max:
        print("NO")
        return
    print("YES")
    for i in range(n):
        row = ""
        for j in range(n):
            if (i + j) % 2 == 0 and count > 0:
                row += "L"
                count -= 1
            else:
                row += "S"
        print(row)

def main():
    n = int(input())
    count = int(input())
    printIsland(n, count)

if __name__ == "__main__":
    main()


import sys

def main():
    n = int(input())
    lst = [int(input()) for _ in range(n)]
    lst.sort()
    c = 1
    for i in range(n):
        if lst[i] >= c:
            c += 1
    print(c)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

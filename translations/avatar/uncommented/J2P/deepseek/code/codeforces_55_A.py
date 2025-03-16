import sys

def main():
    n = int(input().strip())
    a = [0] * n
    i = 0
    k = 0
    while k < n:
        i = (i + k) % n
        a[i] += 1
        k += 1
    if all(x > 0 for x in a):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

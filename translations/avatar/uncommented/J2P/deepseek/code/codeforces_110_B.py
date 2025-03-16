import sys

def main():
    n = int(input().strip())
    c = [''] * n
    p = 97
    for i in range(4):
        for j in range(i, n, 4):
            c[j] = chr(p)
        p += 1
    print(''.join(c))

if __name__ == "__main__":
    main()

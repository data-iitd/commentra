import sys

def main():
    n = int(input().strip())
    m = int(input().strip())
    a = [0] * m
    
    if n % m == 0:
        for i in range(m):
            a[i] = n // m
    else:
        sub = n // m
        for i in range(m):
            a[i] = sub
        test = n - (sub * m)
        count = 0
        for i in range(test):
            a[count] += 1
            count = (count + 1) % m
    
    for i in range(m - 1, -1, -1):
        print(a[i], end=' ')

if __name__ == "__main__":
    main()

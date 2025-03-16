
import sys

def main():
    n = int(input())
    a = list(map(int, input().split()))
    for k in range(n):
        t = a[k]
        for i in range(n):
            for j in range(n-1):
                if i!= j and t == (a[i] + a[j]):
                    print(k+1, j+1, i+1)
                    return
    print(-1)

if __name__ == "__main__":
    main()


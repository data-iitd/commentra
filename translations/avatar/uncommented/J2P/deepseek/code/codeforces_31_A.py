import sys

def main():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    
    found = False
    for k in range(n):
        t = a[k]
        for i in range(n):
            for j in range(n):
                if i != j and t == a[i] + a[j]:
                    print(k + 1, i + 1, j + 1)
                    found = True
                    break
            if found:
                break
        if found:
            break
    if not found:
        print(-1)

if __name__ == "__main__":
    main()

def main():
    a = []
    n = int(input())
    for i in range(n):
        a.append(int(input()))
    
    d = 0
    for i in range(n):
        for j in range(n - 1, i, -1):
            if a[j] < a[j - 1]:
                a[j], a[j - 1] = a[j - 1], a[j]
                d += 1
    
    print(a[0], end="")
    for i in range(1, n):
        print(f" {a[i]}", end="")
    print(f"\n{d}\n")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

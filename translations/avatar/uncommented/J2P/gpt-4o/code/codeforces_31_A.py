def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = list(map(int, data[1:n+1]))
    
    found = False
    
    for k in range(n):
        t = a[k]
        for i in range(n):
            for j in range(n):
                if i != j and t == (a[i] + a[j]):
                    print(k + 1, j + 1, i + 1)
                    found = True
                    break
            if found:
                break
        if found:
            break
    
    if not found:
        print("-1")

if __name__ == "__main__":
    main()
    
# <END-OF-CODE>

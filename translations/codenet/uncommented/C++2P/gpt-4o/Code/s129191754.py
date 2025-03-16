def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = list(map(int, data[1:n+1]))
    
    a.sort()
    
    for i in range(n - 1):
        if a[i] == a[i + 1]:
            print("NO")
            return
            
    print("YES")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

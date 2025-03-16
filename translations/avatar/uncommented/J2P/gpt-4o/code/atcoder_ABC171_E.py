def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = list(map(int, data[1:n+1]))
    r = 0
    
    for i in range(n):
        r ^= a[i]
    
    result = []
    for i in range(n):
        result.append(str(r ^ a[i]))
    
    print(" ".join(result))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

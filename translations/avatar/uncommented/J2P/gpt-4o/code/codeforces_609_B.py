def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])
    arr = list(map(int, data[2:n+2]))
    
    gen = [0] * 11
    
    for i in range(n):
        gen[arr[i]] += 1
    
    ans = 0
    for i in range(1, m + 1):
        for k in range(1, m + 1):
            if i != k:
                ans += gen[i] * gen[k]
    
    print(ans // 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

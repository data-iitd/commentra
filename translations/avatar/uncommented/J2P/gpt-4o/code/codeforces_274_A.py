def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    arr = list(map(int, data[2:n+2]))
    
    arr.sort()
    count = 0
    seen = set()
    
    for i in range(n):
        if arr[i] % k != 0:
            count += 1
            seen.add(arr[i])
        elif (arr[i] // k) not in seen:
            count += 1
            seen.add(arr[i])
    
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

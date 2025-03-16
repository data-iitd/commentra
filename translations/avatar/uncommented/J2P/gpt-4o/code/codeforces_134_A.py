def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    arr = list(map(int, data[1:n+1]))
    
    total_sum = sum(arr)
    count = 0
    indices = []
    
    for i in range(n):
        if (total_sum - arr[i]) % (n - 1) == 0 and (total_sum - arr[i]) // (n - 1) == arr[i]:
            count += 1
            indices.append(i + 1)  # +1 for 1-based index
    
    print(count)
    print(" ".join(map(str, indices)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

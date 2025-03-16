def main():
    n = int(input())
    arr = list(map(int, input().split()))
    
    max_count = 0
    
    for i in range(n):
        for j in range(i, n):
            brr = arr[:]
            for k in range(i, j + 1):
                brr[k] = 1 - brr[k]
            
            count = brr.count(1)
            max_count = max(max_count, count)
    
    if n == 1:
        print(0 if arr[0] == 1 else 1)
    else:
        print(max_count)

if __name__ == "__main__":
    main()

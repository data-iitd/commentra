def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    A = list(map(int, data[1:N+1]))
    
    A.sort()
    
    min_val = A[0]
    max_val = A[-1]
    
    mins = A.count(min_val)
    maxs = A.count(max_val)
    
    if min_val == max_val:
        result = (max_val - min_val + 1) * mins - (mins * (mins - 1) // 2)
    else:
        result = (max_val - min_val) * mins * maxs
    
    print(result)

if __name__ == "__main__":
    main()

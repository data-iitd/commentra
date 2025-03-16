MOD = int(1e9 + 7)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    index = 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        a = int(data[index + 1])
        b = int(data[index + 2])
        index += 3
        
        if n < a:
            results.append("No")
            continue
        if a == b:
            if n % a == 0:
                results.append("Yes")
            else:
                results.append("No")
            continue
        x = b // (b - a)
        if n > x * a:
            results.append("Yes")
            continue
        low = 1
        high = x + 1
        ans = 1
        while low <= high:
            mid = (low + high) // 2
            if mid * a < n:
                low = mid + 1
            else:
                ans = mid
                high = mid - 1
        if n > (ans - 1) * b and n < ans * a:
            results.append("No")
        else:
            results.append("Yes")
    
    print("\n".join(results))

if __name__ == "__main__":
    main()

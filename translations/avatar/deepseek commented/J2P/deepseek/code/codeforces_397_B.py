def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    index = 1
    
    while t > 0:
        t -= 1
        n = int(data[index])
        a = int(data[index + 1])
        b = int(data[index + 2])
        index += 3
        
        if n < a:
            print("No")
            continue
        
        if a == b:
            if n % a == 0:
                print("Yes")
            else:
                print("No")
            continue
        
        x = b // (b - a)
        
        if n > x * a:
            print("Yes")
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
            print("No")
        else:
            print("Yes")

if __name__ == "__main__":
    main()

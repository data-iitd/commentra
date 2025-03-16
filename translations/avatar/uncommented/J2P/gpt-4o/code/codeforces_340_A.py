def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    x = int(data[0])
    y = int(data[1])
    a = int(data[2])
    b = int(data[3])
    
    j = 2
    c = max(x, y)
    
    if c > b:
        print("0")
        return
    
    ans = True
    while c % min(x, y) != 0 and ans:
        if x > y:
            c = x * j
        else:
            c = y * j
        j += 1
        
        if c > b:
            print("0")
            ans = False
            break
    
    if ans:
        count = 0
        for i in range(a, b + 1):
            if i % c == 0:
                break
        
        if i != b + 1:
            print((b - i) // c + 1)
        else:
            print("0")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

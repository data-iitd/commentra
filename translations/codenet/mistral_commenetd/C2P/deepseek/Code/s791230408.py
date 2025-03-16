def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    j = int(data[0])
    index = 1
    
    for i in range(j):
        a = int(data[index])
        b = int(data[index + 1])
        c = int(data[index + 2])
        index += 3
        
        max_val = a
        k = 0
        
        if max_val <= b:
            max_val = b
            k = 1
        
        if max_val <= c:
            max_val = c
            k = 2
        
        max_val **= 2
        a **= 2
        b **= 2
        c **= 2
        
        if k == 0 and max_val == b + c:
            print("YES")
        elif k == 1 and max_val == a + c:
            print("YES")
        elif k == 2 and max_val == a + b:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

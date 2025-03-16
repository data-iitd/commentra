def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    str_num = data[1]
    
    t = 0
    for char in str_num:
        if char != '4' and char != '7':
            t = 1
            
    if t == 1:
        print("NO")
    else:
        x = sum(int(str_num[i]) for i in range(n // 2))
        y = sum(int(str_num[i]) for i in range(n // 2, n))
        
        if x == y:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

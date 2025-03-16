def main():
    n = int(input())
    s = input()
    l = list(s)
    t = 0
    
    for char in l:
        if char != '4' and char != '7':
            t = 1
            break
    
    if t == 1:
        print("NO")
    else:
        x = sum(int(char) for char in l[:n//2])
        y = sum(int(char) for char in l[n//2:])
        if x == y:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()

def main():
    import sys
    input = sys.stdin.read
    n = int(input().strip())
    
    i = 0
    k = 0
    a = [0] * 1000
    flag = True
    
    while k <= n:
        i += k
        if i >= n:
            while not (i < n):
                i -= n
        a[i] += 1
        k += 1
    
    for i in range(n):
        if a[i] == 0:
            flag = False
            break
    
    if flag:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

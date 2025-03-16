def main():
    n = int(input())
    x = int(input())
    l = []
    
    for _ in range(n):
        tmpL = int(input())
        l.append(tmpL)
    
    tmp_sum = 0
    rs = 0
    
    for i, v in enumerate(l):
        tmp_sum += v
        if i >= n:
            rs = n
            break
        if tmp_sum <= x:
            rs = i + 2
        elif tmp_sum > x:
            break
    
    print(rs)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

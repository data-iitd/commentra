def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    ch = []
    s1, s2 = 0, 0
    j = 0
    flag = 0
    
    index = 1
    for i in range(n):
        x = int(data[index])
        y = int(data[index + 1])
        index += 2
        
        temp1 = s1 + x
        temp2 = s2 + y
        
        if abs(temp1 - s2) <= 500:
            s1 += x
            ch.append('A')
            j += 1
            continue
        
        if abs(temp2 - s1) <= 500:
            s2 += y
            ch.append('G')
            j += 1
            continue
        
        flag = 1
        break
    
    if flag == 1:
        print(-1)
    else:
        ans = ''.join(ch)
        print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

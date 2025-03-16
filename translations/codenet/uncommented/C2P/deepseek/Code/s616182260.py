def main():
    c = []
    for _ in range(3):
        c.append(list(map(int, input().split())))
    
    a = [0] * 3
    b = [0] * 3
    
    b[0] = c[0][0]
    for i in range(3):
        b[i] = c[0][i]
    
    for i in range(1, 3):
        a[i] = c[i][0] - b[0]
    
    for i in range(3):
        for j in range(3):
            if c[i][j] != a[i] + b[j]:
                print("No")
                return
    
    print("Yes")

if __name__ == "__main__":
    main()

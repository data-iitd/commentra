def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    M = int(data[1])
    
    black = [[0] * (N + 2) for _ in range(N + 2)]
    
    index = 2
    for m in range(1, M + 1):
        x = int(data[index])
        y = int(data[index + 1])
        index += 2
        
        for xx in range(x - 1, x + 2):
            for yy in range(y - 1, y + 2):
                if (black[xx][yy] := black[xx][yy] + 1) == 9:
                    print(m)
                    return
    
    print("-1")

if __name__ == "__main__":
    main()

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    N = int(data[index])
    index += 1
    M = int(data[index])
    index += 1
    
    H = list(map(int, data[index:index + N]))
    index += N
    
    ans = [True] * N
    
    for _ in range(M):
        temp1 = int(data[index]) - 1
        index += 1
        temp2 = int(data[index]) - 1
        index += 1
        
        if H[temp1] < H[temp2]:
            ans[temp1] = False
        elif H[temp1] > H[temp2]:
            ans[temp2] = False
        else:
            ans[temp1] = False
            ans[temp2] = False
    
    ans2 = sum(ans)
    print(ans2)

if __name__ == "__main__":
    main()

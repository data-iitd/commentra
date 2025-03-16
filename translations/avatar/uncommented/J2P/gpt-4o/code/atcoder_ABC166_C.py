def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    N = int(data[index])
    index += 1
    M = int(data[index])
    index += 1
    
    H = [0] * N
    ans = [True] * N
    
    for i in range(N):
        H[i] = int(data[index])
        index += 1
    
    for i in range(M):
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
    
    ans2 = sum(1 for x in ans if x)
    print(ans2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

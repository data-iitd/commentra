def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    K = int(data[1])
    A = list(map(int, data[2:N+2]))
    
    B = [-1] * (200100)
    now = 1
    cnt = 0
    
    B[1] = 0
    for j in range(1, K + 1):
        now = A[now - 1]  # Adjusting for 0-based index
        if B[now] == -1:
            B[now] = j
        else:
            cnt = j
            break
    
    if j < K:
        tmp = (K - B[now]) % (cnt - B[now])
        for _ in range(tmp):
            now = A[now - 1]  # Adjusting for 0-based index
    
    print(now)

if __name__ == "__main__":
    main()

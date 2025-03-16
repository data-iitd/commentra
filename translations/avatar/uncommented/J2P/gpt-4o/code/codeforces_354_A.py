def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    L = int(data[1])
    R = int(data[2])
    QL = int(data[3])
    QR = int(data[4])
    
    W = list(map(int, data[5:5 + N]))
    sum_ = [0] * (N + 1)
    
    for n in range(N):
        sum_[n + 1] = sum_[n] + W[n]
    
    min_value = float('inf')
    
    for firstR in range(N + 1):
        lCount = firstR
        rCount = N - lCount
        cand = sum_[lCount] * L + (sum_[N] - sum_[lCount]) * R
        
        llCount = max(0, lCount - rCount - 1)
        rrCount = max(0, rCount - lCount - 1)
        
        cand += llCount * QL
        cand += rrCount * QR
        
        min_value = min(cand, min_value)
    
    print(min_value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

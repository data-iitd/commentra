def main():
    X, N = map(int, input().split())
    if N == 0:
        print(X)
        return
    
    plus = list(range(256))
    minus = [-i for i in range(256)]
    
    for _ in range(N):
        j = int(input())
        plus[j] = 0
    
    i_min = 0
    min_diff = 1000
    
    for i in range(255, -1, -1):
        if plus[i] == 0 and i > 0:
            continue
        k = X - plus[i]
        if k < 0:
            k *= -1
        if k <= min_diff:
            min_diff = k
            i_min = i
    
    print(i_min)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

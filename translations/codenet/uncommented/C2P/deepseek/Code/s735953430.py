import sys

def main():
    X, N = map(int, sys.stdin.readline().split())
    if N == 0:
        print(X)
        return
    
    plus = [0] * 256
    minus = [-i for i in range(256)]
    
    for i in range(N):
        j = int(sys.stdin.readline())
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

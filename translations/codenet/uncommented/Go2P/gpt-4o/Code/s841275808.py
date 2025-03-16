import sys

def scan_int():
    return int(sys.stdin.readline().strip())

def main():
    N = scan_int()
    X = [0] * N
    Y = [0] * N
    
    for i in range(N):
        X[i] = scan_int()
        Y[i] = X[i]
    
    Y.sort()
    m1 = Y[N // 2 - 1]
    m2 = Y[N // 2]
    
    for i in range(N):
        if X[i] <= m1:
            print(m2)
        else:
            print(m1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

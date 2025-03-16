import sys

def main():
    N = int(input().strip())
    X = list(map(int, input().strip().split()))
    Y = X[:]
    
    Y.sort()
    
    y = Y[N // 2]
    for i in range(N):
        if X[i] < Y[N // 2]:
            print(Y[N // 2])
        else:
            print(Y[N // 2 - 1])
        print()

if __name__ == "__main__":
    main()

def main():
    N = int(input())
    X = list(map(int, input().split()))
    Y = sorted(X)
    median = Y[N // 2]
    
    for x in X:
        if x < median:
            print(median)
        else:
            print(median - 1)

if __name__ == "__main__":
    main()

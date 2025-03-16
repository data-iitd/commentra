def main():
    N = int(input())
    idorder = {}
    A = list(map(int, input().split()))
    for i in range(N):
        idorder[A[i]] = i + 1
    for i in range(1, N + 1):
        print(idorder[i], end=' ')

if __name__ == "__main__":
    main()

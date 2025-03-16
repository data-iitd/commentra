def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    A = list(map(int, data[1:N+1]))

    answer = 0
    for i in range(N - 1):
        for j in range(i + 1, N):
            diff = abs(A[i] - A[j])
            answer = max(answer, diff)
    
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

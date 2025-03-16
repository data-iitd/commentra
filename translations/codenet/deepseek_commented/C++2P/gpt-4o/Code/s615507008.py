def solve(N, T, M, P, X):
    # Solve function: This function processes the input data to calculate and output the results for each operation.
    for i in range(M):
        # Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
        ans = 0
        for j in range(N):
            if j == P[i] - 1:
                ans += X[i]
            else:
                ans += T[j]
        print(ans)

def main():
    # Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    N = int(data[index])
    index += 1
    T = list(map(int, data[index:index + N]))
    index += N
    M = int(data[index])
    index += 1
    P = list(map(int, data[index:index + M]))
    index += M
    X = list(map(int, data[index:index + M]))
    
    solve(N, T, M, P, X)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

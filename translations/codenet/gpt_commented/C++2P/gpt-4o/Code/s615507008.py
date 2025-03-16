def solve(N, T, M, P, X):
    # Iterate over each modification request
    for i in range(M):
        ans = 0  # Initialize the answer for the current modification
        # Calculate the total time considering the current modification
        for j in range(N):
            # If the current index matches the modified position, add the new time value
            if j == P[i] - 1:
                ans += X[i]
            # Otherwise, add the original time value
            else:
                ans += T[j]
        # Output the result for the current modification
        print(ans)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    N = int(data[index])  # Read the number of time values
    index += 1
    T = list(map(int, data[index:index + N]))  # Read the original time values into the list
    index += N
    
    M = int(data[index])  # Read the number of modifications
    index += 1
    P = list(map(int, data[index:index + M]))  # Read the modification positions
    index += M
    X = list(map(int, data[index:index + M]))  # Read the new time values for modifications
    
    # Call the solve function to process the modifications and output results
    solve(N, T, M, P, X)

if __name__ == "__main__":
    main()  # Indicate successful completion of the program

# <END-OF-CODE>

def main():
    # Optimize input/output operations
    import sys
    input = sys.stdin.readline
    print = sys.stdout.write
    
    # Read the number of elements in the array
    N = int(input())
    
    # Initialize a list to store the elements
    A = list(map(int, input().split()))

    # Initialize a variable to keep track of the maximum difference
    answer = 0
    
    # Iterate through all pairs of elements to find the maximum difference
    for i in range(N - 1):
        for j in range(i + 1, N):
            # Calculate the absolute difference between the two elements
            diff = abs(A[i] - A[j])
            
            # Update the maximum difference found so far
            answer = max(answer, diff)
    
    # Output the maximum difference
    print(str(answer) + '\n')

if __name__ == "__main__":
    main()

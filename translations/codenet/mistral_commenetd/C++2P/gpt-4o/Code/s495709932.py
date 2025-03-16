def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the number of elements in the vector
    N = int(data[0])
    
    # Initialize a list of size N with integers
    A = list(map(int, data[1:N+1]))
    
    # Initialize the answer variable to 0
    answer = 0
    
    # Outer loop iterates through each element in the list except the last one
    for i in range(N - 1):
        # Inner loop iterates through the remaining elements in the list starting from the next element
        for j in range(i + 1, N):
            # Calculate the absolute difference between the current and next elements
            diff = abs(A[i] - A[j])
            
            # Update the answer variable with the maximum difference found so far
            answer = max(answer, diff)
    
    # Print the answer
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

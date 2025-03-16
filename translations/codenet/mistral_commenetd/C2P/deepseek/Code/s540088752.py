def main():
    # Read an integer value from the standard input and store it in N
    N = int(input())
    
    # Read the elements of array A from the standard input
    A = list(map(int, input().split()))
    
    # Read the elements of array B from the standard input
    B = list(map(int, input().split()))
    
    # Initialize a variable named ans to 0
    ans = 0
    
    # Nested for loop to compare each pair of elements from arrays A and B
    for i in range(N):
        # site i
        if A[i] >= B[i]:
            ans += B[i]  # Add the smaller element to the answer
            A[i] -= B[i]  # Subtract the smaller element from the corresponding element in array A
            B[i] = 0  # Set the smaller element in array B to 0
        else:
            ans += A[i]  # Add the smaller element to the answer
            B[i] -= A[i]  # Subtract the smaller element from the corresponding element in array B
            A[i] = 0  # Set the smaller element in array A to 0
        
        # site i + 1
        if A[i + 1] >= B[i]:
            ans += B[i]  # Add the smaller element to the answer
            A[i + 1] -= B[i]  # Subtract the smaller element from the corresponding element in array A
            B[i] = 0  # Set the smaller element in array B to 0
        else:
            ans += A[i + 1]  # Add the smaller element to the answer
            B[i] -= A[i + 1]  # Subtract the smaller element from the corresponding element in array B
            A[i + 1] = 0  # Set the smaller element in array A to 0
    
    # Print the final answer
    print(ans)  # Print the value of the answer variable

# Call the main function
main()

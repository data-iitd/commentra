import sys

def main():
    # Read the number of elements (N) and the size of the subset (K)
    N, K = map(int, input().split())
    
    # Read N integers into the list S
    S = list(map(int, input().split()))
    
    # Initialize temporary variable and answer variable with a large number
    temp = 0
    ans = 1000000000

    # Case when K is 1: Find the minimum absolute value in the array
    if K == 1:
        for i in range(N):
            temp = S[i]
            ans = min(abs(temp), ans)  # Update ans with the minimum absolute value
        # Output the result
        print(ans)
    
    # Case when K is not equal to N: Calculate the minimum value based on subsets of size K
    elif N - K != 0:
        for i in range(N - K + 1):
            min_val = S[i]  # Minimum value in the current subset
            max_val = S[i + K - 1]  # Maximum value in the current subset
            
            # Calculate temp based on the values of min and max
            if min_val < 0 and max_val > 0:
                # If the subset contains both negative and positive values
                temp = min(2 * (-min_val) + max_val, (-min_val) + 2 * max_val)
            else:
                # If the subset contains only negative or only positive values
                temp = max(abs(min_val), abs(max_val))
            
            # Update the answer with the minimum value found
            ans = min(ans, temp)
        # Output the result
        print(ans)
    
    # Case when K is equal to N: Handle the entire array as a single subset
    else:
        min_val = S[0]  # Minimum value in the array
        max_val = S[N - 1]  # Maximum value in the array
        
        # Check if the array contains both negative and positive values
        if min_val < 0 and max_val > 0:
            # Calculate and print the minimum value based on the formula
            print(min(2 * (-min_val) + max_val, (-min_val) + 2 * max_val))
        else:
            # Print the maximum absolute value
            print(max(abs(min_val), abs(max_val)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

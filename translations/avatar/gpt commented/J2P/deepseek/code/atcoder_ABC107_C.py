import sys

def main():
    # Read the number of elements (N) and the size of the subset (K)
    N, K = map(int, sys.stdin.readline().split())
    
    # Read N integers into the array S
    S = list(map(int, sys.stdin.readline().split()))
    
    # Case when K is 1: Find the minimum absolute value in the array
    if K == 1:
        print(min(abs(x) for x in S))
    # Case when K is not equal to N: Calculate the minimum value based on subsets of size K
    elif N - K != 0:
        ans = float('inf')
        for i in range(N - K + 1):
            min_val = S[i]  # Minimum value in the current subset
            max_val = S[i + K - 1]  # Maximum value in the current subset
            
            # Calculate temp based on the values of min_val and max_val
            if min_val < 0 and max_val > 0:
                # If the subset contains both negative and positive values
                temp = min(2 * (-min_val) + max_val, -min_val + 2 * max_val)
            else:
                # If the subset contains only negative or only positive values
                temp = max(abs(min_val), abs(max_val))
            
            # Update the answer with the minimum value found
            ans = min(ans, temp)
        print(ans)
    # Case when K is equal to N: Handle the entire array as a single subset
    else:
        min_val = S[0]  # Minimum value in the array
        max_val = S[-1]  # Maximum value in the array
        
        # Check if the array contains both negative and positive values
        if min_val < 0 and max_val > 0:
            # Calculate and print the minimum value based on the formula
            print(min(2 * (-min_val) + max_val, -min_val + 2 * max_val))
        else:
            # Print the maximum absolute value
            print(max(abs(min_val), abs(max_val)))

if __name__ == "__main__":
    main()

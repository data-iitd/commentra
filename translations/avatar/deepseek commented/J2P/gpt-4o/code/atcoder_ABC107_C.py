import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read the value of N
    K = int(data[1])  # Read the value of K
    S = list(map(int, data[2:2 + N]))  # Create a list S of size N
    
    temp = 0  # Initialize temp to store intermediate results
    ans = 1000000000  # Initialize ans to store the minimum difference
    
    # Check if K is equal to 1
    if K == 1:
        for i in range(N):
            temp = S[i]  # Store the current element in temp
            ans = min(abs(temp), ans)  # Update ans with the minimum absolute value
        print(ans)  # Print the minimum absolute value
    elif N - K != 0:  # Check if the length of the subarray is not zero
        for i in range(N - K + 1):
            min_val = S[i]  # Initialize min with the first element of the subarray
            max_val = S[i + K - 1]  # Initialize max with the last element of the subarray
            
            # Check if the subarray contains both positive and negative numbers
            if min_val < 0 and max_val > 0:
                temp = min(2 * (-min_val) + max_val, (-min_val) + 2 * max_val)  # Calculate the minimum difference
            else:
                temp = max(abs(min_val), abs(max_val))  # Calculate the maximum absolute value
            
            ans = min(ans, temp)  # Update ans with the minimum difference
        print(ans)  # Print the minimum difference
    else:  # If the length of the subarray is zero
        min_val = S[0]  # Initialize min with the first element
        max_val = S[N - 1]  # Initialize max with the last element
        
        # Check if the array contains both positive and negative numbers
        if min_val < 0 and max_val > 0:
            print(min(2 * (-min_val) + max_val, (-min_val) + 2 * max_val))  # Print the minimum difference
        else:
            print(max(abs(min_val), abs(max_val)))  # Print the maximum absolute value

if __name__ == "__main__":
    main()

# <END-OF-CODE>


import sys; # Import the sys module for input

def main():
    N = int(sys.stdin.readline()); # Read the value of N
    K = int(sys.stdin.readline()); # Read the value of K
    S = [int(sys.stdin.readline()) for i in range(N)]; # Create an array S of size N
    
    # Read the elements of the array S
    temp = 0; # Initialize temp to store intermediate results
    ans = 1000000000; # Initialize ans to store the minimum difference
    
    # Check if K is equal to 1
    if (K == 1):
        for i in range(N):
            temp = S[i]; # Store the current element in temp
            ans = min(abs(temp), ans); # Update ans with the minimum absolute value
        print(ans); # Print the minimum absolute value
    else if (N - K!= 0): # Check if the length of the subarray is not zero
        for i in range(N - K + 1):
            min = S[i]; # Initialize min with the first element of the subarray
            max = S[i + K - 1]; # Initialize max with the last element of the subarray
            
            # Check if the subarray contains both positive and negative numbers
            if (min < 0 and max > 0):
                temp = min(2 * (-min) + max, (-min) + 2 * max); # Calculate the minimum difference
            else:
                temp = max(abs(min), abs(max)); # Calculate the maximum absolute value
            ans = min(ans, temp); # Update ans with the minimum difference
        print(ans); # Print the minimum difference
    else: # If the length of the subarray is zero
        min = S[0]; # Initialize min with the first element
        max = S[N - 1]; # Initialize max with the last element
        
        # Check if the array contains both positive and negative numbers
        if (min < 0 and max > 0):
            print(min(2 * (-min) + max, (-min) + 2 * max)); # Print the minimum difference
        else:
            print(max(abs(min), abs(max))); # Print the maximum absolute value

if __name__ == "__main__":
    main(); # Execute the main function


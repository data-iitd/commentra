import sys

def main():
    # Read an integer N from user input
    N = int(input())
    
    # Initialize count to track the number of digits in N
    count = 0
    
    # Temporary variable to manipulate the value of N
    temp = N
    
    # Count the number of digits in N
    while temp > 0:
        temp //= 10  # Remove the last digit from temp
        count += 1  # Increment the digit count
    
    # Initialize the final answer
    ans = 0
    
    # Loop through each digit position from 1 to count
    for i in range(1, count + 1):
        # Check if we are at the last digit position
        if i == count:
            # If the last digit position is odd, calculate the contribution to ans
            if i % 2 == 1:
                ans += (N - 10**(i - 1) + 1)
        else:
            # Handle contributions for positions other than the last
            if i == 1:
                # For the first digit position, there are 9 possibilities (1-9)
                ans += 9
            elif i % 2 == 1:
                # For odd digit positions, calculate the range of numbers
                ans += (10**i - 10**(i - 1))
    
    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()

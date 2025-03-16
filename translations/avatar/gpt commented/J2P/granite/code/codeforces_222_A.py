
import sys

def main():
    # Read the number of elements (n) and the threshold (k) from input
    n, k = map(int, sys.stdin.readline().split())
    
    # Initialize variables to keep track of the last number and the count of consecutive occurrences
    last_num = None
    count = 0
    
    # Loop through each element to count consecutive occurrences
    for i in range(n):
        # Read the next integer from input
        num = int(sys.stdin.readline())
        
        # Check if the current number is the same as the last one
        if num == last_num:
            count += 1  # Increment the count of consecutive occurrences
        else:
            count = 1  # Reset the count if the number changes
        
        # Update the last number to the current one
        last_num = num
    
    # Check if the count of consecutive numbers plus k exceeds n
    if count + k > n:
        # If true, print the number of elements that are not part of the consecutive sequence
        print(n - count)
    else:
        # Otherwise, print -1 indicating the condition is not met
        print(-1)

if __name__ == "__main__":
    main()


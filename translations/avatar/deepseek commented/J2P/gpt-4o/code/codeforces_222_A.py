# Import the necessary module
import sys

def main():
    # Read the number of elements (n) and a threshold value (k)
    n, k = map(int, sys.stdin.readline().split())
    
    # Initialize variables to keep track of the last number and its consecutive occurrences
    l = 0
    c = 1
    
    # Loop to read n numbers and count consecutive occurrences
    for i in range(n):
        a = int(sys.stdin.readline().strip())
        if a == l:
            c += 1  # Increment count if the current number is the same as the last
        else:
            c = 1  # Reset count if the current number is different
        l = a  # Update the last number
    
    # Check if the number of consecutive occurrences plus the threshold value is greater than n
    if c + k > n:
        print(n - c)  # Print the number of elements to remove
    else:
        print(-1)  # Print -1 if it's not possible to satisfy the condition

if __name__ == "__main__":
    main()

# <END-OF-CODE>

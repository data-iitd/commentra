import sys

def main():
    # Read the number of elements (n) and the threshold (k)
    n, k = map(int, sys.stdin.readline().split())
    
    # Initialize variables to count consecutive occurrences
    l = 0
    c = 1
    
    # Loop through each element to count consecutive occurrences
    for _ in range(n):
        # Read the next integer from input
        a = int(sys.stdin.readline())
        
        # Check if the current number is the same as the last one
        if a == l:
            c += 1  # Increment the count of consecutive occurrences
        else:
            c = 1  # Reset the count if the number changes
        
        # Update the last number to the current one
        l = a
    
    # Check if the count of consecutive numbers plus k exceeds n
    if c + k > n:
        # If true, print the number of elements that are not part of the consecutive sequence
        print(n - c)
    else:
        # Otherwise, print -1 indicating the condition is not met
        print(-1)

if __name__ == "__main__":
    main()

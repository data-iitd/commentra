def main():
    # Read the number of elements (n) and a threshold value (k)
    n, k = map(int, input().split())
    
    # Initialize variables to keep track of the last number and its consecutive occurrences
    l, c = 0, 1
    
    # Loop to read n numbers and count consecutive occurrences
    for _ in range(n):
        a = int(input())
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

# Call the main function
main()

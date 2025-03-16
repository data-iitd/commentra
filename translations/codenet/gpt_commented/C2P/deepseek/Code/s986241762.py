def main():
    # Read the number of elements from user input
    n = int(input())
    
    # Read n elements into the array from user input
    a = list(map(int, input().split()))
    
    # Initialize the sum of differences
    total_sum = 0
    
    # Iterate through the array to calculate the sum of differences
    for i in range(1, n):
        # Check if the previous element is greater than the current element
        if a[i - 1] > a[i]:
            # Calculate the difference and add it to the sum
            total_sum += a[i - 1] - a[i]
            # Update the current element to be equal to the previous element
            a[i] = a[i - 1]
    
    # Print the total sum of differences
    print(total_sum)

# Call the main function
main()

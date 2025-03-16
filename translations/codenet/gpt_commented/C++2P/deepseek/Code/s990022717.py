def main():
    # Read input values: n (total items), k (threshold), x (cost for first k items), y (cost for items beyond k)
    n, k, x, y = map(int, input().split())
    
    # Initialize sum to accumulate total cost
    sum = 0

    # Loop through each item from 1 to n
    for i in range(1, n + 1):
        # If the current item index exceeds k, add cost y; otherwise, add cost x
        if i > k: 
            sum += y  # Cost for items beyond the threshold
        else: 
            sum += x  # Cost for items within the threshold

    # Output the total calculated cost
    print(sum)

# Call the main function
main()

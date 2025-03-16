def B():
    x = int(input())  # Read input value x from the user
    sum = 100  # Initialize sum to 100
    i = 0  # Declare a counter variable

    # Loop until sum is less than x
    while sum < x:
        # Increase sum by 1% of its current value
        sum += sum // 100
        i += 1  # Increment the counter

    # Output the number of iterations needed to exceed or meet x
    print(i)

# Call function B to execute its logic
B()

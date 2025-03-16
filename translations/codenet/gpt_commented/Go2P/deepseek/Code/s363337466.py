def walk_on_multiplication_table(num):
    # Initialize a variable to store the largest divisor found
    div = 0

    # Iterate from the largest integer less than or equal to the square root of num down to 2
    for i in range(int(math.sqrt(num)), 1, -1):
        # Check if i is a divisor of num
        if num % i == 0:
            div = i  # Store the divisor
            break  # Exit the loop once the largest divisor is found

    # If no divisor was found, return num - 1 (indicating num is prime)
    if div == 0:
        return num - 1

    # Calculate and return the result based on the found divisor
    return div + num // div - 2


# Read an integer from standard input
num = int(input())

# Call the walk_on_multiplication_table function and print the result
print(walk_on_multiplication_table(num))

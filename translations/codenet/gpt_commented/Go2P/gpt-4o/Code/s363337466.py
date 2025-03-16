import math

# walk_on_multiplication_table calculates a specific value based on the input number.
# It finds the largest divisor of the number that is less than the square root of the number.
def walk_on_multiplication_table(num):
    # Initialize a variable to store the largest divisor found
    div = 0

    # Iterate from the largest integer less than or equal to the square root of num down to 2
    for i in range(int(math.sqrt(num)), 1, -1):
        # Check if i is a divisor of num
        if num % i == 0:
            div = i  # Store the divisor
            break    # Exit the loop once the largest divisor is found

    # If no divisor was found, return num - 1 (indicating num is prime)
    if div == 0:
        return num - 1

    # Calculate and return the result based on the found divisor
    return div + num // div - 2

if __name__ == "__main__":
    # Declare a variable to hold user input
    a = int(input())

    # Call the walk_on_multiplication_table function and print the result
    print(walk_on_multiplication_table(a))

# <END-OF-CODE>

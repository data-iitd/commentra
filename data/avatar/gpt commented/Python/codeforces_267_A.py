def substract(a, b):
    # Check if 'a' is greater than 'b'
    if a > b:
        total = 0  # Initialize total to accumulate results
        # Loop until either 'a' or 'b' becomes zero
        while a > 0 and b > 0:
            # Add the integer division of 'a' by 'b' to total
            total += int(a / b)
            # Update 'a' to the remainder of 'a' divided by 'b'
            a = a % b
            # If 'a' is still greater than zero, calculate further
            if a > 0:
                # Add the integer division of 'b' by 'a' to total
                total += int(b / a)
                # Update 'b' to the remainder of 'b' divided by 'a'
                b = b % a
        return total  # Return the accumulated total

    # Check if 'a' is less than 'b'
    if a < b:
        total = 0  # Initialize total to accumulate results
        # Loop until either 'a' or 'b' becomes zero
        while a > 0 and b > 0:
            # Add the integer division of 'b' by 'a' to total
            total += int(b / a)
            # Update 'b' to the remainder of 'b' divided by 'a'
            b = b % a
            # If 'b' is still greater than zero, calculate further
            if b > 0:
                # Add the integer division of 'a' by 'b' to total
                total += int(a / b)
                # Update 'a' to the remainder of 'a' divided by 'b'
                a = a % b
        return total  # Return the accumulated total

    # If 'a' is equal to 'b', return 1
    if a == b:
        return 1

# Read an integer input 'n' which represents the number of pairs
n = int(input())
lst = []  # Initialize an empty list to store results

# Loop to read 'n' pairs of integers
for i in range(0, n):
    a, b = map(int, input().split())  # Read a pair of integers
    lst.append(substract(a, b))  # Call the substract function and store the result

# Loop to print each result stored in the list
for i in lst:
    print(i)

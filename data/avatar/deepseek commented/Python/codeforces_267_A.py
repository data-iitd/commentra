def substract(a, b):
    # Check if a is greater than b
    if a > b:
        total = 0  # Initialize the total count of subtractions
        # Loop to subtract b from a until one of them becomes zero
        while a > 0 and b > 0:
            total += int(a / b)  # Count how many times b can be subtracted from a
            a = a % b  # Update a to the remainder of a divided by b
            if a > 0:
                total += int(b / a)  # Count how many times a can be subtracted from b
                b = b % a  # Update b to the remainder of b divided by a
        return total  # Return the total count of subtractions
    
    # If a is less than b, perform similar operations but subtract a from b
    if a < b:
        total = 0  # Initialize the total count of subtractions
        while a > 0 and b > 0:
            total += int(b / a)  # Count how many times a can be subtracted from b
            b = b % a  # Update b to the remainder of b divided by a
            if b > 0:
                total += int(a / b)  # Count how many times b can be subtracted from a
                a = a % b  # Update a to the remainder of a divided by b
        return total  # Return the total count of subtractions
    
    # If a and b are equal, return 1
    if a == b:
        return 1

# Read the number of pairs of integers
n = int(input())
lst = []  # Initialize a list to store the results

# Read n pairs of integers and compute the result using the substract function
for i in range(0, n):
    a, b = map(int, input().split())
    lst.append(substract(a, b))

# Print each element in the list
for i in lst:
    print(i)

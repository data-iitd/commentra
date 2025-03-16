# Initialize an empty list to store the results
li = []
# Initialize an index variable
ind = 0

# Loop through numbers from 1 to 370
for i in range(1, 371):
    # Initialize a temporary list to hold digits
    temp = []
    # Assign the current number to p and q for processing
    p, q = i, i
    # Initialize a count variable to track the number of digits
    count = 0
    
    # Count the number of digits in the current number i
    while p != 0:
        p //= 10  # Remove the last digit
        count += 1  # Increment the digit count

    # If the number has 1 digit, add it directly to the list
    if count == 1:
        li.append(i)
    
    # If the number has 2 digits
    if count == 2:
        temp = []  # Reset the temporary list
        # Extract digits of the number q
        while q != 0:
            x = q % 10  # Get the last digit
            q //= 10  # Remove the last digit
            temp.append(x)  # Append the digit to the temporary list
        # Add the digits in reverse order to the main list
        li = li + temp[::-1]
    
    # If the number has 3 digits
    if count == 3:
        temp = []  # Reset the temporary list
        # Extract digits of the number q
        while q != 0:
            x = q % 10  # Get the last digit
            q //= 10  # Remove the last digit
            temp.append(x)  # Append the digit to the temporary list
        # Add the digits in reverse order to the main list
        li = li + temp[::-1]

# Remove the last two elements from the list (not specified why)
li.pop()
li.pop()

# Take user input for the index
n = int(input(''))
# Print the n-th element from the list (1-based index)
print(li[n - 1])

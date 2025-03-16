
# Create a list to store the digits of the number
list = []

# Read the number from the input
x = int(input())

# Loop through each digit of the number from right to left
while x > 0:
    # Get the last digit of the number
    r = x % 10
    
    # Check if the digit is greater than 4 and if 9 - digit is less than digit
    if 9 - r < r:
        # If it's the last digit and 9 - r is 0, add the digit as is
        if x // 10 == 0 and 9 - r == 0:
            list.append(r)
        else:
            # Otherwise, add 9 - digit to the list
            list.append(9 - r)
    else:
        # Otherwise, add the digit to the list
        list.append(r)
    
    # Remove the last digit from the number
    x = x // 10

# Initialize variables to construct the new number
pow = 0
newNumber = 0

# Loop through the list of digits to construct the new number
for i in range(len(list)):
    # Add the digit to the new number at the appropriate place value
    newNumber = newNumber + list[i] * (10 ** pow)
    pow += 1

# Print the new number
print(newNumber)


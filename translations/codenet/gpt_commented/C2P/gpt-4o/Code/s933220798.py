# Declare variables to store input value and average
ave = 0

# Loop to read 5 input values
for i in range(5):
    # Read a double value from user input
    a = float(input())
    
    # Check if the input value is less than or equal to 40
    if a <= 40:
        # If so, add 40 to the average instead of the input value
        ave += 40
    else:
        # Otherwise, add the input value to the average
        ave += a

# Calculate the average by dividing the total by the number of inputs (5)
ave /= 5.0

# Print the calculated average, formatted as an integer
print(int(ave))

# <END-OF-CODE>

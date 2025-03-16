
# Import the required packages
import sys

# Initialize a new list dn to store the values of the second line of the input
dn = []

# Iterate through each line of the input
for line in sys.stdin:
    # Split the line into a list of strings using the split function
    dd = line.split()

    # Iterate through each string d in the list dd
    for d in dd:
        # Convert the string d to an integer using the int function
        dn.append(int(d))

# Initialize a variable sum to 0
sum = 0

# Iterate through each index i in the list dn
for i in range(len(dn)):
    # Iterate through each index j greater than i in the list dn
    for j in range(i+1, len(dn)):
        # Add the product of dn[i] and dn[j] to the sum variable
        sum += dn[i] * dn[j]

# Print the value of sum variable to the standard output using print function
print(sum)

# End of code 
# Read input number as a string
N = input()

# Initialize a variable to hold the sum of the digits
S = 0

# Calculate the sum of the digits in the input string
for digit in N:
    S += int(digit)  # Convert character to integer and add to sum

# Check if the original number is divisible by the sum of its digits
if int(N) % S == 0:
    print("Yes")  # Output "Yes" if divisible
else:
    print("No")   # Output "No" if not divisible

# End of the program
# <END-OF-CODE>

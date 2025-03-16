
# Read the input string from the user
str = input()

# Initialize a variable to hold the sum of digits
sum = 0

# Iterate through each character in the string
for x in str:
    # Convert character to integer and add to sum
    sum += int(x)

# Check if the sum of digits is divisible by 9
if sum % 9 == 0:
    # If divisible, print "Yes"
    print("Yes")
else:
    # If not divisible, print "No"
    print("No")


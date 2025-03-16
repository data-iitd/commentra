# Declare an array to hold 10 integers
v = []

# Initialize a variable to hold the sum of the integers
sum = 0

# Prompt the user to enter 10 integers and store them in the array
for i in range(10):
    num = int(input())
    v.append(num)

# Calculate the sum of the integers stored in the array
for i in range(10):
    sum += v[i]

# Output the calculated sum to the console
print(sum)

# Return 0 to indicate successful completion of the program
# (Not needed in Python, as the program ends naturally)
# <END-OF-CODE>

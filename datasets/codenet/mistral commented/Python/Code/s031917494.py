
# Take an integer input from the user
user_input = int(input())

# Calculate the absolute value of the difference between the input and 25
difference = abs(user_input - 25)

# Concatenate the string 'Christmas' with the string ' Eve' repeated the number of times equal to the absolute value of the difference
message = 'Christmas'
for _ in range(difference):
    message += ' Eve'

# Print the result
print(message)
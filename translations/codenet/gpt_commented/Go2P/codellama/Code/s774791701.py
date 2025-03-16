
# Declare a variable to hold the input string
s = input()

# Initialize the base price
price = 700

# Iterate over each character in the input string
for c in s:
    # Check if the character is 'o'
    if c == 'o':
        # If it is 'o', increase the price by 100
        price += 100

# Print the final price after processing the input string
print(price)


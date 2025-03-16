import math  # Import the math module for mathematical functions

menu = []  # Initialize an empty list to store menu items

# Loop to collect 5 menu items from user input
for _ in range(5):
    m = input()  # Take input from the user
    e = int(m[-1])  # Extract the last character of the input and convert it to an integer
    if e == 0:  # If the last digit is 0
        e = 10  # Change it to 10 (to avoid zero as a value)
    menu.append([int(m), e])  # Append a list containing the integer value of m and e to the menu

# Sort the menu based on the second element (e) of each sublist
menu.sort(key=lambda x: x[1])

ans = 0  # Initialize a variable to accumulate the total cost

# Loop through the sorted menu starting from the second item
for m in menu[1:]:
    # Calculate the cost for each item, rounding up to the nearest multiple of 10
    ans += math.ceil(m[0] / 10) * 10

# Print the total cost, including the first item's original value
print(ans + menu[0][0])  # Add the first item's value to the accumulated cost and print the result

# Import the math module for calculating ceil values
import math

# Initialize an empty list called menu
menu = []

# Use a for loop to iterate 5 times
for _ in range(5):
    # Take user input and assign it to the variable m
    m = input()
    
    # Extract the last character of the string m to determine the exponent e
    e = int(m[-1])
    
    # If e is 0, set it to 10
    if e == 0:
        e = 10
    
    # Append a list containing the integer value of m and the exponent e to the menu list
    menu.append([int(m), e])

# Sort the menu list based on the exponent value using the sort() method with a lambda function as the key
menu.sort(key=lambda x: x[1])

# Initialize a variable called ans to 0
ans = 0

# Use a for loop to iterate through the menu list starting from the second element (index 1)
for m in menu[1:]:
    # Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up using the ceil() function from the math module
    num_full_10s = math.ceil(m[0] / 10)
    
    # Multiply this value by 10 and add it to the ans variable
    ans += num_full_10s * 10

# Finally, print the sum of the first element in the menu list (which is the initial number) and the value of ans
print(menu[0][0] + ans)

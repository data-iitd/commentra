
x, y = list(map(int, input().split())) # Take two integers as input from the user and store them in x and y respectively
a = 0 # Initialize the variable a to 0

while x >= 0 and y >= 22 or x >= 1 and y >= 12 or x >= 2 and y >= 2: # Run the while loop as long as certain conditions are met
    if a: # If a is true
        if y >= 22: # Check if y is greater than or equal to 22
            y -= 22 # If so, reduce y by 22
        elif x >= 1 and y >= 12: # Else if x is greater than or equal to 1 and y is greater than or equal to 12
            x -= 1 # Reduce x by 1
            y -= 12 # Reduce y by 12
        else: # Else, x is greater than or equal to 2 and y is greater than or equal to 2
            x -= 2 # Reduce x by 2
            y -= 2 # Reduce y by 2
    else: # If a is false
        if x >= 2 and y >= 2: # Check if x is greater than or equal to 2 and y is greater than or equal to 2
            x -= 2 # Reduce x by 2
            y -= 2 # Reduce y by 2
        elif x >= 1 and y >= 12: # Else if x is greater than or equal to 1 and y is greater than or equal to 12
            x -= 1 # Reduce x by 1
            y -= 12 # Reduce y by 12
        else: # Else, y is greater than or equal to 22
            y -= 22 # Reduce y by 22
    a = 1 - a # Toggle the value of a

print([ 'Ciel', 'Hanako' ][1 - a]) # Print the name of a character based on the value of a
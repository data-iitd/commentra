s = int(input())  # Read an integer value from the standard input and assign it to variable s
a = set()  # Create an empty set named a
a.add(s)  # Add the value of s to the set a
d = 2  # Initialize d with the value 2

while True:  # Start an infinite loop
    if s % 2 == 0:  # Check if s is even
        x = s // 2  # Calculate the half of s and assign it to x
        if x in a:  # Check if x is already in the set a
            print(d)  # If yes, print the value of d and exit the program
            break
        a.add(x)  # If not, add x to the set a
    else:  # If s is odd
        x = 3 * s + 1  # Calculate 3s + 1 and assign it to x
        if x in a:  # Check if x is already in the set a
            print(d)  # If yes, print the value of d and exit the program
            break
        a.add(x)  # If not, add x to the set a
    s = x  # Update the value of s with the new value of x
    d += 1  # Increment the value of d for each iteration

# The loop will terminate when a duplicate is found, so no need for an additional print statement here.

# <END-OF-CODE>

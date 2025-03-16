
s = int(input()) # Read the initial number from the user
a = {s} # Create a set with the initial number
d = 2

while True: # Start an infinite loop
    if s % 2 == 0: # Check if the current number is even
        x = s // 2 # Halve the number
        if x in a: # Check if the halved number has been encountered before
            print(d) # Output the current step count and terminate the program
            break
    else: # The current number is odd
        x = 3 * s + 1 # Triple the number and add one
        if x in a: # Check if the new number has been encountered before
            print(d) # Output the current step count and terminate the program
            break
    a.add(x) # Insert the new number into the set
    s = x # Update the current number to the new number
    d += 1 # Increment the step count

print(d) # Output the step count (this line will never be reached)


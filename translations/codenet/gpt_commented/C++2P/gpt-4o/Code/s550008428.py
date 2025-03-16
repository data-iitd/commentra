s = int(input())  # Read an integer input from the user
a = set()  # Create a set to store unique values of s
a.add(s)  # Insert the initial value of s into the set
d = 2  # Initialize depth

# Start an infinite loop to process the value of s
while True:
    # Check if s is even
    if s % 2 == 0:
        x = s // 2  # If even, calculate the next value as half of s
    else:
        # If s is odd, calculate the next value using the formula 3*s + 1
        x = 3 * s + 1

    # Check if the new value x already exists in the set
    if x in a:
        print(d)  # If it exists, print the depth and exit
        break  # Exit the loop

    a.add(x)  # Insert the new value x into the set
    s = x  # Update s to the new value x for the next iteration
    d += 1  # Increment the depth counter

# This line will never be reached due to the infinite loop
# print(d)  # Print the depth (not reached)

# Return 0 to indicate successful completion of the program
# (not necessary in Python)
# <END-OF-CODE>

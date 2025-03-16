# Python 3.6.1
# <NAME>
# 02/02/2017

# Initialize variables: s for input, x for calculations, d for depth
s = int(input())
x = 0
d = 2

# Create a set to store unique values of s
a = set()
a.add(s)

# Start an infinite loop to process the value of s
while True:
    # Check if s is even
    if s % 2 == 0:
        x = s // 2 # If even, calculate the next value as half of s
        # Check if the new value x already exists in the set
        if x in a:
            print(d) # If it exists, print the depth and exit
            break
        a.add(x) # Insert the new value x into the set
    else:
        # If s is odd, calculate the next value using the formula 3*s + 1
        x = 3 * s + 1
        # Check if the new value x already exists in the set
        if x in a:
            print(d) # If it exists, print the depth and exit
            break
        a.add(x) # Insert the new value x into the set
    s = x # Update s to the new value x for the next iteration
    d += 1 # Increment the depth counter

# This line will never be reached due to the infinite loop
print(d) # Print the depth (not reached)

# 
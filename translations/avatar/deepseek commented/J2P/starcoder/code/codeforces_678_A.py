import sys; # Step 1: Import the sys module.

n = int(input()); # Step 2: Read an integer value from the user and store it in the variable n.
k = int(input()); # Step 3: Read another integer value from the user and store it in the variable k.

n += 1; # Step 4: Increment the value of n by 1.

z = 0; # Step 5: Initialize a variable z to 0.

if n % k!= 0: # Step 6: Check if n is not divisible by k.
    z = k - n % k; # If true, calculate the difference between k and the remainder of n divided by k, and store it in z.

print(n + z); # Step 7: Print the new value of n plus the value of z.

# 
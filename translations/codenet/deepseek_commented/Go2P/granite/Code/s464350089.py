

import sys

# Read the initial height `h` and the number of attacks `n`
h = int(input())
n = int(input())

# Initialize a variable to keep track of the total damage dealt
a = 0

# Read each attack's damage and accumulate the total damage
for i in range(n):
    a += int(input())

# Check if the total damage is greater than or equal to the initial height
if h > a:
    print("No")
else:
    print("Yes")


import sys

# Read the initial height `h` and the number of attacks `n`
h = int(sys.stdin.readline().strip())
n = int(sys.stdin.readline().strip())

# Initialize a variable to keep track of the total damage dealt
a = 0

# Read each attack's damage and accumulate the total damage
for _ in range(n):
    a += int(sys.stdin.readline().strip())

# Check if the total damage is greater than or equal to the initial height
if h > a:
    print("No")
else:
    print("Yes")

# <END-OF-CODE>


# Declare variables for radius (r), distance (D), and initial value (x)
r = 0
D = 0
x = 0

# Read input values for r, D, and x from the user
r = int(input("Enter the radius: "))
D = int(input("Enter the distance: "))
x = int(input("Enter the initial value: "))

# Loop to perform calculations and print results for 10 iterations
for i in range(1, 11):
    # Calculate and print the result of the formula r*x - D
    print(r*x - D)
    
    # Update x for the next iteration using the formula r*x - D
    x = r*x - D


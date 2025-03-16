
# <START-OF-CODE>

# Create a Scanner object to read input from the user
sc = Scanner ( )

# Read two integers from the input
a = int ( sc.next ( ) )
b = int ( sc.next ( ) )

# Initialize sum to 0, this will store the sum of the two numbers
sum = 0

# Loop runs twice, each time adding the larger of the two numbers to sum
# and decrementing that number by 1
for i in range ( 2 ) :
    if a >= b :
        sum += a
        a -= 1
    else :
        sum += b
        b -= 1

# Print the final sum to the console
print ( sum )

# 
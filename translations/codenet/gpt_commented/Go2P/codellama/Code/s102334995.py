
# Importing the fmt package for formatted I/O
import fmt

# Declare two integer variables to hold user input
a, b = 0, 0

# Read two integers from standard input
fmt.Scan(&a, &b)

# Calculate and print the product of a and b, 
# and also print the perimeter of a rectangle with sides a and b
fmt.Println(a*b, (a+b)*2)


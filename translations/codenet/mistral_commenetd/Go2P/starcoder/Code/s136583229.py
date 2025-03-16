
# Importing the 'fmt' package for formatted I/O
import fmt

# Declaring a variable 'data' of type 'int' to read user input
data = 0

# Reading user input and storing it in the 'data' variable
fmt.Scan(data)

# Declaring a variable'result' of type 'int' to store the result
result = 0

# Assigning the value of 'data' cubed to the'result' variable
result = data * data * data

# Printing the result using the 'Printf' function from 'fmt' package
fmt.Printf("%d\n", result) # Printing the result with format specifier '%d' and newline character '\n'

# 
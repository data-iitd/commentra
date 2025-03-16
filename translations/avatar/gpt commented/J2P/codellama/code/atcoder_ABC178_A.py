
# Importing utility classes for input and output
import java.util.*;

# Importing classes for input and output operations
import java.io.*;

# Creating a Scanner object to read input from the console
scan = java.util.Scanner(java.lang.System.in)

# Reading an integer input from the user
x = int(scan.next())

# Using a ternary operator to determine the boolean value based on the input
bool = x == 1

# Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
result = not bool

# Creating a PrintWriter object to output the result to the console
out = java.io.PrintWriter(java.lang.System.out)

# Printing the result to the console
out.println(result)

# Flushing the output stream to ensure all data is written out
out.flush()

# End of code

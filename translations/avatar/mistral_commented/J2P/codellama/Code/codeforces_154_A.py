
import sys

# Reading the first line of input as a character array and storing it in the 'arr' variable
arr = list ( sys.stdin.readline ( ) .strip ( ) )

# Declaring and initializing the length of the character array 'arr' in the variable 'N'
N = len ( arr )

# Creating an empty HashSet object to store unique strings
set = set ( )

# Reading the second line of input as an integer and storing it in the variable 'K'
K = int ( sys.stdin.readline ( ) .strip ( ) )

# Declaring and initializing an integer variable 'res' to store the result
res = 0

for k in range ( K ) :
    # Starting a for loop that iterates 'K' times

    # Reading a string as input and storing it in the 'input' variable
    input = sys.stdin.readline ( ) .strip ( )

    # Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the character array 'arr'
    a = 0
    b = 0

    for i in range ( N ) :
        # Starting a nested for loop that iterates through each index of the character array 'arr'

        if arr [ i ] == input [ 0 ] :
            # Incrementing the 'a' variable if the character at the current index matches the first character of the input string
            a += 1

        elif arr [ i ] == input [ 1 ] :
            # Incrementing the 'b' variable if the character at the current index matches the second character of the input string
            b += 1

        else :
            # Adding the minimum of 'a' and 'b' to the 'res' variable if the current character is different from both characters in the input string
            res += min ( a , b )
            # Resetting the 'a' and 'b' variables to zero
            a = b = 0

    # Adding the minimum of 'a' and 'b' to the 'res' variable after the end of the outer for loop
    res += min ( a , b )

# Printing the final result to the standard output stream
print ( res )


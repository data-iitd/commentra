

K = int ( input ( ) ) # Read the first integer `K` from the input

S = input ( ) # Read the next token from the input, which is assumed to be a string `S`

if len ( S ) <= K : # Check if the length of the string `S` is less than or equal to the integer `K`

    print ( S ) # If the condition is true, print the string `S` to the standard output

else : # If the condition is false

    print ( S [ : K ] + "..." ) # Print the first `K` characters of the string `S` followed by "..." to the standard output


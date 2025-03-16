# Take the input string 's' and an integer 'n' from the user
s = input ()
n = int ( input () )

# Initialize the answer variable 'ans' to 0
ans = 0

# Iterate through the given range 'n' times
for i in range ( n ) :

    # Take the next string 'x' as input
    x = input ()

    # Initialize variables 'a' and 'b' to 0
    a, b = 0, 0

    # Iterate through each character 'j' in the string 's'
    for j in s :

        # If the character 'j' matches the first character of the string 'x', increment 'a'
        if j == x [ 0 ] :
            a += 1

        # If the character 'j' matches the second character of the string 'x', increment 'b'
        elif j == x [ 1 ] :
            b += 1

        # If the current character 'j' does not match any character in the string 'x',
        # add the minimum of 'a' and 'b' to the answer variable 'ans' and reset 'a' and 'b' to 0
        else :
            ans += min ( a, b )
            a, b = 0, 0

    # Add the minimum of 'a' and 'b' to the answer variable 'ans' after the inner loop completes
    ans += min ( a, b )

# Print the final answer
print ( ans )

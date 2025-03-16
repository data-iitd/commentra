# Take an input string `ip` from the user
ip = input ()

# Initialize an empty string `st`
st = ""

# Check if the length of the input string is not equal to 1
if len ( ip ) != 1 :

    # Check if the first character of the input string is equal to "9"
    if ip [ 0 ] == "9" :
        # Assign "9" to the variable `st`
        st = "9"
        # Slice the input string to exclude the first character
        ip = ip [ 1 : ]

    # Iterate through each character in the input string `ip`
    for i in ip :

        # If the character is an integer greater than 4
        if int ( i ) > 4 :
            # Calculate the difference between 9 and the integer
            n = 9 - int ( i )
            # Add the difference to the string `st`
            st += str ( n )

        # If the character is an integer less than or equal to 4
        else :
            # Add the character directly to the string `st`
            st += i

# If the length of the input string is equal to 1
else :

    # Assign the input string to the variable `st`
    st = ip

# Print the integer value of the string `st` to the console
print ( int ( st ) )

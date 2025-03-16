
# Function to find the difference between two numbers using Euclidean algorithm
def substract ( a , b ) :
    # Check if 'a' is greater than 'b'
    if a > b :
        # Initialize total to 0
        total = 0
        # Continue the loop while both 'a' and 'b' are greater than 0
        while a > 0 and b > 0 :
            # Add the quotient of 'a' and 'b' to the total
            total += int ( a / b )
            # Update 'a' and 'b' for the next iteration
            a = a % b
            if a > 0 :
                # Add the quotient of 'b' and 'a' to the total
                total += int ( b / a )
                # Update 'a' and 'b' for the next iteration
                b = b % a
        # Return the total difference
        return total
    # Check if 'a' is smaller than 'b'
    elif a < b :
        # Initialize total to 0
        total = 0
        # Continue the loop while both 'a' and 'b' are greater than 0
        while a > 0 and b > 0 :
            # Add the quotient of 'b' and 'a' to the total
            total += int ( b / a )
            # Update 'a' and 'b' for the next iteration
            b = b % a
            if b > 0 :
                # Add the quotient of 'a' and 'b' to the total
                total += int ( a / b )
                # Update 'a' and 'b' for the next iteration
                a = a % b
        # Return the total difference
        return total
    # Check if 'a' is equal to 'b'
    else :
        # Return 1 if 'a' is equal to 'b'
        return 1
# Take the number of test cases as input
n = int ( input ( ) )
# Initialize an empty list to store the differences
lst = [ ]
# Iterate through each test case
for i in range ( 0 , n ) :
    # Take two numbers as input
    a , b = map ( int , input ( ).split ( ) )
    # Append the difference between 'a' and 'b' to the list
    lst.append ( substract ( a , b ) )
# Print each difference in the list
for i in lst :
    # Print the difference
    print ( i )
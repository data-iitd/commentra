
li = [ ]
ind = 0
# Initialize an empty list and a variable to keep track of the index

for i in range ( 1 , 371 ) :
    temp = [ ]
    p , q = i , i
    count = 0
    # Initialize an empty temporary list and set p and q to the current value of i
    # Initialize a counter to count the number of digits in i

    while p != 0 :
        p //= 10
        count += 1
    # Count the number of digits in i by repeatedly dividing p by 10

    if count == 1 :
        li.append ( i )
    # If i has 1 digit, append it to the list li

    if count == 2 :
        temp = [ ]
        while q != 0 :
            x = q % 10
            q //= 10
            temp.append ( x )
        li = li + temp [ : : -1 ]
    # If i has 2 digits, extract the digits and reverse them, then append to li

    if count == 3 :
        temp = [ ]
        while q != 0 :
            x = q % 10
            q //= 10
            temp.append ( x )
        li = li + temp [ : : -1 ]
    # If i has 3 digits, extract the digits and reverse them, then append to li

li.pop ( )
li.pop ( )
# Remove the last two elements from li

n = int ( input ( '' ) )
# Take an integer input from the user

print ( li [ n - 1 ] )
# Print the nth element of li based on the user's input
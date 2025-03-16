
x , y = list ( map ( int , input ( ).split ( ) ) )  # Taking two integer inputs, x and y
a = 0  # Initializing a variable a to 0

# The while loop checks a complex condition involving x and y
while x >= 0 and y >= 22 or x >= 1 and y >= 12 or x >= 2 and y >= 2 :
    if a :  # If a is 1 (True), execute the following block
        if y >= 22 :  # If y is greater than or equal to 22, subtract 22 from y
            y -= 22
        elif x >= 1 and y >= 12 :  # If x is greater than or equal to 1 and y is greater than or equal to 12, subtract 1 from x and 12 from y
            x -= 1
            y -= 12
        else :  # Otherwise, subtract 2 from both x and y
            x -= 2
            y -= 2
    else :  # If a is 0 (False), execute the following block
        if x >= 2 and y >= 2 :  # If x is greater than or equal to 2 and y is greater than or equal to 2, subtract 2 from both x and y
            x -= 2
            y -= 2
        elif x >= 1 and y >= 12 :  # If x is greater than or equal to 1 and y is greater than or equal to 12, subtract 1 from x and 12 from y
            x -= 1
            y -= 12
        else :  # Otherwise, subtract 22 from y
            y -= 22
    a = 1 - a  # Toggle the value of a between 0 and 1

print ( [ 'Ciel' , 'Hanako' ] [ 1 - a ] )  # Print the name of the winner based on the value of a


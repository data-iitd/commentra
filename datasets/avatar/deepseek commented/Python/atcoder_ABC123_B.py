
import math
menu = [ ]
for _ in range ( 5 ) :
    m = input ( ) # Taking input from the user
    e = int ( m [ - 1 ] ) # Extracting the last digit and converting it to an integer
    if e == 0 :
        e = 10 # If the last digit is 0, change it to 10
    menu.append ( [ int ( m ) , e ] ) # Appending the input value and the processed last digit as a list to the menu list
menu.sort ( key = lambda x : x [ 1 ] ) # Sorting the menu list based on the last digit
ans = 0
for m in menu [ 1 : ] :
    ans += math.ceil ( m [ 0 ] / 10 ) * 10 # Calculating the sum of the ceiling of each element divided by 10, multiplied by 10
print ( ans + menu [ 0 ] [ 0 ] ) # Printing the sum of the first element and the calculated ans


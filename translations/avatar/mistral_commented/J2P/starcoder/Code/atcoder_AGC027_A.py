
import java.util.* ; // Importing the utility class Scanner from the java.util package

def main ( ):
    sc = Scanner ( ) ; // Creating a new Scanner object to read input from the standard input

    N = sc.nextInt ( ) ; // Reading the number of elements in the list from the standard input
    x = sc.nextInt ( ) ; // Reading the target value from the standard input

    sweet = [ ] ; // Creating an empty list to store the elements

    for i in range ( N ): # A for loop to read and add N elements to the list
        a = sc.nextInt ( ) ; # Reading an element from the standard input
        sweet.append ( a ) ; # Adding the element to the list

    sweet.sort ( ) ; # Sorting the list in ascending order using the sort() method

    num = 0 ; # Initializing a variable named num to keep track of the number of elements that can be subtracted from x

    for i in range ( N ): # A for loop to find the number of elements that can be subtracted from x
        if ( x - sweet [ num ] >= 0 ): # Checking if x is greater than or equal to the current element in the list
            x = x - sweet [ num ] ; # Subtracting the current element from x
            num += 1 ; # Incrementing the num variable
        else: # If x is less than the current element in the list
            break ; # Exiting the for loop

    if ( ( num == N ) and ( x > 0 ) ): # Checking if all the elements in the list have been subtracted from x and x is still greater than 0
        num -= 1 ; # Decrementing the num variable by 1 as the last element that was subtracted from x is not included in the count

    print ( num ) ; # Printing the number of elements that can be subtracted from x


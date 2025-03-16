
import sys ; // Importing the sys module

def main ( ):
    sc = sys.stdin ; // Creating a new Scanner object to read input
    a = int ( sc.readline ( ) ) ; // Reading the first integer input and assigning it to variable a
    b = int ( sc.readline ( ) ) ; // Reading the second integer input and assigning it to variable b

    count = 0 ; // Initializing the count variable to 0

    while ( True ) :
        if ( a > 0 and b > 0 ) :
            count += 1 ; // Incrementing the count variable if both conditions are true
            a -= 1 ; // Decrementing the value of variable a by 1
            b -= 1 ; // Decrementing the value of variable b by 1
        else :
            break ; // Exiting the loop

    ans = a // 2 + b // 2 ; // Calculating the answer by dividing each number by 2 and summing the results

    print ( count, " ", ans ) ; // Printing the count and answer to the console

main ( ) ; // Calling the main function


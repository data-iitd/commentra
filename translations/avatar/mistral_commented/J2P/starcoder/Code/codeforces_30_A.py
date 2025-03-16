
import sys ; // Importing the utility module

class Main:
    def __init__ ( self ):
        self.solve ( sys.stdin ) ; // Creating an instance of the Main class and calling the solve method with the standard input as an argument

    def solve ( self, sc ):
        A = int ( sc.readline ( ) ) ; // Reading the first integer value from the standard input
        B = int ( sc.readline ( ) ) ; // Reading the second integer value from the standard input
        n = int ( sc.readline ( ) ) ; // Reading the third integer value from the standard input

        if ( A == 0 ):
            if ( B == 0 ):
                print ( 1 ) ; # If both A and B are zero, print 1
            else:
                print ( "No solution" ) ; # If A is zero but B is not, print "No solution"
                return ; # Exit the method
        else:
            if ( B % A!= 0 ):
                print ( "No solution" ) ; # If B is not divisible by A, print "No solution"
                return ; # Exit the method
            else:
                B /= A ; # Dividing B by A
                neg = B < 0 ; # Checking if B is negative

                if ( neg and n % 2 == 0 ):
                    print ( "No solution" ) ; # If both conditions are true, print "No solution"
                    return ; # Exit the method
                else:
                    if ( neg ): B = - B ; # If B is negative, make it positive

                    for x in range ( 0, B + 1 ): # Iterating through all possible values of x from 0 to B
                        if ( x ** n == B ): # Checking if x raised to the power of n is equal to B
                            print ( neg and - x or x ) ; # Printing the value of x with its sign
                            return ; # Exit the method
                    print ( "No solution" ) ; # If no solution is found, print "No solution"


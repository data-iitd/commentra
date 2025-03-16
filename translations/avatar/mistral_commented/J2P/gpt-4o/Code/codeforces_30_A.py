import sys

class Main:  # Main class definition
    def solve(self, sc):  # solve method definition with Scanner as a parameter
        A = int(sc.readline().strip())  # Reading the first integer value from the standard input
        B = int(sc.readline().strip())  # Reading the second integer value from the standard input
        n = int(sc.readline().strip())  # Reading the third integer value from the standard input

        if A == 0:  # Checking if A is equal to zero
            if B == 0:  # Checking if B is also equal to zero
                print(1)  # If both A and B are zero, print 1
            else:
                print("No solution")  # If A is zero but B is not, print "No solution"
            return  # Exit the method

        if B % A != 0:  # Checking if B is not divisible by A
            print("No solution")  # If B is not divisible by A, print "No solution"
            return  # Exit the method

        B //= A  # Dividing B by A
        neg = B < 0  # Checking if B is negative

        if neg and n % 2 == 0:  # Checking if n is even and B is negative
            print("No solution")  # If both conditions are true, print "No solution"
            return  # Exit the method

        if neg: 
            B = -B  # If B is negative, make it positive

        for x in range(B + 1):  # Iterating through all possible values of x from 0 to B
            if x ** n == B:  # Checking if x raised to the power of n is equal to B
                print(-x if neg else x)  # Printing the value of x with its sign
                return  # Exit the method

        print("No solution")  # If no solution is found, print "No solution"

if __name__ == "__main__":  # Main entry point
    main = Main()  # Creating an instance of the Main class
    main.solve(sys.stdin)  # Calling the solve method with the standard input

# <END-OF-CODE>

import sys

# Main function to read input and print output
def main():
    # Read three integers from the user, representing the coefficients of the equation
    a = int(input())
    b = int(input())
    c = int(input())
    
    # Create an Equation object using the input coefficients
    toSolve = Equation(a, b, c)
    
    # Find any solution for the given equation
    solution = findAnySolution(toSolve)
    
    # Check the type of solution and print the appropriate message
    if solution == Solution.NO_SOLUTION:
        print("No solution exists.")
    elif solution == Solution.INFINITE_SOLUTIONS:
        print("Infinite solutions exist.")
    else:
        # Print the unique solution found
        print("One solution is: x = " + str(solution.getX()) + ", y = " + str(solution.getY()))

# Method to find any solution for the given equation
def findAnySolution(equation):
    # Check if the equation is of the form 0 = 0, which has infinite solutions
    if equation.a() == 0 and equation.b() == 0 and equation.c() == 0:
        return Solution.INFINITE_SOLUTIONS
    
    # Initialize a wrapper to hold GCD and a solution
    stub = GcdSolutionWrapper(0, Solution(0, 0))
    
    # Calculate the GCD of the coefficients and get a particular solution
    gcdSolution = gcd(equation.a(), equation.b(), stub)
    
    # Check if the equation has no solution based on the GCD
    if equation.c() % gcdSolution.getGcd() != 0:
        return Solution.NO_SOLUTION
    
    # Create a new solution object to return
    toReturn = Solution(0, 0)
    
    # Calculate the specific solution based on the GCD and the input constant
    xToSet = stub.getSolution().getX() * (equation.c() / stub.getGcd())
    yToSet = stub.getSolution().getY() * (equation.c() / stub.getGcd())
    
    # Set the calculated values in the solution object
    toReturn.setX(xToSet)
    toReturn.setY(yToSet)
    
    # Return the found solution
    return toReturn

# Recursive method to calculate the GCD of two integers and find a solution
def gcd(a, b, previous):
    # Base case: if b is 0, return the GCD and a solution
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))
    
    # Create a stub for the next recursive call
    stubWrapper = GcdSolutionWrapper(0, Solution(0, 0))
    
    # Recursive call to find the GCD
    next = gcd(b, a % b, stubWrapper)
    
    # Update the previous solution based on the results of the recursive call
    previous.getSolution().setX(next.getSolution().getY())
    previous.getSolution().setY(next.getSolution().getX() - (a / b) * (next.getSolution().getY()))
    previous.setGcd(next.getGcd())
    
    # Return the updated GCD and solution
    return GcdSolutionWrapper(next.getGcd(), previous.getSolution())

# Inner class representing a solution to the equation
class Solution:
    # Constants representing special cases of solutions
    NO_SOLUTION = Solution(sys.maxsize, sys.maxsize)
    INFINITE_SOLUTIONS = Solution(sys.minsize, sys.minsize)
    
    # Variables to hold the solution values
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Getter for x
    def getX(self):
        return self.x

    # Getter for y
    def getY(self):
        return self.y

    # Setter for x
    def setX(self, x):
        self.x = x

    # Setter for y
    def setY(self, y):
        self.y = y

    # Override equals method to compare solutions
    def __eq__(self, other):
        if other == self:
            return True
        if other == None or other.__class__ != self.__class__:
            return False
        that = other
        return self.x == that.x and self.y == that.y

    # Override hashCode method for proper hashing
    def __hash__(self):
        return hash((self.x, self.y))

    # Override toString method for easy representation
    def __str__(self):
        return "Solution[" \
            + "x=" + str(self.x) + ", " \
            + "y=" + str(self.y) + ']'

# Inner class representing the equation with coefficients
class Equation:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    # Getter for coefficient a
    def a(self):
        return self.a

    # Getter for coefficient b
    def b(self):
        return self.b

    # Getter for coefficient c
    def c(self):
        return self.c

# Wrapper class to hold GCD and a corresponding solution
class GcdSolutionWrapper:
    def __init__(self, gcd, solution):
        self.gcd = gcd
        self.solution = solution

    # Override equals method for comparison
    def __eq__(self, other):
        if other == self:
            return True
        if other == None or other.__class__ != self.__class__:
            return False
        that = other
        return self.gcd == that.gcd and self.solution == that.solution

    # Getter for GCD
    def getGcd(self):
        return self.gcd

    # Setter for GCD
    def setGcd(self, gcd):
        self.gcd = gcd

    # Getter for solution
    def getSolution(self):
        return self.solution

    # Setter for solution
    def setSolution(self, solution):
        self.solution = solution

    # Override hashCode method for proper hashing
    def __hash__(self):
        return hash((self.gcd, self.solution))

    # Override toString method for easy representation
    def __str__(self):
        return "GcdSolutionWrapper[" \
            + "gcd=" + str(self.gcd) + ", " \
            + "solution=" + str(self.solution) + ']'

# Main function to read input and print output
main()

# END-OF-CODE

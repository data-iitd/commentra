
import sys

# Class representing the solution of the equation
class Solution:
    # Singleton representing the case when there is no solution
    NO_SOLUTION = Solution(sys.maxsize, sys.maxsize)

    # Singleton representing the case when there are infinite solutions
    INFINITE_SOLUTIONS = Solution(sys.minsize, sys.minsize)

    # Store the solution's x and y components
    x = 0
    y = 0

    # Constructor
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Getters for x and y components
    def getX(self):
        return self.x

    def getY(self):
        return self.y

    # Setters for x and y components
    def setX(self, x):
        self.x = x

    def setY(self, y):
        self.y = y

    # Override equals method to compare solutions based on their components
    def __eq__(self, other):
        if self is other:
            return True
        if other is None or other.__class__!= self.__class__:
            return False
        return self.x == other.x and self.y == other.y

    # Override hashCode method to generate a hash based on x and y components
    def __hash__(self):
        return hash((self.x, self.y))

    # Override toString method to print the solution in a readable format
    def __str__(self):
        return "Solution[" \
            + "x=" + str(self.x) + ", " \
            + "y=" + str(self.y) + ']'

# Class representing the equation to be solved
class Equation:
    # Store the coefficients a, b, and constant c
    a = 0
    b = 0
    c = 0

    # Constructor
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    # Getters for coefficients a, b, and constant c
    def a(self):
        return self.a

    def b(self):
        return self.b

    def c(self):
        return self.c

# Helper method to find the greatest common divisor (gcd) using Euclidean algorithm
def gcd(a, b, previous):
    # Base case: b equals zero, return the gcd and the solution
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))

    # Recursive case: apply the Euclidean algorithm to b and the remainder of a modulo b
    next = gcd(b, a % b, GcdSolutionWrapper(0, Solution(0, 0)))

    # Update the previous solution with the new solution
    previous.getSolution().setX(next.getSolution().getY())
    previous.getSolution().setY(next.getSolution().getX() - (a / b) * next.getSolution().getY())
    previous.setGcd(next.getGcd())

    return GcdSolutionWrapper(next.getGcd(), previous.getSolution())

# Class representing the gcd and the solution using extended Euclidean algorithm
class GcdSolutionWrapper:
    # Store the gcd and the solution
    gcd = 0
    solution = Solution(0, 0)

    # Constructor
    def __init__(self, gcd, solution):
        self.gcd = gcd
        self.solution = solution

    # Getters and setters for gcd and solution
    def getGcd(self):
        return self.gcd

    def setGcd(self, gcd):
        self.gcd = gcd

    def getSolution(self):
        return self.solution

    def setSolution(self, solution):
        self.solution = solution

    # Override equals method to compare GcdSolutionWrapper based on gcd and solution
    def __eq__(self, other):
        if self is other:
            return True
        if other is None or other.__class__!= self.__class__:
            return False
        return self.gcd == other.gcd and self.solution == other.solution

    # Override hashCode method to generate a hash based on gcd and solution
    def __hash__(self):
        return hash((self.gcd, self.solution))

    # Override toString method to print the gcd and solution in a readable format
    def __str__(self):
        return ("GcdSolutionWrapper["
            + "gcd=" + str(self.gcd) + ", "
            + "solution=" + str(self.solution) + ']')

# Find any solution for the given equation using Euclidean algorithm
def findAnySolution(equation):
    # Check if the equation has infinite solutions (when all coefficients are zero)
    if equation.a() == 0 and equation.b() == 0 and equation.c() == 0:
        return Solution.INFINITE_SOLUTIONS

    # Initialize a helper object to store the gcd and the solution
    stubWrapper = GcdSolutionWrapper(0, Solution(0, 0))

    # Find the gcd of coefficients a and b using Euclidean algorithm
    gcdSolution = gcd(equation.a(), equation.b(), stubWrapper)

    # Check if there is a solution for the given equation
    if equation.c() % gcdSolution.getGcd()!= 0:
        return Solution.NO_SOLUTION

    # Calculate the solution x and y using the extended Euclidean algorithm
    toReturn = Solution(0, 0)
    xToSet = stubWrapper.getSolution().getX() * (equation.c() / gcdSolution.getGcd())
    yToSet = stubWrapper.getSolution().getY() * (equation.c() / gcdSolution.getGcd())
    toReturn.setX(xToSet)
    toReturn.setY(yToSet)

    return toReturn

# Helper method to read three integers a, b, and c from the user
def readThreeIntegers():
    a = int(input("Enter a: "))
    b = int(input("Enter b: "))
    c = int(input("Enter c: "))
    return a, b, c

# Main method
def main():
    # Read three integers a, b, and c from the user
    a, b, c = readThreeIntegers()

    # Create an Equation object with coefficients a, b, and constant c
    toSolve = Equation(a, b, c)

    # Find any solution for the given equation
    solution = findAnySolution(toSolve)

    # Check the type of solution and print the result accordingly
    if solution == Solution.NO_SOLUTION:
        print("No solution exists.")
    elif solution == Solution.INFINITE_SOLUTIONS:
        print("Infinite solutions exist.")
    else:
        print("One solution is: x = " + str(solution.getX()) + ", y = " + str(solution.getY()))

# Entry point of the program
if __name__ == "__main__":
    main()

# 
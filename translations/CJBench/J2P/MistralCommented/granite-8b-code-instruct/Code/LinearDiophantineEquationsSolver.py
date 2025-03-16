

import sys

class Solution:
    # Singleton representing the case when there is no solution
    NO_SOLUTION = Solution(sys.maxsize, sys.maxsize)

    # Singleton representing the case when there are infinite solutions
    INFINITE_SOLUTIONS = Solution(sys.minsize, sys.minsize)

    # Store the solution's x and y components
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
        if not isinstance(other, Solution):
            return False
        return self.x == other.x and self.y == other.y

    # Override hashCode method to generate a hash based on x and y components
    def __hash__(self):
        return hash((self.x, self.y))

    # Override toString method to print the solution in a readable format
    def __str__(self):
        return f"Solution[x={self.x}, y={self.y}]"

class Equation:
    # Store the coefficients a, b, and constant c
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

class GcdSolutionWrapper:
    # Store the gcd and the solution
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
        if not isinstance(other, GcdSolutionWrapper):
            return False
        return self.gcd == other.gcd and self.solution == other.solution

    # Override hashCode method to generate a hash based on gcd and solution
    def __hash__(self):
        return hash((self.gcd, self.solution))

    # Override toString method to print the gcd and solution in a readable format
    def __str__(self):
        return f"GcdSolutionWrapper[gcd={self.gcd}, solution={self.solution}]"

# Find any solution for the given equation using Euclidean algorithm
def findAnySolution(equation):
    # Check if the equation has infinite solutions (when all coefficients are zero)
    if equation.a() == 0 and equation.b() == 0 and equation.c() == 0:
        return Solution.INFINITE_SOLUTIONS

    # Initialize a helper object to store the gcd and the solution
    gcd_solution = GcdSolutionWrapper(0, Solution(0, 0))

    # Find the gcd of coefficients a and b using Euclidean algorithm
    gcd_solution = gcd(equation.a(), equation.b(), gcd_solution)

    # Check if there is a solution for the given equation
    if equation.c() % gcd_solution.getGcd()!= 0:
        return Solution.NO_SOLUTION

    # Calculate the solution x and y using the extended Euclidean algorithm
    x_to_set = gcd_solution.getSolution().getX() * (equation.c() // gcd_solution.getGcd())
    y_to_set = gcd_solution.getSolution().getY() * (equation.c() // gcd_solution.getGcd())
    solution = Solution(x_to_set, y_to_set)

    return solution

# Helper method to find the greatest common divisor (gcd) using Euclidean algorithm
def gcd(a, b, previous):
    # Base case: b equals zero, return the gcd and the solution
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))

    # Recursive case: apply the Euclidean algorithm to b and the remainder of a modulo b
    next = GcdSolutionWrapper(0, Solution(0, 0))
    gcd(b, a % b, next)

    # Update the previous solution with the new solution
    previous.getSolution().setX(next.getSolution().getY())
    previous.getSolution().setY(next.getSolution().getX() - (a // b) * next.getSolution().getY())
    previous.setGcd(next.getGcd())

    return GcdSolutionWrapper(next.getGcd(), previous.getSolution())

# Read three integers a, b, and c from the user
a = int(input("Enter the value of a: "))
b = int(input("Enter the value of b: "))
c = int(input("Enter the value of c: "))

# Create an Equation object with coefficients a, b, and constant c
equation = Equation(a, b, c)

# Find any solution for the given equation
solution = findAnySolution(equation)

# Check the type of solution and print the result accordingly
if solution == Solution.NO_SOLUTION:
    print("No solution exists.")
elif solution == Solution.INFINITE_SOLUTIONS:
    print("Infinite solutions exist.")
else:
    print(f"One solution is: x = {solution.getX()}, y = {solution.getY()}")

# END-OF-CODE
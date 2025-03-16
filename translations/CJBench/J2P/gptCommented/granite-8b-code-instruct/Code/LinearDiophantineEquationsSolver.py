
import math

class Solution:
    # Constants representing special cases of solutions
    NO_SOLUTION = (math.inf, math.inf)
    INFINITE_SOLUTIONS = (-math.inf, -math.inf)

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def setX(self, x):
        self.x = x

    def setY(self, y):
        self.y = y

    def __eq__(self, other):
        if self is other:
            return True
        if not isinstance(other, Solution):
            return False
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return hash((self.x, self.y))

    def __str__(self):
        return f"Solution[x={self.x}, y={self.y}]"

class Equation:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def a(self):
        return self.a

    def b(self):
        return self.b

    def c(self):
        return self.c

class GcdSolutionWrapper:
    def __init__(self, gcd, solution):
        self.gcd = gcd
        self.solution = solution

    def __eq__(self, other):
        if self is other:
            return True
        if not isinstance(other, GcdSolutionWrapper):
            return False
        return self.gcd == other.gcd and self.solution == other.solution

    def getGcd(self):
        return self.gcd

    def setGcd(self, gcd):
        self.gcd = gcd

    def getSolution(self):
        return self.solution

    def setSolution(self, solution):
        self.solution = solution

    def __hash__(self):
        return hash((self.gcd, self.solution))

    def __str__(self):
        return f"GcdSolutionWrapper[gcd={self.gcd}, solution={self.solution}]"

def find_any_solution(equation):
    # Check if the equation is of the form 0 = 0, which has infinite solutions
    if equation.a() == 0 and equation.b() == 0 and equation.c() == 0:
        return Solution.INFINITE_SOLUTIONS

    # Initialize a wrapper to hold GCD and a solution
    gcd_solution = GcdSolutionWrapper(0, Solution(0, 0))

    # Calculate the GCD of the coefficients and get a particular solution
    gcd_solution = gcd(equation.a(), equation.b(), gcd_solution)

    # Check if the equation has no solution based on the GCD
    if equation.c() % gcd_solution.getGcd()!= 0:
        return Solution.NO_SOLUTION

    # Create a new solution object to return
    solution = Solution(0, 0)

    # Calculate the specific solution based on the GCD and the input constant
    solution.setX(gcd_solution.getSolution().getX() * (equation.c() // gcd_solution.getGcd()))
    solution.setY(gcd_solution.getSolution().getY() * (equation.c() // gcd_solution.getGcd()))

    # Return the found solution
    return solution

def gcd(a, b, previous):
    # Base case: if b is 0, return the GCD and a solution
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))

    # Create a stub for the next recursive call
    stub = GcdSolutionWrapper(0, Solution(0, 0))

    # Recursive call to find the GCD
    next = gcd(b, a % b, stub)

    # Update the previous solution based on the results of the recursive call
    previous.getSolution().setX(next.getSolution().getY())
    previous.getSolution().setY(next.getSolution().getX() - (a // b) * (next.getSolution().getY()))
    previous.setGcd(next.getGcd())

    # Return the updated GCD and solution
    return GcdSolutionWrapper(next.getGcd(), previous.getSolution())

# END-OF-CODE
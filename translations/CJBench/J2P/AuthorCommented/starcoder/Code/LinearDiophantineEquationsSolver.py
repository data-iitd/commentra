
import sys
import math

# This program solves Linear Diophantine Equations of the form ax + by = c.
# It provides solutions or determines if no solutions or infinite solutions exist.

# <START-OF-CODE>

def findAnySolution(equation):
    if equation.a() == 0 and equation.b() == 0 and equation.c() == 0:
        return Solution.INFINITE_SOLUTIONS
    stub = GcdSolutionWrapper(0, Solution(0, 0))
    gcdSolution = gcd(equation.a(), equation.b(), stub)
    if equation.c() % gcdSolution.getGcd()!= 0:
        return Solution.NO_SOLUTION

    # Compute a valid solution using the GCD and scaling by c
    toReturn = Solution(0, 0)
    xToSet = stub.getSolution().getX() * (equation.c() / stub.getGcd())
    yToSet = stub.getSolution().getY() * (equation.c() / stub.getGcd())
    toReturn.setX(xToSet)
    toReturn.setY(yToSet)
    return toReturn

def gcd(a, b, previous):
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))
    stubWrapper = GcdSolutionWrapper(0, Solution(0, 0))
    next = gcd(b, a % b, stubWrapper)

    # Update the solution based on the previous recursive call
    previous.getSolution().setX(next.getSolution().getY())
    previous.getSolution().setY(next.getSolution().getX() - (a / b) * (next.getSolution().getY()))
    previous.setGcd(next.getGcd())
    return GcdSolutionWrapper(next.getGcd(), previous.getSolution())

class Solution:
    NO_SOLUTION = Solution(sys.maxsize, sys.maxsize)
    INFINITE_SOLUTIONS = Solution(-sys.maxsize, -sys.maxsize)

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
        if other is None or other.__class__!= self.__class__:
            return False
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return hash((self.x, self.y))

    def __str__(self):
        return "Solution[x=" + str(self.x) + ", y=" + str(self.y) + "]"

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
        if other is None or other.__class__!= self.__class__:
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
        return "GcdSolutionWrapper[gcd=" + str(self.gcd) + ", solution=" + str(self.solution) + "]"

# 
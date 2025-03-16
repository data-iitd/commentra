

import sys

class Solution:
    NO_SOLUTION = Solution(sys.maxsize, sys.maxsize)
    INFINITE_SOLUTIONS = Solution(sys.minsize, sys.minsize)

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        if self is other:
            return True
        if other is None or type(self)!= type(other):
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

def find_any_solution(equation):
    if equation.a == 0 and equation.b == 0 and equation.c == 0:
        return Solution.INFINITE_SOLUTIONS
    stub = GcdSolutionWrapper(0, Solution(0, 0))
    gcd_solution = gcd(equation.a, equation.b, stub)
    if equation.c % gcd_solution.gcd!= 0:
        return Solution.NO_SOLUTION
    # Compute a valid solution using the GCD and scaling by c
    to_return = Solution(0, 0)
    x_to_set = stub.solution.x * (equation.c // gcd_solution.gcd)
    y_to_set = stub.solution.y * (equation.c // gcd_solution.gcd)
    to_return.x = x_to_set
    to_return.y = y_to_set
    return to_return

def gcd(a, b, previous):
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))
    stub_wrapper = GcdSolutionWrapper(0, Solution(0, 0))
    next = gcd(b, a % b, stub_wrapper)
    # Update the solution based on the previous recursive call
    previous.solution.x = next.solution.y
    previous.solution.y = next.solution.x - (a // b) * (next.solution.y)
    previous.gcd = next.gcd
    return GcdSolutionWrapper(next.gcd, previous.solution)

class GcdSolutionWrapper:
    def __init__(self, gcd, solution):
        self.gcd = gcd
        self.solution = solution

    def __eq__(self, other):
        if self is other:
            return True
        if other is None or type(self)!= type(other):
            return False
        return self.gcd == other.gcd and self.solution == other.solution

    def __hash__(self):
        return hash((self.gcd, self.solution))

    def __str__(self):
        return f"GcdSolutionWrapper[gcd={self.gcd}, solution={self.solution}]"

# 
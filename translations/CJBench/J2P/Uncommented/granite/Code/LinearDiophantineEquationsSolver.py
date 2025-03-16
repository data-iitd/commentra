

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
        if not isinstance(other, Solution):
            return False
        return self.x == other.x and self.y == other.y
    def __hash__(self):
        return hash((self.x, self.y))
    def __repr__(self):
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
    def __repr__(self):
        return f"GcdSolutionWrapper[gcd={self.gcd}, solution={self.solution}]"
def find_any_solution(equation):
    if equation.a() == 0 and equation.b() == 0 and equation.c() == 0:
        return Solution.INFINITE_SOLUTIONS
    stub = GcdSolutionWrapper(0, Solution(0, 0))
    gcd_solution = gcd(equation.a(), equation.b(), stub)
    if equation.c() % gcd_solution.getGcd()!= 0:
        return Solution.NO_SOLUTION
    to_return = Solution(0, 0)
    x_to_set = stub.getSolution().getX() * (equation.c() // gcd_solution.getGcd())
    y_to_set = stub.getSolution().getY() * (equation.c() // gcd_solution.getGcd())
    to_return.setX(x_to_set)
    to_return.setY(y_to_set)
    return to_return
def gcd(a, b, previous):
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))
    stub_wrapper = GcdSolutionWrapper(0, Solution(0, 0))
    next = gcd(b, a % b, stub_wrapper)
    previous.getSolution().setX(next.getSolution().getY())
    previous.getSolution().setY(next.getSolution().getX() - (a // b) * (next.getSolution().getY()))
    previous.setGcd(next.getGcd())
    return GcdSolutionWrapper(next.getGcd(), previous.getSolution())
if __name__ == "__main__":
    a, b, c = map(int, input().split())
    equation = Equation(a, b, c)
    solution = find_any_solution(equation)
    if solution == Solution.NO_SOLUTION:
        print("No solution exists.")
    elif solution == Solution.INFINITE_SOLUTIONS:
        print("Infinite solutions exist.")
    else:
        print(f"One solution is: x = {solution.getX()}, y = {solution.getY()}")


import sys
import math

class Solution:
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

    def getGcd(self):
        return self.gcd

    def setGcd(self, gcd):
        self.gcd = gcd

    def getSolution(self):
        return self.solution

    def setSolution(self, solution):
        self.solution = solution

def findAnySolution(equation):
    if equation.a() == 0 and equation.b() == 0 and equation.c() == 0:
        return Solution.INFINITE_SOLUTIONS
    stub = GcdSolutionWrapper(0, Solution(0, 0))
    gcdSolution = gcd(equation.a(), equation.b(), stub)
    if equation.c() % gcdSolution.getGcd()!= 0:
        return Solution.NO_SOLUTION
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
    previous.getSolution().setX(next.getSolution().getY())
    previous.getSolution().setY(next.getSolution().getX() - (a / b) * (next.getSolution().getY()))
    previous.setGcd(next.getGcd())
    return GcdSolutionWrapper(next.getGcd(), previous.getSolution())

def main():
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    a = data[0]
    b = data[1]
    c = data[2]
    equation = Equation(a, b, c)
    solution = findAnySolution(equation)
    if solution.equals(Solution.NO_SOLUTION):
        print("No solution exists.")
    elif solution.equals(Solution.INFINITE_SOLUTIONS):
        print("Infinite solutions exist.")
    else:
        print("One solution is: x =", solution.getX(), ", y =", solution.getY())

if __name__ == '__main__':
    main()

# 
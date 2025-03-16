
import math
import sys

def find_any_solution(equation):
    if equation.a == 0 and equation.b == 0 and equation.c == 0:
        return Solution(0, 0)
    gcd_solution = gcd(equation.a, equation.b)
    if equation.c % gcd_solution.gcd != 0:
        return Solution(0, 0)
    x = gcd_solution.solution.x * (equation.c / gcd_solution.gcd)
    y = gcd_solution.solution.y * (equation.c / gcd_solution.gcd)
    return Solution(x, y)

def gcd(a, b):
    if b == 0:
        return GcdSolution(a, Solution(1, 0))
    gcd_solution = gcd(b, a % b)
    solution = gcd_solution.solution
    solution.x = gcd_solution.solution.y
    solution.y = gcd_solution.solution.x - (a / b) * (gcd_solution.solution.y)
    return GcdSolution(gcd_solution.gcd, solution)

class Solution:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class GcdSolution:
    def __init__(self, gcd, solution):
        self.gcd = gcd
        self.solution = solution

class Equation:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

def main():
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    c = int(sys.stdin.readline())
    equation = Equation(a, b, c)
    solution = find_any_solution(equation)
    if solution.x == 0 and solution.y == 0:
        print("No solution exists.")
    elif solution.x == -1 and solution.y == -1:
        print("Infinite solutions exist.")
    else:
        print("One solution is: x = " + str(solution.x) + ", y = " + str(solution.y))

if __name__ == "__main__":
    main()


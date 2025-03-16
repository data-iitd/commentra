
import sys


def find_any_solution(equation):
    if equation.a == 0 and equation.b == 0 and equation.c == 0:
        return Solution(0, 0)
    gcd_solution = gcd(equation.a, equation.b, GcdSolutionWrapper(0, Solution(0, 0)))
    if equation.c % gcd_solution.gcd != 0:
        return None
    x = gcd_solution.solution.x * (equation.c // gcd_solution.gcd)
    y = gcd_solution.solution.y * (equation.c // gcd_solution.gcd)
    return Solution(x, y)


def gcd(a, b, previous):
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))
    next = gcd(b, a % b, GcdSolutionWrapper(0, Solution(0, 0)))
    previous.solution.x = next.solution.y
    previous.solution.y = next.solution.x - (a // b) * (next.solution.y)
    previous.gcd = next.gcd
    return GcdSolutionWrapper(next.gcd, previous.solution)


class Solution:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Equation:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c


class GcdSolutionWrapper:
    def __init__(self, gcd, solution):
        self.gcd = gcd
        self.solution = solution


if __name__ == "__main__":
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    c = int(sys.stdin.readline())
    equation = Equation(a, b, c)
    solution = find_any_solution(equation)
    if solution is None:
        print("No solution exists.")
    else:
        print("One solution is: x = " + str(solution.x) + ", y = " + str(solution.y))



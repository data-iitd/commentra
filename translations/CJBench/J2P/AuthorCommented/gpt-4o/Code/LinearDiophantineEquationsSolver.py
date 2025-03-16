class Solution:
    NO_SOLUTION = (float('inf'), float('inf'))
    INFINITE_SOLUTIONS = (float('-inf'), float('-inf'))

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        if isinstance(other, Solution):
            return self.x == other.x and self.y == other.y
        return False

    def __hash__(self):
        return hash((self.x, self.y))

    def __str__(self):
        return f"Solution[x={self.x}, y={self.y}]"


class Equation:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c


class GcdSolutionWrapper:
    def __init__(self, gcd, solution):
        self.gcd = gcd
        self.solution = solution

    def __eq__(self, other):
        if isinstance(other, GcdSolutionWrapper):
            return self.gcd == other.gcd and self.solution == other.solution
        return False

    def __hash__(self):
        return hash((self.gcd, self.solution))

    def __str__(self):
        return f"GcdSolutionWrapper[gcd={self.gcd}, solution={self.solution}]"


def gcd(a, b, previous):
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))
    stub_wrapper = GcdSolutionWrapper(0, Solution(0, 0))
    next_gcd = gcd(b, a % b, stub_wrapper)

    previous.solution.x = next_gcd.solution.y
    previous.solution.y = next_gcd.solution.x - (a // b) * next_gcd.solution.y
    previous.gcd = next_gcd.gcd
    return GcdSolutionWrapper(next_gcd.gcd, previous.solution)


def find_any_solution(equation):
    if equation.a == 0 and equation.b == 0 and equation.c == 0:
        return Solution.INFINITE_SOLUTIONS

    stub = GcdSolutionWrapper(0, Solution(0, 0))
    gcd_solution = gcd(equation.a, equation.b, stub)

    if equation.c % gcd_solution.gcd != 0:
        return Solution.NO_SOLUTION

    x_to_set = stub.solution.x * (equation.c // stub.gcd)
    y_to_set = stub.solution.y * (equation.c // stub.gcd)
    return Solution(x_to_set, y_to_set)


def main():
    a = int(input())
    b = int(input())
    c = int(input())

    equation = Equation(a, b, c)
    solution = find_any_solution(equation)

    if solution == Solution.NO_SOLUTION:
        print("No solution exists.")
    elif solution == Solution.INFINITE_SOLUTIONS:
        print("Infinite solutions exist.")
    else:
        print(f"One solution is: x = {solution.x}, y = {solution.y}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>

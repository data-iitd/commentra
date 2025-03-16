import sys

class Solution:
    NO_SOLUTION = None
    INFINITE_SOLUTIONS = None

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def get_x(self):
        return self.x

    def get_y(self):
        return self.y

    def set_x(self, x):
        self.x = x

    def set_y(self, y):
        self.y = y

    def __eq__(self, obj):
        if obj is self:
            return True
        if obj is None or type(obj) is not type(self):
            return False
        return self.x == obj.x and self.y == obj.y

    def __hash__(self):
        return hash((self.x, self.y))

    def __repr__(self):
        return f"Solution(x={self.x}, y={self.y})"


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

    def get_gcd(self):
        return self.gcd

    def set_gcd(self, gcd):
        self.gcd = gcd

    def get_solution(self):
        return self.solution

    def set_solution(self, solution):
        self.solution = solution

    def __eq__(self, obj):
        if obj is self:
            return True
        if obj is None or type(obj) is not type(self):
            return False
        return self.gcd == obj.gcd and self.solution == obj.solution

    def __hash__(self):
        return hash((self.gcd, self.solution))

    def __repr__(self):
        return f"GcdSolutionWrapper(gcd={self.gcd}, solution={self.solution})"


def gcd(a, b, previous):
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))
    stub_wrapper = GcdSolutionWrapper(0, Solution(0, 0))
    next = gcd(b, a % b, stub_wrapper)
    previous.get_solution().set_x(next.get_solution().get_y())
    previous.get_solution().set_y(next.get_solution().get_x() - (a // b) * (next.get_solution().get_y()))
    previous.set_gcd(next.get_gcd())
    return GcdSolutionWrapper(next.get_gcd(), previous.get_solution())


def find_any_solution(equation):
    if equation.a() == 0 and equation.b() == 0 and equation.c() == 0:
        return Solution.INFINITE_SOLUTIONS
    stub = GcdSolutionWrapper(0, Solution(0, 0))
    gcd_solution = gcd(equation.a(), equation.b(), stub)
    if equation.c() % gcd_solution.get_gcd() != 0:
        return Solution.NO_SOLUTION
    to_return = Solution(0, 0)
    x_to_set = stub.get_solution().get_x() * (equation.c() // stub.get_gcd())
    y_to_set = stub.get_solution().get_y() * (equation.c() // stub.get_gcd())
    to_return.set_x(x_to_set)
    to_return.set_y(y_to_set)
    return to_return


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
        print(f"One solution is: x = {solution.get_x()}, y = {solution.get_y()}")


if __name__ == "__main__":
    main()

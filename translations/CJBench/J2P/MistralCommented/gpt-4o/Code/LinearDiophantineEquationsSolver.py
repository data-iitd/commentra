class Solution:
    # Singleton representing the case when there is no solution
    NO_SOLUTION = (float('inf'), float('inf'))

    # Singleton representing the case when there are infinite solutions
    INFINITE_SOLUTIONS = (float('-inf'), float('-inf'))

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

    def __eq__(self, other):
        if isinstance(other, GcdSolutionWrapper):
            return self.gcd == other.gcd and self.solution == other.solution
        return False

    def __hash__(self):
        return hash((self.gcd, self.solution))

    def __str__(self):
        return f"GcdSolutionWrapper[gcd={self.gcd}, solution={self.solution}]"


def gcd(a, b, previous):
    # Base case: b equals zero, return the gcd and the solution
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))

    # Recursive case: apply the Euclidean algorithm to b and the remainder of a modulo b
    stub_wrapper = GcdSolutionWrapper(0, Solution(0, 0))
    next_gcd_solution = gcd(b, a % b, stub_wrapper)

    # Update the previous solution with the new solution
    previous.get_solution().set_x(next_gcd_solution.get_solution().get_y())
    previous.get_solution().set_y(next_gcd_solution.get_solution().get_x() - (a // b) * next_gcd_solution.get_solution().get_y())
    previous.set_gcd(next_gcd_solution.get_gcd())

    return GcdSolutionWrapper(next_gcd_solution.get_gcd(), previous.get_solution())


def find_any_solution(equation):
    # Check if the equation has infinite solutions (when all coefficients are zero)
    if equation.a == 0 and equation.b == 0 and equation.c == 0:
        return Solution.INFINITE_SOLUTIONS

    # Initialize a helper object to store the gcd and the solution
    stub_wrapper = GcdSolutionWrapper(0, Solution(0, 0))

    # Find the gcd of coefficients a and b using Euclidean algorithm
    gcd_solution = gcd(equation.a, equation.b, stub_wrapper)

    # Check if there is a solution for the given equation
    if equation.c % gcd_solution.get_gcd() != 0:
        return Solution.NO_SOLUTION

    # Calculate the solution x and y using the extended Euclidean algorithm
    x_to_set = stub_wrapper.get_solution().get_x() * (equation.c // gcd_solution.get_gcd())
    y_to_set = stub_wrapper.get_solution().get_y() * (equation.c // gcd_solution.get_gcd())
    return Solution(x_to_set, y_to_set)


def main():
    # Read three integers a, b, and c from the user
    a = int(input())
    b = int(input())
    c = int(input())

    # Create an Equation object with coefficients a, b, and constant c
    to_solve = Equation(a, b, c)

    # Find any solution for the given equation
    solution = find_any_solution(to_solve)

    # Check the type of solution and print the result accordingly
    if solution == Solution.NO_SOLUTION:
        print("No solution exists.")
    elif solution == Solution.INFINITE_SOLUTIONS:
        print("Infinite solutions exist.")
    else:
        print(f"One solution is: x = {solution.get_x()}, y = {solution.get_y()}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>

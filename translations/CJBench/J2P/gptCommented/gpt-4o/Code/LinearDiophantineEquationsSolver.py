class Solution:
    # Constants representing special cases of solutions
    NO_SOLUTION = (float('inf'), float('inf'))
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


def find_any_solution(equation):
    # Check if the equation is of the form 0 = 0, which has infinite solutions
    if equation.a == 0 and equation.b == 0 and equation.c == 0:
        return Solution.INFINITE_SOLUTIONS

    # Initialize a wrapper to hold GCD and a solution
    stub = GcdSolutionWrapper(0, Solution(0, 0))

    # Calculate the GCD of the coefficients and get a particular solution
    gcd_solution = gcd(equation.a, equation.b, stub)

    # Check if the equation has no solution based on the GCD
    if equation.c % gcd_solution.get_gcd() != 0:
        return Solution.NO_SOLUTION

    # Create a new solution object to return
    to_return = Solution(0, 0)

    # Calculate the specific solution based on the GCD and the input constant
    x_to_set = stub.get_solution().get_x() * (equation.c // stub.get_gcd())
    y_to_set = stub.get_solution().get_y() * (equation.c // stub.get_gcd())

    # Set the calculated values in the solution object
    to_return.set_x(x_to_set)
    to_return.set_y(y_to_set)

    # Return the found solution
    return to_return


def gcd(a, b, previous):
    # Base case: if b is 0, return the GCD and a solution
    if b == 0:
        return GcdSolutionWrapper(a, Solution(1, 0))

    # Create a stub for the next recursive call
    stub_wrapper = GcdSolutionWrapper(0, Solution(0, 0))

    # Recursive call to find the GCD
    next_gcd_solution = gcd(b, a % b, stub_wrapper)

    # Update the previous solution based on the results of the recursive call
    previous.get_solution().set_x(next_gcd_solution.get_solution().get_y())
    previous.get_solution().set_y(next_gcd_solution.get_solution().get_x() - (a // b) * next_gcd_solution.get_solution().get_y())
    previous.set_gcd(next_gcd_solution.get_gcd())

    # Return the updated GCD and solution
    return GcdSolutionWrapper(next_gcd_solution.get_gcd(), previous.get_solution())


def main():
    # Read three integers from the user, representing the coefficients of the equation
    a = int(input())
    b = int(input())
    c = int(input())

    # Create an Equation object using the input coefficients
    to_solve = Equation(a, b, c)

    # Find any solution for the given equation
    solution = find_any_solution(to_solve)

    # Check the type of solution and print the appropriate message
    if solution == Solution.NO_SOLUTION:
        print("No solution exists.")
    elif solution == Solution.INFINITE_SOLUTIONS:
        print("Infinite solutions exist.")
    else:
        # Print the unique solution found
        print(f"One solution is: x = {solution.get_x()}, y = {solution.get_y()}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>

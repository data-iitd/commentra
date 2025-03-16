import math

class Main:
    def simpsons_method(self, n, h, a):
        data = {}  # Key: i, Value: f(xi)
        xi = a  # Initialize xi = x0

        # Create the table of xi and yi points
        for i in range(n + 1):
            temp = self.f(xi)  # Get the value of the function at xi
            data[i] = temp
            xi += h  # Increment xi to the next point

        # Apply Simpson's rule formula
        integral_evaluation = 0
        for i in range(len(data)):
            if i == 0 or i == len(data) - 1:
                integral_evaluation += data[i]
            elif i % 2 != 0:
                integral_evaluation += 4 * data[i]
            else:
                integral_evaluation += 2 * data[i]

        # Multiply by h/3
        integral_evaluation = h / 3 * integral_evaluation

        # Return the result
        return integral_evaluation

    # Sample function f
    # Function f(x) = e^(-x) * (4 - x^2)
    def f(self, x):
        return math.exp(-x) * (4 - x**2)

# Main function to run the program
if __name__ == "__main__":
    n = int(input())

    # Ensure n is even
    if n % 2 != 0:
        print("n must be an even number for Simpson's method. Exiting.")
        exit()

    a = float(input())
    b = float(input())

    integration = Main()

    # Calculate step h and evaluate the integral
    h = (b - a) / n
    integral_evaluation = integration.simpsons_method(n, h, a)
    print("The integral is equal to:", integral_evaluation)


import math

class Main:
    def __init__(self):
        pass

    def simpsonsMethod(self, n, h, a):
        data = {}
        temp = 0
        xi = a
        for i in range(n + 1):
            temp = self.f(xi)
            data[i] = temp
            xi += h
        integralEvaluation = 0
        for i in range(n + 1):
            if i == 0 or i == n:
                integralEvaluation += data[i]
            elif i % 2!= 0:
                integralEvaluation += 4 * data[i]
            else:
                integralEvaluation += 2 * data[i]
        integralEvaluation = h / 3 * integralEvaluation
        return integralEvaluation

    def f(self, x):
        return math.exp(-x) * (4 - x**2)

if __name__ == "__main__":
    # Create a Scanner object to read input from the user
    scanner = input("Enter the number of intervals (n): ")
    n = int(scanner)
    # Check if n is even; if not, print an error message and exit
    if n % 2!= 0:
        print("n must be an even number for Simpson's method. Exiting.")
        exit()
    # Read the lower limit (a) and upper limit (b) for integration from user input
    a = float(input("Enter the lower limit (a): "))
    b = float(input("Enter the upper limit (b): "))
    # Create an instance of the Main class to access the integration method
    integration = Main()
    # Calculate the width of each interval (h)
    h = (b - a) / n
    # Perform Simpson's method to evaluate the integral
    integralEvaluation = integration.simpsonsMethod(n, h, a)
    # Output the result of the integral evaluation
    print("The integral is equal to: ", integralEvaluation)


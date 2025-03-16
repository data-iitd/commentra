
import math

class Main:
    def __init__(self):
        self.data = {}
        self.h = 0
        self.a = 0
        self.n = 0

    def simpsonsMethod(self, n, h, a):
        self.n = n
        self.h = h
        self.a = a

        # Initialize the current x value at the first limit a
        xi = a

        # Iterate through each interval from 0 to n+1
        for i in range(0, n + 1):
            # Calculate the function value at the current x value xi using the f() method
            temp = self.f(xi)

            # Store the function value and its corresponding index in the TreeMap
            self.data[i] = temp

            # Increment the current x value by the step size h
            xi += h

        # Initialize the integral evaluation to zero
        integralEvaluation = 0

        # Iterate through each key-value pair in the TreeMap
        for i in range(0, len(self.data)):
            # Calculate the contribution of the current function value to the integral evaluation based on its index i
            if i == 0:
                integralEvaluation += self.data[i] # First term: w(0) * f(xi)
            elif i == len(self.data) - 1:
                integralEvaluation += self.data[i] # Last term: w(n) * f(xi)
            elif i % 2!= 0:
                integralEvaluation += 4 * self.data[i] # Odd terms: w(i) * f(xi)
            else:
                integralEvaluation += 2 * self.data[i] # Even terms: w(i) * f(xi)

        # Calculate the final integral evaluation by multiplying the sum of the contributions by the step size h and dividing by 3
        integralEvaluation = h / 3 * integralEvaluation

        # Return the final integral evaluation
        return integralEvaluation

    def f(self, x):
        return math.exp(-x) * (4 - math.pow(x, 2))

if __name__ == "__main__":
    # Initialize an instance of the Main class
    integration = Main()

    # Read the number of intervals n from the user
    n = int(input("Enter the number of intervals: "))

    # Check if n is an even number. If not, print an error message and exit the program
    if n % 2!= 0:
        print("n must be an even number for Simpson's method. Exiting.")
        exit()

    # Read the first limit a and the second limit b from the user
    a = float(input("Enter the first limit: "))
    b = float(input("Enter the second limit: "))

    # Calculate the step size h and store the number of intervals n, step size h, and the first limit a
    h = (b - a) / n

    # Call the simpsonsMethod() with the number of intervals n, step size h, and the first limit a as arguments
    integralEvaluation = integration.simpsonsMethod(n, h, a)

    # Print the result of the integral evaluation
    print("The integral is equal to: " + str(integralEvaluation))


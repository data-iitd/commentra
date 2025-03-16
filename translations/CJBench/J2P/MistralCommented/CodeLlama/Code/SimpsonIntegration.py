
import math

def main():
    # Initialize scanner to read input from the user
    scanner = input()

    # Read the number of intervals n from the user
    n = int(scanner)

    # Check if n is an even number. If not, print an error message and exit the program
    if n % 2 != 0:
        print("n must be an even number for Simpson's method. Exiting.")
        return

    # Read the first limit a and the second limit b from the user
    a = float(scanner)
    b = float(scanner)

    # Create an instance of the Main class to call the simpsonsMethod()
    integration = Main()

    # Calculate the step size h and store the number of intervals n, step size h, and the first limit a
    h = (b - a) / n

    # Call the simpsonsMethod() with the number of intervals n, step size h, and the first limit a as arguments
    integralEvaluation = integration.simpsonsMethod(n, h, a)

    # Print the result of the integral evaluation
    print("The integral is equal to: " + integralEvaluation)

class Main:
    # Simpson's Method implementation
    def simpsonsMethod(self, n, h, a):
        # Initialize an empty TreeMap to store the function values at each interval
        data = {}

        # Initialize a temporary variable to store the function value at each interval
        temp = 0

        # Initialize the current x value at the first limit a
        xi = a

        # Iterate through each interval from 0 to n+1
        for i in range(0, n+1):
            # Calculate the function value at the current x value xi using the f() method
            temp = f(xi)

            # Store the function value and its corresponding index in the TreeMap
            data[i] = temp

            # Increment the current x value by the step size h
            xi += h

        # Initialize the integral evaluation to zero
        integralEvaluation = 0

        # Iterate through each key-value pair in the TreeMap
        for i in range(0, len(data)):
            # Calculate the contribution of the current function value to the integral evaluation based on its index i
            if i == 0:
                integralEvaluation += data[i] # First term: w(0) * f(xi)
            elif i == len(data) - 1:
                integralEvaluation += data[i] # Last term: w(n) * f(xi)
            elif i % 2 != 0:
                integralEvaluation += 4 * data[i] # Odd terms: w(i) * f(xi)
            else:
                integralEvaluation += 2 * data[i] # Even terms: w(i) * f(xi)

        # Calculate the final integral evaluation by multiplying the sum of the contributions by the step size h and dividing by 3
        integralEvaluation = h / 3 * integralEvaluation

        # Return the final integral evaluation
        return integralEvaluation

    # Function to calculate f(x) = e^(-x) * (4 - x^2)
    def f(self, x):
        return math.exp(-x) * (4 - math.pow(x, 2))

# Call the main() function
main()


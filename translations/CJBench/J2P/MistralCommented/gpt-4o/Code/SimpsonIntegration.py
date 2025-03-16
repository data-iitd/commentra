import math

class Main:
    def main(self):
        # Initialize scanner to read input from the user
        n = int(input("Enter the number of intervals (n): "))

        # Check if n is an even number. If not, print an error message and exit the program
        if n % 2 != 0:
            print("n must be an even number for Simpson's method. Exiting.")
            return

        # Read the first limit a and the second limit b from the user
        a = float(input("Enter the first limit (a): "))
        b = float(input("Enter the second limit (b): "))

        # Calculate the step size h
        h = (b - a) / n

        # Call the simpsons_method with the number of intervals n, step size h, and the first limit a as arguments
        integral_evaluation = self.simpsons_method(n, h, a)

        # Print the result of the integral evaluation
        print("The integral is equal to:", integral_evaluation)

    # Simpson's Method implementation
    def simpsons_method(self, n, h, a):
        # Initialize an empty list to store the function values at each interval
        data = []

        # Initialize the current x value at the first limit a
        xi = a

        # Iterate through each interval from 0 to n+1
        for i in range(n + 1):
            # Calculate the function value at the current x value xi using the f() method
            temp = self.f(xi)

            # Store the function value in the list
            data.append(temp)

            # Increment the current x value by the step size h
            xi += h

        # Initialize the integral evaluation to zero
        integral_evaluation = 0

        # Iterate through each index in the data list
        for i in range(len(data)):
            # Calculate the contribution of the current function value to the integral evaluation based on its index i
            if i == 0:
                integral_evaluation += data[i]  # First term: w(0) * f(xi)
            elif i == len(data) - 1:
                integral_evaluation += data[i]  # Last term: w(n) * f(xi)
            elif i % 2 != 0:
                integral_evaluation += 4 * data[i]  # Odd terms: w(i) * f(xi)
            else:
                integral_evaluation += 2 * data[i]  # Even terms: w(i) * f(xi)

        # Calculate the final integral evaluation by multiplying the sum of the contributions by the step size h and dividing by 3
        integral_evaluation = h / 3 * integral_evaluation

        # Return the final integral evaluation
        return integral_evaluation

    # Function to calculate f(x) = e^(-x) * (4 - x^2)
    def f(self, x):
        return math.exp(-x) * (4 - x ** 2)

# Create an instance of the Main class and call the main method
if __name__ == "__main__":
    integration = Main()
    integration.main()

# <END-OF-CODE>

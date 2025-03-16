import math

class Main:
    def main(self):
        # Read the number of intervals (n) from user input
        n = int(input("Enter the number of intervals (must be even): "))
        
        # Check if n is even; if not, print an error message and exit
        if n % 2 != 0:
            print("n must be an even number for Simpson's method. Exiting.")
            return
        
        # Read the lower limit (a) and upper limit (b) for integration from user input
        a = float(input("Enter the lower limit (a): "))
        b = float(input("Enter the upper limit (b): "))
        
        # Calculate the width of each interval (h)
        h = (b - a) / n
        
        # Perform Simpson's method to evaluate the integral
        integral_evaluation = self.simpsons_method(n, h, a)
        
        # Output the result of the integral evaluation
        print("The integral is equal to:", integral_evaluation)
    
    # Method to perform Simpson's method for numerical integration
    def simpsons_method(self, n, h, a):
        # Create a list to store the function values at each interval
        data = []
        xi = a
        
        # Calculate the function values at each interval and store them in the list
        for i in range(n + 1):
            temp = self.f(xi)
            data.append(temp)
            xi += h
        
        # Initialize the variable to hold the result of the integral evaluation
        integral_evaluation = 0
        
        # Apply Simpson's rule to compute the integral
        for i in range(len(data)):
            # Add the first and last terms
            if i == 0 or i == len(data) - 1:
                integral_evaluation += data[i]
            # Add the odd-indexed terms multiplied by 4
            elif i % 2 != 0:
                integral_evaluation += 4 * data[i]
            # Add the even-indexed terms multiplied by 2
            else:
                integral_evaluation += 2 * data[i]
        
        # Multiply the accumulated sum by h/3 to get the final integral value
        integral_evaluation = h / 3 * integral_evaluation
        return integral_evaluation
    
    # Function to evaluate the mathematical function f(x) = e^(-x) * (4 - x^2)
    def f(self, x):
        return math.exp(-x) * (4 - x ** 2)

# Create an instance of the Main class and call the main method
if __name__ == "__main__":
    integration = Main()
    integration.main()

# <END-OF-CODE>

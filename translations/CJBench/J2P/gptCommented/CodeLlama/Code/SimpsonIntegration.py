import math

def main():
    # Create a Scanner object to read input from the user
    scanner = Scanner(System.in)
    
    # Read the number of intervals (n) from user input
    n = scanner.nextInt()
    
    # Check if n is even; if not, print an error message and exit
    if n % 2 != 0:
        print("n must be an even number for Simpson's method. Exiting.")
        return
    
    # Read the lower limit (a) and upper limit (b) for integration from user input
    a = scanner.nextDouble()
    b = scanner.nextDouble()
    
    # Create an instance of the Main class to access the integration method
    integration = Main()
    
    # Calculate the width of each interval (h)
    h = (b - a) / n
    
    # Perform Simpson's method to evaluate the integral
    integralEvaluation = integration.simpsonsMethod(n, h, a)
    
    # Output the result of the integral evaluation
    print("The integral is equal to: " + integralEvaluation)

def simpsonsMethod(n, h, a):
    # Create a TreeMap to store the function values at each interval
    data = TreeMap()
    temp = 0
    xi = a
    
    # Calculate the function values at each interval and store them in the TreeMap
    for i in range(0, n + 1):
        temp = f(xi)
        data.put(i, temp)
        xi += h
    
    # Initialize the variable to hold the result of the integral evaluation
    integralEvaluation = 0
    
    # Apply Simpson's rule to compute the integral
    for i in range(0, data.size()):
        # Add the first and last terms
        if i == 0 or i == data.size() - 1:
            integralEvaluation += data.get(i)
        # Add the odd-indexed terms multiplied by 4
        elif i % 2 != 0:
            integralEvaluation += 4 * data.get(i)
        # Add the even-indexed terms multiplied by 2
        else:
            integralEvaluation += 2 * data.get(i)
    
    # Multiply the accumulated sum by h/3 to get the final integral value
    integralEvaluation = h / 3 * integralEvaluation
    return integralEvaluation

def f(x):
    return math.exp(-x) * (4 - math.pow(x, 2))

if __name__ == "__main__":
    main()


import sys

# Function to evaluate the mathematical function f(x) = e^(-x) * (4 - x^2)
def f(x):
    return math.exp(-x) * (4 - x**2)

# Main function
def main():
    # Check if the number of command line arguments is correct
    if len(sys.argv)!= 3:
        print("Usage: python3 simpsons.py n a b")
        return
    
    # Read the number of intervals (n) and lower limit (a) and upper limit (b) for integration from command line arguments
    n = int(sys.argv[1])
    a = float(sys.argv[2])
    b = float(sys.argv[3])
    
    # Check if n is even; if not, print an error message and exit
    if n % 2!= 0:
        print("n must be an even number for Simpson's method. Exiting.")
        return
    
    # Calculate the width of each interval (h)
    h = (b - a) / n
    
    # Perform Simpson's method to evaluate the integral
    integralEvaluation = simpsonsMethod(n, h, a)
    
    # Output the result of the integral evaluation
    print("The integral is equal to: " + str(integralEvaluation))

# Method to perform Simpson's method for numerical integration
def simpsonsMethod(n, h, a):
    # Create a TreeMap to store the function values at each interval
    data = {}
    temp = 0
    xi = a
    
    # Calculate the function values at each interval and store them in the TreeMap
    for i in range(n + 1):
        temp = f(xi)
        data[i] = temp
        xi += h
    
    # Initialize the variable to hold the result of the integral evaluation
    integralEvaluation = 0
    
    # Apply Simpson's rule to compute the integral
    for i in range(n + 1):
        # Add the first and last terms
        if i == 0 or i == n:
            integralEvaluation += data[i]
        # Add the odd-indexed terms multiplied by 4
        elif i % 2!= 0:
            integralEvaluation += 4 * data[i]
        # Add the even-indexed terms multiplied by 2
        else:
            integralEvaluation += 2 * data[i]
    
    # Multiply the accumulated sum by h/3 to get the final integral value
    integralEvaluation = h / 3 * integralEvaluation
    return integralEvaluation

# Main execution
if __name__ == "__main__":
    main()

# 
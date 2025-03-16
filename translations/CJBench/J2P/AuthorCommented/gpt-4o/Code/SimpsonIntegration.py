import math

def f(x):
    # Sample function f(x) = e^(-x) * (4 - x^2)
    return math.exp(-x) * (4 - x**2)

def simpsons_method(n, h, a):
    data = {}  # Dictionary to store xi and f(xi)
    xi = a  # Initialize xi = x0

    # Create the table of xi and f(xi) points
    for i in range(n + 1):
        data[i] = f(xi)  # Get the value of the function at xi
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

def main():
    n = int(input("Enter an even number of intervals (n): "))

    # Ensure n is even
    if n % 2 != 0:
        print("n must be an even number for Simpson's method. Exiting.")
        return

    a = float(input("Enter the starting point of the interval (a): "))
    b = float(input("Enter the ending point of the interval (b): "))

    # Calculate step h and evaluate the integral
    h = (b - a) / n
    integral_evaluation = simpsons_method(n, h, a)
    print("The integral is equal to:", integral_evaluation)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

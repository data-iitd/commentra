# <START-OF-CODE>

# Continuously read input until EOF (End of File) is reached
while True:
    # Declare integer variables for input coefficients
    a, b, c, d, e, f = map(int, input().split())
    # Declare double variables for the results of the equations
    x, y = 0, 0

    # Calculate the value of y using the given formula
    y = (c * d - f * a) / (b * d - e * a)
    # Calculate the value of x using the given formula
    x = (c * e - f * b) / (a * e - d * b)
    
    # Adjust y to 0 if it is a small negative number close to zero
    if y <= 0 and y > -0.0005: y = 0
    # Adjust x to 0 if it is a small negative number close to zero
    if x <= 0 and x > -0.0005: x = 0

    # Print the results x and y formatted to three decimal places
    print(f"{x:.3f} {y:.3f}")

# 
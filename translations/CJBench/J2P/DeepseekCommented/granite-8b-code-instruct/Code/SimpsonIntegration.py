
import math

def simpsons_method(n, a, b):
    h = (b - a) / n
    data = {}
    xi = a
    for i in range(n + 1):
        temp = f(xi)
        data[i] = temp
        xi += h
    integral_evaluation = 0
    for i in range(n + 1):
        if i == 0 or i == n:
            integral_evaluation += data[i]
        elif i % 2!= 0:
            integral_evaluation += 4 * data[i]
        else:
            integral_evaluation += 2 * data[i]
    integral_evaluation = h / 3 * integral_evaluation
    return integral_evaluation

def f(x):
    return math.exp(-x) * (4 - x**2)

n = int(input("Enter the number of intervals: "))
a = float(input("Enter the lower limit of the interval: "))
b = float(input("Enter the upper limit of the interval: "))

if n % 2!= 0:
    print("n must be an even number for Simpson's method. Exiting.")
else:
    integral_evaluation = simpsons_method(n, a, b)
    print("The integral is equal to:", integral_evaluation)


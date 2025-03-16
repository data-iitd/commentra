

import math

def simpsonsMethod(n, a, b):
    h = (b - a) / n
    data = {}
    xi = a
    for i in range(n + 1):
        temp = f(xi)
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

def f(x):
    return math.exp(-x) * (4 - x**2)

n = int(input("Enter the value of n: "))
a = float(input("Enter the value of a: "))
b = float(input("Enter the value of b: "))

if n % 2!= 0:
    print("n must be an even number for Simpson's method. Exiting.")
else:
    integralEvaluation = simpsonsMethod(n, a, b)
    print("The integral is equal to:", integralEvaluation)


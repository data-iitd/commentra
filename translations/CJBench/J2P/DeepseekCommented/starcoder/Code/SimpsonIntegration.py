import sys
import math

def f(x):
    return math.exp(-x) * (4 - x ** 2)

def simpsons_method(n, h, a):
    data = {}
    temp = 0
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

if __name__ == "__main__":
    n = int(input())
    if n % 2!= 0:
        print("n must be an even number for Simpson's method. Exiting.")
        sys.exit(0)
    a = float(input())
    b = float(input())
    h = (b - a) / n
    integral_evaluation = simpsons_method(n, h, a)
    print("The integral is equal to: " + str(integral_evaluation))


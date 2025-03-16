
import math
import numpy as np

def euler_step(x_current, step_size, y_current, differential_equation):
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")
    return y_current + step_size * differential_equation(x_current, y_current)

def euler_full(x_start, x_end, step_size, y_start, differential_equation):
    if x_start >= x_end:
        raise ValueError("x_end should be greater than x_start")
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")
    points = []
    points.append([x_start, y_start])
    y_current = y_start
    x_current = x_start
    while x_current < x_end:
        y_current = euler_step(x_current, step_size, y_current, differential_equation)
        x_current += step_size
        points.append([x_current, y_current])
    return points

def differential_equation_1(x, y):
    return x

def differential_equation_2(x, y):
    return y

def differential_equation_3(x, y):
    return x + y + x * y

def main():
    x_start = float(input("Enter x_start: "))
    x_end = float(input("Enter x_end: "))
    step_size = float(input("Enter step_size: "))
    y_start = float(input("Enter y_start: "))
    equation_choice = int(input("Enter equation_choice: "))
    differential_equation = None
    if equation_choice == 1:
        differential_equation = differential_equation_1
    elif equation_choice == 2:
        differential_equation = differential_equation_2
    elif equation_choice == 3:
        differential_equation = differential_equation_3
    else:
        raise ValueError("Invalid choice of differential equation")
    points = euler_full(x_start, x_end, step_size, y_start, differential_equation)
    print("Results:")
    for point in points:
        print(f"x: {point[0]:.6f}; y: {point[1]:.6f}")

if __name__ == "__main__":
    main()


import math
import sys

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

def main():
    x_start = float(sys.argv[1])
    x_end = float(sys.argv[2])
    step_size = float(sys.argv[3])
    y_start = float(sys.argv[4])
    equation_choice = int(sys.argv[5])
    differential_equation = None
    if equation_choice == 1:
        differential_equation = lambda x, y: x
    elif equation_choice == 2:
        differential_equation = lambda x, y: y
    elif equation_choice == 3:
        differential_equation = lambda x, y: x + y + x * y
    else:
        raise ValueError("Invalid choice of differential equation")
    points = euler_full(x_start, x_end, step_size, y_start, differential_equation)
    print("Results:")
    for point in points:
        print("x: {:.6f}; y: {:.6f}".format(point[0], point[1]))

if __name__ == "__main__":
    main()


import numpy as np

def euler_step(x_current, step_size, y_current, differential_equation):
    if step_size <= 0:
        raise ValueError("stepSize should be greater than zero")
    return y_current + step_size * differential_equation(x_current, y_current)

def euler_full(x_start, x_end, step_size, y_start, differential_equation):
    if x_start >= x_end:
        raise ValueError("xEnd should be greater than xStart")
    if step_size <= 0:
        raise ValueError("stepSize should be greater than zero")
    
    points = []
    points.append((x_start, y_start))
    y_current = y_start
    x_current = x_start
    
    while x_current < x_end:
        y_current = euler_step(x_current, step_size, y_current, differential_equation)
        x_current += step_size
        points.append((x_current, y_current))
    
    return points

def main():
    x_start = float(input())
    x_end = float(input())
    step_size = float(input())
    y_start = float(input())
    equation_choice = int(input())
    
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
        print(f"x: {point[0]:.6f}; y: {point[1]:.6f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

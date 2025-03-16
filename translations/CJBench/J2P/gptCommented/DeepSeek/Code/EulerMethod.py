import math
from typing import List, Callable

def euler_step(x_current: float, step_size: float, y_current: float, differential_equation: Callable[[float, float], float]) -> float:
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")
    return y_current + step_size * differential_equation(x_current, y_current)

def euler_full(x_start: float, x_end: float, step_size: float, y_start: float, differential_equation: Callable[[float, float], float]) -> List[List[float]]:
    if x_start >= x_end:
        raise ValueError("x_end should be greater than x_start")
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")
    
    points = [[x_start, y_start]]
    y_current = y_start
    x_current = x_start
    
    while x_current < x_end:
        y_current = euler_step(x_current, step_size, y_current, differential_equation)
        x_current += step_size
        points.append([x_current, y_current])
    
    return points

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    x_start = float(data[0])
    x_end = float(data[1])
    step_size = float(data[2])
    y_start = float(data[3])
    equation_choice = int(data[4])
    
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

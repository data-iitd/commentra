import math
from typing import List, Callable, Tuple

# Initializing the scanner for user input
class Main:
    def __init__(self):
        pass

    # Starting point of the main method
    @staticmethod
    def main():
        # Creating a new Scanner object for reading user input
        scanner = Scanner(sys.stdin)

        # Reading user input for the initial conditions and equation choice
        x_start = scanner.nextDouble()
        x_end = scanner.nextDouble()
        step_size = scanner.nextDouble()
        y_start = scanner.nextDouble()
        equation_choice = scanner.nextInt()

        # Assigning the differential equation based on the user's choice
        differential_equation: Callable[[float, float], float]
        if equation_choice == 1:
            differential_equation = lambda x, y: x  # Assigning the first differential equation
        elif equation_choice == 2:
            differential_equation = lambda x, y: y  # Assigning the second differential equation
        elif equation_choice == 3:
            differential_equation = lambda x, y: x + y + x * y  # Assigning the third differential equation
        else:
            raise ValueError("Invalid choice of differential equation")  # Throwing an exception for invalid equation choice

        # Calculating the points using the Euler method
        points = Main.euler_full(x_start, x_end, step_size, y_start, differential_equation)

        # Printing the results
        print("Results:")
        for point in points:
            print(f"x: {point[0]:.6f}; y: {point[1]:.6f}")

        # Closing the scanner to release system resources
        scanner.close()

    # Euler step method for calculating the next point
    @staticmethod
    def euler_step(x_current: float, step_size: float, y_current: float, differential_equation: Callable[[float, float], float]) -> float:
        if step_size <= 0:  # Checking if the step size is valid
            raise ValueError("step_size should be greater than zero")
        return y_current + step_size * differential_equation(x_current, y_current)  # Calculating the next y value using the Euler method

    # Euler Full method for calculating all the points
    @staticmethod
    def euler_full(x_start: float, x_end: float, step_size: float, y_start: float, differential_equation: Callable[[float, float], float]) -> List[Tuple[float, float]]:
        if x_start >= x_end:  # Checking if x_end is greater than x_start
            raise ValueError("x_end should be greater than x_start")
        if step_size <= 0:  # Checking if the step size is valid
            raise ValueError("step_size should be greater than zero")

        # Initializing an empty ArrayList to store the points
        points = []

        # Adding the initial point to the ArrayList
        points.append((x_start, y_start))

        y_current = y_start  # Initializing the current y value
        x_current = x_start  # Initializing the current x value

        # Calculating all the remaining points using the Euler method
        while x_current < x_end:
            y_current = Main.euler_step(x_current, step_size, y_current, differential_equation)
            x_current += step_size
            points.append((x_current, y_current))

        # Returning the ArrayList of points
        return points

# Importing necessary modules
import sys
from sys import stdin

# Creating a Scanner class to read input
class Scanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def nextDouble(self):
        return float(self.input_stream.readline().strip())

    def nextInt(self):
        return int(self.input_stream.readline().strip())

    def close(self):
        pass

# Calling the main method
if __name__ == "__main__":
    Main.main()

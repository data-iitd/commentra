import java.util.ArrayList;
import java.util.Scanner;
import java.util.function.BiFunction;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    public static void main(String[] args) {
        // Create a scanner object for user input
        Scanner scanner = new Scanner(System.in);
        
        // Read the starting x value, ending x value, step size, starting y value, and equation choice from user input
        double xStart = scanner.nextDouble();
        double xEnd = scanner.nextDouble();
        double stepSize = scanner.nextDouble();
        double yStart = scanner.nextDouble();
        int equationChoice = scanner.nextInt();
        
        // Declare a BiFunction to represent the differential equation
        BiFunction<Double, Double, Double> differentialEquation;
        
        // Select the appropriate differential equation based on user choice
        switch (equationChoice) {
            case 1:
                differentialEquation = (x, y) -> x; // dy/dx = x
                break;
            case 2:
                differentialEquation = (x, y) -> y; // dy/dx = y
                break;
            case 3:
                differentialEquation = (x, y) -> x + y + x * y; // dy/dx = x + y + xy
                break;
            default:
                // Throw an exception if the user provides an invalid choice
                throw new IllegalArgumentException("Invalid choice of differential equation");
        }
        
        // Calculate the points using the Euler method
        ArrayList<double[]> points = eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation);
        
        // Print the results
        System.out.println("Results:");
        for (double[] point : points) {
            System.out.printf("x: %.6f; y: %.6f%n", point[0], point[1]);
        }
    }

    // Method to perform a single Euler step
    public static double eulerStep(double xCurrent, double stepSize, double yCurrent, BiFunction<Double, Double, Double> differentialEquation) {
        // Validate that the step size is positive
        if (stepSize <= 0) {
            throw new IllegalArgumentException("stepSize should be greater than zero");
        }
        // Calculate the new y value using the differential equation
        return yCurrent + stepSize * differentialEquation.apply(xCurrent, yCurrent);
    }

    // Method to perform the full Euler method over the specified range
    public static ArrayList<double[]> eulerFull(double xStart, double xEnd, double stepSize, double yStart, BiFunction<Double, Double, Double> differentialEquation) {
        // Validate that the start and end x values are in the correct order
        if (xStart >= xEnd) {
            throw new IllegalArgumentException("xEnd should be greater than xStart");
        }
        // Validate that the step size is positive
        if (stepSize <= 0) {
            throw new IllegalArgumentException("stepSize should be greater than zero");
        }
        
        // Initialize a list to store the points (x, y)
        ArrayList<double[]> points = new ArrayList<>();
        points.add(new double[]{xStart, yStart}); // Add the starting point
        
        double yCurrent = yStart; // Initialize the current y value
        double xCurrent = xStart; // Initialize the current x value
        
        // Loop until the current x value reaches or exceeds the end x value
        while (xCurrent < xEnd) {
            // Perform an Euler step to calculate the new y value
            yCurrent = eulerStep(xCurrent, stepSize, yCurrent, differentialEquation);
            xCurrent += stepSize; // Increment the current x value by the step size
            
            // Add the new point to the list
            points.add(new double[]{xCurrent, yCurrent});
        }
        
        // Return the list of calculated points
        return points;
    }
}

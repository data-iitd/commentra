
import java.util.ArrayList;
import java.util.Scanner;
import java.util.function.BiFunction;

// Initializing the scanner for user input
public final class Main {
    private Main() {
    }

    // Starting point of the main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for reading user input

        // Reading user input for the initial conditions and equation choice
        double xStart = scanner.nextDouble();
        double xEnd = scanner.nextDouble();
        double stepSize = scanner.nextDouble();
        double yStart = scanner.nextDouble();
        int equationChoice = scanner.nextInt();

        // Assigning the differential equation based on the user's choice
        BiFunction<Double, Double, Double> differentialEquation;
        switch (equationChoice) {
            case 1:
                differentialEquation = (x, y) -> x; // Assigning the first differential equation
                break;
            case 2:
                differentialEquation = (x, y) -> y; // Assigning the second differential equation
                break;
            case 3:
                differentialEquation = (x, y) -> x + y + x * y; // Assigning the third differential equation
                break;
            default:
                throw new IllegalArgumentException("Invalid choice of differential equation"); // Throwing an exception for invalid equation choice
        }

        // Calculating the points using the Euler method
        ArrayList<double[]> points = eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation);

        // Printing the results
        System.out.println("Results:");
        for (double[] point : points) {
            System.out.printf("x: %.6f; y: %.6f%n", point[0], point[1]);
        }

        // Closing the scanner to release system resources
        scanner.close();
    }

    // Euler step method for calculating the next point
    public static double eulerStep(double xCurrent, double stepSize, double yCurrent, BiFunction<Double, Double, Double> differentialEquation) {
        if (stepSize <= 0) { // Checking if the step size is valid
            throw new IllegalArgumentException("stepSize should be greater than zero");
        }
        return yCurrent + stepSize * differentialEquation.apply(xCurrent, yCurrent); // Calculating the next y value using the Euler method
    }

    // Euler Full method for calculating all the points
    public static ArrayList<double[]> eulerFull(double xStart, double xEnd, double stepSize, double yStart, BiFunction<Double, Double, Double> differentialEquation) {
        if (xStart >= xEnd) { // Checking if xEnd is greater than xStart
            throw new IllegalArgumentException("xEnd should be greater than xStart");
        }
        if (stepSize <= 0) { // Checking if the step size is valid
            throw new IllegalArgumentException("stepSize should be greater than zero");
        }

        // Initializing an empty ArrayList to store the points
        ArrayList<double[]> points = new ArrayList<>();

        // Adding the initial point to the ArrayList
        points.add(new double[]{xStart, yStart});

        double yCurrent = yStart; // Initializing the current y value
        double xCurrent = xStart; // Initializing the current x value

        // Calculating all the remaining points using the Euler method
        while (xCurrent < xEnd) {
            yCurrent = eulerStep(xCurrent, stepSize, yCurrent, differentialEquation);
            xCurrent += stepSize;
            points.add(new double[]{xCurrent, yCurrent});
        }

        // Returning the ArrayList of points
        return points;
    }
}
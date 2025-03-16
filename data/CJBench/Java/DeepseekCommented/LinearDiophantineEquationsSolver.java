import java.util.Scanner;
import java.util.Objects;

public final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the user, representing the coefficients of the equation
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        
        // Create an Equation object using the input coefficients
        Equation toSolve = new Equation(a, b, c);
        
        // Find any solution for the given equation
        Solution solution = findAnySolution(toSolve);
        
        // Check the type of solution and print the appropriate message
        if (solution.equals(Solution.NO_SOLUTION)) {
            System.out.println("No solution exists.");
        } else if (solution.equals(Solution.INFINITE_SOLUTIONS)) {
            System.out.println("Infinite solutions exist.");
        } else {
            // Print the unique solution found
            System.out.println("One solution is: x = " + solution.getX() + ", y = " + solution.getY());
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }

    // Method to find any solution for the given equation
    public static Solution findAnySolution(final Equation equation) {
        // Check if the equation is of the form 0 = 0, which has infinite solutions
        if (equation.a() == 0 && equation.b() == 0 && equation.c() == 0) {
            return Solution.INFINITE_SOLUTIONS;
        }
        
        // Initialize a wrapper to hold GCD and a solution
        final var stub = new GcdSolutionWrapper(0, new Solution(0, 0));
        
        // Calculate the GCD of the coefficients and get a particular solution
        final var gcdSolution = gcd(equation.a(), equation.b(), stub);
        
        // Check if the equation has no solution based on the GCD
        if (equation.c() % gcdSolution.getGcd() != 0) {
            return Solution.NO_SOLUTION;
        }
        
        // Create a new solution object to return
        final var toReturn = new Solution(0, 0);
        
        // Calculate the specific solution based on the GCD and the input constant
        var xToSet = stub.getSolution().getX() * (equation.c() / stub.getGcd());
        var yToSet = stub.getSolution().getY() * (equation.c() / stub.getGcd());
        
        // Set the calculated values in the solution object
        toReturn.setX(xToSet);
        toReturn.setY(yToSet);
        
        // Return the found solution
        return toReturn;
    }

    // Recursive method to calculate the GCD of two integers and find a solution
    private static GcdSolutionWrapper gcd(final int a, final int b, final GcdSolutionWrapper previous) {
        // Base case: if b is 0, return the GCD and a solution
        if (b == 0) {
            return new GcdSolutionWrapper(a, new Solution(1, 0));
        }
        
        // Create a stub for the next recursive call
        final var stubWrapper = new GcdSolutionWrapper(0, new Solution(0, 0));
        
        // Recursive call to find the GCD
        final var next = gcd(b, a % b, stubWrapper);
        
        // Update the previous solution based on the results of the recursive call
        previous.getSolution().setX(next.getSolution().getY());
        previous.getSolution().setY(next.getSolution().getX() - (a / b) * (next.getSolution().getY()));
        previous.setGcd(next.getGcd());
        
        // Return the updated GCD and solution
        return new GcdSolutionWrapper(next.getGcd(), previous.getSolution());
    }

    // Inner class representing a solution to the equation
    public static final class Solution {
        // Constants representing special cases of solutions
        public static final Solution NO_SOLUTION = new Solution(Integer.MAX_VALUE, Integer.MAX_VALUE);
        public static final Solution INFINITE_SOLUTIONS = new Solution(Integer.MIN_VALUE, Integer.MIN_VALUE);
        
        // Variables to hold the solution values
        private int x;
        private int y;

        // Constructor to initialize the solution
        public Solution(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // Getter for x
        public int getX() {
            return x;
        }

        // Getter for y
        public int getY() {
            return y;
        }

        // Setter for x
        public void setX(int x) {
            this.x = x;
        }

        // Setter for y
        public void setY(int y) {
            this.y = y;
        }

        // Override equals method to compare solutions
        @Override
        public boolean equals(Object obj) {
            if (obj == this) {
                return true;
            }
            if (obj == null || obj.getClass() != this.getClass()) {
                return false;
            }
            var that = (Solution) obj;
            return this.x == that.x && this.y == that.y;
        }

        // Override hashCode method for proper hashing
        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        // Override toString method for easy representation
        @Override
        public String toString() {
            return "Solution["
                + "x=" + x + ", "
                + "y=" + y + ']';
        }
    }

    // Inner class representing the equation with coefficients
    public static class Equation {
        private final int a;
        private final int b;
        private final int c;

        // Constructor to initialize the equation coefficients
        public Equation(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        // Getter for coefficient a
        public int a() {
            return a;
        }

        // Getter for coefficient b
        public int b() {
            return b;
        }

        // Getter for coefficient c
        public int c() {
            return c;
        }
    }

    // Wrapper class to hold GCD and a corresponding solution
    public static final class GcdSolutionWrapper {
        private int gcd;
        private Solution solution;

        // Constructor to initialize the GCD and solution
        public GcdSolutionWrapper(int gcd, Solution solution) {
            this.gcd = gcd;
            this.solution = solution;
        }

        // Override equals method for comparison
        @Override
        public boolean equals(Object obj) {
            if (obj == this) {
                return true;
            }
            if (obj == null || obj.getClass() != this.getClass()) {
                return false;
            }
            var that = (GcdSolutionWrapper) obj;
            return (this.gcd == that.gcd && Objects.equals(this.solution, that.solution));
        }

        // Getter for GCD
        public int getGcd() {
            return gcd;
        }

        // Setter for GCD
        public void setGcd(int gcd) {
            this.gcd = gcd;
        }

        // Getter for solution
        public Solution getSolution() {
            return solution;
        }

        // Setter for solution
        public void setSolution(Solution solution) {
            this.solution = solution;
        }

        // Override hashCode method for proper hashing
        @Override
        public int hashCode() {
            return Objects.hash(gcd, solution);
        }

        // Override toString method for easy representation
        @Override
        public String toString() {
            return ("GcdSolutionWrapper["
                + "gcd=" + gcd + ", "
                + "solution=" + solution + ']');
        }
    }
}

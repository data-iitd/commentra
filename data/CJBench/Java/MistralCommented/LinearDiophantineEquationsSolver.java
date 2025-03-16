
import java.util.Scanner;
import java.util.Objects;

public final class Main {
    private Main() {
    }

    // Initialize Scanner to read input from the console
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read three integers a, b, and c from the user
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        // Create an Equation object with coefficients a, b, and constant c
        Equation toSolve = new Equation(a, b, c);

        // Find any solution for the given equation
        Solution solution = findAnySolution(toSolve);

        // Check the type of solution and print the result accordingly
        if (solution.equals(Solution.NO_SOLUTION)) {
            System.out.println("No solution exists.");
        } else if (solution.equals(Solution.INFINITE_SOLUTIONS)) {
            System.out.println("Infinite solutions exist.");
        } else {
            System.out.println("One solution is: x = " + solution.getX() + ", y = " + solution.getY());
        }

        // Close the Scanner to release system resources
        sc.close();
    }

    // Find any solution for the given equation using Euclidean algorithm
    public static Solution findAnySolution(final Equation equation) {
        // Check if the equation has infinite solutions (when all coefficients are zero)
        if (equation.a() == 0 && equation.b() == 0 && equation.c() == 0) {
            return Solution.INFINITE_SOLUTIONS;
        }

        // Initialize a helper object to store the gcd and the solution
        final var stubWrapper = new GcdSolutionWrapper(0, new Solution(0, 0));

        // Find the gcd of coefficients a and b using Euclidean algorithm
        final var gcdSolution = gcd(equation.a(), equation.b(), stubWrapper);

        // Check if there is a solution for the given equation
        if (equation.c() % gcdSolution.getGcd() != 0) {
            return Solution.NO_SOLUTION;
        }

        // Calculate the solution x and y using the extended Euclidean algorithm
        final var toReturn = new Solution(0, 0);
        var xToSet = stubWrapper.getSolution().getX() * (equation.c() / gcdSolution.getGcd());
        var yToSet = stubWrapper.getSolution().getY() * (equation.c() / gcdSolution.getGcd());
        toReturn.setX(xToSet);
        toReturn.setY(yToSet);

        return toReturn;
    }

    // Helper method to find the greatest common divisor (gcd) using Euclidean algorithm
    private static GcdSolutionWrapper gcd(final int a, final int b, final GcdSolutionWrapper previous) {
        // Base case: b equals zero, return the gcd and the solution
        if (b == 0) {
            return new GcdSolutionWrapper(a, new Solution(1, 0));
        }

        // Recursive case: apply the Euclidean algorithm to b and the remainder of a modulo b
        final var stubWrapper = new GcdSolutionWrapper(0, new Solution(0, 0));
        final var next = gcd(b, a % b, stubWrapper);

        // Update the previous solution with the new solution
        previous.getSolution().setX(next.getSolution().getY());
        previous.getSolution().setY(next.getSolution().getX() - (a / b) * next.getSolution().getY());
        previous.setGcd(next.getGcd());

        return new GcdSolutionWrapper(next.getGcd(), previous.getSolution());
    }

    // Class representing the solution of the equation
    public static final class Solution {
        // Singleton representing the case when there is no solution
        public static final Solution NO_SOLUTION = new Solution(Integer.MAX_VALUE, Integer.MAX_VALUE);

        // Singleton representing the case when there are infinite solutions
        public static final Solution INFINITE_SOLUTIONS = new Solution(Integer.MIN_VALUE, Integer.MIN_VALUE);

        // Store the solution's x and y components
        private int x;
        private int y;

        // Constructor
        public Solution(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // Getters for x and y components
        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        // Setters for x and y components
        public void setX(int x) {
            this.x = x;
        }

        public void setY(int y) {
            this.y = y;
        }

        // Override equals method to compare solutions based on their components
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

        // Override hashCode method to generate a hash based on x and y components
        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        // Override toString method to print the solution in a readable format
        @Override
        public String toString() {
            return "Solution["
                + "x=" + x + ", "
                + "y=" + y + ']';
        }
    }

    // Class representing the equation to be solved
    public static class Equation {
        // Store the coefficients a, b, and constant c
        private final int a;
        private final int b;
        private final int c;

        // Constructor
        public Equation(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        // Getters for coefficients a, b, and constant c
        public int a() {
            return a;
        }

        public int b() {
            return b;
        }

        public int c() {
            return c;
        }
    }

    // Class representing the gcd and the solution using extended Euclidean algorithm
    public static class GcdSolutionWrapper {
        // Store the gcd and the solution
        private int gcd;
        private Solution solution;

        // Constructor
        public GcdSolutionWrapper(int gcd, Solution solution) {
            this.gcd = gcd;
            this.solution = solution;
        }

        // Getters and setters for gcd and solution
        public int getGcd() {
            return gcd;
        }

        public void setGcd(int gcd) {
            this.gcd = gcd;
        }

        public Solution getSolution() {
            return solution;
        }

        public void setSolution(Solution solution) {
            this.solution = solution;
        }

        // Override equals method to compare GcdSolutionWrapper based on gcd and solution
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

        // Override hashCode method to generate a hash based on gcd and solution
        @Override
        public int hashCode() {
            return Objects.hash(gcd, solution);
        }

        // Override toString method to print the gcd and solution in a readable format
        @Override
        public String toString() {
            return ("GcdSolutionWrapper["
                + "gcd=" + gcd + ", "
                + "solution=" + solution + ']');
        }
    }
}
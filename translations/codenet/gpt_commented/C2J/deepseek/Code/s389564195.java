public class CubeCalculator {
    public static void main(String[] args) {
        // Declare an integer variable x for input
        int x;

        // Create a Scanner object to read input from the console
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Prompt the user to enter an integer value
        System.out.print("Enter an integer: ");
        x = scanner.nextInt();

        // Calculate the cube of the input value x
        int kotae = x * x * x;

        // Output the result (the cube of x) to the console
        System.out.println("The cube of " + x + " is " + kotae);

        // Close the scanner to free up resources
        scanner.close();
    }
}

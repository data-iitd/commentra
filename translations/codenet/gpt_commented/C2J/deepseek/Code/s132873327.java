public class CubeCalculator {
    public static void main(String[] args) {
        // Declare an integer variable to hold the input value
        int x;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read an integer value from the user and store it in variable x
        x = scanner.nextInt();

        // Calculate the cube of the input value and print the result
        System.out.println(x * x * x);

        // Return 0 to indicate that the program finished successfully
        return 0;
    }
}

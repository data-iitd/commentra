public class CubeCalculator {
    public static void main(String[] args) {
        // Declare an integer variable x
        int x;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read an integer value from the user and store it in variable x
        x = scanner.nextInt();

        // Calculate the cube of x and store the result in variable y
        int y = x * x * x;

        // Print the result (the cube of x) to the console
        System.out.println(y);

        // Close the Scanner object
        scanner.close();
    }
}

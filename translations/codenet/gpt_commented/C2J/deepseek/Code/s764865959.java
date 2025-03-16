public class Main {
    public static void main(String[] args) {
        // Declare an integer variable to hold the input value
        int x;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read an integer value from the user and store it in variable x
        x = scanner.nextInt();

        // Calculate the cube of the input value by multiplying it by itself twice
        x = x * x * x;

        // Print the result (the cube of the input value) to the console
        System.out.println(x);

        // Close the Scanner object to free up resources
        scanner.close();
    }
}

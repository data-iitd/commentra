public class Main {
    public static void main(String[] args) {
        // Initialize a counter variable 'i' to track the case number and an 'Input' variable to store user input
        int i = 1;

        // Start an infinite loop to continuously accept user input
        while (true) {
            // Read an integer input from the user
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            int Input = scanner.nextInt();

            // Check if the input is zero, which indicates the end of input
            if (Input == 0) {
                // Exit the loop if the input is zero
                break;
            }

            // Print the case number and the input value
            System.out.println("Case " + i + ": " + Input);

            // Increment the case number for the next iteration
            i++;
        }
    }
}

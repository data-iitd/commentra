public class Main {
    public static void main(String[] args) {
        // Declare and initialize variables
        int i = 1; // Initialize counter variable i to 1
        int Input = 0; // Declare variable to store user input

        while(true) {
            // Read user input and store it in the Input variable
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            Input = scanner.nextInt();

            // Check if user input is 0
            if(Input == 0) {
                // If user input is 0, break out of the loop
                break;
            }

            // Print the case number and user input
            System.out.println("Case " + i + ": " + Input);

            // Increment the counter variable i
            i++;
        }
    }
}

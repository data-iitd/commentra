public class Main {
    public static void main(String[] args) {
        // Declare variables for iteration, sum, and a flag
        int i, sum = 0;
        // No need for a flag as it's not used in the Java code
        String x; // String to store input strings

        // Read the first input string
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x = scanner.nextLine();

        // Loop to process input until the termination condition is met
        do {
            // Iterate through the characters of the input string
            for (i = 0; i < x.length(); i++) {
                // Check for the end of the string (empty string)
                if (i == x.length()) {
                    // Print the sum of the digits in the string
                    System.out.println(sum);
                    break; // Exit the loop if end of string is reached
                } else {
                    // Convert character to integer and add to sum
                    sum += x.charAt(i) - '0'; // '0' is represented by 0x30 in ASCII
                }
            }
            
            // Reset sum for the next input
            sum = 0;

            // Read the next input string
            x = scanner.nextLine();
        } while (!x.equals("0")); // Continue until the input string is '0'

        scanner.close(); // Close the scanner
    }
}

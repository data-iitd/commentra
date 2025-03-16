import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty string variable named 'source'
        String source = "";

        // Read a string input from the standard input stream (Scanner) and store it in the 'source' variable
        Scanner scanner = new Scanner(System.in);
        source = scanner.nextLine();

        // Check if the length of the input string is valid (greater than 10 characters or less than 1 character)
        if (source.length() > 10 || source.length() < 1) {
            // If the condition is true, return an error code (-1)
            System.exit(-1);
        }

        // Calculate the maximum value of 'i' based on the length of the input string using bitwise operations
        int max_i = (int) Math.pow(2, source.length() - 1);

        // Initialize a variable named 'sum' with a value of 0
        double sum = 0;

        // Iterate through the range of 'i' from 0 to 'max_i' using a for loop
        for (int i = 0; i < max_i; ++i) {
            // Create a bitset-like representation of 'i'
            String binaryString = String.format("%" + (source.length()) + "s", Integer.toBinaryString(i)).replace(' ', '0');

            // Initialize a variable named 'number' with a value of 0
            double number = 0;

            // Initialize a string variable named 'working' with the value of the input string 'source'
            String working = source;

            // Iterate through the bits of the binary string
            for (int j = 0; j < binaryString.length(); j++) {
                if (binaryString.charAt(j) == '1') {
                    // Add the substring of the 'working' string starting from the current index to the 'sum' variable
                    sum += Double.parseDouble(working.substring(0, j + 1));

                    // Update the value of the 'working' string by removing the substring that has been added to the 'sum' variable
                    working = working.substring(j + 1);
                }
            }

            // Add the remaining substring of the 'working' string to the 'sum' variable
            if (!working.isEmpty()) {
                sum += Double.parseDouble(working);
            }
        }

        // Set the precision of the output stream (System.out) to 0 decimal places
        System.out.printf("%.0f%n", sum);

        // Return 0 to indicate successful execution of the program
        scanner.close();
    }
}

// <END-OF-CODE>

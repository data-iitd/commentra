import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input numbers and intermediate values
        char[] inputNumbers = new char[4]; // Array to store input numbers as characters
        int a, b, c, d; // Variables to hold the individual numbers
        int sum; // Variable to hold the calculated sum
        char[] symbols = new char[3]; // Array to store the symbols used in the expression

        // Read a string of numbers from user input
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        inputNumbers = input.toCharArray();

        // Convert each character to an integer and store in respective variables
        a = Character.getNumericValue(inputNumbers[0]);
        b = Character.getNumericValue(inputNumbers[1]);
        c = Character.getNumericValue(inputNumbers[2]);
        d = Character.getNumericValue(inputNumbers[3]);

        // Iterate through all combinations of addition and subtraction for the four numbers
        for (int i = 0; i < 2; i++) { // Loop for the first operation (a + b or a - b)
            for (int j = 0; j < 2; j++) { // Loop for the second operation (result + c or result - c)
                for (int k = 0; k < 2; k++) { // Loop for the third operation (result + d or result - d)
                    // Determine the first operation (addition or subtraction with a and b)
                    if (i == 0) {
                        sum = a + b; // Perform addition
                        symbols[0] = '+'; // Store the symbol used
                    } else {
                        sum = a - b; // Perform subtraction
                        symbols[0] = '-'; // Store the symbol used
                    }

                    // Determine the second operation (addition or subtraction with c)
                    if (j == 0) {
                        sum = sum + c; // Perform addition
                        symbols[1] = '+'; // Store the symbol used
                    } else {
                        sum = sum - c; // Perform subtraction
                        symbols[1] = '-'; // Store the symbol used
                    }

                    // Determine the third operation (addition or subtraction with d)
                    if (k == 0) {
                        sum = sum + d; // Perform addition
                        symbols[2] = '+'; // Store the symbol used
                    } else {
                        sum = sum - d; // Perform subtraction
                        symbols[2] = '-'; // Store the symbol used
                    }

                    // Check if the calculated sum equals 7
                    if (sum == 7) {
                        // Print the expression that results in 7
                        System.out.printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d);
                        return; // Exit the program after finding the first valid expression
                    }
                }
            }
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>

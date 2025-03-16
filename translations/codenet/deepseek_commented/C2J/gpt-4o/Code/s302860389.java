import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Scanner to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Array to store the input numbers as characters
        char[] inputNumbers = new char[4];
        // Integer variables to store the digits
        int a, b, c, d;
        // Variable to store the intermediate results
        int sum;
        // Array to store the operators
        char[] symbols = new char[3];
        
        // Read a string of four characters from the input
        String input = scanner.nextLine();
        inputNumbers = input.toCharArray();

        // Extract each digit from inputNumbers and convert it to an integer
        a = Character.getNumericValue(inputNumbers[0]);
        b = Character.getNumericValue(inputNumbers[1]);
        c = Character.getNumericValue(inputNumbers[2]);
        d = Character.getNumericValue(inputNumbers[3]);
        
        // Nested loop structure to explore all combinations of addition and subtraction
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    // Choose the operation based on the value of i
                    if (i == 0) {
                        sum = a + b;
                        symbols[0] = '+';
                    } else {
                        sum = a - b;
                        symbols[0] = '-';
                    }

                    // Choose the operation based on the value of j
                    if (j == 0) {
                        sum = sum + c;
                        symbols[1] = '+';
                    } else {
                        sum = sum - c;
                        symbols[1] = '-';
                    }

                    // Choose the operation based on the value of k
                    if (k == 0) {
                        sum = sum + d;
                        symbols[2] = '+';
                    } else {
                        sum = sum - d;
                        symbols[2] = '-';
                    }

                    // Check if the sum equals 7
                    if (sum == 7) {
                        // Print the expression if the sum is 7
                        System.out.printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d);
                        
                        // Exit the program
                        return;
                    }
                }
            }
        }

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>

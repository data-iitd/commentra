import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare variables
        String inputNumbers;
        int a, b, c, d;
        int sum;
        char[] symbols = {'+', '+', '+'};

        // Read input numbers from user
        System.out.print("Enter four integers separated by spaces: ");
        inputNumbers = scanner.nextLine();

        // Extract each number from input string and convert to integer
        a = Integer.parseInt(inputNumbers.substring(0, 1));
        b = Integer.parseInt(inputNumbers.substring(1, 2));
        c = Integer.parseInt(inputNumbers.substring(2, 3));
        d = Integer.parseInt(inputNumbers.substring(3, 4));

        // Perform arithmetic operations and check for the sum equal to 7
        for (int i = 0; i < 2; i++) { // outer loop
            for (int j = 0; j < 2; j++) { // middle loop
                for (int k = 0; k < 2; k++) { // inner loop
                    // Assign symbols based on the position of current number
                    if (i == 0) {
                        sum = a + b;
                        symbols[0] = '+';
                    } else {
                        sum = a - b;
                        symbols[0] = '-';
                    }

                    if (j == 0) {
                        sum = sum + c;
                        symbols[1] = '+';
                    } else {
                        sum = sum - c;
                        symbols[1] = '-';
                    }

                    if (k == 0) {
                        sum = sum + d;
                        symbols[2] = '+';
                    } else {
                        sum = sum - d;
                        symbols[2] = '-';
                    }

                    // Check if the sum is equal to 7
                    if (sum == 7) {
                        System.out.printf("%d%c%d%c%d%c%d = 7\n", a, symbols[0], b, symbols[1], c, symbols[2], d);

                        // If sum is equal to 7, exit the loop and return 0
                        return;
                    }
                }
            }
        }

        // If no combination of four numbers results in a sum of 7, return 0
    }
}

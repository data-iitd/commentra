import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Read a string of four characters from the input
        Scanner sc = new Scanner(System.in);
        String inputNumbers = sc.next();

        // Initialize the second element of temp to the null character
        char temp[] = new char[2];
        temp[1] = '\0';

        // Extract each digit from inputNumbers and convert it to an integer
        temp[0] = inputNumbers.charAt(0);
        int a = Integer.parseInt(temp);
        temp[0] = inputNumbers.charAt(1);
        int b = Integer.parseInt(temp);
        temp[0] = inputNumbers.charAt(2);
        int c = Integer.parseInt(temp);
        temp[0] = inputNumbers.charAt(3);
        int d = Integer.parseInt(temp);

        // Nested loop structure to explore all combinations of addition and subtraction
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    // Choose the operation based on the value of i
                    if (i == 0) {
                        int sum = a + b;
                        char symbols[] = new char[3];
                        symbols[0] = '+';
                    } else {
                        int sum = a - b;
                        char symbols[] = new char[3];
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

                        // Exit the program with a return value of 0
                        return;
                    }
                }
            }
        }

        // Return 0 if no combination results in a sum of 7
        return;
    }
}


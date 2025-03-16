import java.util.Scanner;

public class ArithmeticOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] c = new int[256];
        int i = 0;

        // Initialize array c with zeros
        for (int j = 0; j < 256; j++) {
            c[j] = 0;
        }

        // Read input values of a, m, and b from the user
        while (true) {
            int a = scanner.nextInt();
            char m = scanner.next().charAt(0);
            int b = scanner.nextInt();

            // Check if the user has entered '?' to terminate the loop
            if (m == '?') {
                break;
            }

            // Perform arithmetic operations based on the operator m
            switch (m) {
                case '+':
                    c[i] = a + b; // Store the result of addition in the array c
                    break;
                case '-':
                    c[i] = a - b; // Store the result of subtraction in the array c
                    break;
                case '*':
                    c[i] = a * b; // Store the result of multiplication in the array c
                    break;
                case '/':
                    c[i] = a / b; // Store the result of division in the array c
                    break;
            }
            i++;
        }

        // Print the results of the arithmetic operations
        for (int j = 0; j < i; j++) {
            System.out.println(c[j]);
        }
    }
}

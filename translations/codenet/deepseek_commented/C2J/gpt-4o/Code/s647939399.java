import java.util.Scanner;  // Step 1: Import the Scanner class for input.

public class Main {  // Step 2: Define the main class.
    public static void main(String[] args) {  // Step 3: Define the main method.
        char m;  // Step 4: Declare a character variable 'm'.
        int a, b;  // Step 5: Declare two integers 'a' and 'b'.
        int[] c = new int[256];  // Step 6: Declare an array 'c' of size 256.
        int i = 0;  // Step 7: Initialize the index variable 'i'.

        Scanner scanner = new Scanner(System.in);  // Step 8: Create a Scanner object for input.

        while (true) {  // Step 9: Start an infinite loop.
            a = scanner.nextInt();  // Step 10: Read an integer 'a'.
            m = scanner.next().charAt(0);  // Step 11: Read a character 'm'.
            b = scanner.nextInt();  // Step 12: Read an integer 'b'.

            if (m == '?') {  // Step 13: Check if the character 'm' is '?'. If true, break the loop.
                break;
            }
            if (m == '+') {  // Step 14: Depending on the character 'm', perform the corresponding arithmetic operation and store the result in the array 'c' at index 'i'.
                c[i] = a + b;
            }
            if (m == '-') {
                c[i] = a - b;
            }
            if (m == '*') {
                c[i] = a * b;
            }
            if (m == '/') {
                c[i] = a / b;
            }
            i++;  // Increment the index variable 'i'.
        }

        for (int j = 0; j < i; j++) {  // Step 15: After the loop ends, start another loop to print the results stored in the array 'c' from index 0 to 'i-1'.
            System.out.println(c[j]);
        }

        scanner.close();  // Step 16: Close the scanner to prevent resource leaks.
    }  // End of main method.
}  // End of class.

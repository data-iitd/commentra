import java.util.Scanner;

public class SumOfDigits {
    public static void main(String[] args) {
        final int N = 1000;  // Define a constant N to represent the maximum size of the input array
        char[] su = new char[N];  // Declare a character array to store the input
        int susum = 0;       // Initialize a variable to hold the sum of the digits

        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input

        // Infinite loop to continuously read input until a specific condition is met
        while (true) {
            int j = 0;  // Initialize a counter variable for the loop

            // Loop to read characters into the array until a newline is encountered or the limit is reached
            while (j < N) {
                su[j] = scanner.next().charAt(0);  // Read a character from standard input
                if (su[j] == '\n') break;  // Break the loop if a newline character is encountered
                susum += (su[j] - '0');  // Convert the character to an integer and add it to the sum
                j++;
            }

            // Check if the first character is '0', which indicates the end of input
            if (su[0] == '0') break;  // Exit the loop if the first character is '0'

            System.out.println(susum);  // Print the sum of the digits read
            susum = 0;  // Reset the sum for the next input
        }

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>

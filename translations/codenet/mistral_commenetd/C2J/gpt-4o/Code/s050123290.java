import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int N = 1000; // Define a constant N with the value 1000
        char[] su = new char[N]; // Declare a character array 'su' of size N
        int susum = 0; // Initialize an integer variable 'susum' to zero

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        while (true) { // Start an infinite loop
            int j = 0; // Initialize an integer variable 'j' to zero
            while (j < N) { // Iterate through each index of the array 'su'
                su[j] = scanner.next().charAt(0); // Read a character from the standard input and store it in the array 'su' at the current index
                if (su[j] == '\n') break; // If the character read is a newline character, break out of the loop
                susum += (su[j] - '0'); // Add the ASCII value of the character (after subtracting '0') to the variable 'susum'
                j++;
            }
            if (su[0] == '0') break; // If the first character of the array 'su' is '0', break out of the loop
            System.out.println(susum); // Print the sum of the digits read from the standard input
            susum = 0; // Reset the variable 'susum' to zero for the next iteration
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>

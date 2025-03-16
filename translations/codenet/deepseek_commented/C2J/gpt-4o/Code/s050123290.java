import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // 1. Define the array and variables
        char[] su = new char[1000]; // Array to store the sequence of digits
        int susum = 0; // Variable to store the sum of the digits
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            // 2. Read input and calculate sum
            int j = 0;
            while (j < su.length) {
                su[j] = scanner.next().charAt(0); // Read a character
                if (su[j] == '\n') break; // Break if newline character is encountered
                if (su[j] == '0' && j == 0) return; // Break if the sequence starts with '0'
                susum += (su[j] - '0'); // Convert character to integer and add to sum
                j++;
            }
            // 3. Print the sum
            System.out.println(susum); // Print the sum of the digits
            susum = 0; // Reset the sum for the next sequence
        }
        // 4. Check for termination condition
    }
}
// <END-OF-CODE>

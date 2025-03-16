import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sum = 0;

        while (true) {
            String x = scanner.next(); // Read the first string from the input
            if (x.charAt(0) == '0') { // Check if the first character is '0'
                break; // Exit the loop if it is
            }

            sum = 0; // Reset the sum for the new string
            for (int i = 0; i < x.length(); i++) { // Loop through each character in the string
                sum += x.charAt(i) - '0'; // Convert the character to its corresponding digit and add it to the sum
            }
            System.out.println(sum); // Print the sum of the digits
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>

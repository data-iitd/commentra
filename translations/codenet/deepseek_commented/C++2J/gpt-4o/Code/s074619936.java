import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        String str; // Declare a string variable to store user input
        int sum; // Declare an integer variable to store the sum of digits

        // Infinite loop that continues until the user inputs "0"
        while (true) {
            str = scanner.nextLine(); // Read a string from the user
            if (str.equals("0")) break; // If the input string is "0", break the loop
            sum = 0; // Initialize sum to 0
            for (int i = 0; i < str.length(); i++) { // Loop through each character in the string
                char ch = str.charAt(i); // Get the character at index i
                int num = Character.getNumericValue(ch); // Convert the character to an integer
                sum += num; // Add the integer to the sum
            }

            System.out.println(sum); // Print the sum
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>

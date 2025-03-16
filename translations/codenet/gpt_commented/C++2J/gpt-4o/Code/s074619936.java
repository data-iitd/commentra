import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input string and the sum of digits
        Scanner scanner = new Scanner(System.in);
        String str;
        int sum;

        // Infinite loop to continuously accept input until "0" is entered
        while (true) {
            // Read input from the user
            str = scanner.nextLine();

            // Check if the input is "0", if so, exit the loop
            if (str.equals("0")) break;

            // Initialize sum to 0 for the new input string
            sum = 0;

            // Loop through each character in the input string
            for (int i = 0; i < str.length(); i++) {
                // Convert the character to an integer
                int num = Character.getNumericValue(str.charAt(i));

                // Add the integer value to the sum
                sum += num;
            }

            // Output the sum of the digits for the current input string
            System.out.println(sum);
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>

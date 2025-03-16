import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty string variable named 's'
        String s = "";

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read a string input from the user
        s = scanner.nextLine();

        // Declare a variable named 'price' with initial value 700
        int price = 700;

        // Iterate through each character 'c' in the string 's'
        for (char c : s.toCharArray()) {
            // Check if the current character 'c' is equal to 'o'
            if (c == 'o') {
                // If yes, add 100 to the 'price' variable
                price += 100;
            }
        }

        // Print the final value of 'price'
        System.out.println(price);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>

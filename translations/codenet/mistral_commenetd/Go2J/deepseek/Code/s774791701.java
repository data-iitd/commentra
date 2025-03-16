import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty string variable named 's'
        String s = "";

        // Read a string input from the user using Scanner
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();

        // Declare a variable named 'price' with initial value 700
        int price = 700;

        // Iterate through each character 'c' in the string 's' using a for loop
        for (char c : s.toCharArray()) {
            // Check if the current character 'c' is equal to 'o'
            if (c == 'o') {
                // If yes, add 100 to the 'price' variable
                price += 100;
            }
        }

        // Print the final value of 'price' using System.out.println()
        System.out.println(price);
    }
}

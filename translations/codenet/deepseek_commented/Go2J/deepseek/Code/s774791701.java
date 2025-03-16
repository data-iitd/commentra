import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        // Read input from the user and store it in the variable `s`
        String s = scanner.nextLine();

        // Initialize the price variable with a starting value of 700
        int price = 700;
        // Loop through each character in the string `s`
        for (char c : s.toCharArray()) {
            // Check if the current character is 'o'
            if (c == 'o') {
                // If the character is 'o', add 100 to the price
                price += 100;
            }
        }
        // Print the final value of the price
        System.out.println(price);
    }
}

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        // Initialize the base price
        int price = 700;
        
        // Iterate over each character in the input string
        for (char c : s.toCharArray()) {
            // Check if the character is 'o'
            if (c == 'o') {
                // If it is 'o', increase the price by 100
                price += 100;
            }
        }
        
        // Print the final price after processing the input string
        System.out.println(price);
        
        scanner.close();
    }
}

// <END-OF-CODE>

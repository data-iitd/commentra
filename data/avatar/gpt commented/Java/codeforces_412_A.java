import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Reading two integers n and k from user input
        int n = sc.nextInt(), k = sc.nextInt();
        
        // Reading a string a from user input
        String a = sc.next();
        
        // Check if k is greater than half of n
        if (k > n / 2) {
            // If true, move to the right until k equals n
            while (k < n) {
                System.out.println("RIGHT"); // Output "RIGHT" for each step to the right
                k++; // Increment k
            }
        } else {
            // If false, move to the left until k equals 1
            while (k > 1) {
                System.out.println("LEFT"); // Output "LEFT" for each step to the left
                k--; // Decrement k
            }
        }
        
        // If k equals 1, print the characters of the string from left to right
        if (k == 1) {
            for (int i = 0; i < a.length(); i++) {
                System.out.println("PRINT " + a.charAt(i)); // Print the current character
                // If not at the last character, output "RIGHT"
                if ((i + 1) < a.length()) {
                    System.out.println("RIGHT");
                }
            }
        } else {
            // If k is not 1, print the characters of the string from right to left
            for (int i = a.length() - 1; i >= 0; i--) {
                System.out.println("PRINT " + a.charAt(i)); // Print the current character
                // If not at the first character, output "LEFT"
                if ((i - 1) >= 0) {
                    System.out.println("LEFT");
                }
            }
        }
    }
}

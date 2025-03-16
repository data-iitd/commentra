import java.util.Scanner; // Importing the Scanner class to read input from the user

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input from the user
        int n = sc.nextInt(); // Reading the integer n from the user
        int k = sc.nextInt(); // Reading the integer k from the user
        String a = sc.next(); // Reading the string a from the user

        // Check if k is greater than n/2
        if (k > n / 2) {
            // Move right until k equals n
            while (k < n) {
                System.out.println("RIGHT"); // Print "RIGHT"
                k++; // Increment k
            }
        } else {
            // Move left until k equals 1
            while (k > 1) {
                System.out.println("LEFT"); // Print "LEFT"
                k--; // Decrement k
            }
        }

        // If k equals 1, print each character of the string a starting from the first character and moving rightwards
        if (k == 1) {
            for (int i = 0; i < a.length(); i++) {
                System.out.println("PRINT " + a.charAt(i)); // Print the character and then move right
                if ((i + 1) < a.length()) {
                    System.out.println("RIGHT"); // Print "RIGHT" if it's not the last character
                }
            }
        } else {
            // If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
            for (int i = a.length() - 1; i >= 0; i--) {
                System.out.println("PRINT " + a.charAt(i)); // Print the character and then move left
                if ((i - 1) >= 0) {
                    System.out.println("LEFT"); // Print "LEFT" if it's not the first character
                }
            }
        }
    }
}

import java.util.Scanner;

public class Main {
    // Function to determine group based on input number n
    public static String group(int n) {
        // Check if number belongs to group B
        if (n == 4 || n == 6 || n == 9 || n == 11) {
            return "B";
        } else {
            return "A";
        }
    }

    public static void main(String[] args) { // Main function
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int x = scanner.nextInt(); // Read input value of x
        int y = scanner.nextInt(); // Read input value of y

        // Check if either x or y is equal to 2
        if (x == 2 || y == 2) {
            System.out.println("No"); // If yes, print "No" and exit
            return;
        }

        String xg = group(x); // Determine group of number x
        String yg = group(y); // Determine group of number y

        // Check if both numbers belong to the same group
        if (xg.equals(yg)) {
            System.out.println("Yes"); // If yes, print "Yes"
        } else {
            System.out.println("No"); // If not, print "No"
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>

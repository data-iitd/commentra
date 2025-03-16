import java.util.Scanner; // Import the Scanner class to read input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object
        String str = scanner.next(); // Read a string input from the standard input and assign it to the 'str' variable

        // Check if the third and fourth characters of the string are identical
        if (str.charAt(2) == str.charAt(3)) {
            // If the condition is true, proceed to the next check
            if (str.charAt(4) == str.charAt(5)) { // Check if the fifth and sixth characters are identical
                System.out.println("Yes"); // If both conditions are true, print 'Yes' to the standard output
            } else {
                System.out.println("No"); // If not, print 'No' instead
            }
        }
    }
}

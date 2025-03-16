import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner in = new Scanner(System.in);
        
        // Reading a string input and converting it to a character array
        char[] n = in.next().toCharArray();
        
        // Initializing a boolean variable to track the state of the previous character
        boolean s = false;
        
        // Iterating through each character in the character array
        for (int i = 0; i < n.length; i++) {
            // Checking if the current character is a dot '.'
            if (n[i] == '.') {
                // If the previous character was also a dot, print 1 and reset the state
                if (s) {
                    System.out.print(1);
                    s = false; // Resetting the state
                } else {
                    // If the previous character was not a dot, print 0
                    System.out.print(0);
                }
            } else {
                // If the current character is not a dot
                if (s) {
                    // If the previous character was also not a dot, print 2 and reset the state
                    System.out.print(2);
                    s = false; // Resetting the state
                } else {
                    // If the previous character was a dot, set the state to true
                    s = true;
                }
            }
        }
        
        // Closing the Scanner object to prevent resource leaks
        in.close();
    }
}

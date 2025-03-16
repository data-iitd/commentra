import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read an integer from the input, calculate its remainder when divided by 500,
        // and compare it with another integer read from the input.
        // Print "Yes" if the remainder is less than or equal to the second integer, otherwise print "No".
        System.out.println(sc.nextInt() % 500 <= sc.nextInt() ? "Yes" : "No");
        
        // Close the scanner to prevent resource leaks (optional but good practice)
        sc.close();
    }
}

import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner in = new Scanner(System.in);
        
        // Read an integer K from the user, which represents the maximum length of the string to display
        int K = in.nextInt();
        
        // Read a string S from the user
        String S = in.next();
        
        // Check if the length of the string S is less than or equal to K
        if (S.length() <= K) {
            // If true, print the string S as it is
            System.out.println(S);
        } else {
            // If false, print the first K characters of S followed by "..."
            System.out.println(S.substring(0, K) + "...");
        }
        
        // Close the scanner to prevent resource leaks
        in.close();
    }
}

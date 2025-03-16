import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner to read input
        Scanner scanner = new Scanner(System.in);
        // Read input from the standard input and store it in the variable `s`
        String s = scanner.next();
        
        // Initialize a variable to count the number of '1's in the input string
        int ans = 0;
        // Iterate over each character in the string `s`
        for (char c : s.toCharArray()) {
            // Check if the character is '1'
            if (c == '1') {
                // Increment the count of '1's
                ans++;
            }
        }
        // Print the count of '1's to the standard output
        System.out.println(ans);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    // A very large number to represent infinity
    static final long INF = (long) 1e20;  
    // A small number to handle precision issues
    static final double EPS = 1.0 / 1e10;  
    // A large prime number used for modular arithmetic
    static final int MOD = 1000000007;  

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String s = scanner.nextLine();  // Read the input string
        int k = scanner.nextInt();  // Read the integer k
        scanner.close();  // Close the scanner

        int l = 0;  // Initialize a counter for leading '1's
        for (char c : s.toCharArray()) {  // Loop through each character in the string
            if (c != '1') {  // Check if the character is not '1'
                break;  // Exit the loop if a non-'1' character is found
            }
            l++;  // Increment the counter for each '1' found
        }
        
        if (l >= k) {  // Check if the number of leading '1's is greater than or equal to k
            System.out.println(1);  // Print 1 if true
        } else {
            System.out.println(s.charAt(l));  // Print the character at the position of the first non-'1' character
        }
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two strings S and T from standard input
        String S = scanner.nextLine();
        String T = scanner.nextLine();
        
        // Initialize a variable to keep track of the maximum number of matching characters
        int max = 0;
        
        // Iterate over each possible starting index in S where T can fit
        for (int i = 0; i <= S.length() - T.length(); i++) {
            // Initialize a counter for matching characters
            int c = 0;
            
            // Compare characters of T with the corresponding characters in S
            for (int j = 0; j < T.length(); j++) {
                if (S.charAt(i + j) == T.charAt(j)) {
                    c++; // Increment the counter for each matching character
                }
            }
            
            // Update the maximum count of matching characters if the current count is greater
            if (max < c) {
                max = c;
            }
        }
        
        // Output the number of characters in T that do not match with S
        System.out.println(T.length() - max);
        
        scanner.close();
    }
}

// <END-OF-CODE>

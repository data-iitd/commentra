import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Read the input values
        int n = scanner.nextInt(); // The integer `n` represents the length of the string `s`.
        String s = scanner.next(); // The string `s` is read from the standard input.
        
        // Step 2: Initialize a counter
        int cnt = 0; 
        
        // Step 3: Iterate through the string
        for (int i = 0; i < n; i++) { 
            cnt++; // Increment the counter for each distinct character
            int j = i + 1;
            
            // Step 4: Count distinct characters
            for (; j < n; j++) { 
                if (s.charAt(i) != s.charAt(j)) { // Check if the current character is different from the next one
                    break; // If a different character is found, break the inner loop
                }
            }
            // Step 5: Update the loop index
            i = j - 1; 
        }
        
        // Step 6: Output the result
        System.out.println(cnt); 
        scanner.close();
    }
}

// <END-OF-CODE>

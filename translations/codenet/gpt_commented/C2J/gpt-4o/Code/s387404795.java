import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare character arrays for input strings and temporary storage
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        String p = scanner.next();
        
        // Copy the original string into a temporary variable and concatenate it with itself
        String tmp = str;
        str = str + tmp;
        
        // Calculate the lengths of the concatenated string and the pattern string
        int slen = str.length();
        int plen = p.length();
        
        // Initialize a flag to indicate if the pattern is found
        boolean flag = false;
        
        // Loop through the concatenated string to search for the pattern
        for (int i = 0; i <= slen - plen; i++) {
            // Compare the substring of str with the pattern p
            if (str.substring(i, i + plen).equals(p)) {
                flag = true; // Set flag if a match is found
                break; // Exit the loop if a match is found
            }
        }
        
        // Output "Yes" if the pattern was found, otherwise output "No"
        if (flag) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>

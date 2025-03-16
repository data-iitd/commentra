import java.util.Scanner;

public class StringComparison {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first string from the user input
        String str1 = scanner.nextLine();
        // Read the second string from the user input
        String str2 = scanner.nextLine();
        
        // Check if the lengths of the two strings are not equal
        if (str1.length() != str2.length()) {
            // Print "NO" if the lengths are not equal
            System.out.println("NO");
        } else {
            // Reverse the first string
            StringBuilder temp = new StringBuilder(str1).reverse();
            
            // Compare the reversed string with the second string
            if (temp.toString().equals(str2)) {
                // Print "YES" if all characters match
                System.out.println("YES");
            } else {
                // Print "NO" if not all characters match
                System.out.println("NO");
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

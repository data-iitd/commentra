import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Declare two string variables, s and t
        String s;
        
        // Read a string from the standard input and store it in s
        s = scanner.nextLine();
        
        // Initialize t with the first character of s
        String t = String.valueOf(s.charAt(0));
        
        // Append the size of s minus 2 to t
        t += (s.length() - 2);
        
        // Append the last character of s to t
        t += s.charAt(s.length() - 1);
        
        // Print the modified string t
        System.out.println(t);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>

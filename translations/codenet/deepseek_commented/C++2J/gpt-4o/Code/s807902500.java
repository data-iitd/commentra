import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String s = scanner.next();
        String t = scanner.next(); // Read two strings from standard input
        
        // Concatenate s with itself to double its length
        s += s;
        
        // Check if t is a substring of the doubled s
        // If found, contains returns true; otherwise, it returns false
        System.out.println(s.contains(t) ? "Yes" : "No");
        
        scanner.close();
    }
}

// <END-OF-CODE>

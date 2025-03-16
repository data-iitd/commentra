import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two string variables s and t to store user input.
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        String t = scanner.next();
        
        // Concatenate the string s with itself and store the result back in s.
        s += s;

        // Check if the substring t is present in the string s. If it is, print "Yes" to the console. Otherwise, print "No".
        System.out.println(s.contains(t) ? "Yes" : "No");

        scanner.close();
    }
}

// <END-OF-CODE>

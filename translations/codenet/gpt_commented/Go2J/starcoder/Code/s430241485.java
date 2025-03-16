import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two string variables to hold input values
        String s, t;
        
        // Read two strings from standard input
        Scanner scanner = new Scanner(System.in);
        s = scanner.next();
        t = scanner.next();
        
        // Print the concatenation of the second string followed by the first string
        System.out.println(t + s);
    }
}

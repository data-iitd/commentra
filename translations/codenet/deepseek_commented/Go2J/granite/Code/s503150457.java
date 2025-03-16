
import java.util.Scanner;

public class s503150457{
    public static void main(String[] args) {
        // Declare three string variables to hold the input values
        String s1, s2, s3;

        // Create a Scanner object to read input values from the standard input
        Scanner scanner = new Scanner(System.in);

        // Read input values for s1, s2, and s3 from the standard input
        s1 = scanner.next();
        s2 = scanner.next();
        s3 = scanner.next();

        // Split each input string into individual characters
        char[] s1s = s1.toCharArray();
        char[] s2s = s2.toCharArray();
        char[] s3s = s3.toCharArray();

        // Print the uppercase version of the first character of each input string
        System.out.println(Character.toUpperCase(s1s[0]) + Character.toUpperCase(s2s[0]) + Character.toUpperCase(s3s[0]));
    }
}

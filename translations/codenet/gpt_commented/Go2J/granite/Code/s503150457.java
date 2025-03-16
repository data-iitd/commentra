
import java.util.Scanner;

public class s503150457{
    public static void main(String[] args) {
        // Declare three string variables to hold user input
        String s1, s2, s3;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read three strings from standard input
        s1 = scanner.next();
        s2 = scanner.next();
        s3 = scanner.next();

        // Split each string into a character array
        char[] s1Array = s1.toCharArray();
        char[] s2Array = s2.toCharArray();
        char[] s3Array = s3.toCharArray();

        // Convert the first character of each string to uppercase and concatenate them
        String result = String.valueOf(Character.toUpperCase(s1Array[0])).concat(String.valueOf(Character.toUpperCase(s2Array[0])).concat(String.valueOf(Character.toUpperCase(s3Array[0]));

        // Print the concatenated result
        System.out.println(result);
    }
}

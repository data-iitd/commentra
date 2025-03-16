
import java.util.Scanner;

public class s278875041{
    public static void main(String[] args) {
        // Declare a string variable to hold user input
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine();
        
        // Replace all occurrences of "1" with "0" in the string `a`
        String tmp = a.replaceAll("1", "0");
        
        // Store the result of the first replacement in a temporary variable `tmp`
        // Replace all occurrences of "9" with "1" in the string `tmp`
        String b = tmp.replaceAll("9", "1");
        
        // Store the result of the second replacement in the variable `b`
        // Replace all occurrences of "0" with "9" in the string `b`
        String ans = b.replaceAll("0", "9");
        
        // Print the final result to the console
        System.out.println(ans);
    }
}

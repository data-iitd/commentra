
import java.util.Scanner;

public class s894183124{
    public static void main(String[] args) {
        // Declare variables to hold the integer input and the string input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        
        // Count the occurrences of the substring "ABC" in the input string
        // and print the result
        int count = 0;
        for (int i = 0; i <= s.length() - 3; i++) {
            if (s.substring(i, i + 3).equals("ABC")) {
                count++;
            }
        }
        System.out.println(count);
    }
}

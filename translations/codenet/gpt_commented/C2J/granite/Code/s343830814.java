
import java.util.Scanner;

public class s343830814{
    public static void main(String[] args) {
        // Declare a buffer to hold the input string and an integer to store its length
        Scanner scanner = new Scanner(System.in);
        String buf = scanner.nextLine();
        int len = buf.length();

        // Print the first character, the length of the string minus 3, and the second to last character
        System.out.printf("%c%d%c\n", buf.charAt(0), len-3, buf.charAt(len-2));

        // Return 0 to indicate successful completion of the program
        System.exit(0);
    }
}

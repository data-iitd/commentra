import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a Scanner object to read input from stdin
        Scanner in = new Scanner(System.in);

        // Read a line of input from stdin into a String
        String buf = in.nextLine();

        // Calculate the length of the input string
        int len = buf.length();

        // Print the first character, the length of the string minus 3, and the second to last character
        System.out.printf("%c%d%c\n", buf.charAt(0), len-3, buf.charAt(len-2));
    }
}

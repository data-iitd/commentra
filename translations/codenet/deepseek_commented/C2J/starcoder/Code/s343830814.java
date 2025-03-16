import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 1: Declare a Scanner object
        Scanner input = new Scanner(System.in);

        // Step 2: Read input from stdin
        String buf = input.nextLine();

        // Step 3: Calculate the length of the input
        int len = buf.length();

        // Step 4: Print the first character, the length minus 3, and the second last character of the input
        System.out.printf("%c%d%c\n", buf.charAt(0), len-3, buf.charAt(len-2));

        // Step 5: Close the Scanner object
        input.close();
    }
}


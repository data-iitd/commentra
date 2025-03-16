import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("\n");
        String s = sc.next();

        // Define the difference between lowercase and uppercase ASCII values
        int d = 'a' - 'A';

        // Iterate over each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char r = s.charAt(i);
            // Check if the character is an uppercase letter
            if ('A' <= r && r <= 'Z') {
                // Convert uppercase to lowercase
                r = (char) (r + d);
            } else if ('a' <= r && r <= 'z') {
                // Convert lowercase to uppercase
                r = (char) (r - d);
            }
            // Print the converted character
            System.out.print(r);
        }
        System.out.println();
    }
}


import java.util.Scanner;

public class s876834921{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine(); // Step 1: Reading Input - The program starts by declaring a string variable `s` and using `Scanner` to read input from the user.

        s = s.replaceAll("dream", "D"); // Step 2: Replacing Substrings - The program replaces occurrences of "dream" with "D" and "erase" with "E".
        s = s.replaceAll("erase", "E");

        s = s.replaceAll("Der", ""); // Step 3: Removing Modified Substrings - The program further replaces occurrences of "Der", "Er", "D", and "E" with an empty string.
        s = s.replaceAll("Er", "");
        s = s.replaceAll("D", "");
        s = s.replaceAll("E", "");

        s = s.trim(); // Step 4: Trimming Spaces - The program removes any leading or trailing whitespace from the string.

        if (s.isEmpty()) { // Step 5: Checking for Emptiness - The program checks if the string `s` is empty and prints "YES" or "NO" accordingly.
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}

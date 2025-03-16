import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Replace all occurrences of the substrings "dream" and "erase" with "D" and "E" respectively
        s = s.replace("dream", "D");
        s = s.replace("erase", "E");

        // Remove the substrings "Der" and "Er" from the string 's'
        s = s.replace("Der", "");
        s = s.replace("Er", "");

        // Remove leading and trailing spaces from the string 's'
        s = s.trim();

        // Check if the string 's' is empty or not
        if (s.isEmpty()) {
            // Print "YES" if the string 's' is empty
            System.out.println("YES");
        } else {
            // Print "NO" if the string 's' is not empty
            System.out.println("NO");
        }
    }
}


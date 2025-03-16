import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine(); // Step 1: Reading Input

        s = s.replace("dream", "D"); // Step 2: Replacing Substrings
        s = s.replace("erase", "E");

        s = s.replace("Der", ""); // Step 3: Removing Modified Substrings
        s = s.replace("Er", "");
        s = s.replace("D", "");
        s = s.replace("E", "");

        s = s.trim(); // Step 4: Trimming Spaces

        if (s.isEmpty()) { // Step 5: Checking for Emptiness
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        scanner.close();
    }
}

// <END-OF-CODE>

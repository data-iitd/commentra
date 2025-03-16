import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first string from the standard input
        String S = scanner.next();

        // Check if the string starts with "YAKI"
        if (S.startsWith("YAKI")) {
            System.out.println("Yes"); // Print "Yes" if the condition is true
        } else {
            System.out.println("No"); // Print "No" if the condition is false
        }
    }
}


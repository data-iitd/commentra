import java.util.Scanner;

public class StringComparison {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare variables
        int n; // number of strings to be compared
        int taro = 0; // score for Taro
        int hanako = 0; // score for Hanako

        // Read the number of strings to be compared from the standard input
        n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Initialize arrays for t and h
        String[] t = new String[n];
        String[] h = new String[n];

        // Initialize the loops for t and h arrays
        for (int i = 0; i < n; i++) {
            // Read strings from the standard input and store them in t and h arrays
            t[i] = scanner.nextLine();
            h[i] = scanner.nextLine();

            // Compare the strings and update the scores accordingly
            if (t[i].compareTo(h[i]) < 0) {
                hanako += 3; // Hanako gets 3 points if the current string in t is smaller than the corresponding string in h
            } else if (t[i].compareTo(h[i]) > 0) {
                taro += 3; // Taro gets 3 points if the current string in t is larger than the corresponding string in h
            } else { // If the strings are equal
                taro += 1; // Taro gets 1 point if the strings are equal
                hanako += 1; // Hanako gets 1 point if the strings are equal
            }
        }

        // Print the scores for Taro and Hanako
        System.out.println(taro + " " + hanako);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>

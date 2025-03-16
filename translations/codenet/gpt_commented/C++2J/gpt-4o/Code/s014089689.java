import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a Scanner object for user input
        Scanner scanner = new Scanner(System.in);

        // Read the length of the string from user input
        int n = scanner.nextInt();

        // Read the string from user input
        String s = scanner.next();

        // Initialize a counter to count the number of distinct segments
        int cnt = 0;

        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            // Increment the counter for each new segment found
            cnt++;

            // Initialize a variable j to find the end of the current segment
            int j = i + 1;

            // Continue moving j forward as long as the characters are the same
            for (; j < n; j++) {
                // If the current character is different from the next character, break the loop
                if (s.charAt(i) != s.charAt(j)) {
                    break;
                }
            }

            // Move i to the end of the current segment
            i = j - 1;
        }

        // Output the total count of distinct segments
        System.out.println(cnt);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>

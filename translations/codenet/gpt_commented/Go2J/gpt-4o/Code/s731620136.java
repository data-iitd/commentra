import java.util.Scanner;

public class Main {
    // Method to run the logic of the program
    public static int run(Scanner sc) {
        int N = sc.nextInt(); // Read the number of elements
        String S = sc.next(); // Read the string of colors

        // Handle case where there are no elements
        if (N == 0) {
            return 0;
        }

        // If there are fewer than 4 elements, output 0
        if (N < 4) {
            System.out.println(0);
            return 0;
        }

        // Count occurrences of each color
        int nr = 0, nb = 0, ng = 0;
        for (char c : S.toCharArray()) {
            if (c == 'R') {
                nr++;
            } else if (c == 'B') {
                nb++;
            } else if (c == 'G') {
                ng++;
            }
        }

        int same = 0; // Counter for same color combinations

        // Iterate through possible combinations of indices
        for (int a = 1; a < N; a++) {
            int i = 0;
            int j = 1 * a;
            int k = 2 * a;
            if (k >= N) {
                break; // Exit if index exceeds string length
            }
            while (k < N) {
                // Check if the colors at the indices are different
                if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
                    same++; // Increment same color combination counter
                }
                i++; // Move to the next index
                j++;
                k++;
            }
        }

        // Calculate total combinations of different colors
        int tot = nr * nb * ng;

        // Output the result by subtracting same combinations from total
        System.out.println(tot - same);

        return 0; // Return success
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        run(sc); // Run the program
        sc.close(); // Close the scanner
    }
}

// <END-OF-CODE>

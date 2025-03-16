import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int result = run(scanner);
        System.exit(result);
    }

    private static int run(Scanner scanner) {
        int N = scanner.nextInt(); // Read the first integer from input

        if (N < 4) { // Check if N is less than 4
            System.out.println(0); // Print 0 if N is less than 4
            return 0; // Return 0
        }

        String S = scanner.next(); // Read the string S
        int nr = 0, nb = 0, ng = 0; // Declare and initialize variables for red, blue, and green balls

        for (char c : S.toCharArray()) { // Iterate through each character in the string S
            if (c == 'R') {
                nr++; // Increment the nr counter
            } else if (c == 'B') {
                nb++; // Increment the nb counter
            } else if (c == 'G') {
                ng++; // Increment the ng counter
            }
        }

        int same = 0; // Initialize a counter for the number of same-colored groups of three balls

        // Outer loop
        for (int a = 1; a < N; a++) { // Iterate through each index a from 1 to N-1
            int i = 0; // Initialize index i to 0
            int j = 1 * a; // Initialize index j to a multiplied by 1
            int k = 2 * a; // Initialize index k to a multiplied by 2

            // Inner loop
            while (k < N) { // Iterate through each index k from a*2 to N-1
                // Check if the balls at indices i, j, and k have different colors
                if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
                    same++; // If so, increment the same counter
                }

                // Update indices
                i += 1; // Increment index i
                j += 1; // Increment index j
                k += 1; // Increment index k
            }
        }

        int tot = nr * nb * ng; // Calculate the total number of balls

        System.out.println(tot - same); // Print the result, which is the total number of balls minus the number of same-colored groups of three balls

        return 0; // Return 0 to indicate successful execution
    }
}

// <END-OF-CODE>

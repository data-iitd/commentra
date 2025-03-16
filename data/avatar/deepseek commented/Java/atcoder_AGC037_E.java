import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input
        try {
            final int N = sc.nextInt(); // Read the integer N
            int K = sc.nextInt(); // Read the integer K
            StringBuilder S = new StringBuilder(sc.next()); // Read the string S and wrap it in a StringBuilder
            boolean firstTime = true; // Initialize a flag to check if it's the first time through the loop
            int step = 1; // Initialize the step size

            // Main loop to manipulate the string based on the value of K
            while (K > 0) {
                StringBuilder T = new StringBuilder(S.toString()); // Create a copy of S
                T.reverse(); // Reverse the copy
                StringBuilder revU = new StringBuilder(S.toString() + T.toString()); // Concatenate S with its reverse
                revU.reverse(); // Reverse the concatenated string
                String sDash = S.toString(); // Initialize sDash with the original string S

                // Iterate over the reversed concatenated string to find the best substring
                for (int i = N; i >= 0; i -= step) {
                    String tmp = revU.substring(i, i + N); // Get a substring of length N
                    if (sDash.compareTo(tmp) > 0) { // Compare lexicographically
                        sDash = tmp; // Update sDash if a better substring is found
                    } else {
                        if (!firstTime) { // If it's not the first time, break the loop
                            break;
                        }
                    }
                }

                // Check if it's the first time through the loop
                if (firstTime) {
                    firstTime = false; // Set the flag to false
                    if (Math.pow(2, K) > N) { // Check the power of 2 of K
                        char c = sDash.charAt(0); // Get the first character of sDash
                        for (int i = 0; i < N; i++) { // Print the character N times
                            System.out.print(c);
                        }
                        System.out.println(); // Print a newline
                        System.exit(0); // Exit the program
                    }
                } else {
                    step += step; // Double the step size
                }
                K--; // Decrement K
                S = new StringBuilder(sDash); // Update S with the best substring found
                S.reverse(); // Reverse S
            }
            System.out.println(S.reverse()); // Print the final reversed string S
        } finally {
            sc.close(); // Close the Scanner object
        }
    }
}

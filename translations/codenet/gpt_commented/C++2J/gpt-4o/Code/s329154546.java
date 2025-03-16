import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of strings (N) and the length of each string (L)
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Declare an array to hold the strings
        String[] S = new String[N];

        // Input the strings from the user
        for (int i = 0; i < N; i++) {
            S[i] = scanner.nextLine();
        }

        // Sort the array of strings in lexicographical order
        Arrays.sort(S);

        // Output the sorted strings
        for (int i = 0; i < N; i++) {
            System.out.print(S[i]);
        }

        // Print a newline at the end of the output
        System.out.println();
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>

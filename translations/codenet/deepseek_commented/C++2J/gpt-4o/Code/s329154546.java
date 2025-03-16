import java.util.*; // Import the utility package for various utility classes

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int N = scanner.nextInt(); // Read the number of strings
        int L = scanner.nextInt(); // Read the length of each string
        String[] S = new String[N]; // Declare an array to store the strings
        
        for (int i = 0; i < N; i++) {
            S[i] = scanner.next(); // Read each string and store it in the array
        }
        
        Arrays.sort(S); // Sort the array of strings alphabetically
        
        for (int i = 0; i < N; i++) {
            System.out.print(S[i]); // Output each sorted string
        }
        
        System.out.println(); // Output a newline character
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>

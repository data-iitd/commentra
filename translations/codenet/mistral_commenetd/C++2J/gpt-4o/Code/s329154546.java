import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int N = scanner.nextInt(); // Read the number of strings
        int L = scanner.nextInt(); // Read the length of the strings (not used in this code)
        String[] S = new String[N]; // Declare an array of strings of size N
        
        for (int i = 0; i < N; i++) {
            S[i] = scanner.next(); // Read each string from the user and store it in the array S
        }
        
        Arrays.sort(S); // Sort the strings in ascending order
        
        for (String s : S) {
            System.out.print(s); // Print each sorted string to the console
        }
        
        System.out.println(); // Print an empty line at the end
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>

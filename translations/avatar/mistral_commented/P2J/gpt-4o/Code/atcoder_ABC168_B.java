import java.util.Scanner;

public class Main {

    // Define the main method
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the integer K from the standard input
        int K = scanner.nextInt();
        // Consume the newline character after the integer input
        scanner.nextLine();

        // Read a string S from the standard input
        String S = scanner.nextLine();

        // Call the processString method and print its result
        System.out.println(processString(K, S));
        
        // Close the scanner
        scanner.close();
    }

    // Define a method to process the string based on the length
    public static String processString(int K, String S) {
        // Check if the length of the string S is less than or equal to K
        if (S.length() <= K) {
            // If the condition is true, return the string S
            return S;
        }
        // If the condition is false, return a slice of the string S
        // from the beginning to the index K, followed by three dots '...'
        return S.substring(0, K) + "...";
    }
}

// <END-OF-CODE>

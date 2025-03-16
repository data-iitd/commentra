import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the number of test cases

        int acCount = 0; // Initialize a variable to count AC submissions
        int waCount = 0; // Initialize a variable to count WA submissions
        int tleCount = 0; // Initialize a variable to count TLE submissions
        int reCount = 0; // Initialize a variable to count RE submissions

        // Loop through each test case
        for (int i = 0; i < n; i++) {
            String s = scanner.next(); // Read the result of a test case
            if (s.equals("AC")) { // Check if the result is AC
                acCount++; // Increment the AC count
            } else if (s.equals("WA")) { // Check if the result is WA
                waCount++; // Increment the WA count
            } else if (s.equals("TLE")) { // Check if the result is TLE
                tleCount++; // Increment the TLE count
            } else if (s.equals("RE")) { // Check if the result is RE
                reCount++; // Increment the RE count
            }
        }

        // Print the counts of each result type
        System.out.println("AC x " + acCount);
        System.out.println("WA x " + waCount);
        System.out.println("TLE x " + tleCount);
        System.out.println("RE x " + reCount);
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class SubmissionResults {
    public static void main(String[] args) {
        // Declare a variable to hold the number of submissions
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of submissions from the user

        // Initialize counters for different result types
        int acCount = 0; // Count of Accepted submissions
        int waCount = 0; // Count of Wrong Answer submissions
        int tleCount = 0; // Count of Time Limit Exceeded submissions
        int reCount = 0; // Count of Runtime Error submissions

        // Loop through each submission
        for (int i = 0; i < n; ++i) {
            String s = scanner.next(); // Variable to hold the result of the current submission

            // Increment the respective counter based on the result
            if (s.equals("AC")) {
                acCount++; // Increment Accepted count
            } else if (s.equals("WA")) {
                waCount++; // Increment Wrong Answer count
            } else if (s.equals("TLE")) {
                tleCount++; // Increment Time Limit Exceeded count
            } else if (s.equals("RE")) {
                reCount++; // Increment Runtime Error count
            }
        }

        // Output the counts of each result type
        System.out.println("AC x " + acCount); // Display Accepted count
        System.out.println("WA x " + waCount); // Display Wrong Answer count
        System.out.println("TLE x " + tleCount); // Display Time Limit Exceeded count
        System.out.println("RE x " + reCount); // Display Runtime Error count

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class ContestResults {
    public static void main(String[] args) {
        // Initialize variables to store the number of each contest result
        int n; // number of contest results to be read
        int acCount = 0; // number of AC (Accepted) results
        int waCount = 0; // number of WA (Wrong Answer) results
        int tleCount = 0; // number of TLE (Time Limit Exceeded) results
        int reCount = 0; // number of RE (Runtime Error) results

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of contest results from the standard input
        n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Read each contest result and update the corresponding counter
        for (int i = 0; i < n; ++i) {
            String s = scanner.nextLine(); // string to store the contest result (AC, WA, TLE, or RE)
            if (s.equals("AC")) { // if the contest result is AC
                acCount++; // increment the number of AC results
            } else if (s.equals("WA")) { // if the contest result is WA
                waCount++; // increment the number of WA results
            } else if (s.equals("TLE")) { // if the contest result is TLE
                tleCount++; // increment the number of TLE results
            } else if (s.equals("RE")) { // if the contest result is RE
                reCount++; // increment the number of RE results
            }
        }

        // Print the number of each contest result to the standard output
        System.out.println("AC x " + acCount);
        System.out.println("WA x " + waCount);
        System.out.println("TLE x " + tleCount);
        System.out.println("RE x " + reCount);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>

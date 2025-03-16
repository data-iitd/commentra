import java.util.Scanner;

public class ContestResults {
    // Initialize variables to store the number of each contest result
    static int n; // number of contest results to be read
    static int ac_count = 0; // number of AC (Accepted) results
    static int wa_count = 0; // number of WA (Wrong Answer) results
    static int tle_count = 0; // number of TLE (Time Limit Exceeded) results
    static int re_count = 0; // number of RE (Runtime Error) results

    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);

        // Read the number of contest results from the standard input
        n = scanner.nextInt();

        // Read each contest result and update the corresponding counter
        for (int i = 0; i < n; ++i) {
            String s = scanner.next(); // string to store the contest result (AC, WA, TLE, or RE)
            if (s.equals("AC")) { // if the contest result is AC
                ac_count += 1; // increment the number of AC results
            } else if (s.equals("WA")) { // if the contest result is WA
                wa_count += 1; // increment the number of WA results
            } else if (s.equals("TLE")) { // if the contest result is TLE
                tle_count += 1; // increment the number of TLE results
            } else if (s.equals("RE")) { // if the contest result is RE
                re_count += 1; // increment the number of RE results
            }
        }

        // Print the number of each contest result to the standard output
        System.out.println("AC x " + ac_count);
        System.out.println("WA x " + wa_count);
        System.out.println("TLE x " + tle_count);
        System.out.println("RE x " + re_count);
    }
}

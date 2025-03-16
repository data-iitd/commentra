import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the number of submissions
        int n;
        // Read the number of submissions from the user
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Initialize counters for different result types
        int ac_count = 0; // Count of Accepted submissions
        int wa_count = 0; // Count of Wrong Answer submissions
        int tle_count = 0; // Count of Time Limit Exceeded submissions
        int re_count = 0; // Count of Runtime Error submissions

        // Loop through each submission
        for (int i = 0; i < n; ++i) {
            String s; // Variable to hold the result of the current submission
            // Read the result of the current submission
            s = sc.next();

            // Increment the respective counter based on the result
            if (s.equals("AC")) {
                ac_count += 1; // Increment Accepted count
            } else if (s.equals("WA")) {
                wa_count += 1; // Increment Wrong Answer count
            } else if (s.equals("TLE")) {
                tle_count += 1; // Increment Time Limit Exceeded count
            } else if (s.equals("RE")) {
                re_count += 1; // Increment Runtime Error count
            }
        }

        // Output the counts of each result type
        System.out.println("AC x " + ac_count); // Display Accepted count
        System.out.println("WA x " + wa_count); // Display Wrong Answer count
        System.out.println("TLE x " + tle_count); // Display Time Limit Exceeded count
        System.out.println("RE x " + re_count); // Display Runtime Error count
    }
}

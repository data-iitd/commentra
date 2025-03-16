import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in);
        
        // Read the number of segments (n) from input
        int n = in.nextInt();
        
        // Initialize arrays to store the travel times, start times, and frequencies
        int[] c = new int[n - 1]; // Array to hold travel times
        int[] s = new int[n - 1]; // Array to hold start times
        int[] f = new int[n - 1]; // Array to hold frequencies

        // Read the travel times, start times, and frequencies for each segment
        for (int i = 0; i < n - 1; i++) {
            c[i] = in.nextInt(); // Travel time for segment i
            s[i] = in.nextInt(); // Start time for segment i
            f[i] = in.nextInt(); // Frequency for segment i
        }

        // Calculate the total time for each segment
        for (int i = 0; i < n - 1; i++) {
            // Initialize the time with the start time plus travel time for the current segment
            int time = s[i] + c[i];
            
            // Iterate through the subsequent segments to calculate the total time
            for (int j = i + 1; j < n - 1; j++) {
                // Adjust the time to the next available frequency if not already aligned
                if (time % f[j] != 0) {
                    time += f[j] - (time % f[j]);
                }

                // If the adjusted time is less than the start time of the next segment, update it
                if (time < s[j]) {
                    time = s[j];
                }

                // Add the travel time for the next segment
                time += c[j];
            }

            // Output the total time after processing all segments from the current starting segment
            System.out.println(time);
        }
        
        // Print 0 at the end of processing
        System.out.println(0);
    }
}

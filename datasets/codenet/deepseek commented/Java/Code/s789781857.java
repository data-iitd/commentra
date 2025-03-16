import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); // Read the number of stations
        int[] c = new int[n - 1]; // Array to store travel times between stations
        int[] s = new int[n - 1]; // Array to store starting times of trains
        int[] f = new int[n - 1]; // Array to store frequencies of trains

        // Read the travel times, starting times, and frequencies for each station
        for (int i = 0; i < n - 1; i++) {
            c[i] = in.nextInt();
            s[i] = in.nextInt();
            f[i] = in.nextInt();
        }

        // Iterate over each station (except the last one) to calculate travel times
        for (int i = 0; i < n - 1; i++) {
            int time = s[i] + c[i]; // Initial time to reach the next station
            // Iterate over the next stations to calculate the exact arrival time
            for (int j = i + 1; j < n - 1; j++) {
                if (time % f[j] != 0) {
                    // If the current time does not match the train frequency, wait for the next train
                    time += f[j] - (time % f[j]);
                }

                if (time < s[j]) {
                    // If the current time is earlier than the starting time of the next train, wait until the next train starts
                    time = s[j];
                }

                // Add the travel time to the next station
                time += c[j];
            }

            // Print the time to reach the next station
            System.out.println(time);
        }
        // Print 0 to indicate the end of the journey
        System.out.println(0);
    }
}

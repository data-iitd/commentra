// Import necessary Java utility classes
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

// Main class with a main method
public class Main {

    // Main method to start the program
    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);

        // Read the number of activities N and the time limit T from the console
        int N = sc.nextInt();
        int T = sc.nextInt();

        // Initialize a 2D array AB to store the start time and value of each activity
        int[][] AB = new int[N][2];

        // Read the start time and value of each activity from the console and store it in the AB array
        for (int i = 0; i < N; i++) {
            AB[i][0] = sc.nextInt(); // Read the start time of activity i
            AB[i][1] = sc.nextInt(); // Read the value of activity i
        }

        // Sort the AB array based on the start time of each activity
        Arrays.sort(AB, Comparator.comparingInt(a -> a[0]));

        // Initialize a 2D array dp to store the maximum value that can be obtained up to a certain time after eating an activity
        int[][] dp = new int[N + 1][6001];

        // For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
        for (int i = 1; i <= N; i++) {
            for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
                // Set the value of dp[i][timeAfterEat] to be the maximum of its previous value and the value obtained by eating the activity i at timeAfterEat
                dp[i][timeAfterEat] = Math.max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]);

                // If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat] with the maximum value that can be obtained by eating activity i at timeAfterEat and adding the value of the activity to the previous value
                int time = AB[i - 1][0];
                int value = AB[i - 1][1];
                if (timeAfterEat >= time && timeAfterEat < time + T) {
                    dp[i][timeAfterEat] = Math.max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
                }
            }
        }

        // Print the maximum value that can be obtained after eating all the activities
        System.out.println(Arrays.stream(dp[N]).max().getAsInt());
    }
}

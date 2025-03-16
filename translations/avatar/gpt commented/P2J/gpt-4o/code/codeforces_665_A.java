import java.util.Scanner;

public class ActivityScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the starting time and duration of activity A
        int a = scanner.nextInt();
        int at = scanner.nextInt();

        // Read the starting time and duration of activity B
        int b = scanner.nextInt();
        int bt = scanner.nextInt();

        // Read the start time in hours and minutes, then convert it to total minutes
        String[] time = scanner.next().split(":");
        int t1 = Integer.parseInt(time[0]);
        int t2 = Integer.parseInt(time[1]);
        int st = t2 + (t1 - 5) * 60;  // Convert start time to minutes since 5:00

        // Calculate the finish time for activity A
        int fin = st + at;

        // Initialize the current time and the answer counter
        int now = 0;
        int ans = 0;

        // Loop until the current time exceeds the finish time or the maximum time limit (19:00 or 1140 minutes)
        while (now < fin && now < 1140) {
            // Check if activity B can start after the current time
            if (now + bt > st) {
                ans++;  // Increment the count of possible starts for activity B
            }
            now += b;  // Move the current time forward by the duration of activity B
        }

        // Print the total number of times activity B can start
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>

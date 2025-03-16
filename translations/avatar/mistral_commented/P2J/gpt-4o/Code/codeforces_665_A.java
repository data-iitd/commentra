import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first pair of integers (a and at) from the user input
        int a = scanner.nextInt();
        int at = scanner.nextInt();

        // Read the second pair of integers (b and bt) from the user input
        int b = scanner.nextInt();
        int bt = scanner.nextInt();

        // Read the start time (t1) and end time (t2) from the user input in the format "HH:MM"
        String[] time = scanner.next().split(":");
        int t1 = Integer.parseInt(time[0]);
        int t2 = Integer.parseInt(time[1]);

        // Calculate the start time in seconds
        int st = t2 + (t1 - 5) * 60;

        // Calculate the finish time in seconds
        int fin = st + at;

        // Initialize the current time to zero
        int now = 0;

        // Initialize the answer to zero
        int ans = 0;

        // Loop through the time until the current time is less than the finish time and less than 1140 (11:00 PM)
        while (now < fin && now < 1140) {
            // If the next event starts after the current time, increment the answer
            if (now + bt > st) {
                ans++;
            }
            // Increment the current time by the duration of the next event
            now += b;
        }

        // Print the final answer
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>

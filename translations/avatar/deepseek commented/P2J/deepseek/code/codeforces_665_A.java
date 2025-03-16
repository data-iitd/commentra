import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int at = scanner.nextInt();
        int b = scanner.nextInt();
        int bt = scanner.nextInt();
        String[] time = scanner.next().split(":");
        int t1 = Integer.parseInt(time[0]);
        int t2 = Integer.parseInt(time[1]);

        // Calculate the start time by adjusting t1 by subtracting 5 hours and converting to minutes, then adding t2
        int st = t2 + (t1 - 5) * 60;

        // Calculate the finish time by adding at to the start time
        int fin = st + at;

        // Initialize now and ans variables
        int now = 0;
        int ans = 0;

        // Loop until now is less than fin and now is less than 1140
        while (now < fin && now < 1140) {
            if (now + bt > st) {  // Check if adding bt to now would exceed the start time
                ans += 1;  // Increment ans if the condition is met
            }
            now += b;  // Increment now by b
        }

        // Print the final value of ans
        System.out.println(ans);
    }
}


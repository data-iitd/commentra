import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values
        int a = scanner.nextInt();
        int at = scanner.nextInt();
        int b = scanner.nextInt();
        int bt = scanner.nextInt();
        String[] time = scanner.next().split(":");
        int t1 = Integer.parseInt(time[0]);
        int t2 = Integer.parseInt(time[1]);
        
        // Calculate start time in minutes
        int st = t2 + (t1 - 5) * 60;
        int fin = st + at;
        int now = 0;
        int ans = 0;
        
        // Loop to count the number of valid intervals
        while (now < fin && now < 1140) {
            if (now + bt > st) {
                ans += 1;
            }
            now += b;
        }
        
        // Print the result
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>

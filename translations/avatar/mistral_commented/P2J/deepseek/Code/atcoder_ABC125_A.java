public class Main {
    public static void main(String[] args) {
        // Read input values a, b, and t from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int t = scanner.nextInt();
        // Initialize cookie counter to 0
        int cookie = 0;
        // Set initial time to a
        int time = a;
        // Cookies are produced every 'a' time units, with each production adding 'b' cookies
        // The loop runs as long as the time for production is less than or equal to the total time 't' plus half a time unit
        while (time <= t + 0.5) {
            // Increment cookie counter by 'b'
            cookie += b;
            // Update time for next production
            time += a;
        }
        // Print the total number of cookies produced
        System.out.println(cookie);
    }
}

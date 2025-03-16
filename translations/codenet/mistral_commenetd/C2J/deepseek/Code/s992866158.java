public class Main {
    public static void main(String[] args) {
        // Declare variables n, k, and cnt of type int
        int n, k, cnt;

        // Create a Scanner object to read from the standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers n and k from the standard input using scanner.nextInt()
        n = scanner.nextInt();
        k = scanner.nextInt();
        // Initialize variable cnt to zero
        cnt = 0;
        // Loop through n times using a for loop
        for (int i = 0; i < n; i++) {
            // Declare variable h of type int
            int h;

            // Read an integer h from the standard input using scanner.nextInt()
            h = scanner.nextInt();
            // If h is greater than or equal to k, increment cnt by 1
            if (h >= k)
                cnt++;
        }
        // Print the value of cnt to the standard output using System.out.println()
        System.out.println(cnt);
    }
}

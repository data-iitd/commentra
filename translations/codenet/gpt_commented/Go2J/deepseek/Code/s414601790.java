public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the number of operations (n) and the sequence of operations (s)
        int n;
        String s;

        // Read input values for n and s from the standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        s = scanner.next();

        // Initialize variables to track the maximum count and the current count
        int max = 0;
        int cnt = 0;

        // Iterate over each character in the string s
        for (int i = 0; i < n; i++) {
            // Increment count for 'I' and decrement for any other character
            if (s.charAt(i) == 'I') {
                cnt++;
            } else {
                cnt--;
            }

            // Update max if the current count exceeds the previously recorded maximum
            if (cnt > max) {
                max = cnt;
            }
        }

        // Print the maximum count achieved during the iterations
        System.out.println(max);
    }
}

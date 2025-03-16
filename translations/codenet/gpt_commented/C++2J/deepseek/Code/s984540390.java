public class Main {
    public static void main(String[] args) {
        // Initialize variables to store the answer, maximum value, sum, minimum value, and count
        long ans = 0, mx = 0, sum = 0, mn = 100000000, cnt = 1;

        // Read the input value for h
        long h;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        h = scanner.nextLong();

        // Loop until h becomes 1
        while (h != 1) {
            // If h is odd, decrement it by 1 to make it even
            if (h % 2 != 0) h--;

            // Divide h by 2
            h /= 2;

            // Double the count for each iteration
            cnt *= 2;

            // Accumulate the count into the answer
            ans += cnt;
        }

        // Output the final answer incremented by 1
        System.out.println(ans + 1);
    }
}

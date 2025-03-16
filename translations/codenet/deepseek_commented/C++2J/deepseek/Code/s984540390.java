public class Main {
    public static void main(String[] args) {
        // Input the value of h
        long h = System.in.read() - '0'; // Read the input value of h

        // Define constants and variables
        long ans = 0, mx = 0, sum = 0, mn = 100000000, cnt = 1;

        // Loop to calculate the answer
        while (h != 1) {
            if (h % 2 != 0) {
                h--; // Decrement h if it is odd
            }
            h /= 2; // Divide h by 2
            cnt *= 2; // Double the count
            ans += cnt; // Increment the sum by the current count
        }

        // Output the final result
        System.out.println(ans + 1);
    }
}

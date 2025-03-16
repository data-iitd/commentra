import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Define constants and variables
        long ans = 0, cnt = 1;

        // Input the value of h
        Scanner scanner = new Scanner(System.in);
        long h = scanner.nextLong();

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
// <END-OF-CODE>

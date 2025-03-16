import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();  // Read the integer k
        long t = 0;  // Initialize t to 0

        for (int i = 1; i <= k; i++) {  // Loop from 1 to k
            t = (t % k) * 10 + 7;  // Update t based on the current iteration
            if (t % k == 0) {  // Check if t is divisible by k
                System.out.println(i);  // Print the current index if t is divisible by k
                return;  // Exit the program as we found the solution
            }
        }
        System.out.println(-1);  // Print -1 indicating no solution was found
    }
}
// <END-OF-CODE>

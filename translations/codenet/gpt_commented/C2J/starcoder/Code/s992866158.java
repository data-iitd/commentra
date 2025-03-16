import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new Scanner object to read input from stdin
        Scanner sc = new Scanner(System.in);

        // Read the number of elements and the threshold value from user input
        int n = sc.nextInt();
        int k = sc.nextInt();

        // Initialize the counter to zero
        int cnt = 0;

        // Loop through each element, decrementing n until it reaches zero
        while (n-- > 0) {
            // Read the current element from user input
            int h = sc.nextInt();

            // Check if the current element is greater than or equal to the threshold
            if (h >= k)
                // Increment the counter if the condition is met
                cnt++;
        }

        // Output the final count of elements that met or exceeded the threshold
        System.out.println(cnt);
    }
}

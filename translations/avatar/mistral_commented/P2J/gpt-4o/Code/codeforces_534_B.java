import java.util.Scanner;

public class DistanceCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get the initial values of v1, v2, t, and d from user input
        String[] input1 = scanner.nextLine().split(" ");
        String[] input2 = scanner.nextLine().split(" ");

        // Convert the input strings to integers
        int v1 = Integer.parseInt(input1[0]);
        int v2 = Integer.parseInt(input1[1]);
        int t = Integer.parseInt(input2[0]);
        int d = Integer.parseInt(input2[1]);

        // Initialize variables
        int a = 1;
        int v = v1;
        int distance = 0;

        // For loop to calculate the total distance
        for (int i = 0; i < t; i++) {
            // Check if v is ahead of v2 by more than the difference * (time - i)
            if (v - v2 > (t - i) * d) {
                // If so, change the direction of acceleration
                a *= -1;
                // Update the position of v
                v = (t - i) * d + v2;
            }

            // Add the current position of v to the total distance
            distance += v;

            // Update the position of v based on the acceleration
            v += a * d;
        }

        // Print the total distance
        System.out.println(distance);
        
        scanner.close();
    }
}
// <END-OF-CODE>

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        // Include necessary headers
        // The code starts by including necessary headers for input and output operations.
        // Headers for input and output operations are included.

        // Declare arrays
        // Two arrays, `train` and `bus`, are declared to store the values.
        int[] train = new int[2];
        int[] bus = new int[2];

        // Input values
        // The values for `train` and `bus` are taken from the user.
        Scanner sc = new Scanner(System.in);
        train[0] = sc.nextInt();
        train[1] = sc.nextInt();
        bus[0] = sc.nextInt();
        bus[1] = sc.nextInt();

        // Calculate the sum
        // The code then calculates the sum of the minimum values from both arrays.
        int sum = (train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]);

        // Output the result
        // Finally, the result is printed to the console.
        System.out.println(sum);
    }
}




import java.util.Scanner;

public class s217679680{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the array of integers from stdin
        int[] arr = new int[2];
        for (int i = 0; i < 2; i++) {
            arr[i] = scanner.nextInt();
        }
        // Initialize variables a and b with the first two elements of the array
        int a = arr[0], b = arr[1];
        // Initialize variables tap and consent with default values
        int tap = 0, consent = 1;
        // Loop until consent is greater than or equal to b
        while (consent < b) {
            // Increment consent by the sum of a and consent minus one
            consent = consent + a - 1;
            // Increment tap by one for each iteration
            tap++;
        }
        // Print the result, i.e., the number of taps required
        System.out.println(tap);
    }
}


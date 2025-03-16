import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create an array to hold three integers
        int[] in = new int[3];

        // Read three integers from standard input
        Scanner scanner = new Scanner(System.in);
        in[0] = scanner.nextInt();
        in[1] = scanner.nextInt();
        in[2] = scanner.nextInt();
        scanner.close();

        // Sort the integers in ascending order
        Arrays.sort(in);

        // Calculate the result based on the sorted integers
        // The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
        System.out.println(in[2] * 10 + in[1] + in[0]);
    }
}

// <END-OF-CODE>

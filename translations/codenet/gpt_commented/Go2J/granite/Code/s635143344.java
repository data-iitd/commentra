
import java.util.Arrays;
import java.util.Scanner;

public class s635143344{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create an array to hold three integers
        int[] in = new int[3];

        // Read three integers from standard input
        for (int i = 0; i < 3; i++) {
            in[i] = scanner.nextInt();
        }

        // Sort the integers in ascending order
        Arrays.sort(in);

        // Calculate the result based on the sorted integers
        // The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
        int result = in[2] * 10 + in[1] + in[0];

        // Print the result
        System.out.println(result);
    }
}

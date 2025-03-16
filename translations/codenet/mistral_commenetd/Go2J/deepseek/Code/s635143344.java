import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] in = new int[3];

        // Read three integers from the standard input and store them in the array in
        for (int i = 0; i < 3; i++) {
            in[i] = scanner.nextInt();
        }

        // Sort the integers in ascending order
        Arrays.sort(in);

        // Multiply the last integer by 10 and add the second last and the last integer
        // Then print the result
        System.out.println(in[2] * 10 + in[1] + in[0]);
    }
}


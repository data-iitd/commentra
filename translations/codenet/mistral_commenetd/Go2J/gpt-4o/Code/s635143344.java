import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an integer array named in with a length of 3
        int[] in = new int[3];

        // Use Scanner to read three integers from the standard input and store them in the array in
        Scanner scanner = new Scanner(System.in);
        in[0] = scanner.nextInt();
        in[1] = scanner.nextInt();
        in[2] = scanner.nextInt();

        // Sort the integers in ascending order using Arrays.sort method
        Arrays.sort(in);

        // Multiply the last integer by 10 and add the second last and the last integer
        // Then print the result
        System.out.println(in[2] * 10 + in[1] + in[0]);
    }
}
// <END-OF-CODE>


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 1: Create a Scanner object
        Scanner scanner = new Scanner(System.in);

        // Step 2: Create an array of integers with a length of 3
        int[] in = new int[3];

        // Step 3: Prompt the user to input three integers
        for (int i = 0; i < in.length; i++) {
            in[i] = scanner.nextInt();
        }

        // Step 4: Sort the array of integers in ascending order
        Arrays.sort(in);

        // Step 5: Perform a calculation using the sorted integers and print the result
        System.out.println(in[2] * 10 + in[1] + in[0]);
    }
}


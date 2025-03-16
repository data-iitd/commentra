import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first line of input containing 4 integers and store them in ns array
        System.out.println("Reading input");
        String[] input = scanner.nextLine().split(" ");
        int[] ns = new int[4];
        for (int i = 0; i < 4; i++) {
            ns[i] = Integer.parseInt(input[i]);
        }

        // Sort the ns array in ascending order
        System.out.println("Sorting the numbers in ns array");
        Arrays.sort(ns);

        // Check if the sorted ns array matches the specific condition (1, 4, 7, 9)
        System.out.println("Checking the condition");
        if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
            System.out.println("The condition is true, print YES");
            System.out.println("Output: YES");
            System.out.println();
            System.out.println("End of the program");
            return;
        } else {
            System.out.println("The condition is false, print NO");
            System.out.println("Output: NO");
            System.out.println();
            System.out.println("End of the program");
            return;
        }
    }
}

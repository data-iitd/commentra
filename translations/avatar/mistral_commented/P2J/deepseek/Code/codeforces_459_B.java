import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements in the list
        int[] l1 = new int[n];
        for (int i = 0; i < n; i++) {
            l1[i] = scanner.nextInt(); // Read the list elements and store them in an array
        }
        Arrays.sort(l1); // Sort the array in ascending order

        int a = l1[n - 1]; // Assign the last element of the sorted array to the variable a
        int b = l1[0]; // Assign the first element of the sorted array to the variable b

        if (a == b) { // Check if the first and the last elements are equal
            System.out.println(a - b + " " + (n * (n - 1)) / 2); // If so, calculate and print the result
        } else {
            int ac = 0, bc = 0;
            for (int num : l1) { // Count the number of occurrences of the element a in the array
                if (num == a) ac++;
                if (num == b) bc++;
            }
            System.out.println(a - b + " " + ac * bc); // Print the result
        }
    }
}

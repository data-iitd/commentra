
import java.util.Arrays;
import java.util.Scanner;

public class codeforces_108_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read an input line (not used in the logic)
        String[] input = scanner.nextLine().split(" "); // Read a line of integers, split by spaces
        int[] a = new int[input.length]; // Convert the input array to an integer array
        for (int i = 0; i < input.length; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(a); // Sort the array of integers in ascending order
        for (int i = 1; i < a.length; i++) { // Iterate through the sorted array starting from the second element
            if (a[i]!= a[i - 1] && a[i] < a[i - 1] * 2) { // Check if the current element is different from the previous one and if it is less than double the previous element
                System.out.println("YES"); // If the condition is met, print 'YES'
                return;
            }
        }
        System.out.println("NO"); // If no such pair is found, print 'NO'
    }
}

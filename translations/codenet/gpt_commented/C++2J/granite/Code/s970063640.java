
import java.util.Arrays;
import java.util.Scanner;

public class s970063640{
    public static void main(String[] args) {
        // Declare an integer to hold the number of elements
        int n;
        // Read the number of elements from user input
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        // Declare an integer to hold the number of largest elements to sum
        int a;
        // Read the number of largest elements to sum from user input
        a = scanner.nextInt();

        // Initialize a variable to hold the sum of the largest elements
        int sum = 0;

        // Declare an array to hold the elements
        int[] s = new int[n];

        // Read the elements into the array from user input
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        // Sort the array in non-decreasing order
        Arrays.sort(s);

        // Sum the largest 'a' elements from the sorted array
        for (int i = n - 1; i > n - a - 1; i--) {
            sum += s[i];
        }

        // Output the calculated sum of the largest 'a' elements
        System.out.println(sum);

        // Return 0 to indicate successful completion of the program
        return 0;
    }
}

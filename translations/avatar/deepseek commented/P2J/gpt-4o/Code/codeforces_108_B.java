import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static String s() {
        // Take input from the user
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first line (not used)
        // Read the input, split it into an array of integers, and store it in 'a'
        String[] input = scanner.nextLine().split(" ");
        int[] a = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        // Sort the array 'a'
        Arrays.sort(a);
        // Iterate through the sorted array starting from the second element
        for (int i = 1; i < a.length; i++) {
            // Check if the current element is not equal to the previous element
            // and if the current element is less than twice the previous element
            if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
                // If the condition is met, return 'YES'
                return "YES";
            }
        }
        // If the loop completes without finding a match, return 'NO'
        return "NO";
    }

    public static void main(String[] args) {
        // Print the result returned by the function 's()'
        System.out.println(s());
    }
}

// <END-OF-CODE>

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read an integer n
        int[] a = new int[n]; // Create an array of size n
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Read n integers into the array a
        }
        Arrays.sort(a); // Sort the array a
        for (int i = 0; i < n - 1; i++) { // Iterate through the sorted array to check for duplicates
            if (a[i] == a[i + 1]) {
                System.out.println("NO"); // If duplicates are found, print "NO" and exit
                return;
            }
        }
        System.out.println("YES"); // If no duplicates are found, print "YES"
    }
}
// <END-OF-CODE>

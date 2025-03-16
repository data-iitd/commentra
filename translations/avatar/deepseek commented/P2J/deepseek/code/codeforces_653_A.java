import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input for the number of elements
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();  // Take a list of integers as input
        }
        Arrays.sort(l);  // Sort the list of integers

        // Check if there exists any integer i in the list such that i + 1 and i + 2 are also in the list
        boolean found = false;
        for (int i = 0; i < n; i++) {
            if (Arrays.stream(l).anyMatch(x -> x == l[i] + 1) && Arrays.stream(l).anyMatch(x -> x == l[i] + 2)) {
                found = true;
                break;
            }
        }
        System.out.println(found ? "YES" : "NO");  // Print 'YES' if found, otherwise print 'NO'
    }
}

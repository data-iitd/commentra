import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of elements in the list
        int[] l = new int[n];  // Create an array to store the list of integers
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();  // Read the list of integers and store them in the array
        }
        Arrays.sort(l);  // Sort the array in ascending order

        boolean found = false;  // Initialize a flag to check if the condition is met
        for (int i = 0; i < n; i++) {  // Iterate through each element in the sorted array
            if (Arrays.stream(l).anyMatch(x -> x == l[i] + 1) && Arrays.stream(l).anyMatch(x -> x == l[i] + 2)) {
                // Check if the next two elements are also in the array
                found = true;  // Set the flag to true
                break;  // Break out of the loop
            }
        }
        if (found) {
            System.out.println("YES");  // If the flag is true, print 'YES'
        } else {
            System.out.println("NO");  // If the flag is false, print 'NO'
        }
    }
}

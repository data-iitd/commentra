import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Create an array 'A' from the input, which is a sequence of space-separated integers
        int[] A = Arrays.stream(scanner.nextLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();

        // Check if the second or third element of the array 'A' is less than or equal to the first element
        if (A[1] <= A[2] || A[3] <= A[0]) {
            // If the condition is true, print '0'
            System.out.println(0);
        } else {
            // If the condition is false, sort the array 'A' in ascending order
            Arrays.sort(A);

            // Print the difference between the third and second elements of the sorted array
            System.out.println(A[2] - A[1]);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
